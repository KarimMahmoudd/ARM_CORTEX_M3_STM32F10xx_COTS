/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 9 DEC 2022                                                                                                         */
/*  Layer       : HAL                                                                                                                */
/*  SWC         : STP                                                                                                                */
/*  Version     : V01                                                                                                                */
/*************************************************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "STP_interface.h"
#include "STP_private.h"
#include "STP_config.h"

void HSTP_voidSendSynchronous(u8 Copy_u8Data){
    MGPIO_u8SetPinValue(STP_STC_PIN,GPIO_PIN_LOW);
    for(u8 Local_u8Iterator=0;Local_u8Iterator<8;Local_u8Iterator++){
        MGPIO_u8SetPinValue(STP_SHC_PIN,GPIO_PIN_LOW);
        MGPIO_u8SetPinValue(STP_SD_PIN,GET_BIT(Copy_u8Data,(7-Local_u8Iterator)));
        MGPIO_u8SetPinValue(STP_SHC_PIN,GPIO_PIN_HIGH);
    }
    MGPIO_u8SetPinValue(STP_STC_PIN,GPIO_PIN_HIGH);
}