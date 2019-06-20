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
#include <stdio.h>//librería necesaria para la funcion sprintf
#include <stdlib.h>//libreria necesaria para algunas funciones char


#define DO 5
#define RE 10
#define MI 15
#define FA 20
#define SOL 25
#define LA 30
#define SI 35


int contador_nota=0, contador_escala=0;        //variable para lectura del timer
float distancia_nota=0.0, distancia_escala=0.0;        //variable para la conversion a distancia en cm
char imp[9], imp2[9];

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    wave_Start();
    
    Timer_Start();          //Inicialización del timer
    Timer_1_Start();

    for(;;)
    {
        
        while(echo_Read()==0)//condición de espera para implementar la secuencia de inicio
        {
            Trigger_out_Write(1);//activar en 1 lógico la salida al pin trigg y el reinicio del timer
            CyDelay(10u);        //Espera de 10uS para la activación de envío de ráfagas
            Trigger_out_Write(0);//Desactivar el pin trigg generando así el pulso de entrada
            CyDelay(1);          //Espera necesaria para que el módulo envíe la rafaga de ondas ultrasonicas
        }
        while(echo_Read()== 1){}; //Espera entre los dos estados del pin echo, activo y inactivo (El timer funciona en todo este tiempo)
        
        while(echo_1_Read()==0)//condición de espera para implementar la secuencia de inicio
        {
            Trigger_out_1_Write(1);
            CyDelay(10u);        //Espera de 10uS para la activación de envío de ráfagas
            Trigger_out_1_Write(0);
            CyDelay(1);          //Espera necesaria para que el módulo envíe la rafaga de ondas ultrasonicas
        }
        while(echo_1_Read()==1){}; //Espera entre los dos estados del pin echo, activo y inactivo (El timer funciona en todo este tiempo)
        
        
        contador_nota = 65535-Timer_ReadCounter();//Lectura del timer y conversion de descendente a ascendente
        contador_escala = 65535-Timer_1_ReadCounter();
        
        distancia_nota = contador_nota / 58.0 ;        //Conversión directa de microsegundos a distancia en cm
        distancia_escala = contador_escala / 58.0 ;
        
        
        if (distancia_escala >= 10 && distancia_escala < 20)
            escala_Write(1);
        else if (distancia_escala >= 20 && distancia_escala < 30)
            escala_Write(2);
        else if (distancia_escala >= 30 && distancia_escala < 40)
            escala_Write(3);
        else
            escala_Write(0);
        
        if (distancia_nota >= DO && distancia_nota < RE)
            nota_Write(7);
        else if (distancia_nota >= RE && distancia_nota < MI)
            nota_Write(6);
        else if (distancia_nota >= MI && distancia_nota < FA)
            nota_Write(5);
        else if (distancia_nota >= FA && distancia_nota < SOL)
            nota_Write(4);
        else if (distancia_nota >= SOL && distancia_nota < LA)
            nota_Write(3);
        else if (distancia_nota >= LA && distancia_nota < SI)
            nota_Write(2);
        else if (distancia_nota >= SI && distancia_nota < 80)
            nota_Write(1);
        else
            nota_Write(0);

    }
}

/* [] END OF FILE */
