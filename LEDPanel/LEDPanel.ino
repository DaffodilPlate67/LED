#include <Adafruit_GFX.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>

#include <FastLED.h>        
#include <LEDMatrix.h>    

// Change the next defines to match your matrix type and size
#define DATA_PIN            5

#define COLOR_ORDER         GRB
#define CHIPSET             WS2811

// initial matrix layout (to get led strip index by x/y)
#define MATRIX_WIDTH        16
#define MATRIX_HEIGHT       16
#define MATRIX_TYPE         HORIZONTAL_ZIGZAG_MATRIX
#define MATRIX_SIZE         (MATRIX_WIDTH*MATRIX_HEIGHT)
#define NUMPIXELS           MATRIX_SIZE

// create our matrix based on matrix definition
cLEDMatrix<MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_TYPE> leds;

void setup() {
  // initial FastLED by using CRGB led source from our matrix class
  FastLED.addLeds<CHIPSET, DATA_PIN, COLOR_ORDER>(leds[0], leds.Size()).setCorrection(TypicalSMD5050);
  FastLED.setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(10);
  FastLED.clear(true);
}

void loop() {
  int16_t sx, sy, x, y, xc, yc, r;
  uint8_t h;
  //IMPORTANT NOTE:
  //These functions use coordinates x,y
  //But for some reason x is the one that goes down and y is to the right
  for (x = 0; x < (leds.Width() + leds.Height()); x++)
  {
    leds.DrawCircle(8, 8, 6, CRGB::Purple);
    leds.DrawCircle(5,6,1, CRGB::Blue);
    leds.DrawCircle(5,10,1, CRGB::Blue);
    leds.DrawRectangle(10,5,11,11, CRGB::Green);
  }
  FastLED.show();
}

