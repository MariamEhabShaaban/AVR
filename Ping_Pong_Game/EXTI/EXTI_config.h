#ifndef EXTI_CONFIG_H
#define EXTI_CONFIG_H
#include "../LIB/stdTypes.h"


#define ACTIVE_STATE 	    ACTIVE
#define DEACTIVE_STATE		DEACTIVE

#define INT0_STATE     ACTIVE
#define INT1_STATE     ACTIVE
#define INT2_STATE     ACTIVE

#define INT0_MODE   ANY_LOGIC
#define INT1_MODE   ANY_LOGIC
#define INT2_MODE   RISING_EDGE



#define LOW_LEVEL_MODE			LOW_LEVEL
#define ANY_LOGIC_MODE			ANY_LOGIC
#define FALLING_EDGE_MODE		FALLING_EDGE
#define RISING_EDGE_MODE		RISING_EDGE



#define INT_ZERO    INT0
#define INT_ONE     INT1
#define INT_TWO     INT2
#define INT_GLOBAL  GLOBAL
typedef struct
{
	u8 EXTI_u8State;
	u8 EXTI_u8SenceLevel;
}EXTI_t;

#endif
