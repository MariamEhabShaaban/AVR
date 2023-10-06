#include "stdTypes.h"
#include "errorStates.h"
#include "DIO_int.h"
#include <util/delay.h>
int main(void){
	DIO_enuint();
    DIO_enuSetPinValue( D_u8PORTA ,D_u8PIN0 , 0x00);

while(1){
	DIO_enuSetPinValue(D_u8PORTA ,D_u8PIN0,0);
	_delay_ms(500);
	DIO_enuSetPinValue(D_u8PORTA ,D_u8PIN0,1);
	_delay_ms(500);

}

	return 0;
}
