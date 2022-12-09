/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 29 NOV 2022                                                                                                        */
/*  Layer       : MCAL                                                                                                               */
/*  SWC         : EXTI                                                                                                               */
/*  Version     : V01                                                                                                                */
/*************************************************************************************************************************************/

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#define EXTI_LINE0                          0
#define EXTI_LINE1                          1
#define EXTI_LINE2                          2
#define EXTI_LINE3                          3
#define EXTI_LINE4                          4
#define EXTI_LINE5                          5
#define EXTI_LINE6                          6
#define EXTI_LINE7                          7
#define EXTI_LINE8                          8
#define EXTI_LINE9                          9
#define EXTI_LINE10                         10
#define EXTI_LINE11                         11
#define EXTI_LINE12                         12
#define EXTI_LINE13                         13
#define EXTI_LINE14                         14
#define EXTI_LINE15                         15

#define EXTI_RISING                         0
#define EXTI_FALLING                        1
#define EXTI_ON_CHANGE                      2

void MEXTI_voidInit(void);

u8 MEXTI_u8EnableLineInterrupt(u8 Copy_u8Line);

u8 MEXTI_u8DisableLineInterrupt(u8 Copy_u8Line);

u8 MEXTI_u8TriggerSoftwareInterrupt(u8 Copy_u8Line);

u8 MEXTI_u8SetSenseMode(u8 Copy_u8Line, u8 Copy_u8SenseMode);

void MEXTI_voidSetCallBack(u8 Copy_u8Line, void (*Copy_pvCallBackFunc)(void));



#endif