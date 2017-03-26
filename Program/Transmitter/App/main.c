/* Application Program for Smart Gloves */
/* Playback audio corresponding to Sign Language */
/* Written by : Prashanth (BSP Embed)		*/

#include "main.h"

extern int8u lcdptr;
static volatile int8u mode = VOICE;
struct App Flag;

const char *TextMsg[] = {	"It's time to take my pills", 
							"Can u get me today's newspaper?",
							"I'm starving! Can I have my meal",
							"Get me some water to drink!",
							"I need a pertinent attire",
							"I feel sickish, call the doctor!",
							"Critical, need expeditious help!",
							"I need to go the restroom!"  } ;
int main(void) {
	init();
	while (TRUE) {
		if (Flag.ChkSym) {
			ProcessSymb();
			Flag.ChkSym = FALSE;
		}
		sleep_cpu();
	}
	return 0;
}
static void init(void) {
	int8u i;
	buzinit();
	APRinit();
	RFTxInit();
	beep(2,100);
	lcdinit();
	swinit();
	ledinit();
	tmr1init();
	if (SwPress())
		CalibGlove();
	else
		ReadFlexSym();
	disptitl();
	sei();
	sleep_enable();
	sleep_cpu();
}
static void ProcessSymb(void) {
	int8u Sym;
	if (Sym = CheckSym()) {
		beep(1,ALRT_DLY);
		Sym--;
		if (Sym == CONTROL_SIGN) {
			if (mode == VOICE)
				mode = CTRL;
			else
				mode = VOICE;
			DispMode();
			beep(2,250);
		} else
			switch (mode) {
				case VOICE: lcdclr();
							lcdws(TextMsg[Sym]);
							APRVoice(Sym);
							lcdclr(); DispMode(); break;
				case CTRL:	RFTx(Sym+1); break;
			}
	}
}
static void disptitl(void) { 
	lcdclr();
	lcdws("  SMART GloveS");
	DispMode();
}
static void DispMode(void) {
	lcdptr = 0xc1;
	if (mode == VOICE) lcdws("VOICE PLAYBACK");
	else lcdws("DEVICE CONTROL");
}
static void tmr1init(void) {
	TCNT1H   = 225;					/* overflows at every 250msec */
	TCNT1L   = 123;
	TIMSK   |= _BV(TOIE1);			//ENABLE OVERFLOW INTERRUPT
	TCCR1A   = 0x00;					
	TCCR1B  |= _BV(CS12);			 /* PRESCALAR BY 256 */
}
ISR(TIMER1_OVF_vect)  { 
	static int8u i,j;
	TCNT1H   = 225;					/* overflows at every 250msec */
	TCNT1L   = 123;
	
	if (++i >= 40) i = 0;
	switch(i) {
		case 0: case 2: ledon();  break;
		case 1: case 3: ledoff(); break;
	} 
	if (!Flag.ChkSym && ++j >= 2) {
		j = 0;
		Flag.ChkSym = TRUE;
	}
}





