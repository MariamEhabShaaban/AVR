



#include "../LIB/stdTypes.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/_ADC_/ADC_int.h"
#include "../HAL/LCD/LCD_int.h"
#include "../HAL/Th_LM/TH_int.h"
#include <util/delay.h>
int main(){


u16 adcread=0;
s32 Temp=0;
DIO_enuInit();
DIO_enuSetPinDirection(DIO_u8PORTA,DIO_u8PIN0,DIO_u8INPUT);
DIO_enuSetPortDirection(DIO_u8PORTD,DIO_u8OUTPUT);
ADC_enu_Int();
LCD_enuInit();
TH_enuInit();
ADC_enuSelectChannel(0);
ADC_enuEnable();
LCD_enuSendCommand(0x0c);
LCD_enuSendString("Temp =");


		while(1){
			LCD_GoTo(0,6);
			LCD_enuSendString("       ");
			LCD_GoTo(0,6);

			ADC_enu_Start_Conversion();
			ADC_enu_Read(&adcread);
          DIO_enuSetPortValue(DIO_u8PORTD,adcread);
          TH_enuGetTem(adcread,&Temp);
          LCD_enuDisplayIntegerNum(Temp);

		  _delay_ms(500);

		}



	return 0;
}
