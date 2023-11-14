/*=================================================================================*/
/*  File        : EXTI_Config.h                                                    */
/*  Description : This Config file includes Driver for Led Matrix stm32f401CC      */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 26/6/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/

/* File Gaurd*/

#ifndef HAL_LED_MATRIX_LED_MATIX_CONFIG_H_
#define HAL_LED_MATRIX_LED_MATIX_CONFIG_H_


#define   LEDMAT_GPIOA      0
#define   LEDMAT_GPIOB      1
#define   LEDMAT_GPIOC      2

#define LED_MATRIX_ROWS_GPIO        LEDMAT_GPIOA
#define LED_MATRIX_COLS_GPIO        LEDMAT_GPIOB

#define LED_MATRIC_COLS_ENABLE      LOW
#define LED_MATRIC_COLS_DISABLE     HIGH

#define LED_MATRIC_ROWS_ENABLE      HIGH
#define LED_MATRIC_ROWS_DISABLE     LOW

#define LED_MATRIX_ROW0   PIN0
#define LED_MATRIX_ROW1   PIN1
#define LED_MATRIX_ROW2   PIN2
#define LED_MATRIX_ROW3   PIN3
#define LED_MATRIX_ROW4   PIN4
#define LED_MATRIX_ROW5   PIN5
#define LED_MATRIX_ROW6   PIN6
#define LED_MATRIX_ROW7   PIN7


#define LED_MATRIX_COL0   PIN0
#define LED_MATRIX_COL1   PIN1
#define LED_MATRIX_COL2   PIN5
#define LED_MATRIX_COL3   PIN6
#define LED_MATRIX_COL4   PIN7
#define LED_MATRIX_COL5   PIN8
#define LED_MATRIX_COL6   PIN9
#define LED_MATRIX_COL7   PIN10



#endif /* HAL_LED_MATRIX_LED_MATIX_CONFIG_H_ */
