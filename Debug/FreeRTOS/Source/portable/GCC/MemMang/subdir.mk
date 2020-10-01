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
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F407xx -DUSE_HAL_DRIVER -I"D:\Desktop\tasks_FreeRTOS_qemu-master" -I"D:\Desktop\tasks_FreeRTOS_qemu-master\Libraries\CMSIS\Core\Include" -I"D:\Desktop\tasks_FreeRTOS_qemu-master\Libraries\CMSIS\Device\ST\STM32F4xx\Include" -I"D:\Desktop\tasks_FreeRTOS_qemu-master\Libraries\STM32F4xx_HAL_Driver\Inc" -I"D:\Desktop\tasks_FreeRTOS_qemu-master\FreeRTOS\Source\include" -I"D:\Desktop\tasks_FreeRTOS_qemu-master\FreeRTOS\Source\portable\GCC\ARM_CM3" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


