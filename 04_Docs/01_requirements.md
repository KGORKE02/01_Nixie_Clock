# Requirements — Nixie Clock

## Requirements

### General
  #### Modularity
  - Each module (power stages, driver, encoder) is a separate PCB, designed individually
  - Main PCB interconnects all modules

  ### Hardware
  #### Mechanical
  - Simple wooden housing
  #### Display
  - 6x IN-14 Nixie tubes
  - Driven via HV5530PG-G
  #### Power
  - Input: USB-C Power Delivery, 20V
  - 20V → 200V (boost, LT3757) for Nixie tubes
  - 20V → 12V (buck, OTS IC) for Nixie driver
  - 20V → 5V (buck, OTS IC) for ESP32
  ### Sensing
  - Human presence: Waveshare 24GHz FMCW mmWave radar (GPIO/UART, 3.3V)
  #### Compute
  - Waveshare ESP32-S3-DEV-KIT-N8R8

  ### Software
  #### Timekeeping
  - Primary: NTP sync via WiFi
  - Fallback: DS3231 RTC (CR2032 backup battery) when WiFi/NTP unavailable
  - Manual time set via rotary encoder when in fallback mode

## Result Architecture

### Overview
<p align="left">
  <img src="NIXIE_CLOCK-Overview.png" alt="Overview" width="800">
</p>

### Power Tree
<p align="left">
  <img src="NIXIE_CLOCK-Power_Tree.png" alt="Power Tree" width="800">
</p>

### Signal Flow
<p align="left">
  <img src="NIXIE_CLOCK-Signal_Flow.png" alt="Signal Flow" width="800">
</p>

### Modules
  #### 01_MainPCB
  1. 
  2. ...
  #### 02_USBPD_Supply
  1. 
  2. ...
  #### 03_Buck_12V
  1. 
  2. ...
  #### 06_RotaryEncoder
  1. 
  2. ...