/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 12 DEC 2022                                                                                                        */
/*  Layer       : MCAL                                                                                                               */
/*  SWC         : USART                                                                                                              */
/*  Version     : V02                                                                                                                */
/*************************************************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"
static u8 USART_u8State = IDLE;
void MUSART1_voidInit(void)
{
	USART1->BRR = USART_BAUD_RATE;

#if USART_WORD_LENGTH == _9_BITS
	SET_BIT(USART1->CR1, USART_CR1_M);
#elif USART_WORD_LENGTH == DISABLED
	CLR_BIT(USART1->CR1, USART_CR1_M);
#endif

#if USART_PARITY == ENABLED
	SET_BIT(USART1->CR1, USART_CR1_PCE);
#if USART_PARITY_MODE == ODD
	SET_BIT(USART1->CR1, USART_CR1_PS);
#elif USART_PARITY_MODE == EVEN
	CLR_BIT(USART1->CR1, USART_CR1_PS);
#endif
#elif USART_PARITY == DISABLED
	CLR_BIT(USART1->CR1, USART_CR1_PCE);
#endif

	USART1->CR2 &= (~(11 << (USART_CR2_STOP)));
	USART1->CR2 |= (USART_STOP_BITS << (USART_CR2_STOP));

#if USART_TRANSMITTER == ENABLED
	SET_BIT(USART1->CR1, USART_CR1_TE);
#elif USART_TRANSMITTER == DISABLED
	CLR_BIT(USART1->CR1, USART_CR1_TE);
#endif

#if USART_RECEIVER == ENABLED
	SET_BIT(USART1->CR1, USART_CR1_RE);
#elif USART_TRANSMITTER == DISABLED
	CLR_BIT(USART1->CR1, USART_CR1_RE);
#endif

	SET_BIT(USART1->CR1, USART_CR1_UE);

	USART1->SR = 0;
}

u8 MUSART1_u8TransmitDataSynch(u8 Copy_u8Data)
{
	u8 Local_u8ErrorState=OK;
	if(USART_u8State==IDLE){
		USART_u8State=BUSY;
		u32 Local_u32Counter=0;
		USART1->DR = Copy_u8Data;
		while(((USART1->SR)&(1<<USART_SR_TC))==0&&Local_u32Counter!=TIMEOUT){
			Local_u32Counter++;
		}
		if(Local_u32Counter==TIMEOUT){
			Local_u8ErrorState=FUNC_TIMEOUT;
		}
		else{

		}
		USART_u8State=IDLE;
	}
	else{
		Local_u8ErrorState=BUSY_FUNC;
	}
	return Local_u8ErrorState;
}

u8 MUSART1_u8TransmitStringSynch(char* Copy_pchString)
{
	u8 Local_u8ErrorState=OK;
	if(Copy_pchString!=NULL){
		u8 Local_u8Index=0;
		while(Copy_pchString[Local_u8Index]!='\0'){
			MUSART1_voidTransmitDataSynch(Copy_pchString[Local_u8Index++]);
		}
	}
	else{
		Local_u8ErrorState=NULL_POINTER;
	}
	return Local_u8ErrorState;
}

void MUSART1_voidTransmitArrSynch(u8* Copy_pu8Arr,u32 Copy_u32ArrSize)
{
	u32 Local_u32Index=0;
	for(Local_u32Index=0;Local_u32Index<Copy_u32ArrSize;Local_u32Index++){
		MUSART1_voidTransmitDataSynch(Copy_pu8Arr[Local_u32Index]);
	}
}



u8 MUSART1_u8ReceiveDataSynch(u8 *Copy_pu8ReceivedData)
{
	u8 Local_u8ErrorState=OK;
	if(USART_u8State==IDLE){
		if(Copy_pu8ReceivedData!=NULL){
			USART_u8State=BUSY;
			u32 Local_u32Counter=0;
			while(GET_BIT(USART1->SR, USART_SR_RXNE)==0 && Local_u32Counter!=TIMEOUT){
				Local_u32Counter++;
			}
			if(Local_u32Counter==TIMEOUT){
				Local_u8ErrorState=FUNC_TIMEOUT;
			}
			else{
				*Copy_pu8ReceivedData = USART1->DR;

			}
			USART_u8State=IDLE;
		}
		else{
			Local_u8ErrorState=NULL_POINTER;
		}
	}
	else{
		Local_u8ErrorState=BUSY_FUNC;
	}
	return Local_u8ErrorState;

}

u8 MUSART1_u8ReceiveBufferSynch(u8 *Copy_pu8Buffer,u8 Copy_u8BufferSize)
{
	u8 Local_u8ErrorState=OK;
	if(USART_u8State==IDLE){
		if(Copy_pu8Buffer!=NULL){
			u8 Local_u8Iterator;
			for(Local_u8Iterator=0;Local_u8Iterator<Copy_u8BufferSize;Local_u8Iterator++){
				MUSART1_voidReceiveDataSynch(&Copy_pu8Buffer[Local_u8Iterator]);
			}
		}
		else{
			Local_u8ErrorState=NULL_POINTER;
		}
	}
	else{
		Local_u8ErrorState=BUSY_FUNC;
	}

	return Local_u8ErrorState;

}
