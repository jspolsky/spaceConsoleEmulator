#define FASTLED_INTERNAL
#include <FastLED.h>
#include "roof.h"

namespace Roof
{

  #define NUM_LEDS 1200

  // Define the array of leds
  CRGB leds[NUM_LEDS];

  const uint32_t ring_endpoints[6][4] =
  { 
    { 225, 299, 525, 599 },
    { 150, 224, 450, 524 },
    { 75, 149, 375, 449 },
    { 825, 899, 1125, 1199 },
    { 750, 824, 1050, 1124 },
    { 675, 749, 975, 1049 }
  };

  const uint32_t edge_endpoints[6][8] = 
  {
    {299,266,265,225,525,558,559,599},
    {224,191,190,150,450,483,484,524},
    {149,116,115,75,375,408,409,449},
    {858,825,1125,1165,1166,1199,899,859},
    {783,750,1050,1090,1091,1124,824,784},
    {708,675,975,1015,1016,1049,749,709}
  };

  const uint32_t edge_endpoints_hd[6][8] = 
  {
    {1199,1064,1063,900,2100,2235,2236,2399},
    {899,764,763,600,1800,1935,1936,2099},
    {599,464,463,300,1500,1635,1636,1799},
    {3435,3300,4500,4663,4664,4799,3599,3436},
    {3135,3000,4200,4363,4364,4499,3299,3136},
    {2835,2700,3900,4063,4064,4199,2999,2836}
  };

  //
  // Simulator: Sets one LED out of 1200
  // Real life: Sets four contiguous LEDs out of 4800
  //
  void SetLed(uint32_t i, CRGB color) {
    leds[i] = color;
  }

  //
  // Simulator: if !(i % 4) sets one LED out of 1200
  // Real life: Sets one LED out of 4800
  //
  void SetLedHD(uint32_t i, CRGB color) {
    if (!(i % 4)) {
      leds[i / 4] = color;
    }
  }

  void SetRingColor(ring_t ring, CRGB color) {

    for (uint32_t i = ring_endpoints[ring][0]; i <= ring_endpoints[ring][1]; i++)
      SetLed(i, color);
    for (uint32_t i = ring_endpoints[ring][2]; i <= ring_endpoints[ring][3]; i++)
      SetLed(i, color);

  }

  void SetEdgeColor(ring_t ring, edge_t edge, CRGB color) {
  
    uint32_t endpoint[2];
    endpoint[0] = min(edge_endpoints[ring][edge * 2], edge_endpoints[ring][edge * 2 + 1]);
    endpoint[1] = max(edge_endpoints[ring][edge * 2], edge_endpoints[ring][edge * 2 + 1]);

    for (uint32_t i = endpoint[0]; i <= endpoint[1]; i++)
      SetLed(i, color);

  }

  void SetRingPixel(ring_t ring, uint32_t pixel, CRGB color) {

    // for the purpose of this function each ring is deemed to have 150 pixels
    // numbered 0..149, starting at the *center* of the *back* of the ring and
    // running clockwise when looking down on the camp.

    uint32_t physical = 0;

    // Where does this pixel land?
    if (pixel < 17) {
      // top right
      physical = map(pixel, 0, 16, edge_endpoints[ring][0] - 17, edge_endpoints[ring][1]);
    }
    else if (pixel < 58) {
      // right
      physical = map(pixel, 17, 57, edge_endpoints[ring][2], edge_endpoints[ring][3]);
    }
    else if (pixel < 92) {
      // bottom
      physical = map(pixel, 58, 91, edge_endpoints[ring][4], edge_endpoints[ring][5]);
    }
    else if (pixel < 133) {
      // left
      physical = map(pixel, 92, 132, edge_endpoints[ring][6], edge_endpoints[ring][7]);
    }
    else if (pixel < 150) {
      physical = map(pixel, 133, 150, edge_endpoints[ring][0], edge_endpoints[ring][1] + 16);
    }
    else {
      // error
    }

    SetLed(physical, color);

  }

  void SetRingPixelHD(ring_t ring, uint32_t pixel, CRGB color)
  {
    // for the purpose of this function each ring is deemed to have 600 pixels
    // numbered 0..599, starting at the *center* of the *back* of the ring and
    // running clockwise when looking down on the camp.

    uint32_t physical = 0;

    // Where does this pixel land?
    if (pixel < 68 /* 17 */ ) {
      // top right
      physical = map(pixel, 0, 67 /* 16 */, edge_endpoints_hd[ring][0] - 68 /* 17 */, edge_endpoints_hd[ring][1]);
    }
    else if (pixel < 232 /* 58 */) {
      // right
      physical = map(pixel, 68 /* 17 */, 231 /* 57 */, edge_endpoints_hd[ring][2], edge_endpoints_hd[ring][3]);
    }
    else if (pixel < 368 /* 92 */) {
      // bottom
      physical = map(pixel, 232 /* 58 */, 367 /* 91 */, edge_endpoints_hd[ring][4], edge_endpoints_hd[ring][5]);
    }
    else if (pixel < 532 /* 133 */) {
      // left
      physical = map(pixel, 368 /* 92 */, 531 /* 132 */, edge_endpoints_hd[ring][6], edge_endpoints_hd[ring][7]);
    }
    else if (pixel < 600 /* 150 */) {
      physical = map(pixel, 532 /* 133 */, 600 /* 150 */, edge_endpoints_hd[ring][0], edge_endpoints_hd[ring][1] + 67 /* 16 */);
    }
    else {
      // error
    }

    SetLedHD(physical, color);
  }

  void SetRingAngle(ring_t ring, uint32_t degrees, CRGB color)
  {

    // for the purpose of this function each ring is deemed to have 360 pixels
    // numbered 0..359, starting at the *center* of the *back* of the ring and
    // running clockwise when looking down on the camp.

  }

  void SetGlobalColor(CRGB color) {

    for (ring_t ring = 0; ring < 6; ring++) {
      SetRingColor(ring, color);
    }

  }
  
  void setup()
  {
    const uint32_t DATA_PIN = 3;
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
    FastLED.setBrightness(255);
  }

  void loop()
  {
    FastLED.delay(1);
  }
}
