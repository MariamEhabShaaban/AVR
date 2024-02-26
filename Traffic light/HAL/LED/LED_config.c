/*
 * LED_config.c
 *
 *  Created on: Feb 24, 2024
 *      Author: repair
 */

#include "../../LIB/stdTypes.h"
#include "../../LIB/errorStates.h"
#include "LED_priv.h"
#include "LED_config.h"
#include "../../MCAL/DIO/DIO_int.h"
LED_t LED_CONFIG[LED_NUM] = {
		{ DIO_u8PORTC, DIO_u8PIN7, DIO_SOURCE, DIO_u8LOW }, { DIO_u8PORTC,
				DIO_u8PIN4, DIO_SOURCE, DIO_u8LOW }, { DIO_u8PORTC, DIO_u8PIN2,
				DIO_SOURCE, DIO_u8LOW }, { DIO_u8PORTD, DIO_u8PIN0, DIO_SOURCE,
				DIO_u8LOW }, { DIO_u8PORTD, DIO_u8PIN3, DIO_SOURCE, DIO_u8LOW },
		{ DIO_u8PORTD, DIO_u8PIN6, DIO_SOURCE, DIO_u8LOW } };
