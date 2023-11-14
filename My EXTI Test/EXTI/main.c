/*=================================================================================*/
/*  File        : main.c                                                           */
/*  Description : This Program file i Drivers for stm32f401CC                      */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 17/6/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/

#include "MCAL/NVIC/NVIC_Interface.h"
#include "MCAL/EXTI/EXTI_Interface.h"
#include "MCAL/GPIO/Gpio_Interface.h"
#include "HAL/Seven_seg/Seven_seg_Interface.h"
#include "MCAL/RCC/RCC_Interface.h"

u8 G_SEVEN = 0 ;

void INC(void)
{
	G_SEVEN++;

	if(G_SEVEN > 99)
		G_SEVEN = 0;
}

void DEC(void)
{

	if(G_SEVEN > 0)
		G_SEVEN--;
}

void main(void)
{
	RCC_voidInitSystemClock(HSI);
	RCC_voidEnablePeripheralClock(AHB1,RCC_GPIOB);

	SEVEN_seg_init(SEV_SEG_PORTB,SEV_SEG_PIN0,SEV_SEG_PIN6,ANODE);
	SEVEN_seg_init(SEV_SEG_PORTA,SEV_SEG_PIN9,SEV_SEG_PIN15,ANODE);

	GPIO_voidPinInit(GPIOA,PIN0,INPUT,PULL_UP,HIGH_SPEED);
	GPIO_voidPinInit(GPIOA,PIN3,INPUT,PULL_UP,HIGH_SPEED);


	EXTI_PinConfig_t SW_INC = {EXTI_GPIOA,EXTI_PIN0,EXTI_FALLING,INC};
	EXTI_PinConfig_t SW_DEC = {EXTI_GPIOA,EXTI_PIN3,EXTI_FALLING,DEC};

	EXTI_u8PinInit(&SW_INC);
	EXTI_u8PinInit(&SW_DEC);

	EXTI_u8EnableINT(EXTI_PIN0);
	EXTI_u8EnableINT(EXTI_PIN3);

	NVIC_voidEnablePeripheral(EXTI0);
	NVIC_voidEnablePeripheral(EXTI3);


	for(;;)
	{
		SEVEN_seg_display_num(SEV_SEG_PORTB,SEV_SEG_PIN0,SEV_SEG_PIN6,ANODE,G_SEVEN % 10);
		SEVEN_seg_display_num(SEV_SEG_PORTA,SEV_SEG_PIN9,SEV_SEG_PIN15,ANODE,G_SEVEN / 10);
	}
}
