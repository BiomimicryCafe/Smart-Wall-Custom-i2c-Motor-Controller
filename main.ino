#include <Arduino.h>
#include "Wire.h"
#define solenoidPin 10;
#define pumpPin 9;
Wire comm;

void handleInput() {
 if (wire.available()) {
   
 }
}

void setup() {
  comm.begin(0x0f);
  pinMode(solenoidPin, OUTPUT);
  pinMode(pumpPin, OUTPUT);
  comm.onRecieve(handleInput);
}

void loop() {

}
