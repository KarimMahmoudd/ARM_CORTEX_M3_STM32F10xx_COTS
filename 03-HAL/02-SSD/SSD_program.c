/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 25 NOV 2022                                                                                                        */
/*  Layer       : HAL                                                                                                                */
/*  SWC         : SSD                                                                                                                */
/*  Version     : V01                                                                                                                */
/*************************************************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "SSD_interface.h"
#include "SSD_config.h"
#include "SSD_private.h"

u8 HSSD_u8SetNumber(SSD_t *Copy_SSD, u8 Copy_u8Number)
{
    u8 Local_u8ErrorState = OK;
    if (Copy_SSD != NULL)
    {
        if (Copy_SSD->CommonType == COMMON_CATHODE)
        {
            GPIO_u8SetPinValue(Copy_SSD->A.Port, Copy_SSD->A.Pin, GET_BIT(SevenSegArray[Copy_u8Number], 0));
            GPIO_u8SetPinValue(Copy_SSD->B.Port, Copy_SSD->B.Pin, GET_BIT(SevenSegArray[Copy_u8Number], 1));
            GPIO_u8SetPinValue(Copy_SSD->C.Port, Copy_SSD->C.Pin, GET_BIT(SevenSegArray[Copy_u8Number], 2));
            GPIO_u8SetPinValue(Copy_SSD->D.Port, Copy_SSD->D.Pin, GET_BIT(SevenSegArray[Copy_u8Number], 3));
            GPIO_u8SetPinValue(Copy_SSD->E.Port, Copy_SSD->E.Pin, GET_BIT(SevenSegArray[Copy_u8Number], 4));
            GPIO_u8SetPinValue(Copy_SSD->F.Port, Copy_SSD->F.Pin, GET_BIT(SevenSegArray[Copy_u8Number], 5));
            GPIO_u8SetPinValue(Copy_SSD->G.Port, Copy_SSD->G.Pin, GET_BIT(SevenSegArray[Copy_u8Number], 6));
        }
        else if (Copy_SSD->CommonType == COMMON_ANODE)
        {
            GPIO_u8SetPinValue(Copy_SSD->A.Port, Copy_SSD->A.Pin, ~(GET_BIT(SevenSegArray[Copy_u8Number], 0)));
            GPIO_u8SetPinValue(Copy_SSD->B.Port, Copy_SSD->B.Pin, ~(GET_BIT(SevenSegArray[Copy_u8Number], 1)));
            GPIO_u8SetPinValue(Copy_SSD->C.Port, Copy_SSD->C.Pin, ~(GET_BIT(SevenSegArray[Copy_u8Number], 2)));
            GPIO_u8SetPinValue(Copy_SSD->D.Port, Copy_SSD->D.Pin, ~(GET_BIT(SevenSegArray[Copy_u8Number], 3)));
            GPIO_u8SetPinValue(Copy_SSD->E.Port, Copy_SSD->E.Pin, ~(GET_BIT(SevenSegArray[Copy_u8Number], 4)));
            GPIO_u8SetPinValue(Copy_SSD->F.Port, Copy_SSD->F.Pin, ~(GET_BIT(SevenSegArray[Copy_u8Number], 5)));
            GPIO_u8SetPinValue(Copy_SSD->G.Port, Copy_SSD->G.Pin, ~(GET_BIT(SevenSegArray[Copy_u8Number], 6)));
        }
        else
        {
            Local_u8ErrorState = NOK;
        }
    }
    else
    {
        Local_u8ErrorState = NULL_POINTER;
    }
    return Local_u8ErrorState;
}
u8 HSSD_u8Enable(SSD_t *Copy_SSD)
{
    u8 Local_u8ErrorState = OK;
    if (Copy_SSD != NULL)
    {
        if (Copy_SSD->CommonType == COMMON_CATHODE)
        {
            GPIO_u8SetPinValue(Copy_SSD->Common.Port, Copy_SSD->Common.Pin, GPIO_PIN_LOW);
        }
        else if (Copy_SSD->CommonType == COMMON_ANODE)
        {
            GPIO_u8SetPinValue(Copy_SSD->Common.Port, Copy_SSD->Common.Pin, GPIO_PIN_HIGH);
        }
    }
    else
    {
        Local_u8ErrorState = NULL_POINTER;
    }
    return Local_u8ErrorState;
}

u8 HSSD_u8Disable(SSD_t *Copy_SSD)
{
    u8 Local_u8ErrorState = OK;
    if (Copy_SSD != NULL)
    {
        if (Copy_SSD->CommonType == COMMON_CATHODE)
        {
            GPIO_u8SetPinValue(Copy_SSD->Common.Port, Copy_SSD->Common.Pin, GPIO_PIN_HIGH);
        }
        else if (Copy_SSD->CommonType == COMMON_ANODE)
        {
            GPIO_u8SetPinValue(Copy_SSD->Common.Port, Copy_SSD->Common.Pin, GPIO_PIN_LOW);
        }
    }
    else
    {
        Local_u8ErrorState = NULL_POINTER;
    }
    return Local_u8ErrorState;
}