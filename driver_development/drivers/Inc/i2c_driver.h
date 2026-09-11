#ifndef INC_I2C_DRIVER_H
#define INC_I2C_DRIVER_H

#include "STM32F303REx.h"

#define ENABLE 1
#define DISABLE 0

typedef struct // for nucleo f3 I2C interface was completely redesigned comparing to f4, f1 (need to write it differently)
{
    uint32_t I2C_SCLSpeed; // 0x2000090E -> standard mode 100kHz for HSI 8MHz
    uint8_t I2C_SlaveDeviceAddress;
    uint8_t I2C_AddressingMode; // 7-bit -> 0, 10-bit -> 1
} I2C_Config_t;

typedef struct
{
    I2C_RegDef_t *pI2Cx;
    I2C_Config_t I2C_Config;
    uint8_t *pTxBuffer;
    uint32_t TxLen;
    uint8_t *pRxBuffer;
    uint32_t RxLen;
    uint8_t TxStatus;
    uint8_t RxStatus;
    uint32_t slaveAddr;
    uint8_t repeatedStart;

} I2C_Handle_t;

void I2C_PeriClockControl(I2C_RegDef_t *pI2Cx, uint8_t EnorDi);

void I2C_Init(I2C_Handle_t* pI2CHandle);

void I2C_Enable(I2C_Handle_t* pI2CHandle);

void I2C_MasterSendData(I2C_Handle_t *pI2CHandle, uint8_t *pTxbuffer, uint32_t Len, uint8_t slaveAddr, uint8_t repeatedStart);

void I2C_MasterReadData(I2C_Handle_t *pI2CHandle, uint8_t *pRxbuffer, uint32_t Len, uint8_t slaveAddr, uint8_t repeatedStart);

uint8_t I2C_MasterSendDataIT(I2C_Handle_t *pI2CHandle, uint8_t *pTxbuffer, uint32_t Len, uint8_t slaveAddr, uint8_t repeatedStart);

void I2C_IRQHandling(I2C_Handle_t *pI2CHandle);
//I2C specific macros
#define I2C_READY 0
#define I2C_BUSY_IN_TX 1
#define I2C_BUSY_IN_RX 2


#endif