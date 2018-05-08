/**
  ******************************************************************************
  * @file    LedBuzzerController.h
  * @author  Tiberiu Simion Voicu, Ioakim Ioakim
  * @version V1.0.0
  * @date    17 April 2018
  * @brief   This file provide definitions of the functions used 
						 to control the control the LEDs, buzzer and button
  ******************************************************************************
  */

#ifndef LEDBUZZERCONTROLLER_H_   /* Include guard */
#define LEDBUZZERCONTROLLER_H_

#include "gpioController.h"
#include "defines.h"

/** @defgroup LedBuzzerButton_Controller
* @brief functions to control LEDs, buzzer and button
* @{
*/ 

/** @defgroup LedBuzzerButton_Controller_public_functions
* @brief functions to control LEDs, buzzer and button
* @{
*/ 

/**
  * @brief  Initiate buzzer 
  * @param  dIndex
  * @retval None
  */
void initBuzzer (int8_t Dindex);

/**
  * @brief  Initiate Led 
  * @param  None
  * @retval None
  */
void initLed (int8_t Dindex);

/**
  * @brief  Initiate button and interrupt
  * @param  None
  * @retval None
  */

void initButton(void);

/**
  * @brief  Turn buzzer on
  * @param  None
  * @retval None
  */
void startAlarm(void);

/**
  * @brief  Turn buzzer and Leds Off 
  * @param  None
  * @retval None
  */
void stopAlarm(void);

/**
  * @brief  Turn the 2 Leds on
  * @param  None
  * @retval None
  */
void startLights(void);


/**
* @}
*/

/**
* @}
*/

#endif // LEDBUZZERCONTROLLER_H_
