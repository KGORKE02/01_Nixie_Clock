#include <Arduino.h>
#include "pins.h"

void nixie_init() {
  // HV supplies, off first
  pinMode(ENABLE_12V,  OUTPUT);  digitalWrite(ENABLE_12V,  LOW);
  pinMode(ENABLE_200V, OUTPUT);  digitalWrite(ENABLE_200V, LOW);

  // HV5530 control lines, safe defaults
  pinMode(SR_DIN, OUTPUT);  digitalWrite(SR_DIN, LOW);
  pinMode(SR_CLK, OUTPUT);  digitalWrite(SR_CLK, LOW);
  pinMode(SR_LE,  OUTPUT);  digitalWrite(SR_LE,  LOW);
  pinMode(SR_BLK, OUTPUT);  digitalWrite(SR_BLK, LOW); 
}