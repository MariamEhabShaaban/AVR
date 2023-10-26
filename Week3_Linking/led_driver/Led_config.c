#include "stdTypes.h"
#include "errorStates.h"
#include "Led_priv.h"
#include "Led_config.h"
#include "DIO_int.h"
  LED_t LED_CONFIG[LED_NUM]={
		  {DIO_u8PORTA,DIO_u8PIN0,DIO_SOURCE,DIO_u8LOW},
		  {DIO_u8PORTB,DIO_u8PIN0,	DIO_SOURCE,DIO_u8LOW}


  };
