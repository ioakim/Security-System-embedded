//this is the Code file for STM-MotionSensor
#include "stm32f4xx.h"
GPIO_InitTypeDef GPIO_InitLed;
EXTI_InitTypeDef EXTI_InitSensor;
NVIC_InitTypeDef NVIC_InitSensor;
void Delay(__IO uint32_t nCount){

	while(nCount --){}
	}
	int main(void)
	{
		  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE);
                  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
	          RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG,ENABLE);
                  GPIO_InitLed.GPIO_Pin =GPIO_Pin_0 |GPIO_Pin_1 ;
		  GPIO_InitLed.GPIO_Mode =GPIO_Mode_OUT;
		  GPIO_InitLed.GPIO_OType =GPIO_OType_PP;
		  GPIO_InitLed.GPIO_PuPd =GPIO_PuPd_NOPULL;
		  GPIO_InitLed.GPIO_Speed =GPIO_Speed_50MHz;
		  GPIO_Init(GPIOD, &GPIO_InitLed);


		  GPIO_InitLed.GPIO_Pin =GPIO_Pin_1;
		  GPIO_InitLed.GPIO_Mode =GPIO_Mode_IN;
		  GPIO_InitLed.GPIO_OType =GPIO_OType_PP;
		  GPIO_InitLed.GPIO_PuPd =GPIO_PuPd_DOWN;
		  GPIO_InitLed.GPIO_Speed =GPIO_Speed_50MHz;
		  GPIO_Init(GPIOD, &GPIO_InitLed);

		  SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource1);

		  EXTI_InitSensor.EXTI_Line = EXTI_Line1;
		  EXTI_InitSensor.EXTI_Line = EXTI_Mode_Interrupt;
		  EXTI_InitSensor.EXTI_Line = EXTI_Trigger_Rising;
		  EXTI_InitSensor.EXTI_LineCmd = ENABLE;
		  EXTI_Init(&EXTI_InitSensor);

		  NVIC_InitSensor.NVIC_IRQChannel =EXTI1_IRQn;
	          NVIC_InitSensor.NVIC_IRQChannelPreemptionPriority = 0;
		  NVIC_InitSensor.NVIC_IRQChannelSubPriority =0;
		  NVIC_InitSensor.NVIC_IRQChannelCmd = ENABLE;
		  NVIC_Init(&NVIC_InitSensor);


		//led1 continuously blink 4ever
		 while (1)
		 {
		GPIO_WriteBit(GPIOD, GPIO_Pin_0, Bit_SET);
		Delay(1680000);

	        GPIO_WriteBit(GPIOD, GPIO_Pin_0, Bit_RESET);
		Delay(1680000);

		 }
	}


	// ISR for external interrupt line 1 ... WHENEVER interrupt 'll occur the led2 'll switch on
	void EXTI_IRQHandler(void)
	{
	    if (EXTI_GetITStatus(EXTI_Line1)!= RESET)
		{
		 GPIO_WriteBit(GPIOD, GPIO_Pin_1, Bit_SET);
		 Delay(3360000);

		GPIO_WriteBit(GPIOD, GPIO_Pin_1, Bit_RESET);
		EXTI_ClearITPendingBit(EXTI_Line1);

		}

        }

