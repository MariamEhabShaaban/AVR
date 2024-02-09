




#include "DIO/DIO_int.h"
#include "_ADC_/ADC_int.h"
#include "LCD/LCD_int.h"
#include <util/delay.h>
int main(){
DIO_enuInit();
ADC_enu_Int();
LCD_enuInit();

u16 adcread;
DIO_enuSetPinDirection(DIO_u8PORTD,DIO_u8PIN0,DIO_u8OUTPUT);


		while(1){
			adcread=ADC_u16_Read();

							f32 output=(adcread*5000UL)/1024.0;
							LCD_enuDisplayIntegerNum((s32)adcread);

					if(output>4996){
						DIO_enuSetPinValue(DIO_u8PORTD,DIO_u8PIN0,DIO_u8HIGH);
					}
					else{
							DIO_enuSetPinValue(DIO_u8PORTD,DIO_u8PIN0,DIO_u8LOW);

					}
		}



	return 0;
}
