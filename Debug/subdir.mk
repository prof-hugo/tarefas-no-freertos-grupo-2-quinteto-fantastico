################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS_ex2b.c \
../stm32f4_discovery.c \
../system_stm32f4xx.c 

S_UPPER_SRCS += \
../startup_stm32f407xx.S 

OBJS += \
./FreeRTOS_ex2b.o \
./startup_stm32f407xx.o \
./stm32f4_discovery.o \
./system_stm32f4xx.o 

S_UPPER_DEPS += \
./startup_stm32f407xx.d 

C_DEPS += \
./FreeRTOS_ex2b.d \
./stm32f4_discovery.d \
./system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F407xx -DUSE_HAL_DRIVER -I"/home/luis/eclipse-workspace/FreeRTOS_ex2b" -I"/home/luis/eclipse-workspace/FreeRTOS_ex2b/Libraries/CMSIS/Core/Include" -I"/home/luis/eclipse-workspace/FreeRTOS_ex2b/Libraries/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/luis/eclipse-workspace/FreeRTOS_ex2b/Libraries/STM32F4xx_HAL_Driver/Inc" -I"/home/luis/eclipse-workspace/FreeRTOS_ex2b/FreeRTOS/Source/include" -I"/home/luis/eclipse-workspace/FreeRTOS_ex2b/FreeRTOS/Source/portable/GCC/ARM_CM3" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

%.o: ../%.S
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross Assembler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


