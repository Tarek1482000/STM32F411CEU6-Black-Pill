/*=================================================================================*/
/*  File        : RCC_Program.c                                                     */
/*  Description : This Program file includes RCC Driver macros for stm32f401CC      */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                    */
/*  Date        : 12/6/2023                                                         */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/            */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                  */
/*  mail        : tarekahmed0128@gmil.com                                           */
/*=================================================================================*/

#include "../../LIB/bit_math.h"
#include"RCC_Interface.h"
#include"RCC_Config.h"
#include"RCC_Private.h"


/************************************************************************************************/
/* Function Name : RCC_voidInitSystemClock                                                      */
/* Description : Initilization of RCC to initialize System clock                                */
/* Fun. Argument1: Copy_u8Clock_Source { HSI,HSE_RC,HSE_OSC,PLL }                               */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void RCC_voidInitSystemClock (u8 Copy_u8Clock_Source)
{
 	if(Copy_u8Clock_Source == HSI)
 	{
		SET_BIT(RCC_REG->RCC_CR,HSION);	//Enable HSI
		/* Select HSI As Clock Source */
		CLEAR_BIT(RCC_REG->RCC_CFGR,SW0);
		CLEAR_BIT(RCC_REG->RCC_CFGR,SW1);
 	}
	else if (Copy_u8Clock_Source == HSE_RC)
	{
		SET_BIT(RCC_REG->RCC_CR,HSEON);	//Enable HSE
		SET_BIT(RCC_REG->RCC_CR,HSEBYP); //Enable ByPass
		/* Select HSE As Clock Source */
		SET_BIT(RCC_REG->RCC_CFGR,SW0);
		CLEAR_BIT(RCC_REG->RCC_CFGR,SW1);
	}
	else if (Copy_u8Clock_Source == HSE_OSC)
	{
		SET_BIT(RCC_REG->RCC_CR,HSEON);	  //Enable HSE
		CLEAR_BIT(RCC_REG->RCC_CR,HSEBYP); //Disable ByPass
		/* Select HSE As Clock Source */
		SET_BIT(RCC_REG->RCC_CFGR,SW0);
		CLEAR_BIT(RCC_REG->RCC_CFGR,SW1);
	}
	else if (Copy_u8Clock_Source == PLL)
	{
		
	}
}

/************************************************************************************************/
/* Function Name : RCC_voidEnablePeripheralClock                                                */
/* Description : Enable clock source to specific Bus and spesific Peripheral                    */
/* Fun. Argument1: Copy_u8BusID { AHB1,AHB2,APB1,APB2 }                                         */
/* Fun. Argument2: Copy_u8PeripheralID { from 0 -> 32 according to Pheripheral }                */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void RCC_voidEnablePeripheralClock(u8 Copy_BusID, u8 Copy_PeripheralID)
{
	switch(Copy_BusID)
	{
		case AHB1 :	SET_BIT(RCC_REG->RCC_AHB1ENR,Copy_PeripheralID); break ;
		case AHB2 :	SET_BIT(RCC_REG->RCC_AHB2ENR,Copy_PeripheralID); break ;
		case APB1 :	SET_BIT(RCC_REG->RCC_APB1ENR,Copy_PeripheralID); break ;
		case APB2 :	SET_BIT(RCC_REG->RCC_APB2ENR,Copy_PeripheralID); break ;
		default   : break;
	}
}


/************************************************************************************************/
/* Function Name : RCC_voidDisablePeripheralClock                                               */
/* Description : Disable clock source to specific Bus and spesific Peripheral                   */
/* Fun. Argument1: Copy_u8BusID { AHB1,AHB2,APB1,APB2 }                                         */
/* Fun. Argument2: Copy_u8PeripheralID { from 0 -> 32 according to Pheripheral }                */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void RCC_voidDisablePeripheralClock(u8 Copy_BusID, u8 Copy_PeripheralID)
{
	switch(Copy_BusID)
		{
			case AHB1 :	CLEAR_BIT(RCC_REG->RCC_AHB1ENR,Copy_PeripheralID); break;
			case AHB2 :	CLEAR_BIT(RCC_REG->RCC_AHB2ENR,Copy_PeripheralID); break;
			case APB1 :	CLEAR_BIT(RCC_REG->RCC_APB1ENR,Copy_PeripheralID); break;
			case APB2 :	CLEAR_BIT(RCC_REG->RCC_APB2ENR,Copy_PeripheralID); break;
			default   : break;
		}
}


