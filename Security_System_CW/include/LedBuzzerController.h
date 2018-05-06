#ifndef LEDBUZZERCONTROLLER_H_   /* Include guard */
#define LEDBUZZERCONTROLLER_H_

#include "stdint.h"
#include "gpioController.h"
#include "defines.h"

/** @defgroup LedBuzzerButton_Controller
* @brief functions to control LEDs, buzzer and button
* @{
*/ 

void initBuzzer (int8_t Dindex);
void initLed (int8_t Dindex);

/**
  * @brief  Initiate buzzer 
  * @param  dIndex
  * @retval None
  */
void initBuzzer (uint8_t dIndex);

/**
  * @brief  Initiate Led 
  * @param  None
  * @retval None
  */
void initLed (uint8_t dIndex);

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


#endif // LEDBUZZERCONTROLLER_H_