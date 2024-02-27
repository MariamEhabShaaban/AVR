/*
 * Timer_prog.c
 *
 *  Created on: Feb 22, 2024
 *      Author: repair
 */
#include "Timer_int.h"
#include "../../interrupt.h"
static void* (*Global_p_Fun)(void*) = NULL;
static void *Gparameter = NULL;
static u8 counts = 0;
u32 Int_Num_OVF;
u8 preload;
ES_t Timer_enu_init() {
	u8 Local_error_state = ES_NOK;
#if Timer0_State==Enable
	TCCR0 = 0;
	SREG |= (1 << 7);
	Local_error_state = ES_OK;
#if Timer0_Mode==OVR
	TCCR0 &= ~(1 << 3);
	TCCR0 &= ~(1 << 6);
	Local_error_state = ES_OK;

#elif Timer0_Mode==CTC
	TCCR0 |= (1 << 3);
	TCCR0 &= ~(1 << 6);
  #if CTC_MODE==TOGGLE
	TCCR0 |= (1 << 4); //tog each compare match
	Local_error_state = ES_OK;
  #endif

#elif Timer0_Mode==FPWM
	TCCR0 |= (1 << 3);
	TCCR0 |= (1 << 6);

	Local_error_state = ES_OK;
#elif Timer0_Mode==PC_PWM
	TCCR0 &= ~(1 << 3);
	TCCR0 |= (1 << 6);
	Local_error_state = ES_OK;
#endif
#if Prescslar == pre_64
	TCCR0 |= (3 << 0);
	Local_error_state = ES_OK;
#elif Prescslar == pre_1024
	TCCR0 |= (5 << 0);
	Local_error_state = ES_OK;
#endif
#endif

	return Local_error_state;
}
ES_t Timer_enu_Asyn_Delay(u32 Time, void* (*CpFun)(void*), void * parameter) {
	u8 Local_error_state = ES_NOK;

	if (CpFun != NULL) {
		Global_p_Fun = CpFun;
		Gparameter = parameter;
		f32 OVF_time = 256 * ((f32) Prescslar / F_CPU);

		if (Time > OVF_time) {
			f32 Num_OVF = Time / OVF_time; //19.073
			if (Num_OVF - (u32) Num_OVF != 0.0) {
				Int_Num_OVF = (u32) Num_OVF + 1; //20
				Num_OVF = Num_OVF - (u32) Num_OVF; //.073
				preload = 256 - (Num_OVF * 256);
				TCNT0 = preload;
			}
			TIMSK |= (1 << 0);
			if (counts == Int_Num_OVF) {
				TCNT0 = preload;
				Global_p_Fun(Gparameter);
				counts = 0;
			}

		} else {
			OCR0 = (Time / OVF_time) * 256;
			TIMSK |= (1 << 1);

		}
	} else
		Local_error_state = ES_NULL_POINTER;

	return Local_error_state;

}

ES_t Timer_enu_syn_Delay(u32 Time) {
	ES_t Local_enuErrorState = ES_NOK;
	f32 OVF_time = 256 * ((f32) Prescslar / F_CPU);

	if (Time > OVF_time) {
		f32 Num_OVF = Time / OVF_time; //19.073
		if (Num_OVF - (u32) Num_OVF != 0.0) {
			Int_Num_OVF = (u32) Num_OVF + 1; //20
			Num_OVF = Num_OVF - (u32) Num_OVF; //.073
			preload = 256 - (Num_OVF * 256);
			TCNT0 = preload;
		}
		while (Int_Num_OVF--) {
			while (((TIFR >> 1) & 1) == 0)
				;
			TIFR |= (1 << 1);
		}
	}
	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;

}
#if Timer0_Mode==FPWM
ES_t Timer_enu_Generate_FPWM(f32 Copy_desired_top) {
	u8 Local_error_state = ES_NOK;


	f32 duty = (Copy_desired_top / 5) * (Copy_desired_top / 5);
#if FPWM_MODE==SET_TOP
	TCCR0 |= (2 << 4);
	OCR0 = (u8) (duty * 256);
	Local_error_state = ES_OK;
#elif  FPWM_MODE==CLEAR_TOP
	TCCR0|=(3<<4);
	OCR0=255-(duty*256);
	Local_error_state = ES_OK;
#endif

	return Local_error_state;
}
#elif Timer0_Mode==PC_PWM
ES_t Timer_enu_Generate_PC_PWM(f32 Copy_desired_top){


	u8 Local_error_state = ES_NOK;

		f32 duty = (Copy_desired_top / 5) * (Copy_desired_top / 5);
	#if PC_PWM_MODE== CLEAR_UP_SET_DOWN

		TCCR0 &=~ (1 << 4);
		TCCR0 |= (1 << 5);
		OCR0 = (u8) (duty * 255);
		Local_error_state = ES_OK;
	#elif  PC_PWM_MODE== SET_UP_CLEAR_DOWN
		TCCR0|=(3<<4);
		OCR0=(1-duty)*255;
		Local_error_state = ES_OK;
	#endif

		return Local_error_state;

}
#endif
ISR(VECT_TIMER0_OVR) {

	counts++;

}

ISR(VECT_TIMER0_CTC) {
	if (Global_p_Fun != NULL)
		Global_p_Fun(Gparameter);

}
