/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 25 NOV 2022                                                                                                        */
/*  Layer       : LIB                                                                                                                */
/*  SWC         : MATH_HELPER                                                                                                        */
/*  Version     : V01                                                                                                                */
/*************************************************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MATH_HELPER.h"

u32 MATH_u32Power(u32 Copy_u32Base,u32 Copy_u32Exponent){
	u32 Local_u32Result=1;
	for(u32 i=0;i<Copy_u32Exponent;i++){
		Local_u32Result*=Copy_u32Base;
	}
	return Local_u32Result;
}

s32 MATH_s32Map(s32 Copy_s32InputMin,s32 Copy_s32InputMax,s32 Copy_s32OutputMin,s32 Copy_s32OutputMax,s32 Copy_s32InputVal){
    s32 Local_s32OutputVal;
    Local_s32OutputVal= (((Copy_s32OutputMax-Copy_s32OutputMin)*(Copy_s32InputVal-Copy_s32InputMin))/(Copy_s32InputMax-Copy_s32InputMin))+Copy_s32OutputMin;
    return Local_s32OutputVal;
}