#ifndef FLEX_SENSOR_H
#define FLEX_SENSOR_H

#include "includes.h"

void	FlexSensInit	(void);

void	CalibGlove		(void);
void	ReadFlexSym		(void);
int8u	CheckSym		(void);
#endif