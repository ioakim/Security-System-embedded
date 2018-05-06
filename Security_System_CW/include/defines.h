/**
  ******************************************************************************
  * @file    defines.h 
  * @author  Tiberiu Simion Voicu, Ioakim Ioakim
  * @version V1.0.0
  * @date    27 April 2018
  * @brief   This file contains definitions of variables used throughout the project
  ******************************************************************************
  */


#ifndef MFRC522_SPI

#define MFRC522_SPI         		SPI2
#define MFRC522_SPI_PINSPACK		TM_SPI_PinsPack_4
#define MFRC522_CS_RCC				RCC_AHB1Periph_GPIOB
#define MFRC522_CS_PORT				GPIOB
#define MFRC522_CS_PIN				GPIO_Pin_8
#define MFRC522_Num					15
#endif
//#define GPIO_AFx_SPI2               0x05

#define pir_GPIO_Num                5  
#define buzzer_GPIO_Num							0
#define led1_GPIO_Num               1
#define led2_GPIO_Num               2
#define motor_GPIO_Num							4
#define button_GPIO_Num							3
#define SD_Pointer									100000
   
#define TS_MULTI_TOUCH_SUPPORTED		0
