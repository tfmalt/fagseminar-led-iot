
#include <Arduino.h>
#include <FastLED.h>
//     -DLED_TYPE="SK9822"
//     -DLED_COUNT=140
//     -DLED_DATA=17
//     -DLED_CLOCK=16
//     -DLED_COLOR_ORDER="BGR"
//     -DLED_mA=12000
//     -DFFT_ACTIVE=1
//     -DFFT_INPUT_PIN=34
//     -DFPS=120
#define NUM_LEDS 30
#define DATA_PIN 17
#define CLOCK_PIN 16

CRGB leds[NUM_LEDS];

void setup() { Serial.begin(115200); }

void loop() {
  Serial.println("Hello World.");
  delay(1000);
}