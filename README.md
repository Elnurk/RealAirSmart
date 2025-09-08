# RealAirSmart

RealAirSmart is an environmental monitoring and control system that measures air quality and environmental parameters and communicates data to a connected dashboard. Designed for robotics competitions and demonstrations, the project uses a microcontroller with attached sensors (temperature, humidity, air quality, etc.) to capture data and actuators to maintain optimal conditions. The codebase includes a main Arduino sketch and bundled libraries for ease of use.

## Features
- Monitors environmental parameters such as temperature, humidity, and gas/air quality.
- Uses DHT sensors and gas sensors to provide real‑time data.
- Communicates with a remote interface via serial/USB for data logging and display.
- Actuates fans or devices to maintain safe air quality.
- Organizes hardware drivers and libraries in the `library/` folder for portability.

## Hardware
- **Microcontroller:** Arduino‑compatible board.
- **Sensors:** DHT11/DHT22, MQ series gas sensors, and other analog sensors as required.
- **Actuators:** Small DC fans or relay‑controlled devices for ventilation.
- **Libraries:** ArduinoJson, firebase‑arduino (stored in the `library/` folder).

## Software / Stack
- Written in C++ for the Arduino platform.
- Uses the [ArduinoJson](https://github.com/bblanchon/ArduinoJson) library to format sensor data.
- Includes the [Firebase Arduino](https://github.com/FirebaseExtended/firebase-arduino) library for optional cloud data upload.
- The `RealAirSmort.ino` sketch contains the main control logic.

## Build & Run
### Using the Arduino IDE
1. Copy the contents of the `library/` folder into your Arduino libraries directory (typically `~/Documents/Arduino/libraries`).
2. Open `RealAirSmort.ino` in the Arduino IDE.
3. Select the correct board and COM port.
4. Click **Upload** to compile and upload the firmware to your microcontroller.

### Using Arduino CLI
```bash
# Install required libraries
arduino-cli lib install ArduinoJson
# Compile for an Arduino Uno (adjust the FQBN as needed)
arduino-cli compile --fqbn arduino:avr:uno RealAirSmort.ino
# Upload to the connected device
arduino-cli upload -p /dev/ttyUSB0 --fqbn arduino:avr:uno RealAirSmort.ino
```

## License
This project is licensed under the MIT License. See the `LICENSE` file for details.
