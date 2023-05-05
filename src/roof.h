#pragma once

namespace Roof {

  //
  // The LEDs are arranged in 6 "rings" (actually rectangles). From a bird's eye view,
  // the rectangles look like this:
  //
  // +---+---+---+
  // | 0 | 1 | 2 |
  // +---+---+---+
  // | 3 | 4 | 5 |
  // +---+---+---+
  // camp entrance
  //
  // Ring 0 and 2 are above the camp bars. Ring 1 is above the DJ booth. Rings 3, 4, and 5 are above
  // the front of the public area.
  //
  typedef uint8_t ring_t;   // Ring number. There are 6 rings, numbered from 0 to 5.


  //
  // Each ring has four edges and you can refer to one edge at a time. They are numbered as follows:
  //
  //  +--0--+--1--+--2--+
  //  |12 13|14 15|16 17|
  //  +--3--+--4--+--5--+
  //
  //  +--6--+--7--+--8--+
  //  |18 19|20 21|22 23|
  //  +--9--+-10--+-11--+
  // 
  typedef uint8_t edge_t;   // Edge number. There are 24 edges, numbered from 0 to 23.


  // These utility functions can be used by animations to set
  // the color of LEDs. Animations should not access the leds[] array
  // directly, as this array will be a different size in production vs. simulator.

  void SetRingColor(ring_t ring, CRGB color);   // sets an entire ring to the same color.
  void SetEdgeColor(edge_t edge, CRGB color);   // sets on edge of one ring to a specific color
  void SetGlobalColor(CRGB color);              // set the entire roof to the same color.


  void setup();
  void loop();
};