/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 5 DEC 2022                                                                                                         */
/*  Layer       : SERVICES                                                                                                           */
/*  SWC         : OS                                                                                                                 */
/*  Version     : V01                                                                                                                */
/*************************************************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"

#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"

static Task OS_Tasks[NUMBER_OF_TASKS] = {NULL};

void SOS_voidCreateTask(u8 Copy_u8ID, u16 Copy_u16Periodicity, u16 Copy_u16FirstDelay, void (*Copy_pvFunc)(void))
{
    OS_Tasks[Copy_u8ID].ID = Copy_u8ID;
    OS_Tasks[Copy_u8ID].FirstDelay = Copy_u16FirstDelay;
    OS_Tasks[Copy_u8ID].Periodicity = Copy_u16Periodicity;
    OS_Tasks[Copy_u8ID].Function = Copy_pvFunc;
    OS_Tasks[Copy_u8ID].State = Ready;

}
void SOS_voidStart(void)
{
    MSTK_voidInit();
    MSTK_voidSetIntervalPeriodic(1000, Scheduler);
}

void SOS_voidSuspendTask(u8 Copy_u8ID){
    OS_Tasks[Copy_u8ID].State = Suspended;
}

void SOS_voidResumeTask(u8 Copy_u8ID){
    OS_Tasks[Copy_u8ID].State = Ready;
}

void SOS_voidDeleteTask(u8 Copy_u8ID){
    OS_Tasks[Copy_u8ID].Function = NULL;
}

static void Scheduler(void)
{
    for (u8 i = 0; i < NUMBER_OF_TASKS; i++)
    {
        if (OS_Tasks[i].State==Ready && OS_Tasks[i].Function!=NULL)
        {
            if(OS_Tasks[i].FirstDelay == 0){
                OS_Tasks[i].FirstDelay=OS_Tasks[i].Periodicity-1;
                OS_Tasks[i].Function();
            }
            else
            {
                OS_Tasks[i].FirstDelay--;
            }
            
        }
    }
}
