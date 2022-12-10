/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 10 DEC 2022                                                                                                         */
/*  Layer       : MCAL                                                                                                               */
/*  SWC         : SPI                                                                                                                */
/*  Version     : V02                                                                                                                */
/*************************************************************************************************************************************/

#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

typedef struct{
    volatile u32 CR1;
    volatile u32 CR2;
    volatile u32 SR;
    volatile u32 DR;
    volatile u32 CRCPR;
    volatile u32 RXCRCR;
    volatile u32 TXCRCR;
    volatile u32 I2SCFGR;
    volatile u32 I2SPR;
}SPI_t;

#define SPI1                         ((volatile SPI_t*)(0x40013000))


#define SPI_CR1_CPHA                 0
#define SPI_CR1_CPOL                 1
#define SPI_CR1_MSTR                 2
#define SPI_CR1_BR0                  3
#define SPI_CR1_BR1                  4
#define SPI_CR1_BR2                  5
#define SPI_CR1_SPE                  6
#define SPI_CR1_LSBF                 7
#define SPI_CR1_SSI                  8
#define SPI_CR1_SSM                  9
#define SPI_CR1_RXONLY               10
#define SPI_CR1_DFF                  11
#define SPI_CR1_CRCNEXT              12
#define SPI_CR1_CRCEN                13
#define SPI_CR1_BIDIOE               14
#define SPI_CR1_BIDIMODE             15

#define SPI_CR2_RXDMAEN              0
#define SPI_CR2_TXDMAEN              1
#define SPI_CR2_SSOE                 2
#define SPI_CR2_ERRIE                5
#define SPI_CR2_RXNEIE               6
#define SPI_CR2_TXEIE                7

#define SPI_SR_RXNE                  0
#define SPI_SR_TXE                   1
#define SPI_SR_CHSIDE                2
#define SPI_SR_UDR                   3
#define SPI_SR_CRCERR                4
#define SPI_SR_MODF                  5
#define SPI_SR_OVR                   6
#define SPI_SR_BSY                   7


#define DIV_BY_2                     0
#define DIV_BY_4                     1
#define DIV_BY_8                     2
#define DIV_BY_16                    3
#define DIV_BY_32                    4
#define DIV_BY_64                    5
#define DIV_BY_128                   6
#define DIV_BY_256                   7

#define _8_BITS                      1
#define _16_BITS                     2

#define LSB                          1
#define MSB                          2

#define LOW                          1
#define HIGH                         2

#define WRITE_FIRST                  1
#define READ_FIRST                   2


#define WRITE_FIRST                  1
#define READ_FIRST                   2


#endif

