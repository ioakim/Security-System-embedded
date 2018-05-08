/**
  ******************************************************************************
  * @file    motorController.c
  * @author  Tiberiu Simion Voicu, Ioakim Ioakim
  * @version V1.0.0
  * @date    17 April 2018
  * @brief   This file provides implementation of the functions 
              used to control the motor
  ******************************************************************************
  */

#include "motorController.h"

void initMotor(int8_t Dindex) {
	initGPIO(Dindex, GPIO_MODE_OUTPUT_PP, GPIO_PULLDOWN, GPIO_SPEED_HIGH, 0);
}
void moveDoor() {
	digitalWrite(motor_GPIO_Num, 1);
	delayMicro(100000000 / 8 );
	digitalWrite(motor_GPIO_Num, 0);
}
