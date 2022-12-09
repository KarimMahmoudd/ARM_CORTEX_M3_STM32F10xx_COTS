/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 8 DEC 2022                                                                                                         */
/*  Layer       : MCAL                                                                                                               */
/*  SWC         : DMA                                                                                                                */
/*  Version     : V02                                                                                                                */
/*************************************************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DMA_interface.h"
#include "DMA_private.h"
#include "DMA_config.h"

void MDMA_voidInit(void)
{
/******************************************CHANNEL1**************************************************************/
#if DMA_CHANNEL1_TCI_STATE == ENABLED
    SET_BIT(DMA->Channel[0].CCR, DMA_CCR_TCIE);
#elif DMA_CHANNEL1_TCI_STATE == DISABLED
    CLR_BIT(DMA->Channel[0].CCR, DMA_CCR_TCIE);
#endif

#if DMA_CHANNEL1_HTI_STATE == ENABLED
    SET_BIT(DMA->Channel[0].CCR, DMA_CCR_HTIE);
#elif DMA_CHANNEL1_HTI_STATE == DISABLED
    CLR_BIT(DMA->Channel[0].CCR, DMA_CCR_HTIE);
#endif

#if DMA_CHANNEL1_TEI_STATE == ENABLED
    SET_BIT(DMA->Channel[0].CCR, DMA_CCR_TEIE);
#elif DMA_CHANNEL1_TEI_STATE == DISABLED
    CLR_BIT(DMA->Channel[0].CCR, DMA_CCR_TEIE);
#endif

#if DMA_CHANNEL1_CIRCULAR_MODE == ENABLED
    SET_BIT(DMA->Channel[0].CCR, DMA_CCR_CIRC);
#elif DMA_CHANNEL1_CIRCULAR_MODE == DISABLED
    CLR_BIT(DMA->Channel[0].CCR, DMA_CCR_CIRC);
#endif

#if DMA_CHANNEL1_MEMORY_INC_MODE == ENABLED
    SET_BIT(DMA->Channel[0].CCR, DMA_CCR_MINC);
#elif DMA_CHANNEL1_MEMORY_INC_MODE == DISABLED
    CLR_BIT(DMA->Channel[0].CCR, DMA_CCR_MINC);
#endif

#if DMA_CHANNEL1_PER_INC_MODE == ENABLED
    SET_BIT(DMA->Channel[0].CCR, DMA_CCR_PINC);
#elif DMA_CHANNEL1_PER_INC_MODE == DISABLED
    CLR_BIT(DMA->Channel[0].CCR, DMA_CCR_PINC);
#endif

#if DMA_CHANNEL1_DIR == MEM2PER
    CLR_BIT(DMA->Channel[0].CCR, DMA_CCR_MEM2MEM);
    SET_BIT(DMA->Channel[0].CCR, DMA_CCR_DIR);
#elif DMA_CHANNEL1_DIR == PER2MEM
    CLR_BIT(DMA->Channel[0].CCR, DMA_CCR_MEM2MEM);
    CLR_BIT(DMA->Channel[0].CCR, DMA_CCR_DIR);
#elif DMA_CHANNEL1_DIR == MEM2MEM
    SET_BIT(DMA->Channel[0].CCR, DMA_CCR_MEM2MEM);
    CLR_BIT(DMA->Channel[0].CCR, DMA_CCR_DIR);
#endif

    DMA->Channel[0].CCR &= (~(0b11 << DMA_CCR_PSIZE1));
    DMA->Channel[0].CCR |= (DMA_CHANNEL1_PERIPHERAL_SIZE << DMA_CCR_PSIZE1);

    DMA->Channel[0].CCR &= (~(0b11 << DMA_CCR_MSIZE1));
    DMA->Channel[0].CCR |= (DMA_CHANNEL1_MEMORY_SIZE << DMA_CCR_MSIZE1);

    DMA->Channel[0].CCR &= (~(0b11 << DMA_CCR_PL1));
    DMA->Channel[0].CCR |= (DMA_CHANNEL1_PRIORITY << DMA_CCR_PL1);

/******************************************CHANNEL2**************************************************************/
#if DMA_CHANNEL2_TCI_STATE == ENABLED
    SET_BIT(DMA->Channel[1].CCR, DMA_CCR_TCIE);
#elif DMA_CHANNEL2_TCI_STATE == DISABLED
    CLR_BIT(DMA->Channel[1].CCR, DMA_CCR_TCIE);
