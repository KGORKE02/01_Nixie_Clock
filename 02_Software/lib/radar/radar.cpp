#include "Radar.h" 
#include <Arduino.h>
#include "RadarProtocol.h" 
#include "RadarParser.h"

Radar::Radar(HardwareSerial& port) 
    : _port(port) {}

void Radar::init(int8_t rx, int8_t tx) {
    _port.begin(RadarProtocol::BAUDRATE, SERIAL_8N1, rx, tx);
    while(!_port)   delay(100);
    _parser.reset();
    sendCommand(RadarProtocol::REPORT_MODE, RadarProtocol::COMMAND_LENGTH);
}

void Radar::update() {
    while (_port.available() > 0) {
        uint8_t incomingByte = _port.read();

        if(_parser.feed(incomingByte)) {
            _hasFrame = true;
            _lastMS = millis();
        }
    }
}

bool Radar::isPresent() {
    return _parser.getFrame().present;
}

uint16_t Radar::getEnergy(uint8_t gate){
    if(gate >= RadarProtocol::NUM_GATES) return 0;
    return _parser.getFrame().energy[gate];
}

bool Radar::hasFault() {
    return ( (millis() - _lastMS) > RadarProtocol::FRAME_TIMEOUT_MS );
}

void Radar::sendCommand(const uint8_t* command, const uint8_t command_length) {
    _port.write(command, command_length);
}