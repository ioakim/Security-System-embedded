#include "stdlib.h"
#include "gpioController.h"
#include "pirController.h"
#include "LedBuzzerController.h"
#include "keypadController.h"
#include "tm_stm32f4_keypad.h"
#include "GLCD_Config.h"
#include "Board_GLCD.h"
#include "Board_Touch.h"


void delay(uint32_t nanosec);
static void CPU_CACHE_Enable(void);
int main (void) {
//	int pirStatus = 0;
//	int state = 0;
		int keyVal;
//	initBuzzer(1);
//	initPir(0);
	initLed(0);
	

	TM_KEYPAD_Init(TM_KEYPAD_Type_Large);
	while(1){
		
		keyVal = -1;
//		digitalWrite(1,1);
//		delay(500000);
//		digitalWrite(1,0);
		TM_KEYPAD_Update();
		keyVal = TM_KEYPAD_Read();
		TM_KEYPAD_Update();
		if (keyVal == 0x01) {
			digitalWrite(0,1);
			delay(500000);
			digitalWrite(0,0);
		}
		if(keyVal == -1) {
			int i =0;
			for(i=0; i<100; i++) {
				digitalWrite(0,1);
				delay(10000);
				digitalWrite(0,0);
			}
		}
		
		
		
		
		
//		// buzzer working the one with 2 pins
//		
//		pirStatus = digitalRead(0);
////		//delay(50000);

//		if (pirStatus == 1) {
//			//Motion Started
//			if( state == 0) {
//				digitalWrite(1, 1);		
//				state = 1;
//			}
//		}
//		else {
//			if(state == 1) {
//				// Motion Ended
//				digitalWrite(1,0);
//				state = 0;
//			}
//		}
	}
}
static void SystemClock_Config (void) {
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;

  /* Enable HSE Oscillator and activate PLL with HSE as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSIState = RCC_HSI_OFF;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 400;  
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 8;
  HAL_RCC_OscConfig(&RCC_OscInitStruct);

  /* Activate the OverDrive to reach the 200 MHz Frequency */
  HAL_PWREx_EnableOverDrive();
  
  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;  
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;  
  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_6);
}

static void CPU_CACHE_Enable (void) {

  /* Enable I-Cache */
  SCB_EnableICache();

  /* Enable D-Cache */
  SCB_EnableDCache();
}

void delay(uint32_t nanosec) {
	uint32_t i;
	for(i=0; i<nanosec; i++) {
	}
}

	