#endif

#if DMA_CHANNEL2_HTI_STATE == ENABLED
    SET_BIT(DMA->Channel[1].CCR, DMA_CCR_HTIE);
#elif DMA_CHANNEL2_HTI_STATE == DISABLED
    CLR_BIT(DMA->Channel[1].CCR, DMA_CCR_HTIE);
#endif

#if DMA_CHANNEL2_TEI_STATE == ENABLED
    SET_BIT(DMA->Channel[1].CCR, DMA_CCR_TEIE);
#elif DMA_CHANNEL2_TEI_STATE == DISABLED
    CLR_BIT(DMA->Channel[1].CCR, DMA_CCR_TEIE);
#endif

#if DMA_CHANNEL2_CIRCULAR_MODE == ENABLED
    SET_BIT(DMA->Channel[1].CCR, DMA_CCR_CIRC);
#elif DMA_CHANNEL2_CIRCULAR_MODE == DISABLED
    CLR_BIT(DMA->Channel[1].CCR, DMA_CCR_CIRC);
#endif

#if DMA_CHANNEL2_MEMORY_INC_MODE == ENABLED
    SET_BIT(DMA->Channel[1].CCR, DMA_CCR_MINC);
#elif DMA_CHANNEL2_MEMORY_INC_MODE == DISABLED
    CLR_BIT(DMA->Channel[1].CCR, DMA_CCR_MINC);
#endif

#if DMA_CHANNEL2_PER_INC_MODE == ENABLED
    SET_BIT(DMA->Channel[1].CCR, DMA_CCR_PINC);
#elif DMA_CHANNEL2_PER_INC_MODE == DISABLED
    CLR_BIT(DMA->Channel[1].CCR, DMA_CCR_PINC);
#endif

#if DMA_CHANNEL2_DIR == MEM2PER
    CLR_BIT(DMA->Channel[1].CCR, DMA_CCR_MEM2MEM);
    SET_BIT(DMA->Channel[1].CCR, DMA_CCR_DIR);
#elif DMA_CHANNEL2_DIR == PER2MEM
    CLR_BIT(DMA->Channel[1].CCR, DMA_CCR_MEM2MEM);
    CLR_BIT(DMA->Channel[1].CCR, DMA_CCR_DIR);
#elif DMA_CHANNEL2_DIR == MEM2MEM
    SET_BIT(DMA->Channel[1].CCR, DMA_CCR_MEM2MEM);
    CLR_BIT(DMA->Channel[1].CCR, DMA_CCR_DIR);
#endif

    DMA->Channel[1].CCR &= (~(0b11 << DMA_CCR_PSIZE1));
    DMA->Channel[1].CCR |= (DMA_CHANNEL2_PERIPHERAL_SIZE << DMA_CCR_PSIZE1);

    DMA->Channel[1].CCR &= (~(0b11 << DMA_CCR_MSIZE1));
    DMA->Channel[1].CCR |= (DMA_CHANNEL2_MEMORY_SIZE << DMA_CCR_MSIZE1);

    DMA->Channel[1].CCR &= (~(0b11 << DMA_CCR_PL1));
    DMA->Channel[1].CCR |= (DMA_CHANNEL2_PRIORITY << DMA_CCR_PL1);

/******************************************CHANNEL3**************************************************************/
#if DMA_CHANNEL3_TCI_STATE == ENABLED
    SET_BIT(DMA->Channel[2].CCR, DMA_CCR_TCIE);
#elif DMA_CHANNEL3_TCI_STATE == DISABLED
    CLR_BIT(DMA->Channel[2].CCR, DMA_CCR_TCIE);
#endif

#if DMA_CHANNEL3_HTI_STATE == ENABLED
    SET_BIT(DMA->Channel[2].CCR, DMA_CCR_HTIE);
#elif DMA_CHANNEL3_HTI_STATE == DISABLED
    CLR_BIT(DMA->Channel[2].CCR, DMA_CCR_HTIE);
#endif

#if DMA_CHANNEL3_TEI_STATE == ENABLED
    SET_BIT(DMA->Channel[2].CCR, DMA_CCR_TEIE);
#elif DMA_CHANNEL3_TEI_STATE == DISABLED
    CLR_BIT(DMA->Channel[2].CCR, DMA_CCR_TEIE);
#endif

