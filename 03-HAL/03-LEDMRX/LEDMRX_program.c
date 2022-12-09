/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 1 DEC 2022                                                                                                         */
/*  Layer       : HAL                                                                                                                */
/*  SWC         : LED MATRIX                                                                                                         */
/*  Version     : V01                                                                                                                */
/*************************************************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "LEDMRX_interface.h"
#include "LEDMRX_private.h"
#include "LEDMRX_config.h"

static PIN_t LEDMRX_u8RowPins[8] = {{LEDMRX_ROW0}, {LEDMRX_ROW1}, {LEDMRX_ROW2}, {LEDMRX_ROW3}, {LEDMRX_ROW4}, {LEDMRX_ROW5}, {LEDMRX_ROW6}, {LEDMRX_ROW7}};
static PIN_t LEDMRX_u8ColumnPins[8] = {{LEDMRX_COL0}, {LEDMRX_COL1}, {LEDMRX_COL2}, {LEDMRX_COL3}, {LEDMRX_COL4}, {LEDMRX_COL5}, {LEDMRX_COL6}, {LEDMRX_COL7}};

void HLEDMRX_voidDisplayFrame(u8 *Copy_u8Frame)
{
    u8 Local_u8Column = 0;

    /* Disable All Columns */
    DisableAllColumns();

    /* Set Values */
    for (Local_u8Column = 0; Local_u8Column < 8; Local_u8Column++)
    {
        SetColumnValues(Copy_u8Frame[Local_u8Column], Local_u8Column);
    }
}

void HLEDMRX_voidDisplaySentence(u8 *Copy_u8Sentence, u8 Copy_u8Length, u16 Copy_u16Speed)
{
    u8 Local_u8FirstIndex = 0, Local_u8Iterator = 0;
    for (Local_u8FirstIndex = 0; Local_u8FirstIndex < Copy_u8Length; Local_u8FirstIndex++)
    {
        u8 Local_u8Frame[8];
        for (Local_u8Iterator = 0; Local_u8Iterator < 8; Local_u8Iterator++)
        {
            if (Local_u8FirstIndex + Local_u8Iterator >= Copy_u8Length)
            {
                Local_u8Frame[Local_u8Iterator] = Copy_u8Sentence[(Local_u8FirstIndex + Local_u8Iterator) - Copy_u8Length];
            }
            else
            {
                Local_u8Frame[Local_u8Iterator] = Copy_u8Sentence[Local_u8FirstIndex + Local_u8Iterator];
            }
        }
        for (Local_u8Iterator = 0; Local_u8Iterator < Copy_u16Speed; Local_u8Iterator++)
        {
            HLEDMRX_voidDisplayFrame(Local_u8Frame);
        }
    }
}

static void DisableAllColumns(void)
{
    u8 Local_u8Column = 0;

    for (Local_u8Column = 0; Local_u8Column < 8; Local_u8Column++)
    {
        MGPIO_u8SetPinValue(LEDMRX_u8ColumnPins[Local_u8Column].Port, LEDMRX_u8ColumnPins[Local_u8Column].Pin, GPIO_PIN_HIGH);
    }
}

static void SetRowValues(u8 Copy_u8Value)
{
    u8 Local_u8Row = 0;
    u8 Local_u8Bit = 0;
    for (Local_u8Row = 0; Local_u8Row < 8; Local_u8Row++)
    {
        /* Get the value of the Coressponding Row and Write it while the current Column is Active */
        Local_u8Bit = GET_BIT(Copy_u8Value, Local_u8Row);
        MGPIO_u8SetPinValue(LEDMRX_u8RowPins[Local_u8Row].Port, LEDMRX_u8RowPins[Local_u8Row].Pin, Local_u8Bit);
    }
}

static void SetColumnValues(u8 Copy_u8Value, u8 Copy_u8Column)
{
    /* Set Row Values for the Current Column */
    SetRowValues(Copy_u8Value);
    /* Enable The Current Column */
    MGPIO_u8SetPinValue(LEDMRX_u8ColumnPins[Copy_u8Column].Port, LEDMRX_u8ColumnPins[Copy_u8Column].Pin, GPIO_PIN_LOW);
    /* Set Busy Waiting for For 50 FPS */
    MSTK_voidSetBusyWait(2500);
    /* Disable the Current Column */
    MGPIO_u8SetPinValue(LEDMRX_u8ColumnPins[Copy_u8Column].Port, LEDMRX_u8ColumnPins[Copy_u8Column].Pin, GPIO_PIN_HIGH);
}
