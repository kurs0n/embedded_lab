#ifndef STM32F303REx_H
#define STM32F303REx_H

#include <stdint.h>
#include <stddef.h>
#define _vo volatile

#define NO_PRIORITY_BITS_IMPLEMENTED 4

#define NVIC_ISER0 ((_vo uint32_t*) 0xE000E100UL)
#define NVIC_ISER1 ((_vo uint32_t*) 0xE000E104UL)
#define NVIC_ISER2 ((_vo uint32_t*) 0xE000E108UL)
#define NVIC_ISER3 ((_vo uint32_t*) 0xE000E10CUL)

#define NVIC_ICER0 ((_vo uint32_t*) 0xE000E180UL)
#define NVIC_ICER1 ((_vo uint32_t*) 0xE000E184UL)
#define NVIC_ICER2 ((_vo uint32_t*) 0xE000E188UL)
#define NVIC_ICER3 ((_vo uint32_t*) 0xE000E18CUL)

#define NVIC_PR_BASE_ADDR ((_vo uint32_t*) 0xE000E400UL)

#define FLASH_BASEADDR 0x08000000U
#define SRAM_BASEADDR 0x20000000UL
#define ROM_BASEADDR 0x1FFFD800UL


/* Peripherial buses adresses */

#define PERIPH_BASE 0x40000000UL
#define APB1PERIPH_BASE PERIPH_BASE
#define APB2PERIPH_BASE 0x40010000UL
#define AHB1PERIPH_BASE 0x40020000UL
#define AHB2PERIPH_BASE 0x48000000UL
#define AHB3PERIPH_BASE 0x50000000UL

#define SRAM SRAM_BASEADDR 

/* Peripherial buses addresses end */

/* Base addresses of peripherials which are hanging on AHB3 BUS */

#define ADC1_ADC2_BASEADDR AHB3PERIPH_BASE
#define ADC3_ADC4_BASEADDR (AHB3PERIPH_BASE + 0x0400UL)

/* Base addresses of peripherials which are hanging on AHB3 BUS end */

/* Base addresses of peripherials which are hanging on AHB2 BUS */

#define GPIOA_BASEADDR (AHB2PERIPH_BASE + 0x0000UL)
#define GPIOB_BASEADDR (AHB2PERIPH_BASE + 0x0400UL)
#define GPIOC_BASEADDR (AHB2PERIPH_BASE + 0x0800UL)
#define GPIOD_BASEADDR (AHB2PERIPH_BASE + 0x0C00UL)
#define GPIOE_BASEADDR (AHB2PERIPH_BASE + 0x1000UL)
#define GPIOF_BASEADDR (AHB2PERIPH_BASE + 0x1400UL)
#define GPIOG_BASEADDR (AHB2PERIPH_BASE + 0x1800UL)
#define GPIOH_BASEADDR (AHB2PERIPH_BASE + 0x1C00UL)

/* Base addresses of peripherials which are hanging on AHB2 BUS end*/


/* Base addresses of peripherials which are hanging on AHB1 BUS */

#define DMA1_BASEADDR AHB1PERIPH_BASE
#define DMA2_BASEADDR (AHB1PERIPH_BASE + 0x0400UL)
#define RCC_BASEADDR (AHB1PERIPH_BASE + 0x1000UL)
#define FLASHIF_BASEADDR (AHB1PERIPH_BASE + 0x2000UL)
#define CRC_BASEADDR (AHB1PERIPH_BASE + 0x3000UL)
#define TSC_BASEADDR (AHB1PERIPH_BASE + 0x4000UL)

/* Base addresses of peripherials which are hanging on AHB1 BUS end*/


/* Base addresses of peripherials which are hanging on APB1 BUS */

