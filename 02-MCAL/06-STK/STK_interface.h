/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 30 NOV 2022                                                                                                        */
/*  Layer       : MCAL                                                                                                               */
/*  SWC         : SysTick                                                                                                            */
/*  Version     : V02                                                                                                                */
/*************************************************************************************************************************************/

#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H



void MSTK_voidInit(void);

void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_pvNotifFunc)(void));

void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks, void (*Copy_pvNotifFunc)(void));

void MSTK_voidSetBusyWait(u32 Copy_u32Ticks);

void MSTK_voidStartTimer(void);

void MSTK_voidStopTimer(void);

u32 MSTK_u32GetElapsedTime(void);

u32 MSTK_u32GetRemainingTime(void);

#endif