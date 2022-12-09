/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 25 NOV 2022                                                                                                        */
/*  Layer       : MCAL                                                                                                               */
/*  SWC         : GPIO                                                                                                               */
/*  Version     : V01                                                                                                                */
/*************************************************************************************************************************************/

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

/* GPIO PORTS */
#define GPIO_PORTA                      0
#define GPIO_PORTB                      1
#define GPIO_PORTC                      2

/* GPIO PINS */
#define GPIO_PIN0                       0
#define GPIO_PIN1                       1
#define GPIO_PIN2                       2
#define GPIO_PIN3                       3
#define GPIO_PIN4                       4
#define GPIO_PIN5                       5
#define GPIO_PIN6                       6
#define GPIO_PIN7                       7
#define GPIO_PIN8                       8
#define GPIO_PIN9                       9
#define GPIO_PIN10                      10
#define GPIO_PIN11                      11
#define GPIO_PIN12                      12
#define GPIO_PIN13                      13
#define GPIO_PIN14                      14
#define GPIO_PIN15                      15

/* INPUT/OUTPUT MODES FOR GPIO PINS */
#define GPIO_IP_ANALOG                       0x0
#define GPIO_IP_FLOATING                     0x4
#define GPIO_IP_PULLED                       0x8
#define GPIO_OP_PUSH_PULL_10_MHZ             0x1
#define GPIO_OP_OPEN_DRAIN_10_MHZ            0x5
#define GPIO_OP_AF_PUSH_PULL_10_MHZ          0x9
#define GPIO_OP_AF_OPEN_DRAIN_10_MHZ         0xD
#define GPIO_OP_PUSH_PULL_2_MHZ              0x2
#define GPIO_OP_OPEN_DRAIN_2_MHZ             0x6
#define GPIO_OP_AF_PUSH_PULL_2_MHZ           0xA
#define GPIO_OP_AF_OPEN_DRAIN_2_MHZ          0xE
#define GPIO_OP_PUSH_PULL_50_MHZ             0x3
#define GPIO_OP_OPEN_DRAIN_50_MHZ            0x7
#define GPIO_OP_AF_PUSH_PULL_50_MHZ          0xB
#define GPIO_OP_AF_OPEN_DRAIN_50_MHZ         0xF

#define GPIO_PIN_HIGH                        1
#define GPIO_PIN_LOW                         0

void MPORT_voidInit(void);

u8 MGPIO_u8SetPinMode(u8 Copy_u8Port , u8 Copy_u8Pin , u32 Copy_u32Mode);

u8 MGPIO_u8SetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value);

u8 MGPIO_u8TogglePinValue(u8 Copy_u8Port, u8 Copy_u8Pin);

u8 MGPIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8* Copy_pu8Value);

void MGPIO_voidSetPortValue(u8 Copy_u8Port, u16 Copy_u16Value);

u8 MGPIO_u8LockPin(u8 Copy_u8Port , u8 Copy_u8Pin);

u8 MGPIO_u8LockPort(u8 Copy_u8Port);

#endif