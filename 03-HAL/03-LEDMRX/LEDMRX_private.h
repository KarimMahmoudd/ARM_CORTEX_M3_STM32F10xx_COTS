/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 1 DEC 2022                                                                                                         */
/*  Layer       : HAL                                                                                                                */
/*  SWC         : LED MATRIX                                                                                                         */
/*  Version     : V01                                                                                                                */
/*************************************************************************************************************************************/

#ifndef LEDMRX_PRIVATE_H
#define LEDMRX_PRIVATE_H

typedef struct 
{
    u8 Port;
    u8 Pin;
}PIN_t;

static void DisableAllColumns(void);
static void SetRowValues(u8 Copy_u8Value);
static void SetColumnValues(u8 Copy_u8Value,u8 Copy_u8Column);

#endif
