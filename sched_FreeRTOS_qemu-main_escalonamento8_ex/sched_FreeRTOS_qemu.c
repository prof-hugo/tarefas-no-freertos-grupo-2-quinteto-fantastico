/*==================================================================================================

  sched_FreeRTOS_qemu.c

  Used hardware: STM32F4-Discovery evaluation board (QEMU)

  Example of using the FreeRTOS with the ESFree scheduler on the STM32F4-Discovery board.

  ==================================================================================================
*/

#include "stm32f4_discovery.h"
#include "scheduler.h"
#include "diag/Trace.h"


TaskHandle_t xHandle1 = NULL, xHandle2 = NULL, xHandle3 = NULL;


void vBlink(void *pvParam){
	int dt = (int)xTaskGetTickCount();
  trace_printf("%s*************\n", pcTaskGetName(NULL));
  trace_printf("%s priority: %i\n", pcTaskGetName(xHandle1),uxTaskPriorityGet(xHandle1));
  trace_printf("%s priority: %i\n", pcTaskGetName(xHandle2),uxTaskPriorityGet(xHandle2));
  trace_printf("%s priority: %i\n", pcTaskGetName(xHandle3),uxTaskPriorityGet(xHandle3));

  int i;
  for(i=0;i<800000;i++);

  dt =(int)xTaskGetTickCount() - dt;
  trace_printf("dt %i\n",dt);

  BSP_LED_Toggle((uint32_t)pvParam);

} // vBlink


void main(void){
  __HAL_RCC_GPIOD_CLK_ENABLE();
  BSP_LED_Init(LED3);
  BSP_LED_Init(LED5);
  BSP_LED_Init(LED6);

  vSchedulerInit();

  vSchedulerPeriodicTaskCreate(vBlink, "Task1", configMINIMAL_STACK_SIZE, (void *)LED3, 1, &xHandle1, pdMS_TO_TICKS(000), pdMS_TO_TICKS(200), pdMS_TO_TICKS(010), pdMS_TO_TICKS(200));
  vSchedulerPeriodicTaskCreate(vBlink, "Task2", configMINIMAL_STACK_SIZE, (void *)LED6, 1, &xHandle2, pdMS_TO_TICKS(150), pdMS_TO_TICKS(250), pdMS_TO_TICKS(010), pdMS_TO_TICKS(250));
  vSchedulerPeriodicTaskCreate(vBlink, "Task3", configMINIMAL_STACK_SIZE, (void *)LED5, 1, &xHandle3, pdMS_TO_TICKS(200), pdMS_TO_TICKS(300), pdMS_TO_TICKS(010), pdMS_TO_TICKS(300));

  vSchedulerStart();
  while(1);
} // main