#define TIM2_BASEADDR APB1PERIPH_BASE
#define TIM3_BASEADDR (APB1PERIPH_BASE + 0x0400UL)
#define TIM4_BASEADDR (APB1PERIPH_BASE + 0x0800UL)
#define TIM6_BASEADDR (APB1PERIPH_BASE + 0x1000UL)
#define TIM7_BASEADDR (APB1PERIPH_BASE + 0x1400UL)
#define RTC_BASEADDR (APB1PERIPH_BASE + 0x2800UL)
#define WWDG_BASEADDR (APB1PERIPH_BASE + 0x2C00UL)
#define IWDG_BASEADDR (APB1PERIPH_BASE + 0x3000UL)
#define I2S2EXT_BASEADDR (APB1PERIPH_BASE + 0x3400UL)
#define SPI2_I2S2_BASEADDR (APB1PERIPH_BASE + 0x3800UL)
#define SPI3_I2S3_BASEADDR (APB1PERIPH_BASE + 0x3C00UL)
#define I2S3EXT_BASEADDR (APB1PERIPH_BASE + 0x4000UL)
#define USART2_BASEADDR (APB1PERIPH_BASE + 0x4400UL)
#define USART3_BASEADDR (APB1PERIPH_BASE + 0x4800UL)
#define UART4_BASEADDR (APB1PERIPH_BASE + 0x4C00UL)
#define UART5_BASEADDR (APB1PERIPH_BASE + 0x5000UL)
#define I2C1_BASEADDR (APB1PERIPH_BASE + 0x5400UL)
#define I2C2_BASEADDR (APB1PERIPH_BASE + 0x5800UL)
#define USBDEVICEFS_BASEADDR (APB1PERIPH_BASE + 0x5C00UL)
#define USBSRAM15BYTES_BASEADDR (APB1PERIPH_BASE + 0x6000UL)
#define BXCAN_BASEADDR (APB1PERIPH_BASE + 0x6400UL)
#define PWR_BASEADDR (APB1PERIPH_BASE + 0x7000UL)
#define DAC1_BASEADDR (APB1PERIPH_BASE + 0x7400UL)

/* Base addresses of peripherials which are hanging on APB1 BUS end */


/* Base addresses of peripherials which are hanging on APB2 BUS */

#define SYSCFG_COMP_OPAMP_BASEADDR APB2PERIPH_BASE
#define EXTI_BASEADDR (APB2PERIPH_BASE + 0x0400UL)
#define TIM1_BASEADDR (APB2PERIPH_BASE + 0x2C00UL)
#define SPI1_BASEADDR (APB2PERIPH_BASE + 0x3000UL)
#define TIM8_BASEADDR (APB2PERIPH_BASE + 0x3400UL)
#define USART1_BASEADDR (APB2PERIPH_BASE + 0x3800UL)
#define SPI4_BASEADDR (APB2PERIPH_BASE + 0x3C00UL)
#define TIM15_BASEADDR (APB2PERIPH_BASE + 0x4000UL)
#define TIM16_BASEADDR (APB2PERIPH_BASE + 0x4400UL)
#define TIM17_BASEADDR (APB2PERIPH_BASE + 0x4800UL)

/* Base addresses of peripherials which are hanging on APB2 BUS end */



// Peripheral register definition structures

typedef struct
{
    _vo uint32_t MODER;      // GPIO port mode register
    _vo uint32_t OTYPER;
    _vo uint32_t OSPEEDR;   // GPIO port output speed register
    _vo uint32_t PUPDR;     // GPIO port pull-up/pull-down register
    _vo uint32_t IDR;       // GPIO port input data register
    _vo uint32_t ODR;       // GPIO port output data register
    _vo uint32_t BSRR;      // GPIO port bit set/reset register
    _vo uint32_t LCKR;      // GPIO port configuration lock register
    _vo uint32_t AFR[2];    // GPIO alternate function registers (AFR[0] and AFR[1])
    _vo uint32_t BRR;    // GPIO port bit reset register
} GPIO_RegDef_t;

typedef struct 
{
    _vo uint32_t CR1; // SPI control register 1
    _vo uint32_t CR2; // SPI control register 2
    _vo uint32_t SR; // SPI status register
    _vo uint32_t DR; // SPI data register
    _vo uint32_t CRCPR; // SPI CRC polynomial register
    _vo uint32_t RXCRCR; // SPI Rx CRC register
    _vo uint32_t TXCRCR; // SPI Tx CRC register 
    _vo uint32_t I2SCFGR; // I2S configuration register
    _vo uint32_t I2SPR;
} SPI_RegDef_t;

