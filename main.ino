#include <Arduino.h>
#include "Wire.h"
#define solenoidPin 10;
#define pumpPin 9;

void handleInput() {
 while (Wire.available()) {
   switch (int(Wire.read())) {
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
  Wire.begin(0x0f);
  pinMode(solenoidPin, OUTPUT);
  pinMode(pumpPin, OUTPUT);
  Wire.onRecieve(handleInput);
}

void loop() {
 delay(100);
}
