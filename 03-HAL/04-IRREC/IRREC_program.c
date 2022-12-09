/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 4 DEC 2022                                                                                                         */
/*  Layer       : HAL                                                                                                                */
/*  SWC         : IR RECEIVER                                                                                                        */
/*  Version     : V01                                                                                                                */
/*************************************************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "EXTI_interface.h"

#include "IRREC_interface.h"
#include "IRREC_private.h"
#include "IRREC_config.h"

static volatile u8 IRREC_u8StartFlag = 0;
static volatile u8 IRREC_u8EdgeCounter = 0;
static volatile u32 IRREC_u32FrameData[50] = {0};
volatile u8 IRREC_u8Data = 0;

static void (*IRREC_pvCallBackFunc)(void) = NULL;

void MIRREC_voidInit()
{
	MEXTI_voidSetCallBack(IRREC_EXTI_LINE, GetFrame);
	MEXTI_u8SetSenseMode(IRREC_EXTI_LINE, EXTI_FALLING);
	MEXTI_u8EnableLineInterrupt(IRREC_EXTI_LINE);
}

volatile u8 *MIRREC_voidSetCallBack(void (*Copy_pvCallBackFunc)(void))
{
	IRREC_pvCallBackFunc = Copy_pvCallBackFunc;
	return (&IRREC_u8Data);
}

void GetFrame(void)
{
	if (IRREC_u8StartFlag == 0)
	{
		MSTK_voidSetIntervalSingle(1000000, TakeAction);
		IRREC_u8StartFlag = 1;
	}
	else
	{
		IRREC_u32FrameData[IRREC_u8EdgeCounter++] = MSTK_u32GetElapsedTime();
		MSTK_voidSetIntervalSingle(1000000, TakeAction);
	}
}

void TakeAction(void)
{
	u8 Local_u8Iterator;
	IRREC_u8Data = 0;
	if ((IRREC_u32FrameData[0] >= 8500) && (IRREC_u32FrameData[0] <= 14000))
	{
		for (Local_u8Iterator = 0; Local_u8Iterator < 8; Local_u8Iterator++)
		{
			if (IRREC_u32FrameData[17 + Local_u8Iterator] >= 2000 && IRREC_u32FrameData[17 + Local_u8Iterator] < 2500)
			{
				SET_BIT(IRREC_u8Data, Local_u8Iterator);
			}
			else if (IRREC_u32FrameData[17 + Local_u8Iterator] >= 1000 && IRREC_u32FrameData[17 + Local_u8Iterator] < 1500)
			{
				CLR_BIT(IRREC_u8Data, Local_u8Iterator);
			}
		}

		IRREC_pvCallBackFunc();
	}

	IRREC_u8StartFlag = 0;
	IRREC_u8EdgeCounter = 0;
	IRREC_u32FrameData[0] = 0;
}
