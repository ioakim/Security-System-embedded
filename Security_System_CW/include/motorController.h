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
void initMotor(int8_t Dindex);
void moveDoor();
void initTIM3(void);
void startMotor();
void stopMotor();



#endif // MOTORCONTROLLER_H_
