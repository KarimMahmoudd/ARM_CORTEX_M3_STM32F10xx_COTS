/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 23 NOV 2022                                                                                                        */
/*  SWC         : RCC                                                                                                                */
/*  Version     : V01                                                                                                                */
/*************************************************************************************************************************************/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

void MRCC_voidInitSystemClock(void);

u8 MRCC_u8EnableClock(u8 Copy_u8BusID,u8 Copy_u8PerID);

u8 MRCC_u8DisableClock(u8 Copy_u8BusID,u8 Copy_u8PerID);

// IP Macros for RCC_u8EnableClock, RCC_u8DisableClock
// IP for Copy_u8BusID
#define RCC_AHB         0
#define RCC_APB1        1
#define RCC_APB2        3

// IP for Copy_u8PerID
#define RCC_AHB_DMA1    0
#define RCC_AHB_DMA2    1
#define RCC_AHB_SRAM    2
#define RCC_AHB_FLITF   4
#define RCC_AHB_CRC     6
#define RCC_AHB_FSMC    8
#define RCC_AHB_SDIO    10

#define RCC_APB1_TIM2   0
#define RCC_APB1_TIM3   1
#define RCC_APB1_TIM4   2
#define RCC_APB1_TIM5   3
#define RCC_APB1_TIM6   4
#define RCC_APB1_TIM7   5
#define RCC_APB1_TIM12  6
#define RCC_APB1_TIM13  7
#define RCC_APB1_TIM14  8
#define RCC_APB1_WWD    11
#define RCC_APB1_SPI12  14
#define RCC_APB1_SPI13  15
#define RCC_APB1_USART2 17
#define RCC_APB1_USART3 18
#define RCC_APB1_UART4  19
#define RCC_APB1_UART5  20
#define RCC_APB1_I2C1   21
#define RCC_APB1_I2C2   22
#define RCC_APB1_USB    23
#define RCC_APB1_CAN    25
#define RCC_APB1_BKP    27
#define RCC_APB1_PWR    28
#define RCC_APB1_DAC    29

#define RCC_APB2_AFIO   0
#define RCC_APB2_IOPA   2
#define RCC_APB2_IOPB   3
#define RCC_APB2_IOPC   4
#define RCC_APB2_IOPD   5
#define RCC_APB2_IOPE   6
#define RCC_APB2_IOPF   7
#define RCC_APB2_IOPG   8
#define RCC_APB2_ADC1   9
#define RCC_APB2_ADC2   10
#define RCC_APB2_TIM1   11
#define RCC_APB2_SPI1   12
#define RCC_APB2_TIM8   13
#define RCC_APB2_USART1 14
#define RCC_APB2_ADC3   15
#define RCC_APB2_TIM9   19
#define RCC_APB2_TIM10  20
#define RCC_APB2_TIM11  21

#endif