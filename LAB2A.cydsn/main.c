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
#include "display.h"

void main()
{
    uint8 contador = 0u;
    
    CharLCD_Start();
    DisplayWelcome();
    DisplayTitle();

    for(;;)
    {
        DisplayCount(contador);
        contador++;
        if(contador>99){
            contador=0;
        }
    }
}

/* [] END OF FILE */