typedef struct 
{
    _vo uint32_t CR1;
    _vo uint32_t CR2;
    _vo uint32_t OAR1;
    _vo uint32_t OAR2;
    _vo uint32_t TIMINGR;
    _vo uint32_t TIMEOUTR;
    _vo uint32_t ISR;
    _vo uint32_t ICR;
    _vo uint32_t PECR;
    _vo uint32_t RXDR;
    _vo uint32_t TXDR;
} I2C_RegDef_t;

typedef struct{
    _vo uint32_t CR; // RCC clock control register
    _vo uint32_t CFGR; // RCC clock configuration register
    _vo uint32_t CIR; // RCC clock interrupt register
    _vo uint32_t APB2RSTR;  // RCC APB2 peripheral reset register
    _vo uint32_t APB1RSTR;  // RCC APB1 peripheral reset register
    _vo uint32_t AHBENR;  // RCC AHB peripheral clock enable register
    _vo uint32_t APB2ENR;  // RCC APB2 peripheral clock enable register
    _vo uint32_t APB1ENR;  // RCC APB1 peripheral clock enable register
    _vo uint32_t BDCR;  // RCC Backup domain control register
    _vo uint32_t CSR;  // RCC clock control and status register
    _vo uint32_t AHBRSTR;  // RCC AHB peripheral reset register
    _vo uint32_t CFGR2;  // RCC clock configuration register 2
    _vo uint32_t CFGR3;  // RCC clock configuration register 3
} RCC_RegDef_t;

typedef struct {
    _vo uint32_t CFGR1;        // SYSCFG configuration register 1,          offset: 0x00
    _vo uint32_t RCR;          // SYSCFG CCM SRAM control register,         offset: 0x04
    _vo uint32_t EXTICR[4];    // SYSCFG external interrupt configuration,  offset: 0x08-0x14
    _vo uint32_t CFGR2;        // SYSCFG configuration register 2,          offset: 0x18
    uint32_t RESERVED[14]; // Reserved,                                
    _vo uint32_t CFGR3;       // SYSCFG configuration register 3,          offset: 0x50
    _vo uint32_t CFGR4;      // SYSCFG configuration register 4,          offset: 0x54
} SYSCFG_RegDef_t;

typedef struct{
    _vo uint32_t IMR;   // Interrupt mask register
    _vo uint32_t EMR;   // Event mask register
    _vo uint32_t RTSR;  // Rising trigger selection register
    _vo uint32_t FTSR;  // Falling trigger selection register
    _vo uint32_t SWIER; // Software interrupt event register
    _vo uint32_t PR;    // Pending register
} EXTI_RegDef_t;

/* Peripherial Definitions */

#define GPIOA ((GPIO_RegDef_t *)GPIOA_BASEADDR)
#define GPIOB ((GPIO_RegDef_t *)GPIOB_BASEADDR)
#define GPIOC ((GPIO_RegDef_t *)GPIOC_BASEADDR)
#define GPIOD ((GPIO_RegDef_t *)GPIOD_BASEADDR)
#define GPIOE ((GPIO_RegDef_t *)GPIOE_BASEADDR)
#define GPIOF ((GPIO_RegDef_t *)GPIOF_BASEADDR)
#define GPIOG ((GPIO_RegDef_t *)GPIOG_BASEADDR)
#define GPIOH ((GPIO_RegDef_t *)GPIOH_BASEADDR)

#define RCC ((RCC_RegDef_t *)RCC_BASEADDR)

#define EXTI ((EXTI_RegDef_t *)EXTI_BASEADDR)

#define SYSCFG ((SYSCFG_RegDef_t *)SYSCFG_COMP_OPAMP_BASEADDR)

/* Reset GPIOx peripherials */

