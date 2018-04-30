#include "LedBuzzerController.h"

void initBuzzer (int8_t Dindex) {
	initGPIO(Dindex, GPIO_MODE_OUTPUT_PP, GPIO_PULLUP, GPIO_SPEED_HIGH, 0);
}
void initLed (int8_t Dindex) {
	initGPIO(Dindex, GPIO_MODE_OUTPUT_PP, GPIO_PULLDOWN, GPIO_SPEED_HIGH, 0);
}
void initButton() {
	initGPIO(button_GPIO_Num, GPIO_MODE_IT_RISING, GPIO_PULLDOWN, GPIO_SPEED_HIGH, 0);
	HAL_NVIC_SetPriority(EXTI4_IRQn, 3, 0);
	HAL_NVIC_EnableIRQ(EXTI4_IRQn);
}
void startLights() {
	 uint16_t i = 0;
	 digitalWrite(led1_GPIO_Num, 1);
	 digitalWrite(led2_GPIO_Num, 1);
//	 while(i < 50000) 
//		 i++;
//	 i = 0;
//	 digitalWrite(led1_GPIO_Num, 1);
//	 digitalWrite(led2_GPIO_Num, 1);
	 
 }
void startAlarm() {
  // if not initiated led then initiate
  digitalWrite(led1_GPIO_Num, 1);
  digitalWrite(led2_GPIO_Num, 1);
	digitalWrite(buzzer_GPIO_Num, 1);
}
void stopAlarm() {
  digitalWrite(led1_GPIO_Num, 0);
  digitalWrite(led2_GPIO_Num, 0);
	digitalWrite(buzzer_GPIO_Num, 0);
}
/* 
	IRQ handler for button on line 4 
*/
void EXTI4_IRQHandler() {
	HAL_GPIO_EXTI_IRQHandler(getPin(button_GPIO_Num).pin);
}
