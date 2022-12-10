/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 10 DEC 2022                                                                                                         */
/*  Layer       : MCAL                                                                                                               */
/*  SWC         : SPI                                                                                                                */
/*  Version     : V02                                                                                                                */
/*************************************************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

void (*SPI1_pvNotifFunc)(u16);

void MSPI1_voidMasterInit(void){
    #if SPI1_CLK_PHASE == WRITE_FIRST
        SET_BIT(SPI1->CR1,SPI_CR1_CPHA);
    #elif SPI1_CLK_PHASE == READ_FIRST
        CLR_BIT(SPI1->CR1,SPI_CR1_CPHA);
    #endif
    

    #if SPI1_CLK_POLARITY == HIGH
        SET_BIT(SPI1->CR1,SPI_CR1_CPOL);
    #elif SPI1_CLK_POLARITY == LOW
        CLR_BIT(SPI1->CR1,SPI_CR1_CPOL);
    #endif
     
    #if SPI1_FIRST_BIT == LSB
        SET_BIT(SPI1->CR1,SPI_CR1_LSBF);
    #elif SPI1_FIRST_BIT == MSB
        CLR_BIT(SPI1->CR1,SPI_CR1_LSBF);
    #endif

    #if SPI1_DATA_FRAME_FORMAT == _16_BITS
        SET_BIT(SPI1->CR1,SPI_CR1_LSBF);
    #elif SPI1_DATA_FRAME_FORMAT == _8_BITS
        CLR_BIT(SPI1->CR1,SPI_CR1_LSBF);
    #endif

    SPI1->CR1 &= (~(111<<SPI_CR1_BR2));
    SPI1->CR1 |= (SPI1_BAUD_RATE_PRESCALER<<SPI_CR1_BR2);

    SET_BIT(SPI1->CR1,SPI_CR1_MSTR);

    SET_BIT(SPI1->CR1,SPI_CR1_SPE);
    

    
}

void MSPI1_voidSlaveInit(void){

    #if SPI1_CLK_PHASE == WRITE_FIRST
        SET_BIT(SPI1->CR1,SPI_CR1_CPHA);
    #elif SPI1_CLK_PHASE == READ_FIRST
        CLR_BIT(SPI1->CR1,SPI_CR1_CPHA);
    #endif
     
    #if SPI1_FIRST_BIT == LSB
        SET_BIT(SPI1->CR1,SPI_CR1_LSBF);
    #elif SPI1_FIRST_BIT == MSB
        CLR_BIT(SPI1->CR1,SPI_CR1_LSBF);
    #endif

    #if SPI1_DATA_FRAME_FORMAT == _16_BITS
        SET_BIT(SPI1->CR1,SPI_CR1_LSBF);
    #elif SPI1_DATA_FRAME_FORMAT == _8_BITS
        CLR_BIT(SPI1->CR1,SPI_CR1_LSBF);
    #endif

    CLR_BIT(SPI1->CR1,SPI_CR1_MSTR);

    SET_BIT(SPI1->CR1,SPI_CR1_SPE);

}

void MSPI1_voidSynchTranscieve(u16 Copy_u16DataToSend, u16* Copy_pu16DataToReceive){
    SPI1->DR = Copy_u16DataToSend;

    while(GET_BIT(SPI1->SR,SPI_SR_BSY)==1);

    *Copy_pu16DataToReceive = SPI1->DR;

}

void MSPI1_voidAsynchTranscieve(u16 Copy_u16DataToSend, void (*Copy_pvNotifFunc)(u16)){
    SET_BIT(SPI1->CR2,SPI_CR2_RXNEIE);
    SPI1_pvNotifFunc=Copy_pvNotifFunc;
    SPI1->DR = Copy_u16DataToSend;
}



void SPI1_IRQHandler(void){
    u16 Data = SPI1->DR;
    SPI1_pvNotifFunc(Data);
}