#include <Arduino.h>
#include "nixie.h"
#include "pins.h"

void setup() {
  // put your setup code here, to run once:

  nixie_init();

}

void loop() {
  // HV supplies
  digitalWrite(ENABLE_12V,  LOW);
  digitalWrite(ENABLE_200V, LOW);

  // HV5530 control lines, safe defaults
  digitalWrite(SR_DIN, LOW);
  digitalWrite(SR_CLK, LOW);
  digitalWrite(SR_LE,  LOW);
  digitalWrite(SR_BLK, LOW); 
  delay(500);
  // HV supplies
  digitalWrite(ENABLE_12V,  HIGH);
  digitalWrite(ENABLE_200V, HIGH);

  // HV5530 control lines, safe defaults
  digitalWrite(SR_DIN, HIGH);
  digitalWrite(SR_CLK, HIGH);
  digitalWrite(SR_LE,  HIGH);
  digitalWrite(SR_BLK, HIGH); 
  delay(500);
}