/*
 * main.c
 *
 *  Created on: Sep 7, 2021
 *      Author: Ahmed El-Gaafrawy
 */
#include "stdTypes.h"
#include "errorStates.h"
#include "Led_config.h"
#include "Led_int.h"
#include "DIO_int.h"
#include <util/delay.h>
extern  LED_t LED_CONFIG[LED_NUM];
int main(void)
{
	DIO_enuInit();
	LED_enuint(LED_CONFIG);
	while(1){
		LED_ON(&LED_CONFIG[0]);
		_delay_ms(500);
		LED_ON(&LED_CONFIG[1]);
		_delay_ms(500);

		LED_OFF(&LED_CONFIG[0]);
				_delay_ms(500);
				LED_OFF(&LED_CONFIG[1]);



	}

			return 0;
}
