/*
 * task1.c
 *
 * Created: 10/6/2023 4:16:25 AM
 * Author : repair
 */ 

#define u8 unsigned int
#define ddra *((u8*)0x3A)
#define porta *((u8*)0x3B)
#define  pina *((volatile u8*)0x39)
#define ddrb *((u8*)0x37)
#define portb *((u8*)0x38)
#define  pinb *((volatile u8*)0x36)
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
   ddra|=(1<<0);
   porta&=~(1<<0);
   
    while (1) 
    {
		porta|=(1<<0);
		_delay_ms(50);
		 porta&=~(1<<0);
		 _delay_ms(50);
    }
}

