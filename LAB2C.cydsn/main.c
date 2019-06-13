/*========================================
*Diseño de Sistemas Electrónicos
*LAB2C
*Fernando Martínez Martí( fmartinezmarti@ugr.es)
*========================================
*/

#include "project.h"

void main()
{
 uint8 count;
 LCD_Char_1_Start();
 for (;;)
 {
  LCD_Char_1_ClearDisplay();
  LCD_Char_1_Position(0, 0);
  LCD_Char_1_PrintString("Count:");
  count = Status_Reg_1_Read();
  LCD_Char_1_PrintDecUint16(count);
  CyDelay(100);
 }
}/* [] END OF FILE */