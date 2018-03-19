#include "stdlib.h"
#include "gpioController.h"
#include "pirController.h"


void delay(uint32_t nanosec);
int main (void) {
	int pirState;
	pirState = 0;
	
	PIR_Initialize(0);
	LED_Initialize(1);
	while(1){
		// buzzer working the one with 2 pins
		digitalWrite(1, 1);
		delay(10000);
		digitalWrite(1, 0);
		delay(2000000);
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

	