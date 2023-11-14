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
#include "HAL/Seven_seg/Seven_seg_Interface.h"
#include "MCAL/GPIO/Gpio_Interface.h"

void APP_voidDelay(u32 Copy_u32Delay)
{
	for(u32 i=0;i<(Copy_u32Delay * 300) ; i++)
	{
		asm("NOP");
	}
}

void main(void)
{
	RCC_voidInitSystemClock(HSI);
	  u8 display = 0;
	  s8 loop = 0;

	  LED_Init(LED_PORT_B , LED_PIN0 , LED_AHB1);
	  LED_Init(LED_PORT_B , LED_PIN1 , LED_AHB1);
	  LED_Init(LED_PORT_B , LED_PIN2 , LED_AHB1);
	  LED_Init(LED_PORT_B , LED_PIN3 , LED_AHB1);
	  LED_Init(LED_PORT_B , LED_PIN4 , LED_AHB1);
	  LED_Init(LED_PORT_B , LED_PIN5 , LED_AHB1);
	  LED_Init(LED_PORT_B , LED_PIN6 , LED_AHB1);
	  LED_Init(LED_PORT_B , LED_PIN7 , LED_AHB1);
	  LED_Init(LED_PORT_B , LED_PIN8 , LED_AHB1);

	  SEVEN_seg_init(SEV_SEG_PORTA ,0,6,ANODE);
	  SEVEN_seg_init(SEV_SEG_PORTA ,7,13,ANODE);
	for(;;)
	{
		  for(loop=0;loop<9;loop++)
		  {
		  	LED_turn_on(LED_PORT_B , loop);
		  	APP_voidDelay(1000);
		  	LED_turn_off(LED_PORT_B , loop);
		  }

		  display++;
		  if(display == 99)
		  	display=0;
		  SEVEN_seg_display_num(SEV_SEG_PORTA,0,6,ANODE,display%10);
		  SEVEN_seg_display_num(SEV_SEG_PORTA,7,13,ANODE,display/10);

		  for(loop=6;loop >=0 ;loop--)
		  {
		  	LED_turn_on(LED_PORT_B , loop);
		  	APP_voidDelay(1000);
		  	LED_turn_off(LED_PORT_B , loop);
		  }

		  display++;
		  if(display == 99)
		  	display=0;
		  SEVEN_seg_display_num(SEV_SEG_PORTA,0,6,ANODE,display%10);
		  SEVEN_seg_display_num(SEV_SEG_PORTA,7,13,ANODE,display/10);
	}
}
