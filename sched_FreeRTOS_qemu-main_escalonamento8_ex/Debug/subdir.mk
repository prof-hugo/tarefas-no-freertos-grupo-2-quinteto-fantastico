################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../sched_FreeRTOS_qemu.c \
../stm32f4_discovery.c \
../system_stm32f4xx.c 

S_UPPER_SRCS += \
../startup_stm32f407xx.S 

OBJS += \
./sched_FreeRTOS_qemu.o \
./startup_stm32f407xx.o \
./stm32f4_discovery.o \
./system_stm32f4xx.o 

S_UPPER_DEPS += \
./startup_stm32f407xx.d 

C_DEPS += \
./sched_FreeRTOS_qemu.d \
./stm32f4_discovery.d \
./system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F407xx -DUSE_HAL_DRIVER -DDEBUG -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -I"C:\Users\luisf\Desktop\Mesa\eclipse_ws\sched_FreeRTOS_qemu-main_escalonamento8_ex" -I"C:\Users\luisf\Desktop\Mesa\eclipse_ws\sched_FreeRTOS_qemu-main_escalonamento8_ex\Libraries\CMSIS\Core\Include" -I"C:\Users\luisf\Desktop\Mesa\eclipse_ws\sched_FreeRTOS_qemu-main_escalonamento8_ex\Libraries\CMSIS\Device\ST\STM32F4xx\Include" -I"C:\Users\luisf\Desktop\Mesa\eclipse_ws\sched_FreeRTOS_qemu-main_escalonamento8_ex\Libraries\STM32F4xx_HAL_Driver\Inc" -I"C:\Users\luisf\Desktop\Mesa\eclipse_ws\sched_FreeRTOS_qemu-main_escalonamento8_ex\FreeRTOS\Source\include" -I"C:\Users\luisf\Desktop\Mesa\eclipse_ws\sched_FreeRTOS_qemu-main_escalonamento8_ex\FreeRTOS\Source\portable\GCC\ARM_CM3" -I"C:\Users\luisf\Desktop\Mesa\eclipse_ws\sched_FreeRTOS_qemu-main_escalonamento8_ex\ESFree" -I"C:\Users\luisf\Desktop\Mesa\eclipse_ws\sched_FreeRTOS_qemu-main_escalonamento8_ex\system\inc" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

%.o: ../%.S
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross Assembler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


