
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

void loop() {
  // The almost simplest possible loop
  // Serial.printf("INFO: %i\n", FPS_DELAY);

  uint8_t pos = beatsin8(24, 0, NUM_LEDS - 1);
  leds[pos] = CRGB::Red;

  EVERY_N_MILLIS(FPS_DELAY) {
    ledset.fadeToBlackBy(32);
    FastLED.show();
  }
}