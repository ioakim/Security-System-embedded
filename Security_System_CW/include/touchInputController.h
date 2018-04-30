#ifndef TOUCHINPUTCONTROLLER_H_   /* Include guard */
#define TOUCHINPUTCONTROLLER_H_
#include "GLCD_Config.h"
#include "Board_GLCD.h"
#include "Board_Touch.h"
#include "pirController.h"
#include "gpioController.h"
#include "LedBuzzerController.h"
#include "stm32746g_discovery_ts.h"

extern GLCD_FONT     GLCD_Font_16x24;
#define pass1 				"1234"

void initGLCD(void);
void drawKeypad(void);
char getTouch(void);
void addKey(char key);
#endif // TOUCHINPUTCONTROLLER_H_
