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

  const uint32_t edge_endpoints[24][2] = 
  {
    {266, 299},
    {191, 224},
    {116, 149},
    {525, 558},
    {450, 483},
    {375, 408},

    {825, 858},
    {750, 783},
    {675, 708},
    {1166, 1199},
    {1091, 1124},
    {1016, 1049},

    {559, 599},
    {225, 265},
    {484, 524},
    {150, 190},
    {409, 449},
    {75, 115},
    {859, 899},
    {1125, 1165},
    {784, 824},
    {1050, 1090},
    {709, 749},
    {975, 1015}
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

  void SetEdgeColor(edge_t edge, CRGB color) {

    for (uint32_t i = edge_endpoints[edge][0]; i <= edge_endpoints[edge][1]; i++)
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
