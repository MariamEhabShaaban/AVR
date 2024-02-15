/*
 * TH_prog.c
 *
 *  Created on: Feb 15, 2024
 *      Author: repair
 */
#include "../../LIB/errorStates.h"
#include "../../LIB/stdTypes.h"
#include "../../MCAL/DIO/DIO_int.h"

#include "TH_config.h"
#include "TH_priv.h"
ES_t TH_enuInit(){
	ES_t Local_enuErrorstate = ES_NOK;
#if positive_pin_channel ==ADC0 && negative_pin_channel==NOT_CONNECTED
     DIO_enuSetPinDirection(DIO_u8PORTA,ADC0,DIO_u8INPUT);
     Local_enuErrorstate = ES_OK;
#else
#error " ERROR "
#endif
			return Local_enuErrorstate;

}
ES_t TH_enuGetTem(u16 ADC_read,s32* temperature){
	ES_t Local_enuErrorstate = ES_NOK;
	*temperature=(ADC_read*4.88)/10.0;

				return Local_enuErrorstate;
}
