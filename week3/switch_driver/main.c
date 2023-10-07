#include "stdTypes.h"
#include "errorStates.h"
#include "switch_int.h"
#include <util/delay.h>
int main(void){
	SWITCH_enuint();
		 LED_enuint();

		u8 switch_stat=20;
		while(1){

			ES_t Status= SWITCH_STATUS(D_u8PORTB ,D_u8PIN0 , &switch_stat);
			if(Status==ES_OK){

				if(switch_stat==ON){

				PIN_LED_ON(D_u8PORTA ,D_u8PIN0 );
			}
			   else{
				PIN_LED_OFF(D_u8PORTA ,D_u8PIN0 );
			}
			}

}

	return 0;
}
