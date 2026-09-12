#include "i2c_driver.h"

static void I2C_GenerateStartCondition(I2C_RegDef_t *pI2Cx);
static void I2C_GenerateStopCondition(I2C_RegDef_t *pI2Cx);
static void I2C_ConfigureSlaveConnection(I2C_Handle_t *pI2Cx, uint8_t write);

void I2C_PeriClockControl(I2C_RegDef_t *pI2Cx, uint8_t EnorDi)
{
    switch(EnorDi){
        case ENABLE:{
            if (pI2Cx == I2C1){
                I2C1_PCLK_EN();
            } else if(pI2Cx == I2C2){
                I2C2_PCLK_EN();
            }
            break;
        }
        case DISABLE:{
            if (pI2Cx == I2C1){
                I2C1_PCLK_DI();
            } else if(pI2Cx == I2C2){
                I2C2_PCLK_DI();
            }
            break;
        }
    }
}

void I2C_Init(I2C_Handle_t* pI2CHandle)
{ // just configure SCL I2C
    pI2CHandle->pI2Cx->CR1 &= ~(1 << I2C_CR1_PE);

    uint32_t timing_register = 0;

    timing_register = pI2CHandle->I2C_Config.I2C_SCLSpeed;
    
    pI2CHandle->pI2Cx->TIMINGR = timing_register;
}


void I2C_MasterSendData(I2C_Handle_t *pI2CHandle, uint8_t *pTxbuffer, uint32_t Len, uint8_t slaveAddr, uint8_t repeatedStart)
{
    pI2CHandle->pI2Cx->CR2 = 0; //reset 
    // generate start condition
    pI2CHandle->TxLen = Len;
    pI2CHandle->pTxBuffer = pTxbuffer;
    I2C_ConfigureSlaveConnection(pI2CHandle, 1);

    I2C_GenerateStartCondition(pI2CHandle->pI2Cx);

    for(uint8_t i=0; i < pI2CHandle->TxLen; i++){
        pI2CHandle->pI2Cx->TXDR=pI2CHandle->pTxBuffer[i];
        while(!(pI2CHandle->pI2Cx->ISR & (1 << I2C_ISR_TXE))){
        }
    }
    
    if(!repeatedStart) {
        I2C_GenerateStopCondition(pI2CHandle->pI2Cx);
    }
}

void I2C_MasterReadData(I2C_Handle_t *pI2CHandle, uint8_t *pRxbuffer, uint32_t Len, uint8_t slaveAddr, uint8_t repeatedStart)
{
    pI2CHandle->pI2Cx->CR2 = 0; //reset 
    // generate start condition
    pI2CHandle->RxLen = Len;
    pI2CHandle->pRxBuffer = pRxbuffer;
    I2C_ConfigureSlaveConnection(pI2CHandle, 0);

    I2C_GenerateStartCondition(pI2CHandle->pI2Cx);
    while(Len > 0){
        while(!(pI2CHandle->pI2Cx->ISR & (1 << I2C_ISR_RXNE))){
        }
        *pI2CHandle->pRxBuffer = pI2CHandle->pI2Cx->RXDR;
        pI2CHandle->pRxBuffer++;
        Len--;
    } 
    if(!repeatedStart) {
        I2C_GenerateStopCondition(pI2CHandle->pI2Cx);
    }
} 

void I2C_Enable(I2C_Handle_t *pI2CHandle){
    pI2CHandle->pI2Cx->CR1 |= (ENABLE << I2C_CR1_PE);
}

static void I2C_GenerateStartCondition(I2C_RegDef_t *pI2Cx){
    pI2Cx->CR2 |= (1 << I2C_CR2_START);
}

static void I2C_GenerateStopCondition(I2C_RegDef_t *pI2Cx){
    pI2Cx->CR2 |= (1 << I2C_CR2_STOP);
}

static void I2C_ConfigureSlaveConnection(I2C_Handle_t *pI2CHandle, uint8_t write){
    pI2CHandle->pI2Cx->CR2 = 0;
    if(!pI2CHandle->I2C_Config.I2C_AddressingMode){
        pI2CHandle->pI2Cx->CR2 |= (pI2CHandle->I2C_Config.I2C_SlaveDeviceAddress << (I2C_CR2_SAAD + 1)); // for 7 bit address we ignore first bit
    } else {
        pI2CHandle->pI2Cx->CR2 |= (pI2CHandle->I2C_Config.I2C_SlaveDeviceAddress << I2C_CR2_SAAD);
    }
    if(write){
        pI2CHandle->pI2Cx->CR2 |= (pI2CHandle->TxLen << I2C_CR2_NBYTES);
        pI2CHandle->pI2Cx->CR2 &= ~(1 << I2C_CR2_RD_WRN);
    } else { 
        pI2CHandle->pI2Cx->CR2 |= (pI2CHandle->RxLen << I2C_CR2_NBYTES);
        pI2CHandle->pI2Cx->CR2 |= (1 << I2C_CR2_RD_WRN);
    }
    pI2CHandle->pI2Cx->CR2 |= (pI2CHandle->I2C_Config.I2C_AddressingMode << I2C_CR2_ADD0);
}

