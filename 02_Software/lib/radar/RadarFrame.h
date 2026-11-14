#pragma once
#include <stdint.h>

struct RadarFrame {
    bool        present;
    uint16_t    distance;      // distance in cm
    uint16_t energy[16];    // energy in dB
};