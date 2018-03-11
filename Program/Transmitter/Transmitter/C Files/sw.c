#include "sw.h"

void swinit(void) {
	SW_DDR 		&= ~_BV(SW1_PIN);
	SW_PORT 	|= _BV(SW1_PIN);
	#ifdef SWITCH_TWO
		SW_DDR 	&= ~_BV(SW2_PIN);
		SW_PORT |= _BV(SW2_PIN);
	#endif
}
