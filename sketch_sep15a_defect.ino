#include <ESP8266WiFi.h>                 
#include <FirebaseArduino.h>      
  
 
#define FIREBASE_HOST "******************.firebaseio.com"      
#define FIREBASE_AUTH "***********************************"            
#define WIFI_SSID "***********"                                  
#define WIFI_PASSWORD "**************"            
 const int ldrPin = A2
 #define ANALOG_IN_PIN A1
 double sensorValue1 = 0; //AC voltage measerment start
double sensorValue2 = 0;
int crosscount = 0;
int climb_flag = 0;
int val[100];
int max_v = 0;
double VmaxD = 0;
double VeffD = 0;
double Veff = 0;

                   // Floats for ADC voltage & Input voltage
float adc_voltage = 0.0;
float in_voltage = 0.0;
 
// Floats for resistor values in divider (in ohms)
float R1 = 30000.0;
float R2 = 7500.0; 
 
// Float for Reference Voltage
float ref_voltage = 5.0;
 
// Integer for ADC value
int adc_value = 0;                                
 
void setup() 
{
  Serial.begin(115200);
   Serial.println("DC Voltage Test");
  pinMode(ldrPin, INPUT);                                          
               
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                  
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
 
  Serial.println();
  Serial.print("Connected");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());                               //prints local IP address
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);                 // connect to the firebase
 
}
 
void loop() 
{
  
 
   for ( int i = 0; i < 100; i++ ) {
    sensorValue1 = analogRead(A0);  // PIN input
    if (analogRead(A0) > 511) {
      val[i] = sensorValue1;
    }
    else {
      val[i] = 0;
    }
    delay(1);
  }

  max_v = 0;

  for ( int i = 0; i < 100; i++ )
  {
    if ( val[i] > max_v )
    {
      max_v = val[i];
    }
    val[i] = 0;
  }
  if (max_v != 0) {


    VmaxD = max_v;
    VeffD = VmaxD / sqrt(2);
    Veff = (((VeffD - 420.76) / -90.24) * -210.2) + 210.2;
  }
  else {
    Veff = 0;
  }
  Serial.print("Voltage: ");
  Serial.println(Veff);
  VmaxD = 0;
  if(veff == 220){
    Serial.print("AC wire status OK");
  }
  else{
  Firebase.pushString("AC Voltage Status Fail"); 
  }
  
// Read the Analog Input
   adc_value = analogRead(ANALOG_IN_PIN);
   
   // Determine voltage at ADC input
   adc_voltage  = (adc_value * ref_voltage) / 1024.0; 
   
   // Calculate voltage at divider input
   in_voltage = adc_voltage / (R2/(R1+R2)) ; 
   
   // Print results to Serial Monitor to 2 decimal places
  Serial.print("Input Voltage = ");
  Serial.println(in_voltage, 2);
  if(in_voltage == 12){
    Serial.print("Convertor status is OK");
  }
  else{
  Firebase.pushString("Convertor Status Fail"); 
  }
   int ldrStatus = analogRead(ldrPin);
  if (ldrStatus <= 200) {
  Firebase.pushString("LAMP IS OFF"); // If LDR senses darkness led pin high that means led will glow.
  Serial.println(ldrStatus);
  } else {
  Firebase.pushString("LAMP IS  ON"); 
  Serial.println(ldrStatus);
}
  delay(5000);
 
 
            //setup path to send Humidity readings
  
    if (Firebase.failed()) 
    {
 
      Serial.print("pushing /logs failed:");
      Serial.println(Firebase.error()); 
      return;
  }
}
