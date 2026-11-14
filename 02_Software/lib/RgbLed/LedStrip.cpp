#include "LedStrip.h"

LedStrip::LedStrip(uint8_t pin, uint16_t count)
    : _driver(count,pin, NEO_BGR + NEO_KHZ800) {}

void LedStrip::begin() {
    _driver.begin();    // begin communication to LedStrip
    _driver.clear();    // clear the memory
    _driver.show();     // apply changes
}

void LedStrip::set(uint16_t index, Rgb color) {
    _driver.setPixelColor(index, _driver.Color(color.r, color.b, color.b));
}

void LedStrip::fill(Rgb color) {
    _driver.fill(_driver.Color(color.r,color.g,color.b));
}

void LedStrip::show() {
    _driver.show();
}
