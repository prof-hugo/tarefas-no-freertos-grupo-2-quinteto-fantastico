/*==================================================================================================

  tasks_FreeRTOS_qemu.c

  Used hardware: STM32F4-Discovery evaluation board (QEMU)

  Example of using the FreeRTOS Real-Time Operating System on the STM32F4-Discovery board.

  ==================================================================================================
*/

#include "stm32f4_discovery.h"
#include "FreeRTOS.h"
#include "task.h"

  typedef struct {
  	  int LED_index;
  	  int period;
    }xBlinkParam;


void vBlinkLED(void *pvParam){
	xBlinkParam* param = (xBlinkParam *) pvParam;
	const int LED_index = param->LED_index;
	const int time_delay = param->period;
	BSP_LED_Init(LED_index);
	TickType_t xLastWakeTime;
	const TickType_t xPeriod = time_delay / portTICK_PERIOD_MS;
	xLastWakeTime = xTaskGetTickCount();

	while(1){
	BSP_LED_Toggle(LED_index);
	vTaskDelayUntil(&xLastWakeTime, xPeriod);
	taskYIELD();
	}
}

void main(void){
  __HAL_RCC_GPIOD_CLK_ENABLE();

  static xBlinkParam LED_3 = {LED3 , 530};
  static xBlinkParam LED_4 = {LED4 , 430};
  static xBlinkParam LED_5 = {LED5 , 330};
  static xBlinkParam LED_6 = {LED6 , 230};



  xTaskCreate(vBlinkLED , "vBlinkLED3" , configMINIMAL_STACK_SIZE,  (void *) &LED_3  , tskIDLE_PRIORITY, NULL);
  xTaskCreate(vBlinkLED , "vBlinkLED4" , configMINIMAL_STACK_SIZE,  (void *) &LED_4  , tskIDLE_PRIORITY, NULL);
  xTaskCreate(vBlinkLED , "vBlinkLED5" , configMINIMAL_STACK_SIZE,  (void *) &LED_5  , tskIDLE_PRIORITY, NULL);
  xTaskCreate(vBlinkLED , "vBlinkLED6" , configMINIMAL_STACK_SIZE,  (void *) &LED_6  , tskIDLE_PRIORITY, NULL);

  vTaskStartScheduler();
  while(1);
} // main
