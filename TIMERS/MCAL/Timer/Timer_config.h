/*
 * Timer_config.h
 *
 *  Created on: Feb 22, 2024
 *      Author: repair
 */

#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_
#include "../../LIB/stdTypes.h"

#define Timer0_Mode PC_PWM //CTC  PWM

#define Timer0_State Enable
#define  CTC_MODE  TOGGLE
#define FPWM_MODE SET_TOP
#define PC_PWM_MODE CLEAR_UP_SET_DOWN
#define Prescslar   pre_64
#define F_CPU 1000UL

#endif /* TIMER_CONFIG_H_ */
