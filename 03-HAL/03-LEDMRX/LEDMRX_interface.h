/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 1 DEC 2022                                                                                                         */
/*  Layer       : HAL                                                                                                                */
/*  SWC         : LED MATRIX                                                                                                         */
/*  Version     : V01                                                                                                                */
/*************************************************************************************************************************************/

#ifndef LEDMRX_INTERFACE_H
#define LEDMRX_INTERFACE_H

#define LEDMRX_SPEED_LEVEL1                 2
#define LEDMRX_SPEED_LEVEL2                 3
#define LEDMRX_SPEED_LEVEL3                 4
#define LEDMRX_SPEED_LEVEL4                 5
#define LEDMRX_SPEED_LEVEL5                 10
#define LEDMRX_SPEED_LEVEL6                 15
#define LEDMRX_SPEED_LEVEL7                 20
#define LEDMRX_SPEED_LEVEL8                 30
#define LEDMRX_SPEED_LEVEL9                 50
#define LEDMRX_SPEED_LEVEL10                100
#define LEDMRX_SPEED_LEVEL11                150
#define LEDMRX_SPEED_LEVEL12                200
#define LEDMRX_SPEED_LEVEL13                255
#define LEDMRX_STOP                         256


void HLEDMRX_voidDisplayFrame(u8 *Copy_u8Frame);

void HLEDMRX_voidDisplaySentence(u8 *Copy_u8Sentence, u8 Copy_u8Length,u16 Copy_u16Speed);


#endif