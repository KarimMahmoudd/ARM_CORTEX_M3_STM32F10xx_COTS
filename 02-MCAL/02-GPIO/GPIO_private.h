/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 25 NOV 2022                                                                                                        */
/*  Layer       : MCAL                                                                                                               */
/*  SWC         : GPIO                                                                                                               */
/*  Version     : V01                                                                                                                */
/*************************************************************************************************************************************/

#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H


/*                      Register Definitions for GPIO PORTS                  */
#define GPIOA_BASE_ADDRESS              0x40010800
#define GPIOA_CRL                       *((volatile u32*)(GPIOA_BASE_ADDRESS + 0x00))  // PORT A configuration register low
#define GPIOA_CRH                       *((volatile u32*)(GPIOA_BASE_ADDRESS + 0x04))  // PORT A configuration register high
#define GPIOA_IDR                       *((volatile u32*)(GPIOA_BASE_ADDRESS + 0x08))  // PORT A input data register
#define GPIOA_ODR                       *((volatile u32*)(GPIOA_BASE_ADDRESS + 0x0C))  // PORT A Output Data Register
#define GPIOA_BSRR                      *((volatile u32*)(GPIOA_BASE_ADDRESS + 0x10))  // PORT A Bit Set/Reset Register
#define GPIOA_BRR                       *((volatile u32*)(GPIOA_BASE_ADDRESS + 0x14))  // PORT A Bit Reset Register
#define GPIOA_LCKR                      *((volatile u32*)(GPIOA_BASE_ADDRESS + 0x18))  // PORT A Configuration Lock Register
#define GPIOA_LCKR_LCKK                 16

#define GPIOB_BASE_ADDRESS              0x40010C00
#define GPIOB_CRL                       *((volatile u32*)(GPIOB_BASE_ADDRESS + 0x00))  // PORT B configuration register low
#define GPIOB_CRH                       *((volatile u32*)(GPIOB_BASE_ADDRESS + 0x04))  // PORT B configuration register high
#define GPIOB_IDR                       *((volatile u32*)(GPIOB_BASE_ADDRESS + 0x08))  // PORT B input data register
#define GPIOB_ODR                       *((volatile u32*)(GPIOB_BASE_ADDRESS + 0x0C))  // PORT B Output Data Register
#define GPIOB_BSRR                      *((volatile u32*)(GPIOB_BASE_ADDRESS + 0x10))  // PORT B Bit Set/Reset Register
#define GPIOB_BRR                       *((volatile u32*)(GPIOB_BASE_ADDRESS + 0x14))  // PORT B Bit Reset Register
#define GPIOB_LCKR                      *((volatile u32*)(GPIOB_BASE_ADDRESS + 0x18))  // PORT B Configuration Lock Register
#define GPIOB_LCKR_LCKK                 16

#define GPIOC_BASE_ADDRESS              0x40011000
#define GPIOC_CRL                       *((volatile u32*)(GPIOC_BASE_ADDRESS + 0x00))  // PORT C configuration register low
#define GPIOC_CRH                       *((volatile u32*)(GPIOC_BASE_ADDRESS + 0x04))  // PORT C configuration register high
#define GPIOC_IDR                       *((volatile u32*)(GPIOC_BASE_ADDRESS + 0x08))  // PORT C input data register
#define GPIOC_ODR                       *((volatile u32*)(GPIOC_BASE_ADDRESS + 0x0C))  // PORT C Output Data Register
#define GPIOC_BSRR                      *((volatile u32*)(GPIOC_BASE_ADDRESS + 0x10))  // PORT C Bit Set/Reset Register
#define GPIOC_BRR                       *((volatile u32*)(GPIOC_BASE_ADDRESS + 0x14))  // PORT C Bit Reset Register
#define GPIOC_LCKR                      *((volatile u32*)(GPIOC_BASE_ADDRESS + 0x18))  // PORT C Configuration Lock Register
#define GPIOC_LCKR_LCKK                 16

/* INPUT/OUTPUT MODES FOR GPIO PINS */
#define IP_ANALOG                       0
#define IP_FLOATING                     4
#define IP_PULLED                       8
#define OP_PUSH_PULL_10_MHZ             1
#define OP_OPEN_DRAIN_10_MHZ            5
#define OP_AF_PUSH_PULL_10_MHZ          9
#define OP_AF_OPEN_DRAIN_10_MHZ         D
#define OP_PUSH_PULL_2_MHZ              2
#define OP_OPEN_DRAIN_2_MHZ             6
#define OP_AF_PUSH_PULL_2_MHZ           A
#define OP_AF_OPEN_DRAIN_2_MHZ          E
#define OP_PUSH_PULL_50_MHZ             3
#define OP_OPEN_DRAIN_50_MHZ            7
#define OP_AF_PUSH_PULL_50_MHZ          B
#define OP_AF_OPEN_DRAIN_50_MHZ         F

/*                      Concatenation function like macros and helpers for 8 digit hex number and 16 bit binary number                  */

