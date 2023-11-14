/*=================================================================================*/
/*  File        : RCC_Interface.h                                                  */
/*  Description : This Interfance file includes RCC Driver macros for stm32f401CC  */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 12/6/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/

/* File Gaurd*/
#ifndef MCAL_RCC_RCC_INTERFACE_H_
#define MCAL_RCC_RCC_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"

/*==========================================*/
/*============  Clock Source ID  ===========*/
/*==========================================*/
#define HSI				0
#define HSE_RC			1
#define HSE_OSC			2
#define PLL				3
/*=======================================*/
/*============     Bus ID     ===========*/
/*=======================================*/
#define AHB1			0
#define AHB2			1
#define APB1			2
#define APB2			3
/*=======================================*/

typedef enum
{
	RCC_GPIOA,
	RCC_GPIOB,
	RCC_GPIOC,
	RCC_GPIOD,
	RCC_GPIOE,
	RCC_GPIOH  = 7,
	RCC_CRCRST = 12,
	RCC_DMA1   = 21,
	RCC_DMA2   = 22
}RCC_AHB1;


typedef enum
{
	RCC_OTGFS = 7
}RCC_AHB2;


typedef enum
{
	RCC_TIM2,
	RCC_TIM3,
	RCC_TIM4,
	RCC_TIM5,
	RCC_WWDG     = 11,
	RCC_SPI2     = 14,
	RCC_SPI3     = 15,
	RCC_USART2   = 17,
	RCC_I2C1     = 21,
	RCC_I2C2     = 22,
	RCC_I2C3     = 23,
	RCC_PWR      = 28
}RCC_APB1;



typedef enum
{
	RCC_TIM1,
	RCC_USART1   = 4,
	RCC_USART6   = 5,
	RCC_ADC1     = 8,
	RCC_SDIO     = 11,
	RCC_SPI1     = 12,
	RCC_SPI4     = 13,
	RCC_SYSCFG   = 14,
	RCC_TIM9     = 16,
	RCC_TIM10    = 17,
	RCC_TIM11    = 18
}RCC_APB2;


/*======================================================================================================================*/
/*====================================   Tarek Ahmed RCC Functions Implementation      =================================*/
/*======================================================================================================================*/
/********************************************    RCC_voidInitSystemClock            *************************************/
/********************************************    RCC_voidEnablePeripheralClock      *************************************/ 
/********************************************    RCC_voidDisablePeripheralClock     *************************************/ 
/*======================================================================================================================*/

/************************************************************************************************/
/* Function Name : RCC_voidInitSystemClock                                                      */
/* Description : Initilization of RCC to initialize System clock                                */
/* Fun. Argument1: Copy_u8Clock_Source { HSI,HSE_RC,HSE_OSC,PLL }                               */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void RCC_voidInitSystemClock (u8 Copy_u8Clock_Source);

/************************************************************************************************/
/* Function Name : RCC_voidEnablePeripheralClock                                                */
/* Description : Enable clock source to specific Bus and spesific Peripheral                    */
/* Fun. Argument1: Copy_u8BusID { AHB1,AHB2,APB1,APB2 }                                         */
/* Fun. Argument2: Copy_u8PeripheralID { from 0 -> 32 according to Pheripheral }                */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void RCC_voidEnablePeripheralClock(u8 Copy_BusID, u8 Copy_PeripheralID);



/************************************************************************************************/
/* Function Name : RCC_voidDisablePeripheralClock                                               */
/* Description : Disable clock source to specific Bus and spesific Peripheral                   */
/* Fun. Argument1: Copy_u8BusID { AHB1,AHB2,APB1,APB2 }                                         */
/* Fun. Argument2: Copy_u8PeripheralID { from 0 -> 32 according to Pheripheral }                */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void RCC_voidDisablePeripheralClock(u8 Copy_BusID, u8 Copy_PeripheralID);
#endif /* MCAL_RCC_RCC_INTERFACE_H_ */
