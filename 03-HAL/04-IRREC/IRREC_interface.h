/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 4 DEC 2022                                                                                                         */
/*  Layer       : HAL                                                                                                                */
/*  SWC         : IR RECEIVER                                                                                                        */
/*  Version     : V01                                                                                                                */
/*************************************************************************************************************************************/

#ifndef IRREC_INTERFACE_H
#define IRREC_INTERFACE_H


/* Buttons */
#define IRREC_CH_UP		       18
#define IRREC_CH_DOWN	       16
#define IRREC_VOL_UP	       7
#define IRREC_VOL_DOWN	       11
#define IRREC_OK		       104
#define IRREC_MUTE		       15
#define IRREC_EXIT		       45
#define IRREC_UP		       96
#define IRREC_DOWN		       97
#define IRREC_RIGHT		       98
#define IRREC_LEFT		       101
#define IRREC_HOME		       121
#define IRREC_CH_LIST	       107

void MIRREC_voidInit(void);
volatile u8* MIRREC_voidSetCallBack(void (*Copy_pvCallBackFunc)(void));

#endif
