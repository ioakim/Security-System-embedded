/**
  ******************************************************************************
  * @file    touchInputController.h 
  * @author  Tiberiu Simion Voicu, Ioakim Ioakim
  * @version V1.0.0
  * @date    17 April 2018
  * @brief   This file provides implementation of the functions 
  			 used to control the touchscreen and keypad
  ******************************************************************************
  */

#include "touchInputController.h"
#include "motorController.h"



uint16_t box_x = 50; uint16_t box_y = 30;
uint16_t char_x = 15; uint16_t char_y = 15;
uint16_t w = 50; uint16_t h = 50;
char passInput [5];
int inputLen=  0;


/**
  * @brief  Provide x and y coordinate on 
  *	@brief 	touchscreen in order to get pressed key
  * @param  x: 		x coordinate on GLCD
  * @param 	y:		y coordinate on GLCD
  * @retval char:	the symbol which was pressed on the touchscreen
  */
char getPressedKey(uint16_t x, uint16_t y);

/**
  * @brief  Handles inserting wrong password and starts alarm
  * @param  None
  * @retval None
  */
void wrongPass(void);

/**
  * @brief  Handles inserting right password and stops alarm
  * @param  None
  * @retval None
  */
void rightPass(void);

/**
  * @brief  Resets the input password string
  * @param  None
  * @retval None
  */
void clearInput();

