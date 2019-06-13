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

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    SenCua_Start();
    TriSie_Start();
    AMux_Start();
    //Opamp_Start();
    PGA_Start();
    uint8 ant = 0;

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        if(Pin_2_Read()){
            ant = ant ^ 1;
            while(Pin_2_Read());
        }
        
        AMux_Select(ant);
        
    }
}

/* [] END OF FILE */
