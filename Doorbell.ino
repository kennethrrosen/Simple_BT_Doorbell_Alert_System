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
SoftwareSerial BTSerial(10, 11); // RX | TX

const int bellButton = 3;  //D3

void setup() {
  pinMode(bellButton, INPUT_PULLUP);
  BTSerial.begin(38400);
  Serial.begin(9600);
}

void loop() {
  BTSerial.println(digitalRead(bellButton));
  Serial.println(digitalRead(bellButton));
}
