/*
 * main.c
 *
 *  Created on: Sep 7, 2021
 *      Author: Ahmed El-Gaafrawy
 */
#include "stdTypes.h"
#include "errorStates.h"
#include "Switch_config.h"
#include "Switch_int.h"
#include "DIO_int.h"
#include <util/delay.h>
extern  SW_t SWITCH_CONFIG[SW_NUM];
int main(void)
{
	DIO_enuInit();
	SWITCH_enuint(SWITCH_CONFIG);
	u8 sw_stat;
	while(1){
		if(SWITCH_STATUS(&SWITCH_CONFIG[1],&sw_stat)==ES_OK){
			if(sw_stat==0)
			 DIO_enuSetPinValue(DIO_u8PORTA,DIO_u8PIN1, DIO_u8HIGH);
			else
			 DIO_enuSetPinValue(DIO_u8PORTA,DIO_u8PIN1, DIO_u8LOW);

		}

	}
			return 0;
}
