#include "gpio_driver.h"
#include "i2c_driver.h"
#include <stdio.h>
#include <string.h>

#define PICO_SLAVE_ADDRESS 0x17
#define READ_LENGTH_COMMAND_CODE 0x51
#define READ_DATA_COMMAND_CODE 0x52

int delay(void){
    for (volatile uint32_t i = 0; i < 500000; i++);
}

void config_gpio_onboard_button(GPIO_Handle_t *pGPIOHandle){
    GPIO_PeriClockControl(GPIOC,ENABLE);
    pGPIOHandle->pGPIOx = GPIOC;
    pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber=GPIO_PIN_NO_13;
    pGPIOHandle->GPIO_PinConfig.GPIO_PinMode=GPIO_MODE_INPUT;
    pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed=GPIO_SPEED_HIGH;
    pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
    GPIO_Init(pGPIOHandle);
}

void config_gpio_for_i2c1(GPIO_Handle_t *pGPIOHandle){
    GPIO_PeriClockControl(GPIOB, ENABLE);
    pGPIOHandle->pGPIOx = GPIOB;
    pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_8;
    pGPIOHandle->GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTERNATE; 
    pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_HIGH;
    pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_OD;
    pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PU;
    pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode = 4;
    
    GPIO_Init(pGPIOHandle);
    pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_9;
    GPIO_Init(pGPIOHandle);
}

GPIO_Handle_t gpioButton;
GPIO_Handle_t i2cPins;
I2C_Handle_t I2C1Handle;


int main(void){ // alternate function 4 for this pins
    config_gpio_onboard_button(&gpioButton);
    config_gpio_for_i2c1(&i2cPins);

    I2C_PeriClockControl(I2C1, ENABLE);

    I2C1Handle.pI2Cx = I2C1;
    I2C1Handle.I2C_Config.I2C_SCLSpeed = 0x2000090E;
    I2C1Handle.I2C_Config.I2C_SlaveDeviceAddress = 0x17;
    I2C1Handle.I2C_Config.I2C_AddressingMode = 0;
    I2C1Handle.TxStatus = I2C_READY;
    I2C1Handle.RxStatus = I2C_READY;
    GPIO_IRQConfig(IRQ_NO_I2C1_EV,5,ENABLE);
    GPIO_IRQConfig(IRQ_NO_I2C1_ER,5,ENABLE);

    I2C_Init(&I2C1Handle);

    I2C_Enable(&I2C1Handle);
    char dataBuffer[252] = {0};
    uint8_t lengthOfDataToReceive = 0;
    while(1){
        if(!GPIO_ReadFromInputPin(gpioButton.pGPIOx,gpioButton.GPIO_PinConfig.GPIO_PinNumber)){
            uint8_t command = READ_LENGTH_COMMAND_CODE;
            I2C_MasterSendDataIT(&I2C1Handle, &command, 1, PICO_SLAVE_ADDRESS, 0);
            while(I2C1Handle.TxStatus == I2C_BUSY_IN_TX){
                // wait for interrupt
            }
            I2C_MasterReceiveDataIT(&I2C1Handle, &lengthOfDataToReceive, 1, PICO_SLAVE_ADDRESS, 0);
            while(I2C1Handle.RxStatus == I2C_BUSY_IN_RX){
                // wait for interrupt
            }
            command = READ_DATA_COMMAND_CODE;
            I2C_MasterSendDataIT(&I2C1Handle, &command, 1, PICO_SLAVE_ADDRESS, 0);
            while(I2C1Handle.TxStatus == I2C_BUSY_IN_TX){
                // wait for interrupt
            }
            I2C_MasterReceiveDataIT(&I2C1Handle, dataBuffer, lengthOfDataToReceive, PICO_SLAVE_ADDRESS, 0);
            while(I2C1Handle.RxStatus == I2C_BUSY_IN_RX){
                // wait for interrupt
            }

            (void)dataBuffer;
        }
        delay();
    }
}

void I2C1_EV_EXTI23_IRQHandler(void){
    I2C_IRQHandling(&I2C1Handle);
}