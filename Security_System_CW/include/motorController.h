#ifndef MOTORCONTROLLER_H_   /* Include guard */
#define MOTORCONTROLLER_H_

#include "gpioController.h"
#include "defines.h"

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

void initTIM3(void);
void startMotor(void);
void stopMotor(void);



#endif // MOTORCONTROLLER_H_
