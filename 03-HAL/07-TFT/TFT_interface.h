/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 25 DEC 2022                                                                                                        */
/*  Layer       : HAL                                                                                                                */
/*  SWC         : TFT                                                                                                                */
/*  Version     : V02                                                                                                                */
/*************************************************************************************************************************************/

#ifndef TFT_INTERFACE_H
#define TFT_INTERFACE_H

#define TFT_BLACK                   0
#define TFT_WHITE                   0xffff
#define TFT_RED                     0xf800
#define TFT_GREEN                   0x07e0
#define TFT_BLUE                    0x001f
#define TFT_DARK_BLUE				0x000b
#define TFT_PURPLE					0x7970
#define TFT_LIGHT_GREEN				0x7ed0
#define TFT_PALE_YELLOW				0xefb5
#define TFT_LIGHT_BLUE				0x077f



void HTFT_voidInit(void);
void HTFT_voidDisplayImage(const u16* Copy_pu16Image);
void HTFT_voidFillColor(u16 Copy_u16Color);
void HTFT_voidDrawRectangle(u16 Copy_u16StartColumn,u16 Copy_u16EndColumn,u16 Copy_u16StartRow,u16 Copy_u16EndRow,u16 Copy_u16Color);
void HTFT_voidDrawCharacter(char Copy_Character,u16 Copy_u16CharColor,u16 Copy_u16BackGroundColor,u16 Copy_u16StartColumn,u16 Copy_u16StartRow);
void HTFT_voidDrawString(char* Copy_String, u16 Copy_u16StrColor, u16 Copy_u16BackGroundColor,u16 Copy_u16StartColumn, u16 Copy_u16StartRow);
void HTFT_voidDrawNumber(u32 Copy_u32Number,u16 Copy_u16NumColor,u16 Copy_u16BackGroundColor,u16 Copy_u16StartColumn,u16 Copy_u16StartRow);

#endif