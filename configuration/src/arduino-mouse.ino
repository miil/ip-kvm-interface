/*
  Receives from the hardware serial, sends to software serial.
  Receives from software serial, sends to hardware serial.

  The circuit:
   RX is digital pin 10 (connect to TX of other device)
   TX is digital pin 11 (connect to RX of other device)

  Not all pins on the Leonardo and Micro support change interrupts,
  so only the following can be used for RX:
  8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI).
*/

#include <SoftwareSerial.h>
#include <Mouse.h>

SoftwareSerial rpiSerial(10, 11); // RX, TX

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  // Set the data rate for the SoftwareSerial port
  rpiSerial.begin(9600);
  // initialize control over the keyboard:
  Mouse.begin();
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.println("Serial Connection Established");
}

void loop() {
  if (rpiSerial.available()) {
    // read incoming serial data:
    var x = rpiSerial.read();
    if (horzValue != 0){
      Mouse.move(horzValue/sensitivity, 0, 0);  // move mouse on x axis;
    }
    if (vertValue != 0){
      Mouse.move(0, vertValue/sensitivity, 0);  // move mouse on y axis
    }
    Serial.println(inChar);
  }
}
