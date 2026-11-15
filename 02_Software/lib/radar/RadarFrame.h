#pragma once
#include <stdint.h>
#include "RadarProtocol.h"
struct RadarFrame {
    bool        present     = false;                    // default no human present
    uint16_t    distance    = 0;                        // target distance in cm (2 Bytes little endian)
    uint16_t    energy[RadarProtocol::NUM_GATES]  = {}; // energy values for gates (2 Bytes little endian for each gate)
};