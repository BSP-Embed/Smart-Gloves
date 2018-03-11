#ifndef SWITCH_H
#define SWITCH_H

#include	"includes.h"

/*********** SWITCH CONFIGURATION ************/
#define SwPress()	Sw1Press()
#define Sw1Press()	((SW_PPIN & _BV(SW1_PIN)) == 0)
#define Sw2Press()	((SW_PPIN & _BV(SW2_PIN)) == 0)

void swinit(void);

#endif