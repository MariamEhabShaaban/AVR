/*
 * APP.c
 *
 *  Created on: Feb 24, 2024
 *      Author: repair
 */

#include "AAP.h"

#include "../HAL/LED/LED_config.h"
#include "../HAL/LED/LED_int.h"
#include "../MCAL/GIE/GIE_int.h"
#include "../MCAL/EXTI/EXTI_int.h"
#include "../MCAL/Timer/Timer_int.h"
static u8 i = 0;
extern LED_t LED_CONFIG[LED_NUM];

void traffic_light_init() {

	DIO_enuInit();
	LED_enuint(LED_CONFIG);
	Timer_enu_init();
	EXTI_intialiation();

		GIE_enuEnable();
		EXTI_Enable_INT(0);
		EXTI_CallBack(&pedestrian,0);


}
void cars() {

	for (i = 0; i < 3; i++) {

				LED_ON(&LED_CONFIG[i]);
				Timer_enu_syn_Delay(5000);
				LED_OFF(&LED_CONFIG[i]);

			}

			for (i = 1; i>=1; i--) {
				LED_ON(&LED_CONFIG[i]);
				Timer_enu_syn_Delay(5000);
				LED_OFF(&LED_CONFIG[i]);
		}

}

void pedestrian() {
	if (i == 0) {
		LED_ON(&LED_CONFIG[3]);
		LED_ON(&LED_CONFIG[0]);
		Timer_enu_syn_Delay(5000);
		LED_OFF(&LED_CONFIG[3]);
		LED_OFF(&LED_CONFIG[0]);

	}
	else if (i == 1) {
		LED_ON(&LED_CONFIG[1]);
		LED_ON(&LED_CONFIG[4]);
		Timer_enu_syn_Delay(5000);
		LED_OFF(&LED_CONFIG[4]);
		LED_OFF(&LED_CONFIG[1]);
	}

	else if (i == 2) {
		LED_ON(&LED_CONFIG[2]);
		LED_ON(&LED_CONFIG[5]);
		Timer_enu_syn_Delay(5000);
		LED_OFF(&LED_CONFIG[5]);
		LED_OFF(&LED_CONFIG[2]);
	}


}
