#include "stm32f7xx_hal.h"
#include "stm32746g_discovery_sdram.h"
#include "RTE_Components.h"

#include "defines.h"
#include "stdlib.h"
#include "stdio.h"
#include "gpioController.h"
#include "pirController.h"
#include "LedBuzzerController.h"
#include "keypadController.h"
#include "tm_stm32f4_keypad.h"
#include "tm_stm32f4_mfrc522.h"
#include "GLCD_Config.h"
#include "Board_GLCD.h"
#include "Board_Touch.h"

extern GLCD_FONT     GLCD_Font_16x24;

void delay(uint32_t nanosec);
static void SystemClock_Config(void);
static void CPU_CACHE_Enable(void);

#ifdef RTE_CMSIS_RTOS_RTX
extern uint32_t os_time;

uint32_t HAL_GetTick(void) { 
  return os_time; 
}
#endif

int main (void) {
	uint8_t CardID[5];
	char buffer[50];
	
	CPU_CACHE_Enable();                     /* Enable the CPU Cache           */
	HAL_Init();                               /* Initialize the HAL Library     */
	BSP_SDRAM_Init();                         /* Initialize BSP SDRAM           */
	SystemClock_Config(); 					/* Configure the System Clock     */
	enableClocksGPIO();
	
	GLCD_Initialize ();	
	GLCD_SetBackgroundColor (GLCD_COLOR_WHITE);
	GLCD_ClearScreen (); 
	GLCD_SetForegroundColor (GLCD_COLOR_BLUE);
	GLCD_SetFont (&GLCD_Font_16x24);
	GLCD_ClearScreen (); 
		
	//TM_KEYPAD_Init(TM_KEYPAD_Type_Large);
	GLCD_DrawString ( 100, 100, "marat");
	TM_MFRC522_Init();
	while(1){
		TM_MFRC522_Check(CardID);
		sprintf(buffer, "0x%02x\n0x%02x\n0x%02x\n0x%02x\n0x%02x", CardID[0], CardID[1], CardID[2], CardID[3], CardID[4]);
		 if (TM_MFRC522_Check(CardID) == MI_OK) {
            //CardID is valid
			 GLCD_DrawString(150, 150, "Card Detected");
			 sprintf(buffer, "0x%02x\n0x%02x\n0x%02x\n0x%02x\n0x%02x", CardID[0], CardID[1], CardID[2], CardID[3], CardID[4]);
			 GLCD_DrawString(300,150, buffer);
		 }


//			else if (keyVal == TM_KEYPAD_Button_2) {
//				GLCD_DrawString ( 200, 180, "2");
//				GLCD_ClearScreen();
//				//digitalWrite(0,1);
//				delay(50000);
//      }
		
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
//  GPIO_MODE_AF_PP OR GPIO_MODE_AF_OD
void TM_SPI_InitCustomPinsCallback(SPI_TypeDef* SPIx, uint16_t AlternateFunction) {
	/* SPI callback */
	if (SPIx == SPI2) {
		/* Pins on STM32F7-Discovery on Arduino header */

		initGPIO(11, GPIO_MODE_AF_OD, GPIO_NOPULL, GPIO_SPEED_HIGH);//MOSI
		initGPIO(12, GPIO_MODE_AF_OD, GPIO_NOPULL, GPIO_SPEED_HIGH);//MISO
		initGPIO(13, GPIO_MODE_AF_OD, GPIO_NOPULL, GPIO_SPEED_HIGH);//SCK
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

	