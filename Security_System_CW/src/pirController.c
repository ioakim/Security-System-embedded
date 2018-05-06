/**
  ******************************************************************************
  * @file    pirController.h 
  * @author  Tiberiu Simion Voicu, Ioakim Ioakim
  * @version V1.0.0
  * @date    17 April 2018
  * @brief   This file provides implementation of the functions 
  			 used to control the pir sensor
  ******************************************************************************
  */

#include "gpioController.h"
#include "pirController.h"
#include "touchInputController.h"
#include "LedBuzzerController.h"

/** @defgroup PIR_Controller
* @brief functions to control the PIR sensor
* @{
*/ 

/**
* @}
*/

uint8_t flagButton = 0 ;
/*
		Inititate Passive Infrared Sensor
*/
void initPir () {
	initGPIO(pir_GPIO_Num, GPIO_MODE_IT_RISING, GPIO_NOPULL, GPIO_SPEED_HIGH, 0);
	HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(EXTI0_IRQn);
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
 

