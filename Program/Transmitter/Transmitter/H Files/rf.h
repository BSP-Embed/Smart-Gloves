#ifndef RF_H
#define RF_H

#include "includes.h"

#define RFEnLow()		RFPORT &= ~_BV(RFEN_PIN)
#define RFEnHigh()		RFPORT |= _BV(RFEN_PIN)

//DEFINE MACROS
#define EnRF()		do {			\
						RFEnLow();	\
						dlyms(500);	\
						RFEnHigh();	\
						dlyms(200);	\
					} while (0);

#define RFNull()	RFPORT &= 0x0F

/**** FUNCTION PROTOTYPES    ******/
void RFRxInit	(void);
void RFTxInit	(void);
void RFTx		(int8u x);
void trans		(const char *str);
void RFEnInit	(void);

#endif