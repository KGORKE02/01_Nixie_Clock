#include "Radar.h" 
#include <Arduino.h>
#include "RadarProtocol.h" 
#include "RadarParser.h"

Radar::Radar(HardwareSerial& port) 
    : _port(port) {}

void Radar::init(int8_t rx, int8_t tx) {
    _port.begin(RadarProtocol::BAUDRATE, SERIAL_8N1, rx, tx);
    _parser.reset();
    sendCommand(RadarProtocol::COMMAND_REPORT_MODE, RadarProtocol::COMMAND_REPORT_MODE_LEN);
}

void Radar::update() {
    // Read data from Sensor and feed the parser with it
    while (_port.available() > 0) {
        if(_parser.feed(_port.read())) { // True, if the frame is complete
            _lastMS = millis(); // Remember when the last frame was detected
        }
    }

    // If the connection was interrupted, try to reconnect
    if(hasFault() && ((millis() - _lastRetryMS) > RadarProtocol::RETRY_INTERVAL_MS) ){
        _parser.reset();
        sendCommand(RadarProtocol::COMMAND_REPORT_MODE, RadarProtocol::COMMAND_REPORT_MODE_LEN);
        _lastRetryMS = millis();
    }
}

bool Radar::isPresent() const {
    return _parser.getFrame().present;
}

uint16_t Radar::getEnergy(uint8_t gate) const {
    if(gate >= RadarProtocol::NUM_GATES) return 0;
    return _parser.getFrame().energy[gate];
}

bool Radar::hasFault() const {
    return ((millis() - _lastMS) > RadarProtocol::FRAME_TIMEOUT_MS);
}

void Radar::sendCommand(const uint8_t* command, const uint8_t command_length) {
    _port.write(command, command_length);
}