
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
    
    SPIS_Start();

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    uint8_t d = 0x01;
    for(;;)
    {
        /* Place your application code here. */
        SPIS_ClearTxBuffer();
        SPIS_ClearRxBuffer();
        
       uint8 status = SPIS_ReadTxStatus();
    
    
        if(status & (SPIS_STS_SPI_DONE)) {
            SPIS_WriteTxData(0x44);
        }
        
        while(!(SPIS_ReadTxStatus() & SPIS_STS_SPI_DONE)){};
        
      
        
        //CyDelay(500);
    }
}

/* [] END OF FILE */
