################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F1xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
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
EXECUTABLES += \
CASE_STUDY.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
CASE_STUDY.list \

OBJCOPY_BIN += \
CASE_STUDY.bin \


# All Target
all: CASE_STUDY.elf secondary-outputs

# Tool invocations
CASE_STUDY.elf: $(OBJS) $(USER_OBJS) D:\embeded_system_diploma\CAN\ PROTOCOL\CASE\ STUDY\ 1\CODES\CASE_STUDY\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -o "CASE_STUDY.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"D:\embeded_system_diploma\CAN PROTOCOL\CASE STUDY 1\CODES\CASE_STUDY\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="CASE_STUDY.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

CASE_STUDY.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "CASE_STUDY.list"
	@echo 'Finished building: $@'
	@echo ' '

CASE_STUDY.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "CASE_STUDY.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
