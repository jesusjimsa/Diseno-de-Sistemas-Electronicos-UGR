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
CY_ISR_PROTO(GPIOIsrHandler);

void toggleLed(void){
    LED_Pin_Write(LED_Pin_Read() ^ 1U);
}

void main(){
    
    CyGlobalIntEnable;
    /* Sets up the GPIO interrupt and enables it */
    isr_RelojLed_StartEx(GPIOIsrHandler);

    /* Changes initial priority for the GPIO interrupt */
    isr_RelojLed_SetPriority(3u);
    
   
    
    intep = 0;
    
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
    isr_RelojLed_ClearPending();
    intep = 1;
}


/* [] END OF FILE */
