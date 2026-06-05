Smart Parking System

Overview

An Arduino-based Smart Parking System designed to automate vehicle entry and exit management using IR sensors and a servo motor. The system provides real-time parking slot monitoring, LCD display updates, LED indications, and buzzer alerts for efficient parking management.

Features

* Automatic gate control using servo motor
* Real-time parking slot monitoring
* LCD display for slot availability
* Green LED indication when slots are available
* Red LED indication when parking is full
* Buzzer alert for full parking condition
* Vehicle entry and exit detection using IR sensors

Components Used

* Arduino Uno
* IR Sensors (2)
* Servo Motor
* LCD Display (16x2 I2C)
* LEDs
* Buzzer
* Jumper Wires

Working Principle

The system continuously monitors vehicle entry and exit using IR sensors. When a vehicle enters, the available slot count decreases and the gate opens automatically. When a vehicle exits, the slot count increases. The LCD displays available slots in real time, while LEDs and buzzer provide parking status indications.

Technologies Used

* Arduino IDE
* Embedded C/C++
* Servo Library
* LiquidCrystal_I2C Library
* Wire Library

Future Enhancements

* IoT-based remote monitoring
* Mobile application integration
* Cloud-based parking analytics
* RFID-based vehicle authentication

Author

Ankit Pal
