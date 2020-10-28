
#include <Arduino.h>

void setup() {
  // Initialize Serial port
  Serial.begin(115200);
}

void loop() {
  // The almost simplest possible loop
  Serial.println("Hello World.");
  delay(1000);
}