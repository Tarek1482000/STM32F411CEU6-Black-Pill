/*=================================================================================*/
/*  File        : main.c                                                           */
/*  Description : This Program file i Drivers for stm32f401CC                      */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 17/6/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/

#include "HAL/LED_MATRIX/led_matix_Interface.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/GPIO/Gpio_Interface.h"
#include "MCAL/RCC/RCC_Interface.h"
#include "MCAL/SYSTICK/SYSTICK.Interface.h"

/*
 * T
 * a
 * r
 * e
 * k
 */
u8 arr[40][8] = {
		       /* T */
		{0, 0, 56, 16, 16,16,0,0},
		{0, 0, 28, 8, 8, 8, 0, 0},
		{0, 0, 14, 4, 4, 4, 0, 0},
		{0, 0, 7 , 2, 2, 2, 0, 0},
		{0, 0, 3,129,129,129,0,0},
		{0, 0, 129,64,192,64,0,0},

	       	  /* A */
		{0,0,64,160,224,160,0, 0},
		{0,0,32,80,112, 80, 0, 0},
		{0,0,16,40,56, 40,  0, 0},
		{0, 0, 8, 20, 28,20,0, 0},
		{0, 0, 4, 10, 14,10,0, 0},
		{0,0,130,133,135,133,0,0},
		{0, 0, 193,66,195,66,0,0},
		{0,0,224, 161,225,33,0,0},

		      /* r */
		{0,0, 112,80,112,144,0,0},
		{0,0,56,40, 56, 72, 0, 0},
		{0, 0, 28, 20, 28,36,0,0},
		{0, 0, 14, 10, 14,18,0,0},
		{0, 0, 7, 5, 7, 9, 0,  0},


		      /* e */

		{0,0,131,130,131,132,128,0},
		{0, 0, 193,65,193,66,192,0},
		{0, 0,224,32,224,32,224, 0},
		{0, 0,112,16,112,16,112, 0},
		{0, 0, 56, 8, 56, 8, 56, 0},
		{0, 0, 28, 4, 28, 4, 28, 0},
		{0, 0, 14, 2, 14, 2, 14, 0},
		{0,0,135,129,135,129,135,0},
      		  /* k */
		{0, 0, 67, 64, 195,64,67,0},
		{0, 0, 33, 160,97,160,33,0},
		{0, 0, 144, 80,48,80,144,0},
		{0, 0, 72, 40, 24, 40,72,0},
		{0, 0, 36, 20, 12, 20,36,0},
		{0,0, 18, 10, 6, 10, 18, 0},
		{0, 0, 137,  5, 3, 5, 9, 0},
		{0, 0, 196,130,129,130,4,0},
		{0, 0, 226, 65, 64, 65,2,0},
		{0, 0, 113, 32, 32, 32,1,0},
};

u8 i = 0;

void LED_AT (void)
{
	i++;
	if(i == 5)
		i=0;
}

void main(void)
{

	RCC_voidInitSystemClock(HSI);
	RCC_voidEnablePeripheralClock(AHB1,GPIOA);
	RCC_voidEnablePeripheralClock(AHB1,GPIOB);
	STK_voidInit();

	LED_MATRIX_voidInt();
	STK_voidInit();



	for(;;)
	{
		/*
		 * 2ms * 300 = 600ms  frame delay
		 */
		for(s16 j=0;j<300;j++)
		{
			LED_MAT_u8Display(arr[i]);
		}
		i++;
		if(i == 38)
			i=0;
//		STK_voidSetBusyWait(2000);
	}
}
