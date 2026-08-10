# Closed-Loop Buck Converter

## Overview & Objectives
The goal of this project was to design and implement a regulated DC-DC step-down converter capable of maintaining a constant output voltage despite fluctuations in input voltage or load resistance using a feedback control loop. 

## Technical Details
* Designed a Buck topology using a MOSFET switch, power inductor, diode, and output capacitor.
* Implemented a voltage divider to sense the output voltage, which is then fed into a microcontroller (ESP32).
* Developed a software-based PI loop to compare the sensed voltage against the reference.
* The microcontroller adjusts the duty cycle of the PWM signal used to drive the MOSFET gate.

## Key Specifications
* **Input Voltage:** 12V
* **Output Voltage:** 5V
* **Maximum Current:** 2A
* **Switching Frequency:** 5kHz
