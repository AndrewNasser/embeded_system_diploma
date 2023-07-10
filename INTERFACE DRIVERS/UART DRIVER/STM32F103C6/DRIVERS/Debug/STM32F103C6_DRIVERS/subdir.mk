################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32F103C6_DRIVERS/STM32F103C6_EXTI_DRIVER.c \
../STM32F103C6_DRIVERS/STM32F103C6_GPIO_DRIVER.c \
../STM32F103C6_DRIVERS/STM32F103C6_RCC_DRIVER.c \
../STM32F103C6_DRIVERS/STM32F103C6_USART_DRIVER.c 

OBJS += \
./STM32F103C6_DRIVERS/STM32F103C6_EXTI_DRIVER.o \
./STM32F103C6_DRIVERS/STM32F103C6_GPIO_DRIVER.o \
./STM32F103C6_DRIVERS/STM32F103C6_RCC_DRIVER.o \
./STM32F103C6_DRIVERS/STM32F103C6_USART_DRIVER.o 

C_DEPS += \
./STM32F103C6_DRIVERS/STM32F103C6_EXTI_DRIVER.d \
./STM32F103C6_DRIVERS/STM32F103C6_GPIO_DRIVER.d \
./STM32F103C6_DRIVERS/STM32F103C6_RCC_DRIVER.d \
./STM32F103C6_DRIVERS/STM32F103C6_USART_DRIVER.d 


# Each subdirectory must supply rules for building sources it contributes
STM32F103C6_DRIVERS/STM32F103C6_EXTI_DRIVER.o: ../STM32F103C6_DRIVERS/STM32F103C6_EXTI_DRIVER.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/King 45M/STM32CubeIDE/workspace_1.4.0/DRIVERS/HAL" -I../Inc -I"C:/Users/King 45M/STM32CubeIDE/workspace_1.4.0/DRIVERS/STM32F103C6_DRIVERS/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103C6_DRIVERS/STM32F103C6_EXTI_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32F103C6_DRIVERS/STM32F103C6_GPIO_DRIVER.o: ../STM32F103C6_DRIVERS/STM32F103C6_GPIO_DRIVER.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/King 45M/STM32CubeIDE/workspace_1.4.0/DRIVERS/HAL" -I../Inc -I"C:/Users/King 45M/STM32CubeIDE/workspace_1.4.0/DRIVERS/STM32F103C6_DRIVERS/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103C6_DRIVERS/STM32F103C6_GPIO_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32F103C6_DRIVERS/STM32F103C6_RCC_DRIVER.o: ../STM32F103C6_DRIVERS/STM32F103C6_RCC_DRIVER.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/King 45M/STM32CubeIDE/workspace_1.4.0/DRIVERS/HAL" -I../Inc -I"C:/Users/King 45M/STM32CubeIDE/workspace_1.4.0/DRIVERS/STM32F103C6_DRIVERS/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103C6_DRIVERS/STM32F103C6_RCC_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32F103C6_DRIVERS/STM32F103C6_USART_DRIVER.o: ../STM32F103C6_DRIVERS/STM32F103C6_USART_DRIVER.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/King 45M/STM32CubeIDE/workspace_1.4.0/DRIVERS/HAL" -I../Inc -I"C:/Users/King 45M/STM32CubeIDE/workspace_1.4.0/DRIVERS/STM32F103C6_DRIVERS/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103C6_DRIVERS/STM32F103C6_USART_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

