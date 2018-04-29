#ifndef MOTORCONTROLLER_H_   /* Include guard */
#define MOTORCONTROLLER_H_

#include "gpioController.h"
#include "defines.h"
void initMotor(int8_t Dindex);
void initTIM3(void);
void startMotor();
void stopMotor();



#endif // MOTORCONTROLLER_H_
