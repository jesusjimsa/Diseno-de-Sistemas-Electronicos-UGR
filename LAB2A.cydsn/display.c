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

void DisplayWelcome(void) {
    CharLCD_ClearDisplay();
    CharLCD_Position(0U, 0U);
    CharLCD_PrintString("Psoc Mola!");
}

void DisplayTitle(void){
    CharLCD_Position(1U, 0U);
    CharLCD_PrintString("Contador:");
}

void DisplayCount(uint8 count){
    CharLCD_Position(1U, 12U);
    CharLCD_PrintNumber((uint16)count);
    CharLCD_PrintString(" ");
}
    
/* [] END OF FILE */
