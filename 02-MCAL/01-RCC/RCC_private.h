/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 23 NOV 2022                                                                                                        */
/*  SWC         : RCC                                                                                                                */
/*  Version     : V01                                                                                                                */
/*************************************************************************************************************************************/

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

// Register Definitions Base Address : 0x4002 1000

#define RCC_CR                      *((volatile u32*)(0x40021000))
#define RCC_CR_HSION                0
#define RCC_CR_HSIRDY               1
#define RCC_CR_HSITRIM0             3
#define RCC_CR_HSEON                16
#define RCC_CR_HSERDY               17
#define RCC_CR_HSEBYP               18
#define RCC_CR_CSSON                19
#define RCC_CR_PLLON                24
#define RCC_CR_PLLRDY               25

#define RCC_CFGR                    *((volatile u32*)(0x40021004))
#define RCC_CFGR_PLLXTPRE           17
#define RCC_CFGR_PLLSRC             16
#define RCC_CFGR_SWS1               3
#define RCC_CFGR_SWS0               2
#define RCC_CFGR_SW1                1
#define RCC_CFGR_SW0                0

#define RCC_CIR                     *((volatile u32*)(0x40021008))

#define RCC_APB2RSTR                *((volatile u32*)(0x4002100C))

#define RCC_APB1RSTR                *((volatile u32*)(0x40021010))

//AHB BUS Peripherals Clock Enable Register and Bits
#define RCC_AHBENR                  *((volatile u32*)(0x40021014))
#define RCC_AHBENR_DMA1EN           0
#define RCC_AHBENR_DMA2EN           1
#define RCC_AHBENR_SRAMEN           2
#define RCC_AHBENR_FLITFEN          4
#define RCC_AHBENR_CRCEN            6
#define RCC_AHBENR_FSMCEN           8
#define RCC_AHBENR_SDIOEN           10

//APB2 BUS Peripherals Clock Enable Register and Bits
#define RCC_APB2ENR                 *((volatile u32*)(0x40021018))
#define RCC_APB2ENR_AFIOEN          0
#define RCC_APB2ENR_IOPAEN          2
#define RCC_APB2ENR_IOPBEN          3
#define RCC_APB2ENR_IOPCEN          4
#define RCC_APB2ENR_IOPDEN          5
#define RCC_APB2ENR_IOPEEN          6
#define RCC_APB2ENR_IOPFEN          7
#define RCC_APB2ENR_IOPGEN          8
#define RCC_APB2ENR_ADC1EN          9
#define RCC_APB2ENR_ADC2EN          10
#define RCC_APB2ENR_TIM1EN          11
#define RCC_APB2ENR_SPI1EN          12
#define RCC_APB2ENR_TIM8EN          13
#define RCC_APB2ENR_USART1EN        14
#define RCC_APB2ENR_ADC3EN          15
#define RCC_APB2ENR_TIM9EN          19
#define RCC_APB2ENR_TIM10EN         20
#define RCC_APB2ENR_TIM11EN         21

//APB1 BUS Peripherals Clock Enable Register and Bits
#define RCC_APB1ENR                 *((volatile u32*)(0x4002101C))
#define RCC_APB1ENR_TIM2EN          0
#define RCC_APB1ENR_TIM3EN          1
#define RCC_APB1ENR_TIM4EN          2
#define RCC_APB1ENR_TIM5EN          3
#define RCC_APB1ENR_TIM6EN          4
#define RCC_APB1ENR_TIM7EN          5
#define RCC_APB1ENR_TIM12EN         6
#define RCC_APB1ENR_TIM13EN         7
#define RCC_APB1ENR_TIM14EN         8
#define RCC_APB1ENR_WWDEN           11
#define RCC_APB1ENR_SPI12EN         14
#define RCC_APB1ENR_SPI13EN         15
#define RCC_APB1ENR_USART2EN        17
#define RCC_APB1ENR_USART3EN        18
#define RCC_APB1ENR_UART4EN         19
#define RCC_APB1ENR_UART5EN         20
#define RCC_APB1ENR_I2C1EN          21
#define RCC_APB1ENR_I2C2EN          22
#define RCC_APB1ENR_USBEN           23
#define RCC_APB1ENR_CANEN           25
#define RCC_APB1ENR_BKPEN           27
#define RCC_APB1ENR_PWREN           28
#define RCC_APB1ENR_DACEN           29

#define RCC_BDCR                    *((volatile u32*)(0x40021020))

#define RCC_CSR                     *((volatile u32*)(0x40021024))

//SYSTEM CLOCKS

#define RCC_HSI                     1
#define RCC_HSE_CRYSTAL             2
#define RCC_HSE_RC                  3
#define RCC_PLL                     4

#define PLL_HSI_DIV_BY_2            1
#define PLL_HSE_CRYSTAL             2
#define PLL_HSE_RC                  3

//PLL MULTIPLICATION FACTORS
#define MULT_BY_2                   0
#define MULT_BY_3                   1
#define MULT_BY_4                   2
#define MULT_BY_5                   3
#define MULT_BY_6                   4
#define MULT_BY_7                   5
#define MULT_BY_8                   6
#define MULT_BY_9                   7
#define MULT_BY_10                  8
#define MULT_BY_11                  9
#define MULT_BY_12                  10
#define MULT_BY_13                  12
#define MULT_BY_14                  13
#define MULT_BY_15                  14
#define MULT_BY_16                  15

#define PLL_MUL_MASK                0xffc3ffff
#define PLL_MUL_SHIFT               18

#define HSI_TRIM_MASK                   0xffffff07
#define HSI_TRIM_SHIFT                  3
#define HSI_TRIM_DEFAULT                0x10


#define ENABLE                          1
#define DISABLE                         2

#endif