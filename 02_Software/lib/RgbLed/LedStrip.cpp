#include "LedStrip.h"

LedStrip::LedStrip(uint8_t pin, uint16_t count)
    : _driver(count,pin, NEO_RGB + NEO_KHZ800) {} // The onboard LED order is RGB - Try it out.

void LedStrip::begin() {
    _driver.begin();    // begin communication to LedStrip
    _driver.clear();    // clear the memory
    _driver.show();     // apply changes
}

Rgb LedStrip::scaled(Rgb c) const {
    return Rgb {
        static_cast<uint8_t>(c.r * _brightness / 255), 
        static_cast<uint8_t>(c.g * _brightness / 255), 
        static_cast<uint8_t>(c.b * _brightness / 255 )};
}

void LedStrip::set(uint16_t index, Rgb color) {
    Rgb c = scaled(color);
    _driver.setPixelColor(index, _driver.Color(c.r, c.g, c.b));
}

void LedStrip::fill(Rgb color) {
    Rgb c = scaled(color);
    _driver.fill(_driver.Color(c.r,c.g,c.b));
}

void LedStrip::show() {
    _driver.show();
}
