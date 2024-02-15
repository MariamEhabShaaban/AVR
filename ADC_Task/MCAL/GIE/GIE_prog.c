/*
 * GIE_prog.c
 *
 *  Created on: Feb 13, 2024
 *      Author: repair
 */
#include "../../LIB/stdTypes.h"
#include "../../LIB/errorStates.h"
#include "GIE_priv.h"

ES_t GIE_enuEnable(){
	ES_t Local_enuErrorstate = ES_NOK;

	SREG|= (1<<7);
	Local_enuErrorstate = ES_OK;

		return Local_enuErrorstate;

}
ES_t GIE_enuDisable(){
	ES_t Local_enuErrorstate = ES_NOK;
    SREG&=~(1<<7);
    Local_enuErrorstate = ES_OK;
			return Local_enuErrorstate;
}
