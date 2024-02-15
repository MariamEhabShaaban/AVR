
#ifndef ADC_INT_H_
#define ADC_INT_H_
#include "../../LIB/errorStates.h"
#include "../../LIB/stdTypes.h"
ES_t ADC_enu_Int();
ES_t ADC_enuSelectChannel(u8 Copy_u8ChannelID);
ES_t ADC_enuEnable();
ES_t ADC_enuDisable();
ES_t ADC_enu_Start_Conversion();
ES_t ADC_enu_ReadHighVal(u8 Copy_pu8Value);
ES_t  ADC_enu_Read(u16 Copy_pu16Value);
ES_t ADC_enuEnableTriggeringMode(u8 Copy_Trigger_Source);
ES_t ADC_enuDisableTriggeringMode();
ES_t ADC_enuEnableInterruptMode();
ES_t ADC_enuDisableInterruptMode();
ES_t  ADC_CallBack(void (*Copy_fun_ptr) (void) );
#endif
