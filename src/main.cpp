
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

// uint8_t color = 0;

CRGB leds[NUM_LEDS];
CRGBSet ledset(leds, NUM_LEDS);
CRGBPalette16 pal = fagseminar_gp;

void setup() {
  // Initialize Serial port
  Serial.begin(115200);

  // FastLED setup
  FastLED.addLeds<SK9822, DATA_PIN, CLOCK_PIN, BGR>(leds, NUM_LEDS);
}

void loop() {
  // The almost simplest possible loop
  // Serial.printf("INFO: %i\n", FPS_DELAY);

  // sine curve that pulsates with a given beats per minute:
  uint8_t pos = beatsin8(24, 0, NUM_LEDS - 1);
  uint8_t gradient_index = pos * (256 / NUM_LEDS);

  // Hue (Color), Saturation, Value (Brightness)
  leds[pos] = ColorFromPalette(pal, gradient_index);

  EVERY_N_MILLIS(FPS_DELAY) {
    ledset.fadeToBlackBy(32);
    FastLED.show();
  }
}