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
SoftwareSerial BTSerial(0, 1); // RX | TX, ALT: SDA:A4 SCL:A5

const int relayBell = 3;  //A3

void setup()
{
    Serial.begin(9600);
    BTSerial.begin(38400);
    Serial.println("BT Serial Ready");
    Serial.println("Ready for bell ring...");
    pinMode(relayBell, OUTPUT);
    digitalWrite(relayBell, HIGH);
}

void loop()
{
 while (BTSerial.available()) {
    Serial.write(BTSerial.read());
    Serial.read();
    
  }
  if (BTSerial.read() == '1') {
    bellChime();
  }
  else if (BTSerial.read() == '0') {
    digitalWrite(relayBell, HIGH);
  }
}

void bellChime()
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
}
    
