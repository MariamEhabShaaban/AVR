
#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_
//AVCC AREF INT_VREF
#define Vref AVCC

#define ADC_SOURCE ADC0  //ADC0:7
/*#define ADC_SOURCE2 ADC1
#define ADC_SOURCE3 ADC2
#define ADC_SOURCE4 ADC3
#define ADC_SOURCE5 ADC4
#define ADC_SOURCE6 ADC5
#define ADC_SOURCE7 ADC6
#define ADC_SOURCE8 ADC7*/

#define Adjust_Type Right_Adjust //Left_Adjust or Right_Adjust

#define Analog_channel Single_ended //Single_ended or Diff

#define division_factor DIV_FACT128 //DIV_FACT2:DIV_FACT128

#define Trigger_Source Free_Running_mode //Free_Running_mode or Analog_Comparator or EXT_Request

#endif
