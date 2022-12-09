/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 29 NOV 2022                                                                                                        */
/*  Layer       : MCAL                                                                                                               */
/*  SWC         : NVIC                                                                                                               */
/*  Version     : V01                                                                                                                */
/*************************************************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"


void MNVIC_voidInit(void){
    #define SCB_AIRCR                               *((volatile u32*)(0xE000ED0C)) /* Controls Priority Groups in IPR Register */
    SCB_AIRCR = NVIC_GROUP_SUB_DISTRIBURION;
}

u8 MNVIC_u8EnableInterrupt(u8 Copy_u8IntID)
{
    u8 Local_u8ErrorState = OK;

    if (Copy_u8IntID < 32)
    {
        NVIC_ISER0 = (1 << Copy_u8IntID);
    }
    else if (Copy_u8IntID < 60)
    {
        Copy_u8IntID -= 32;

        NVIC_ISER1 = (1 << Copy_u8IntID);
    }
    else
    {
        Local_u8ErrorState = NOK;
    }

    return Local_u8ErrorState;
}

u8 MNVIC_u8DisableInterrupt(u8 Copy_u8IntID)
{
    u8 Local_u8ErrorState = OK;

    if (Copy_u8IntID < 32)
    {
        NVIC_ICER0 = (1 << Copy_u8IntID);
    }
    else if (Copy_u8IntID < 60)
    {
        Copy_u8IntID -= 32;

        NVIC_ICER1 = (1 << Copy_u8IntID);
    }
    else
    {
        Local_u8ErrorState = NOK;
    }

    return Local_u8ErrorState;
}

u8 MNVIC_u8SetPendingFlag(u8 Copy_u8IntID)
{
    u8 Local_u8ErrorState = OK;

    if (Copy_u8IntID < 32)
    {
        NVIC_ISPR0 = (1 << Copy_u8IntID);
    }
    else if (Copy_u8IntID < 60)
    {
        Copy_u8IntID -= 32;

        NVIC_ISPR1 = (1 << Copy_u8IntID);
    }
    else
    {
        Local_u8ErrorState = NOK;
    }

    return Local_u8ErrorState;
}

u8 MNVIC_u8ClearPendingFlag(u8 Copy_u8IntID)
{
    u8 Local_u8ErrorState = OK;

    if (Copy_u8IntID < 32)
    {
        NVIC_ICPR0 = (1 << Copy_u8IntID);
    }
    else if (Copy_u8IntID < 60)
    {
        Copy_u8IntID -= 32;

        NVIC_ICPR1 = (1 << Copy_u8IntID);
    }
    else
    {
        Local_u8ErrorState = NOK;
    }

    return Local_u8ErrorState;
}

u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntID, u8 *Copy_pu8FlagStatus)
{
    u8 Local_u8ErrorState = OK;

    if (Copy_u8IntID < 32)
    {
        *Copy_pu8FlagStatus = GET_BIT(NVIC_IABR0, Copy_u8IntID);
    }
    else if (Copy_u8IntID < 60)
    {
        Copy_u8IntID -= 32;

        *Copy_pu8FlagStatus = GET_BIT(NVIC_IABR1, Copy_u8IntID);
    }
    else
    {
        Local_u8ErrorState = NOK;
    }

    return Local_u8ErrorState;
}

u8 MNVIC_u8SetInterruptPriority(u8 Copy_u8IntID, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority)
{
    u8 Local_u8ErrorState = OK;
    if (Copy_u8IntID <60 )
    {
        u8 Local_u8Priority = (Copy_u8SubPriority | (Copy_u8GroupPriority << ((NVIC_GROUP_SUB_DISTRIBURION - 0x05FA0300) / 256)));
        NVIC_IPR[Copy_u8IntID] = (Local_u8Priority << 4);
    }
    else
    {
        Local_u8ErrorState = NOK;
    }
    return Local_u8ErrorState;
}