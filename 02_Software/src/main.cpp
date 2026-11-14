#include <Arduino.h>
#include "pins.h"
#include "LedStrip.h"

// RgbLed
LedStrip onboardLed(pins::OB_LED, 1); // Onbord RGB LED on ESP32 Dev Kit, no pinMode needed.

void setup() {
  // Initialize Rgb LED
  onboardLed.begin(); // Onbord RGB LED on ESP32 Dev Kit
  onboardLed.setBrightness(15);
  onboardLed.fill(Colors::GREEN);
  onboardLed.show();
}

void loop() {

}