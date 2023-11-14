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

#if(AHB_PRESCALLER == system_clock_not_divided)

	RCC_REG->RCC_CFGR |= (system_clock_not_divided << HPRE0);

#elif(AHB_PRESCALLER == system_clock_divided_by_2)

	RCC_REG->RCC_CFGR |= (system_clock_divided_by_2 << HPRE0);

#elif(AHB_PRESCALLER == system_clock_divided_by_4)

	RCC_REG->RCC_CFGR |= (system_clock_divided_by_4 << HPRE0);

#elif(AHB_PRESCALLER == system_clock_divided_by_8)

	RCC_REG->RCC_CFGR |= (system_clock_divided_by_8 << HPRE0);

#elif(AHB_PRESCALLER == system_clock_divided_by_16)

	RCC_REG->RCC_CFGR |= (system_clock_divided_by_16 << HPRE0);

#elif(AHB_PRESCALLER == system_clock_divided_by_64)

	RCC_REG->RCC_CFGR |= (system_clock_divided_by_64 << HPRE0);

#elif(AHB_PRESCALLER == system_clock_divided_by_128)

	RCC_REG->RCC_CFGR |= (system_clock_divided_by_128 << HPRE0);

#elif(AHB_PRESCALLER == system_clock_divided_by_256)

	RCC_REG->RCC_CFGR |= (system_clock_divided_by_256 << HPRE0);

#elif(AHB_PRESCALLER == system_clock_divided_by_512)

	RCC_REG->RCC_CFGR |= (system_clock_divided_by_512 << HPRE0);

#endif
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


