/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 25 DEC 2022                                                                                                        */
/*  Layer       : HAL                                                                                                                */
/*  SWC         : TFT                                                                                                                */
/*  Version     : V02                                                                                                                */
/*************************************************************************************************************************************/

#ifndef TFT_CONFIG_H
#define TFT_CONFIG_H

#define TFT_A0_PIN                  GPIO_PORTA,GPIO_PIN2
#define TFT_RESET_PIN               GPIO_PORTA,GPIO_PIN0

#define TFT_COL_MOD                 RGB565

#define TFT_START_COLUMN            0
#define TFT_END_COLUMN              127

#define TFT_START_ROW               0
#define TFT_END_ROW                 159
#endif