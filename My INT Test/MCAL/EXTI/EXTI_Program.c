/*=================================================================================*/
/*  File        : EXTI_Program.c                                                   */
/*  Description : This Config file includes Driver for stm32f401CC                 */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 18/6/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
/*==========================================*/
#include "../../MCAL/RCC/RCC_Interface.h"
/*==========================================*/
#include "EXTI_Config.h"
#include "EXTI_Private.h"
#include "EXTI_Interface.h"
/*==========================================*/

static volatile  void(*EXTI_APF[16])(void) = {NULL_PTR};



/************************************************************************************************/
/* Function Name   : EXTI_u8PinInit                                                             */
/* Description     : Init Specific PIN at Specific PORT as an EXTI PIN                          */
/* Fun. Argument1  : EXTI_PinConfig_t * Copy_pstrPinInit { Pointer to Struct }                  */
/* Struct Element1 : PortID        -> { EXTI_GPIOA , EXTI_GPIOB , EXTI_GPIOC }                  */
/* Struct Element2 : PinID         -> { from EXTI_PIN0 -> EXTI_PIN15 }                          */
/* Struct Element3 : TriggerLevel  -> { EXTI_FALLING_EDGE, EXTI_RAISING_EDGE, EXTI_ON_CHANGE }  */
/* Struct Element4 : void (*PF)(void)  -> { CALLBACK Function to IRQHandler }                   */
/* Fun. Return     : Local_u8ErrorStatus                                                        */
/************************************************************************************************/
void EXTI_u8PinInit (const EXTI_PinConfig_t * Copy_pstrPinInit)
{
	u8 Local_u8ShiftValue = 0 ;

	if(((Copy_pstrPinInit->GPIO_ID) <= EXTI_GPIOC) && ((Copy_pstrPinInit->PIN_ID <= EXTI_PIN15)) && ((Copy_pstrPinInit->TRIGGER <= EXTI_ON_CHANGE)) && ((Copy_pstrPinInit->PF != NULL_PTR)))
	{

		/*---------------------------------------------------------------------------------------------------*/
		/* Enable Clock to SYSCFG Peripheral */
		RCC_voidEnablePeripheralClock(APB2,RCC_SYSCFG);
		/*---------------------------------------------------------------------------------------------------*/
		/* Enable Interrupt */
		EXTI_u8EnableINT(Copy_pstrPinInit->PIN_ID);
        /*---------------------------------------------------------------------------------------------------*/
		/* Set SYSCFG to select the PORT */
		Local_u8ShiftValue = (Copy_pstrPinInit->PIN_ID % 4) * 4;
		SYSCFG_REG->EXTICR[Copy_pstrPinInit->PIN_ID / 4] &=~ (0b1111 << Local_u8ShiftValue) ;
		SYSCFG_REG->EXTICR[Copy_pstrPinInit->PIN_ID / 4] &=~ ((Copy_pstrPinInit->GPIO_ID) << Local_u8ShiftValue) ;
        /*---------------------------------------------------------------------------------------------------*/
		/* Select Trigger Source (FALLING_EDGE , RAISING_EDGE , ON_CHANGE )*/
		switch(Copy_pstrPinInit->TRIGGER)
		{
		case EXTI_RAISING:
			SET_BIT(EXTI_REG->RTSR,Copy_pstrPinInit->PIN_ID);
			CLEAR_BIT(EXTI_REG->FTSR,Copy_pstrPinInit->PIN_ID);
			break;

		case EXTI_FALLING:
			CLEAR_BIT(EXTI_REG->RTSR,Copy_pstrPinInit->PIN_ID);
			SET_BIT(EXTI_REG->FTSR,Copy_pstrPinInit->PIN_ID);
			break;
		case EXTI_ON_CHANGE:
			SET_BIT(EXTI_REG->RTSR,Copy_pstrPinInit->PIN_ID);
			SET_BIT(EXTI_REG->FTSR,Copy_pstrPinInit->PIN_ID);
			break;
		default:
			break;
		}
	}

	/*---------------------------------------------------------------------------------------------------*/
	/* Set Global Pointer to Function */
	EXTI_APF[Copy_pstrPinInit->PIN_ID] = Copy_pstrPinInit->PF;
	/*---------------------------------------------------------------------------------------------------*/

}


/************************************************************************************************/
/* Function Name : EXTI_u8EnableINT                                                             */
/* Description   : Enable INT Linex from Line0 to Line15                                        */
/* Fun. Argument1: Copy_u8EXTINum { from EXTI_PIN0 -> EXTI_PIN15 }                              */
/* Fun. Return   : Local_u8ErrorStatus                                                          */
/************************************************************************************************/
void EXTI_u8EnableINT (u8 Copy_u8EXTINum)
{
	if(Copy_u8EXTINum <= EXTI_PIN15)
	{
		SET_BIT(EXTI_REG->IMR,Copy_u8EXTINum);
	}
}



