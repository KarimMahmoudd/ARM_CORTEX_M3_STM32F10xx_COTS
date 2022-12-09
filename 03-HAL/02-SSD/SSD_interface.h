/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 25 NOV 2022                                                                                                        */
/*  Layer       : HAL                                                                                                                */
/*  SWC         : SSD                                                                                                                */
/*  Version     : V01                                                                                                                */
/*************************************************************************************************************************************/
#ifndef SSD_INTERFACE_H
#define SSD_INTERFACE_H


#define COMMON_ANODE 1
#define COMMON_CATHODE 0

typedef struct pin{
    u8 Port;
    u8 Pin;
}PIN_t;

typedef struct SSD
{
    u8 CommonType;
    PIN_t A;
    PIN_t B;
    PIN_t C;
    PIN_t D;
    PIN_t E;
    PIN_t F;
    PIN_t G;
    PIN_t Common;

}SSD_t;

u8 HSSD_u8SetNumber(SSD_t* Copy_SSD , u8 Copy_u8Number);
u8 HSSD_u8Enable(SSD_t* Copy_SSD);
u8 HSSD_u8Disable(SSD_t* Copy_SSD);
#endif