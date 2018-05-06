/**
  ******************************************************************************
  * @file    LedBuzzerController.h 
  * @author  Tiberiu Simion Voicu, Ioakim Ioakim
  * @version V1.0.0
  * @date    17 April 2018
  * @brief   This file defines the functions used to control the 
             control the LEDs, buzzer and button
  ******************************************************************************
  */

#ifndef 	LEDBUZZERCONTROLLER_H_   /* Include guard */
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
void initButton(void);
void startAlarm(void);
void stopAlarm(void);
void startLights(void);


/**
* @}
*/


#endif // LEDBUZZERCONTROLLER_H_