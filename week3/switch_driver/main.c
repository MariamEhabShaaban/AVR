#include "stdTypes.h"
#include "errorStates.h"
#include "DIO_int.h"
//#include <util/delay.h>
int main(void){
	DIO_enuint();
	DIO_enuSetPinValue(D_u8PORTA , D_u8PIN0 ,0);
	DIO_enuSetPinValue(D_u8PORTB , D_u8PIN0 ,1);
	    u8  Copy_pu8Value=20;


	while(1){
		ES_t PIN_state=DIO_enuGetPinValue(D_u8PORTB , D_u8PIN0,  &Copy_pu8Value );
	if(	PIN_state==ES_OK){
		if((Copy_pu8Value)==0){
		DIO_enuSetPinValue(D_u8PORTA , D_u8PIN0,1);
		}
		else{
		DIO_enuSetPinValue(D_u8PORTA, D_u8PIN0 ,0);

		}

	}

	}

		return 0;
	}
