/*
 * Led_Interfance.h
 *
 *  Created on: Jun 16, 2023
 *      Author: tarek
 */

#ifndef HAL_LED_LED_INTERFANCE_H_
#define HAL_LED_LED_INTERFANCE_H_

#define LED_PORT_A     0
#define LED_PORT_B     1
#define LED_PORT_C     2

#define LED_PIN0       0  
#define LED_PIN1       1  
#define LED_PIN2       2  
#define LED_PIN3       3  
#define LED_PIN4       4  
#define LED_PIN5       5  
#define LED_PIN6       6  
#define LED_PIN7       7  
#define LED_PIN8       8  
#define LED_PIN9       9  
#define LED_PIN10      10 
#define LED_PIN11      11 
#define LED_PIN12      12 
#define LED_PIN13      13 
#define LED_PIN14      14 
#define LED_PIN15      15 


/*
 PORTA  : AHB1
 PORTB  : AHB1
 PORTC  : AHB1
*/
#define LED_AHB1			0
#define LED_AHB2			1
#define LED_APB1			2
#define LED_APB2			3


void LED_Init(u8 Copy_u8PortID , u8 Copy_u8PinID, u8 Copy_u8PortBus);
void LED_turn_on(u8 Copy_u8PortID , u8 Copy_u8PinID);
void LED_turn_off(u8 Copy_u8PortID , u8 Copy_u8PinID);

#endif /* HAL_LED_LED_INTERFANCE_H_ */
