/*=================================================================================*/
/*  File        : SYSTICK_Private.h                                                */
/*  Description : This Private file includes SYSTICK Driver macros for stm32f401CC */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 25/6/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/

/* File Gaurd*/
#ifndef MCAL_SYSTICK_SYSTIC_PRIVATE_H_
#define MCAL_SYSTICK_SYSTIC_PRIVATE_H_



/*================================================================================================================*/
/*******************************************       Private Macros       *******************************************/
/*================================================================================================================*/
#define  SYSTIC_BASE_ADDRESS    (0xE000E010)

#define  STK_CTRL            *(volatile u32*)(SYSTIC_BASE_ADDRESS + 0x00)
#define  STK_LOAD            *(volatile u32*)(SYSTIC_BASE_ADDRESS + 0x04)
#define  STK_VAL             *(volatile u32*)(SYSTIC_BASE_ADDRESS + 0x08)
#define  STK_CA              *(volatile u32*)(SYSTIC_BASE_ADDRESS + 0x0C)

/*================================================================================================================*/
/*==============================================*/
#define STK_SINGLE_INTERVAL         1
#define STK_PERIODIC_INTERVAL       2
/*==============================================*/


#endif /* MCAL_SYSTICK_SYSTIC_PRIVATE_H_ */
