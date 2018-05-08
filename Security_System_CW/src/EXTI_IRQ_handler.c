#include "pirController.h"
#include "touchInputController.h"

/**
  * @brief  Initiate Motor
  * @param  dIndex: index belonging to GPIO Pin on board to be used for controlling 	*	@paramthe motor
  * @retval None
  */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	char key;
	// pir pin interrupt
	if (GPIO_Pin == getPin(pir_GPIO_Num).pin) { 
		startLights();
		GLCD_ClearScreen();
		drawKeypad();
	}

	// touch pin interrupt
	else if (GPIO_Pin == GPIO_PIN_13) {
		key = getTouch();
		addKey(key);			 
	}

	// button pin interrupt 
	// initiate PIR sensor and disable button interrupt
	else if (GPIO_Pin == getPin(button_GPIO_Num).pin) {
		initPir();
		HAL_NVIC_DisableIRQ(EXTI4_IRQn);
	}
}

/**
  * @brief Handle line 0 interrupt
  * @param None
  * @retval None
*/
void EXTI0_IRQHandler(void) {
	HAL_GPIO_EXTI_IRQHandler(getPin(pir_GPIO_Num).pin);
	HAL_NVIC_DisableIRQ(EXTI0_IRQn);
}

/**
  * @brief Handle Interrupts on line 4 for Touch input
  * @param None
  * @retval None
*/
void EXTI4_IRQHandler() {
	HAL_GPIO_EXTI_IRQHandler(getPin(button_GPIO_Num).pin);
}

/**
  * @brief Handle Interrupts on line 15-10 for Touch input
  * @param None
  * @retval None
*/
void EXTI15_10_IRQHandler(void) {
	HAL_GPIO_EXTI_IRQHandler(TS_INT_PIN);
	delayMicro(50000000);	
}

