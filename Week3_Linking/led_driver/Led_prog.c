#include "stdTypes.h"
#include "errorStates.h"
#include "Led_priv.h"
#include "Led_config.h"
#include "DIO_int.h"

ES_t LED_enuint(LED_t *SWITCH_CONFIG){
	ES_t Local_error=ES_NOK;
	if(SWITCH_CONFIG!=NULL){
		for(u8 Iterator=0;Iterator<LED_NUM;Iterator++){
		Local_error=DIO_enuSetPinDirection(SWITCH_CONFIG[Iterator].LED_PortID,SWITCH_CONFIG[Iterator].LED_PinID,DIO_u8OUTPUT);
		Local_error=DIO_enuSetPinValue(SWITCH_CONFIG[Iterator].LED_PortID,SWITCH_CONFIG[Iterator].LED_PinID,SWITCH_CONFIG[Iterator].LED_InitState);
		}
	}
	else{
		Local_error=ES_NULL_POINTER;
	}



	return Local_error;
}
ES_t LED_ON(LED_t *SWITCH_CONFIG){
	ES_t Local_error=ES_NOK;
		if(SWITCH_CONFIG!=NULL){
			if(SWITCH_CONFIG->LED_Connection==DIO_SINK){
				Local_error=DIO_enuSetPinValue(SWITCH_CONFIG->LED_PortID,SWITCH_CONFIG->LED_PinID,DIO_u8LOW);
		}
			else if(SWITCH_CONFIG->LED_Connection==DIO_SOURCE){

				Local_error=DIO_enuSetPinValue(SWITCH_CONFIG->LED_PortID,SWITCH_CONFIG->LED_PinID,DIO_u8HIGH);


			}
			else{
				Local_error=ES_OUT_OF_RANGE;
			}
		}

		else{
			Local_error=ES_NULL_POINTER;
		}



		return Local_error;
	}






ES_t LED_OFF(LED_t *SWITCH_CONFIG){

	ES_t Local_error=ES_NOK;
			if(SWITCH_CONFIG!=NULL){
				if(SWITCH_CONFIG->LED_Connection==DIO_SINK){
								Local_error=DIO_enuSetPinValue(SWITCH_CONFIG->LED_PortID,SWITCH_CONFIG->LED_PinID,DIO_u8HIGH);
						}
							else if(SWITCH_CONFIG->LED_Connection==DIO_SOURCE){

								Local_error=DIO_enuSetPinValue(SWITCH_CONFIG->LED_PortID,SWITCH_CONFIG->LED_PinID,DIO_u8LOW);


							}
							else{
								Local_error=ES_OUT_OF_RANGE;
							}
						}

			else{
				Local_error=ES_NULL_POINTER;
			}



			return Local_error;
}





