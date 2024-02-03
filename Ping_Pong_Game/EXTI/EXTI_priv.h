#ifndef EXTI_PRIV_H
#define EXTI_PRIV_H



#define ACTIVE 		    1
#define DEACTIVE 		0


#define LOW_LEVEL			0
#define ANY_LOGIC			1
#define FALLING_EDGE		2
#define RISING_EDGE			3


#define SREG                *((volatile u8*)0x5F)
#define MCUCR				*((volatile u8*)0x55)
#define MCUCSR				*((volatile u8*)0x54)
#define GICR				*((volatile u8*)0x5B)
#define GIFR				*((volatile u8*)0x5A)



#define INT0    0
#define INT1    1
#define INT2    2
#define GLOBAL  3


#define ISR(VECT_NUM)		void VECT_NUM (void) __attribute__ ((signal));\
							void VECT_NUM (void)

#define VECT_INT0			__vector_1
#define VECT_INT1			__vector_2
#define VECT_INT2			__vector_3

#endif
