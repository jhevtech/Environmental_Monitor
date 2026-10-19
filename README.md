# Environmental Monitor

An Arduino-based environmental monitoring system that measures temperature, humidity, atmospheric pressure, and ambient light. Readings appear on a 128×64 OLED display and in the Serial Monitor, updating approximately every two seconds.

## Hardware
- Arduino-compatible microcontroller
- BME280 temperature, humidity, and pressure sensor
- BH1750 ambient light sensor
- SSD1306 128×64 I2C OLED display
- Jumper wires and breadboard

All sensors and the display communicate over a shared I2C bus.

## Measurements
- Temperature: °C
- Relative humidity: %
- Atmospheric pressure: hPa
- Ambient light: lux

## Required Libraries
Install these libraries through the Arduino IDE Library Manager:
- Adafruit GFX Library
- Adafruit Unified Sensor
- Adafruit BME280 Library
- Adafruit SSD1306
- BH1750

The sketch also uses the Wire library for I2C communication.

## Getting Started
1. Connect the BME280, BH1750, and OLED to your board's SDA and SCL pins, with appropriate power and a common ground.
2. Open `H1_combined.ino` in the Arduino IDE.
3. Install the required libraries and select your board and port.
4. Upload the sketch.
5. Open the Serial Monitor at 9600 baud or view readings on the OLED.

The code uses I2C address `0x76` for the BME280 and `0x3C` for the OLED. Verify that these match your hardware.

