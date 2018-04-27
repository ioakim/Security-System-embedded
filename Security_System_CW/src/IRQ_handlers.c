#include "pirController.c"
#include "IRQ_handlers.h"
void EXTI0_IRQHandler(void) {
    /* Check the interrupt flag is set */
    if (EXTI_GetITStatus(EXTI_Line0) != RESET) {
        startAlarm();
        /* Clear interrupt flag */
        EXTI_ClearITPendingBit(EXTI_Line0);
    }
}