#if DMA_CHANNEL3_CIRCULAR_MODE == ENABLED
    SET_BIT(DMA->Channel[2].CCR, DMA_CCR_CIRC);
#elif DMA_CHANNEL3_CIRCULAR_MODE == DISABLED
    CLR_BIT(DMA->Channel[2].CCR, DMA_CCR_CIRC);
#endif

#if DMA_CHANNEL3_MEMORY_INC_MODE == ENABLED
    SET_BIT(DMA->Channel[2].CCR, DMA_CCR_MINC);
#elif DMA_CHANNEL3_MEMORY_INC_MODE == DISABLED
    CLR_BIT(DMA->Channel[2].CCR, DMA_CCR_MINC);
#endif

#if DMA_CHANNEL3_PER_INC_MODE == ENABLED
    SET_BIT(DMA->Channel[2].CCR, DMA_CCR_PINC);
#elif DMA_CHANNEL3_PER_INC_MODE == DISABLED
    CLR_BIT(DMA->Channel[2].CCR, DMA_CCR_PINC);
#endif

#if DMA_CHANNEL3_DIR == MEM2PER
    CLR_BIT(DMA->Channel[2].CCR, DMA_CCR_MEM2MEM);
    SET_BIT(DMA->Channel[2].CCR, DMA_CCR_DIR);
#elif DMA_CHANNEL3_DIR == PER2MEM
    CLR_BIT(DMA->Channel[2].CCR, DMA_CCR_MEM2MEM);
    CLR_BIT(DMA->Channel[2].CCR, DMA_CCR_DIR);
#elif DMA_CHANNEL3_DIR == MEM2MEM
    SET_BIT(DMA->Channel[2].CCR, DMA_CCR_MEM2MEM);
    CLR_BIT(DMA->Channel[2].CCR, DMA_CCR_DIR);
#endif

    DMA->Channel[2].CCR &= (~(0b11 << DMA_CCR_PSIZE1));
    DMA->Channel[2].CCR |= (DMA_CHANNEL3_PERIPHERAL_SIZE << DMA_CCR_PSIZE1);

    DMA->Channel[2].CCR &= (~(0b11 << DMA_CCR_MSIZE1));
    DMA->Channel[2].CCR |= (DMA_CHANNEL3_MEMORY_SIZE << DMA_CCR_MSIZE1);

    DMA->Channel[2].CCR &= (~(0b11 << DMA_CCR_PL1));
    DMA->Channel[2].CCR |= (DMA_CHANNEL3_PRIORITY << DMA_CCR_PL1);

/******************************************CHANNEL4**************************************************************/
#if DMA_CHANNEL4_TCI_STATE == ENABLED
    SET_BIT(DMA->Channel[3].CCR, DMA_CCR_TCIE);
#elif DMA_CHANNEL4_TCI_STATE == DISABLED
    CLR_BIT(DMA->Channel[3].CCR, DMA_CCR_TCIE);
#endif

#if DMA_CHANNEL4_HTI_STATE == ENABLED
    SET_BIT(DMA->Channel[3].CCR, DMA_CCR_HTIE);
#elif DMA_CHANNEL4_HTI_STATE == DISABLED
    CLR_BIT(DMA->Channel[3].CCR, DMA_CCR_HTIE);
#endif

#if DMA_CHANNEL4_TEI_STATE == ENABLED
    SET_BIT(DMA->Channel[3].CCR, DMA_CCR_TEIE);
#elif DMA_CHANNEL4_TEI_STATE == DISABLED
    CLR_BIT(DMA->Channel[3].CCR, DMA_CCR_TEIE);
#endif

#if DMA_CHANNEL4_CIRCULAR_MODE == ENABLED
    SET_BIT(DMA->Channel[3].CCR, DMA_CCR_CIRC);
#elif DMA_CHANNEL4_CIRCULAR_MODE == DISABLED
    CLR_BIT(DMA->Channel[3].CCR, DMA_CCR_CIRC);
#endif

#if DMA_CHANNEL4_MEMORY_INC_MODE == ENABLED
    SET_BIT(DMA->Channel[3].CCR, DMA_CCR_MINC);
#elif DMA_CHANNEL4_MEMORY_INC_MODE == DISABLED
    CLR_BIT(DMA->Channel[3].CCR, DMA_CCR_MINC);
#endif

#if DMA_CHANNEL4_PER_INC_MODE == ENABLED
    SET_BIT(DMA->Channel[3].CCR, DMA_CCR_PINC);
