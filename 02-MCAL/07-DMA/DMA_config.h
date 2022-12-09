/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 8 DEC 2022                                                                                                         */
/*  Layer       : MCAL                                                                                                               */
/*  SWC         : DMA                                                                                                                */
/*  Version     : V02                                                                                                                */
/*************************************************************************************************************************************/

#ifndef DMA_CONFIG_H
#define DMA_CONFIG_H

/*************************************************************************************************************************************/
/***************************************                CHANNEL1                    **************************************************/
/*************************************************************************************************************************************/

#define DMA_CHANNEL1_TCI_STATE              ENABLED
#define DMA_CHANNEL1_HTI_STATE              DISABLED
#define DMA_CHANNEL1_TEI_STATE              DISABLED
#define DMA_CHANNEL1_CIRCULAR_MODE          DISABLED
#define DMA_CHANNEL1_MEMORY_INC_MODE        ENABLED
#define DMA_CHANNEL1_PER_INC_MODE           ENABLED

/* Options: 1- MEM2MEM
            2- PER2MEM
            3- MEM2PER
                                                    */
#define DMA_CHANNEL1_DIR                    MEM2MEM

/* Options: 1- _8_BITS
            2- _16_BITS
            3- _32_BITS
                                                    */
#define DMA_CHANNEL1_PERIPHERAL_SIZE        _32_BITS

#define DMA_CHANNEL1_MEMORY_SIZE            _32_BITS

/* Options: 1- LOW
            2- MEDIUM
            3- HIGH
            4- VERY_HIGH
                                                    */
#define DMA_CHANNEL1_PRIORITY               VERY_HIGH


/*************************************************************************************************************************************/
/***************************************                CHANNEL2                    **************************************************/
/*************************************************************************************************************************************/

#define DMA_CHANNEL2_TCI_STATE              DISABLED
#define DMA_CHANNEL2_HTI_STATE              DISABLED
#define DMA_CHANNEL2_TEI_STATE              DISABLED
#define DMA_CHANNEL2_CIRCULAR_MODE          DISABLED
#define DMA_CHANNEL2_MEMORY_INC_MODE        DISABLED
#define DMA_CHANNEL2_PER_INC_MODE           DISABLED

/* Options: 1- MEM2MEM
            2- PER2MEM
            3- MEM2PER
                                                    */
#define DMA_CHANNEL2_DIR                    PER2MEM

/* Options: 1- _8_BITS
            2- _16_BITS
            3- _32_BITS
                                                    */
#define DMA_CHANNEL2_PERIPHERAL_SIZE        _8_BITS
#define DMA_CHANNEL2_MEMORY_SIZE            _8_BITS

/* Options: 1- LOW
            2- MEDIUM
            3- HIGH
            4- VERY_HIGH
                                                    */
#define DMA_CHANNEL2_PRIORITY               LOW

/*************************************************************************************************************************************/
/***************************************                CHANNEL3                    **************************************************/
/*************************************************************************************************************************************/

#define DMA_CHANNEL3_TCI_STATE              DISABLED
#define DMA_CHANNEL3_HTI_STATE              DISABLED
#define DMA_CHANNEL3_TEI_STATE              DISABLED
#define DMA_CHANNEL3_CIRCULAR_MODE          DISABLED
#define DMA_CHANNEL3_MEMORY_INC_MODE        DISABLED
#define DMA_CHANNEL3_PER_INC_MODE           DISABLED

/* Options: 1- MEM2MEM
            2- PER2MEM
            3- MEM2PER
                                                    */
#define DMA_CHANNEL3_DIR                    PER2MEM

/* Options: 1- _8_BITS
            2- _16_BITS
            3- _32_BITS
                                                    */
#define DMA_CHANNEL3_PERIPHERAL_SIZE        _8_BITS
#define DMA_CHANNEL3_MEMORY_SIZE            _8_BITS

/* Options: 1- LOW
            2- MEDIUM
            3- HIGH
            4- VERY_HIGH
                                                    */
#define DMA_CHANNEL3_PRIORITY               LOW

/*************************************************************************************************************************************/
/***************************************                CHANNEL4                    **************************************************/
/*************************************************************************************************************************************/

#define DMA_CHANNEL4_TCI_STATE              DISABLED
#define DMA_CHANNEL4_HTI_STATE              DISABLED
#define DMA_CHANNEL4_TEI_STATE              DISABLED
#define DMA_CHANNEL4_CIRCULAR_MODE          DISABLED
#define DMA_CHANNEL4_MEMORY_INC_MODE        DISABLED
#define DMA_CHANNEL4_PER_INC_MODE           DISABLED

