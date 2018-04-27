#include "gpioController.h"
#include "pirController.h"

void initPir () {
  GPIO_InitTypeDef GPIO_InitStruct;
  EXTI_InitTypeDef EXTI_InitStruct;
  NVIC_InitTypeDef NVIC_InitStruct;

  GPIO_PIN gpio_pin = getPin(pir_GPIO_Num);
  GPIO_TypeDef *port = gpio_pin.port;
	uint16_t pin = gpio_pin.pin;

  // Enable SYSCFG clock
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

  /* Configure GPIO pin: PC7 (D0) */
  GPIO_InitStruct.Pin   = pin;
  GPIO_InitStruct.Mode  = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull  = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
  HAL_GPIO_Init(port, &GPIO_InitStruct);

  SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC, EXTI_PinSource7);
    
  /* PC7 is connected to EXTI_Line7 */
  EXTI_InitStruct.EXTI_Line = EXTI_Line7;
  /* Enable interrupt */
  EXTI_InitStruct.EXTI_LineCmd = ENABLE;
  /* Interrupt mode */
  EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
  /* Triggers on rising and falling edge */
  EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
  /* Add to EXTI */
  EXTI_Init(&EXTI_InitStruct);

  /* Add IRQ vector to NVIC */
  /* PC7 is connected to EXTI_Line7, which has EXTI7_IRQn vector */
  NVIC_InitStruct.NVIC_IRQChannel = EXTI7_IRQn;
  /* Set priority */
  NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0x00;
  /* Set sub priority */
  NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0x00;
  /* Enable interrupt */
  NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
  /* Add to NVIC */
  NVIC_Init(&NVIC_InitStruct);

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
void stopAlarm()
  digitalWriteLow(led1_GPIO_Num)
  digitalWriteLow(led2_GPIO_Num)
/*
    Handle PIR sensor interrupt
*/
void EXTI7_IRQHandler(void) {
    /* Check the interrupt flag is set */
    if (EXTI_GetITStatus(EXTI_Line0) != RESET) {
        startAlarm();
        // Clear interrupt flag 
        EXTI_ClearITPendingBit(EXTI_Line0);
        // Exit
    }
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

