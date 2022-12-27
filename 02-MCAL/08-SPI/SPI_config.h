/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 10 DEC 2022                                                                                                         */
/*  Layer       : MCAL                                                                                                               */
/*  SWC         : SPI                                                                                                                */
/*  Version     : V02                                                                                                                */
/*************************************************************************************************************************************/

#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H


#define MSPI1_SLAVE_PIN                 GPIO_PORTA,GPIO_PIN12

/* Options:
            1- WRITE_FIRST
            2- READ_FIRST   
                                                         */
#define SPI1_CLK_PHASE                   WRITE_FIRST

/* Options:
            1- LOW
            2- HIGH   
                                                         */

#define SPI1_CLK_POLARITY                HIGH

/* Options:
            1- LSB
            2- MSB   
                                                         */
#define SPI1_FIRST_BIT                   MSB

/* Options:
            1- _8_BITS
            2- _16_BITS   
                                                         */

#define SPI1_DATA_FRAME_FORMAT           _8_BITS

/* Options:
            1- DIV_BY_2
            2- DIV_BY_4   
            3- DIV_BY_8   
            4- DIV_BY_16   
            5- DIV_BY_32   
            6- DIV_BY_64   
            7- DIV_BY_128   
            8- DIV_BY_256   
                                                         */

#define SPI1_BAUD_RATE_PRESCALER         DIV_BY_2

#endif