/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 8 DEC 2022                                                                                                         */
/*  Layer       : HAL                                                                                                                */
/*  SWC         : DAC                                                                                                                */
/*  Version     : V01                                                                                                                */
/*************************************************************************************************************************************/

#ifndef DAC_INTERFACE_H
#define DAC_INTERFACE_H

void DAC_voidConvertDigitalValue(u8 Copy_u8DigitalValue);
void DAC_voidConvertArray(u8* Copy_pu8DigitlArr,u32 Copy_u32Size,u32 Copy_u32PeriodTicks);


#endif