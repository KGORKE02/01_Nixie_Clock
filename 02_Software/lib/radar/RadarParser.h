#pragma once
#include <stdint.h>
#include "RadarFrame.h"

class RadarParser {
    public:
        uint8_t _buffer[45];
        uint8_t _count;
        RadarFrame _frame;
        bool feed(uint8_t byte);
        const RadarFrame& getFrame();
        void reset();
    private:
        void decode();
}
