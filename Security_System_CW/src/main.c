#include "stdlib.h"
#include "gpioController.h"
#include "pirController.h"
#include "LedBuzzerController.h"


void delay(uint32_t nanosec);
int main (void) {
	initBuzzer(1);
	initPir(0);

	
	while(1){
		// buzzer working the one with 2 pins
		int pirStatus = -1;
		pirStatus = digitalRead(0);
//		//delay(50000);

		if (pirStatus > 0) {
			digitalWrite(1, 1);
			delay(1000000);
			digitalWrite(1, 0);
			delay(1000000);
		}
//		printf("Pir Status %d", pirStatus);
		//delay(10000000);
//			digitalWrite(1, 1);
//			delay(1000000);
//			digitalWrite(1, 0);
//			delay(1000000);
//		int val = digitalRead(0); 			 // read input value
//		
//		if (val == 1) {            // check if the input is HIGH
//			digitalWrite(1, 1);  // turn LED ON
//			if (pirState == 0) {
//				// we have just turned on
//				//Serial.println("Motion detected!");
//				// We only want to print on the output change, not state
//				pirState = 1;
//			}
//		} else {
//			digitalWrite(1, 0); // turn LED OFF
//			if (pirState == 1){
//				// we have just turned of
//				//Serial.println("Motion ended!");
//				// We only want to print on the output change, not state
//				pirState = 0;
//			}
//		}
	}
}

void delay(uint32_t nanosec) {
	uint32_t i;
	for(i=0; i<nanosec; i++) {
	}
}

	