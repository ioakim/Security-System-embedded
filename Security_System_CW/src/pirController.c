#include "gpioController.h"
#include "pirController.h"

void PIR_Initialize (uint8_t dIndex) {
	GPIO_PIN gpio_pin = getPin(dIndex);
	GPIO_TypeDef *port = gpio_pin.port;
	uint16_t pin = gpio_pin.pin;
  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
 // __HAL_RCC_GPIOI_CLK_ENABLE();

  /* Configure GPIO pin: PI1 (LD1) */
  GPIO_InitStruct.Pin   = pin;
  GPIO_InitStruct.Mode  = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull  = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
  HAL_GPIO_Init(port, &GPIO_InitStruct);
}

void pool_pir(void) {
	
	
}

