/*
 * Seven_seg.c
 *
 *  Created on: Oct 12, 2022
 *      Author: tarek
 */


#include "Seven_seg_Private.h"
#include "Seven_seg_Config.h"
#include "Seven_seg_Interface.h"
#include "../../MCAL/RCC/RCC_Interface.h"
#include "../../MCAL/GPIO/Gpio_Interface.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

void SEVEN_seg_init(u8 Copy_u8PortID,u8 Copy_pin_start ,u8 Copy_pin_end ,u8 Copy_u8type)
{
	u8 turn_on = 0 ,digit = 0;
	/* Enable Peripheral Clock */
	RCC_voidEnablePeripheralClock(AHB1,Copy_u8PortID); 

	if(Copy_u8type == ANODE)
	{
		for(turn_on = Copy_pin_start ; turn_on <= Copy_pin_end ; turn_on++)
		{
			GPIO_voidPinInit(Copy_u8PortID,turn_on,OUTPUT,PUSH_PULL,HIGH_SPEED);
			GPIO_voidSetPinValueNonAtomic(Copy_u8PortID,turn_on,GET_BIT(seven_seg_A_num[0],digit));
			digit++;
		}
	}
	else if(Copy_u8type == CATHODE)
	{
		for(turn_on = Copy_pin_start ; turn_on <= Copy_pin_end ; turn_on++)
		{
			GPIO_voidPinInit(Copy_u8PortID,turn_on,OUTPUT,PUSH_PULL,HIGH_SPEED);
			GPIO_voidSetPinValueNonAtomic(Copy_u8PortID,turn_on,GET_BIT(seven_seg_C_num[0],digit));
			digit++;
		}
	}
}

void SEVEN_seg_display_num(u8 Copy_u8PortID,u8 Copy_pin_start ,u8 Copy_pin_end ,u8 Copy_u8type,u8 num)
{
	u8 turn_on = 0 , digit = 0;

	if(Copy_u8type == ANODE)
	{
		for(turn_on = Copy_pin_start ; turn_on <= Copy_pin_end ; turn_on++)
		{
			GPIO_voidSetPinValueNonAtomic(Copy_u8PortID,turn_on,GET_BIT(seven_seg_A_num[num],digit));
			digit++;
		}
	}
	else if(Copy_u8type == CATHODE)
	{
		for(turn_on = Copy_pin_start ; turn_on <= Copy_pin_end ; turn_on++)
		{
			GPIO_voidSetPinValueNonAtomic(Copy_u8PortID,turn_on,GET_BIT(seven_seg_C_num[num],digit));
			digit++;
		}
	}

}


