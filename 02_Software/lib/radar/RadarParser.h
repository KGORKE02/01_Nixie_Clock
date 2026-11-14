#pragma once
#include <stdint.h>
#include "RadarFrame.h"
#include "RadarProtocol.h"

class RadarParser {
    public:
        bool feed(uint8_t byte);
        const RadarFrame& getFrame();
        void reset();
    private:
        uint8_t _buffer[45];
        uint8_t _count;
        RadarFrame _frame;
        void decode();
};
