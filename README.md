# maxPhoton0

A Particle project named maxPhoton0 to develop an accurate method to read the serial output of the Maxbotix ultrasonic sensors.

Testing with a XL-Maxsonar 7092 with AN, PW, and Serial(RS232) output.

From the Maxbotix datasheet:

Pin 4- RX- This pin is internally pulled high. If Pin-4 is left unconnected or held high, the sensor will continually measure the range. If Pin-4 is held low the sensor will stop ranging. Bring high 20uS or more to command a range reading.
Pin 5- TX- When Pin 1 is open or held high, the Pin 5 output delivers asynchronous serial data in an RS232 format, except the voltages are 0-Vcc. The output is an ASCII capital “R”, followed by ASCII character digits representing the range in centimeters up to a maximum of 765 (select models) or 1068 (select models), followed by a carriage return (ASCII 13). The baud rate is 9600, 8 bits, no parity, with one stop bit. Although the voltages of 0V to Vcc are outside the RS232 standard, most RS232 devices have sufficient margin to read the 0V to Vcc serial data. If standard voltage level RS232 is desired, invert, and connect an RS232 converter such as a MAX232.

Many projects only require periodic switching of state such as turning an LED on & off. This is not the objective of the development. Other applications simply required a continuous reading from the sensor.

This project is designed to get a distance reading from the sensor using the serial output. As can be seen from the datasheet extract, a reading may be triggered by bringing a pulled-down pin 4 to a HIGH state for 20 microseconds. 

A Particle Photon Arduino compatible microcontroller is used with a MAX3232 breakout from Sparkfun for correct TTL signals. 

Development steps:
1. Get a continuous reading of the sensor output displayed to the serial console.
2. Get a periodic reading.
3. Using built-in CTC interrupt timer, get one-shot range reading.
4. Add to 3, ability to get muliple readings for a mean data calculation.
5. Add to Step 4, managing periodic readings collecting mean data. 