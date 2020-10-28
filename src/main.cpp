
#include <Arduino.h>
#include <FastLED.h>

#define NUM_LEDS 30
#define DATA_PIN 17
#define CLOCK_PIN 16

CRGB leds[NUM_LEDS];

void setup() {
  // Initialize Serial port
  Serial.begin(115200);

  // FastLED setup
  FastLED.addLeds<SK9822, DATA_PIN, CLOCK_PIN, BGR>(leds, NUM_LEDS);
}

void loop() {
  // The almost simplest possible loop
  Serial.println("Hello World.");

  leds[9] = CRGB::Red;
  FastLED.show();
  delay(500);

  leds[9] = CRGB::Black;
  FastLED.show();
  delay(500);
}