################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Includes/keypad.c \
../HAL/Includes/lcd.c 

OBJS += \
./HAL/Includes/keypad.o \
./HAL/Includes/lcd.o 

C_DEPS += \
./HAL/Includes/keypad.d \
./HAL/Includes/lcd.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Includes/keypad.o: ../HAL/Includes/keypad.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/King 45M/STM32CubeIDE/workspace_1.4.0/DRIVERS/HAL" -I../Inc -I"C:/Users/King 45M/STM32CubeIDE/workspace_1.4.0/DRIVERS/STM32F103C6_DRIVERS/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/Includes/keypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL/Includes/lcd.o: ../HAL/Includes/lcd.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/King 45M/STM32CubeIDE/workspace_1.4.0/DRIVERS/HAL" -I../Inc -I"C:/Users/King 45M/STM32CubeIDE/workspace_1.4.0/DRIVERS/STM32F103C6_DRIVERS/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/Includes/lcd.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