/* Options: 1- MEM2MEM
            2- PER2MEM
            3- MEM2PER
                                                    */
#define DMA_CHANNEL4_DIR                    PER2MEM

/* Options: 1- _8_BITS
            2- _16_BITS
            3- _32_BITS
                                                    */
#define DMA_CHANNEL4_PERIPHERAL_SIZE        _8_BITS
#define DMA_CHANNEL4_MEMORY_SIZE            _8_BITS

/* Options: 1- LOW
            2- MEDIUM
            3- HIGH
            4- VERY_HIGH
                                                    */
#define DMA_CHANNEL4_PRIORITY               LOW

/*************************************************************************************************************************************/
/***************************************                CHANNEL5                    **************************************************/
/*************************************************************************************************************************************/

#define DMA_CHANNEL5_TCI_STATE              DISABLED
#define DMA_CHANNEL5_HTI_STATE              DISABLED
#define DMA_CHANNEL5_TEI_STATE              DISABLED
#define DMA_CHANNEL5_CIRCULAR_MODE          DISABLED
#define DMA_CHANNEL5_MEMORY_INC_MODE        DISABLED
#define DMA_CHANNEL5_PER_INC_MODE           DISABLED

/* Options: 1- MEM2MEM
            2- PER2MEM
            3- MEM2PER
                                                    */
#define DMA_CHANNEL5_DIR                    PER2MEM

/* Options: 1- _8_BITS
            2- _16_BITS
            3- _32_BITS
                                                    */
#define DMA_CHANNEL5_PERIPHERAL_SIZE        _8_BITS
#define DMA_CHANNEL5_MEMORY_SIZE            _8_BITS

/* Options: 1- LOW
            2- MEDIUM
            3- HIGH
            4- VERY_HIGH
                                                    */
#define DMA_CHANNEL5_PRIORITY               LOW

/*************************************************************************************************************************************/
/***************************************                CHANNEL6                    **************************************************/
/*************************************************************************************************************************************/

#define DMA_CHANNEL6_TCI_STATE              DISABLED
#define DMA_CHANNEL6_HTI_STATE              DISABLED
#define DMA_CHANNEL6_TEI_STATE              DISABLED
#define DMA_CHANNEL6_CIRCULAR_MODE          DISABLED
#define DMA_CHANNEL6_MEMORY_INC_MODE        DISABLED
#define DMA_CHANNEL6_PER_INC_MODE           DISABLED

/* Options: 1- MEM2MEM
            2- PER2MEM
            3- MEM2PER
                                                    */
#define DMA_CHANNEL6_DIR                    PER2MEM

/* Options: 1- _8_BITS
            2- _16_BITS
            3- _32_BITS
                                                    */
#define DMA_CHANNEL6_PERIPHERAL_SIZE        _8_BITS
#define DMA_CHANNEL6_MEMORY_SIZE            _8_BITS

/* Options: 1- LOW
            2- MEDIUM
            3- HIGH
            4- VERY_HIGH
                                                    */
#define DMA_CHANNEL6_PRIORITY               LOW

/*************************************************************************************************************************************/
/***************************************                CHANNEL7                    **************************************************/
/*************************************************************************************************************************************/

#define DMA_CHANNEL7_TCI_STATE              DISABLED
#define DMA_CHANNEL7_HTI_STATE              DISABLED
#define DMA_CHANNEL7_TEI_STATE              DISABLED
#define DMA_CHANNEL7_CIRCULAR_MODE          DISABLED
#define DMA_CHANNEL7_MEMORY_INC_MODE        DISABLED
#define DMA_CHANNEL7_PER_INC_MODE           DISABLED

/* Options: 1- MEM2MEM
            2- PER2MEM
            3- MEM2PER
                                                    */
#define DMA_CHANNEL7_DIR                    PER2MEM

/* Options: 1- _8_BITS
            2- _16_BITS
            3- _32_BITS
                                                    */
#define DMA_CHANNEL7_PERIPHERAL_SIZE        _8_BITS
#define DMA_CHANNEL7_MEMORY_SIZE            _8_BITS

/* Options: 1- LOW
            2- MEDIUM
            3- HIGH
            4- VERY_HIGH
                                                    */
#define DMA_CHANNEL7_PRIORITY               LOW


#endif