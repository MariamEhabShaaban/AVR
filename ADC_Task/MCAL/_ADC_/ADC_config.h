
#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_
//AVCC AREF INT_VREF
#define Vref AVCC

#define Adjust_Type Right_Adjust //Left_Adjust or Right_Adjust

#define Analog_channel Single_ended //Single_ended or Diff

#define prescalar DIV_FACT128 //DIV_FACT2:DIV_FACT128

#define Trigger_Source Free_Running_mode //Free_Running_mode or Analog_Comparator or EXT_Request

#endif
