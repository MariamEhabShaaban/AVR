/*
 * Timer_config.h
 *
 *  Created on: Feb 22, 2024
 *      Author: repair
 */

#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_
#include "../../LIB/stdTypes.h"

#define Timer0_Mode OVR //CTC  PWM
#define Timer0_State Enable
#define FPWM_MODE SET_TOP
#define Prescslar   pre_1024
#define F_CPU 1000UL

#endif /* TIMER_CONFIG_H_ */
