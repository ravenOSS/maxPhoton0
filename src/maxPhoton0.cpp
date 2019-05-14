#include "application.h"
#line 1 "/Users/raventt/MBP_Projects/arduino/maxPhoton0/src/maxPhoton0.ino"
// /*
//  * Project maxPhoton
//  * Description: Maxbotix reader #Git
//  * Author: DJR
//  * Date: 05.08.19
//  */

// /* test function to Parse data from MaxSonar serial data
//  and return integer range data*/

// Following code SHOULD NOT WORK!!
// There is no detection of the start of the range reading nor of its ending.
// The buffer to contain the data is declared as char
// Serial.print of range data would be expected to include the 'R' and carriage return.
// Console only shows the numeric range data (as char).
// When the sensor is moved to another range, the readout does not immediately change.
// This suggests that there are multiple readings being made, stored, and parsed to buf


void setup();
void loop ();
#line 20 "/Users/raventt/MBP_Projects/arduino/maxPhoton0/src/maxPhoton0.ino"
int maxOn = D0;  // Photon output pin to toggle pin 4 on Maxbotix

char buf[5]; // Create buffer to handle RxxxCR

void setup()
{
  pinMode(maxOn, OUTPUT);
  Serial.begin(9600);
  Serial.println("Hello ravenTT!");
  Serial1.begin(9600);
  Serial.println("Sonar connected");
  digitalWrite(maxOn, LOW); // Stop continuous reading mode on sensor
}

unsigned long currentMillis = millis(); // Timing and Serial.print's are for debug 

void loop ()
{ 
  unsigned long start = micros();
  digitalWrite(maxOn, HIGH); // Bring HIGH to trigger range reading
  Serial1.read(); // Only reads one character at a time
  if (Serial1.available() >=4) // Only iterate over the range data if there is a minimum of Rxxx
  {
    for (int i=0; i<4; i++) {
      buf[i] = Serial1.read(); // Push data into buffer
    }
  }
  digitalWrite(maxOn, LOW); // End range reading
    unsigned long end = micros();
    unsigned long elapsed = millis() / (60 * 1000); // millis is the time since code was started
  Serial1.flush();

  Serial.print("Start: ");
  Serial.println(start);

  Serial.print("End: ");
  Serial.println(end);

  Serial.print("Elapsed: ");
  Serial.println(elapsed);
  
  Serial.print("Buf: ");
  Serial.println(buf);
  int data = atoi(buf);
  Serial.print("Parsed: ");
  Serial.println(data);
  delay(1200); // Repeat the process every X milliseconds
}

