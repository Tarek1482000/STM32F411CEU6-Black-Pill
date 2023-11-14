/*=================================================================================*/
/*  File        : NVIC_Interface.h                                                 */
/*  Description : This Interface file includes NVIC Driver macros for stm32f401CC  */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 14/6/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/

/* File Gaurd*/
#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"

/*====================================================================================================*/
/*===============================      Tarek NVIC User Macros       ==================================*/
/*====================================================================================================*/
#define GR16_SUB0      0b011 
#define GR8_SUB2       0b100
#define GR4_SUB4       0b101
#define GR2_SUB8       0b110
#define GR0_SUB16      0b111
/* Group priorities */
/* Sub priorities */
/*
0b011 : 3    ==> xxxx
0b100 : 4    ==> xxxy
0b101 : 5    ==> xxyy
0b110 : 6    ==> xyyy
0b111 : 7    ==> yyyy
 */
typedef enum
{
	WWDG,
	EXTI16_PVD,
	EXTI21_TAMP_STAMP,
	EXTI22_RTC_WKUP,
	FLASH,
	RCC,
	EXTI0,
	EXTI1,
	EXTI2,
	EXTI3,
	EXTI4,
	DMA1_Stream0,
	DMA1_Stream1,
	DMA1_Stream2,
	DMA1_Stream3,
	DMA1_Stream4,
	DMA1_Stream5,
	DMA1_Stream6,
	ADC,
	RESERVED19,
	RESERVED20,
	RESERVED21,
	RESERVED22,
	EXTI9_5,
	TIM1_BRK_TIM9,
	TIM1_BRK_TIM10,
	TIM1_TRG_COM_TIM11,
	TIM1_CC,
	TIM2,
	TIM3,
	TIM4,
	I2C1_EV,
	I2C1_ER,
	I2C2_EV,
	I2C2_ER,
	SPI1,
	SPI2,
	USART1,
	USART2,
	RESERVED39,
	EXTI15_10,
	EXTI17_RTC_Alarm,
	EXTI18_OTG_FS_WKUP,
	RESERVED43,
	RESERVED44,
	RESERVED45,
	RESERVED46,
	DMA1_Stream7,
	RESERVED48,
	SDIO,
	TIM5,
	SPI3,
	RESERVED52,
	RESERVED53,
	RESERVED54,
	RESERVED55,
	DMA2_Stream0,
	DMA2_Stream1,
	DMA2_Stream2,
	DMA2_Stream3,
	DMA2_Stream4,
	RESERVED61,
	RESERVED62,
	RESERVED63,
	RESERVED64,
	RESERVED65,
	RESERVED66,
	OTG_FS,
	DMA2_Stream5,
	DMA2_Stream6,
	DMA2_Stream7,
	USART6,
	I2C3_EV,
	I2C3_ER,
	RESERVED74,
	RESERVED75,
	RESERVED76,
	RESERVED77,
	RESERVED78,
	RESERVED79,
	RESERVED80,
	FPU,
	RESERVED82,
	RESERVED83,
	SPI4,
}INTERRUPTS;


/*====================================================================================================*/
/*============================      Tarek NVIC Functions Prototypes       ============================*/
/*====================================================================================================*/


/************************************************************************************************/
/* Function Name : NVIC_voidEnablePeripheral                                                    */
/* Description   : Enable Interrupt to Peripheral                                               */
/* Fun. Argument1: Copy_u8INTID { from 0 -> 240 | interface file enum(WWDG -> SPI4) }           */
/* Fun. Return   : void                                                                         */
/************************************************************************************************/
void NVIC_voidEnablePeripheral(u8 Copy_u8INITID);



/************************************************************************************************/
/* Function Name : NVIC_voidDisablePeripheral                                                   */
/* Description   : Disable Interrupt to Peripheral                                              */
/* Fun. Argument1: Copy_u8INTID { from 0 -> 240 | interface file enum(WWDG -> SPI4) }           */
/* Fun. Return   : void                                                                         */
/************************************************************************************************/
void NVIC_voidDisablePeripheral(u8 Copy_u8INITID);



/************************************************************************************************/
/* Function Name : NVIC_voidSetPendingFlag                                                      */
/* Description   : Set Pending Flag to any INT for Testing usage                                */
/* Fun. Argument1: Copy_u8INTID { from 0 -> 240 | interface file enum(WWDG -> SPI4) }           */
/* Fun. Return   : void                                                                         */
/************************************************************************************************/
void NVIC_voidSetPendingFlag(u8 Copy_u8INITID);


/************************************************************************************************/
/* Function Name : NVIC_voidClearPendingFlag                                                    */
/* Description   : Clear Pending Flag to any INT for Testing usage                              */
/* Fun. Argument1: Copy_u8INTID { from 0 -> 240 | interface file enum(WWDG -> SPI4) }           */
/* Fun. Return   : void                                                                         */
/************************************************************************************************/
void NVIC_voidClearPendingFlag(u8 Copy_u8INITID);


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
void NVIC_voidSetupPriorityConfiguration(u8 Copy_u8PriorityOption);



/************************************************************************************************/
/* Function Name : NVIC_voidSetINTPriority                                                      */
/* Description   : Set Software Priority for Peripheral INT                                     */
/* Fun. Argument1: Copy_u8INTID { from 0 -> 240 | interface file enum(WWDG -> SPI4) }           */
/* Fun. Argument2: Copy_u8GroupID    { from 0 -> 16 }                                           */
/* Fun. Argument2: Copy_u8SubGroupID { from 0 -> 16 }                                           */
/* Fun. Return   : void                                                                         */
/************************************************************************************************/
void NVIC_voidSetINTPriority(u8 Copy_u8INITID , u8 Copy_u8GroupID , u8 Copy_u8SubGroubID);



#endif /* NVIC_INTERFACE_H_ */
