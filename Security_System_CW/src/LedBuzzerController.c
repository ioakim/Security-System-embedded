/**
  ******************************************************************************
  * @file    LedBuzzerController.h 
  * @author  Tiberiu Simion Voicu, Ioakim Ioakim
  * @version V1.0.0
  * @date    17 April 2018
  * @brief   This file provide implementation of the functions used 
						 to control the control the LEDs, buzzer and button
  ******************************************************************************
  */
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
	digitalWrite(led1_GPIO_Num, 1);
	digitalWrite(led2_GPIO_Num, 1);
	 
 }
void startAlarm() {
  digitalWrite(led1_GPIO_Num, 1);
  digitalWrite(led2_GPIO_Num, 1);
	digitalWrite(buzzer_GPIO_Num, 1);
}
void stopAlarm() {
  digitalWrite(led1_GPIO_Num, 0);
  digitalWrite(led2_GPIO_Num, 0);
	digitalWrite(buzzer_GPIO_Num, 0);
}
