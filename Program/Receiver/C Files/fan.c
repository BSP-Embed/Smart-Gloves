#include "fan.h"

void FanInit(void) {
	FAN_DDR 	|= _BV(FAN_PIN);
	FAN_PORT 	&= ~_BV(FAN_PIN);
}
void FanOn(void) {
	FAN_PORT |= _BV(FAN_PIN);
}
void FanOff(void) {
	FAN_PORT &= ~_BV(FAN_PIN);
}