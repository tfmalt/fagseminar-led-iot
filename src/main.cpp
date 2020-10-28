
#include <Arduino.h>
#include <FastLED.h>

#define NUM_LEDS 30
#define DATA_PIN 17
#define CLOCK_PIN 16
#define FPS 120
#define FPS_DELAY 1000 / 120

CRGB leds[NUM_LEDS];
CRGBSet ledset(leds, NUM_LEDS);

void setup() {
  // Initialize Serial port
  Serial.begin(115200);

  // FastLED setup
  FastLED.addLeds<SK9822, DATA_PIN, CLOCK_PIN, BGR>(leds, NUM_LEDS);
}

int i = 0;
void loop() {
  // The almost simplest possible loop
  Serial.printf("INFO: %i\n", FPS_DELAY);

  EVERY_N_MILLIS(100) {
    ledset = CRGB::Black;
    ledset(i, i + 3) = CRGB::Red;
    i++;

    if (i >= NUM_LEDS) i = 0;
  }

  EVERY_N_MILLIS(FPS_DELAY) { FastLED.show(); }
}