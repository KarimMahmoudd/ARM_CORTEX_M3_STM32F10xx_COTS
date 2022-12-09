/*************************************************************************************************************************************/
/*  Author      : Karim Mahmoud                                                                                                      */
/*  Date        : 25 NOV 2022                                                                                                        */
/*  Layer       : MCAL                                                                                                               */
/*  SWC         : GPIO                                                                                                               */
/*  Version     : V01                                                                                                                */
/*************************************************************************************************************************************/

#ifndef GPIO_CONFIG_H
#define GPIO_CONFIG_H
/* Options:
            1-  IP_ANALOG              
            2-  IP_FLOATING            
            3-  IP_PULLED                        
            4-  OP_PUSH_PULL_10_MHZ    
            5-  OP_OPEN_DRAIN_10_MHZ   
            6-  OP_AF_PUSH_PULL_10_MHZ 
            7-  OP_AF_OPEN_DRAIN_10_MHZ
            8-  OP_PUSH_PULL_2_MHZ     
            9-  OP_OPEN_DRAIN_2_MHZ    
            10- OP_AF_PUSH_PULL_2_MHZ  
            11- OP_AF_OPEN_DRAIN_2_MHZ 
            12- OP_PUSH_PULL_50_MHZ    
            13- OP_OPEN_DRAIN_50_MHZ   
            14- OP_AF_PUSH_PULL_50_MHZ 
            15- OP_AF_OPEN_DRAIN_50_MHZ
                                                             */

#define PORTA_PIN0_DIR                 OP_PUSH_PULL_2_MHZ
#define PORTA_PIN1_DIR                 OP_PUSH_PULL_2_MHZ
#define PORTA_PIN2_DIR                 OP_PUSH_PULL_2_MHZ
#define PORTA_PIN3_DIR                 OP_PUSH_PULL_2_MHZ
#define PORTA_PIN4_DIR                 OP_PUSH_PULL_2_MHZ
#define PORTA_PIN5_DIR                 OP_PUSH_PULL_2_MHZ
#define PORTA_PIN6_DIR                 OP_PUSH_PULL_2_MHZ
#define PORTA_PIN7_DIR                 OP_PUSH_PULL_2_MHZ
#define PORTA_PIN8_DIR                 OP_PUSH_PULL_2_MHZ
#define PORTA_PIN9_DIR                 OP_PUSH_PULL_2_MHZ
#define PORTA_PIN10_DIR                OP_PUSH_PULL_2_MHZ
#define PORTA_PIN11_DIR                OP_PUSH_PULL_2_MHZ
#define PORTA_PIN12_DIR                OP_PUSH_PULL_2_MHZ
#define PORTA_PIN13_DIR                OP_PUSH_PULL_2_MHZ
#define PORTA_PIN14_DIR                OP_PUSH_PULL_2_MHZ
#define PORTA_PIN15_DIR                OP_PUSH_PULL_2_MHZ

#define PORTB_PIN0_DIR                 OP_PUSH_PULL_2_MHZ
#define PORTB_PIN1_DIR                 OP_PUSH_PULL_2_MHZ
#define PORTB_PIN2_DIR                 OP_PUSH_PULL_2_MHZ
#define PORTB_PIN3_DIR                 OP_PUSH_PULL_2_MHZ
#define PORTB_PIN4_DIR                 OP_PUSH_PULL_2_MHZ
#define PORTB_PIN5_DIR                 OP_PUSH_PULL_2_MHZ
#define PORTB_PIN6_DIR                 OP_PUSH_PULL_2_MHZ
#define PORTB_PIN7_DIR                 OP_PUSH_PULL_2_MHZ
#define PORTB_PIN8_DIR                 OP_PUSH_PULL_2_MHZ
#define PORTB_PIN9_DIR                 OP_PUSH_PULL_2_MHZ
#define PORTB_PIN10_DIR                OP_PUSH_PULL_2_MHZ
#define PORTB_PIN11_DIR                OP_PUSH_PULL_2_MHZ
#define PORTB_PIN12_DIR                OP_PUSH_PULL_2_MHZ
#define PORTB_PIN13_DIR                OP_PUSH_PULL_2_MHZ
#define PORTB_PIN14_DIR                OP_PUSH_PULL_2_MHZ
#define PORTB_PIN15_DIR                OP_PUSH_PULL_2_MHZ

