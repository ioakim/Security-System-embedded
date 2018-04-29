#include "sdController.h"

void initSD() {
	BSP_SD_Init();
}
void deinitSD() {
	BSP_SD_DeInit();
}
void writePass(char* passwords) {
	uint8_t i;
	uint32_t ints [5];
	
	for(i=0; i<sizeof(passwords) / sizeof(char); i++) {
		ints[i] = passwords[i];
	}
	BSP_SD_WriteBlocks(ints, SD_Pointer, 1, 1000);
}
char* readPass() {
	uint32_t i;
	char buffer [5]; 
	char* ptr;
	uint32_t intbuffer [5];
	BSP_SD_ReadBlocks(intbuffer, SD_Pointer, 1, 1000);
	
	for(i=0; i<sizeof(intbuffer) / sizeof(uint32_t); i++) {
		buffer[i] = intbuffer[i] + '0';
	}
	ptr = buffer;
	return ptr;
}