#pragma once // tells the compiler to include the header file only once per source file
#include <Arduino.h>
#include <stdint.h>
#include "RadarParser.h"

class Radar {
    public:
        Radar(HardwareSerial& port);

        void        init(int8_t rx, int8_t tx);
        void        update();
        bool        isPresent();
        uint16_t    getEnergy(uint8_t gate);
        bool        hasFault();
    private:
        void sendCommand(const uint8_t* command, const uint8_t command_length);

        HardwareSerial& _port;
        RadarParser     _parser;
        uint32_t        _lastMS     =   0;
        bool            _hasFrame   =   false;

};