#define GPIOA_REG_RESET() do{GPIOA->BSRR |= (0xFFFF << 16); GPIOA->BSRR &= ~(0xFFFF << 16);}while(0)
#define GPIOB_REG_RESET() do{GPIOB->BSRR |= (0xFFFF << 16); GPIOB->BSRR &= ~(0xFFFF << 16);}while(0)
#define GPIOC_REG_RESET() do{GPIOC->BSRR |= (0xFFFF << 16); GPIOC->BSRR &= ~(0xFFFF << 16);}while(0)
#define GPIOD_REG_RESET() do{GPIOD->BSRR |= (0xFFFF << 16); GPIOD->BSRR &= ~(0xFFFF << 16);}while(0)
#define GPIOE_REG_RESET() do{GPIOE->BSRR |= (0xFFFF << 16); GPIOE->BSRR &= ~(0xFFFF << 16);}while(0)
#define GPIOF_REG_RESET() do{GPIOF->BSRR |= (0xFFFF << 16); GPIOF->BSRR &= ~(0xFFFF << 16);}while(0)

/* Reset GPIOx peripherials end */

/* Clock Enable Macros for GPIOx peripherials */

#define GPIOA_PERI_CLOCK_ENABLE()   ( RCC->AHBENR |= (1<<17))
#define GPIOB_PERI_CLOCK_ENABLE()   ( RCC->AHBENR |= (1<<18))
#define GPIOC_PERI_CLOCK_ENABLE()   ( RCC->AHBENR |= (1<<19))
#define GPIOD_PERI_CLOCK_ENABLE()   ( RCC->AHBENR |= (1<<20))
#define GPIOE_PERI_CLOCK_ENABLE()   ( RCC->AHBENR |= (1<<21))
#define GPIOF_PERI_CLOCK_ENABLE()   ( RCC->AHBENR |= (1<<22))

/* Clock Enable Macros for GPIOx peripherials end */

/* Clock Enable Macros for I2Cx peripherials */

#define I2C1_PCLK_EN()  (RCC->APB1ENR |= (1<<21))
#define I2C2_PCLK_EN()  (RCC->APB1ENR |= (1<<22))
#define I2C3_PCLK_EN()  (RCC->APB1ENR |= (1<<30))

/* Clock Enable Macros for I2Cx peripherials end */

/* Clock Enable Macros for SPIx peripherials */

#define SPI1_PCLK_EN() (RCC->APB2ENR |= (1<<12))
#define SPI2_PCLK_EN() (RCC->APB1ENR |= (1<<14))
#define SPI3_PCLK_EN() (RCC->APB1ENR |= (1<<15))
#define SPI4_PCLK_EN() (RCC->APB2ENR |= (1<<15))

/* Clock Enable Macros for SPIx peripherials end */


/* Clock Enable Macros for USARTx peripherials */

#define USART1_PCLK_EN() (RCC->APB2ENR |= (1<<14))
#define USART2_PCLK_EN() (RCC->APB1ENR |= (1<<17))
#define USART3_PCLK_EN() (RCC->APB1ENR |= (1<<18))
#define UART4_PCLK_EN() (RCC->APB1ENR |= (1<<19))
#define UART5_PCLK_EN() (RCC->APB1ENR |= (1<<20))

/* Clock Enable Macros for USARTx peripherials end*/


/* Clock Enable Macros for SYSCFG peripherial */

#define SYSCFG_PCLK_EN() (RCC->APB2ENR |= 1)

/* Clock Enable Macros for SYSCFG peripherial end*/

/* Clock Disable Macros for GPIOx peripherials */

#define GPIOA_PERI_CLOCK_DISABLE()   ( RCC->AHBENR &= ~(1<<17))
#define GPIOB_PERI_CLOCK_DISABLE()   ( RCC->AHBENR &= ~(1<<18))
#define GPIOC_PERI_CLOCK_DISABLE()   ( RCC->AHBENR &= ~(1<<19))
#define GPIOD_PERI_CLOCK_DISABLE()   ( RCC->AHBENR &= ~(1<<20))
#define GPIOE_PERI_CLOCK_DISABLE()   ( RCC->AHBENR &= ~(1<<21))
#define GPIOF_PERI_CLOCK_DISABLE()   ( RCC->AHBENR &= ~(1<<22))

