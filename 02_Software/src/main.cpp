#include <Arduino.h>
#include "pins.h"
#include "LedStrip.h"
#include "Radar.h"

// RgbLed
LedStrip  onboardLed(pins::OB_LED, 1); // Onbord RGB LED on ESP32 Dev Kit, no pinMode needed.
Radar     HumanPresenceRadar(Serial1); // Waveshare Radar Module is connected to U1

void setup() {
  // Initialize Rgb LED
  onboardLed.begin(); // Onbord RGB LED on ESP32 Dev Kit
  onboardLed.setBrightness(15);
  // Initialize Radar
  HumanPresenceRadar.init(pins::U1_RXD,pins::U1_TXD);

}

void loop() {
  HumanPresenceRadar.update();
  if(HumanPresenceRadar.hasFault()){
    onboardLed.fill(Colors::RED);
  } else if(HumanPresenceRadar.isPresent()){
    onboardLed.fill(Colors::GREEN);
  } else {
    onboardLed.fill(Colors::ORANGE);
  }
  onboardLed.show();
  delay(10);
}