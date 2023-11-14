/*=================================================================================*/
/*  File        : NVIC_Program.c                                                   */
/*  Description : This Program file includes NVIC Driver  for stm32f401CC          */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 14/6/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/

/*==========================================*/
/* Include Header Files From include Folder */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
/*==========================================*/
#include "NVIC_config.h"
#include "NVIC_Interface.h"
#include "NVIC_private.h"
/*==========================================*/

/*
  Num of Group and Subgroup
 */
u8 Global_u8PriorityOption = 0;



/*====================================================================================================*/
/*============================    Tarek NVIC Functions Implementation      ===========================*/
/*====================================================================================================*/

/************************************************************************************************/
/* Function Name : NVIC_voidEnablePeripheral                                                    */
/* Description   : Enable Interrupt to Peripheral                                               */
/* Fun. Argument1: Copy_u8INTID { from 0 -> 240 | interface file enum(WWDG -> SPI4) }           */
/* Fun. Return   : void                                                                         */
/************************************************************************************************/
void NVIC_voidEnablePeripheral(u8 Copy_u8INITID)
{
	NVIC_REG->ISER[Copy_u8INITID / 32] = (1<< (Copy_u8INITID % 32));
}

/************************************************************************************************/
/* Function Name : NVIC_voidDisablePeripheral                                                   */
/* Description   : Disable Interrupt to Peripheral                                              */
/* Fun. Argument1: Copy_u8INTID { from 0 -> 240 | interface file enum(WWDG -> SPI4) }           */
/* Fun. Return   : void                                                                         */
/************************************************************************************************/
void NVIC_voidDisablePeripheral(u8 Copy_u8INITID)
{
	NVIC_REG->ICER[Copy_u8INITID / 32] = (1<< (Copy_u8INITID % 32));
}

/************************************************************************************************/
/* Function Name : NVIC_voidSetPendingFlag                                                      */
/* Description   : Set Pending Flag to any INT for Testing usage                                */
/* Fun. Argument1: Copy_u8INTID { from 0 -> 240 | interface file enum(WWDG -> SPI4) }           */
/* Fun. Return   : void                                                                         */
/************************************************************************************************/
void NVIC_voidSetPendingFlag(u8 Copy_u8INITID)
{
	NVIC_REG->ISPR[Copy_u8INITID / 32] = (1<< (Copy_u8INITID % 32));
}


/************************************************************************************************/
/* Function Name : NVIC_voidClearPendingFlag                                                    */
/* Description   : Clear Pending Flag to any INT for Testing usage                              */
/* Fun. Argument1: Copy_u8INTID { from 0 -> 240 | interface file enum(WWDG -> SPI4) }           */
/* Fun. Return   : void                                                                         */
/************************************************************************************************/
void NVIC_voidClearPendingFlag(u8 Copy_u8INITID)
{
	NVIC_REG->ICPR[Copy_u8INITID / 32] = (1<< (Copy_u8INITID % 32));
}



/************************************************************************************************/
/* Function Name : NVIC_voidSetupPriorityConfiguration                                          */
/* Description   : Set Software Grouping Priority Configration                                  */
/* Fun. Argument1: Copy_u8PriorityOption                                                        */                
/*               (16 GR - 0  SubGR)    GR4BITS_SubGR0BITS   ->   0b011  (3)                     */
/*               (8  GR - 2  SubGR)    GR3BITS_SubGR1BITS   ->   0b100  (4)                     */
/*               (4  GR - 4  SubGR)    GR2BITS_SubGR2BITS   ->   0b101  (5)                     */
/*               (2  GR - 8  SubGR)    GR1BITS_SubGR3BITS   ->   0b110  (6)                     */
/*               (0  GR - 16 SubGR)    GR0BITS_SubGR4BITS   ->   0b111  (7)                     */                                                        
/* Fun. Return   : void                                                                         */
/************************************************************************************************/
void NVIC_voidSetupPriorityConfiguration(u8 Copy_u8PriorityOption)
{
	Global_u8PriorityOption = Copy_u8PriorityOption;
	SCB_AIRCR = VECTKEY | (Copy_u8PriorityOption << 8);
}


/************************************************************************************************/
/* Function Name : NVIC_voidSetINTPriority                                                      */
/* Description   : Set Software Priority for Peripheral INT                                     */
/* Fun. Argument1: Copy_u8INTID { from 0 -> 240 | interface file enum(WWDG -> SPI4) }           */
/* Fun. Argument2: Copy_u8GroupID    { from 0 -> 16 }                                           */
/* Fun. Argument2: Copy_u8SubGroupID { from 0 -> 16 }                                           */
/* Fun. Return   : void                                                                         */
/************************************************************************************************/
void NVIC_voidSetINTPriority(u8 Copy_u8INITID , u8 Copy_u8GroupID , u8 Copy_u8SubGroubID)
{
	if (Copy_u8INITID < 240)
	{
		u8 Local_u8Priorty = Copy_u8SubGroubID | (Copy_u8GroupID << (Global_u8PriorityOption - GR16_SUB0));
		NVIC_REG->IPR[Copy_u8INITID] = (Local_u8Priorty << 4);
	}

	/*
	assume NVIC_voidSetupPriorityConfiguration ===> GR2_SUB8       0b110 ==> xyyy
	assume NVIC_voidSetINTPriority  Gr ==> 1  SubG === 3

	Local_u8Priorty = 0011 |  (001) << (110 - 011) 

					= 0011 |   011  << 3
					= 1011
					  1  011 
					  |  |||>SG ==>3 
					  |>>G==>>1
	 */

	 	/*

	assume NVIC_voidSetupPriorityConfiguration ===> GR4_SUB4       0b101 ==> xxyy
	assume NVIC_voidSetINTPriority  Gr ==> 3  SubG === 0

	Local_u8Priorty = 0000 |  (011) << (101 - 011) 

					= 0000 |   011  << 2
					= 1100
					  11  00 
					  ||  ||>>SG ==>0 
					  || >>G==>>3
	 */
}


