
#include "DIO/DIO_int.h"
#include "LCD/LCD_int.h"
#include "EXTI/EXTI_int.h"
#include <util/delay.h>
u8 row1=0,row2=0,row_ball=0;
u8 tog=1;
void ISR1();

void ISR2();
int main(){

DIO_enuInit();
LCD_enuInit();
LCD_enuSendCommand(0x0c);
EXTI_intialiation();
//EXTI_Enable_INT(INT0);
//EXTI_Enable_INT(INT1);
EXTI_Enable_INT(GLOBAL);

EXTI_CallBack(&ISR1,INT0);
EXTI_CallBack(&ISR2,INT1);




while(1){
	u8 player1=0,player2=0;
	                LCD_Clear();
			        LCD_GoTo(0,15);
				    LCD_enuDisplayChar('|');
				    LCD_GoTo(0,0);
				    LCD_enuDisplayChar('|');

				    LCD_GoTo(0,1);
				    LCD_enuDisplayChar('o');
				    _delay_ms(50);
				    LCD_GoTo(0,1);
				    LCD_enuDisplayChar(' ');


	u8 turns=5;
	while(turns){

		for(u8 col_ball =1;col_ball<14;col_ball++){
			row_ball=((col_ball<<0)&1);

							    LCD_GoTo(row_ball,col_ball);
		    LCD_enuDisplayChar('o');
		    _delay_ms(50);
		    LCD_GoTo(row_ball,col_ball);
		   	LCD_enuDisplayChar(' ');
		}

		if(row1==row_ball){
			player1++;
		}





		for(u8 col_ball =13;col_ball>1;col_ball--){
					row_ball=((col_ball<<0)&1);

				    LCD_GoTo(row_ball,col_ball);
				    LCD_enuDisplayChar('o');
				    _delay_ms(50);
				    LCD_GoTo(row_ball,col_ball);
				   	LCD_enuDisplayChar(' ');
				}

		if(row2== row_ball){
					player2++;
				}



            turns--;

	}
	LCD_Clear();
			LCD_GoTo(0,5);
	        LCD_enuSendString("GAME OVER");
          _delay_ms(500);

	if(player1>player2){
		LCD_Clear();
		LCD_GoTo(0,1);
        LCD_enuSendString("Player1 wins");
        _delay_ms(500);
	}
	else if(player2>player1){
		        LCD_Clear();
				LCD_GoTo(0,1);
		        LCD_enuSendString("Player2 wins");
		        _delay_ms(500);
	}
	else{
		LCD_Clear();
						LCD_GoTo(0,0);
				        LCD_enuSendString("result is tie");
				        _delay_ms(500);
	}
	LCD_Clear();

	}



	return 0;
}



void ISR1(){
	if(row1==0){
	LCD_GoTo(0,15);
	LCD_enuDisplayChar(' ');
	LCD_GoTo(1,15);
	LCD_enuDisplayChar('|');
	row1=1;
	}
	else if(row1==1){
		LCD_GoTo(1,15);
			LCD_enuDisplayChar(' ');
			LCD_GoTo(0,15);
			LCD_enuDisplayChar('|');
			row1=0;
	}

}

void ISR2(){
	if(row2==0){
		LCD_GoTo(0,0);
		LCD_enuDisplayChar(' ');
		LCD_GoTo(1,0);
		LCD_enuDisplayChar('|');
		row2=1;
		}
		else if(row2==1){
			LCD_GoTo(1,0);
				LCD_enuDisplayChar(' ');
				LCD_GoTo(0,0);
				LCD_enuDisplayChar('|');
				row2=0;
		}
}
