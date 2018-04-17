#include "stdlib.h"
#include "gpioController.h"
#include "pirController.h"
#include "LedBuzzerController.h"


void delay(uint32_t nanosec);
int main (void) {
	int pirStatus = 0;
	int state = 0;
	initBuzzer(1);
	initPir(0);
	
	while(1){
		digitalWrite(1,1);
		delay(500000);
		digitalWrite(1,0);
		
		
		
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

void delay(uint32_t nanosec) {
	uint32_t i;
	for(i=0; i<nanosec; i++) {
	}
}

	