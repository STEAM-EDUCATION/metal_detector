# Metal Detector

## Overview

This project is a simple metal detector using an Arduino, sound sensor, coil sensor, and an LCD display to show the type of detected metal. The system detects the presence of metal and identifies its type based on sound values, then displays the results on the LCD and triggers an LED and buzzer for indication.

---

## Components Used

- **Arduino Uno (or compatible Arduino board)**
- **Sound Sensor Module** (for detecting sound signals)
- **Coil Sensor** (detects metal objects)
- **LED** (indicates when metal is detected)
- **Buzzer** (alerts when metal is detected)
- **16x2 LCD Display with I2C Module** (displays detection information)
- **Resistors, Wires, and Breadboard** (for connections)

[Refer to the Components Documentation for detailed specifications and connections.](assets/wire_connection.md)

---

## Pin Configuration

- **soundSensorPin (A0)**: Reads the sound sensor values to detect sound.
- **coilPin (A1)**: Reads the coil sensor values.
- **ledPin (Pin 7)**: Turns on the LED when metal is detected.
- **buzzerPin (Pin 8)**: Activates the buzzer to provide an alert.

---

## Key Logic Breakdown

1. **Sound and Coil Detection**:
   - The sound sensor detects if a sound (typically from metal objects) is within a certain threshold range.
   - The coil sensor detects changes in magnetic fields that indicate the presence of metal.

2. **Metal Type Determination**:
   - The sound value is used to determine the type of metal based on predefined thresholds:
     - **Iron**: If the sound value is between 500 and 600.
     - **Copper**: If the sound value is between 600 and 700.
     - **Aluminum**: If the sound value is above 700.

3. **Indication**:
   - **LED**: Turns on when metal is detected.
   - **Buzzer**: Sounds when metal is detected.
   - **LCD**: Displays the message "Metal Detected" and the type of metal based on the sound values.

---

## Circuit Diagram

1. **Sound Sensor**:
   - Connect the **A0** pin of the Arduino to the **Analog Output** pin of the sound sensor.
   - Connect the **VCC** and **GND** pins of the sound sensor to the **5V** and **GND** pins of the Arduino, respectively.

2. **Coil Sensor**:
   - Connect the **A1** pin of the Arduino to the **Analog Output** pin of the coil sensor.
   - Connect the **VCC** and **GND** pins to **5V** and **GND**.

3. **LED and Buzzer**:
   - Connect the **LED** to **Pin 7** and the **Buzzer** to **Pin 8**.
   - Connect appropriate current-limiting resistors for both the LED and buzzer as needed.

4. **LCD Display**:
   - Connect the **SDA** and **SCL** pins of the LCD to **A4** and **A5** (I2C communication) on the Arduino.
   - Connect **VCC** and **GND** to **5V** and **GND** on the Arduino.

---

## Code Overview

- **setup()**:
  - Initializes the input/output pins for the sound sensor, coil sensor, LED, buzzer, and LCD.
  - The LCD is initialized and displays the "Metal Detector" message.
  - Serial communication is started for debugging purposes.

- **loop()**:
  - Continuously reads values from the sound sensor and coil sensor.
  - If the sound value exceeds a predefined threshold (500), the system detects metal and displays the detection message on the LCD.
  - The type of metal (Iron, Copper, or Aluminum) is determined based on the sound sensor value.
  - The LED and buzzer are activated to indicate metal detection.

---

## Operation Summary

1. **Detection**:
   - The system constantly monitors the sound and coil sensor for changes. If the sound value exceeds a threshold (500), metal is detected.

2. **Metal Type Identification**:
   - Based on the sound value, the type of metal is displayed on the LCD:
     - **Iron**: Sound value between 500 and 600.
     - **Copper**: Sound value between 600 and 700.
     - **Aluminum**: Sound value above 700.

3. **Visual and Audio Feedback**:
   - **LED**: Lights up when metal is detected.
   - **Buzzer**: Activates a sound when metal is detected.
   - **LCD**: Displays the type of metal detected and the status of the detection.

---

## Troubleshooting

1. **No Metal Detection**:
   - Ensure that the sound sensor is correctly connected to the Arduino and properly powered.
   - Check the threshold value for sound detection. If the value is too high, try lowering it to increase sensitivity.

2. **LCD Not Displaying**:
   - Verify that the I2C connections for the LCD are correct (SDA, SCL, VCC, GND).
   - If using an I2C LCD, ensure the I2C address is correct (`0x27` in the code).

3. **LED and Buzzer Not Working**:
   - Double-check the connections for the LED and buzzer.
   - Ensure that the LED and buzzer are properly wired to the designated pins (7 and 8).
   - Make sure there are no shorts or loose connections.

---
