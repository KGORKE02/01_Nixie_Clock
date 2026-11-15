#pragma once
#include "RadarFrame.h"
#include "RadarProtocol.h"

class RadarParser {
    public:
        bool feed(uint8_t incomingByte);
        const RadarFrame& getFrame() const;
        void reset();
    private:
        uint8_t _buffer[RadarProtocol::FRAME_LEN] = {};
        uint8_t _count = 0;
        RadarFrame _frame{};    // Frame initialized with RadarFrame.h defaults
        void decode();
};