#define GPIO_BASEADDR_TO_CODE(x)    ((x == GPIOA) ? 0 : \
                                    (x == GPIOB) ? 1 : \
                                    (x == GPIOC) ? 2 : \
                                    (x == GPIOD) ? 3 : \
                                   (x == GPIOE)? 4 : \
                                    (x == GPIOF) ? 5 : \
                                    (x == GPIOG) ? 6 : 0) 

/* Clock Disable Macros for GPIOx peripherials end */

/* Clock Disable Macros for I2Cx peripherials */

#define I2C1_PCLK_DI()  (RCC->APB1ENR &= ~(1<<21))
#define I2C2_PCLK_DI()  (RCC->APB1ENR &= ~(1<<22))
#define I2C3_PCLK_DI()  (RCC->APB1ENR &= ~(1<<30))

/* Clock Disable Macros for I2Cx peripherials end */

/* Clock Disable Macros for SPIx peripherials */

#define SPI1_PCLK_DI() (RCC->APB2ENR &= ~(1<<12))
#define SPI2_PCLK_DI() (RCC->APB1ENR &= ~(1<<14))
#define SPI3_PCLK_DI() (RCC->APB1ENR &= ~(1<<15))
#define SPI4_PCLK_DI() (RCC->APB2ENR &= ~(1<<15))

/* Clock Disable Macros for SPIx peripherials end */


/* Clock Disable Macros for USARTx peripherials */

#define USART1_PCLK_DI() (RCC->APB2ENR &= ~(1<<14))
#define USART2_PCLK_DI() (RCC->APB1ENR &= ~(1<<17))
#define USART3_PCLK_DI() (RCC->APB1ENR &= ~(1<<18))
#define UART4_PCLK_DI()  (RCC->APB1ENR &= ~(1<<19))
#define UART5_PCLK_DI()  (RCC->APB1ENR &= ~(1<<20))

/* Clock Disable Macros for USARTx peripherials end*/


/* Clock Disable Macros for SYSCFG peripherial */

#define SYSCFG_PCLK_DI() (RCC->APB2ENR &= ~(1))

/* Clock Disable Macros for SYSCFG peripherial end*/

/* SPI Bit positions of SPI peripheral */
// CONTROL REGISTER 1
#define SPI_CR1_CPHA 0
#define SPI_CR1_CPOL 1
#define SPI_CR1_MSTR 2 
#define SPI_CR1_BR 3
#define SPI_CR1_SPE 6 
#define SPI_CR1_LSBFIRST 7
#define SPI_CR1_SSI 8
#define SPI_CR1_SSM 9
#define SPI_CR1_RXONLY 10
#define SPI_CR1_CRCL 11
#define SPI_CR1_CRCNEXT 12 
#define SPI_CR1_CRCEN 13 
#define SPI_CR1_BIDIOE 14 
#define SPI_CR1_BIDIMODE 15

// CONTROL REGISTER 2 
#define SPI_CR2_RXDMAEN 0
#define SPI_CR2_TXDMAEN 1
#define SPI_CR2_SSOE 2
#define SPI_CR2_NSSP 3
#define SPI_CR2_FRF 4
#define SPI_CR2_ERRIE 5
#define SPI_CR2_RXNEIE 6
#define SPI_CR2_TXEIE 7
#define SPI_CR2_DS 8
#define SPI_CR2_FRXTH 12
#define SPI_CR2_LDMA_RX 13
#define SPI_CR2_LDMA_TX 14

// STATUS REGISTER
#define SPI_SR_RXNE 0
#define SPI_SR_TXE 1
#define SPI_SR_CHSIDE 2
#define SPI_SR_UDR 3  
#define SPI_SR_CRCERR 4
#define SPI_SR_MODF 5
#define SPI_SR_OVR 6
#define SPI_SR_BSY 7
#define SPI_SR_FRE 8
#define SPI_SR_FRLVL 9
#define SPI_SR_FTLVL 11

/* SPI Base Addresses */

#define SPI1 ((SPI_RegDef_t *)SPI1_BASEADDR)
#define SPI2 ((SPI_RegDef_t *)SPI2_I2S2_BASEADDR)
#define SPI3 ((SPI_RegDef_t *)SPI3_I2S3_BASEADDR)
#define SPI4 ((SPI_RegDef_t *)SPI4_BASEADDR)

