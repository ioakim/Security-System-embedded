#include "gpioController.h"
#include "pirController.h"

void initPir () {
	initGPIO(pir_GPIO_Num, GPIO_MODE_IT_RISING, GPIO_NOPULL, GPIO_SPEED_HIGH, 0);
	HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(EXTI0_IRQn);
}
 

	 
 

