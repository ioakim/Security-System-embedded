#ifndef SDCONTROLLER_H_   /* Include guard */
#define SDCONTROLLER_H_
#include "stm32746g_discovery_sd.h"
#include "defines.h"
#include "stdlib.h"
void initSD();
void deinitSD();
char* readPass();
void writePass(char* passwords);

#endif // SDCONTROLLER_H_
/********************End OF FILE*****************/
