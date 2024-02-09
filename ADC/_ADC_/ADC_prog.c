#include "../LIB/stdTypes.h"
#include "../LIB/errorStates.h"

#include "ADC_priv.h"
#include "ADC_config.h"



ES_t ADC_enu_Int(){
	ES_t Local_enuErrorstate = ES_NOK;
#if Vref == AREF
	ADMUX&=~(AREF<<6);

#elif Vref == AVCC
	ADMUX|=(AVCC<<6);

#elif Vref == INT_VRE
	ADMUX&=~(1<<6);
	ADMUX|=(INT_VRE<<6);
#endif


#if Adjust_Type==Left_Adjust
	ADMUX|=(1<<ADLAR);
#elif Adjust_Type==Right_Adjust
	ADMUX&=~(1<<ADLAR);
#endif

#if Analog_channel==single_ended&&ADC_SOURCE==ADC0
	ADMUX&=~(15<<0);
#endif



#if division_factor == DIV_FACT128
	ADCSRA |= (7<<0);
#endif





 ADCSRA|=(1<<ADEN);         //enable ADC






	Local_enuErrorstate = ES_OK;
	return Local_enuErrorstate;
}

u16  ADC_u16_Read(){
	u16 Result_Conversion;

#if Trigger_Source==Free_Running_mode
	ADCSRA&=~(1<<ADSC);
#endif
	ADCSRA |= (1<<ADSC);
while(((ADCSRA>>ADIF) &1)==0);//get bit
ADCSRA|=(1<<ADIF);//clear flag
Result_Conversion=ADCADJ;
	return Result_Conversion;
}
