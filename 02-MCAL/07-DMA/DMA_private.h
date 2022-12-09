/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 8 DEC 2022                                                                                                         */
/*  Layer       : MCAL                                                                                                               */
/*  SWC         : DMA                                                                                                                */
/*  Version     : V02                                                                                                                */
/*************************************************************************************************************************************/

#ifndef DMA_PRIVATE_H
#define DMA_PRIVATE_H
typedef struct{
    volatile u32 CCR;
    volatile u32 CNDTR;
    volatile u32 CPAR;
    volatile u32 CMAR;
    volatile u32 Reserved;
}DMA_Channel_t;

typedef struct 
{
    volatile u32 ISR;
    volatile u32 IFCR;
    DMA_Channel_t Channel[7];

}DMA_t;

#define DMA                                     ((volatile DMA_t*)(0x40020000))


#define DMA_ISR_TEIF7                           27
#define DMA_ISR_HTIF7                           26
#define DMA_ISR_TCIF7                           25
#define DMA_ISR_GIF7                            24

#define DMA_ISR_TEIF6                           23
#define DMA_ISR_HTIF6                           22
#define DMA_ISR_TCIF6                           21
#define DMA_ISR_GIF6                            20

#define DMA_ISR_TEIF5                           19
#define DMA_ISR_HTIF5                           18
#define DMA_ISR_TCIF5                           17
#define DMA_ISR_GIF5                            16

#define DMA_ISR_TEIF4                           15
#define DMA_ISR_HTIF4                           14
#define DMA_ISR_TCIF4                           13
#define DMA_ISR_GIF4                            12

#define DMA_ISR_TEIF3                           11
#define DMA_ISR_HTIF3                           10
#define DMA_ISR_TCIF3                           9
#define DMA_ISR_GIF3                            8

#define DMA_ISR_TEIF2                           7
#define DMA_ISR_HTIF2                           6
#define DMA_ISR_TCIF2                           5
#define DMA_ISR_GIF2                            4

#define DMA_ISR_TEIF1                           3
#define DMA_ISR_HTIF1                           2
#define DMA_ISR_TCIF1                           1
#define DMA_ISR_GIF1                            0




#define DMA_IFCR_CTEIF7                           27
#define DMA_IFCR_CHTIF7                           26
#define DMA_IFCR_CTCIF7                           25
#define DMA_IFCR_CGIF7                            24

#define DMA_IFCR_CTEIF6                           23
#define DMA_IFCR_CHTIF6                           22
#define DMA_IFCR_CTCIF6                           21
#define DMA_IFCR_CGIF6                            20

#define DMA_IFCR_CTEIF5                           19
#define DMA_IFCR_CHTIF5                           18
#define DMA_IFCR_CTCIF5                           17
#define DMA_IFCR_CGIF5                            16

#define DMA_IFCR_CTEIF4                           15
#define DMA_IFCR_CHTIF4                           14
#define DMA_IFCR_CTCIF4                           13
#define DMA_IFCR_CGIF4                            12

#define DMA_IFCR_CTEIF3                           11
#define DMA_IFCR_CHTIF3                           10
#define DMA_IFCR_CTCIF3                           9
#define DMA_IFCR_CGIF3                            8

#define DMA_IFCR_CTEIF2                           7
#define DMA_IFCR_CHTIF2                           6
#define DMA_IFCR_CTCIF2                           5
#define DMA_IFCR_CGIF2                            4

#define DMA_IFCR_CTEIF1                           3
#define DMA_IFCR_CHTIF1                           2
#define DMA_IFCR_CTCIF1                           1
#define DMA_IFCR_CGIF1                            0


#define DMA_CCR_EN                                  0
#define DMA_CCR_TCIE                                1
#define DMA_CCR_HTIE                                2
#define DMA_CCR_TEIE                                3
#define DMA_CCR_DIR                                 4
#define DMA_CCR_CIRC                                5
#define DMA_CCR_PINC                                6
#define DMA_CCR_MINC                                7
#define DMA_CCR_PSIZE0                              8
#define DMA_CCR_PSIZE1                              9
#define DMA_CCR_MSIZE0                              10
#define DMA_CCR_MSIZE1                              11
#define DMA_CCR_PL0                                 12
#define DMA_CCR_PL1                                 13
#define DMA_CCR_MEM2MEM                             14



#define DISABLED                                    0
#define ENABLED                                     1

#define MEM2MEM                                     1
#define PER2MEM                                     2
#define MEM2PER                                     3

#define _8_BITS                                     0
#define _16_BITS                                    1
#define _32_BITS                                    2

#define LOW                                         0
#define MEDIUM                                      1
#define HIGH                                        2
#define VERY_HIGH                                   3
#endif