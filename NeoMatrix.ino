#include <FastLED.h>

#define LED_PIN     5
#define NUM_LEDS    64 // 150 LEDs in the full strip
#define PATTERN_LEN 4
int Light_per_row = NUM_LEDS/PATTERN_LEN;
int BRIGHTNESS = 5;

CRGB leds[NUM_LEDS];
CRGB pattern[PATTERN_LEN] = { CRGB::Red, CRGB::Green, CRGB::Blue, CRGB::Yellow};

void setup() {
  Serial.begin(115200);
  delay( 3000 ); // power-up safety delay
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );
}

void row_LED(int i, CRGB color){
  for(int j= Light_per_row*(i); j<Light_per_row*(i+1); j++){
    leds[j] = color;
  }
  FastLED.show();
  delay(500);
  for(int j=Light_per_row*(i); j<Light_per_row*(i+1); j++){
    leds[j] = CRGB::Black;
  }
  FastLED.show();
}

void loop() { 
  for (int i = 0; i < PATTERN_LEN; i = i + 1) {
    row_LED(i, pattern[i]);
  }  
}
