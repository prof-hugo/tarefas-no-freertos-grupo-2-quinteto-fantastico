#include "stm32f4_discovery.h"
#include "FreeRTOS.h"
#include "task.h"


typedef struct parametros{
	int Led;
	int T;

}parametros;

void vBlinkLED( parametros *pvParam){
  int periodo = pvParam-> T;
  int LED = pvParam->Led;

  TickType_t xLastWakeTime;
  const TickType_t xPeriod = periodo / portTICK_PERIOD_MS;
  xLastWakeTime = xTaskGetTickCount();

  while(1){
    BSP_LED_Toggle(LED);
    vTaskDelayUntil(&xLastWakeTime, xPeriod);
  }
}



void main(void){
  __HAL_RCC_GPIOD_CLK_ENABLE();
  BSP_LED_Init(LED4);
  BSP_LED_Init(LED5);
  BSP_LED_Init(LED3);
  BSP_LED_Init(LED6);

  static parametros led3 = {LED3, 530};
  static parametros led4 = {LED4, 430};
  static parametros led5 = {LED5, 330};
  static parametros led6 = {LED6, 230};

  xTaskCreate(vBlinkLED, "vBlinkLED3", configMINIMAL_STACK_SIZE, &led3, tskIDLE_PRIORITY, NULL);
  xTaskCreate(vBlinkLED, "vBlinkLED4", configMINIMAL_STACK_SIZE, &led4, tskIDLE_PRIORITY, NULL);
  xTaskCreate(vBlinkLED, "vBlinkLED5", configMINIMAL_STACK_SIZE, &led5, tskIDLE_PRIORITY, NULL);
  xTaskCreate(vBlinkLED, "vBlinkLED6", configMINIMAL_STACK_SIZE, &led6, tskIDLE_PRIORITY, NULL);

  vTaskStartScheduler();
  while(1);
} // main
