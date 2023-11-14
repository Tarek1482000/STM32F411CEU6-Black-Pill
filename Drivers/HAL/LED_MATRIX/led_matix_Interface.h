/*=================================================================================*/
/*  File        : led_matix_Interface.h                                            */
/*  Description : This Interface file includes Driver for Led Matrix stm32f401CC   */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 26/6/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/

/* File Gaurd*/

#ifndef HAL_LED_MATRIX_LED_MATIX_INTERFACE_H_
#define HAL_LED_MATRIX_LED_MATIX_INTERFACE_H_




/*====================================================================================================*/
/*===========================    Tarek LED MATTIX Functions Prototypes      ==========================*/
/*====================================================================================================*/
/************************************************************************************************/
/* Function Name : LED_MATRIX_voidInt                                                           */
/* Description : Initialization of LDMT ROWS and Columns Pins                                   */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void LED_MATRIX_voidInt(void);


/************************************************************************************************/
/* Function Name : LED_MATRIX_voidDisable_all_cols                                              */
/* Description : Disable_all_cols                                                               */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void LED_MATRIX_voidDisable_all_cols(void);

/************************************************************************************************/
/* Function Name : LED_MATRIX_voidDisable_all_rows                                              */
/* Description : Disable_all_rows                                                               */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void LED_MATRIX_voidDisable_all_rows(void);

/************************************************************************************************/
/* Function Name : LED_MAT_u8Display                                                            */
/* Description : Display the required shape                                                     */
/* Fun. Argument1: Copy_pu8Data {Array of Shape to Display }                                    */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void LED_MAT_u8Display(u8 *Copy_pu8Data);

#endif /* HAL_LED_MATRIX_LED_MATIX_INTERFACE_H_ */
