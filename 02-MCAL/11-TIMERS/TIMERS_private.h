/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 3 JAN 2023                                                                                                         */
/*  Layer       : MCAL                                                                                                               */
/*  SWC         : TIMERS                                                                                                             */
/*  Version     : V01                                                                                                                */
/*************************************************************************************************************************************/

#ifndef TIMERS_PRIVATE
#define TIMERS_PRIVATE

typedef struct 
{
    volatile u32 CR1;
    volatile u32 CR2;
    volatile u32 SMCR;
    volatile u32 DIER;
    volatile u32 SR;
    volatile u32 EGR;
    volatile u32 CCMR1;
    volatile u32 CCMR2;
    volatile u32 CCER;
    volatile u32 CNT;
    volatile u32 PSC;
    volatile u32 ARR;
    volatile u32 Reserved1;
    volatile u32 CCR[4];
    volatile u32 Reserved2;
    volatile u32 DCR;
    volatile u32 DMAR;
}Timer_t;

#define TIMER2                      ((volatile Timer_t *)(0x40000000))
#define TIMER3                      ((volatile Timer_t *)(0x40000400))
#define TIMER4                      ((volatile Timer_t *)(0x40000800))
#define TIMER5                      ((volatile Timer_t *)(0x40000C00))

#endif