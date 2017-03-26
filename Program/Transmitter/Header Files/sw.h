#ifndef SWITCH_H
#define SWITCH_H

#include	"includes.h"

/*********** SWITCH CONFIGURATION ************/
#define SwPress()	((SW_PPIN & _BV(SW_PIN)) == 0)

void swinit(void);

#endif