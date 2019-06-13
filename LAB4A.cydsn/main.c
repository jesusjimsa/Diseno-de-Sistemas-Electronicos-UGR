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
    int32 voltaje;
    
    LCD_Char_Start();
    LCD_Char_Position(0U,0U);
    LCD_Char_ClearDisplay();
    LCD_Char_PrintString("Voltimetro");
    
    ADC_DelSig_Start();
    
    // Comenzamos a convertir la senial analogica a digital
    ADC_DelSig_StartConvert();
    
    
    

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        
        ADC_DelSig_IsEndConversion(ADC_DelSig_WAIT_FOR_RESULT);
        voltaje = ADC_DelSig_CountsTo_mVolts(ADC_DelSig_GetResult32());
        
        LCD_Char_ClearDisplay();
        LCD_Char_Position(0U,0U);
        LCD_Char_PrintString("Medicion: ");
        LCD_Char_Position(1U,0U);
        LCD_Char_PrintNumber(voltaje);
        CyDelay(1000);
        
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
