/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 5 DEC 2022                                                                                                         */
/*  Layer       : SERVICES                                                                                                           */
/*  SWC         : OS                                                                                                                 */
/*  Version     : V01                                                                                                                */
/*************************************************************************************************************************************/

#ifndef OS_INTERFACE_H
#define OS_INTERFACE_H

void SOS_voidCreateTask(u8 Copy_u8ID, u16 Copy_u16Periodicity, u16 Copy_u16FirstDelay, void (*Copy_pvFunc)(void));
void SOS_voidSuspendTask(u8 Copy_u8ID);
void SOS_voidResumeTask(u8 Copy_u8ID);
void SOS_voidDeleteTask(u8 Copy_u8ID);
void SOS_voidStart(void);

#endif