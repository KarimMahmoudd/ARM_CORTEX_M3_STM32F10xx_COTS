/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 25 DEC 2022                                                                                                        */
/*  Layer       : HAL                                                                                                                */
/*  SWC         : TFT                                                                                                                */
/*  Version     : V02                                                                                                                */
/*************************************************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MATH_HELPER.h"

#include "GPIO_interface.h"
#include "SPI_interface.h"
#include "STK_interface.h"

#include "TFT_interface.h"
#include "TFT_private.h"
#include "TFT_config.h"

void HTFT_voidInit(void)
{
    /* Start Pulse */
    MGPIO_u8SetPinValue(TFT_RESET_PIN, GPIO_PIN_HIGH);
    MSTK_voidSetBusyWait(100);
    MGPIO_u8SetPinValue(TFT_RESET_PIN, GPIO_PIN_LOW);
    MSTK_voidSetBusyWait(1);
    MGPIO_u8SetPinValue(TFT_RESET_PIN, GPIO_PIN_HIGH);
    MSTK_voidSetBusyWait(100);
    MGPIO_u8SetPinValue(TFT_RESET_PIN, GPIO_PIN_LOW);
    MSTK_voidSetBusyWait(100);
    MGPIO_u8SetPinValue(TFT_RESET_PIN, GPIO_PIN_HIGH);
    MSTK_voidSetBusyWait(120000);
    /* Sleep Out Command */
    voidSendCommand(CMD_SLPOUT);
    MSTK_voidSetBusyWait(150000);

    /* Choosing Color Mode */
    voidSendCommand(CMD_COLMOD);
    voidSendData(TFT_COL_MOD);

    /* Set Display On */
    voidSendCommand(CMD_DISPON);
}

void HTFT_voidDisplayImage(const u16 *Copy_pu16Image)
{
    u32 Local_u32Counter;

    voidSetBoundaries(TFT_START_COLUMN, TFT_END_COLUMN, TFT_START_ROW, TFT_END_ROW);

    /* Writing Data */
    voidSendCommand(CMD_RAMWR);

    for (Local_u32Counter = 0; Local_u32Counter < 20480; Local_u32Counter++)
    {
        voidFillPixel(Copy_pu16Image[Local_u32Counter]);
    }
}

void HTFT_voidFillColor(u16 Copy_u16Color)
{
    u32 Local_u32Counter;

    voidSetBoundaries(TFT_START_COLUMN, TFT_END_COLUMN, TFT_START_ROW, TFT_END_ROW);

    /* Writing Data */
    voidSendCommand(CMD_RAMWR);

    for (Local_u32Counter = 0; Local_u32Counter < 20480; Local_u32Counter++)
    {
        voidFillPixel(Copy_u16Color);
    }
}

void HTFT_voidDrawRectangle(u16 Copy_u16StartColumn, u16 Copy_u16EndColumn, u16 Copy_u16StartRow, u16 Copy_u16EndRow, u16 Copy_u16Color)
{
    u32 Local_u32Counter;
    u16 Local_u16Limit = (Copy_u16EndColumn - Copy_u16StartColumn + 1) * (Copy_u16EndRow - Copy_u16StartRow + 1);

    voidSetBoundaries(Copy_u16StartColumn, Copy_u16EndColumn, Copy_u16StartRow, Copy_u16EndRow);
    /* Writing Data */
    voidSendCommand(CMD_RAMWR);

    for (Local_u32Counter = 0; Local_u32Counter < Local_u16Limit; Local_u32Counter++)
    {
        voidFillPixel(Copy_u16Color);
    }
}

void HTFT_voidDrawCharacter(char Copy_Character, u16 Copy_u16CharColor, u16 Copy_u16BackGroundColor, u16 Copy_u16StartColumn, u16 Copy_u16StartRow)
{
    s8 Local_s8Line, Local_s8Pixel;
    u8 Local_u8ColorDecision;
    voidSetBoundaries(Copy_u16StartColumn, Copy_u16StartColumn + 7, Copy_u16StartRow, Copy_u16StartRow + 7);
    /* Writing Data */
    voidSendCommand(CMD_RAMWR);

    for (Local_s8Line = 7; Local_s8Line >= 0; Local_s8Line--)
    {
        for (Local_s8Pixel = 0; Local_s8Pixel < 8; Local_s8Pixel++)
        {
            Local_u8ColorDecision = GET_BIT(ASCII[(u8)Copy_Character][Local_s8Line], Local_s8Pixel);
            if (Local_u8ColorDecision == 0)
            {
                voidFillPixel(Copy_u16BackGroundColor);
            }
            else if (Local_u8ColorDecision == 1)
            {
                voidFillPixel(Copy_u16CharColor);
            }
        }
    }
}

