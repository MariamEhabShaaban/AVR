################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/_ADC_/ADC_prog.c 

OBJS += \
./MCAL/_ADC_/ADC_prog.o 

C_DEPS += \
./MCAL/_ADC_/ADC_prog.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/_ADC_/%.o: ../MCAL/_ADC_/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


