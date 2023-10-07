#include "stdTypes.h"
#include "errorStates.h"
#include "sev_int.h"
#include "sev_priv.h"
#include "sev_config.h"

ES_t SEV_SEG_enuint(void){
	ES_t local_enuerror=ES_NOK;
		DDRA =CONC( PA_PIN7_DIR	, PA_PIN6_DIR, PA_PIN5_DIR	, PA_PIN4_DIR, PA_PIN3_DIR, PA_PIN2_DIR, PA_PIN1_DIR, PA_PIN0_DIR);
			DDRB =CONC( PB_PIN7_DIR	, PB_PIN6_DIR, PB_PIN5_DIR	, PB_PIN4_DIR, PB_PIN3_DIR, PB_PIN2_DIR, PB_PIN1_DIR, PB_PIN0_DIR);
			DDRC =CONC( PC_PIN7_DIR	, PC_PIN6_DIR, PC_PIN5_DIR	, PC_PIN4_DIR, PC_PIN3_DIR, PC_PIN2_DIR, PC_PIN1_DIR, PC_PIN0_DIR);
			DDRD =CONC( PD_PIN7_DIR	, PD_PIN6_DIR, PD_PIN5_DIR	, PD_PIN4_DIR, PD_PIN3_DIR, PD_PIN2_DIR, PD_PIN1_DIR, PD_PIN0_DIR);
			PORTA =CONC( PA_PIN7_VAL, PA_PIN6_VAL, PA_PIN5_VAL	, PA_PIN4_VAL, PA_PIN3_VAL, PA_PIN2_VAL, PA_PIN1_VAL, PA_PIN0_VAL);
			PORTB =CONC( PB_PIN7_VAL, PB_PIN6_VAL, PB_PIN5_VAL	, PB_PIN4_VAL, PB_PIN3_VAL, PB_PIN2_VAL, PB_PIN1_VAL, PB_PIN0_VAL);
			PORTC =CONC( PC_PIN7_VAL, PC_PIN6_VAL, PC_PIN5_VAL	, PC_PIN4_VAL, PC_PIN3_VAL, PC_PIN2_VAL, PC_PIN1_VAL, PC_PIN0_VAL);
			PORTD =CONC( PD_PIN7_VAL, PD_PIN6_VAL, PD_PIN5_VAL	, PD_PIN4_VAL, PD_PIN3_VAL, PD_PIN2_VAL, PD_PIN1_VAL, PD_PIN0_VAL);

		local_enuerror=ES_OK;


	return local_enuerror;
	}

ES_t SEV_SEG_enuDisplayNum(u8 Copy_u8PortID,u8 val){

	ES_t local_enuerror=ES_NOK;
				if( Copy_u8PortID<=D_u8PORTD){
					local_enuerror=ES_OK;

					 switch(Copy_u8PortID){
								 case D_u8PORTA:
									 PORTA=val;
									 break;
								 case D_u8PORTB:
									 PORTB= val;
											 break;
								 case D_u8PORTC:
									 PORTC= val;
											 break;
								 case D_u8PORTD:
								 PORTD=val;
											 break;


								 }

				}
				else
					{
					local_enuerror = ES_OUT_OF_RANGE;
					}
				return local_enuerror;

}
