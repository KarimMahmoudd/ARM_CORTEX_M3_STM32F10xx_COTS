/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 30 NOV 2022                                                                                                        */
/*  Layer       : MCAL                                                                                                               */
/*  SWC         : AFIO                                                                                                               */
/*  Version     : V01                                                                                                                */
/*************************************************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"

u8 MAFIO_u8SetEXTIConfiguration(u8 Copy_u8Line, u8 Copy_u8Port)
{
    u8 Local_u8ErrorState = OK;
    if (Copy_u8Line < 16 && Copy_u8Port < 3)
    {
        u8 Local_u8RegIndex = Copy_u8Line / 4;
        u8 Local_u8RegShift = ((Copy_u8Line % 4) * 4);

        AFIO->EXTICR[Local_u8RegIndex] &= ~((0b1111) << Local_u8RegShift);
        AFIO->EXTICR[Local_u8RegIndex] |= ((Copy_u8Port) << Local_u8RegShift);
    }
    else
    {
        Local_u8ErrorState=NOK;
    }
    return Local_u8ErrorState;
}