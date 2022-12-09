/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 29 NOV 2022                                                                                                        */
/*  Layer       : MCAL                                                                                                               */
/*  SWC         : EXTI                                                                                                               */
/*  Version     : V01                                                                                                                */
/*************************************************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

static void (*EXTI_pvCallBackFuncs[16])(void) = {NULL};

void MEXTI_voidInit(void)
{
#if LINE0_MODE == RISING
    SET_BIT((EXTI->RTSR), LINE0);
    CLR_BIT((EXTI->FTSR), LINE0);
#elif LINE0_MODE == FALLING
    CLR_BIT((EXTI->RTSR), LINE0);
    SET_BIT((EXTI->FTSR), LINE0);
#elif LINE0_MODE == ON_CHANGE
    SET_BIT((EXTI->RTSR), LINE0);
    SET_BIT((EXTI->FTSR), LINE0);
#else
#error("WRONG LINE0 MODE CONFIGURATION")
#endif

#if LINE0_STATE == ENABLE
    SET_BIT((EXTI->IMR), LINE0);
#elif LINE0_STATE == DISABLE
    CLR_BIT((EXTI->IMR), LINE0);
#else
#error("WRONG LINE0 STATE CONFIGURATION")
#endif

#if LINE1_MODE == RISING
    SET_BIT((EXTI->RTSR), LINE1);
    CLR_BIT((EXTI->FTSR), LINE1);
#elif LINE1_MODE == FALLING
    CLR_BIT((EXTI->RTSR), LINE1);
    SET_BIT((EXTI->FTSR), LINE1);
#elif LINE1_MODE == ON_CHANGE
    SET_BIT((EXTI->RTSR), LINE1);
    SET_BIT((EXTI->FTSR), LINE1);
#else
#error("WRONG LINE1 MODE CONFIGURATION")
#endif

#if LINE1_STATE == ENABLE
    SET_BIT((EXTI->IMR), LINE1);
#elif LINE1_STATE == DISABLE
    CLR_BIT((EXTI->IMR), LINE1);
#else
#error("WRONG LINE1 STATE CONFIGURATION")
#endif

#if LINE2_MODE == RISING
    SET_BIT((EXTI->RTSR), LINE2);
    CLR_BIT((EXTI->FTSR), LINE2);
#elif LINE2_MODE == FALLING
    CLR_BIT((EXTI->RTSR), LINE2);
    SET_BIT((EXTI->FTSR), LINE2);
#elif LINE2_MODE == ON_CHANGE
    SET_BIT((EXTI->RTSR), LINE2);
    SET_BIT((EXTI->FTSR), LINE2);
#else
#error("WRONG LINE2 MODE CONFIGURATION")
#endif

#if LINE2_STATE == ENABLE
    SET_BIT((EXTI->IMR), LINE2);
#elif LINE2_STATE == DISABLE
    CLR_BIT((EXTI->IMR), LINE2);
#else
#error("WRONG LINE2 STATE CONFIGURATION")
#endif

#if LINE3_MODE == RISING
    SET_BIT((EXTI->RTSR), LINE3);
    CLR_BIT((EXTI->FTSR), LINE3);
#elif LINE3_MODE == FALLING
    CLR_BIT((EXTI->RTSR), LINE3);
    SET_BIT((EXTI->FTSR), LINE3);
#elif LINE3_MODE == ON_CHANGE
    SET_BIT((EXTI->RTSR), LINE3);
    SET_BIT((EXTI->FTSR), LINE3);
#else
#error("WRONG LINE3 MODE CONFIGURATION")
#endif

#if LINE3_STATE == ENABLE
    SET_BIT((EXTI->IMR), LINE3);
#elif LINE3_STATE == DISABLE
    CLR_BIT((EXTI->IMR), LINE3);
#else
#error("WRONG LINE3 STATE CONFIGURATION")
#endif

#if LINE4_MODE == RISING
    SET_BIT((EXTI->RTSR), LINE4);
    CLR_BIT((EXTI->FTSR), LINE4);
#elif LINE4_MODE == FALLING
    CLR_BIT((EXTI->RTSR), LINE4);
    SET_BIT((EXTI->FTSR), LINE4);
#elif LINE4_MODE == ON_CHANGE
    SET_BIT((EXTI->RTSR), LINE4);
    SET_BIT((EXTI->FTSR), LINE4);
#else
#error("WRONG LINE4 MODE CONFIGURATION")
#endif

#if LINE4_STATE == ENABLE
    SET_BIT((EXTI->IMR), LINE4);
#elif LINE4_STATE == DISABLE
    CLR_BIT((EXTI->IMR), LINE4);
#else
#error("WRONG LINE4 STATE CONFIGURATION")
#endif

#if LINE5_MODE == RISING
    SET_BIT((EXTI->RTSR), LINE5);
    CLR_BIT((EXTI->FTSR), LINE5);
#elif LINE5_MODE == FALLING
    CLR_BIT((EXTI->RTSR), LINE5);
    SET_BIT((EXTI->FTSR), LINE5);
#elif LINE5_MODE == ON_CHANGE
    SET_BIT((EXTI->RTSR), LINE5);
    SET_BIT((EXTI->FTSR), LINE5);
#else
#error("WRONG LINE5 MODE CONFIGURATION")
#endif

#if LINE5_STATE == ENABLE
    SET_BIT((EXTI->IMR), LINE5);
#elif LINE5_STATE == DISABLE
    CLR_BIT((EXTI->IMR), LINE5);
#else
#error("WRONG LINE5 STATE CONFIGURATION")
#endif

#if LINE6_MODE == RISING
    SET_BIT((EXTI->RTSR), LINE6);
    CLR_BIT((EXTI->FTSR), LINE6);
#elif LINE6_MODE == FALLING
    CLR_BIT((EXTI->RTSR), LINE6);
    SET_BIT((EXTI->FTSR), LINE6);
#elif LINE6_MODE == ON_CHANGE
    SET_BIT((EXTI->RTSR), LINE6);
    SET_BIT((EXTI->FTSR), LINE6);
#else
#error("WRONG LINE6 MODE CONFIGURATION")
#endif

#if LINE6_STATE == ENABLE
    SET_BIT((EXTI->IMR), LINE6);
#elif LINE6_STATE == DISABLE
    CLR_BIT((EXTI->IMR), LINE6);
#else
#error("WRONG LINE6 STATE CONFIGURATION")
#endif

#if LINE7_MODE == RISING
    SET_BIT((EXTI->RTSR), LINE7);
    CLR_BIT((EXTI->FTSR), LINE7);
#elif LINE7_MODE == FALLING
    CLR_BIT((EXTI->RTSR), LINE7);
    SET_BIT((EXTI->FTSR), LINE7);
#elif LINE7_MODE == ON_CHANGE
    SET_BIT((EXTI->RTSR), LINE7);
    SET_BIT((EXTI->FTSR), LINE7);
#else
#error("WRONG LINE7 MODE CONFIGURATION")
#endif

#if LINE7_STATE == ENABLE
    SET_BIT((EXTI->IMR), LINE7);
#elif LINE7_STATE == DISABLE
    CLR_BIT((EXTI->IMR), LINE7);
#else
#error("WRONG LINE7 STATE CONFIGURATION")
#endif

#if LINE8_MODE == RISING
    SET_BIT((EXTI->RTSR), LINE8);
    CLR_BIT((EXTI->FTSR), LINE8);
#elif LINE8_MODE == FALLING
    CLR_BIT((EXTI->RTSR), LINE8);
    SET_BIT((EXTI->FTSR), LINE8);
#elif LINE8_MODE == ON_CHANGE
    SET_BIT((EXTI->RTSR), LINE8);
    SET_BIT((EXTI->FTSR), LINE8);
#else
#error("WRONG LINE8 MODE CONFIGURATION")
#endif

#if LINE8_STATE == ENABLE
    SET_BIT((EXTI->IMR), LINE8);
#elif LINE8_STATE == DISABLE
    CLR_BIT((EXTI->IMR), LINE8);
#else
#error("WRONG LINE8 STATE CONFIGURATION")
#endif

#if LINE9_MODE == RISING
    SET_BIT((EXTI->RTSR), LINE9);
    CLR_BIT((EXTI->FTSR), LINE9);
#elif LINE9_MODE == FALLING
    CLR_BIT((EXTI->RTSR), LINE9);
    SET_BIT((EXTI->FTSR), LINE9);
#elif LINE9_MODE == ON_CHANGE
    SET_BIT((EXTI->RTSR), LINE9);
    SET_BIT((EXTI->FTSR), LINE9);
#else
#error("WRONG LINE9 MODE CONFIGURATION")
#endif

#if LINE9_STATE == ENABLE
    SET_BIT((EXTI->IMR), LINE9);
#elif LINE9_STATE == DISABLE
    CLR_BIT((EXTI->IMR), LINE9);
#else
#error("WRONG LINE9 STATE CONFIGURATION")
#endif

#if LINE10_MODE == RISING
    SET_BIT((EXTI->RTSR), LINE10);
    CLR_BIT((EXTI->FTSR), LINE10);
#elif LINE10_MODE == FALLING
    CLR_BIT((EXTI->RTSR), LINE10);
    SET_BIT((EXTI->FTSR), LINE10);
#elif LINE10_MODE == ON_CHANGE
    SET_BIT((EXTI->RTSR), LINE10);
    SET_BIT((EXTI->FTSR), LINE10);
#else
#error("WRONG LINE10 MODE CONFIGURATION")
#endif

#if LINE10_STATE == ENABLE
    SET_BIT((EXTI->IMR), LINE10);
#elif LINE10_STATE == DISABLE
    CLR_BIT((EXTI->IMR), LINE10);
#else
#error("WRONG LINE10 STATE CONFIGURATION")
#endif

#if LINE11_MODE == RISING
    SET_BIT((EXTI->RTSR), LINE11);
    CLR_BIT((EXTI->FTSR), LINE11);
#elif LINE11_MODE == FALLING
    CLR_BIT((EXTI->RTSR), LINE11);
    SET_BIT((EXTI->FTSR), LINE11);
#elif LINE11_MODE == ON_CHANGE
    SET_BIT((EXTI->RTSR), LINE11);
    SET_BIT((EXTI->FTSR), LINE11);
#else
#error("WRONG LINE11 MODE CONFIGURATION")
#endif

#if LINE11_STATE == ENABLE
    SET_BIT((EXTI->IMR), LINE11);
#elif LINE11_STATE == DISABLE
    CLR_BIT((EXTI->IMR), LINE11);
#else
#error("WRONG LINE11 STATE CONFIGURATION")
#endif

#if LINE12_MODE == RISING
    SET_BIT((EXTI->RTSR), LINE12);
    CLR_BIT((EXTI->FTSR), LINE12);
#elif LINE12_MODE == FALLING
    CLR_BIT((EXTI->RTSR), LINE12);
    SET_BIT((EXTI->FTSR), LINE12);
#elif LINE12_MODE == ON_CHANGE
    SET_BIT((EXTI->RTSR), LINE12);
    SET_BIT((EXTI->FTSR), LINE12);
#else
#error("WRONG LINE12 MODE CONFIGURATION")
#endif

#if LINE12_STATE == ENABLE
    SET_BIT((EXTI->IMR), LINE12);
#elif LINE12_STATE == DISABLE
    CLR_BIT((EXTI->IMR), LINE12);
#else
#error("WRONG LINE12 STATE CONFIGURATION")
#endif

#if LINE13_MODE == RISING
    SET_BIT((EXTI->RTSR), LINE13);
    CLR_BIT((EXTI->FTSR), LINE13);
#elif LINE13_MODE == FALLING
    CLR_BIT((EXTI->RTSR), LINE13);
    SET_BIT((EXTI->FTSR), LINE13);
#elif LINE13_MODE == ON_CHANGE
    SET_BIT((EXTI->RTSR), LINE13);
    SET_BIT((EXTI->FTSR), LINE13);
#else
#error("WRONG LINE13 MODE CONFIGURATION")
#endif

#if LINE13_STATE == ENABLE
    SET_BIT((EXTI->IMR), LINE13);
#elif LINE13_STATE == DISABLE
    CLR_BIT((EXTI->IMR), LINE13);
#else
#error("WRONG LINE13 STATE CONFIGURATION")
#endif

#if LINE14_MODE == RISING
    SET_BIT((EXTI->RTSR), LINE14);
    CLR_BIT((EXTI->FTSR), LINE14);
#elif LINE14_MODE == FALLING
    CLR_BIT((EXTI->RTSR), LINE13);
    SET_BIT((EXTI->FTSR), LINE13);
#elif LINE14_MODE == ON_CHANGE
    SET_BIT((EXTI->RTSR), LINE13);
    SET_BIT((EXTI->FTSR), LINE13);
#else
#error("WRONG LINE14 MODE CONFIGURATION")
#endif

#if LINE14_STATE == ENABLE
    SET_BIT((EXTI->IMR), LINE14);
#elif LINE14_STATE == DISABLE
    CLR_BIT((EXTI->IMR), LINE14);
#else
#error("WRONG LINE14 STATE CONFIGURATION")
#endif

#if LINE15_MODE == RISING
    SET_BIT((EXTI->RTSR), LINE15);
    CLR_BIT((EXTI->FTSR), LINE15);
#elif LINE15_MODE == FALLING
    CLR_BIT((EXTI->RTSR), LINE15);
    SET_BIT((EXTI->FTSR), LINE15);
#elif LINE15_MODE == ON_CHANGE
    SET_BIT((EXTI->RTSR), LINE15);
    SET_BIT((EXTI->FTSR), LINE15);
#else
#error("WRONG LINE15 MODE CONFIGURATION")
#endif

#if LINE15_STATE == ENABLE
    SET_BIT((EXTI->IMR), LINE15);
#elif LINE15_STATE == DISABLE
    CLR_BIT((EXTI->IMR), LINE15);
#else
#error("WRONG LINE15 STATE CONFIGURATION")
#endif
}

u8 MEXTI_u8EnableLineInterrupt(u8 Copy_u8Line)
{
    u8 Local_u8ErrorState = OK;
    if (Copy_u8Line < 16)
    {
        SET_BIT((EXTI->IMR), Copy_u8Line);
    }
    else
    {
        Local_u8ErrorState = NOK;
    }
    return Local_u8ErrorState;
}

u8 MEXTI_u8DisableLineInterrupt(u8 Copy_u8Line)
{
    u8 Local_u8ErrorState = OK;
    if (Copy_u8Line < 16)
    {
        CLR_BIT((EXTI->IMR), Copy_u8Line);
    }
    else
    {
        Local_u8ErrorState = NOK;
    }
    return Local_u8ErrorState;
}

u8 MEXTI_u8TriggerSoftwareInterrupt(u8 Copy_u8Line)
{
    u8 Local_u8ErrorState = OK;
    if (Copy_u8Line < 16)
    {
        SET_BIT((EXTI->SWIER), Copy_u8Line);
    }
    else
    {
        Local_u8ErrorState = NOK;
    }
    return Local_u8ErrorState;
}

u8 MEXTI_u8SetSenseMode(u8 Copy_u8Line, u8 Copy_u8SenseMode)
{
    u8 Local_u8ErrorState = OK;
    switch (Copy_u8SenseMode)
    {
    case EXTI_RISING:
        SET_BIT((EXTI->RTSR), Copy_u8Line);
        CLR_BIT((EXTI->FTSR), Copy_u8Line);
        break;

    case EXTI_FALLING:
        CLR_BIT((EXTI->RTSR), Copy_u8Line);
        SET_BIT((EXTI->FTSR), Copy_u8Line);
        break;

    case EXTI_ON_CHANGE:
        SET_BIT((EXTI->RTSR), Copy_u8Line);
        SET_BIT((EXTI->FTSR), Copy_u8Line);
        break;

    default:
        Local_u8ErrorState = NOK;
        break;
    }

    return Local_u8ErrorState;
}

void MEXTI_voidSetCallBack(u8 Copy_u8Line, void (*Copy_pvCallBackFunc)(void))
{
    EXTI_pvCallBackFuncs[Copy_u8Line] = Copy_pvCallBackFunc;
}

void EXTI0_IRQHandler(void)
{
    if (EXTI_pvCallBackFuncs[LINE0] != 0)
    {
        EXTI_pvCallBackFuncs[LINE0]();
    }
    SET_BIT((EXTI->PR), LINE0);
}

void EXTI1_IRQHandler(void)
{
    if (EXTI_pvCallBackFuncs[LINE1] != 0)
    {
        EXTI_pvCallBackFuncs[LINE1]();
    }
    SET_BIT((EXTI->PR), LINE1);
}

void EXTI2_IRQHandler(void)
{
    if (EXTI_pvCallBackFuncs[LINE2] != 0)
    {
        EXTI_pvCallBackFuncs[LINE2]();
    }
    SET_BIT((EXTI->PR), LINE2);
}

void EXTI3_IRQHandler(void)
{
    if (EXTI_pvCallBackFuncs[LINE3] != 0)
    {
        EXTI_pvCallBackFuncs[LINE3]();
    }
    SET_BIT((EXTI->PR), LINE3);
}

void EXTI4_IRQHandler(void)
{
    if (EXTI_pvCallBackFuncs[LINE4] != 0)
    {
        EXTI_pvCallBackFuncs[LINE4]();
    }
    SET_BIT((EXTI->PR), LINE4);
}

void EXTI9_5_IRQHandler(void)
{
        if (GET_BIT((EXTI->PR), LINE5) == 1)
    {
        if (EXTI_pvCallBackFuncs[LINE5] != 0)
        {
            EXTI_pvCallBackFuncs[LINE5]();
        }
        SET_BIT((EXTI->PR), LINE5);
    }

        if (GET_BIT((EXTI->PR), LINE6) == 1)
    {
        if (EXTI_pvCallBackFuncs[LINE6] != 0)
        {
            EXTI_pvCallBackFuncs[LINE6]();
        }
        SET_BIT((EXTI->PR), LINE6);
    }

        if (GET_BIT((EXTI->PR), LINE7) == 1)
    {
        if (EXTI_pvCallBackFuncs[LINE7] != 0)
        {
            EXTI_pvCallBackFuncs[LINE7]();
        }
        SET_BIT((EXTI->PR), LINE7);
    }

        if (GET_BIT((EXTI->PR), LINE8) == 1)
    {
        if (EXTI_pvCallBackFuncs[LINE8] != 0)
        {
            EXTI_pvCallBackFuncs[LINE8]();
        }
        SET_BIT((EXTI->PR), LINE8);
    }

    if (GET_BIT((EXTI->PR), LINE9) == 1)
    {
        if (EXTI_pvCallBackFuncs[LINE9] != 0)
        {
            EXTI_pvCallBackFuncs[LINE9]();
        }
        SET_BIT((EXTI->PR), LINE9);
    }
}

void EXTI15_10_IRQHandler(void)
{
       if (GET_BIT((EXTI->PR), LINE10) == 1)
    {
        if (EXTI_pvCallBackFuncs[LINE10] != 0)
        {
            EXTI_pvCallBackFuncs[LINE10]();
        }
        SET_BIT((EXTI->PR), LINE10);
    }

        if (GET_BIT((EXTI->PR), LINE11) == 1)
    {
        if (EXTI_pvCallBackFuncs[LINE11] != 0)
        {
            EXTI_pvCallBackFuncs[LINE11]();
        }
        SET_BIT((EXTI->PR), LINE11);
    }
    
        if (GET_BIT((EXTI->PR), LINE12) == 1)
    {
        if (EXTI_pvCallBackFuncs[LINE12] != 0)
        {
            EXTI_pvCallBackFuncs[LINE12]();
        }
        SET_BIT((EXTI->PR), LINE12);
    }

        if (GET_BIT((EXTI->PR), LINE13) == 1)
    {
        if (EXTI_pvCallBackFuncs[LINE13] != 0)
        {
            EXTI_pvCallBackFuncs[LINE13]();
        }
        SET_BIT((EXTI->PR), LINE13);
    }

        if (GET_BIT((EXTI->PR), LINE14) == 1)
    {
        if (EXTI_pvCallBackFuncs[LINE14] != 0)
        {
            EXTI_pvCallBackFuncs[LINE14]();
        }
        SET_BIT((EXTI->PR), LINE14);
    }

        if (GET_BIT((EXTI->PR), LINE15) == 1)
    {
        if (EXTI_pvCallBackFuncs[LINE15] != 0)
        {
            EXTI_pvCallBackFuncs[LINE15]();
        }
        SET_BIT((EXTI->PR), LINE15);
    }
}