#include <Arduino.h>
#include "Wire.h"
#define solenoidPin 10;
#define pumpPin 9;
Wire comm;

void handleInput() {
 while (wire.available()) {
   switch (int(comm.read())) {
    case 1:
     digitalWrite(pumpPin, HIGH);
     break;
    case 2:
     digitalWrite(pumpPin, LOW);
     break;
    case 3:
     digitalWrite(solenoidPin, HIGH);
     break;
    case 4:
     digitalWrite(solenoidPin, LOW);
     break;
    default:
     break;
   }
 }
}

void setup() {
  comm.begin(0x0f);
  pinMode(solenoidPin, OUTPUT);
  pinMode(pumpPin, OUTPUT);
  comm.onRecieve(handleInput);
}

void loop() {
 delay(100);
}
