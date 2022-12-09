/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 29 NOV 2022                                                                                                        */
/*  Layer       : MCAL                                                                                                               */
/*  SWC         : NVIC                                                                                                               */
/*  Version     : V01                                                                                                                */
/*************************************************************************************************************************************/

#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

#define NVIC_BASE_ADRESS 0xE000E100

#define NVIC_ISER0                               *((volatile u32 *)(NVIC_BASE_ADRESS + 0x00)) /* Enables External Interrupts from 0 to 31 */
#define NVIC_ISER1                               *((volatile u32 *)(NVIC_BASE_ADRESS + 0x04)) /* Enables External Interrupts from 32 to 63 */

#define NVIC_ICER0                               *((volatile u32 *)(NVIC_BASE_ADRESS + 0x80)) /* Disables External Interrupts from 0 to 31 */
#define NVIC_ICER1                               *((volatile u32 *)(NVIC_BASE_ADRESS + 0x84)) /* Disables External Interrupts from 32 to 63 */

#define NVIC_ISPR0                               *((volatile u32 *)(NVIC_BASE_ADRESS + 0x100)) /* Sets Pending Flags from 0 to 31 */
#define NVIC_ISPR1                               *((volatile u32 *)(NVIC_BASE_ADRESS + 0x104)) /* Sets Pending Flags from 32 to 63 */

#define NVIC_ICPR0                               *((volatile u32 *)(NVIC_BASE_ADRESS + 0x180)) /* Clears Pending Flags from 0 to 31 */
#define NVIC_ICPR1                               *((volatile u32 *)(NVIC_BASE_ADRESS + 0x184)) /* Clears Pending Flags from 32 to 63 */

#define NVIC_IABR0                               *((volatile u32 *)(NVIC_BASE_ADRESS + 0x200)) /* Read Only Registers for active flags of interrupts from 0 to 31 */
#define NVIC_IABR1                               *((volatile u32 *)(NVIC_BASE_ADRESS + 0x204)) /* Read Only Registers for active flags of interrupts from 32 to 63 */

#define NVIC_IPR                                 ((volatile u8 *)(NVIC_BASE_ADRESS + 0x300)) /* Sets the Software priority of External Interrupts */





// Group Priority and Sub Group Priority Options
#define GROUP_4_SUB_0                           0x05FA0300 /* 4 bits for group (IPR) => Group */
#define GROUP_3_SUB_1                           0x05FA0400 /* 3 bits for group and 1 bit for sub priority */
#define GROUP_2_SUB_2                           0x05FA0500 /* 2 bits for group and 2 bits for sub priority */
#define GROUP_1_SUB_3                           0x05FA0600 /* 1 bit for group and 3 bits for sub priority */
#define GROUP_0_SUB_4                           0x05FA0700 /* 4 bits for subpriority */

#endif                              