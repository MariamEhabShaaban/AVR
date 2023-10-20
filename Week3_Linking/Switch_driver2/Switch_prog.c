#include "stdTypes.h"
#include "errorStates.h"
#include "Switch_priv.h"
#include "Switch_config.h"
#include "DIO_int.h"


ES_t SWITCH_enuint(SW_t *SWITCH_CONFIG){
	ES_t local_enuerror=ES_NOK;
	if(SWITCH_CONFIG!=NULL){
		for(u8 Iterator=0;Iterator<SW_NUM;Iterator++){
		local_enuerror=DIO_enuSetPinDirection(SWITCH_CONFIG[Iterator].PORT_ID,SWITCH_CONFIG[Iterator].PIN_ID,INPUT);
		local_enuerror=DIO_enuSetPinValue(SWITCH_CONFIG[Iterator].PORT_ID,SWITCH_CONFIG[Iterator].PIN_ID,SWITCH_CONFIG[Iterator].SWITCH_STAT);

		}


	}
	else
		local_enuerror=ES_NULL_POINTER;

	return local_enuerror;
}


ES_t SWITCH_STATUS(SW_t *SWITCH_CONFIG, u8* Switch_status ){

	ES_t local_enuerror=ES_NOK;

	if(SWITCH_CONFIG!=NULL){


			local_enuerror=DIO_enuGetPinValue(SWITCH_CONFIG->PORT_ID,SWITCH_CONFIG->PIN_ID,Switch_status);



		}
		else
			local_enuerror=ES_NULL_POINTER;

		return local_enuerror;


}
