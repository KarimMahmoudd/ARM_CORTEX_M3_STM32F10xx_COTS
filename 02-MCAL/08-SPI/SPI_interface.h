/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 10 DEC 2022                                                                                                         */
/*  Layer       : MCAL                                                                                                               */
/*  SWC         : SPI                                                                                                                */
/*  Version     : V02                                                                                                                */
/*************************************************************************************************************************************/

#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

void MSPI1_voidMasterInit(void);
void MSPI1_voidSlaveInit(void);
void MSPI1_voidSynchTranscieve(u16 Copy_u16DataToSend, u16* Copy_pu16DataToReceive);
void MSPI1_voidAsynchTranscieve(u16 Copy_u16DataToSend, void (*Copy_pvNotifFunc)(u16));

#endif