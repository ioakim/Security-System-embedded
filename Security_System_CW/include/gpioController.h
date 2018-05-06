#ifndef GPIOCONTROLLER_H_   /* Include guard */
#define GPIOCONTROLLER_H_

#include "stm32f746xx.h"
#include "stm32f7xx_hal.h"
#include "stm32f7xx_hal_gpio.h"

/**
  * @brief Typdef struct to include GPIO port and pin 
  * @param GPIO_TypeDef:  GPIO Port
  * @param uint16_t:      GPIO Pin
  * @retval GPIO_PIN
*/
typedef struct _GPIO_PIN {
  GPIO_TypeDef *port;
  uint16_t      pin;
} GPIO_PIN;

extern const GPIO_PIN GPIO_PINS[] = {
	{GPIOC, GPIO_PIN_7},  //D0
	{GPIOC, GPIO_PIN_6},  //D1
	{GPIOG, GPIO_PIN_6},  //D2
	{GPIOB, GPIO_PIN_4},  //D3	
	{GPIOG, GPIO_PIN_7},  //D4
	{GPIOI, GPIO_PIN_0},  //D5
	{GPIOH, GPIO_PIN_6},  //D6
	{GPIOI, GPIO_PIN_3},  //D7
	{GPIOI, GPIO_PIN_2},  //D8
	{GPIOA, GPIO_PIN_15}, //D9
	{GPIOA, GPIO_PIN_8},  //D10
	{GPIOB, GPIO_PIN_15}, //D11
	{GPIOB, GPIO_PIN_14}, //D12
	{GPIOI, GPIO_PIN_1},  //D13
	{GPIOB, GPIO_PIN_9},  //D14
	{GPIOB, GPIO_PIN_8},  //D15
};
/**
  * @brief  Enable GPIO clocks
  * @param  None
  * @retval None
  */
void enableClocksGPIO(void);

// PinNum is just an int representing an index of GPIO_PINS array
// returning the right port and pin for GPIO access as numbered on the board
// Set gpioPin high if it's set in output mode
#define digitalWriteHigh(pinNum)   	((GPIO_PINS[pinNum].port)->BSRR = (uint32_t)((GPIO_PINS[pinNum].pin)))
// Set gpioPin Low if it's set in output mode
#define digitalWriteLow(pinNum)   	((GPIO_PINS[pinNum].port)->BSRR = (uint32_t)((GPIO_PINS[pinNum].pin) << 16))
// Read value of gpio pin 
#define digitalRead1(pinNum)       (((GPIO_PINS[pinNum].port)->IDR & (GPIO_PINS[pinNum].pin)) == 0 ? 0 : 1)

/**
  * @brief  Get gpio pin
  * @param  dIndex: 	index from gpio pins array
  * @retval GPIO_PIN:	the GPIO pin belonging to dIndex number on the board
  */
GPIO_PIN getPin(uint8_t dIndex);
/**
  * @brief  Initiate given GPIO pin based on provided parameters
  *	@note 	Uses hal gpio library
  * @param  dIndex:		index from gpio pins array
  * @param  mode:		mode of GPIO from mode typedef in hal gpio lib
  * @param  pull:		pull of GPIO from pull typedef in hal gpio lib
  * @param  speed:		speed of GPIO from speed typedef in hal gpio lib
  * @param 	alternate:	optional parameter only used if mode is alternate(alternate typdef in gpio lib) 
  * @retval None
  */
extern void initGPIO(uint32_t dIndex, uint32_t mode, uint32_t pull, uint32_t speed, uint32_t alternate);

/**
  * @brief  Set gpio pin 1 or 0 if it's set in output mode
  * @param  dIndex: 	index from gpio pins array
  * @param 	set:		set gpio as either 0 or 1
  * @retval None
  */
extern void digitalWrite (uint8_t dIndex, uint8_t set);

/**
  * @brief  Read the value of a GPIO pin if it's set in input mode
  * @param  dIndex: 	index from gpio pins array
  * @retval uint8_t:	0 or 1 based on value of GPIO pin
  */
extern uint8_t digitalRead(uint8_t dIndex);

/**
  * @brief  To be used for small delays needed in interrupts
  * @brief	hal one is based on clocks which are paused when the context changes
  * @param  micros: 	Approximate time in microsec 
  * @retval None
  */
extern void delayMicro(uint64_t micros);

#endif // GPIOCONTROLLER_H_
