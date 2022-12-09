/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 5 DEC 2022                                                                                                         */
/*  Layer       : SERVICES                                                                                                           */
/*  SWC         : OS                                                                                                                 */
/*  Version     : V01                                                                                                                */
/*************************************************************************************************************************************/

#ifndef OS_PRIVATE_H
#define OS_PRIVATE_H

typedef struct
{
    State_t State          ;
    u8  ID                  ;
    u16 Periodicity         ;
    u16 FirstDelay          ;
    void (*Function)(void)  ;
    
} Task;

typedef enum
{
    Ready,
    Running,
    Blocked,
    Suspended
}State_t;


static void Scheduler(void);

#endif