#elif DMA_CHANNEL4_PER_INC_MODE == DISABLED
    CLR_BIT(DMA->Channel[3].CCR, DMA_CCR_PINC);
#endif

#if DMA_CHANNEL4_DIR == MEM2PER
    CLR_BIT(DMA->Channel[3].CCR, DMA_CCR_MEM2MEM);
    SET_BIT(DMA->Channel[3].CCR, DMA_CCR_DIR);
#elif DMA_CHANNEL4_DIR == PER2MEM
    CLR_BIT(DMA->Channel[3].CCR, DMA_CCR_MEM2MEM);
    CLR_BIT(DMA->Channel[3].CCR, DMA_CCR_DIR);
#elif DMA_CHANNEL4_DIR == MEM2MEM
    SET_BIT(DMA->Channel[3].CCR, DMA_CCR_MEM2MEM);
    CLR_BIT(DMA->Channel[3].CCR, DMA_CCR_DIR);
#endif

    DMA->Channel[3].CCR &= (~(0b11 << DMA_CCR_PSIZE1));
    DMA->Channel[3].CCR |= (DMA_CHANNEL4_PERIPHERAL_SIZE << DMA_CCR_PSIZE1);

    DMA->Channel[3].CCR &= (~(0b11 << DMA_CCR_MSIZE1));
    DMA->Channel[3].CCR |= (DMA_CHANNEL4_MEMORY_SIZE << DMA_CCR_MSIZE1);

    DMA->Channel[3].CCR &= (~(0b11 << DMA_CCR_PL1));
    DMA->Channel[3].CCR |= (DMA_CHANNEL4_PRIORITY << DMA_CCR_PL1);

/******************************************CHANNEL5**************************************************************/
#if DMA_CHANNEL5_TCI_STATE == ENABLED
    SET_BIT(DMA->Channel[4].CCR, DMA_CCR_TCIE);
#elif DMA_CHANNEL5_TCI_STATE == DISABLED
    CLR_BIT(DMA->Channel[4].CCR, DMA_CCR_TCIE);
#endif

#if DMA_CHANNEL5_HTI_STATE == ENABLED
    SET_BIT(DMA->Channel[4].CCR, DMA_CCR_HTIE);
#elif DMA_CHANNEL5_HTI_STATE == DISABLED
    CLR_BIT(DMA->Channel[4].CCR, DMA_CCR_HTIE);
#endif

#if DMA_CHANNEL5_TEI_STATE == ENABLED
    SET_BIT(DMA->Channel[4].CCR, DMA_CCR_TEIE);
#elif DMA_CHANNEL5_TEI_STATE == DISABLED
    CLR_BIT(DMA->Channel[4].CCR, DMA_CCR_TEIE);
#endif

#if DMA_CHANNEL5_CIRCULAR_MODE == ENABLED
    SET_BIT(DMA->Channel[4].CCR, DMA_CCR_CIRC);
#elif DMA_CHANNEL5_CIRCULAR_MODE == DISABLED
    CLR_BIT(DMA->Channel[4].CCR, DMA_CCR_CIRC);
#endif

#if DMA_CHANNEL5_MEMORY_INC_MODE == ENABLED
    SET_BIT(DMA->Channel[4].CCR, DMA_CCR_MINC);
#elif DMA_CHANNEL5_MEMORY_INC_MODE == DISABLED
    CLR_BIT(DMA->Channel[4].CCR, DMA_CCR_MINC);
#endif

#if DMA_CHANNEL5_PER_INC_MODE == ENABLED
    SET_BIT(DMA->Channel[4].CCR, DMA_CCR_PINC);
#elif DMA_CHANNEL5_PER_INC_MODE == DISABLED
    CLR_BIT(DMA->Channel[4].CCR, DMA_CCR_PINC);
#endif

#if DMA_CHANNEL5_DIR == MEM2PER
    CLR_BIT(DMA->Channel[4].CCR, DMA_CCR_MEM2MEM);
    SET_BIT(DMA->Channel[4].CCR, DMA_CCR_DIR);
#elif DMA_CHANNEL5_DIR == PER2MEM
    CLR_BIT(DMA->Channel[4].CCR, DMA_CCR_MEM2MEM);
    CLR_BIT(DMA->Channel[4].CCR, DMA_CCR_DIR);
