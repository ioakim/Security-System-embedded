#include "stm32f7xx_hal.h"
#include "stm32746g_discovery_sdram.h"
#include "RTE_Components.h"
#include "GLCD_Config.h"
#include "Board_GLCD.h"
#include "Board_Touch.h"
#include "gpioController.h"

void delay(uint32_t nanosec);
int main (void) {
	LED_Initialize(1);
	init_button(0);

	while(true){
		if(BUTTON_Read(0) == 1) {
			LED_On(1);
		}
		delay(5000);
		

	}
}

void delay(uint32_t nanosec) {
	uint32_t i;
	for(i=0; i<nanosec; i++) {
	}
}

	