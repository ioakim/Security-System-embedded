#include "LedBuzzerController.h"

void initBuzzer (int8_t Dindex) {
	GPIO_TypeDef *port = GPIO_PINS[Dindex].port;
	uint16_t pin = GPIO_PINS[Dindex].pin;
  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
	// TODO NOT HAVE TO CHANGE GPIOX every time
  __HAL_RCC_GPIOC_CLK_ENABLE();

  /* Configure GPIO pin: PI1 (LD1) */
  GPIO_InitStruct.Pin   = pin;
  GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull  = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
  HAL_GPIO_Init(port, &GPIO_InitStruct);
}
void initLed (int8_t Dindex) {
	GPIO_TypeDef *port = GPIO_PINS[Dindex].port;
	uint16_t pin = GPIO_PINS[Dindex].pin;
  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
	// TODO NOT HAVE TO CHANGE GPIOX every time
  __HAL_RCC_GPIOC_CLK_ENABLE();

  /* Configure GPIO pin: PI1 (LD1) */
  GPIO_InitStruct.Pin   = pin;
  GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull  = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
  HAL_GPIO_Init(port, &GPIO_InitStruct);
}

