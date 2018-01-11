#include <FastLED.h>
#include <LEDMatrix.h>
#include <FastLED_GFX.h>

// Change the next defines to match your matrix type and size
#define DATA_PIN            5

#define COLOR_ORDER         GRB
#define CHIPSET             WS2811

// initial matrix layout (to get led strip index by x/y)
#define MATRIX_WIDTH        16
#define MATRIX_HEIGHT       16
#define MATRIX_TYPE         VERTICAL_ZIGZAG_MATRIX
#define MATRIX_SIZE         (MATRIX_WIDTH*MATRIX_HEIGHT)
#define NUMPIXELS           MATRIX_SIZE
#define BRIGHTNESS          5
// create our matrix based on matrix definition
cLEDMatrix<MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_TYPE> leds;

void setup() {
  // initial FastLED by using CRGB led source from our matrix class
  FastLED.addLeds<CHIPSET, DATA_PIN, COLOR_ORDER>(leds[0], leds.Size()).setCorrection(TypicalSMD5050);
  FastLED.setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);

  //Setup Works
  FastLED.showColor(CRGB::Red);
  delay(1000);
  FastLED.showColor(CRGB::Lime);
  delay(1000);
  FastLED.showColor(CRGB::Blue);
  delay(1000);
  FastLED.showColor(CRGB::White);
  delay(1000);
  FastLED.clear(true);
}

void loop() {
  int16_t sx, sy, x, y, xc, yc, r;
  uint8_t h;
  for (x = 0; x < leds.Size(); x++)
  {
    drawMushroom();
  }
  FastLED.show();
}

void drawMushroom() {
  //Draw Red head
  leds.DrawFilledCircle(8, 6, 7, CRGB(200, 0, 0));
  //Draw white circle thingy
  leds.DrawFilledCircle(8, 5, leds.Width() / 4, CRGB(100, 100, 100));
  //DrawFace outline
  leds.DrawFilledRectangle(5 , 12, 11, 15, CRGB(250, 160, 110));
  //Draw Eyes
  leds.DrawLine(7, 13, 7, 14, CRGB::Black);
  leds.DrawLine(9, 13, 9, 14, CRGB::Black);
  //Draw White part in helmet
  leds.DrawLine(1, 4, 1, 8, CRGB::White);
  leds.DrawLine(2, 2, 2, 10, CRGB::White);
  leds.DrawLine(15, 4, 15, 8, CRGB::White);
  leds.DrawLine(14, 2, 14, 10, CRGB::White);
}



void drawNorwayFlag() {
  int16_t x = (leds.Width() / 4);
  int16_t y = (leds.Height() / 2) - 2;
  leds.DrawFilledRectangle(0, 0, x, y, CRGB(255, 255, 255));
  leds.DrawFilledRectangle(0, 0, x - 1, y - 1, CRGB(255, 0, 0));
  leds.DrawFilledRectangle(x + 3, 0, leds.Width() - 1, y, CRGB(255, 255, 255));
  leds.DrawFilledRectangle(x + 4, 0, leds.Width() - 1, y - 1, CRGB(255, 0, 0));
  leds.DrawFilledRectangle(0, y + 3, x, leds.Height() - 1, CRGB(255, 255, 255));
  leds.DrawFilledRectangle(0, y + 4, x - 1, leds.Height() - 1, CRGB(255, 0, 0));
  leds.DrawFilledRectangle(x + 3, y + 3, leds.Width() - 1, leds.Height() - 1, CRGB(255, 255, 255));
  leds.DrawFilledRectangle(x + 4, y + 4, leds.Width() - 1, leds.Height() - 1, CRGB(255, 0, 0));
  leds.DrawLine(0, y + 1, leds.Width() - 1, y + 1, CRGB(0, 0, 255));
  leds.DrawLine(0, y + 2, leds.Width() - 1, y + 2, CRGB(0, 0, 255));
  leds.DrawLine(x + 1, 0, x + 1, leds.Height() - 1, CRGB(0, 0, 255));
  leds.DrawLine(x + 2, 0, x + 2, leds.Height() - 1, CRGB(0, 0, 255));
}

void drawJapFlag() {
  leds.DrawFilledRectangle(0, 0, leds.Width() - 1, leds.Height() - 1, CRGB::White);
  uint16_t r = min((leds.Width() - 1) / 2, (leds.Height() - 1) / 2) - 1;
  leds.DrawFilledCircle((leds.Width() - 1) / 2, (leds.Height() - 1) / 2, r, CRGB::Red);
}

void drawFace() {
  int16_t x = leds.Width() / 2;
  int16_t y = leds.Height() / 2;
  leds.DrawCircle(x, y, 6, CRGB::Purple);
  leds.DrawCircle(5, 6, 1, CRGB::Blue);
  leds.DrawCircle(10, 6, 1, CRGB::Blue);
  leds.DrawRectangle(5, 10, 11, 11, CRGB::Green);
}

//Function to draw triangles
void drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, CRGB color) {
  leds.DrawLine(x0, y0, x1, y1, color);
  leds.DrawLine(x1, y1, x2, y2, color);
  leds.DrawLine(x2, y2, x0, y0, color);
}

//Function to draw custom quadrilaterals
void drawQuadrilateral(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, int16_t x3, int16_t y3, CRGB color) {
  leds.DrawLine(x0, y0, x1, y1, color);
  leds.DrawLine(x1, y1, x2, y2, color);
  leds.DrawLine(x2, y2, x3, y3, color);
  leds.DrawLine(x3, y3, x0, y0, color);
}

