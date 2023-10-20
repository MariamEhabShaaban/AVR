#include "stdTypes.h"
#include "errorStates.h"
#include "Switch_priv.h"
#include "Switch_config.h"
#include "DIO_int.h"
  SW_t SWITCH_CONFIG[SW_NUM]={
		  {DIO_u8PORTA,DIO_u8PIN0,DIO_u8PULL_UP},
		  {DIO_u8PORTB,DIO_u8PIN0,	DIO_u8PULL_UP}


  };
