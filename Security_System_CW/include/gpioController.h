#ifndef GPIOCONTROLLER_H_   /* Include guard */
#define GPIOCONTROLLER_H_

#include "stdint.h"
#include "stm32f746xx.h"
#include "stm32f7xx_hal.h"


typedef struct _GPIO_PIN {
  GPIO_TypeDef *port;
  uint16_t      pin;
} GPIO_PIN;

 static const GPIO_PIN GPIO_PINS[] = {
	{GPIOC, GPIO_PIN_7},//D0
	{GPIOC, GPIO_PIN_6},//D1
	{GPIOG, GPIO_PIN_6},//D2
	{GPIOB, GPIO_PIN_4},//D3	
	{GPIOG, GPIO_PIN_7},//D4
	{GPIOI, GPIO_PIN_0},//D5
	{GPIOH, GPIO_PIN_6},//D6
	{GPIOI, GPIO_PIN_3},//D7
	{GPIOI, GPIO_PIN_2},//D8
	{GPIOA, GPIO_PIN_15},//D9
	{GPIOA, GPIO_PIN_8},//D10
	{GPIOB, GPIO_PIN_15},//D11
	{GPIOB, GPIO_PIN_14},//D12
	{GPIOI, GPIO_PIN_1},//D13
	{GPIOB, GPIO_PIN_9},//D14
	{GPIOB, GPIO_PIN_8},//D15
};
 
void enableClocksGPIO(void);


GPIO_PIN getPin(uint8_t dIndex);
void initGPIO(int32_t Dindex, uint32_t mode, uint32_t pull, uint32_t speed);
void LED_Initialize (int8_t Dindex);  /* An example function declaration */
void digitalWrite (uint8_t num, int set);
int digitalRead(uint8_t num);
void init_button(int8_t Dindex);

#endif // GPIOCONTROLLER_H_
