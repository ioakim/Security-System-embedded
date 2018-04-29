#ifndef TOUCHINPUTCONTROLLER_H_   /* Include guard */
#define TOUCHINPUTCONTROLLER_H_
#include "GLCD_Config.h"
#include "Board_GLCD.h"
#include "Board_Touch.h"

extern GLCD_FONT     GLCD_Font_16x24;

void initGLCD();
void drawKeypad();
void getTouch();
#endif // TOUCHINPUTCONTROLLER_H_
