/*=================================================================================*/
/*  File        : EXTI_Pivate.h                                                    */
/*  Description : This Private file includes Driver for stm32f401CC                */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 18/6/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/

/* File Gaurd*/
#ifndef MCAL_EXTI_EXTI_PRIVATE_H_
#define MCAL_EXTI_EXTI_PRIVATE_H_


/*================================================================================================================*/
/**************************************       Private Macros & struct       ***************************************/
/*================================================================================================================*/

/*================================================================================================================*/
/*-----------------------------------------------(     SYSCFG     )-----------------------------------------------*/
/*================================================================================================================*/

/*
 * SYSCFG_REG ==> EXTICR
 * Choose Required port and pin to be an EXTI
 */

/*============     SYSCFG Base Address     ============*/
#define   SYSCFG_BASE_ADDRESS       0x40013800
#define   SYSCFG_REG               ((volatile SYSCFG_Memory*)(SYSCFG_BASE_ADDRESS))
/*============     [SYSCFG] Registers      ============*/
typedef struct
{
	volatile  u32 MEMRMP;
	volatile  u32 PMC;
	volatile  u32 EXTICR[4];
	volatile  u32 RESERVED[2] ;
	volatile  u32 CMPCR;

}SYSCFG_Memory;


/*==================================================================================================*/
/*----------------------------------------(     EXTI     )------------------------------------------*/
/*==================================================================================================*/

/*============     EXTI Base Address     ============*/
#define   EXTI_BASE_ADDRESS     0x40013C00
#define   EXTI_REG              ((volatile EXTI_Memory*)(EXTI_BASE_ADDRESS))

/*============     [EXTI] Registers      ============*/
typedef struct
{
	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RTSR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;
}EXTI_Memory;

/*
Interrupt mask register (EXTI_IMR)
Event mask register (EXTI_EMR)
Rising trigger selection register (EXTI_RTSR)
Falling trigger selection register (EXTI_FTSR)
Software interrupt event register (EXTI_SWIER)
Pending register (EXTI_PR)
*/


#endif /* MCAL_EXTI_EXTI_PRIVATE_H_ */