#define PORTC_PIN0_DIR                 OP_PUSH_PULL_2_MHZ
#define PORTC_PIN1_DIR                 OP_PUSH_PULL_2_MHZ
#define PORTC_PIN2_DIR                 OP_PUSH_PULL_2_MHZ
#define PORTC_PIN3_DIR                 OP_PUSH_PULL_2_MHZ
#define PORTC_PIN4_DIR                 OP_PUSH_PULL_2_MHZ
#define PORTC_PIN5_DIR                 OP_PUSH_PULL_2_MHZ
#define PORTC_PIN6_DIR                 OP_PUSH_PULL_2_MHZ
#define PORTC_PIN7_DIR                 OP_PUSH_PULL_2_MHZ
#define PORTC_PIN8_DIR                 OP_PUSH_PULL_2_MHZ
#define PORTC_PIN9_DIR                 OP_PUSH_PULL_2_MHZ
#define PORTC_PIN10_DIR                OP_PUSH_PULL_2_MHZ
#define PORTC_PIN11_DIR                OP_PUSH_PULL_2_MHZ
#define PORTC_PIN12_DIR                OP_PUSH_PULL_2_MHZ
#define PORTC_PIN13_DIR                OP_PUSH_PULL_2_MHZ
#define PORTC_PIN14_DIR                OP_PUSH_PULL_2_MHZ
#define PORTC_PIN15_DIR                OP_PUSH_PULL_2_MHZ



/* choose: 0 OR 1*/
#define PORTA_PIN0_INIT_VAL                 0
#define PORTA_PIN1_INIT_VAL                 0
#define PORTA_PIN2_INIT_VAL                 0
#define PORTA_PIN3_INIT_VAL                 0
#define PORTA_PIN4_INIT_VAL                 0
#define PORTA_PIN5_INIT_VAL                 0
#define PORTA_PIN6_INIT_VAL                 0
#define PORTA_PIN7_INIT_VAL                 0
#define PORTA_PIN8_INIT_VAL                 0
#define PORTA_PIN9_INIT_VAL                 0
#define PORTA_PIN10_INIT_VAL                0
#define PORTA_PIN11_INIT_VAL                0
#define PORTA_PIN12_INIT_VAL                0
#define PORTA_PIN13_INIT_VAL                0
#define PORTA_PIN14_INIT_VAL                0
#define PORTA_PIN15_INIT_VAL                0

#define PORTB_PIN0_INIT_VAL                 0
#define PORTB_PIN1_INIT_VAL                 0
#define PORTB_PIN2_INIT_VAL                 0
#define PORTB_PIN3_INIT_VAL                 0
#define PORTB_PIN4_INIT_VAL                 0
#define PORTB_PIN5_INIT_VAL                 0
#define PORTB_PIN6_INIT_VAL                 0
#define PORTB_PIN7_INIT_VAL                 0
#define PORTB_PIN8_INIT_VAL                 0
#define PORTB_PIN9_INIT_VAL                 0
#define PORTB_PIN10_INIT_VAL                0
#define PORTB_PIN11_INIT_VAL                0
#define PORTB_PIN12_INIT_VAL                0
#define PORTB_PIN13_INIT_VAL                0
#define PORTB_PIN14_INIT_VAL                0
#define PORTB_PIN15_INIT_VAL                0

#define PORTC_PIN0_INIT_VAL                 0
#define PORTC_PIN1_INIT_VAL                 0
#define PORTC_PIN2_INIT_VAL                 0
#define PORTC_PIN3_INIT_VAL                 0
#define PORTC_PIN4_INIT_VAL                 0
#define PORTC_PIN5_INIT_VAL                 0
#define PORTC_PIN6_INIT_VAL                 0
#define PORTC_PIN7_INIT_VAL                 0
#define PORTC_PIN8_INIT_VAL                 0
#define PORTC_PIN9_INIT_VAL                 0
#define PORTC_PIN10_INIT_VAL                0
#define PORTC_PIN11_INIT_VAL                0
#define PORTC_PIN12_INIT_VAL                0
#define PORTC_PIN13_INIT_VAL                0
#define PORTC_PIN14_INIT_VAL                0
#define PORTC_PIN15_INIT_VAL                0



#endif