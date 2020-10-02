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



void vBlinkLED3(void *pvParam){
	   int* param = pvParam;
	  const int LED_index = LED3;
	  const int time_delay = 530;
	  BSP_LED_Init(LED_index);
	  TickType_t xLastWakeTime;
	  const TickType_t xPeriod = time_delay / portTICK_PERIOD_MS;
	  xLastWakeTime = xTaskGetTickCount();

	  while(1){
	    BSP_LED_Toggle(LED_index);
	    vTaskDelayUntil(&xLastWakeTime, xPeriod);
	    taskYIELD();
	  } // while
} // vBlinkLED3

void vBlinkLED4(void *pvParam){
	   int* param = pvParam;
	  const int LED_index = LED4;
	  const int time_delay = 430;
	  BSP_LED_Init(LED_index);
	  TickType_t xLastWakeTime;
	  const TickType_t xPeriod = time_delay / portTICK_PERIOD_MS;
	  xLastWakeTime = xTaskGetTickCount();

	  while(1){
	    BSP_LED_Toggle(LED_index);
	    vTaskDelayUntil(&xLastWakeTime, xPeriod);
	    taskYIELD();
	  } // while
} // vBlinkLED4

void vBlinkLED5(void *pvParam){
	   int* param = pvParam;
	  const int LED_index = LED5;
	  const int time_delay = 330;
	  BSP_LED_Init(LED_index);
	  TickType_t xLastWakeTime;
	  const TickType_t xPeriod = time_delay / portTICK_PERIOD_MS;
	  xLastWakeTime = xTaskGetTickCount();

	  while(1){
	    BSP_LED_Toggle(LED_index);
	    vTaskDelayUntil(&xLastWakeTime, xPeriod);
	    taskYIELD();
	  } // while
} // vBlinkLED5

void vBlinkLED6(void *pvParam){
	  const int LED_index = LED6;
	  const int time_delay = 230;
	  BSP_LED_Init(LED_index);
	  TickType_t xLastWakeTime;
	  const TickType_t xPeriod = time_delay / portTICK_PERIOD_MS;
	  xLastWakeTime = xTaskGetTickCount();

	  while(1){
	    BSP_LED_Toggle(LED_index);
	    vTaskDelayUntil(&xLastWakeTime, xPeriod);
	    taskYIELD();
	  } // while
} // vBlinkLED3


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

int param[] = {LED3, 500};
void main(void){
  __HAL_RCC_GPIOD_CLK_ENABLE();


  static xBlinkParam LED_3 = {LED3 , 530};
  static xBlinkParam LED_4 = {LED4 , 430};
  static xBlinkParam LED_5 = {LED5 , 330};
  static xBlinkParam LED_6 = {LED6 , 230};


  /*
  xTaskCreate(vBlinkLED3, "vBlinkLED3", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL);
  xTaskCreate(vBlinkLED4, "vBlinkLED4", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL);
  xTaskCreate(vBlinkLED5, "vBlinkLED5", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL);
  xTaskCreate(vBlinkLED6, "vBlinkLED6", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL);
*/

  xTaskCreate(vBlinkLED , "vBlinkLED3" , configMINIMAL_STACK_SIZE,  (void *) &LED_3  , tskIDLE_PRIORITY, NULL);
  xTaskCreate(vBlinkLED , "vBlinkLED4" , configMINIMAL_STACK_SIZE,  (void *) &LED_4  , tskIDLE_PRIORITY, NULL);
  xTaskCreate(vBlinkLED , "vBlinkLED5" , configMINIMAL_STACK_SIZE,  (void *) &LED_5  , tskIDLE_PRIORITY, NULL);
  xTaskCreate(vBlinkLED , "vBlinkLED6" , configMINIMAL_STACK_SIZE,  (void *) &LED_6  , tskIDLE_PRIORITY, NULL);

  vTaskStartScheduler();
  while(1);
} // main