#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)                                                        CONC_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)                                                 0x##b7##b6##b5##b4##b3##b2##b1##b0
#define DOUBLE_CONC(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0)                   DOUBLE_CONC_HELPER(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0)
#define DOUBLE_CONC_HELPER(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0)            0b##b15##b14##b13##b12##b11##b10##b9##b8##b7##b6##b5##b4##b3##b2##b1##b0

/*                                              Direction Macros for the three ports                                                     */
#define PORTA_DIR_L                                                                          CONC(PORTA_PIN7_DIR,PORTA_PIN6_DIR,PORTA_PIN5_DIR,PORTA_PIN4_DIR,PORTA_PIN3_DIR,PORTA_PIN2_DIR,PORTA_PIN1_DIR,PORTA_PIN0_DIR)
#define PORTA_DIR_H                                                                          CONC(PORTA_PIN15_DIR,PORTA_PIN14_DIR,PORTA_PIN13_DIR,PORTA_PIN12_DIR,PORTA_PIN11_DIR,PORTA_PIN10_DIR,PORTA_PIN9_DIR,PORTA_PIN8_DIR)
#define PORTB_DIR_L                                                                          CONC(PORTB_PIN7_DIR,PORTB_PIN6_DIR,PORTB_PIN5_DIR,PORTB_PIN4_DIR,PORTB_PIN3_DIR,PORTB_PIN2_DIR,PORTB_PIN1_DIR,PORTB_PIN0_DIR)
#define PORTB_DIR_H                                                                          CONC(PORTB_PIN15_DIR,PORTB_PIN14_DIR,PORTB_PIN13_DIR,PORTB_PIN12_DIR,PORTB_PIN11_DIR,PORTB_PIN10_DIR,PORTB_PIN9_DIR,PORTB_PIN8_DIR)
#define PORTC_DIR_L                                                                          CONC(PORTC_PIN7_DIR,PORTC_PIN6_DIR,PORTC_PIN5_DIR,PORTC_PIN4_DIR,PORTC_PIN3_DIR,PORTC_PIN2_DIR,PORTC_PIN1_DIR,PORTC_PIN0_DIR)
#define PORTC_DIR_H                                                                          CONC(PORTC_PIN15_DIR,PORTC_PIN14_DIR,PORTC_PIN13_DIR,PORTC_PIN12_DIR,PORTC_PIN11_DIR,PORTC_PIN10_DIR,PORTC_PIN9_DIR,PORTC_PIN8_DIR)

/*                                                Initial Value Macros for the three ports                                                   */
#define PORTA_INIT_VAL                                                                       DOUBLE_CONC(PORTA_PIN15_INIT_VAL,PORTA_PIN14_INIT_VAL,PORTA_PIN13_INIT_VAL,PORTA_PIN12_INIT_VAL,PORTA_PIN11_INIT_VAL,PORTA_PIN10_INIT_VAL,PORTA_PIN9_INIT_VAL,PORTA_PIN8_INIT_VAL,PORTA_PIN7_INIT_VAL,PORTA_PIN6_INIT_VAL,PORTA_PIN5_INIT_VAL,PORTA_PIN4_INIT_VAL,PORTA_PIN3_INIT_VAL,PORTA_PIN2_INIT_VAL,PORTA_PIN1_INIT_VAL,PORTA_PIN0_INIT_VAL)
#define PORTB_INIT_VAL                                                                       DOUBLE_CONC(PORTB_PIN15_INIT_VAL,PORTB_PIN14_INIT_VAL,PORTB_PIN13_INIT_VAL,PORTB_PIN12_INIT_VAL,PORTB_PIN11_INIT_VAL,PORTB_PIN10_INIT_VAL,PORTB_PIN9_INIT_VAL,PORTB_PIN8_INIT_VAL,PORTB_PIN7_INIT_VAL,PORTB_PIN6_INIT_VAL,PORTB_PIN5_INIT_VAL,PORTB_PIN4_INIT_VAL,PORTB_PIN3_INIT_VAL,PORTB_PIN2_INIT_VAL,PORTB_PIN1_INIT_VAL,PORTB_PIN0_INIT_VAL)
#define PORTC_INIT_VAL                                                                       DOUBLE_CONC(PORTC_PIN15_INIT_VAL,PORTC_PIN14_INIT_VAL,PORTC_PIN13_INIT_VAL,PORTC_PIN12_INIT_VAL,PORTC_PIN11_INIT_VAL,PORTC_PIN10_INIT_VAL,PORTC_PIN9_INIT_VAL,PORTC_PIN8_INIT_VAL,PORTC_PIN7_INIT_VAL,PORTC_PIN6_INIT_VAL,PORTC_PIN5_INIT_VAL,PORTC_PIN4_INIT_VAL,PORTC_PIN3_INIT_VAL,PORTC_PIN2_INIT_VAL,PORTC_PIN1_INIT_VAL,PORTC_PIN0_INIT_VAL)


#endif