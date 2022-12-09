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
#include "STK_interface.h"

#include "STP_interface.h"
#include "STP_private.h"
#include "STP_config.h"

void HSTP_voidSendSynchronous(u8 Copy_u8Data){
    s8 Local_s8Counter=0;
    u8 Local_u8Bit=0;
    for(Local_s8Counter=0;Local_s8Counter>=0;Local_s8Counter--){
        
        Local_u8Bit=GET_BIT(Copy_u8Data,Local_s8Counter);

        MGPIO_u8SetPinValue(STP_SD_PIN,Local_u8Bit);

        MGPIO_u8SetPinValue(STP_SHC_PIN,GPIO_PIN_HIGH);
        MSTK_voidSetBusyWait(1);
        MGPIO_u8SetPinValue(STP_SHC_PIN,GPIO_PIN_LOW);
        MSTK_voidSetBusyWait(1);
    }
    MGPIO_u8SetPinValue(STP_STC_PIN,GPIO_PIN_HIGH);
    MSTK_voidSetBusyWait(1);
    MGPIO_u8SetPinValue(STP_STC_PIN,GPIO_PIN_LOW);
    MSTK_voidSetBusyWait(1);
}