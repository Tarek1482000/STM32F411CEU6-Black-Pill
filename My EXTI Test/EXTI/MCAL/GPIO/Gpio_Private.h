/*=================================================================================*/
/*  File        : Gpio_Private.h                                                   */
/*  Description : This Private file includes Gpio Driver macros for stm32f401CC    */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 14/6/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/

/* File Gaurd*/
#ifndef MCAL_GPIO_GPIO_PRIVATE_H_
#define MCAL_GPIO_GPIO_PRIVATE_H_

#include "../../LIB/STD_TYPES.h"

/*================================================================================================================*/
/*******************************************       Private Macros       *******************************************/
/*================================================================================================================*/
/*============     GPIO Base Address     ============*/
#define GPIOA_BASE_ADDRESS      (0x40020000)
#define GPIOB_BASE_ADDRESS      (0x40020400)
#define GPIOC_BASE_ADDRESS      (0x40020800)

#define GPIOA_REG  ((volatile GPIOX_Memory_t*)(GPIOA_BASE_ADDRESS)) /* AHP1 */
#define GPIOB_REG  ((volatile GPIOX_Memory_t*)(GPIOB_BASE_ADDRESS)) /* AHP1 */
#define GPIOC_REG  ((volatile GPIOX_Memory_t*)(GPIOC_BASE_ADDRESS)) /* AHP1 */

typedef struct
{
   volatile u32 MODER;
   volatile u32 OTYPER;
   volatile u32 OSPEEDER;
   volatile u32 PUPDR;
   volatile u32 IDR;
   volatile u32 ODR;
   volatile u32 BSRR;
   volatile u32 LCKR;
   volatile u32 AFRL;
   volatile u32 AFRH;
}GPIOX_Memory_t;




#endif /* MCAL_GPIO_GPIO_PRIVATE_H_ */
