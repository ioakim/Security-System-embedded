#ifndef GPIOCONTROLLER_H_   /* Include guard */
#define GPIOCONTROLLER_H_

#include "stm32f7xx_hal.h"
#include "stdint.h"

typedef struct _GPIO_PIN {
  GPIO_TypeDef *port;
  uint16_t      pin;
} GPIO_PIN;

GPIO_PIN getPin(uint8_t dIndex);
void LED_Initialize (int8_t Dindex);  /* An example function declaration */
void digitalWrite (uint8_t num, int set);
int digitalRead(uint8_t num);
void init_button(int8_t Dindex);

#endif // GPIOCONTROLLER_H_
