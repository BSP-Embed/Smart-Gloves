#include "Flex.h"

extern int8u lcdptr;
extern struct App Flag;

int8u EEMEM SYMBOL_ADDR;
int8u SYM[][5] = {
					93,93,93,93,77,		
					93,93,93,60,93,		
					93,93,40,93,93,		
					93,80,93,93,93,
					70,93,93,93,93,
					93,93,47,76,93,
					93,83,45,93,93,	
					93,87,54,80,85,	
					80,77,53,86,67
				};
				
void FlexSensInit(void) {
		adcinit();
}
int8u CheckSym(void) {
	int8u i,j;
	char TempStr[10];
	int8u FlexVal[5];
	
	for (i = 0; i < 5; i++) {
		FlexVal[i] = adcget(i) / 11;
		itoa(FlexVal[i], TempStr);
		lcdptr = 0x81 + (i * 3);
		lcdws("   ");
		lcdptr = 0x81 + (i * 3);
		lcdws(TempStr);
	}
	for (j = 0; j < MAX_SYMBOL; j++) {
		Flag.Sym = TRUE;
		for (i = 0; i < 5; i++) {
			if ((FlexVal[i] < (SYM[j][i] + DELTA)) && (FlexVal[i] > (SYM[j][i] - DELTA)))
				;
			else {
				Flag.Sym = FALSE;
				break;
			}
		}
		if (Flag.Sym) 
			return j+1;
	}
	return 0;
}
void CalibGlove(void) {
	int8u i, j, FlexVal[5];
	int8u *Addr = &SYMBOL_ADDR;
	char TempStr[10], Text[20];
	
	lcdclr();
	lcdws("Calibrat'g Glove");
	beep(1,75);
	dlyms(500);
	while (SwPress());
		
	for (j = 0; j < MAX_SYMBOL; j++) {
		while (TRUE) {
			for (i = 0; i < 5; i++) {
				FlexVal[i] = adcget(i) / 11;
				itoa(FlexVal[i], TempStr);
				lcdptr = 0x81 + (i * 3);
				lcdws("   ");
				lcdptr = 0x81 + (i * 3);
				lcdws(TempStr);
			}
			if (SwPress()) {
				beep(1,150);
				lcdr2();
				sprintf(Text, "Storing %d SYMBOL", j+1);
				lcdws(Text);
				for (i = 0; i < 5; i++) {
					eeprom_write_byte(Addr++, FlexVal[i]);
					FlexVal[i] = 0;
					dlyms(10);
				}
				break;
			}
		}
	}
	dlyms(500);
	lcdclr();
	lcdws("  Calibrated!!");
	beep(3,75);
	dlyms(500);
	ReadFlexSym();
} 
void ReadFlexSym(void) {
	int8u i, j;
	int8u *Addr = &SYMBOL_ADDR;
	
	for (j = 0; j < MAX_SYMBOL; j++)
		for (i = 0; i < 5; i++)
			SYM[j][i] = eeprom_read_byte (Addr++);
}