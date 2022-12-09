/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 25 NOV 2022                                                                                                        */
/*  Layer       : LIB                                                                                                                */
/*  SWC         : BIT_MATH                                                                                                           */
/*  Version     : V01                                                                                                                */
/*************************************************************************************************************************************/

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(VAR,BIT_NO)             (VAR|=(1<<BIT_NO))

#define CLR_BIT(VAR,BIT_NO)             (VAR&=(~(1<<BIT_NO)))

#define TOGGLE_BIT(VAR,BIT_NO)          (VAR^=(1<<BIT_NO))

#define GET_BIT(VAR,BIT_NO)             (1&(VAR>>BIT_NO))

#endif