#include "stdTypes.h"
#include "errorStates.h"
#include "DIO_int.h"
#include "DIO_priv.h"
#include "DIO_config.h"

ES_t LED_enuint (void){
	ES_t local_enuerror=ES_NOK;
	DDRA =CONC( PA_PIN7_DIR	, PA_PIN6_DIR, PA_PIN5_DIR	, PA_PIN4_DIR, PA_PIN3_DIR, PA_PIN2_DIR, PA_PIN1_DIR, PA_PIN0_DIR);
		DDRB =CONC( PB_PIN7_DIR	, PB_PIN6_DIR, PB_PIN5_DIR	, PB_PIN4_DIR, PB_PIN3_DIR, PB_PIN2_DIR, PB_PIN1_DIR, PB_PIN0_DIR);
		DDRC =CONC( PC_PIN7_DIR	, PC_PIN6_DIR, PC_PIN5_DIR	, PC_PIN4_DIR, PC_PIN3_DIR, PC_PIN2_DIR, PC_PIN1_DIR, PC_PIN0_DIR);
		DDRD =CONC( PD_PIN7_DIR	, PD_PIN6_DIR, PD_PIN5_DIR	, PD_PIN4_DIR, PD_PIN3_DIR, PD_PIN2_DIR, PD_PIN1_DIR, PD_PIN0_DIR);
		PORTA =CONC( PA_PIN7_DIR, PA_PIN6_DIR, PA_PIN5_DIR	, PA_PIN4_DIR, PA_PIN3_DIR, PA_PIN2_DIR, PA_PIN1_DIR, PA_PIN0_DIR);
		PORTB =CONC( PB_PIN7_DIR, PB_PIN6_DIR, PB_PIN5_DIR	, PB_PIN4_DIR, PB_PIN3_DIR, PB_PIN2_DIR, PB_PIN1_DIR, PB_PIN0_DIR);
		PORTC =CONC( PC_PIN7_DIR, PC_PIN6_DIR, PC_PIN5_DIR	, PC_PIN4_DIR, PC_PIN3_DIR, PC_PIN2_DIR, PC_PIN1_DIR, PC_PIN0_DIR);
		PORTD =CONC( PD_PIN7_DIR, PD_PIN6_DIR, PD_PIN5_DIR	, PD_PIN4_DIR, PD_PIN3_DIR, PD_PIN2_DIR, PD_PIN1_DIR, PD_PIN0_DIR);

	local_enuerror=ES_OK;


return local_enuerror;
}

ES_t PIN_LED_ON(u8 Copy_u8PortID ,u8 Copy_u8PinID ){
	ES_t local_enuerror=ES_NOK;

	if(Copy_u8PortID<=D_u8PORTD && Copy_u8PinID<=D_u8PIN7){
				local_enuerror=ES_OK;
				switch(Copy_u8PortID){
				case DIO_PORTA:

					PORTA |=(ON<<Copy_u8PinID);

				break;
				case DIO_PORTB:
					PORTB |=(ON<<Copy_u8PinID);
						break;
				case DIO_PORTC:
					PORTC |=(ON<<Copy_u8PinID);
						break;
				case DIO_PORTD:
					PORTD |=(ON<<Copy_u8PinID);
						break;

				}





			}
			else
				{
				local_enuerror = ES_OUT_OF_RANGE;
				}
	return local_enuerror;
}
ES_t PIN_LED_OFF(u8 Copy_u8PortID ,u8 Copy_u8PinID ){

	ES_t local_enuerror=ES_NOK;

		if(Copy_u8PortID<=D_u8PORTD && Copy_u8PinID<=D_u8PIN7){
					local_enuerror=ES_OK;
					switch(Copy_u8PortID){
					case DIO_PORTA:

						PORTA &=~(ON<<Copy_u8PinID);

					break;
					case DIO_PORTB:
						PORTB&=~(ON<<Copy_u8PinID);
							break;
					case DIO_PORTC:
						PORTC &=~(ON<<Copy_u8PinID);
							break;
					case DIO_PORTD:
						PORTD&=~(ON<<Copy_u8PinID);
							break;

					}





				}
				else
				{
				local_enuerror = ES_OUT_OF_RANGE;
				}
		return local_enuerror;
}


