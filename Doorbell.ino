/*

DON'T SCARE ME (sender)
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

const int bellButton = 3;  //D3

void setup()
{
    pinMode(bellButton, INPUT);
    digitalWrite(bellButton, HIGH);
    Serial.begin(9600);
    BTSerial.begin(38400);
    Serial.println("BT Serial Ready");
    Serial.println("Ready for bell press...");
}

void loop()
{
while (BTSerial.available()) {
      Serial.println(digitalRead(bellButton));
      BTSerial.print(digitalRead(bellButton));
}
  if (bellButton == LOW) {
    BTSerial.print('1');
  }
  else if (bellButton == HIGH) {
    BTSerial.print('0');
  }
}
