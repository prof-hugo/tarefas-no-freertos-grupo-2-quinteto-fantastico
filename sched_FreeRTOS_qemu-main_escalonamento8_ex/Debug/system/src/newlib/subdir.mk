################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../system/src/newlib/_exit.c \
../system/src/newlib/_sbrk.c \
../system/src/newlib/_startup.c \
../system/src/newlib/_syscalls.c \
../system/src/newlib/assert.c 

OBJS += \
./system/src/newlib/_exit.o \
./system/src/newlib/_sbrk.o \
./system/src/newlib/_startup.o \
./system/src/newlib/_syscalls.o \
./system/src/newlib/assert.o 

C_DEPS += \
./system/src/newlib/_exit.d \
./system/src/newlib/_sbrk.d \
./system/src/newlib/_startup.d \
./system/src/newlib/_syscalls.d \
./system/src/newlib/assert.d 


# Each subdirectory must supply rules for building sources it contributes
system/src/newlib/%.o: ../system/src/newlib/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F407xx -DUSE_HAL_DRIVER -DDEBUG -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -I"C:\Users\luisf\Desktop\Mesa\eclipse_ws\sched_FreeRTOS_qemu-main_escalonamento8_ex" -I"C:\Users\luisf\Desktop\Mesa\eclipse_ws\sched_FreeRTOS_qemu-main_escalonamento8_ex\Libraries\CMSIS\Core\Include" -I"C:\Users\luisf\Desktop\Mesa\eclipse_ws\sched_FreeRTOS_qemu-main_escalonamento8_ex\Libraries\CMSIS\Device\ST\STM32F4xx\Include" -I"C:\Users\luisf\Desktop\Mesa\eclipse_ws\sched_FreeRTOS_qemu-main_escalonamento8_ex\Libraries\STM32F4xx_HAL_Driver\Inc" -I"C:\Users\luisf\Desktop\Mesa\eclipse_ws\sched_FreeRTOS_qemu-main_escalonamento8_ex\FreeRTOS\Source\include" -I"C:\Users\luisf\Desktop\Mesa\eclipse_ws\sched_FreeRTOS_qemu-main_escalonamento8_ex\FreeRTOS\Source\portable\GCC\ARM_CM3" -I"C:\Users\luisf\Desktop\Mesa\eclipse_ws\sched_FreeRTOS_qemu-main_escalonamento8_ex\ESFree" -I"C:\Users\luisf\Desktop\Mesa\eclipse_ws\sched_FreeRTOS_qemu-main_escalonamento8_ex\system\inc" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


