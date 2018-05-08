/**
  ******************************************************************************
  * @file    motorController.h 
  * @author  Tiberiu Simion Voicu, Ioakim Ioakim
  * @version V1.0.0
  * @date    17 April 2018
  * @brief   This file defines the functions used to control the 
             motor
  ******************************************************************************
  */

#ifndef MOTORCONTROLLER_H_   /* Include guard */
#define MOTORCONTROLLER_H_

#include "gpioController.h"
#include "defines.h"

/** @defgroup Motor_Controller
* @brief functions to control the motor
* @{
*/ 

/** @defgroup Motor_Controller_public_functions
* @brief functions to control the motor
* @{
*/ 

/**
  * @brief  Initiate Motor
  * @param  dIndex: index belonging to GPIO Pin on board to be used for controlling the motor
  * @retval None
  */
void initMotor(int8_t dIndex);

/**
  * @brief  Turn on motor to move the door 180 degrees 
  * @param  None
  * @retval None
  */
void moveDoor(void);
/**
* @}
*/

/**
* @}
*/
#endif // MOTORCONTROLLER_H_
