/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 30 NOV 2022                                                                                                        */
/*  Layer       : MCAL                                                                                                               */
/*  SWC         : SysTick                                                                                                            */
/*  Version     : V02                                                                                                                */
/*************************************************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"

static void (*STK_pvNotifFunc)(void) = NULL;
static u8 STK_u8Periodicity = 0;

void MSTK_voidInit(void)
{
#if STK_CLK_SOURCE == CLK_AHB
    SET_BIT(STK_CTRL, STK_CTRL_CLK_SOURCE);
#elif STK_CLK_SOURCE == CLK_AHB_DIV_BY_8
    CLR_BIT(STK_CTRL, STK_CTRL_CLK_SOURCE);
#else
#error "WRONG CLK SOURCE CONFIGURATION"
#endif
}

void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_pvNotifFunc)(void))
{
    STK_pvNotifFunc = Copy_pvNotifFunc;

    STK_u8Periodicity = PERIODIC;

    STK_LOAD = Copy_u32Ticks;

    if(GET_BIT(STK_CTRL,STK_CTRL_TICK_INT)==0){
        SET_BIT(STK_CTRL,STK_CTRL_TICK_INT);
    }
    if(GET_BIT(STK_CTRL,STK_CTRL_ENABLE)==0){
        SET_BIT(STK_CTRL,STK_CTRL_ENABLE);
    }
    
}

void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks, void (*Copy_pvNotifFunc)(void))
{
    CLR_BIT(STK_CTRL,STK_CTRL_ENABLE);
    
    STK_VAL=0;

    STK_pvNotifFunc = Copy_pvNotifFunc;

    STK_u8Periodicity = SINGLE;

    STK_LOAD = Copy_u32Ticks;

    if(GET_BIT(STK_CTRL,STK_CTRL_TICK_INT)==0){
        SET_BIT(STK_CTRL,STK_CTRL_TICK_INT);
    }
    if(GET_BIT(STK_CTRL,STK_CTRL_ENABLE)==0){
        SET_BIT(STK_CTRL,STK_CTRL_ENABLE);
    }
}

void MSTK_voidSetBusyWait(u32 Copy_u32Ticks)
{
    u32 Local_u32PreviousDelay= MSTK_u32GetRemainingTime();
    STK_LOAD = Copy_u32Ticks;

    if(GET_BIT(STK_CTRL,STK_CTRL_TICK_INT)==1){
        CLR_BIT(STK_CTRL,STK_CTRL_TICK_INT);
    }

    if(GET_BIT(STK_CTRL,STK_CTRL_ENABLE)==0){
        SET_BIT(STK_CTRL,STK_CTRL_ENABLE);
    }

    while (GET_BIT(STK_CTRL, STK_CTRL_COUNT_FLAG) == 0);
    STK_VAL = 0;
    STK_LOAD = Local_u32PreviousDelay;
}

void MSTK_voidStopTimer(void)
{
    CLR_BIT(STK_CTRL, STK_CTRL_ENABLE);
}

void MSTK_voidStartTimer(void)
{
    SET_BIT(STK_CTRL, STK_CTRL_ENABLE);
}

u32 MSTK_u32GetElapsedTime(void)
{
    return (STK_LOAD - STK_VAL);
}

u32 MSTK_u32GetRemainingTime(void)
{
    return (STK_VAL);
}

void voidDisableInterrupt(void)
{
    CLR_BIT(STK_CTRL, STK_CTRL_TICK_INT);
}

void voidEnableInterrupt(void)
{
    SET_BIT(STK_CTRL, STK_CTRL_TICK_INT);
}

void SysTick_Handler(void)
{
    if (STK_pvNotifFunc != NULL)
    {
        STK_pvNotifFunc();
        if (STK_u8Periodicity == SINGLE)
        {
            STK_LOAD = 0;
            STK_VAL = 0;
        }
    }
}