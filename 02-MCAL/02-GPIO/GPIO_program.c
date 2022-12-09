/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 25 NOV 2022                                                                                                        */
/*  Layer       : MCAL                                                                                                               */
/*  SWC         : GPIO                                                                                                               */
/*  Version     : V01                                                                                                                */
/*************************************************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_config.h"
#include "GPIO_private.h"

void MPORT_voidInit(void)
{
    /* Initializing port A direction */
    GPIOA_CRL = PORTA_DIR_L;
    GPIOA_CRH = PORTA_DIR_H;

    /* Initializing Port B Direction */
    GPIOB_CRL = PORTB_DIR_L;
    GPIOB_CRH = PORTB_DIR_H;

    /* Initializing Port C Direction */
    GPIOC_CRL = PORTC_DIR_L;
    GPIOC_CRH = PORTC_DIR_H;

    /* Initializing Values for the three ports */
    GPIOA_ODR = PORTA_INIT_VAL;
    GPIOB_ODR = PORTB_INIT_VAL;
    GPIOC_ODR = PORTC_INIT_VAL;
}

u8 MGPIO_u8SetPinMode(u8 Copy_u8Port, u8 Copy_u8Pin, u32 Copy_u32Mode)
{
    u8 Local_u8ErrorState = OK;
    u32 Local_u32ModeMask;
    if (Copy_u8Pin <= 7)
    {
        /* Initializing Bit Mask */
        Local_u32ModeMask = (0xf << (Copy_u8Pin * 4));
        Local_u32ModeMask = ~(Local_u32ModeMask);
        /* Shifting the mode to its place in the register */
        Copy_u32Mode = (Copy_u32Mode << (Copy_u8Pin * 4));
        switch (Copy_u8Port)
        {
        case GPIO_PORTA:
            GPIOA_CRL &= Local_u32ModeMask;
            GPIOA_CRL |= (Copy_u32Mode);
            break;
        case GPIO_PORTB:
            GPIOB_CRL &= Local_u32ModeMask;
            GPIOB_CRL |= (Copy_u32Mode);
            break;
        case GPIO_PORTC:
            GPIOC_CRL &= Local_u32ModeMask;
            GPIOC_CRL |= (Copy_u32Mode);
            break;
        default:
            Local_u8ErrorState = NOK;
            break;
        }
    }
    else if (Copy_u8Pin > 7 && Copy_u8Pin <= 15)
    {
        /* Initializing Bit Mask */
        Local_u32ModeMask = (0xf << ((Copy_u8Pin - 8) * 4));
        Local_u32ModeMask = ~(Local_u32ModeMask);
        /* Shifting the mode to its place in the register */
        Copy_u32Mode = (Copy_u32Mode << ((Copy_u8Pin - 8) * 4));
        switch (Copy_u8Port)
        {
        case GPIO_PORTA:
            GPIOA_CRH &= Local_u32ModeMask;
            GPIOA_CRH |= (Copy_u32Mode);
            break;
        case GPIO_PORTB:
            GPIOB_CRH &= Local_u32ModeMask;
            GPIOB_CRH |= (Copy_u32Mode);
            break;
        case GPIO_PORTC:
            GPIOC_CRH &= Local_u32ModeMask;
            GPIOC_CRH |= (Copy_u32Mode);
            break;
        default:
            Local_u8ErrorState = NOK;
            break;
        }
    }
    else
    {
        Local_u8ErrorState = NOK;
    }

    return Local_u8ErrorState;
}