uint8_t I2C_MasterSendDataIT(I2C_Handle_t *pI2CHandle, uint8_t *pTxbuffer, uint32_t Len, uint8_t slaveAddr, uint8_t repeatedStart){
    uint8_t state = pI2CHandle->TxStatus;
    if(state != I2C_BUSY_IN_TX ){
        pI2CHandle->pTxBuffer = pTxbuffer;

        pI2CHandle->TxLen = Len;
    
        pI2CHandle->repeatedStart = repeatedStart;

        pI2CHandle->TxStatus = I2C_BUSY_IN_TX;
        
        pI2CHandle->pI2Cx->CR1 |= (ENABLE << I2C_CR1_TXIE);

        I2C_ConfigureSlaveConnection(pI2CHandle, 1);
        
        I2C_GenerateStartCondition(pI2CHandle->pI2Cx);
    }

    return state;
}

uint8_t I2C_MasterReceiveDataIT(I2C_Handle_t *pI2CHandle, uint8_t *pRxbuffer, uint32_t Len, uint8_t slaveAddr, uint8_t repeatedStart){
    uint8_t state = pI2CHandle->RxStatus;

    if(state != I2C_BUSY_IN_RX){
        pI2CHandle->pRxBuffer = pRxbuffer;
        
        pI2CHandle->RxLen = Len;
        
        pI2CHandle->repeatedStart = repeatedStart;
        
        pI2CHandle->RxStatus = I2C_BUSY_IN_RX;

        pI2CHandle->pI2Cx->CR1 |= (ENABLE << I2C_CR1_RXIE);

        I2C_ConfigureSlaveConnection(pI2CHandle, 0);
        
        I2C_GenerateStartCondition(pI2CHandle->pI2Cx);
    }

    return state;
}

void I2C_CloseTransmission(I2C_Handle_t *pI2CHandle){
    pI2CHandle->pTxBuffer = NULL;
    pI2CHandle->TxLen = 0;
    pI2CHandle->repeatedStart = 0;

    pI2CHandle->TxStatus = I2C_READY;

    pI2CHandle->pI2Cx->CR1 &= ~(1 << I2C_CR1_TXIE);
}

void I2C_CloseReception(I2C_Handle_t *pI2CHandle){
    pI2CHandle->pRxBuffer = NULL;
    pI2CHandle->RxLen = 0;
    pI2CHandle->repeatedStart = 0;

    pI2CHandle->RxStatus = I2C_READY;

    pI2CHandle->pI2Cx->CR1 &= ~(1 << I2C_CR1_RXIE);
}

static void i2c_txis_interrupt_handler(I2C_Handle_t *pI2CHandle){
    pI2CHandle->pI2Cx->TXDR=*pI2CHandle->pTxBuffer;
    pI2CHandle->pTxBuffer++;
    pI2CHandle->TxLen--;

    if(pI2CHandle->TxLen == 0){
        if(!pI2CHandle->repeatedStart){
            I2C_GenerateStopCondition(pI2CHandle->pI2Cx);
        }
        I2C_CloseTransmission(pI2CHandle);
    }
}


static void i2c_rxie_interrupt_handler(I2C_Handle_t *pI2CHandle){ // get one byte at the time. WE SHOULDN'T HAVE LOOPS in interrupts. They should be non blocking!!!
    if(pI2CHandle->RxLen > 0){
        *pI2CHandle->pRxBuffer = pI2CHandle->pI2Cx->RXDR;
        pI2CHandle->pRxBuffer++;
        pI2CHandle->RxLen--;
    } 
    
    if(pI2CHandle->RxLen == 0){
        if(!pI2CHandle->repeatedStart) {
            I2C_GenerateStopCondition(pI2CHandle->pI2Cx);
        }
        I2C_CloseReception(pI2CHandle);
    }
}

void I2C_IRQHandling(I2C_Handle_t *pI2CHandle){
    uint8_t temp1, temp2;

    temp1 = pI2CHandle->pI2Cx->ISR & (1 << I2C_ISR_TXIS);
    temp2 = pI2CHandle->pI2Cx->CR1 & (1 << I2C_CR1_TXIE);
    if(temp1 && temp2){
        i2c_txis_interrupt_handler(pI2CHandle);
    }

    temp1 = pI2CHandle->pI2Cx->ISR & (1 << I2C_ISR_RXNE); 
    temp2 = pI2CHandle->pI2Cx->CR1 & (1 << I2C_CR1_RXIE);
    if(temp1 && temp2){
       i2c_rxie_interrupt_handler(pI2CHandle); 
    }
}
