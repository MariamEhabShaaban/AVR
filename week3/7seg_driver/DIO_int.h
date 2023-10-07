#ifndef DIO_INT_H_
#define  DIO_INT_H_
#include "errorStates.h"
#include "DIO_priv.h"
#include "stdTypes.h"

#define D_u8PORTA		0
#define D_u8PORTB		1
#define D_u8PORTC		2
#define D_u8PORTD		3

#define D_u8PIN0		0
#define D_u8PIN1		1
#define D_u8PIN2		2
#define D_u8PIN3		3
#define D_u8PIN4		4
#define D_u8PIN5		5
#define D_u8PIN6		6
#define D_u8PIN7		7


ES_t SEV_SEG_enuint(void);

ES_t SEV_SEG_enuDisplayNum(u8 Copy_u8PortID, u8 val);


#endif
