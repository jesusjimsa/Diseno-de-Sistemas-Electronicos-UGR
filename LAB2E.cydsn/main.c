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
    LCD_Char_Start();
    
    CyDelay(1000);
    LCD_Char_PrintString("Juguemos");
    
    CyDelay(1000);
    LCD_Char_ClearDisplay();
    char personajes[4] = {'G', 'M', 'P', 'Z'};
    

    for(;;){
        switch(Status_Reg_Read()){
            case 0:
                LCD_Char_ClearDisplay();
                LCD_Char_Position(0U,0U);
                LCD_Char_PrintString("Perdedor");
                CyDelay(1000);
                Control_Reg_Write(0);
            break;
                
            case 2:
                LCD_Char_ClearDisplay();
                LCD_Char_Position(0U,0U);
                LCD_Char_PrintString("Ganador");
                CyDelay(1000);
                Control_Reg_Write(0);
            break;
                
            case 1:
                LCD_Char_ClearDisplay();
                LCD_Char_Position(0U,0U);
                for (int i = 0; i < 4; i++){
                    if(!(Control_Reg_Read() & 1<<i)){
                        LCD_Char_PutChar(personajes[i]);
                        LCD_Char_PrintString(" ");
                    }
                    else
                        LCD_Char_PrintString("  ");
                }
                LCD_Char_Position(1U,0U);
                for (int i = 0; i < 4; i++){
                    if(Control_Reg_Read() & 1<<i){
                        LCD_Char_PutChar(personajes[i]);
                        LCD_Char_PrintString(" ");
                    }
                    else
                        LCD_Char_PrintString("  ");
                }
                
                if (!Granjero_Read()){
                    Control_Reg_Write(Control_Reg_Read() ^ 1);
                    while(!Granjero_Read());
                }
                if (!Maiz_Read()){
                    Control_Reg_Write(Control_Reg_Read() ^ 3);
                    while(!Maiz_Read());
                }
                if (!Pollo_Read()){
                    Control_Reg_Write(Control_Reg_Read() ^ 5);
                    while(!Pollo_Read());
                }
                if (!Zorro_Read()){
                    Control_Reg_Write(Control_Reg_Read() ^ 9);
                    while(!Zorro_Read());
                }
            break;
        }
    }
}

/* [] END OF FILE */
