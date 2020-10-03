################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS/Source/portable/GCC/MemMang/heap_2.c 

OBJS += \
./FreeRTOS/Source/portable/GCC/MemMang/heap_2.o 

C_DEPS += \
./FreeRTOS/Source/portable/GCC/MemMang/heap_2.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS/Source/portable/GCC/MemMang/%.o: ../FreeRTOS/Source/portable/GCC/MemMang/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F407xx -DUSE_HAL_DRIVER -I"/home/luis/eclipse-workspace/FreeRTOS_ex2b" -I"/home/luis/eclipse-workspace/FreeRTOS_ex2b/Libraries/CMSIS/Core/Include" -I"/home/luis/eclipse-workspace/FreeRTOS_ex2b/Libraries/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/luis/eclipse-workspace/FreeRTOS_ex2b/Libraries/STM32F4xx_HAL_Driver/Inc" -I"/home/luis/eclipse-workspace/FreeRTOS_ex2b/FreeRTOS/Source/include" -I"/home/luis/eclipse-workspace/FreeRTOS_ex2b/FreeRTOS/Source/portable/GCC/ARM_CM3" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


