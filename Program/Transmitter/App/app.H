#ifndef _APP_H
#define _APP_H

/************** LCD PIN DEFINITION  *************/
#define LCD_DDR           	   		DDRC 
#define LCD_DATA_PORT          		PORTC
#define LCD_ENABLE_PIN        		PC3 
#define LCD_REGISTER_SELECT_PIN     PC2
#define DISPLAY_INIT				1
#define LCD_NSCRL					1
#define FLOAT_T0_STRING				1
#define DECIMAL_PRECISION			100
/*************************************************/

/*********** BUZZER PIN DEFINITION  ****************/
#define	BUZ_DDR			DDRC
#define	BUZ_PORT		PORTC
#define	BUZ_PIN			PC1
#define OFF_TIME		100
/******** BUZZER CONFIGURATION ENDS ****************/

/********** LED PIN DEFINITION  ******************/
#define	LED_DDR			DDRC
#define	LED_PORT		PORTC
#define	LED_PIN			PC0
#define OFF_TIME		100
/********************************************/

/******** APR PIN DEFINITION *****************/
#define APR_DDR			DDRB
#define APR_PORT		PORTB
/*********************************************/

/******** ADC CONFIGURATION*******************/
#define REF_VOL_256	
/*********************************************/

/********* RF PIN DEFINTION *************/
#define RFDDR			DDRD
#define RFPORT			PORTD
#define RFEN_PIN		PD3
#define RF_TRANSMITTER_ENABLE
/***************************************/

/********* SWITCH PIN DEFINITION *******/
#define SW_DDR		DDRD
#define SW_PORT		PORTD
#define SW_PIN		PD2
#define	SW_PPIN		PIND
/**************************************/

/********* FLEX SENSOR PIN DEFINITION ***/
#define DELTA				5
#define MAX_SYMBOL			9
/***************************************/

/******* STRUCTURE DEFINITION *********/
struct App {
	volatile char Sym:1;
	volatile char ChkSym:1;
};
/*************************************/

#endif
