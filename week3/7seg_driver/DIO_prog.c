#include "stdTypes.h"
#include "errorStates.h"
#include "DIO_int.h"
#include "DIO_priv.h"
#include "DIO_config.h"

ES_t DIO_enuint (void){
	ES_t local_enuerror=ES_NOK;
	DDRA =CONC( PA_PIN7_DIR	, PA_PIN6_DIR, PA_PIN5_DIR	, PA_PIN4_DIR, PA_PIN3_DIR, PA_PIN2_DIR, PA_PIN1_DIR, PA_PIN0_DIR);
	DDRB =CONC( PB_PIN7_DIR	, PB_PIN6_DIR, PB_PIN5_DIR	, PB_PIN4_DIR, PB_PIN3_DIR, PB_PIN2_DIR, PB_PIN1_DIR, PB_PIN0_DIR);
	DDRC =CONC( PC_PIN7_DIR	, PC_PIN6_DIR, PC_PIN5_DIR	, PC_PIN4_DIR, PC_PIN3_DIR, PC_PIN2_DIR, PC_PIN1_DIR, PC_PIN0_DIR);
	DDRD =CONC( PD_PIN7_DIR	, PD_PIN6_DIR, PD_PIN5_DIR	, PD_PIN4_DIR, PD_PIN3_DIR, PD_PIN2_DIR, PD_PIN1_DIR, PD_PIN0_DIR);
	PORTC =CONC( PC_PIN7_DIR, PC_PIN6_DIR, PC_PIN5_DIR	, PC_PIN4_DIR, PC_PIN3_DIR, PC_PIN2_DIR, PC_PIN1_DIR, PC_PIN0_DIR);

	local_enuerror=ES_OK;


return local_enuerror;
}

ES_t DIO_enuSetPortDirection(u8 Copy_u8PortID , u8 Copy_u8Value){
	ES_t local_enuerror=ES_NOK;
	if( Copy_u8PortID<=D_u8PORTD){

		 local_enuerror=ES_OK;
		 switch(Copy_u8PortID){
		 case D_u8PORTA:
			 DDRA=Copy_u8Value;
			 break;
		 case D_u8PORTB:
					 DDRB=Copy_u8Value;
					 break;
		 case D_u8PORTC:
					 DDRC=Copy_u8Value;
					 break;
		 case D_u8PORTD:
					 DDRD=Copy_u8Value;
					 break;


		 }

	}
	return local_enuerror;
}

ES_t DIO_enuSetPortValue(u8 Copy_u8PortID , u8 Copy_u8Value){

	ES_t local_enuerror=ES_NOK;
		if( Copy_u8PortID<=D_u8PORTD){

			 local_enuerror=ES_OK;
			 switch(Copy_u8PortID){
			 case D_u8PORTA:
				 PORTA=Copy_u8Value;
				 break;
			 case D_u8PORTB:
				 PORTB=Copy_u8Value;
						 break;
			 case D_u8PORTC:
				 PORTC=Copy_u8Value;
						 break;
			 case D_u8PORTD:
			 PORTD=Copy_u8Value;
						 break;


			 }

		}
		else
			{
			local_enuerror = ES_OUT_OF_RANGE;
			}
		return local_enuerror;
}

ES_t DIO_enuTogPortValue(u8 Copy_u8PortID){
	ES_t local_enuerror=ES_NOK;
			if( Copy_u8PortID<=D_u8PORTD){
				local_enuerror=ES_OK;

				 switch(Copy_u8PortID){
							 case D_u8PORTA:
								 PORTA= ~PORTA;
								 break;
							 case D_u8PORTB:
								 PORTB= ~PORTB;
										 break;
							 case D_u8PORTC:
								 PORTC= ~PORTC;
										 break;
							 case D_u8PORTD:
							 PORTD=~ PORTD;
										 break;


							 }

			}
			else
				{
				local_enuerror = ES_OUT_OF_RANGE;
				}
			return local_enuerror;
}

ES_t DIO_enuGetPortValue(u8 Copy_u8PortID , u8  *Copy_pu8Value){
	ES_t local_enuerror=ES_NOK;
	if( Copy_pu8Value!=NULL){
	if( Copy_u8PortID<=D_u8PORTD){

				 local_enuerror=ES_OK;
				 switch(Copy_u8PortID){
				 case DIO_PORTA:
					 *Copy_pu8Value=PINA;
					 break;
				 case DIO_PORTB:
					 *Copy_pu8Value=PINB;
							 break;
				 case DIO_PORTC:
					 *Copy_pu8Value=PINC;
							 break;
				 case DIO_PORTD:
				 *Copy_pu8Value=PIND;
							 break;


				 }

			}

			else
				{
				local_enuerror = ES_OUT_OF_RANGE;
				}
	}
	else{
		local_enuerror = ES_NULLPOINTER;
	}

return local_enuerror;

}

