# Requirements

## Functional
- FR-01 The clock shall display time as HH:MM:SS on 6 Nixie tubes.
- FR-02 The clock shall synchronize time via NTP over WiFi.
- FR-03 The clock shall keep time without WiFi using a battery-backed RTC.
- FR-04 The user shall be able to set the time manually when NTP is unavailable.
- FR-05 The clock shall [blank/dim] the tubes when no person is present.
- FR-06 The clock shall illuminate the tumes with a backlight.

## Non-Functional
- NFR-01 Power input: USB-C PD at 20 V.
- NFR-02 Each function shall be a separate PCB, connected via a main PCB.
- NFR-03 The housing shall be made of wood.

## Constraints
- C-01 Display tubes: IN-14.
- C-02 MCU: Waveshare ESP32-S3-DEV-KIT-N8R8.
- C-03 Tube driver: HV5530.
- C-04 USB-C PD: STUSB4500.
- C-05 RTC: DS3231.

