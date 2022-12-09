/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 30 NOV 2022                                                                                                        */
/*  Layer       : MCAL                                                                                                               */
/*  SWC         : SysTick                                                                                                            */
/*  Version     : V02                                                                                                                */
/*************************************************************************************************************************************/

#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

#define STK_BASE_ADDRESS                        0xE000E010

#define STK_CTRL                                *(( volatile u32* )( STK_BASE_ADDRESS + 0x00 ))
#define STK_CTRL_ENABLE                         0
#define STK_CTRL_TICK_INT                       1
#define STK_CTRL_CLK_SOURCE                     2
#define STK_CTRL_COUNT_FLAG                     16

#define STK_LOAD                                *(( volatile u32* )( STK_BASE_ADDRESS + 0x04 ))
#define STK_VAL                                 *(( volatile u32* )( STK_BASE_ADDRESS + 0x08 ))
#define STK_CALIB                               *(( volatile u32* )( STK_BASE_ADDRESS + 0x0C ))


#define CLK_AHB                                 1
#define CLK_AHB_DIV_BY_8                        2


#define SINGLE                  0
#define PERIODIC                1

void voidEnableInterrupt(void);

void voidDisableInterrupt(void);

#endif