/************************************************************************************************/
/* Function Name : EXTI_u8DisableINT                                                            */
/* Description   : Disable INT Linex from Line0 to Line15                                       */
/* Fun. Argument1: Copy_u8EXTINum { from EXTI_PIN0 -> EXTI_PIN15 }                              */
/* Fun. Return   : Local_u8ErrorStatus                                                          */
/************************************************************************************************/
void EXTI_u8DisableINT (u8 Copy_u8EXTINum)
{
	if(Copy_u8EXTINum <= EXTI_PIN15)
	{
		SET_BIT(EXTI_REG->EMR,Copy_u8EXTINum);
	}
}




/************************************************************************************************/
/* Function Name : EXTI_u8ClearPendingFlag                                                      */
/* Description   : Clear Pending Flag to Linex from Line0 to Line15                             */
/* Fun. Argument1: Copy_u8EXTINum { from EXTI_PIN0 -> EXTI_PIN15 }                              */
/* Fun. Return   : Local_u8ErrorStatus                                                          */
/************************************************************************************************/
void EXTI_u8ClearPendingFlag (u8 Copy_u8EXTINum)
{
	if(Copy_u8EXTINum <= EXTI_PIN15)
	{
		SET_BIT(EXTI_REG->PR,Copy_u8EXTINum);
	}
}



/*==============================================================================================*/
/*==================================         IRQ Handlers         ==============================*/
/*==============================================================================================*/
/***************************************/
/* Function Name : EXTI0_IRQHandler    */
/***************************************/

void EXTI0_IRQHandler(void)
{
	if(EXTI_APF[0] != NULL_PTR )
	{
		EXTI_APF[0]();
	}

	EXTI_u8ClearPendingFlag(0);
}



/***************************************/
/* Function Name : EXTI1_IRQHandler    */
/***************************************/

void EXTI1_IRQHandler(void)
{
	if(EXTI_APF[1] != NULL_PTR )
	{
		EXTI_APF[1]();
	}

	EXTI_u8ClearPendingFlag(1);
}


/***************************************/
/* Function Name : EXTI2_IRQHandler    */
/***************************************/

void EXTI2_IRQHandler(void)
{
	if(EXTI_APF[2] != NULL_PTR )
	{
		EXTI_APF[2]();
	}

	EXTI_u8ClearPendingFlag(2);
}




/***************************************/
/* Function Name : EXTI3_IRQHandler    */
/***************************************/

void EXTI3_IRQHandler(void)
{
	if(EXTI_APF[3] != NULL_PTR )
	{
		EXTI_APF[3]();
	}

	EXTI_u8ClearPendingFlag(3);
}



/***************************************/
/* Function Name : EXTI4_IRQHandler    */
/***************************************/

void EXTI4_IRQHandler(void)
{
	if(EXTI_APF[4] != NULL_PTR )
	{
		EXTI_APF[4]();
	}

	EXTI_u8ClearPendingFlag(4);
}




/***************************************/
/* Function Name : EXTI9_5_IRQHandler    */
/***************************************/

void EXTI9_5_IRQHandler(void)
{

	if(EXTI_APF[5] != NULL_PTR )
	{
		EXTI_APF[5]();
		EXTI_u8ClearPendingFlag(5);
	}
	if(EXTI_APF[6] != NULL_PTR )
	{
		EXTI_APF[6]();
		EXTI_u8ClearPendingFlag(6);
	}
	if(EXTI_APF[7] != NULL_PTR )
	{
		EXTI_APF[7]();
		EXTI_u8ClearPendingFlag(7);
	}
	if(EXTI_APF[8] != NULL_PTR )
	{
		EXTI_APF[8]();
		EXTI_u8ClearPendingFlag(8);
	}
	if(EXTI_APF[9] != NULL_PTR )
	{
		EXTI_APF[9]();
		EXTI_u8ClearPendingFlag(9);
	}
}




/***************************************/
/* Function Name : EXTI15_10_IRQHandler    */
/***************************************/

void EXTI15_10_IRQHandler()
{
	if(EXTI_APF[10] != NULL_PTR )
	{
		EXTI_APF[10]();
		EXTI_u8ClearPendingFlag(10);
	}
	if(EXTI_APF[11] != NULL_PTR )
	{
		EXTI_APF[11]();
		EXTI_u8ClearPendingFlag(11);
	}
	if(EXTI_APF[12] != NULL_PTR )
	{
		EXTI_APF[12]();
		EXTI_u8ClearPendingFlag(12);
	}
	if(EXTI_APF[13] != NULL_PTR )
	{
		EXTI_APF[13]();
		EXTI_u8ClearPendingFlag(13);
	}
	if(EXTI_APF[14] != NULL_PTR )
	{
		EXTI_APF[14]();
		EXTI_u8ClearPendingFlag(14);
	}
	if(EXTI_APF[15] != NULL_PTR )
	{
		EXTI_APF[15]();
		EXTI_u8ClearPendingFlag(15);
	}
}
