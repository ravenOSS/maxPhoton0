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
  // int data = parseInt(buf);
  Serial.println(buf);
  delay(1200); // Repeat the process every X milliseconds
}



// void loop()
// {
//   char readByte(); // nothing to do in this sketch

//   digitalWrite(maxOn, HIGH);
//   if (Serial1.available()) {
//   Serial.println(Serial1.read());
//   delayMicroseconds(20);
//   digitalWrite(maxOn, LOW);
//   Serial.println("End");
//   delay(700);
// }
// }
// void loop()
// {
//   int range = MAXread();
//   if (stringComplete)
//   {
//     stringComplete = false; //reset sringComplete ready for next reading
//     Serial.print("Range: ");
//     Serial.println(range);
//     delay(1500); //set interval for sensor reading
//   }
// }

// int MAXread()
// {
//   int result;
//   char readByte();
//   char inData[4]; //char array to read data into
//   int index = 0;

//   Serial1.flush(); // Clear cache ready for next reading

//   while (stringComplete == false)
//   {
//     Serial.println("Read Sonar"); //debug line
//     if (Serial1.available())
//     {
//     char readByte = Serial1.read();
//       if(readByte == 'R');              //read serial input for "R" to mark start of data
//       {
//         Serial.println("readByte set");
//         while (index < 3)               //read next 3 characters for range from sensor
//         {
//           inData[index] = Serial1.read();
//           Serial.print("This is inData char: ");
//           Serial.println(inData[index]); //Debug line
//           index++;                       // Increment where to write next
//         }
//         inData[index] = 0x00;           //add a padding byte at end for atoi() function
//       }

//       readByte = 0;          //reset the readByte ready for next reading
//       index = 0;             // Reset index ready for next reading
//       stringComplete = true; // Set completion of read to true
//       result = atoi(inData); // Changes string data into an integer for use
//     }
//     return result;
//   }
// }