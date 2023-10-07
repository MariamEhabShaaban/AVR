#include "stdTypes.h"
#include "errorStates.h"
#include "DIO_int.h"
#include <util/delay.h>
int main(void){
	u8 seg []= { 0x3F, 0x06, 0x5B,0x4F, 0x66, 0x6D,0x7D, 0x07, 0x7F,0x6F};
	DIO_enuint();
	DIO_enuSetPortValue(D_u8PORTC , 0x00);
while(1){
	for(u8 i=0;i<10;i++){

		DIO_enuSetPortValue(D_u8PORTC , seg[i]);
		_delay_ms(500);
	}
}

	return 0;
}

