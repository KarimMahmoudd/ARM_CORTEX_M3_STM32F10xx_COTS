/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 8 DEC 2022                                                                                                         */
/*  Layer       : HAL                                                                                                                */
/*  SWC         : DAC                                                                                                                */
/*  Version     : V01                                                                                                                */
/*************************************************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "DAC_interface.h"
#include "DAC_private.h"
#include "DAC_config.h"

u8 DAC_u8Pins[8]={DAC_BIT0_PIN,DAC_BIT1_PIN,DAC_BIT2_PIN,DAC_BIT3_PIN,DAC_BIT4_PIN,DAC_BIT5_PIN,DAC_BIT6_PIN,DAC_BIT7_PIN};
u8* DAC_pu8Arr=NULL;
u32 DAC_u32ArrSize;

void DAC_voidConvertDigitalValue(u8 Copy_u8DigitalValue){
    u16 Local_u16PortValue=0;
    for(u8 Local_u8Iterator=0;Local_u8Iterator<8;Local_u8Iterator++){
        Local_u16PortValue |= ((GET_BIT(Copy_u8DigitalValue,Local_u8Iterator))<<DAC_u8Pins[Local_u8Iterator]) ;
    }
    MGPIO_voidSetPortValue(DAC_PORT,Local_u16PortValue);
}

void DAC_voidConvertArray(u8* Copy_pu8DigitlArr,u32 Copy_u32Size,u32 Copy_u32PeriodTicks){
    DAC_u32ArrSize=Copy_u32Size;
    DAC_pu8Arr=Copy_pu8DigitlArr;
    MSTK_voidSetIntervalPeriodic(Copy_u32PeriodTicks,voidConvertElement);
}

void voidConvertElement(void){
    static u32 Local_u32Counter=0;
    DAC_voidConvertDigitalValue(DAC_pu8Arr[Local_u32Counter]);
    Local_u32Counter++;
    if(Local_u32Counter==DAC_u32ArrSize){
        Local_u32Counter=0;
    }
}