/* Reset SPIx peripherials */
#define SPI1_REG_RESET() do{RCC->APB2RSTR |= (1<<12); RCC->APB2RSTR &= ~(1<<12);}while(0)
#define SPI2_REG_RESET() do{RCC->APB1RSTR |= (1<<14); RCC->APB1RSTR &= ~(1<<14);}while(0)
#define SPI3_REG_RESET() do{RCC->APB1RSTR |= (1<<15); RCC->APB1RSTR &= ~(1<<15);}while(0)
#define SPI4_REG_RESET() do{RCC->APB2RSTR |= (1<<15); RCC->APB2RSTR &= ~(1<<15);}while(0)

// I2C Bit positions of I2C peripherial
// Control Register 1
#define I2C_CR1_PE 0
#define I2C_CR1_TXIE 1 
#define I2C_CR1_RXIE 2
#define I2C_CR1_ADDRIE 3
#define I2C_CR1_NACKIE 4
#define I2C_CR1_STOPIE 5
#define I2C_CR1_TCIE 6
#define I2C_CR1_ERRIE 7
#define I2C_CR1_DNF 8
#define I2C_CR1_ANFOFF 12
#define I2C_CR1_TXDMAEN 14
#define I2C_CR1_RXDMAEN 15
#define I2C_CR1_SBC 16
#define I2C_CR1_NOSTRETCH 17
#define I2C_CR1_WUPEN 18
#define I2C_CR1_GCEN 19
#define I2C_CR1_SMBHEN 20
#define I2C_CR1_SMBDEN 21
#define I2C_CR1_ALERTEN 22
#define I2C_CR1_PECEN 23

// Control register 2
#define I2C_CR2_SAAD 0
#define I2C_CR2_RD_WRN 10
#define I2C_CR2_ADD0 11
#define I2C_CR2_HEAD10R 12
#define I2C_CR2_START 13
#define I2C_CR2_STOP 14
#define I2C_CR2_NACK 15
#define I2C_CR2_NBYTES 16
#define I2C_CR2_RELOAD 24
#define I2C_CR2_AUTOEND 25
#define I2C_CR2_PECBYTE 26

// Timing register 
#define I2C_TIMINGR_SCLL 0
#define I2C_TIMINGR_SCLH 8
#define I2C_TIMINGR_SDAEL 16
#define I2C_TIMINGR_SCLDEL 20
#define I2C_TIMINGR_PRESC 28

// ISR register
#define I2C_ISR_TXE 0
#define I2C_ISR_TXIS 1
#define I2C_ISR_RXNE 2
#define I2C_ISR_ADDR 3
#define I2C_ISR_NACKF 4
#define I2C_ISR_STOPF 5
#define I2C_ISR_TC 6
#define I2C_ISR_TCR 7
#define I2C_ISR_BERR 8
#define I2C_ISR_ARLO 9
#define I2C_ISR_OVR 10
#define I2C_ISR_PECERR 11
#define I2C_ISR_TIMEOUT 12
#define I2C_ISR_ALERT 13
#define I2C_ISR_BUSY 15
#define I2C_ISR_DIR 16
#define I2C_ISR_ADDCODE 17

/* I2C Base Addresses */
#define I2C1 ((I2C_RegDef_t *) I2C1_BASEADDR)
#define I2C2 ((I2C_RegDef_t *) I2C2_BASEADDR)

/* Reset I2Cx peripherials */


/*  IRQ numbers
*/

#define IRQ_NO_EXTI0 6
#define IRQ_NO_EXTI1 7
#define IRQ_NO_EXTI2 8
#define IRQ_NO_EXTI3 9
#define IRQ_NO_EXTI4 10
#define IRQ_NO_EXTI5_9 23
#define IRQ_NO_I2C1_EV 31
#define IRQ_NO_I2C1_ER 32
#define IRQ_NO_SPI1 35
#define IRQ_NO_SPI2 36
#define IRQ_NO_EXTI10_15 40

/* IRQ numbers end*/

#endif
