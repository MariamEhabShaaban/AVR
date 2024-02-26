/*
 * LED_config.h
 *
 *  Created on: Feb 24, 2024
 *      Author: repair
 */


#ifndef LED_CONFIG_H
#define LED_CONFIG_H

#include "../../LIB/stdTypes.h"

#define LED_NUM 6
typedef struct{

	u8 LED_PortID;
		u8 LED_PinID;
		u8 LED_Connection;
		u8 LED_InitState;


}LED_t;






#endif /* LED_LED_CONFIG_H_ */
