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
    
    SS_SetDriveMode(SS_DM_RES_UP);
    SPIM_Start();

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        /* Place your application code here. */
        SPIM_ClearTxBuffer();
        SPIM_ClearRxBuffer();
        
       uint8 status = SPIM_ReadTxStatus();
    
        if(status & (SPIM_STS_SPI_DONE | SPIM_STS_SPI_IDLE)) {
            SPIM_WriteTxData(0x00);
        }
        
        //while(!(SPIM_ReadTxStatus() & (SPIM_STS_SPI_DONE))){};
        
        uint8 data = SPIM_ReadRxData();
        if(SPIM_ReadRxData() == data) {
            TestPin_Write(1);   
        }
        
    }
}

/* [] END OF FILE */
