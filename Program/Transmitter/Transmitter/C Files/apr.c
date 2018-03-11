#include "apr.h"

void APRinit(void){
	APR_DDR	= 0xFF;
	APR_PORT |= 0xFF;
}
void APRVoice(int8u ch){
	APR_PORT &= ~_BV(ch);
	dlyms(100);
	APR_PORT |= _BV(ch);
} 