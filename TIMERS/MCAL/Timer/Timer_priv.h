/*
 * Timer_priv.h
 *
 *  Created on: Feb 22, 2024
 *      Author: repair
 */

#ifndef TIMER_PRIV_H_
#define TIMER_PRIV_H_

#define OCR0 *(( volatile u8*)0x5C)
#define TIMSK *(( volatile u8*)0x59)
#define TIFR *(( volatile u8*)0x58)
#define TCCR0 *(( volatile u8*)0x53)
#define TCNT0 *(( volatile u8*)0x2)
#define SREG                *((volatile u8*)0x5F)

#define NO_Ck_source  0
#define pre_0 (0)
#define pre_8 (8)
#define pre_64 (64)
#define pre_256 (256)
#define pre_1024 (1024)
#define EXTF     0
#define EXTR     1

#define Enable 1
#define Disable 0
#define OVR 0
#define CTC 1
#define FPWM 2
#define PC_PWM 3

#define  SET_TOP 78
#define  CLEAR_TOP 77
#define CLEAR_UP_SET_DOWN 100
#define SET_UP_CLEAR_DOWN 101
#define   TOGGLE  75
#endif /* TIMER_PRIV_H_ */
