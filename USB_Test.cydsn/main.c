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
#include <stdio.h>

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    USBUART_Start(0, USBUART_5V_OPERATION);
    while(!USBUART_bGetConfiguration());
    USBUART_CDC_Init();
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    int16 test;
    char StringToPrint[90];
    for(;;)
    {
        test += 1;
        /* Place your application code here. */
        sprintf(StringToPrint, "Result = %d\n", test);
        USBUART_PutString(StringToPrint);
    }
}

/* [] END OF FILE */
