################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Password/Password.c 

OBJS += \
./HAL/Password/Password.o 

C_DEPS += \
./HAL/Password/Password.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Password/%.o: ../HAL/Password/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"E:\Mohamed\NTI\Embedded projects\AVR_Project\HAL\LCD" -I"E:\Mohamed\NTI\Embedded projects\AVR_Project\MCAL\UART" -I"E:\Mohamed\NTI\Embedded projects\AVR_Project\HAL\Password" -I"E:\Mohamed\NTI\Embedded projects\AVR_Project\HAL\RTC" -I"E:\Mohamed\NTI\Embedded projects\AVR_Project\MCAL\DIO" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

