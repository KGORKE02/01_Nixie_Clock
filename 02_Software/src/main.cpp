#include <Arduino.h>
#include "pins.h"
#include "LedStrip.h"

// RgbLed
LedStrip onboardLed(pins::OB_LED, 1); // Onbord RGB LED on ESP32 Dev Kit, no pinMode needed.

void setup() {
  // Initialize Rgb LED
  onboardLed.begin(); // Onbord RGB LED on ESP32 Dev Kit
}

void loop() {
  
  // low brightness every color
  onboardLed.fill(Rgb{31, 0, 0}); onboardLed.show(); // red
  delay(500);
  onboardLed.fill(Rgb{0, 31, 0}); onboardLed.show(); // green
  delay(500);
  onboardLed.fill(Rgb{0, 0, 31}); onboardLed.show(); // blue
  delay(500);

  // low brightness white
  onboardLed.fill(Rgb{31, 31, 31}); onboardLed.show(); // blue
  delay(500);

}