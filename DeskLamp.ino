/*

DON'T SCARE ME (reciever)
Doorbell modification and light alert system for workshed.

  by: Questionable Mechanics
  contact: questionable.mechanics@gmail.com
  last rev: 10/2020
  This sketch is in the public domain
  Note: Developed and tested using VSCODE with Arduino plugin:
  https://github.com/microsoft/vscode-arduino

*/

#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10, 11); // RX | TX
const byte numChars = 1024;
char receivedChars[numChars];   // an array to store the received data

boolean newData = false;

const int relayBell = 3;

void setup() {
 pinMode(relayBell, OUTPUT);
 digitalWrite(relayBell, LOW);
 BTSerial.begin(38400);
 Serial.begin(9600);
 Serial.println("<Arduino is ready>");
}

void loop() {
 if (BTSerial.available()) {
   Serial.write(BTSerial.read());
   }
  if (BTSerial.read() == '1') {
    bellFlicker();
  }
  else if (BTSerial.read() == '0') {
    digitalWrite(relayBell, LOW);
  }
}

void bellFlicker()
{
    digitalWrite(relayBell, LOW);
    delay(250);
    digitalWrite(relayBell, HIGH);
    delay(250);
    digitalWrite(relayBell, LOW);
    delay(250);
    digitalWrite(relayBell, HIGH);
    delay(250);
    digitalWrite(relayBell, LOW);
    delay(250);
    digitalWrite(relayBell, HIGH);
    delay(250);
    digitalWrite(relayBell, LOW);
    delay(250);
}