u8 MGPIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
    u8 Local_u8ErrorState = OK;
    if (Copy_u8Pin < 16)
    {
        if (Copy_u8Value == GPIO_PIN_HIGH)
        {
            switch (Copy_u8Port)
            {
            case GPIO_PORTA:
                GPIOA_BSRR = (1 << Copy_u8Pin);
                break;
            case GPIO_PORTB:
                GPIOB_BSRR = (1 << Copy_u8Pin);
                break;
            case GPIO_PORTC:
                GPIOC_BSRR = (1 << Copy_u8Pin);
                break;
            default:
                Local_u8ErrorState = NOK;
                break;
            }
        }
        else if (Copy_u8Value == GPIO_PIN_LOW)
        {
            switch (Copy_u8Port)
            {
            case GPIO_PORTA:
                GPIOA_BRR = (1 << Copy_u8Pin);
                break;
            case GPIO_PORTB:
                GPIOB_BRR = (1 << Copy_u8Pin);
                break;
            case GPIO_PORTC:
                GPIOC_BRR = (1 << Copy_u8Pin);
                break;
            default:
                Local_u8ErrorState = NOK;
                break;
            }
        }
        else
        {
            Local_u8ErrorState = NOK;
        }
    }
    else
    {
        Local_u8ErrorState = NOK;
    }
    return Local_u8ErrorState;
}

u8 MGPIO_u8TogglePinValue(u8 Copy_u8Port, u8 Copy_u8Pin)
{
    u8 Local_u8ErrorState = OK;
    if (Copy_u8Pin < 16)
    {
        switch (Copy_u8Port)
        {
        case GPIO_PORTA:
            TOGGLE_BIT(GPIOA_ODR, Copy_u8Pin);
            break;
        case GPIO_PORTB:
            TOGGLE_BIT(GPIOB_ODR, Copy_u8Pin);
            break;
        case GPIO_PORTC:
            TOGGLE_BIT(GPIOC_ODR, Copy_u8Pin);
            break;
        default:
            Local_u8ErrorState = NOK;
            break;
        }
    }
    else
    {
        Local_u8ErrorState = NOK;
    }
    return Local_u8ErrorState;
}

