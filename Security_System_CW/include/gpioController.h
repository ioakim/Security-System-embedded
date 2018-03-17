#ifndef GPIOCONTROLLER_H_   /* Include guard */
#define GPIOCONTROLLER_H_

#include "stm32f7xx_hal.h"

typedef struct _GPIO_PIN {
  GPIO_TypeDef *port;
  uint16_t      pin;
} GPIO_PIN;

void LED_Initialize (int8_t Dindex);  /* An example function declaration */
void LED_On (uint8_t num);
void LED_Off (uint8_t num);
int BUTTON_Read(uint8_t num);
void init_button(int8_t Dindex);
#endif // GPIOCONTROLLER_H_
