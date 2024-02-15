#include "../../LIB/stdTypes.h"
#include "../../LIB/errorStates.h"

#include "ADC_priv.h"
#include "ADC_config.h"
#include "../interrupt.h"

static void (*ADC_GpFun)(void*)=NULL;
static void *ADC_Gparameter=NULL;


 ES_t ADC_enu_Int(){
	ES_t Local_enuErrorstate = ES_NOK;
#if Vref == AREF
	ADMUX&=~(3<<6);

#elif Vref == AVCC
	ADMUX&=~(1<<7);
	ADMUX|=(AVCC<<6);

#elif Vref == INT_VRE
	ADMUX|=(INT_VRE<<6);
#endif


#if Adjust_Type==Left_Adjust
	ADMUX|=(1<<5);
#elif Adjust_Type==Right_Adjust
	ADMUX&=~(1<<5);
#endif




#if prescalar == DIV_FACT2
	ADCSRA &=~ (7<<0);
#elif prescalar == DIV_FACT4
	ADCSRA &=~ (7<<0);
	ADCSRA |= (2<<0);
#elif prescalar == DIV_FACT8
	ADCSRA &=~ (7<<0);
	ADCSRA |= (3<<0);
#elif prescalar == DIV_FACT16
	ADCSRA &=~ (7<<0);
	ADCSRA |= (4<<0);
#elif prescalar == DIV_FACT32
	ADCSRA &=~ (7<<0);
	ADCSRA |= (5<<0);
#elif prescalar == DIV_FACT64
	ADCSRA &=~ (7<<0);
	ADCSRA |= (6<<0);
#elif prescalar == DIV_FACT128
	ADCSRA |= (7<<0);
#endif

	Local_enuErrorstate = ES_OK;
	return Local_enuErrorstate;
}
ES_t ADC_enu_Start_Conversion(){
	ES_t Local_enuErrorstate = ES_NOK;
	ADCSRA|=(1<<6);
	while(((ADCSRA>>4)&1)==0);  //polling
	ADCSRA|=(1<<4);
	Local_enuErrorstate = ES_OK;
		return Local_enuErrorstate;
}
ES_t ADC_enuEnable(){
	ES_t Local_enuErrorstate = ES_NOK;
	ADCSRA|=(1<<7);
	Local_enuErrorstate = ES_OK;
			return Local_enuErrorstate;
}
ES_t ADC_enuDisable(){
	ES_t Local_enuErrorstate = ES_NOK;
	ADCSRA&=~(1<<7);
		Local_enuErrorstate = ES_OK;
				return Local_enuErrorstate;
}

ES_t ADC_enu_ReadHighVal(u8 *Copy_pu8Value){
	ES_t Local_enuErrorstate = ES_NOK;
#if Adjust_Type==Left_Adjust
	*Copy_pu8Value=ADCH;
#elif Adjust_Type==Right_Adjust
	*Copy_pu8Value=(ADCL>>2);
	*Copy_pu8Value|=(ADCH<<6);
#endif
	Local_enuErrorstate = ES_OK;
			return Local_enuErrorstate;
}


ES_t  ADC_enu_Read(u16 *Copy_pu16Value){
	ES_t Local_enuErrorstate = ES_NOK;


#if Adjust_Type==Left_Adjust
	*Copy_pu16Value=(ADCL>>6);
	*Copy_pu16Value|=(ADCH<<2);
#elif Adjust_Type==Right_Adjust
	*Copy_pu16Value=ADCADJ;
#endif

	Local_enuErrorstate = ES_OK;
	return Local_enuErrorstate;
}


ES_t ADC_enuSelectChannel(u8 Copy_u8ChannelID){
	ES_t Local_enuErrorstate = ES_NOK;
	if(Copy_u8ChannelID<32){
	ADMUX&=~(31>>0);
	ADMUX|=Copy_u8ChannelID;
	Local_enuErrorstate = ES_OK;
	}

	return Local_enuErrorstate;
}

ES_t ADC_enuEnableTriggeringMode(u8 Copy_Trigger_Source){
	ES_t Local_enuErrorstate = ES_NOK;
	ADCSRA &=~(1<<5);
	switch(Copy_Trigger_Source){
	case Free_Running_mode:
		SFIOR&=~(7<<5);

		break;
	case EXT_Request:
		SFIOR&=~(7<<5);
		SFIOR|=(2<<5);

		break;
	case Analog_Comparator:
			SFIOR&=~(7<<5);
			SFIOR|=(1<<5);

			break;
	}
	ADCSRA |=(1<<5);



	Local_enuErrorstate = ES_OK;
		return Local_enuErrorstate;
}


ES_t ADC_enuDisableTriggeringMode(){
	ES_t Local_enuErrorstate = ES_NOK;

	ADCSRA&=~(1<<5);


	Local_enuErrorstate = ES_OK;
	return Local_enuErrorstate;
}


ES_t ADC_enuEnableInterruptMode(void){
	ES_t Local_enuErrorstate = ES_NOK;

		ADCSRA|=(1<<3);


		Local_enuErrorstate = ES_OK;
		return Local_enuErrorstate;
}
ES_t ADC_enuDisableInterruptMode(void){
	ES_t Local_enuErrorstate = ES_NOK;

		ADCSRA&=~(1<<3);


		Local_enuErrorstate = ES_OK;
		return Local_enuErrorstate;

}
ES_t  ADC_CallBack(void (*Copy_fun_ptr) (void), void * Copy_pvidAppParameter ){
	ES_t Local_enuErrorstate = ES_NOK;
	if(Copy_fun_ptr!=NULL && Copy_pvidAppParameter!=NULL){
		ADC_GpFun=Copy_fun_ptr;
		ADC_Gparameter=Copy_pvidAppParameter;
		Local_enuErrorstate = ES_OK;

	}

				return Local_enuErrorstate;

}
ISR(VECT_ADC){
if(ADC_GpFun!=NULL){
	ADC_GpFun(ADC_Gparameter);
}


}
