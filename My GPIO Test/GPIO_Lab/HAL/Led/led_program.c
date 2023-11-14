/*
 * led.c
 *
 *  Created on: Jun 15, 2023
 *      Author: tarek
 */

#include "../../MCAL/RCC/RCC_Interface.h"
#include "../../MCAL/GPIO/Gpio_Interface.h"
#include "../../LIB/BIT_MATH.h"
#include "Led_Config.h"
#include "Led_Interfance.h"
#include "Led_Private.h"


void LED_Init(u8 Copy_u8PortID , u8 Copy_u8PinID, u8 Copy_u8PortBus)
{
	RCC_voidEnablePeripheralClock(Copy_u8PortBus,Copy_u8PortID);

	GPIO_voidPinInit(Copy_u8PortID,Copy_u8PinID,OUTPUT,PUSH_PULL,HIGH_SPEED);

	GPIO_voidSetPinValueNonAtomic(Copy_u8PortID,Copy_u8PinID,LOW);
}

void LED_turn_on(u8 Copy_u8PortID , u8 Copy_u8PinID)
{
GPIO_voidSetPinValueNonAtomic(Copy_u8PortID,Copy_u8PinID,HIGH);
}

void LED_turn_off(u8 Copy_u8PortID , u8 Copy_u8PinID)
{
GPIO_voidSetPinValueNonAtomic(Copy_u8PortID,Copy_u8PinID,LOW);
}
