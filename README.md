# Defect Detection System for Street Lamps

The Defect Detection System is designed to monitor the functionality of street lamps by detecting various faults in the electrical circuitry. This README file provides an overview of the system components, their roles, and instructions for setup.

## Components

The Defect Detection System consists of the following components:

- **AC Voltage Sensor Module (ZMPT101B)**: Measures AC voltage at the input of the LED driver to ensure proper connection and voltage levels.
- **DC Voltage Sensor**: Measures DC voltage at the output of the LED driver to verify proper functioning.
- **LED Panel**: Provides illumination for the street lamp.
- **LED Driver**: provide required power supply to led pannle
- **LDR Sensor**: Measures ambient light intensity to ensure the LED panel is operating at full brightness.
- **ESP32**: Collects data from each sensor, processes it, and determines the type of fault in the street lamp.

## Functionality

The system operates as follows:

1. **Voltage Measurement**:
   - The AC Voltage Sensor Module measures AC voltage at the input of the LED driver to check for proper connection and voltage levels.
   - The DC Voltage Sensor measures DC voltage at the output of the LED driver to verify its proper functioning.

2. **Brightness Monitoring**:
   - The LDR sensor measures ambient light intensity in front of the LED panel to ensure it is operating at full brightness.

3. **Fault Detection**:
   - The ESP32 collects data from each sensor and processes it to determine the type of fault in the street lamp.

4. **Fault Communication**:
   - If a fault is detected, the ESP32 sends fault data to the next street lamp for further action.

## Setup Instructions

To set up the Defect Detection System for Street Lamps, follow these steps:

1. **Hardware Assembly**:
   - Connect the AC Voltage Sensor Module to the input of the LED driver.
   - Connect the DC Voltage Sensor to the output of the LED driver.
   - Place the LDR sensor in front of the LED panel to monitor brightness.
   - Connect all sensors and the LED panel to the ESP32 for data collection and processing.

2. **Software Setup**:
   - Upload the provided code to the ESP32.
   - Configure the code to read data from each sensor and determine fault types.
   - Implement communication protocols for sending fault data to neighboring street lamps.

3. **Testing and Calibration**:
   - Power on the system and observe sensor readings.
   - Verify that fault detection and communication functionalities are working as expected.
   - Calibrate sensor thresholds and fault detection algorithms as necessary.

## Usage

Once the Defect Detection System is set up and calibrated, it will continuously monitor the street lamp's functionality and detect any faults. Fault data will be communicated to neighboring street lamps for prompt action.

## Troubleshooting

If you encounter any issues with the Defect Detection System, please refer to the following troubleshooting steps:

- Check the connections between components to ensure they are securely connected.
- Verify the code uploaded to the ESP32 for any errors or bugs.
- Calibrate sensor thresholds and fault detection algorithms to improve accuracy.

If the issue persists, please consult the documentation or seek assistance from the project maintainers.

