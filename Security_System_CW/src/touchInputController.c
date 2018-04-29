#include "touchInputController.h"

uint16_t box_x = 50; uint16_t box_y = 30;
uint16_t char_x = 15; uint16_t char_y = 15;
uint16_t w = 50; uint16_t h = 50;

// Private Func Declaration
char getPressedKey(uint16_t x, uint16_t y); 
void initGLCD() {
	GLCD_Initialize ();	
	GLCD_SetBackgroundColor (GLCD_COLOR_WHITE);
	GLCD_SetForegroundColor (GLCD_COLOR_BLUE);
	GLCD_SetFont (&GLCD_Font_16x24);
	GLCD_ClearScreen (); 
		
	GLCD_DrawString (100, 100, "Security System Project");
	GLCD_DrawString(100, 130, "Tiberiu Simion Voicu");
	GLCD_DrawString(100, 160, "Ioakim Ioakim");
	//GLCD_ClearScreen();
	
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
}
void getTouch() {
	uint16_t x; uint16_t y;
	TOUCH_STATE  touchState;
	Touch_GetState (&touchState); /* Get touch state */   
  if (touchState.pressed) {
		x = touchState.x;
		y = touchState.y;
	}
	getPressedKey(x,y);
}
char getPressedKey(uint16_t x, uint16_t y) {
	char inputch;
	
	if( (x >= box_x) && (x <= box_x + w) && (y >= box_y) && (y <= box_y + h) ){
		inputch = '1';
	}
	if( (x >= 2*box_x) && (x <= 2*box_x + w) && (y >= box_y) && (y <= box_y + h) ){
		inputch = '2';
	}
	if( (x >= 3*box_x) && (x <= 3*box_x + w) && (y >= box_y) && (y <= box_y + h) ){
		inputch = '3';
	}	
	if( (x >= box_x) && (x <= box_x + w) && (y >= box_y + h) && (y <= box_y + (2*h)) ){
		inputch = '4';
	}
	if( (x >= 2*box_x) && (x <= 2*box_x + w) && (y >= box_y + h) && (y <= box_y + (2*h)) ){
		inputch = '5';
	}
	if( (x >= 3*box_x) && (x <= 3*box_x + w) && (y >= box_y + h) && (y <= box_y + (2*h)) ){
		inputch = '6';
	}	
	if( (x >= box_x) && (x <= box_x + w) && (y >= box_y + (2*h) ) && (y <= box_y + (3*h)) ){
		inputch = '7';
	}
	if( (x >= 2*box_x) && (x <= 2*box_x + w) && (y >= box_y + (2*h)) && (y <= box_y + (3*h)) ){
		inputch = '8';
	}
	if( (x >= 3*box_x) && (x <= 3*box_x + w) && (y >= box_y + (2*h)) && (y <= box_y + (3*h)) ){
		inputch = '9';
	}	
	if( (x >= box_x) && (x <= box_x + w) && (y >= box_y + (3*h) ) && (y <= box_y + (4*h)) ){
		inputch = 'C';
	}
	if( (x >= 2*box_x) && (x <= 2*box_x + w) && (y >= box_y + (3*h)) && (y <= box_y + (4*h)) ){
		inputch = '0';
	}
	if( (x >= 3*box_x) && (x <= 3*box_x + w) && (y >= box_y + (3*h)) && (y <= box_y + (4*h)) ){
		inputch = 'A';
	}	
	
	return inputch;	
}
