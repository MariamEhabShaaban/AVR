#ifndef ADC_PRIV_H_
#define ADC_PRIV_H_

/***********     Voltage Source     *************/
#define AREF 0
#define AVCC 1
#define INT_VREF 3

/*************Adress of Registers***************/

#define ADMUX  (*(u8*)0x27)
#define ADCSRA (*(u8*)0x26)
#define ADCH   (*(volatile u8*)0x25)
#define ADCL   (*(volatile u8*)0x24)

#define ADCADJ (*(volatile u16*)0x24)//ADCH ADCL
#define SFIOR  (*(u8*)0x50)

/*****Adjust*****/
#define Left_Adjust 1
#define Right_Adjust 0

/*****************Single or Diff************/
#define single_ended 0   //mux0:4
#define Diff 1


#define DIV_FACT2 0 //first 3pins ADPS0:2
#define DIV_FACT4 2
#define DIV_FACT8 3
#define DIV_FACT16 4
#define DIV_FACT32 5
#define DIV_FACT64 6
#define DIV_FACT128 7

/********Trigger Source*****************/
#define Free_Running_mode 0
#define  Analog_Comparator  1
#define  EXT_Request  2

#endif
