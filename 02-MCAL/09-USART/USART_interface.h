/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 12 DEC 2022                                                                                                        */
/*  Layer       : MCAL                                                                                                               */
/*  SWC         : USART                                                                                                              */
/*  Version     : V02                                                                                                                */
/*************************************************************************************************************************************/

#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

void MUSART1_voidInit(void);

u8 MUSART1_u8TransmitDataSynch(u8 Copy_u8Data);

u8 MUSART1_u8TransmitStringSynch(char* Copy_pchString);

void MUSART1_voidTransmitArrSynch(u8* Copy_pu8Arr,u32 Copy_u32ArrSize);

u8 MUSART1_u8ReceiveDataSynch(u8 *Copy_pu8ReceivedData);

u8 MUSART1_u8ReceiveBufferSynch(u8 *Copy_pu8Buffer,u8 Copy_u8BufferSize);




#endif
