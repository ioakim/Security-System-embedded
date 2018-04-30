#include "gpioController.h"
#include "pirController.h"
#include "touchInputController.h"
#include "LedBuzzerController.h"

void initPir () {
	initGPIO(pir_GPIO_Num, GPIO_MODE_IT_RISING, GPIO_NOPULL, GPIO_SPEED_HIGH, 0);
	//Delay to calibrate sensor 
	
	HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(EXTI0_IRQn);
	//HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}
/*
    Handle line 0 interrupt
*/
   void EXTI0_IRQHandler(void) {
		HAL_GPIO_EXTI_IRQHandler(getPin(pir_GPIO_Num).pin);
		HAL_NVIC_DisableIRQ(EXTI0_IRQn);
 }
	 void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
		 char key;
		 
		 if (GPIO_Pin == getPin(pir_GPIO_Num).pin) { // pir pin
			startLights();
			GLCD_ClearScreen();
			drawKeypad();
		 }
		 else if (GPIO_Pin == GPIO_PIN_13) {// touch pin
			 key = getTouch();
			 addKey(key);			 
		 }
		 else if (GPIO_Pin == getPin(button_GPIO_Num).pin) {
			 // button pin
			initPir();
			HAL_NVIC_DisableIRQ(EXTI4_IRQn);
		 }
	 }
 

