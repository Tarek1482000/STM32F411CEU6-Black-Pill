/*=================================================================================*/
/*  File        : led_matix_Program.c                                              */
/*  Description : This program file includes Driver for Led Matrix stm32f401CC     */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 26/6/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/

/* File Gaurd*/

#include "../../MCAL/GPIO/Gpio_Interface.h"
#include "../../MCAL/SYSTICK/SYSTICK.Interface.h"
#include "led_matix_Config.h"
#include "led_matix_Interface.h"
#include "led_matix_Private.h"



/************************************************************************************************/
/* Function Name : LED_MATRIX_voidInt                                                           */
/* Description : Initialization of LDMT ROWS and Columns Pins                                   */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void LED_MATRIX_voidInt(void)
{
	for(u8 iter = 0 ; iter < 8 ; iter++)
	{
		GPIO_voidPinInit(LED_MATRIX_ROWS_GPIO, iter, OUTPUT,  PUSH_PULL,  LOW_SPEED);

	}

	for(u8 iter = 0 ; iter < 11 ; iter++)
	{
		if(iter == 2 || iter == 3 || iter == 4)
		{
			continue;
		}
		else
		{
			GPIO_voidPinInit(LED_MATRIX_COLS_GPIO, iter, OUTPUT,  PUSH_PULL,  LOW_SPEED);
		}


	}
}

/************************************************************************************************/
/* Function Name : LED_MATRIX_voidDisable_all_cols                                              */
/* Description : Disable_all_cols                                                               */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void LED_MATRIX_voidDisable_all_cols(void)
{
	for(u8 iter = 0 ; iter < 11 ; iter++)
	{
		if(iter == 2 || iter == 3 || iter == 4)
		{
			continue;
		}
		else
		{
			GPIO_voidSetPinValueNonAtomic( LED_MATRIX_COLS_GPIO, iter,  LED_MATRIC_COLS_DISABLE);
		}
	}
}


/************************************************************************************************/
/* Function Name : LED_MATRIX_voidDisable_all_rows                                              */
/* Description : Disable_all_rows                                                               */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void LED_MATRIX_voidDisable_all_rows(void)
{
	for(u8 iter = 0 ; iter < 8 ; iter++)
	{
		GPIO_voidSetPinValueAtomic( LED_MATRIX_ROWS_GPIO, iter,  LED_MATRIC_ROWS_DISABLE);
	}
}


/************************************************************************************************/
/* Function Name : LED_MATRIX_voidSet_ROWS_value                                                */
/* Description : Set_ROWS_value                                                                 */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
static void LED_MATRIX_voidSet_ROWS_value(u8 Copy_u8Value)
{
	GPIO_voidSetLeastPortValueNonAtomic(LED_MATRIX_ROWS_GPIO, Copy_u8Value);
}



/************************************************************************************************/
/* Function Name : LED_MAT_u8Display                                                            */
/* Description : Display the required shape                                                     */
/* Fun. Argument1: Copy_pu8Data {Array of Shape to Display }                                    */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void LED_MAT_u8Display(u8 *Copy_pu8Data)
{
	u8 col_iter = 0 , ArrayIteration = 0;

	for(col_iter = 0 ; col_iter < 11 ; col_iter++)
	{
		if(col_iter == 2 || col_iter == 3 || col_iter == 4)
		{
			continue;
		}
		LED_MATRIX_voidDisable_all_cols();
		LED_MATRIX_voidSet_ROWS_value(Copy_pu8Data[ArrayIteration]);
		GPIO_voidSetPinValueNonAtomic(LED_MATRIX_COLS_GPIO,col_iter ,LOW);
		STK_voidSetBusyWait(2);
		ArrayIteration++;
	}
}
