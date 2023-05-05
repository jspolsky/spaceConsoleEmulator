//
// Jetpack Joel's color patterns
//
// Want to write your own color patterns? Start by using jetpack.h/.cpp as
// the template. Change the namespace and file names. Include them in 
// spaceConsole.cpp.
//
// you can use any features of FastLED.
// To access the LED array, use the functions
// made available in roof.h. Don't access the leds[] array directly,
// as roof.h/roof.cpp provide abstractions over the physical
// hardware which are different in the simulator.
//

#define FASTLED_INTERNAL
#include <FastLED.h>
#include "roof.h"
#include "jetpack.h"

namespace Jetpack {

  void setup() {
    
    // called once when the controller is powered up

  }
  
  void slowRainbow() {

    static uint8_t hue = 0;       // use "static" to keep values around for the next time through the loop

    //
    // FastLED has handy functions like EVERY_N_MILLIS() for causing things to 
    // happen on a schedule.
    //

    EVERY_N_MILLIS(10) {        
      hue += 1;
    }

    // Colors can be specified using CRGB() or CHSV(). 
    // CHSV is better for getting pretty rainbows - just use 0..255 as the hue

    Roof::SetRingColor(0, CHSV(hue, 255, 255));
    Roof::SetRingColor(1, CHSV(hue + 20, 255, 255));
    Roof::SetRingColor(2, CHSV(hue + 30, 255, 255));
    Roof::SetRingColor(3, CHSV(hue + 50, 255, 255));
    Roof::SetRingColor(4, CHSV(hue + 70, 255, 255));
    Roof::SetRingColor(5, CHSV(hue + 90, 255, 255));

  }

  CRGB palmSpringsPalette[] = {
    CRGB(216, 174, 157),
    CRGB(240, 203, 163),
    CRGB(155, 208, 201),
    CRGB(189, 220, 173),
    CRGB(237, 222, 164),
    CRGB(199, 193, 181),
    CRGB(240, 137, 121),
    CRGB(215, 201, 222),
    CRGB(112, 172, 166),
    CRGB(245, 179, 120)
  };

  void palmSpringsModern() {

    // called continuously; put your color patterns here
    static uint8_t currentColor = 0;
    static Roof::ring_t currentRing = 0;
    static size_t numberOfColors = sizeof(palmSpringsPalette) / sizeof(palmSpringsPalette[0]);

    EVERY_N_MILLIS(500) {
      currentColor = (currentColor + 1) % numberOfColors;
      currentRing = (currentRing + 1) % 6;
      Roof::SetRingColor(currentRing, palmSpringsPalette[currentColor]);
    }

  }

  void edgeTest() {

    static Roof::edge_t edgeNumber = 0;
    
    EVERY_N_MILLIS(100) {

      if (edgeNumber == 0)
      {
        Roof::SetGlobalColor(CRGB::Black);
      }

      Roof::SetEdgeColor(edgeNumber, CRGB::Red);
      edgeNumber = (edgeNumber + 1) % 24;

    }

  }

  void loop() {


    // slowRainbow();
    // palmSpringsModern();
    edgeTest();

  }

}