/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 1 DEC 2022                                                                                                         */
/*  Layer       : HAL                                                                                                                */
/*  SWC         : LED MATRIX                                                                                                         */
/*  Version     : V01                                                                                                                */
/*************************************************************************************************************************************/

#ifndef LEDMRX_CONFIG_H
#define LEDMRX_CONFIG_H

#define LEDMRX_ROW0      GPIO_PORTA,GPIO_PIN7
#define LEDMRX_ROW1      GPIO_PORTA,GPIO_PIN6
#define LEDMRX_ROW2      GPIO_PORTA,GPIO_PIN5
#define LEDMRX_ROW3      GPIO_PORTA,GPIO_PIN4
#define LEDMRX_ROW4      GPIO_PORTA,GPIO_PIN3
#define LEDMRX_ROW5      GPIO_PORTA,GPIO_PIN2
#define LEDMRX_ROW6      GPIO_PORTA,GPIO_PIN1
#define LEDMRX_ROW7      GPIO_PORTA,GPIO_PIN0


#define LEDMRX_COL0      GPIO_PORTB,GPIO_PIN15
#define LEDMRX_COL1      GPIO_PORTB,GPIO_PIN14
#define LEDMRX_COL2      GPIO_PORTB,GPIO_PIN13
#define LEDMRX_COL3      GPIO_PORTB,GPIO_PIN12
#define LEDMRX_COL4      GPIO_PORTB,GPIO_PIN11
#define LEDMRX_COL5      GPIO_PORTB,GPIO_PIN10
#define LEDMRX_COL6      GPIO_PORTB,GPIO_PIN9
#define LEDMRX_COL7      GPIO_PORTB,GPIO_PIN8


#endif