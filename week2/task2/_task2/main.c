/*
 * _task2.c
 *
 * Created: 10/6/2023 7:15:20 AM
 * Author : repair
 */ 

#define u8 unsigned int
#define ddra *((u8*)0x3A)
#define porta *((u8*)0x3B)
#define  pina *((volatile u8*)0x39)
#define ddrb *((u8*)0x37)
#define portb *((u8*)0x38)
#define  pinb *((volatile u8*)0x36)
#define ddrd *((u8*)0x31)
#define portd *((u8*)0x32)
#define  pind *((volatile u8*)0x30)
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
   
  
  ddra =0;
   porta=0xFF;
 
  ddrd=0xff;
  portd=0;

  u8 Segment[]={0x3F,0x06,0x5B,
	  0x4F,0x66,0x6D,0x7D,
	  0x07,0x7F,0x6F
  },counter=0;
  portd=Segment[0];
  while(1)
  {
	  if(((pina>>0)&1)==0)
	  {
		  
		  if(counter<9)
		  {
			  counter++;
		  }
		  portd=Segment[counter];
		  while(((pina>>0)&1)==0);
	  }
	  if(((pina>>1)&1)==0)
	  {
		  if(counter>0)
		   counter--;



		 
		  portd=Segment[counter];
		  while(((pina>>1)&1)==0);
	  }
	 



  }
  return 0;
}

