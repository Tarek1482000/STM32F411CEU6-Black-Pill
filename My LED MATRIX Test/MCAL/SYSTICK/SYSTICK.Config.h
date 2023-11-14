/*=================================================================================*/
/*  File        : SYSTICk_Config.h                                                 */
/*  Description : This Config file includes SYSTICK Driver macros for stm32f401CC  */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 25/6/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/

/* File Gaurd*/
#ifndef MCAL_SYSTICK_SYSTIC_CONFIG_H_
#define MCAL_SYSTICK_SYSTIC_CONFIG_H_


/*==============================================*/
/*============  Select SYSTIC Source   =========*/
/*==============================================*/
#define AHB_CLOCK                           0
#define AHB_CLOCK_DividedBy_8               1
/*==============================================*/
#define STK_CLOCK_SOURCE    AHB_CLOCK_DividedBy_8
/*==============================================*/



#endif /* MCAL_SYSTICK_SYSTIC_CONFIG_H_ */