void HTFT_voidDrawString(char *Copy_String, u16 Copy_u16StrColor, u16 Copy_u16BackGroundColor, u16 Copy_u16StartColumn, u16 Copy_u16StartRow)
{
    s8 Local_s8CharIndex = 0;
    u8 Local_s8StrLength = 0;
    while (Copy_String[Local_s8StrLength] != '\0')
    {
        Local_s8StrLength++;
    }
    for (Local_s8CharIndex = Local_s8StrLength - 1; Local_s8CharIndex >= 0; Local_s8CharIndex--)
    {
        HTFT_voidDrawCharacter(Copy_String[Local_s8StrLength - Local_s8CharIndex - 1], Copy_u16StrColor, Copy_u16BackGroundColor, Copy_u16StartColumn + (8 * Local_s8CharIndex), Copy_u16StartRow);
    }
}

void HTFT_voidDrawNumber(u32 Copy_u32Number, u16 Copy_u16NumColor, u16 Copy_u16BackGroundColor, u16 Copy_u16StartColumn, u16 Copy_u16StartRow)
{
    /*set local variables to know the number of digits and the digit to print*/
    u8 Local_u8Quotient = 1;
    u8 Local_u8NumOfDigits = 0;
    u8 Local_u8Digit;
    /*calculating the number of digits in the number*/
    while (Local_u8Quotient != 0)
    {
        Local_u8Quotient = Copy_u32Number / MATH_u32Power(10, ++Local_u8NumOfDigits);
    }
    /*separating each digit then sending then sending them separately to the CLCD*/
    for (s8 Local_s8Power = Local_u8NumOfDigits - 1; Local_s8Power >= 0; Local_s8Power--)
    {
        Local_u8Digit = Copy_u32Number / MATH_u32Power(10, Local_s8Power);
        Copy_u32Number %= MATH_u32Power(10, Local_s8Power);
        HTFT_voidDrawCharacter((char)Local_u8Digit, Copy_u16NumColor, Copy_u16BackGroundColor, Copy_u16StartColumn + (8 * Local_s8Power), Copy_u16StartRow);
    }
}

static void voidFillPixel(u16 Copy_u16Color)
{
    u8 Local_u8HighByte = (u8)(Copy_u16Color >> 8);
    u8 Local_u8LowByte = (u8)Copy_u16Color;

    voidSendData(Local_u8HighByte);
    voidSendData(Local_u8LowByte);
}

static void voidSetBoundaries(u16 Copy_u16StartColumn, u16 Copy_u16EndColumn, u16 Copy_u16StartRow, u16 Copy_u16EndRow)
{
    /* Configure the Start and End Values of X-Coordinate */
    voidSendCommand(CMD_CASET);
    voidSendData((u8)(Copy_u16StartColumn >> 8));
    voidSendData((u8)Copy_u16StartColumn);
    voidSendData((u8)(Copy_u16EndColumn >> 8));
    voidSendData((u8)Copy_u16EndColumn);

    /* Configure the Start and End Values of Y-Coordinate */
    voidSendCommand(CMD_RASET);
    voidSendData((u8)(Copy_u16StartRow >> 8));
    voidSendData((u8)Copy_u16StartRow);
    voidSendData((u8)(Copy_u16EndRow >> 8));
    voidSendData((u8)Copy_u16EndRow);
}
static void voidSendCommand(u8 Copy_u8Command)
{
    u16 Local_u16Garbage;
    MGPIO_u8SetPinValue(TFT_A0_PIN, GPIO_PIN_LOW);

    MSPI1_voidSynchTranscieve((u16)Copy_u8Command, &Local_u16Garbage);
}

static void voidSendData(u8 Copy_u8Data)
{
    u16 Local_u16Garbage;
    MGPIO_u8SetPinValue(TFT_A0_PIN, GPIO_PIN_HIGH);

    MSPI1_voidSynchTranscieve((u16)Copy_u8Data, &Local_u16Garbage);
}
