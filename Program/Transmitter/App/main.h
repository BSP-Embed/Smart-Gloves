#ifndef MAIN_H
#define MAIN_H

#include "includes.h"

//DEFINE CONSTANT
#define CONTROL_SIGN		8	

enum {VOICE = 1, CTRL};

//FUNCTION PROTOTYPES
static void		 init		(void);
static void 	disptitl 	(void);
static void 	tmr1init	(void);
static void		EXT0init	(void);	
static void		gpioinit	(void);
static void		DispMode	(void);
static void		ProcessSymb	(void);

#endif
