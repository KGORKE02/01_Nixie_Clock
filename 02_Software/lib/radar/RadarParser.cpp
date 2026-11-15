#include "RadarParser.h"
#include <string.h>

bool RadarParser::feed(uint8_t incomingByte) {
    // return true, if a frame was found
    // Find header
    if(_count < sizeof(RadarProtocol::FRAME_HEADER)){
        if(incomingByte == RadarProtocol::FRAME_HEADER[_count]){
            _buffer[_count++] = incomingByte; // Header byte found, increment _count after byte was written to buffer   
        } 
        else{
            _count = 0;         // No header byte found at _count
            if(incomingByte == RadarProtocol::FRAME_HEADER[0]){ // But maybe, the incomingByte is the first header byte
                _buffer[_count++] = incomingByte; // Header byte found
            }
        }
        return false; // Abort here, the frame is not complete.
    }

    // _count >= 4, so valid header was found!
    
    // Fill the rest of the buffer
    _buffer[_count++] = incomingByte;
    if(_count < RadarProtocol::FRAME_LEN){
        return false; // Abort here, the frame is not complete.
    }

    // Frame completed
    _count = 0; // Initialize for next loop
    if(memcmp(&_buffer[RadarProtocol::FRAME_LEN - sizeof(RadarProtocol::FRAME_TAIL)], RadarProtocol::FRAME_TAIL, sizeof(RadarProtocol::FRAME_TAIL)) == 0){ // Check if Frame Tail is valid
        decode();       // Fetch data from frame
        return true;    // Tail was valid, frame was found
    }
    return false; // No valid frame
}

void RadarParser::decode() {
    // Check human presence
    // 0x01 => presence detected
    // 0x00 => no target detected
    if(_buffer[RadarProtocol::POS_PRESENCE] == 0x01){
        _frame.present = true;

        // Target detected. Get distance:
        //                <     Least significant byte       >   <          Most significant byte              >
        _frame.distance = _buffer[RadarProtocol::POS_DISTANCE] | (_buffer[RadarProtocol::POS_DISTANCE + 1] << 8);
    } else{
        _frame.present = false; // No target detected
        _frame.distance = 0;    // No target, no distance.
    }

    // Get energy values
    for (uint8_t gate = 0; gate < RadarProtocol::NUM_GATES; gate++) {
        uint8_t i = RadarProtocol::POS_GATES + gate * 2;
        _frame.energy[gate] = _buffer[i] | (_buffer[i + 1] << 8);
    }
}

void RadarParser::reset(){
    _count = 0;
    _frame = RadarFrame{};
    memset(_buffer, 0, sizeof(_buffer));
}

const RadarFrame& RadarParser::getFrame() const{
    return _frame;
}