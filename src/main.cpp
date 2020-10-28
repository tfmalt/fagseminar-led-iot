
#include <Arduino.h>
#include <FastLED.h>

#define NUM_LEDS 30
#define DATA_PIN 17
#define CLOCK_PIN 16
#define FPS 120
#define FPS_DELAY 1000 / 120

DEFINE_GRADIENT_PALETTE(fagseminar_gp){
    0,   255, 0,   0,    // red
    8,   255, 0,   0,    // still red
    64,  192, 0,   255,  // purple-ish
    192, 0,   0,   255,  // blue
    248, 0,   128, 255,  // cyan-ish
    255, 0,   128, 255   // cyan-ish
};

CRGB leds[NUM_LEDS];
CRGBPalette16 pal = fagseminar_gp;

void setup() {
  // Initialize Serial port
  Serial.begin(115200);

  // FastLED setup
  FastLED.addLeds<SK9822, DATA_PIN, CLOCK_PIN, BGR>(leds, NUM_LEDS);
}

void loop() {
  // The almost simplest possible loop
  uint8_t step = 256 / NUM_LEDS;

  fill_palette(leds, NUM_LEDS, 0, step, pal, 255, LINEARBLEND);

  EVERY_N_MILLIS(FPS_DELAY) { FastLED.show(); }
}