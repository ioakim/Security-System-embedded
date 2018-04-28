#include "gpioController.h"
#include "pirController.h"

void initPir () {
  GPIO_InitTypeDef GPIO_InitStruct;

  GPIO_PIN gpio_pin = getPin(pir_GPIO_Num);
  GPIO_TypeDef *port = gpio_pin.port;
	uint16_t pin = gpio_pin.pin;

  /* Configure GPIO pin: PC7 (D0) */
  GPIO_InitStruct.Pin   = pin;
  GPIO_InitStruct.Mode  = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull  = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
  HAL_GPIO_Init(port, &GPIO_InitStruct);

}

void pool_pir(void) {
	
	
}
void startAlarm(void);
void stopAlarm(void);
void startAlarm() {
  // if not initiated led then initiate
  digitalWriteHigh(led1_GPIO_Num);
  digitalWriteHigh(led2_GPIO_Num);
}
void stopAlarm() {
  digitalWriteLow(led1_GPIO_Num);
  digitalWriteLow(led2_GPIO_Num);
}
/*
    Handle PIR sensor interrupt
*/
void EXTI7_IRQHandler(void) {
    /* Check the interrupt flag is set */
}
// Same pin line handler
// void EXTI9_5_IRQHandler(void) {
//     uint32_t pending = EXTI->PR1;
//     if(pending & (1 << 5)) {
//         EXTI->PR1 = 1 << 5; // clear pending flag, otherwise we'd get endless interrupts
//         // handle pin 5 here
//     }
//     if(pending & (1 << 6)) {
//         EXTI->PR1 = 1 << 6;
//         // handle pin 6 here
//     }
// }

