/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 8 DEC 2022                                                                                                         */
/*  Layer       : MCAL                                                                                                               */
/*  SWC         : DMA                                                                                                                */
/*  Version     : V02                                                                                                                */
/*************************************************************************************************************************************/

#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H

#define DMA_CHANNEL_1                           0
#define DMA_CHANNEL_2                           1
#define DMA_CHANNEL_3                           2
#define DMA_CHANNEL_4                           3
#define DMA_CHANNEL_5                           4
#define DMA_CHANNEL_6                           5
#define DMA_CHANNEL_7                           6

void MDMA_voidInit(void);

void MDMA_voidChannelStart(u32* Copy_pu32PeripheralAddress, u32* Copy_pu32MemoryAddress, u16 Copy_u16BlockLength, u8 Copy_u8Channel);


#endif