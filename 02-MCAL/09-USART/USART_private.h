/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 12 DEC 2022                                                                                                        */
/*  Layer       : MCAL                                                                                                               */
/*  SWC         : USART                                                                                                              */
/*  Version     : V02                                                                                                                */
/*************************************************************************************************************************************/

#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H

typedef struct 
{
    volatile u32 SR;
    volatile u32 DR;
    volatile u32 BRR;
    volatile u32 CR1;
    volatile u32 CR2;
    volatile u32 CR3;
    volatile u32 GPTR;
}USART_t;

#define USART1                      ((volatile USART_t*)(0x40013800))


#define USART_SR_PE                 0
#define USART_SR_FE                 1
#define USART_SR_NE                 2
#define USART_SR_ORE                3
#define USART_SR_IDLE               4
#define USART_SR_RXNE               5
#define USART_SR_TC                 6
#define USART_SR_TXE                7
#define USART_SR_LBD                8
#define USART_SR_CTS                9

#define USART_BRR_DIV_FRACTION      0
#define USART_BRR_DIV_MANTISSA      3


#define USART_CR1_SBK               0
#define USART_CR1_RWU               1
#define USART_CR1_RE                2
#define USART_CR1_TE                3
#define USART_CR1_IDLEIE            4
#define USART_CR1_RXNEIE            5
#define USART_CR1_TCIE              6
#define USART_CR1_TXEIE             7
#define USART_CR1_PEIE              8
#define USART_CR1_PS                9
#define USART_CR1_PCE               10
#define USART_CR1_WAKE              11
#define USART_CR1_M                 12
#define USART_CR1_UE                13

#define USART_CR2_ADD               0
#define USART_CR2_LBDL              5
#define USART_CR2_LBDIE             6
#define USART_CR2_LBCL              8
#define USART_CR2_CPHA              9
#define USART_CR2_CPOL              10
#define USART_CR2_CLKEN             11
#define USART_CR2_STOP              12
#define USART_CR2_LINEN             14

#define USART_CR3_EIE               0
#define USART_CR3_IREN              1
#define USART_CR3_IRLP              2
#define USART_CR3_HDSEL             3
#define USART_CR3_NACK              4
#define USART_CR3_SCEN              5
#define USART_CR3_DMAR              6
#define USART_CR3_DMAT              7
#define USART_CR3_RTSE              8
#define USART_CR3_CTSE              9
#define USART_CR3_CTSIE             10



#define _8_BITS                     0
#define _9_BITS                     1

#define DISABLED                    0
#define ENABLED                     1

#define EVEN                        0
#define ODD                         1

#define _1_STOP_BIT                 0
#define _2_STOP_BITS                2

#define BAUD_RATE_9600              0x341
#define BAUD_RATE_115200            0x45


#define IDLE						0
#define BUSY						1


#define TIMEOUT						500000
#endif
