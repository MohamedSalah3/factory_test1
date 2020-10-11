/*
 * pushButtonConfig.h
 *
 *  Created on: Oct 21, 2019
 *      Author: Sprints
 */

#ifndef PUSHBUTTONCONFIG_H_
#define PUSHBUTTONCONFIG_H_
#include "registers.h"
#include "Error.h"
#include "std_types.h"
#include "DIO.h"


#define BTN_MAX_NUM		(2)


#define BTN_0_GPIO	GPIOB
#define BTN_0_BIT	BIT0

#define BTN_1_GPIO	GPIOB
#define BTN_1_BIT	BIT1

#define BTN_2_GPIO	GPIOA
#define BTN_2_BIT	BIT2

#define BTN_3_GPIO 	GPIOA
#define BTN_3_BIT	BIT3
#define PRESSED_AND_HOLD 0xff

#endif /* PUSHBUTTONCONFIG_H_ */