/*=================================================================================*/
/*  File        : main.c                                                           */
/*  Description : This Program file i Drivers for stm32f401CC                      */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 17/6/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/

#include "MCAL/RCC/RCC_Interface.h"
#include "HAL/Led/Led_Interfance.h"
#include "MCAL/GPIO/Gpio_Interface.h"
#include "MCAL/NVIC/NVIC_Interface.h"
#include "MCAL/EXTI/EXTI_Interface.h"

void ON(void)
{
	LED_turn_on(GPIOA,PIN0);
}

void OFF(void)
{
	LED_turn_off(GPIOA,PIN0);
}


void main(void)
{
	RCC_voidInitSystemClock(HSI);

	/* 2 Switch  Configuration*/
	EXTI_PinConfig_t SWITCH_ON = {EXTI_GPIOA,EXTI_PIN1 ,EXTI_FALLING,ON};
	EXTI_PinConfig_t SWITCH_OFF = {EXTI_GPIOA,EXTI_PIN2,EXTI_FALLING,OFF};
	EXTI_u8PinInit(&SWITCH_ON);
	EXTI_u8PinInit(&SWITCH_OFF);


	/* Enable 2 Switch for turn on and off the led */
	GPIO_voidPinInit(GPIOA,PIN1,INPUT,PULL_UP,HIGH_SPEED);
	GPIO_voidPinInit(GPIOA,PIN2,INPUT,PULL_UP,HIGH_SPEED);

	/* Enable NVIC to use 2 Switch */
	NVIC_voidEnablePeripheral(EXTI1);
	NVIC_voidEnablePeripheral(EXTI2);

	/* Enable 2 Switch */
	EXTI_u8EnableINT(EXTI_PIN1);
	EXTI_u8EnableINT(EXTI_PIN2);

	/* Initialize the led */
	LED_Init(LED_PORT_A,LED_PIN0,LED_AHB1);
	for(;;)
	{

	}
}
