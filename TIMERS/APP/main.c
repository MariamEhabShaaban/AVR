/*
 * main.c
 *
 *  Created on: Feb 22, 2024
 *      Author: repair
 */



#include "../MCAL/Timer/Timer_int.h"
#include "../MCAL/DIO/DIO_int.h"
int main() {


	Timer_enu_init();
	DIO_enuSetPinDirection(DIO_u8PORTB,DIO_u8PIN3,DIO_u8OUTPUT);

	while (1) {


		Timer_enu_Generate_PC_PWM(0.725);


	}


	return 0;
}

