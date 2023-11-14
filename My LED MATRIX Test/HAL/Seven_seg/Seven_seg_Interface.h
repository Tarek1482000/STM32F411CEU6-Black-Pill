/*
 * Seven_deg_Interface.h
 *
 *  Created on: Jun 16, 2023
 *      Author: tarek
 */

#ifndef HAL_SEVEN_SEG_SEVEN_DEG_INTERFACE_H_
#define HAL_SEVEN_SEG_SEVEN_DEG_INTERFACE_H_


#include "../../LIB/STD_TYPES.h"

#define SEV_SEG_PORTA   0
#define SEV_SEG_PORTB   1
#define SEV_SEG_PORTC   2


#define SEV_SEG_PIN0        0
#define SEV_SEG_PIN1        1
#define SEV_SEG_PIN2        2
#define SEV_SEG_PIN3        3
#define SEV_SEG_PIN4        4
#define SEV_SEG_PIN5        5
#define SEV_SEG_PIN6        6
#define SEV_SEG_PIN7        7
#define SEV_SEG_PIN8        8
#define SEV_SEG_PIN9        9
#define SEV_SEG_PIN10       10
#define SEV_SEG_PIN11       11
#define SEV_SEG_PIN12       12
#define SEV_SEG_PIN13       13
#define SEV_SEG_PIN14       14
#define SEV_SEG_PIN15       15



#define ANODE   0
#define CATHODE 1

void SEVEN_seg_init(u8 Copy_u8PortID,u8 Copy_pin_start ,u8 Copy_pin_end ,u8 Copy_u8type);

void SEVEN_seg_display_num(u8 Copy_u8PortID,u8 Copy_pin_start ,u8 Copy_pin_end ,u8 Copy_u8type,u8 num);

#endif /* HAL_SEVEN_SEG_SEVEN_DEG_INTERFACE_H_ */
