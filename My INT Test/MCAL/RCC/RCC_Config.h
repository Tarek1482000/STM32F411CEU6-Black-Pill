/*=================================================================================*/
/*  File        : RCC_Config.h                                                     */
/*  Description : This Config file includes RCC Driver macros for stm32f401CC      */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 12/6/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/

/* File Gaurd*/
#ifndef MCAL_RCC_RCC_CONFIG_H_
#define MCAL_RCC_RCC_CONFIG_H_

/*=======================================*/
/*=========  Configration List   ========*/
/*=========      { PLL }         ========*/
/*=======================================*/
/*=======================================*/
/*=======================================*/
/*=========    AHB Prescaller    ========*/
#define system_clock_not_divided     0000
#define system_clock_divided_by_2    1000
#define system_clock_divided_by_4    1001
#define system_clock_divided_by_8    1010
#define system_clock_divided_by_16   1011
#define system_clock_divided_by_64   1100
#define system_clock_divided_by_128  1101
#define system_clock_divided_by_256  1110
#define system_clock_divided_by_512  1111

/*=======================================*/
#define AHB_PRESCALLER      system_clock_divided_by_2
/*=======================================*/

#endif /* MCAL_RCC_RCC_CONFIG_H_ */
