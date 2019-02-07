################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
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
CA7_keypad_lcd_interfacing_with_interrupts.lss \

FLASH_IMAGE += \
CA7_keypad_lcd_interfacing_with_interrupts.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: CA7_keypad_lcd_interfacing_with_interrupts.elf secondary-outputs

# Tool invocations
CA7_keypad_lcd_interfacing_with_interrupts.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,CA7_keypad_lcd_interfacing_with_interrupts.map -mmcu=atmega328p -o "CA7_keypad_lcd_interfacing_with_interrupts.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

CA7_keypad_lcd_interfacing_with_interrupts.lss: CA7_keypad_lcd_interfacing_with_interrupts.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S CA7_keypad_lcd_interfacing_with_interrupts.elf  >"CA7_keypad_lcd_interfacing_with_interrupts.lss"
	@echo 'Finished building: $@'
	@echo ' '

CA7_keypad_lcd_interfacing_with_interrupts.hex: CA7_keypad_lcd_interfacing_with_interrupts.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex CA7_keypad_lcd_interfacing_with_interrupts.elf  "CA7_keypad_lcd_interfacing_with_interrupts.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: CA7_keypad_lcd_interfacing_with_interrupts.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p CA7_keypad_lcd_interfacing_with_interrupts.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) CA7_keypad_lcd_interfacing_with_interrupts.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
