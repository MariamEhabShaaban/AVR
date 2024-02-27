


#ifndef EXTI_INT_H
#define EXTI_INT_H

#include "../DIO/DIO_int.h"
#include "../../LIB/errorStates.h"
#include "EXTI_priv.h"
#include "EXTI_config.h"








ES_t  EXTI_intialiation();
ES_t  EXTI_Enable_INT(u8 Copy_u8EXTI_ID);
ES_t  EXTI_Disable_INT(u8 Copy_u8EXTI_ID);
ES_t  EXTI_CallBack(void (*Copy_fun_ptr) (void),u8 Copy_u8EXTI_ID );


#endif
