#include "motorController.h"

void initMotor(int8_t Dindex) {
//	GPIO_TypeDef *port = GPIO_PINS[Dindex].port;
//	uint16_t pin = GPIO_PINS[Dindex].pin;
//  GPIO_InitTypeDef GPIO_InitStruct;

//  /* GPIO Ports Clock Enable */
//	// TODO NOT HAVE TO CHANGE GPIOX every time
//  __HAL_RCC_GPIOC_CLK_ENABLE();
//	__TIM_CLK_ENABLE();
//  

//  /* Configure GPIO pin: PI1 (LD1) */
//  GPIO_InitStruct.Pin   = pin;
//  GPIO_InitStruct.Mode  = GPIO_MODE_AF_PP;
//  GPIO_InitStruct.Pull  = GPIO_NOPULL;
//  GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
//	GPIO_InitStruct.Alternate = GPIO_AF1_TIM1;
//  HAL_GPIO_Init(port, &GPIO_InitStruct);
//}
//void TM_TIMER_Init(void) {
//	TIM_TimeBaseInitTypeDef TIM_BaseStruct;
//	
//	/* Enable clock for TIM4 */
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
///*	
//	TIM4 is connected to APB1 bus, which has on F407 device 42MHz clock 				
//	But, timer has internal PLL, which double this frequency for timer, up to 84MHz 	
//	Remember: Not each timer is connected to APB1, there are also timers connected 	
//	on APB2, which works at 84MHz by default, and internal PLL increase 				
//	this to up to 168MHz 															
//	
//	Set timer prescaller 
//	Timer count frequency is set with 
//	
//	timer_tick_frequency = Timer_default_frequency / (prescaller_set + 1)		
//	
//	In our case, we want a max frequency for timer, so we set prescaller to 0 		
//	And our timer will have tick frequency		
//	
//	timer_tick_frequency = 84000000 / (0 + 1) = 84000000 
//*/	
//	TIM_BaseStruct.TIM_Prescaler = 0;
//	/* Count up */
//    TIM_BaseStruct.TIM_CounterMode = TIM_CounterMode_Up;
///*
//	Set timer period when it have reset
//	First you have to know max value for timer
//	In our case it is 16bit = 65535
//	To get your frequency for PWM, equation is simple
//	
//	PWM_frequency = timer_tick_frequency / (TIM_Period + 1)
//	
//	If you know your PWM frequency you want to have timer period set correct
//	
//	TIM_Period = timer_tick_frequency / PWM_frequency - 1
//	
//	In our case, for 10Khz PWM_frequency, set Period to
//	
//	TIM_Period = 84000000 / 10000 - 1 = 8399
//	
//	If you get TIM_Period larger than max timer value (in our case 65535),
//	you have to choose larger prescaler and slow down timer tick frequency
//*/
//    TIM_BaseStruct.TIM_Period = 8399; /* 10kHz PWM */
//    TIM_BaseStruct.TIM_ClockDivision = TIM_CKD_DIV1;
//    TIM_BaseStruct.TIM_RepetitionCounter = 0;
//	/* Initialize TIM4 */
//    TIM_TimeBaseInit(TIM4, &TIM_BaseStruct);
//	/* Start count on TIM4 */
//    TIM_Cmd(TIM4, ENABLE);
}