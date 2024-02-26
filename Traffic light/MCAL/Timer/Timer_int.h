/*
 * Timer_int.h
 *
 *  Created on: Feb 22, 2024
 *      Author: repair
 */

#ifndef TIMER_INT_H_
#define TIMER_INT_H_
#include "../../LIB/errorStates.h"
#include "../../LIB/stdTypes.h"
#include "Timer_priv.h"
#include "Timer_config.h"

ES_t Timer_enu_init();

ES_t  Timer_enu_Asyn_Delay(u32 Time, void* (*CpFun)(void*), void * parameter);
ES_t Timer_enu_syn_Delay(u32 Copy_u8Time);
ES_t Timer_enu_Generate_PWM(f32 Copy_desired_top);

#endif /* TIMER_INT_H_ */
