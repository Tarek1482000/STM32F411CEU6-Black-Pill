/*===================================================================================*/
/*  File        : SYSTICK_Interface.h                                                */
/*  Description : This Interface file includes SYSTICK Driver macros for stm32f401C  */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                     */
/*  Date        : 25/6/2023                                                          */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/             */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                   */
/*  mail        : tarekahmed0128@gmil.com                                            */
/*===================================================================================*/

/* File Gaurd*/
#ifndef MCAL_SYSTICK_SYSTIC_INTERFACE_H_
#define MCAL_SYSTICK_SYSTIC_INTERFACE_H_



/*====================================================================================================*/
/*==============================--==    Tarek SYSTICK Macros               ===========================*/
/*====================================================================================================*/

/*===========STK_CTRL_REG============*/
#define SYSTIC_ENABLE        0
#define SYSTIC_TICKINT       1
#define SYSTIC_CLKSOURCE     2
#define SYSTIC_COUNTFLAG     16
/*===================================*/


/*===========STK_LOAD_REG============*/
#define SYSTIC_RELOAD        0
/*===================================*/


/*===========STK_VAL_REG============*/
#define SYSTIC_CURRENT        0
/*===================================*/



/*===========STK_CALIB_REG============*/
#define SYSTIC_TENMS         0
#define SYSTIC_SKEW          30
#define SYSTIC_NOREF         31
/*===================================*/



/*===========STK_CALIB_REG============*/
#define STK_SingleInterval            0
#define STK_PeriodicInterval          1
/*===================================*/


/*====================================================================================================*/
/*==========================    Tarek SYSTICK Functions Prototypes         ===========================*/
/*====================================================================================================*/
/*********************************    STK_voidInit                       ******************************/
/*********************************    STK_voidSetBusyWait                ******************************/
/*********************************    STK_voidSetIntervalSingle          ******************************/
/*********************************    STK_voidSetIntervalPeriodic        ******************************/
/*********************************    STK_voidStopInterval               ******************************/
/*********************************    STK_u32GetElapsedTime              ******************************/
/*********************************    STK_u32GetRemainingTime            ******************************/
/*********************************    SysTick_Handler                    ******************************/
/*====================================================================================================*/


void STK_voidInit (void);
void STK_voidSetBusyWait(u32 Copy_u32TimeMs);
void STK_voidSetIntervalSingle  (u32 Copy_u32TimeMs,void (*Copy_ptr)(void));
void STK_voidSetIntervalPeriodic(u32 Copy_u32TimeMs,void (*Copy_ptr)(void));
void STK_voidStopInterval (void);
u32  STK_u32GetElapsedTime (void);
u32  STK_u32GetRemainingTime (void);


#endif /* MCAL_SYSTICK_SYSTIC_INTERFACE_H_ */
