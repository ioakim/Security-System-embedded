#include "gpioController.h"
#include "pirController.h"


void initPir () {
	initGPIO(pir_GPIO_Num, GPIO_MODE_IT_RISING, GPIO_NOPULL, GPIO_SPEED_HIGH, 0);
	//Delay to calibrate sensor 
	HAL_Delay(100);
	
	HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(EXTI0_IRQn);
	//HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

void pool_pir(void) {
	
	
}
void startAlarm(void);
void stopAlarm(void);
void startAlarm() {
  // if not initiated led then initiate
  digitalWrite(led1_GPIO_Num, 1);
  digitalWrite(led2_GPIO_Num, 1);
//	digitalWrite(buzzer_GPIO_Num, 1);
	//stopAlarm();
}
void stopAlarm() {
  digitalWrite(led1_GPIO_Num, 0);
  digitalWrite(led2_GPIO_Num, 0);
	digitalWrite(buzzer_GPIO_Num, 0);
}
/*
    Handle line 0 interrupt
*/
   void EXTI0_IRQHandler(void) {
	 HAL_GPIO_EXTI_IRQHandler(getPin(pir_GPIO_Num).pin);
 }
	 void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
		 if (GPIO_Pin == getPin(pir_GPIO_Num).pin) {
			 startAlarm();
			 HAL_Delay(500);
			 stopAlarm();
		 }
	 }
 

