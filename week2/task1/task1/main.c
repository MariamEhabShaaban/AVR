/*
 * task1.c
 *
 * Created: 10/6/2023 4:42:53 AM
 * Author : repair
 */ 
#define s8  signed int
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
	ddra|=(1<<1);
	porta&=~(1<<0);
	porta&=~(1<<1);
		ddrb&=~(1<<0);
	ddrb&=~(1<<1);
		ddrb&=~(1<<2);
		portb|=(1<<0);
		portb|=(1<<1);
		portb|=(1<<2);
    while (1) 
    {
		porta&=~(1<<0);
		porta&=~(1<<1);
		u8 sw1=((pinb>>0)&1),sw2=((pinb>>1)&1),sw3=((pinb>>2)&1);
		if(sw1==0&&sw2==1&&sw3==1){
			porta|=(1<<0);
			porta&=~(1<<1);
    }
	else if(sw1==1&&sw2==0&&sw3==1){
		porta|=(1<<1);
		porta&=~(1<<0);
	}
	else if(sw1==1&&sw2==1&&sw3==0){
			porta|=(1<<1);
			porta|=(1<<0);
	}
}

return 0;
}