#include "sw.h"

void swinit(void) {
	SW_DDR 		&= ~_BV(SW_PIN);
	SW_PORT 	|= _BV(SW_PIN);
}
