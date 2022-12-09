/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 23 NOV 2022                                                                                                        */
/*  SWC         : RCC                                                                                                                */
/*  Version     : V01                                                                                                                */
/*************************************************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void MRCC_voidInitSystemClock(void){
    #if RCC_SYSTEM_CLOCK==RCC_HSI
    SET_BIT(RCC_CR,RCC_CR_HSION);
    while(GET_BIT(RCC_CR,RCC_CR_HSIRDY)==0);
    //choosing hsi
    CLR_BIT(RCC_CFGR,RCC_CFGR_SW1);
    CLR_BIT(RCC_CFGR,RCC_CFGR_SW0);
    #elif RCC_SYSTEM_CLOCK==RCC_HSE_CRYSTAL
    SET_BIT(RCC_CR,RCC_CR_HSEON);
    while(GET_BIT(RCC_CR,RCC_CR_HSERDY)==0);
    //choosing HSE
    CLR_BIT(RCC_CFGR,RCC_CFGR_SW1);
    SET_BIT(RCC_CFGR,RCC_CFGR_SW0);
    #elif RCC_SYSTEM_CLOCK==RCC_HSE_RC
    SET_BIT(RCC_CR,RCC_CR_HSEBYP);
    SET_BIT(RCC_CR,RCC_CR_HSEON);
    while(GET_BIT(RCC_CR,RCC_CR_HSERDY)==0);
    //choosing HSE
    CLR_BIT(RCC_CFGR,RCC_CFGR_SW1);
    SET_BIT(RCC_CFGR,RCC_CFGR_SW0);
    #elif RCC_SYSTEM_CLOCK==RCC_PLL
    #if RCC_PLL_XTR_DIV_BY_2 == ENABLE
    SET_BIT(RCC_CFGR,RCC_CFGR_PLLXTPRE);
    #elif RCC_PLL_XTR_DIV_BY_2 == DISABLE
    CLR_BIT(RCC_CFGR,RCC_CFGR_PLLXTPRE);
    #else
    #error "WROND PLL CONFIGURATION"
    #endif
    #if RCC_PLL_SRC ==PLL_HSI_DIV_BY_2
    CLR_BIT(RCC_CFGR,RCC_CFGR_PLLSRC);
    SET_BIT(RCC_CR,RCC_CR_HSION);
    #elif RCC_PLL_SRC== PLL_HSE_CRYSTAL
    SET_BIT(RCC_CR,RCC_CR_HSEON);
    SET_BIT(RCC_CFGR,RCC_CFGR_PLLSRC);
    #elif RCC_PLL_SRC== PLL_HSE_RC
    SET_BIT(RCC_CR,RCC_CR_HSEBYP);
    SET_BIT(RCC_CR,RCC_CR_HSEON);
    SET_BIT(RCC_CFGR,RCC_CFGR_PLLSRC);
    #else
    #error "WRONG PLL SOURCE CONFIGURATION"
    #endif
    RCC_CFGR&=PLL_MUL_MASK;
    RCC_CFGR|=(RCC_PLL_MULT<<PLL_MUL_SHIFT);
    SET_BIT(RCC_CR,RCC_CR_PLLON);
    while(GET_BIT(RCC_CR,RCC_CR_PLLRDY)==0);
    SET_BIT(RCC_CFGR,RCC_CFGR_SW1);
    CLR_BIT(RCC_CFGR,RCC_CFGR_SW0);
    #else
    #error "WRONG CLOCK CONFIGURATION"
    #endif
}

u8 MRCC_u8EnableClock(u8 Copy_u8BusID,u8 Copy_u8PerID){
    u8 Local_u8ErrorState=OK;
    if(Copy_u8PerID<=31)
    {
        switch (Copy_u8BusID)
        {
        case RCC_AHB    : SET_BIT(RCC_AHBENR,Copy_u8PerID);    break;
        case RCC_APB1   : SET_BIT(RCC_APB1ENR,Copy_u8PerID);   break;
        case RCC_APB2   : SET_BIT(RCC_APB2ENR,Copy_u8PerID);   break;
        default         : Local_u8ErrorState = NOK;            break;
        }
    }
    else
    {
        //Return Error
        Local_u8ErrorState=NOK;
    }
    return Local_u8ErrorState;
}

u8 MRCC_u8DisableClock(u8 Copy_u8BusID,u8 Copy_u8PerID){
    u8 Local_u8ErrorState=OK;
    if(Copy_u8PerID<=31)
    {
        switch (Copy_u8BusID)
        {
        case RCC_AHB    : CLR_BIT(RCC_AHBENR,Copy_u8PerID);    break;
        case RCC_APB1   : CLR_BIT(RCC_APB1ENR,Copy_u8PerID);   break;
        case RCC_APB2   : CLR_BIT(RCC_APB2ENR,Copy_u8PerID);   break;
        default         : Local_u8ErrorState = NOK;            break;
        }
    }
    else
    {
        //Return Error
        Local_u8ErrorState=NOK;
    }
    return Local_u8ErrorState;
}