#elif DMA_CHANNEL5_DIR == MEM2MEM
    SET_BIT(DMA->Channel[4].CCR, DMA_CCR_MEM2MEM);
    CLR_BIT(DMA->Channel[4].CCR, DMA_CCR_DIR);
#endif

    DMA->Channel[4].CCR &= (~(0b11 << DMA_CCR_PSIZE1));
    DMA->Channel[4].CCR |= (DMA_CHANNEL5_PERIPHERAL_SIZE << DMA_CCR_PSIZE1);

    DMA->Channel[4].CCR &= (~(0b11 << DMA_CCR_MSIZE1));
    DMA->Channel[4].CCR |= (DMA_CHANNEL5_MEMORY_SIZE << DMA_CCR_MSIZE1);

    DMA->Channel[4].CCR &= (~(0b11 << DMA_CCR_PL1));
    DMA->Channel[4].CCR |= (DMA_CHANNEL5_PRIORITY << DMA_CCR_PL1);

/******************************************CHANNEL6**************************************************************/
#if DMA_CHANNEL6_TCI_STATE == ENABLED
    SET_BIT(DMA->Channel[5].CCR, DMA_CCR_TCIE);
#elif DMA_CHANNEL6_TCI_STATE == DISABLED
    CLR_BIT(DMA->Channel[5].CCR, DMA_CCR_TCIE);
#endif

#if DMA_CHANNEL6_HTI_STATE == ENABLED
    SET_BIT(DMA->Channel[5].CCR, DMA_CCR_HTIE);
#elif DMA_CHANNEL6_HTI_STATE == DISABLED
    CLR_BIT(DMA->Channel[5].CCR, DMA_CCR_HTIE);
#endif

#if DMA_CHANNEL6_TEI_STATE == ENABLED
    SET_BIT(DMA->Channel[5].CCR, DMA_CCR_TEIE);
#elif DMA_CHANNEL6_TEI_STATE == DISABLED
    CLR_BIT(DMA->Channel[5].CCR, DMA_CCR_TEIE);
#endif

#if DMA_CHANNEL6_CIRCULAR_MODE == ENABLED
    SET_BIT(DMA->Channel[5].CCR, DMA_CCR_CIRC);
#elif DMA_CHANNEL6_CIRCULAR_MODE == DISABLED
    CLR_BIT(DMA->Channel[5].CCR, DMA_CCR_CIRC);
#endif

#if DMA_CHANNEL6_MEMORY_INC_MODE == ENABLED
    SET_BIT(DMA->Channel[5].CCR, DMA_CCR_MINC);
#elif DMA_CHANNEL6_MEMORY_INC_MODE == DISABLED
    CLR_BIT(DMA->Channel[5].CCR, DMA_CCR_MINC);
#endif

#if DMA_CHANNEL6_PER_INC_MODE == ENABLED
    SET_BIT(DMA->Channel[5].CCR, DMA_CCR_PINC);
#elif DMA_CHANNEL6_PER_INC_MODE == DISABLED
    CLR_BIT(DMA->Channel[5].CCR, DMA_CCR_PINC);
#endif

#if DMA_CHANNEL6_DIR == MEM2PER
    CLR_BIT(DMA->Channel[5].CCR, DMA_CCR_MEM2MEM);
    SET_BIT(DMA->Channel[5].CCR, DMA_CCR_DIR);
#elif DMA_CHANNEL6_DIR == PER2MEM
    CLR_BIT(DMA->Channel[5].CCR, DMA_CCR_MEM2MEM);
    CLR_BIT(DMA->Channel[5].CCR, DMA_CCR_DIR);
#elif DMA_CHANNEL6_DIR == MEM2MEM
    SET_BIT(DMA->Channel[5].CCR, DMA_CCR_MEM2MEM);
    CLR_BIT(DMA->Channel[5].CCR, DMA_CCR_DIR);
#endif

    DMA->Channel[5].CCR &= (~(0b11 << DMA_CCR_PSIZE1));
    DMA->Channel[5].CCR |= (DMA_CHANNEL6_PERIPHERAL_SIZE << DMA_CCR_PSIZE1);

    DMA->Channel[5].CCR &= (~(0b11 << DMA_CCR_MSIZE1));
    DMA->Channel[5].CCR |= (DMA_CHANNEL6_MEMORY_SIZE << DMA_CCR_MSIZE1);

    DMA->Channel[5].CCR &= (~(0b11 << DMA_CCR_PL1));
    DMA->Channel[5].CCR |= (DMA_CHANNEL6_PRIORITY << DMA_CCR_PL1);

