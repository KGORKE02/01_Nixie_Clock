#pragma once
#include <stdint.h>
namespace RadarProtocol {
    constexpr uint8_t   FRAME_LEN       = 45;                       // Frame Length in bytes
    constexpr uint8_t   NUM_GATES       = 16;                       // Number of gate values in frame, each gate delivers a 2 bytes (little endian)
    constexpr uint8_t   POS_PRESENCE    = 6;                        // Index of presence indicating byte in RadarFrame
    constexpr uint8_t   POS_DISTANCE    = 7;                        // First index of the two distance bytes in RadarFrame
    constexpr uint8_t   POS_GATES       = 9;                        // First index of the NUM_GATES bytes in RadarFrame
    constexpr uint8_t   FRAME_HEADER[4] = {0xF4, 0xF3, 0xF2, 0xF1}; // Header of Report-Mode
    constexpr uint8_t   FRAME_TAIL[4]   = {0xF8, 0xF7, 0xF6, 0xF5}; // Tail of Report-Mode
    constexpr uint32_t  BAUDRATE        = 115200;                   // Default baufrate accouding to website https://www.waveshare.com/hmmd-mmwave-sensor.htm?srsltid=AYCX9vKyi4Z2Ddgy9TDvU-rkJhPb4Rf1ln-N2QR6HWqPpBWjownNsebl
    constexpr uint8_t   REPORT_MODE[] = {0xFD, 0xFC, 0xFB, 0xFA, 0x08, 0x00, 0x12, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x03, 0x02, 0x01};
    constexpr uint8_t   COMMAND_LENGTH  = sizeof(RadarProtocol::REPORT_MODE);
    constexpr uint32_t  FRAME_TIMEOUT_MS = 1000;                    // no frame for this long = fault
}