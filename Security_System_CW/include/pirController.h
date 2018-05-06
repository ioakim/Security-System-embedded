/**
  ******************************************************************************
  * @file    pirController.h 
  * @author  Tiberiu Simion Voicu, Ioakim Ioakim
  * @version V1.0.0
  * @date    17 April 2018
  * @brief   This file defines the functions used to control the 
             pir sensor
  ******************************************************************************
  */

#ifndef PIRCONTROLLER_H_   /* Include guard */
#define PIRCONTROLLER_H_

#include "stdint.h"
#include "defines.h"

/**
  * @brief  Initiate Passive Infrared Sensor and interrupt
  * @param  None
  * @retval None
  */
void initPir (void);

#endif // PIRCONTROLLER_H_
