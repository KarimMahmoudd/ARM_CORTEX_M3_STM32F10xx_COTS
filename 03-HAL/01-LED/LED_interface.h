/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 25 NOV 2022                                                                                                        */
/*  Layer       : HAL                                                                                                                */
/*  SWC         : LED                                                                                                                */
/*  Version     : V01                                                                                                                */
/*************************************************************************************************************************************/

#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

#define LED_SINK            1
#define LED_SOURCE          2

typedef struct LED
{
    u8 Connection;
    u8 Port;
    u8 Pin;
}LED_t;

u8 HLED_u8ON(LED_t* Copy_LED);
u8 HLED_u8OFF(LED_t* Copy_LED);
u8 HLED_u8Toggle(LED_t* Copy_LED);
#endif