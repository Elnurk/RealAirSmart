# RealAirSmart

RealAirSmart is an environmental monitoring system that measures environmental parameters and communicates data to a server. Designed for research work, the project uses a microcontroller with attached sensors to capture data. The codebase includes a main ESP sketch and bundled libraries for ease of use.

## Features
- Monitors environmental parameters such as gas quantity, and air quality.
- Communicates with a real-time server for data logging.
- Organizes hardware drivers and libraries in the `library/` folder for portability.

## Hardware
- **Microcontroller:** ESP32 board.
- **Sensors:** MQ series gas sensors, and other analog sensors as required.
- **Libraries:** ArduinoJson, firebase‑arduino (stored in the `library/` folder).

## Software / Stack
- Written in C++ for the ESP32 platform.
- Uses the [ArduinoJson](https://github.com/bblanchon/ArduinoJson) library to format sensor data.
- Includes the [Firebase Arduino](https://github.com/FirebaseExtended/firebase-arduino) library for cloud data upload.
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
