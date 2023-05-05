#include <Arduino.h>
#include "FastLED.h"

#include "roof.h"
#include "jetpack.h"

void setup() {
  Roof::setup();
  Jetpack::setup();
}

void loop() {
  Jetpack::loop();
  Roof::loop();
} //loop
