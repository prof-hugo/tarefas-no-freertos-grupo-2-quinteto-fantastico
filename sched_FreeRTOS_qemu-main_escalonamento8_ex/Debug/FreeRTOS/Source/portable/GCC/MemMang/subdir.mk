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
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F407xx -DUSE_HAL_DRIVER -DDEBUG -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -I"C:\Users\luisf\Desktop\Mesa\eclipse_ws\sched_FreeRTOS_qemu-main_escalonamento8_ex" -I"C:\Users\luisf\Desktop\Mesa\eclipse_ws\sched_FreeRTOS_qemu-main_escalonamento8_ex\Libraries\CMSIS\Core\Include" -I"C:\Users\luisf\Desktop\Mesa\eclipse_ws\sched_FreeRTOS_qemu-main_escalonamento8_ex\Libraries\CMSIS\Device\ST\STM32F4xx\Include" -I"C:\Users\luisf\Desktop\Mesa\eclipse_ws\sched_FreeRTOS_qemu-main_escalonamento8_ex\Libraries\STM32F4xx_HAL_Driver\Inc" -I"C:\Users\luisf\Desktop\Mesa\eclipse_ws\sched_FreeRTOS_qemu-main_escalonamento8_ex\FreeRTOS\Source\include" -I"C:\Users\luisf\Desktop\Mesa\eclipse_ws\sched_FreeRTOS_qemu-main_escalonamento8_ex\FreeRTOS\Source\portable\GCC\ARM_CM3" -I"C:\Users\luisf\Desktop\Mesa\eclipse_ws\sched_FreeRTOS_qemu-main_escalonamento8_ex\ESFree" -I"C:\Users\luisf\Desktop\Mesa\eclipse_ws\sched_FreeRTOS_qemu-main_escalonamento8_ex\system\inc" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


