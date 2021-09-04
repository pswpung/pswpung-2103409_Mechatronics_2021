#include <FastLED.h>

int LDR_analog = 2;
#define LED_PIN     5
#define NUM_LEDS    64 // 150 LEDs in the full strip
#define PATTERN_LEN 4
int Light_per_row = NUM_LEDS/PATTERN_LEN;

CRGB leds[NUM_LEDS];
CRGB pattern[PATTERN_LEN] = { CRGB::Red, CRGB::Green, CRGB::Blue, CRGB::Yellow};

void setup() {
  Serial.begin(115200);
  delay( 3000 ); // power-up safety delay
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
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

void column_LED(int i, CRGB color){
  for(int j=0; j<NUM_LEDS; j++){
    if (j%8 == 2*i || j%8 == (2*i)+1){
      leds[j] = color;
    }
  }
  FastLED.show();
  delay(500);
  for(int j=0; j<NUM_LEDS; j++){
    if (j%8 == 2*i || j%8 == (2*i)+1){
      leds[j] = CRGB::Black;
    }
  }
  FastLED.show(); 
}

void loop() { 
  int analog_value = analogRead(LDR_analog);
  Serial.println(analog_value);
  float BRIGHTNESS = ((4095-analog_value)*128/4095);
  Serial.println(BRIGHTNESS);
  FastLED.setBrightness(  BRIGHTNESS );
  if (analog_value <= (4095/2)){
    for (int i = 0; i < PATTERN_LEN; i = i + 1) {
      column_LED(i, pattern[i]);
    }
  } else {
    for (int i = 0; i < PATTERN_LEN; i = i + 1) {
      row_LED(i, pattern[i]);
    }      
  }
}
