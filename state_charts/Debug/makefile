################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src-gen/subdir.mk
-include sc_timer/subdir.mk
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
CA9-PartA.lss \

FLASH_IMAGE += \
CA9-PartA.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: CA9-PartA.elf secondary-outputs

# Tool invocations
CA9-PartA.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,CA9-PartA.map -mmcu=atmega328p -o "CA9-PartA.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

CA9-PartA.lss: CA9-PartA.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S CA9-PartA.elf  >"CA9-PartA.lss"
	@echo 'Finished building: $@'
	@echo ' '

CA9-PartA.hex: CA9-PartA.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex CA9-PartA.elf  "CA9-PartA.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: CA9-PartA.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p CA9-PartA.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) CA9-PartA.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
