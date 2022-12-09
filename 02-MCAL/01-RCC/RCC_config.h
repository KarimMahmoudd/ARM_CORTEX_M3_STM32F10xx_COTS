/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 23 NOV 2022                                                                                                        */
/*  SWC         : RCC                                                                                                                */
/*  Version     : V01                                                                                                                */
/*************************************************************************************************************************************/

#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/*Options:          1- RCC_HSE_CRYSTAL
                    2- RCC_HSE_RC
                    3- RCC_HSI
                    4- RCC_PLL                                */
#define RCC_SYSTEM_CLOCK            RCC_HSE_CRYSTAL

#if RCC_SYSTEM_CLOCK == RCC_PLL

/*Options:          1- PLL_HSE_CRYSTAL
                    2- PLL_HSE_RC
                    3- PLL_HSI_DIV_BY_2
                                                               */
#define RCC_PLL_SRC                 PLL_HSI_DIV_BY_2
/* Options:             1-ENABLE
                        2-DISABLE
                                                                 */
#define RCC_PLL_XTR_DIV_BY_2        ENABLE

/*Options:          1-  MULT_BY_2
                    2-  MULT_BY_3
                    3-  MULT_BY_4
                    4-  MULT_BY_5
                    5-  MULT_BY_6
                    6-  MULT_BY_7
                    7-  MULT_BY_8
                    8-  MULT_BY_9
                    9-  MULT_BY_10
                    10- MULT_BY_11
                    11- MULT_BY_12
                    12- MULT_BY_13
                    13- MULT_BY_14
                    14- MULT_BY_15
                    15- MULT_BY_16
                                                                */
#define RCC_PLL_MULT                            MULT_BY_2

#endif

#endif