#include "main.h"

int main(void) {
	init();
	while (TRUE)
		sleep_cpu(); 
	return 0;
}
static void init(void) {
	ledinit();
	blink(1,150);
	LightInit();
	FanInit();
	Tmr0Init();
	RFRxInit();
	EXT0init();
	sei();
	sleep_enable();
	sleep_cpu(); 
}
static void EXT0init(void) {
	INTDDR 	&= ~_BV(INT0_PIN);
	INTPORT |= _BV(INT0_PIN);
	GIMSK |= _BV(INT0);			//ENABLE EXTERNAL INTERRUPT
	MCUCR |= _BV(ISC01);		//FALLING EDGE INTERRUPT
}
ISR(INT0_vect) {
	switch ((RF_PPIN & 0x78) >> 3) {
		case 1: LightOn(); break;
		case 2: LightOff(); break;
		case 3: FanOn(); break;
		case 4: FanOff(); break;
	}
	GIMSK |= _BV(INT0);
}
static void Tmr0Init(void) {
	TCNT0   =  60;						/* OverFlows every 25msec */
	TIMSK   |= _BV(TOIE0);				/*ENABLE OVERFLOW INTERRUPT */
	TCCR0B	|= _BV(CS02) | _BV(CS00);	/* Prescalar by 1024 */
}
ISR(TIMER0_OVF_vect) {
	static int8u i,j;
	TCNT0 = 60;
	if (++i >= 200)
		i = 0;
	switch(i) {
			case 0: case 4: ledon(); break;
			case 2: case 6: ledoff(); break;
	}
}