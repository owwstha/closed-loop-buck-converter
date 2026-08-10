# closed-loop-buck-converter
 
**Overview & Objectives** <br>
The goal of this project was to design and implement a regulated DC-DC step-down converter capable of maintaining a constant output voltage despite fluctuations in input voltage or load resistance using a feedback control loop. 

**Technical Details** <br>
•	Designed a standard Buck topology using a MOSFET switch, power inductor, diode, and output capacitor.<br>
•	Implemented a voltage divider to sense the output voltage, which is then fed into a microcontroller (ESP32).<br>
•	Developed a software-based PI loop to compare the sensed voltage against the reference.<br>
•	The microcontroller adjusts the duty cycle of the PWM signal used to drive the MOSFET gate.<br>
•	**Key Specs:** 12V to 5V conversion, 2A max current, 5kHz switching frequency.
