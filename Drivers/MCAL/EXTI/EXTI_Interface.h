/*=================================================================================*/
/*  File        : EXTI_Interface.c                                                 */
/*  Description : This Interface file includes Driver for stm32f401CC              */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 18/6/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/

/* File Gaurd*/
#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
/*============================================================================================*/
/*=============================  Steps in main to Active EXTIx  ==============================*/
/*============================================================================================*/

/* (1) Init of Pin as a INPUT ---------------------------------------------------------------*/
// GPIO_voidPinInit(GPIOx,PINx,INPUT,PULL_UP,LOW_SPEED);
/* (2) Define Object from struct contain {PORT,EXTI Line,Sense Control,CallBack Function} ---*/
// EXTI_PinConfig_t EXTI_x = {EXTI_GPIOx,EXTI_PINx,EXTI_FALLING_EDGE,&EXTIxFunc};
/* (3) Call Function EXTI_u8PinInit with Previous struct Object -----------------------------*/
// EXTI_u8PinInit (&EXTI_x);
/* (4) Enable Peripheral INT (EXTI_x) from NVIC --------------------------------------------*/
// NVIC_voidEnablePeripheralINT (x);
/*============================================================================================*/




/*================================================================================================================*/
/**************************************       Macros & Struct       ***********************************************/
/*================================================================================================================*/
typedef enum
{
	EXTI_GPIOA = 0b0000,
	EXTI_GPIOB = 0b0001,
	EXTI_GPIOC = 0b0010
}EXTI_GPIO;


typedef enum
{
	EXTI_PIN0,
	EXTI_PIN1,
	EXTI_PIN2,
	EXTI_PIN3,
    EXTI_PIN4,
	EXTI_PIN5,
	EXTI_PIN6,
    EXTI_PIN7,
	EXTI_PIN8,
	EXTI_PIN9,
    EXTI_PIN10,
	EXTI_PIN11,
	EXTI_PIN12,
    EXTI_PIN13,
	EXTI_PIN14,
	EXTI_PIN15,
}EXTI_PIN;

typedef enum
{
	EXTI_RAISING,
	EXTI_FALLING,
	EXTI_ON_CHANGE
}EXTI_RIGGER_LEVEL;


typedef struct
{
	EXTI_GPIO GPIO_ID;
	EXTI_PIN  PIN_ID;
	EXTI_RIGGER_LEVEL TRIGGER;
	void(*PF)(void);
}EXTI_PinConfig_t;



/*====================================================================================================*/
/*==============================     Tarek EXTI Functions Prototypes      ============================*/
/*====================================================================================================*/
void EXTI_u8PinInit (const EXTI_PinConfig_t * Copy_pstrPinInit);
void EXTI_u8EnableINT (u8 Copy_u8EXTINum);
void EXTI_u8DisableINT (u8 Copy_u8EXTINum);
void EXTI_u8ClearPendingFlag (u8 Copy_u8EXTINum);




#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
