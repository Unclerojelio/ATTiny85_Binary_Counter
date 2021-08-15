// This sketch outputs a binary coded hexadecimal value out to the pins of an
// ATTiny85.
//
// Roger Banks
// 15 Aug 2021
//
#include <Arduino.h>

void setup() {
  // Set pins to output
  pinMode(PCINT0, OUTPUT);
  pinMode(PCINT1, OUTPUT);
  pinMode(PCINT2, OUTPUT);
  pinMode(PCINT3, OUTPUT);
}

void loop() {
  for(byte x = 0; x < 16; x++) {
    digitalWrite(PCINT0, x & B0001);
    digitalWrite(PCINT1, x & B0010);
    digitalWrite(PCINT2, x & B0100);
    digitalWrite(PCINT3, x & B1000);
    delay(63);  // 1000/16, because this ATTiny85 does not have a bootloader
                // is running at 1MHz.
  }
}