u8 MGPIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 *Copy_pu8Value)
{
    u8 Local_u8ErrorState = OK;
    if (Copy_pu8Value != NULL)
    {
        if (Copy_u8Pin < 16)
        {
            switch (Copy_u8Port)
            {
            case GPIO_PORTA:
                *Copy_pu8Value = GET_BIT(GPIOA_IDR, Copy_u8Pin);
                break;
            case GPIO_PORTB:
                *Copy_pu8Value = GET_BIT(GPIOB_IDR, Copy_u8Pin);
                break;
            case GPIO_PORTC:
                *Copy_pu8Value = GET_BIT(GPIOC_IDR, Copy_u8Pin);
                break;
            default:
                Local_u8ErrorState = NOK;
                break;
            }
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

void MGPIO_voidSetPortValue(u8 Copy_u8Port, u16 Copy_u16Value)
{
    switch (Copy_u8Port)
    {
    case GPIO_PORTA:
        GPIOA_ODR = Copy_u16Value;
        break;
    case GPIO_PORTB:
        GPIOB_ODR = Copy_u16Value;
        break;
    case GPIO_PORTC:
        GPIOC_ODR = Copy_u16Value;
        break;
    default:
        break;
    }
}

u8 MGPIO_u8LockPin(u8 Copy_u8Port, u8 Copy_u8Pin)
{
    u8 Local_u8ErrorState = OK;
    if (Copy_u8Pin < 16)
    {
        if (Copy_u8Port == GPIO_PORTA)
        {
            SET_BIT(GPIOA_LCKR, Copy_u8Pin);
            SET_BIT(GPIOA_LCKR, GPIOA_LCKR_LCKK);
            CLR_BIT(GPIOA_LCKR, GPIOA_LCKR_LCKK);
            SET_BIT(GPIOA_LCKR, GPIOA_LCKR_LCKK);
            
            if (GET_BIT(GPIOA_LCKR, GPIOA_LCKR_LCKK) == 0)
            {

                if (GET_BIT(GPIOA_LCKR, GPIOA_LCKR_LCKK) != 1)
                {
                    Local_u8ErrorState = NOK;
                }
            }
            else
            {
                Local_u8ErrorState = NOK;
            }
        }
        else if (Copy_u8Port == GPIO_PORTB)
        {
            SET_BIT(GPIOB_LCKR, Copy_u8Pin);
            SET_BIT(GPIOB_LCKR, GPIOB_LCKR_LCKK);
            CLR_BIT(GPIOB_LCKR, GPIOB_LCKR_LCKK);
            SET_BIT(GPIOB_LCKR, GPIOB_LCKR_LCKK);

            if (GET_BIT(GPIOB_LCKR, GPIOB_LCKR_LCKK) == 0)
            {

                if (GET_BIT(GPIOB_LCKR, GPIOB_LCKR_LCKK) != 1)
                {
                    Local_u8ErrorState = NOK;
                }
            }
            else
            {
                Local_u8ErrorState = NOK;
            }
        }
        else if (Copy_u8Port == GPIO_PORTC)
        {
            SET_BIT(GPIOC_LCKR, Copy_u8Pin);
            SET_BIT(GPIOC_LCKR, GPIOC_LCKR_LCKK);
            CLR_BIT(GPIOC_LCKR, GPIOC_LCKR_LCKK);
            SET_BIT(GPIOC_LCKR, GPIOC_LCKR_LCKK);

            if (GET_BIT(GPIOC_LCKR, GPIOC_LCKR_LCKK) == 0)
            {

                if (GET_BIT(GPIOC_LCKR, GPIOC_LCKR_LCKK) != 1)
                {
                    Local_u8ErrorState = NOK;
                }
            }
            else
            {
                Local_u8ErrorState = NOK;
            }
        }
        else
        {
            Local_u8ErrorState = NOK;
        }
    }
    else
    {
        Local_u8ErrorState = NOK;
    }

    return Local_u8ErrorState;
}

u8 MGPIO_u8LockPort(u8 Copy_u8Port)
{
    u8 Local_u8ErrorState = OK;
    if (Copy_u8Port == GPIO_PORTA)
    {
        GPIOA_LCKR = 0xffff;
        SET_BIT(GPIOA_LCKR, GPIOA_LCKR_LCKK);
        CLR_BIT(GPIOA_LCKR, GPIOA_LCKR_LCKK);
        SET_BIT(GPIOA_LCKR, GPIOA_LCKR_LCKK);

        if (GET_BIT(GPIOA_LCKR, GPIOA_LCKR_LCKK) == 0)
        {

            if (GET_BIT(GPIOA_LCKR, GPIOA_LCKR_LCKK) != 1)
            {
                Local_u8ErrorState = NOK;
            }
        }
        else
        {
            Local_u8ErrorState = NOK;
        }
    }
    else if (Copy_u8Port == GPIO_PORTB)
    {
        GPIOB_LCKR = 0xffff;
        SET_BIT(GPIOB_LCKR, GPIOB_LCKR_LCKK);
        CLR_BIT(GPIOB_LCKR, GPIOB_LCKR_LCKK);
        SET_BIT(GPIOB_LCKR, GPIOB_LCKR_LCKK);

        if (GET_BIT(GPIOB_LCKR, GPIOB_LCKR_LCKK) == 0)
        {

            if (GET_BIT(GPIOB_LCKR, GPIOB_LCKR_LCKK) != 1)
            {
                Local_u8ErrorState = NOK;
            }
        }
        else
        {
            Local_u8ErrorState = NOK;
        }
    }
    else if (Copy_u8Port == GPIO_PORTC)
    {
        GPIOC_LCKR = 0xffff;
        SET_BIT(GPIOC_LCKR, GPIOC_LCKR_LCKK);
        CLR_BIT(GPIOC_LCKR, GPIOC_LCKR_LCKK);
        SET_BIT(GPIOC_LCKR, GPIOC_LCKR_LCKK);

        if (GET_BIT(GPIOC_LCKR, GPIOC_LCKR_LCKK) == 0)
        {

            if (GET_BIT(GPIOC_LCKR, GPIOC_LCKR_LCKK) != 1)
            {
                Local_u8ErrorState = NOK;
            }
        }
        else
        {
            Local_u8ErrorState = NOK;
        }
    }
    else
    {
        Local_u8ErrorState = NOK;
    }

    return Local_u8ErrorState;
}