/******************************************CHANNEL7**************************************************************/
#if DMA_CHANNEL7_TCI_STATE == ENABLED
    SET_BIT(DMA->Channel[6].CCR, DMA_CCR_TCIE);
#elif DMA_CHANNEL7_TCI_STATE == DISABLED
    CLR_BIT(DMA->Channel[6].CCR, DMA_CCR_TCIE);
#endif

#if DMA_CHANNEL7_HTI_STATE == ENABLED
    SET_BIT(DMA->Channel[6].CCR, DMA_CCR_HTIE);
#elif DMA_CHANNEL7_HTI_STATE == DISABLED
    CLR_BIT(DMA->Channel[6].CCR, DMA_CCR_HTIE);
#endif

#if DMA_CHANNEL7_TEI_STATE == ENABLED
    SET_BIT(DMA->Channel[6].CCR, DMA_CCR_TEIE);
#elif DMA_CHANNEL7_TEI_STATE == DISABLED
    CLR_BIT(DMA->Channel[6].CCR, DMA_CCR_TEIE);
#endif

#if DMA_CHANNEL7_CIRCULAR_MODE == ENABLED
    SET_BIT(DMA->Channel[6].CCR, DMA_CCR_CIRC);
#elif DMA_CHANNEL7_CIRCULAR_MODE == DISABLED
    CLR_BIT(DMA->Channel[6].CCR, DMA_CCR_CIRC);
#endif

#if DMA_CHANNEL7_MEMORY_INC_MODE == ENABLED
    SET_BIT(DMA->Channel[6].CCR, DMA_CCR_MINC);
#elif DMA_CHANNEL7_MEMORY_INC_MODE == DISABLED
    CLR_BIT(DMA->Channel[6].CCR, DMA_CCR_MINC);
#endif

#if DMA_CHANNEL7_PER_INC_MODE == ENABLED
    SET_BIT(DMA->Channel[6].CCR, DMA_CCR_PINC);
#elif DMA_CHANNEL7_PER_INC_MODE == DISABLED
    CLR_BIT(DMA->Channel[6].CCR, DMA_CCR_PINC);
#endif

#if DMA_CHANNEL7_DIR == MEM2PER
    CLR_BIT(DMA->Channel[6].CCR, DMA_CCR_MEM2MEM);
    SET_BIT(DMA->Channel[6].CCR, DMA_CCR_DIR);
#elif DMA_CHANNEL7_DIR == PER2MEM
    CLR_BIT(DMA->Channel[6].CCR, DMA_CCR_MEM2MEM);
    CLR_BIT(DMA->Channel[6].CCR, DMA_CCR_DIR);
#elif DMA_CHANNEL7_DIR == MEM2MEM
    SET_BIT(DMA->Channel[6].CCR, DMA_CCR_MEM2MEM);
    CLR_BIT(DMA->Channel[6].CCR, DMA_CCR_DIR);
#endif

    DMA->Channel[6].CCR &= (~(0b11 << DMA_CCR_PSIZE1));
    DMA->Channel[6].CCR |= (DMA_CHANNEL7_PERIPHERAL_SIZE << DMA_CCR_PSIZE1);

    DMA->Channel[6].CCR &= (~(0b11 << DMA_CCR_MSIZE1));
    DMA->Channel[6].CCR |= (DMA_CHANNEL7_MEMORY_SIZE << DMA_CCR_MSIZE1);

    DMA->Channel[6].CCR &= (~(0b11 << DMA_CCR_PL1));
    DMA->Channel[6].CCR |= (DMA_CHANNEL7_PRIORITY << DMA_CCR_PL1);
}

void MDMA_voidChannelStart(u32* Copy_pu32PeripheralAddress, u32* Copy_pu32MemoryAddress, u16 Copy_u16BlockLength, u8 Copy_u8Channel)
{
    CLR_BIT(DMA->Channel[Copy_u8Channel].CCR,DMA_CCR_EN);
    DMA->Channel[Copy_u8Channel].CNDTR = Copy_u16BlockLength;
    DMA->Channel[Copy_u8Channel].CPAR = Copy_pu32PeripheralAddress;
    DMA->Channel[Copy_u8Channel].CMAR = Copy_pu32MemoryAddress;
    SET_BIT(DMA->Channel[Copy_u8Channel].CCR,DMA_CCR_EN);
}