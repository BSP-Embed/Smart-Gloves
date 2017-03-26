#ifndef RF_H
#define RF_H

#include "includes.h"

//DEFINE MACROS
#define EnRF()		do {							\
						RFPORT &= ~_BV(RFEN_PIN);	\
						dlyms(500);					\
						RFPORT |= _BV(RFEN_PIN);	\
						dlyms(200);					\
					} while (0);

/**** FUNCTION PROTOTYPES    ******/
void RFRxInit	(void);
void RFTxInit	(void);
void RFTx		(int8u x);
void trans		(const char *str);
void RFEnInit	(void);

#endif