ES_t DIO_enuSetPinDirection(u8 Copy_u8PortID ,u8 Copy_u8PinID , u8 Copy_u8Value){
	ES_t local_enuerror=ES_NOK;

	if(Copy_u8PortID<=D_u8PORTD && Copy_u8PinID<=D_u8PIN7 && Copy_u8Value<=OUTPUT){
		local_enuerror=ES_OK;
		switch(Copy_u8PortID){
		case DIO_PORTA:
			DDRA&=~(OUTPUT<<Copy_u8PinID);
			DDRA|=(Copy_u8Value<<Copy_u8PinID);

		break;
		case DIO_PORTB:
					DDRB&=~(OUTPUT<<Copy_u8PinID);
					DDRB|=(Copy_u8Value<<Copy_u8PinID);

				break;
		case DIO_PORTC:
					DDRC=~(OUTPUT<<Copy_u8PinID);
					DDRC|=(Copy_u8Value<<Copy_u8PinID);

				break;
		case DIO_PORTD:
					DDRD&=~(OUTPUT<<Copy_u8PinID);
					DDRD|=(Copy_u8Value<<Copy_u8PinID);

				break;

		}





	}
	else{
			local_enuerror = ES_NULLPOINTER;
		}

	return local_enuerror;

}

ES_t DIO_enuSetPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID ,u8 Copy_u8Value){
	ES_t local_enuerror=ES_NOK;

		if(Copy_u8PortID<=D_u8PORTD && Copy_u8PinID<=D_u8PIN7 && Copy_u8Value<=OUTPUT){
			local_enuerror=ES_OK;
			switch(Copy_u8PortID){
			case DIO_PORTA:
				PORTA &=~(OUTPUT<<Copy_u8PinID);
				PORTA |=(Copy_u8Value<<Copy_u8PinID);

			break;
			case DIO_PORTB:
				PORTB&=~(OUTPUT<<Copy_u8PinID);
				PORTB|=(Copy_u8Value<<Copy_u8PinID);

					break;
			case DIO_PORTC:
				PORTC =~(OUTPUT<<Copy_u8PinID);
				PORTC |=(Copy_u8Value<<Copy_u8PinID);

					break;
			case DIO_PORTD:
						PORTD &=~(OUTPUT<<Copy_u8PinID);
						PORTD |=(Copy_u8Value<<Copy_u8PinID);

					break;

			}





		}
		else{
				local_enuerror = ES_NULLPOINTER;
			}


		return local_enuerror;

}

ES_t DIO_enuTogPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID ){
	ES_t local_enuerror=ES_NOK;
	if(Copy_u8PortID<= DIO_PORTD && Copy_u8PinID<= D_u8PIN7){
		local_enuerror=ES_OK;
		switch(Copy_u8PortID){
					case DIO_PORTA:
						PORTA ^=(OUTPUT<<Copy_u8PinID);


					break;
					case DIO_PORTB:
						PORTB ^=(OUTPUT<<Copy_u8PinID);
							break;
					case DIO_PORTC:
						PORTC ^=(OUTPUT<<Copy_u8PinID);

							break;
					case DIO_PORTD:
						PORTD ^=(OUTPUT<<Copy_u8PinID);
							break;

					}


	}
	else{
					local_enuerror = ES_NULLPOINTER;
				}

	 return local_enuerror;
}

ES_t DIO_enuGetPinValue(u8 Copy_u8PortID ,u8 Copy_u8PinID , u8 * Copy_pu8Value){


	ES_t local_enuerror=ES_NOK;
		if( Copy_pu8Value!=NULL){
		if( Copy_u8PortID<=D_u8PORTD &&Copy_u8PinID<=D_u8PIN7){

					 local_enuerror=ES_OK;
					 switch(Copy_u8PortID){
					 case DIO_PORTA:
						 *Copy_pu8Value=(PINA>>Copy_u8PinID)&OUTPUT;
						 break;
					 case DIO_PORTB:
						 *Copy_pu8Value=(PINB>>Copy_u8PinID)&OUTPUT;
								 break;
					 case DIO_PORTC:
						 *Copy_pu8Value=(PINC>>Copy_u8PinID)&OUTPUT;
								 break;
					 case DIO_PORTD:
					 *Copy_pu8Value=(PIND>>Copy_u8PinID)&OUTPUT;
								 break;


					 }

				}

				else
					{
					local_enuerror = ES_OUT_OF_RANGE;
					}
		}
		else{
			local_enuerror = ES_NULLPOINTER;
		}

	return local_enuerror;

}
