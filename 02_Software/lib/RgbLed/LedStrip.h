#pragma once
#include <Adafruit_Neopixel.h>
#include <stdint.h>
#include "rgb.h"

class LedStrip{
    public:
        LedStrip(uint8_t pin, uint16_t count); // Constructor of class

        // methods
        void begin();   // begin Led
        void set(uint16_t index, Rgb color);        // changes data memory
        void fill(Rgb color);                       // changes data memory
        void show();                                // applies changes

    private:
        Adafruit_NeoPixel _driver;                  // composition: strip owns the driver
};
