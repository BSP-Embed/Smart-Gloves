#include "light.h"

void LightInit(void) {
	LIGHT_DDR 	|= _BV(LIGHT_PIN);
	LIGHT_PORT 	&= ~_BV(LIGHT_PIN);
}
void LightOn(void) {
	LIGHT_PORT |= _BV(LIGHT_PIN);
}
void LightOff(void) {
	LIGHT_PORT &= ~_BV(LIGHT_PIN);
}
