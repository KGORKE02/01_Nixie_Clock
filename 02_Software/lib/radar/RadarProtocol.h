#pragma once

namespace RadarProtocol {
    constexpr uint8_t   FRAME_LEN       = 45;                       // Frame Length in bytes
    constexpr uint8_t   NUM_GATES       = 16;                       // Number of gate values in frame, each gate delivers a 2 bytes (little endian)
    constexpr uint8_t   FRAME_HEADER[4] = {0xF4, 0xF3, 0xF2, 0xF1}; // Header of Report-Mode
    constexpr uint8_t   FRAME_TAIL[4]   = {0xF8, 0xF7, 0xF6, 0xF5}; // Tail of Report-Mode
    constexpr uint32_t  BAUDRATE        = 115200;                   // Default baufrate accouding to website https://www.waveshare.com/hmmd-mmwave-sensor.htm?srsltid=AYCX9vKyi4Z2Ddgy9TDvU-rkJhPb4Rf1ln-N2QR6HWqPpBWjownNsebl
}