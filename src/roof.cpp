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
    {858,825,1125,1165,1165,1199,899,859},
    {783,750,1050,1090,1090,1124,824,784},
    {708,675,975,1015,1015,1049,749,709}
  };

  void SetLed(uint32_t i, CRGB color) {
    leds[i] = color;
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