void initGLCD() {
	GLCD_Initialize ();
	Touch_Initialize();	
	GLCD_SetBackgroundColor (GLCD_COLOR_WHITE);
	GLCD_SetForegroundColor (GLCD_COLOR_BLUE);
	GLCD_SetFont (&GLCD_Font_16x24);
	GLCD_ClearScreen (); 
		
	GLCD_DrawString (100, 100, "Security System Project");
	GLCD_DrawString(100, 130, "Tiberiu Simion Voicu");
	GLCD_DrawString(100, 160, "Ioakim Ioakim");
}
void drawKeypad(void) {
	
	GLCD_ClearScreen();
	GLCD_DrawRectangle(box_x, box_y, w, h);
	GLCD_DrawChar(box_x + char_x, box_y + char_y, '1');
	
	GLCD_DrawRectangle(2*box_x,box_y, w, h);
	GLCD_DrawChar(((2*box_x) + char_x), box_y + char_y, '2');
	
	GLCD_DrawRectangle(3*box_x,box_y, w, h);
	GLCD_DrawChar(((3*box_x) + char_x), box_y + char_y, '3');
	
	GLCD_DrawRectangle(box_x,box_y+h , w, h);
	GLCD_DrawChar(box_x + char_x, box_y + h + char_y, '4');
	
	GLCD_DrawRectangle(2*box_x,box_y+h, w, h);
	GLCD_DrawChar(((2*box_x) + char_x), box_y + h + char_y, '5');
	
	GLCD_DrawRectangle(3*box_x,box_y+h, w, h);
	GLCD_DrawChar(((3*box_x) + char_x), box_y + h + char_y, '6');
	
	GLCD_DrawRectangle(box_x,box_y + (2*h) , w, h);
	GLCD_DrawChar(box_x + char_x, box_y + (2*h) + char_y, '7');
	
	GLCD_DrawRectangle(2*box_x,box_y + (2*h) , w, h);
	GLCD_DrawChar((2*box_x) + char_x,  box_y + (2*h) + char_y, '8');
	
	GLCD_DrawRectangle(3*box_x,box_y + (2*h) , w, h);
	GLCD_DrawChar((3*box_x) + char_x,  box_y + (2*h) + char_y, '9');
	
	GLCD_DrawRectangle(box_x,box_y + (3*h) , w, h);
	GLCD_DrawChar(box_x + char_x, box_y + (3*h) + char_y, 'C');
	
	GLCD_DrawRectangle(2*box_x,box_y + (3*h) , w, h);
	GLCD_DrawChar((2*box_x) + char_x,  box_y + (3*h) + char_y, '0');
	
	GLCD_DrawRectangle(3*box_x,box_y + (3*h) , w, h);
	GLCD_DrawChar((3*box_x) + char_x,  box_y + (3*h) + char_y, 'A');
	
	GLCD_DrawRectangle(250, 100, 200, 50);
	GLCD_DrawString(250, 50, "Input Password");
	BSP_TS_ITConfig();
}
char getTouch() {
	uint16_t x; uint16_t y;
	TOUCH_STATE  touchState;
	Touch_GetState (&touchState); /* Get touch state */  
  if (touchState.pressed) {
		x = touchState.x;
		y = touchState.y;
	}
	return getPressedKey(x,y);
}
char getPressedKey(uint16_t x, uint16_t y) {
	char inputch;
	
	if( (x >= box_x) && (x <= box_x + w) && (y >= box_y) && (y <= box_y + h) ){
		inputch = '1';
	}
	else if( (x >= 2*box_x) && (x <= 2*box_x + w) && (y >= box_y) && (y <= box_y + h) ){
		inputch = '2';
	}
	else if( (x >= 3*box_x) && (x <= 3*box_x + w) && (y >= box_y) && (y <= box_y + h) ){
		inputch = '3';
	}	
	else if( (x >= box_x) && (x <= box_x + w) && (y >= box_y + h) && (y <= box_y + (2*h)) ){
		inputch = '4';
	}
	else if( (x >= 2*box_x) && (x <= 2*box_x + w) && (y >= box_y + h) && (y <= box_y + (2*h)) ){
		inputch = '5';
	}
	else if( (x >= 3*box_x) && (x <= 3*box_x + w) && (y >= box_y + h) && (y <= box_y + (2*h)) ){
		inputch = '6';
	}	
	else if( (x >= box_x) && (x <= box_x + w) && (y >= box_y + (2*h) ) && (y <= box_y + (3*h)) ){
		inputch = '7';
	}
	else if( (x >= 2*box_x) && (x <= 2*box_x + w) && (y >= box_y + (2*h)) && (y <= box_y + (3*h)) ){
		inputch = '8';
	}
	else if ( (x >= 3*box_x) && (x <= 3*box_x + w) && (y >= box_y + (2*h)) && (y <= box_y + (3*h)) ){
		inputch = '9';
	}	
	else if( (x >= box_x) && (x <= box_x + w) && (y >= box_y + (3*h) ) && (y <= box_y + (4*h)) ){
		inputch = 'C';
	}
	else if( (x >= 2*box_x) && (x <= 2*box_x + w) && (y >= box_y + (3*h)) && (y <= box_y + (4*h)) ){
		inputch = '0';
	}
	else if( (x >= 3*box_x) && (x <= 3*box_x + w) && (y >= box_y + (3*h)) && (y <= box_y + (4*h)) ){
		inputch = 'A';
	}	
	else 
		return 0;
	
	return inputch;	
}
void addKey(char key) {
	int i=0;
	if(key == 'C') {
		GLCD_ClearScreen();
		drawKeypad();
		clearInput();
	}
	else if(key == 'A') {
		if( inputLen != 4) {
			wrongPass();
		}
		else {		
			for(i=0; i<4; i++) {
				if(passInput[i] != pass1[i])
					wrongPass();
			}
			rightPass();
		}
	}
	else if( key != 0 && key != 'A') {
		drawKeypad();
		passInput[inputLen] = key;
		inputLen ++;
		if(inputLen > 4) 
			wrongPass();
		GLCD_DrawString(265, 115, passInput);	
	}
	
}
void wrongPass() {
	GLCD_ClearScreen();
	GLCD_DrawString(100, 150, "Wrong Password");
	startAlarm();
	delayMicro(300000000); // 3 sec delay for displaying wrong pass
	GLCD_ClearScreen();
	drawKeypad();
	clearInput();
}
void rightPass() {
	GLCD_ClearScreen();
	GLCD_DrawString(100, 150, "Correct Password");
	stopAlarm();
	moveDoor();
	
}
void clearInput() {
	uint8_t i = 0;
	for(i=0; i<4; i++) 
		passInput[i] = ' ';
	inputLen = 0;
}