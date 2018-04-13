#ifndef GPIOCONTROLLER_H_   /* Include guard */
#define GPIOCONTROLLER_H_

#include "stm32f7xx_hal.h"
#include "stm32f746xx.h"
#include "stdint.h"

typedef struct _GPIO_PIN {
  GPIO_TypeDef *port;
  uint16_t      pin;
} GPIO_PIN;

static const GPIO_PIN GPIO_PINS[] = {
	{GPIOC, GPIO_PIN_7}, 	//D0
	{GPIOC, GPIO_PIN_6},		//D1
	{GPIOG, GPIO_PIN_6},		//D2
	{GPIOB, GPIO_PIN_4},		//D3	
	{GPIOG, GPIO_PIN_7}		//D4
};


GPIO_PIN getPin(uint8_t dIndex);
void LED_Initialize (int8_t Dindex);  /* An example function declaration */
void digitalWrite (uint8_t num, int set);
int digitalRead(uint8_t num);
void init_button(int8_t Dindex);

#endif // GPIOCONTROLLER_H_
