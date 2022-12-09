/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 25 NOV 2022                                                                                                        */
/*  Layer       : HAL                                                                                                                */
/*  SWC         : LED                                                                                                                */
/*  Version     : V01                                                                                                                */
/*************************************************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "LED_interface.h"
#include "LED_config.h"
#include "LED_private.h"


u8 HLED_u8ON(LED_t* Copy_LED){
    u8 Local_u8ErrorState=OK;
    if(Copy_LED!=NULL){
        if(Copy_LED->Connection==LED_SOURCE){
            GPIO_u8SetPinValue(Copy_LED->Port,Copy_LED->Pin,GPIO_PIN_HIGH);
        }
        else if(Copy_LED->Connection==LED_SINK){
            GPIO_u8SetPinValue(Copy_LED->Port,Copy_LED->Pin,GPIO_PIN_LOW);
        }
        else{
            Local_u8ErrorState=NOK;
        }

    }
    else{
        Local_u8ErrorState=NULL_POINTER;
    }
    
    return Local_u8ErrorState;
}

u8 HLED_u8OFF(LED_t* Copy_LED){
    u8 Local_u8ErrorState=OK;
    if(Copy_LED!=NULL){
        if(Copy_LED->Connection==LED_SOURCE){
            GPIO_u8SetPinValue(Copy_LED->Port,Copy_LED->Pin,GPIO_PIN_LOW);
        }
        else if(Copy_LED->Connection==LED_SINK){
            GPIO_u8SetPinValue(Copy_LED->Port,Copy_LED->Pin,GPIO_PIN_HIGH);
        }
        else{
            Local_u8ErrorState=NOK;
        }

    }
    else{
        Local_u8ErrorState=NULL_POINTER;
    }
    
    return Local_u8ErrorState;
}


u8 HLED_u8Toggle(LED_t* Copy_LED){
    u8 Local_u8ErrorState=OK;
    if(Copy_LED!=NULL){
        GPIO_u8TogglePinValue(Copy_LED->Port,Copy_LED->Pin);
    }
    else{
        Local_u8ErrorState=NULL_POINTER;
    }
    
    return Local_u8ErrorState;
}