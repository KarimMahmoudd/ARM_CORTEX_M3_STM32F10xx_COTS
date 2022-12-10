/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 9 DEC 2022                                                                                                         */
/*  Layer       : HAL                                                                                                                */
/*  SWC         : STP                                                                                                                */
/*  Version     : V01                                                                                                                */
/*************************************************************************************************************************************/

#ifndef STP_INTERFACE_H
#define STP_INTERFACE_H

void HSTP_voidReset(void);
void HSTP_voidSendSynchronous(u32 Copy_u32Data,u8 Copy_u8DataLength);

#endif