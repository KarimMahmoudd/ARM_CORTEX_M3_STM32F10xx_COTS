/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 30 NOV 2022                                                                                                        */
/*  Layer       : MCAL                                                                                                               */
/*  SWC         : AFIO                                                                                                               */
/*  Version     : V01                                                                                                                */
/*************************************************************************************************************************************/

#ifndef AFIO_INTERFACE_H
#define AFIO_INTERFACE_H

#define AFIO_EXTI_LINE0                             0
#define AFIO_EXTI_LINE1                             1
#define AFIO_EXTI_LINE2                             2
#define AFIO_EXTI_LINE3                             3
#define AFIO_EXTI_LINE4                             4
#define AFIO_EXTI_LINE5                             5
#define AFIO_EXTI_LINE6                             6
#define AFIO_EXTI_LINE7                             7
#define AFIO_EXTI_LINE8                             8
#define AFIO_EXTI_LINE9                             9
#define AFIO_EXTI_LINE10                            10
#define AFIO_EXTI_LINE11                            11
#define AFIO_EXTI_LINE12                            12
#define AFIO_EXTI_LINE13                            13
#define AFIO_EXTI_LINE14                            14
#define AFIO_EXTI_LINE15                            15

#define AFIO_PORTA                                  0
#define AFIO_PORTB                                  1
#define AFIO_PORTC                                  3

u8 MAFIO_u8SetEXTIConfiguration(u8 Copy_u8Line, u8 Copy_u8Port);

#endif