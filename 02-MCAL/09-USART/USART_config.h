/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 12 DEC 2022                                                                                                        */
/*  Layer       : MCAL                                                                                                               */
/*  SWC         : USART                                                                                                              */
/*  Version     : V02                                                                                                                */
/*************************************************************************************************************************************/

#ifndef USART_CONFIG_H
#define USART_CONFIG_H

/* Options:
            1- _8_BITS
            2- _9_BITS                  
                                                                 */

#define USART_WORD_LENGTH                   _8_BITS

/* Options:
            1- DISABLED
            2- ENABLED                  
                                                                 */

#define USART_PARITY                        DISABLED

#if USART_PARITY == ENABLED
/* Options:
            1- EVEN
            2- ODD                  
                                                                 */

#define USART_PARITY_MODE                   EVEN

#endif

/* Options:
            1- DISABLED
            2- ENABLED                  
                                                                 */

#define USART_TRANSMITTER                   ENABLED

/* Options:
            1- DISABLED
            2- ENABLED                  
                                                                 */

#define USART_RECEIVER                      ENABLED


/* Options:
            1- _1_STOP_BIT
            2- _2_STOP_BITS      
                                                                 */

#define USART_STOP_BITS                     _1_STOP_BIT

/* Options:
            1- BAUD_RATE_115200 = 4.34
            2- BAUD_RATE_9600    
                                                                 */
#define USART_BAUD_RATE                     BAUD_RATE_9600                     
#endif