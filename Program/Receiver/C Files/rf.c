#include "rf.h"

#ifdef RF_RECEIVER_ENABLE
	void RFRxInit(void) {
		RFDDR &= 0x03;
		RFPORT |= 0x03;
		RFVdInit();
	}
	void RFVdInit(void) {
		RFDDR &= ~_BV(RFVD_PIN);
		RFPORT |= _BV(RFVD_PIN);
	}
	int8u RFRx(void) {
		if (RF_PPIN & _BV(RFVD_PIN))
			return (RF_PPIN >> 4);
		else
			return 0;
	}
#endif

#ifdef RF_TRANSMITTER_ENABLE
	void RFTxInit(void) {
		RFDDR |= _BV(RFEN_PIN);
		RFPORT |= _BV(RFEN_PIN);
		RFDDR |= 0xF0;
		RFPORT &= 0x0F;
		
	}
	void RFTx(int8u x){
		RFPORT = (RFPORT & 0x0F) | (x << 4);
		EnRF();
	}
	void trans(const char *str) {
		int8u i;
		rfinit();
		RFPORT = (RFPORT & 0X0F) | ('<' & 0xF0);
		EnRF();
		RFPORT = (RFPORT & 0X0F) | ('<' << 4);
		EnRF();
		for (i = 0; str[i] != '\0'; i++) {
			RFPORT = RFPORT & 0X0F | (str[i] & 0xF0);
			EnRF();
			RFPORT = RFPORT & 0X0F | (str[i] << 4);
			EnRF();
		}
		RFPORT = RFPORT & 0X0F | ('>' & 0xF0);
		EnRF();
		RFPORT = RFPORT & 0X0F | ('>' << 4);
		EnRF();
	}
#endif

#ifdef  RF_ENABLE_ONLY
	void RFEnInit(void) {
		RFDDR |= _BV(RFEN_PIN);
		RFPORT |= _BV(RFEN_PIN);
	}
#endif
