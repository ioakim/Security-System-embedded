#include "stm32f7xx_hal.h"

int32_t PIR_Initialize (void) {
  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOI_CLK_ENABLE();

  /* Configure GPIO pin: PI1 (LD1) */
  GPIO_InitStruct.Pin   = GPIO_PIN_1;
  GPIO_InitStruct.Mode  = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull  = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
  HAL_GPIO_Init(GPIOI, &GPIO_InitStruct);

  return 0;
}
