#ifndef _APP_H
#define _APP_H

/********** LED PIN DEFINTION **********/
#define	LED_DDR			DDRB
#define	LED_PORT		PORTB
#define	LED_PIN			PB2
#define OFF_TIME		100
/**************************************/

/********* RF PIN DEFINITION **********/
#define RFDDR			DDRD
#define RFPORT			PORTD
#define RF_PPIN			PIND
#define RFVD_PIN		PD0
#define RF_RECEIVER_ENABLE	
/**************************************/

/********** LIGHT PIN DEFINITION *****/
#define LIGHT_DDR		DDRB
#define LIGHT_PORT		PORTB
#define LIGHT_PIN		PB7
/*************************************/

/********* FAN PIN DEFINITION ********/
#define FAN_DDR			DDRB
#define FAN_PORT		PORTB
#define FAN_PIN			PB1
/************************************/

/******** INTERRUPT PIN DEFINITION ***/
#define INTDDR			DDRD
#define INTPORT			PORTD
#define	INT0_PIN		PD2
/*************************************/
#endif
