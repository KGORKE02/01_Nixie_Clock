#pragma once
#include <stdint.h>

namespace RadarProtocol {

    // ---- Serial ----
    constexpr uint32_t BAUDRATE = 115200;   // default, see https://www.waveshare.com/hmmd-mmwave-sensor.htm

    // ---- Command: switch to report mode (module works in default settings only) ----
    constexpr uint8_t COMMAND_REPORT_MODE[] = {
        0xFD, 0xFC, 0xFB, 0xFA,                          // header
        0x08, 0x00,                                      // data length = 8
        0x12, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,  // command + payload
        0x04, 0x03, 0x02, 0x01                           // tail
    };
    constexpr uint8_t COMMAND_REPORT_MODE_LEN = sizeof(COMMAND_REPORT_MODE);

    // ---- Report-mode frame (45 bytes) ----
    // [0-3] header | [4-5] length | [6] presence | [7-8] distance | [9-40] 16 gates x 2 bytes | [41-44] tail
    constexpr uint8_t FRAME_LEN = 45;
    constexpr uint8_t NUM_GATES = 16;

    constexpr uint8_t FRAME_HEADER[]    = {0xF4, 0xF3, 0xF2, 0xF1};
    constexpr uint8_t FRAME_LEN_FIELD[] = {0x23, 0x00};   // 35 data bytes, little endian
    constexpr uint8_t FRAME_TAIL[]      = {0xF8, 0xF7, 0xF6, 0xF5};

    constexpr uint8_t POS_LENGTH   = 4;
    constexpr uint8_t POS_PRESENCE = 6;
    constexpr uint8_t POS_DISTANCE = 7;   // 2 bytes, little endian
    constexpr uint8_t POS_GATES    = 9;   // 2 bytes per gate, little endian

    // ---- Timing ----
    constexpr uint32_t FRAME_TIMEOUT_MS  = 1000;   // no frame for this long = fault
    constexpr uint32_t RETRY_INTERVAL_MS = 1000;   // pause between command retries

}