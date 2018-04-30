#ifndef 	LEDBUZZERCONTROLLER_H_   /* Include guard */
#define LEDBUZZERCONTROLLER_H_

#include "stdint.h"
#include "gpioController.h"
#include "defines.h"

void initBuzzer (int8_t Dindex);
void initLed (int8_t Dindex);
void initButton(void);
void startAlarm(void);
void stopAlarm(void);
void startLights(void);


#endif // LEDBUZZERCONTROLLER_H_