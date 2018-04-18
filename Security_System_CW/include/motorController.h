#ifndef MOTORCONTROLLER_H_   /* Include guard */
#define MOTORCONTROLLER_H_

#include "gpioController.h"
#include "stm32f7xx_hal_tim.h"
#include "stm32f7xx_hal_dac.h"
void initMotor(int8_t Dindex);
void TM_TIMER_Init(void);



#endif // MOTORCONTROLLER_H_
