#include "stdTypes.h"
#include "errorStates.h"
#include "DIO_int.h"
#include <util/delay.h>
int main(void){
	LED_enuint();
while(1){
	PIN_LED_ON(D_u8PORTA ,D_u8PIN0);
	_delay_ms(500);
	PIN_LED_OFF(D_u8PORTA ,D_u8PIN0);
	_delay_ms(500);

}

	return 0;
}

