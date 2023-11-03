################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/DIO/subdir.mk
-include HAL/Solenoid/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Solenoid_driver.lss \

FLASH_IMAGE += \
Solenoid_driver.hex \

EEPROM_IMAGE += \
Solenoid_driver.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Solenoid_driver.elf secondary-outputs

# Tool invocations
Solenoid_driver.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Solenoid_driver.map -mmcu=atmega32 -o "Solenoid_driver.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Solenoid_driver.lss: Solenoid_driver.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Solenoid_driver.elf  >"Solenoid_driver.lss"
	@echo 'Finished building: $@'
	@echo ' '

Solenoid_driver.hex: Solenoid_driver.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Solenoid_driver.elf  "Solenoid_driver.hex"
	@echo 'Finished building: $@'
	@echo ' '

Solenoid_driver.eep: Solenoid_driver.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Solenoid_driver.elf  "Solenoid_driver.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Solenoid_driver.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Solenoid_driver.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Solenoid_driver.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
