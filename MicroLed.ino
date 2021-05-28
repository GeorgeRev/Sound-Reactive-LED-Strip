#include <FastLED.h>

#define LED_PIN 7
#define READ_PIN A0                     // analogue pin of arduino nano

#define NUM_LEDS      145
#define BRIGHTNESS    255
#define LED_TYPE      WS2812B
#define COLOR_ORDER   GRB
CRGB leds[NUM_LEDS];

void setup() {

  pinMode(READ_PIN,INPUT); //microphone
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );

}

void loop()
{
  
  float soundstate = analogRead(READ_PIN);
  int numLedsToLight = map(soundstate, 0, 1023, 0, NUM_LEDS);                   // mapping the values taken from the microphone to the number of available LEDs
  FastLED.clear();
  
  for(int led = 0; led < numLedsToLight; led++) { 
    leds[led] = CRGB::Red;                                                      // colour of LEDs
  }
  FastLED.show();

}
