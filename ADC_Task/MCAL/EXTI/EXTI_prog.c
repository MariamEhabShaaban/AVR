




#include "../../LIB/stdTypes.h"
#include "../../LIB/errorStates.h"


#include "EXTI_priv.h"
#include "EXTI_config.h"



void (*pfunINTFun0)(void)=NULL;
void (*pfunINTFun1)(void)=NULL;
void (*pfunINTFun2)(void)=NULL;

ES_t EXTI_intialiation(){

	ES_t Local_enuErrorstate = ES_NOK;

	MCUCR &=~(15<<0); // CLEAR BIT 0 1 2 3 (INT0 & INT1)

#if INT0_MODE == FALLING_EDGE
	MCUCR|=FALLING_EDGE;
#elif  INT0_MODE == LOW_LEVEL
	MCUCR|=LOW_LEVEL;
#elif  INT0_MODE == RISING_EDGE
	MCUCR|=RISING_EDGE;
#elif  INT0_MODE == ANY_LOGIC
	MCUCR|=ANY_LOGIC;
#endif

#if INT1_MODE == FALLING_EDGE
	MCUCR|=(FALLING_EDGE<<2);
#elif  INT1_MODE == LOW_LEVEL
	MCUCR|=(LOW_LEVEL<<2);
#elif  INT1_MODE == RISING_EDGE
	MCUCR|=(RISING_EDGE<<2);
#elif  INT1_MODE == ANY_LOGIC
	MCUCR|=(ANY_LOGIC<<2);
#endif


#if INT0_STATE == ACTIVE
	GICR |=(1<<6);
#elif  INT0_STATE == DEACTIVE
	GICR &=~(1<<6);
#endif



#if INT1_STATE == ACTIVE
	GICR |=(1<<7);
#elif  INT1_STATE == DEACTIVE
	GICR &=~(1<<7);
#endif

#if INT2_STATE == ACTIVE
	GICR |=(1<<5);
#elif  INT2_STATE == DEACTIVE
	GICR &=~(1<<5);
#endif

	GIFR|=(7<<5);     //CLEAR FLAGS IN BIT 5,6,7


		return Local_enuErrorstate;


}
ES_t  EXTI_Enable_INT(u8 Copy_u8EXTI_ID){
	ES_t Local_enuErrorstate = ES_NOK;
	if (Copy_u8EXTI_ID < 4)
		{
			if (Copy_u8EXTI_ID ==0)
			{

				GICR |= (1<<6);
			}
			else if (Copy_u8EXTI_ID ==1)
			{
				GICR |= (1<<7);
			}
			else if (Copy_u8EXTI_ID ==2)
			{
				GICR |= (1<<5);
			}
			else if(Copy_u8EXTI_ID==GLOBAL){
			           SREG|= (1<<7);

	         }
			 Local_enuErrorstate = ES_OK;
		}

	return Local_enuErrorstate;
}
ES_t  EXTI_Disable_INT(u8 Copy_u8EXTI_ID){
	ES_t Local_enuErrorstate = ES_NOK;
		if (Copy_u8EXTI_ID < 4)
			{
			if (Copy_u8EXTI_ID ==0)
							{

								GICR &= ~(1<<6);
							}
							else if (Copy_u8EXTI_ID ==1)
							{
								GICR &=~(1<<7);
							}
							else if (Copy_u8EXTI_ID ==2)
							{
								GICR &=~(1<<5);
							}
							else if(Copy_u8EXTI_ID==GLOBAL){
                                    SREG&=~(1<<7);
							}
				 Local_enuErrorstate = ES_OK;
			}

		return Local_enuErrorstate;


}

ES_t  EXTI_CallBack(void (*Copy_fun_ptr) (void),u8 Copy_u8EXTI_ID ){

	ES_t Local_enuErrorstate = ES_NOK;


	if (Copy_fun_ptr != NULL && Copy_u8EXTI_ID <3)
		{
		switch(Copy_u8EXTI_ID){
		case INT0:
		      pfunINTFun0=Copy_fun_ptr;
		      break;
		case INT1:
				 pfunINTFun1=Copy_fun_ptr;
				 break;
		case INT2:
			 pfunINTFun2=Copy_fun_ptr;
		     break;

		}
		      Local_enuErrorstate = ES_OK;

		}

			return Local_enuErrorstate;


}


ISR(VECT_INT0){
	if(pfunINTFun0!=NULL){
		pfunINTFun0();
	}

}


ISR(VECT_INT1){
	if(pfunINTFun1!=NULL){
		pfunINTFun1();
	}

}


ISR(VECT_INT2){
	if(pfunINTFun2!=NULL){
		pfunINTFun2();
	}

}
