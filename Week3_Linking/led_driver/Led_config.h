#ifndef LED_CONFIG_H
#define LED_CONFIG_H

#include "stdTypes.h"

#define LED_NUM 2
typedef struct{

	u8 LED_PortID;
		u8 LED_PinID;
		u8 LED_Connection;
		u8 LED_InitState;


}LED_t;





#endif
