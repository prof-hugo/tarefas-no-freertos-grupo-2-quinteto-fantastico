/*==================================================================================================

  sched_FreeRTOS_qemu.c

  Used hardware: STM32F4-Discovery evaluation board (QEMU)

  Example of using the FreeRTOS with the ESFree scheduler on the STM32F4-Discovery board.

  ==================================================================================================
*/

#include "stm32f4_discovery.h"
#include "scheduler.h"
#include "system/inc/diag/Trace.h"
#include "semphr.h"


TaskHandle_t xHandle1 = NULL, xHandle2 = NULL, xHandle3 = NULL, xHandle4 = NULL;
SemaphoreHandle_t xMutex1 = NULL, xMutex2 = NULL;
void delay(int ticks)
{	int i;
	for(i=0; i<160000*ticks;i++);
}

void vTask1(void *pvParam){
  trace_printf("T1,INICIO: %d\n", (int)xTaskGetTickCount());
  delay(10);

  trace_printf("T1,TAKE M1: %d\n", (int)xTaskGetTickCount());
  if(xSemaphoreTake(xMutex1, 20000) == pdTRUE)
  {
	  trace_printf("T1,TAKE OK M1: %d\n", (int)xTaskGetTickCount());
	  delay(10);
	  trace_printf("T1,GIVE M1: %d\n", (int)xTaskGetTickCount());
	  xSemaphoreGive(xMutex1);
  }

  trace_printf("T1,TAKE M2: %d\n", (int)xTaskGetTickCount());
  if(xSemaphoreTake(xMutex2, 20000) == pdTRUE)
    {
	  trace_printf("T1,TAKE OK M2: %d\n", (int)xTaskGetTickCount());
	  delay(10);
	  trace_printf("T1,GIVE M2: %d\n", (int)xTaskGetTickCount());
  	  xSemaphoreGive(xMutex2);
    }

  delay(10);
  trace_printf("T1,FIM: %d\n", (int)xTaskGetTickCount());

} // vTask1

void vTask2(void *pvParam){
  trace_printf("T2,INICIO: %d\n", (int)xTaskGetTickCount());
  delay(10);

  trace_printf("T2,TAKE M2: %d\n", (int)xTaskGetTickCount());
    if(xSemaphoreTake(xMutex2, 20000) == pdTRUE)
      {
		  trace_printf("T2,TAKE OK M2: %d\n", (int)xTaskGetTickCount());
		  delay(20);
		  trace_printf("T2,GIVE M2: %d\n", (int)xTaskGetTickCount());
		  xSemaphoreGive(xMutex2);
      }

  delay(10);
  trace_printf("T2,FIM: %d\n", (int)xTaskGetTickCount());

} // vTask2

void vTask3(void *pvParam){
	trace_printf("T3,INI: %d\n", (int)xTaskGetTickCount());
    delay(10);
    trace_printf("T3,FIM: %d\n", (int)xTaskGetTickCount());

} // vTask3

void vTask4(void *pvParam){
	  trace_printf("T4,INI: %d\n", (int)xTaskGetTickCount());
	delay(10);

	trace_printf("T4,TAKE M1: %d\n", (int)xTaskGetTickCount());
	  if(xSemaphoreTake(xMutex1, 20000) == pdTRUE)
	  {
		  trace_printf("T4,TAKE OK M1: %d\n", (int)xTaskGetTickCount());
		  delay(40);
		  trace_printf("T4,GIVE M1: %d\n", (int)xTaskGetTickCount());
		  xSemaphoreGive(xMutex1);
	  }

	delay(10);
	trace_printf("T4,FIM: %d\n", (int)xTaskGetTickCount());

} // vTask4


void main(void){
  __HAL_RCC_GPIOD_CLK_ENABLE();
  BSP_LED_Init(LED3);
  BSP_LED_Init(LED4);
  BSP_LED_Init(LED5);
  BSP_LED_Init(LED6);

  vSchedulerInit();

  vSchedulerPeriodicTaskCreate(vTask1, "Task1", configMINIMAL_STACK_SIZE, (void *)NULL, 4, &xHandle1, 160, 20000, 40, 20000);
  vSchedulerPeriodicTaskCreate(vTask2, "Task2", configMINIMAL_STACK_SIZE, (void *)NULL, 3, &xHandle1, 140, 20000, 40, 20000);
  vSchedulerPeriodicTaskCreate(vTask3, "Task3", configMINIMAL_STACK_SIZE, (void *)NULL, 2, &xHandle1, 140, 20000, 10, 20000);
  vSchedulerPeriodicTaskCreate(vTask4, "Task4", configMINIMAL_STACK_SIZE, (void *)NULL, 1, &xHandle1, 120, 20000, 60, 20000);

  xMutex1 = xSemaphoreCreateMutex();
  xMutex2 = xSemaphoreCreateMutex();

  vSchedulerStart();
  while(1);
} // main
