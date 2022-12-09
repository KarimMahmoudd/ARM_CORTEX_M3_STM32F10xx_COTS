/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 29 NOV 2022                                                                                                        */
/*  Layer       : MCAL                                                                                                               */
/*  SWC         : NVIC                                                                                                               */
/*  Version     : V01                                                                                                                */
/*************************************************************************************************************************************/

#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

/* Interrupt IDs */
#define NVIC_WWDG               0
#define NVIC_PVD                1
#define NVIC_TAMPER             2
#define NVIC_RTC                3
#define NVIC_FLASH              4
#define NVIC_RCC                5
#define NVIC_EXTI0              6
#define NVIC_EXTI1              7
#define NVIC_EXTI2              8
#define NVIC_EXTI3              9
#define NVIC_EXTI4              10
#define NVIC_DMA1_Channel1      11
#define NVIC_DMA1_Channel2      12
#define NVIC_DMA1_Channel3      13
#define NVIC_DMA1_Channel4      14
#define NVIC_DMA1_Channel5      15
#define NVIC_DMA1_Channel6      16
#define NVIC_DMA1_Channel7      17
#define NVIC_ADC1_2             18
#define NVIC_USB_HP_CAN_TX      19
#define NVIC_USB_LP_CAN_RX0     20
#define NVIC_CAN_RX1            21
#define NVIC_CAN_SCE            22
#define NVIC_EXTI9_5            23
#define NVIC_TIM1_BRK           24
#define NVIC_TIM1_UP            25
#define NVIC_TIM1_TRG_COM       26
#define NVIC_TIM1_CC            27
#define NVIC_TIM2               28
#define NVIC_TIM3               29
#define NVIC_TIM4               30
#define NVIC_I2C1_EV            31
#define NVIC_I2C1_ER            32
#define NVIC_I2C2_EV            33
#define NVIC_I2C2_ER            34
#define NVIC_SPI1               35
#define NVIC_SPI2               36
#define NVIC_USART1             37
#define NVIC_USART2             38
#define NVIC_USART3             39
#define NVIC_EXTI15_10          40
#define NVIC_RTCAlarm           41
#define NVIC_USBWakeup          42
#define NVIC_TIM8_BRK           43
#define NVIC_TIM8_UP            44
#define NVIC_TIM8_TRG_COM       45
#define NVIC_TIM8_CC            46
#define NVIC_ADC3               47
#define NVIC_FSMC               48
#define NVIC_SDIO               49
#define NVIC_TIM5               50
#define NVIC_SPI3               51
#define NVIC_UART4              52
#define NVIC_UART5              53
#define NVIC_TIM6               54
#define NVIC_TIM7               55
#define NVIC_DMA2_Channel1      56
#define NVIC_DMA2_Channel2      57
#define NVIC_DMA2_Channel3      58
#define NVIC_DMA2_Channel4_5    59

// Group Priority and Sub Group Priority Options
#define NVIC_GROUP_4_SUB_0                  0x05FA0300 /* 4 bits for group (IPR) => Group */
#define NVIC_GROUP_3_SUB_1                  0x05FA0400 /* 3 bits for group and 1 bit for sub priority */
#define NVIC_GROUP_2_SUB_2                  0x05FA0500 /* 2 bits for group and 2 bits for sub priority */
#define NVIC_GROUP_1_SUB_3                  0x05FA0600 /* 1 bit for group and 3 bits for sub priority */
#define NVIC_GROUP_0_SUB_4                  0x05FA0700 /* 4 bits for subpriority */


void MNVIC_voidInit(void);

u8 MNVIC_u8EnableInterrupt(u8 Copy_u8IntID);

u8 MNVIC_u8DisableInterrupt(u8 Copy_u8IntID);

u8 MNVIC_u8SetPendingFlag(u8 Copy_u8IntID);

u8 MNVIC_u8ClearPendingFlag(u8 Copy_u8IntID);

u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntID,u8* Copy_pu8FlagStatus);

u8 MNVIC_u8SetInterruptPriority(u8 Copy_u8IntID, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority);

#endif