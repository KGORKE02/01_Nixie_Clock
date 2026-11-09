#pragma once                // include this header only once per source file
#include <cstdint>          // fixed-width integer types such as uint8_t

// All pin definitions in one place.
namespace pins {
// constexpr: typed constants, fixed at compile time, no RAM used

// Digital input
constexpr uint8_t PD_POWER_GOOD = 21;  // Pin 27
constexpr uint8_t ENCODER_A     = 11;  // Pin 17
constexpr uint8_t ENCODER_B     = 12;  // Pin 18
constexpr uint8_t ENCODER_SW    = 14;  // Pin 20

// Digital output
constexpr uint8_t SR_DIN        = 42;  // Pin 39
constexpr uint8_t SR_CLK        = 41;  // Pin 38
constexpr uint8_t SR_LE         = 40;  // Pin 37
constexpr uint8_t SR_BLK        = 39;  // Pin 36
constexpr uint8_t LED_COM       = 2;   // Pin 40
constexpr uint8_t ENABLE_12V    = 4;   // Pin 4
constexpr uint8_t ENABLE_200V   = 6;   // Pin 6

// Analog input (all ADC1)
constexpr uint8_t SENSE_5V      = 1;   // Pin 41
constexpr uint8_t SENSE_12V     = 5;   // Pin 5
constexpr uint8_t SENSE_200V    = 7;   // Pin 7

// Analog output

// UART
constexpr uint8_t U1_TXD        = 17;  // Pin 10
constexpr uint8_t U1_RXD        = 18;  // Pin 11

// I2C
constexpr uint8_t I2C_SDA       = 15;  // Pin 8
constexpr uint8_t I2C_SCL       = 16;  // Pin 9

// USB (native USB, do not use as GPIO)
constexpr uint8_t USB_D_N       = 19;  // Pin 25
constexpr uint8_t USB_D_P       = 20;  // Pin 26
} 