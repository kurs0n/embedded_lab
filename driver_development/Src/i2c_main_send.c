#include "gpio_driver.h"
#include "i2c_driver.h"
#include <string.h>

#define PICO_SLAVE_ADDRESS 0x17

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
const char buffer[] = "hello from master i2c!";

int main(void){
    config_gpio_onboard_button(&gpioButton);
    config_gpio_for_i2c1(&i2cPins);

    I2C_PeriClockControl(I2C1, ENABLE);

    I2C1Handle.pI2Cx = I2C1;
    I2C1Handle.I2C_Config.I2C_SCLSpeed = 0x2000090E;
    I2C1Handle.I2C_Config.I2C_SlaveDeviceAddress = 0x17;
    I2C1Handle.I2C_Config.I2C_AddressingMode = 0;
    I2C1Handle.I2C_Config.I2C_SlaveMode = 0;

    I2C_Init(&I2C1Handle);

    I2C_Enable(&I2C1Handle);

    while(1){
        if(!GPIO_ReadFromInputPin(gpioButton.pGPIOx,gpioButton.GPIO_PinConfig.GPIO_PinNumber)){
            I2C_MasterSendData(&I2C1Handle, (uint8_t *)buffer, strlen(buffer), PICO_SLAVE_ADDRESS, 0);
        }
        delay();
    }
}