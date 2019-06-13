/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"



uint8 intep;
uint8 divisor;
CY_ISR_PROTO(GPIOIsrHandler);

void toggleLed(void){
    ledSoftwareInterrupcionPWM_Write(ledSoftwareInterrupcionPWM_Read() ^ 1U);
}

int main(void)
{
    
    
    /* Sets up the GPIO interrupt and enables it */
    isr_GPIO_StartEx(GPIOIsrHandler);

    /* Changes initial priority for the GPIO interrupt */
    isr_GPIO_SetPriority(3u);
    CyGlobalIntEnable; /* Enable global interrupts. */
    PWM_Start();
   
    intep = 0;
    divisor = 0;
    for(;;){
        if(intep == 1){
            toggleLed();
            intep = 0;
        }
    }
}

CY_ISR(GPIOIsrHandler)
{
    /* Clear pending Interrupt */
    isr_GPIO_ClearPending();
    PWM_ReadStatusRegister();
    if(!botoncito_Read())
        intep = 1;
    else{
        divisor = divisor ^ 1U;
        if (divisor == 0)
            intep = 1;
    }
}




/* [] END OF FILE */