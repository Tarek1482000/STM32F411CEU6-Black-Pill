/*=================================================================================*/
/*  File        : Gpio_Interface.h                                                 */
/*  Description : This Interfac file includes Gpio Driver macros for stm32f401CC   */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 14/6/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/

/* File Gaurd*/
#ifndef MCAL_GPIO_GPIO_INTERFACE_H_
#define MCAL_GPIO_GPIO_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"

/*=============================*/
#define   GPIOA             0
#define   GPIOB             1
#define   GPIOC             2
#define GPIO_BUS            AHB1
/*=============================*/
#define   INPUT             0
#define   OUTPUT            1
#define   AF                2
#define   ANALOG            3
/*=============================*/
#define   PUSH_PULL         0
#define   OPEN_DRAIN        1
#define   PULL_UP           2
#define   PULL_DOWN         3
/*=============================*/
#define   LOW_SPEED         0
#define   MEDIUM_SPEED      1
#define   HIGH_SPEED        2
/*=============================*/
#define   LOW               0
#define   HIGH              1
/*=============================*/
#define   RST               0
#define   SET               1
/*=============================*/

#define   PIN0              0 
#define   PIN1              1 
#define   PIN2              2 
#define   PIN3              3 
#define   PIN4              4 
#define   PIN5              5 
#define   PIN6              6 
#define   PIN7              7 
#define   PIN8              8 
#define   PIN9              9 
#define   PIN10             10
#define   PIN11             11
#define   PIN12             12
#define   PIN13             13
#define   PIN14             14
#define   PIN15             15
/*=============================*/


/*====================================================================================================*/
/*================================   Tarek Ahmed GPIO Functions Prototypes  ==========================*/
/*====================================================================================================*/
/*********************************    GPIO_voidPinInit                   ******************************/
/*********************************    GPIO_voidSetPinMode                ******************************/ 
/*********************************    GPIO_voidSetPinType                ******************************/ 
/*********************************    GPIO_voidSetPinSpeed               ******************************/ 
/*********************************    GPIO_voidSetPinValueNonAtomic      ******************************/ 
/*********************************    GPIO_voidSetPinValueAtomic         ******************************/ 
/*********************************    GPIO_u8GetPinValue                 ******************************/ 
/*********************************    GPIO_voidPortInit                  ******************************/ 
/*********************************    GPIO_voidSetPortMode               ******************************/ 
/*********************************    GPIO_voidSetPortType               ******************************/
/*********************************    GPIO_voidSetPortSpeed              ******************************/
/*====================================================================================================*/


/*==============================================================================================*/
/* ==============================        Init Functions          ===============================*/
/*==============================================================================================*/
/************************************************************************************************/
/* Function Name : GPIO_voidPinInit                                                             */
/* Description   : Inilization of Pin {Mode,Type,Speed}                                         */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                          */
/* Fun. Argument2: Copy_u8PinID { PIN0 -> PIN15 }                                               */
/* Fun. Argument3: Copy_u8Mode { OUTPUT , INPUT , ALTERNATE , ANALOG }                          */
/* Fun. Argument4: Copy_u8Type  {PUSH_PULL,OPEN_DRAIN,NO_PULL_UP_DOWM,PULL_UP,PULL_DOWN }       */
/* Fun. Argument5: Copy_u8Speed {LOW_SPEED,MEDIUM_SPEED,HIGH_SPEED}                             */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void GPIO_voidPinInit (u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Mode, u8 Copy_u8Type ,u8 Copy_u8Speed);

/************************************************************************************************/
/* Function Name : GPIO_voidSetPinMode                                                          */
/* Description   : Inilization of Pin {Mode:{ OUTPUT , INPUT , ALTERNATE , ANALOG }}            */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                          */
/* Fun. Argument2: Copy_u8PinID { PIN0 -> PIN15 }                                               */
/* Fun. Argument3: Copy_u8Mode { OUTPUT , INPUT , ALTERNATE , ANALOG }                          */
/* Fun. Return   : void                                                                         */
/************************************************************************************************/
void GPIO_voidSetPinMode (u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Mode);

/****************************************************************************************************/
/* Function Name : GPIO_voidSetPinType                                                              */
/* Description : Inilization of Pin {Type:{PUSH_PULL,OPEN_DRAIN,NO_PULL_UP_DOWM,PULL_UP,PULL_DOWN}} */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                              */
/* Fun. Argument2: Copy_u8PinID { PIN0 -> PIN15 }                                                   */
/* Fun. Argument3: Copy_u8Type  {PUSH_PULL,OPEN_DRAIN,NO_PULL_UP_DOWM,PULL_UP,PULL_DOWN }           */
/* Fun. Return : void                                                                               */
/****************************************************************************************************/
void GPIO_voidSetPinType (u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Type);


/************************************************************************************************/
/* Function Name : GPIO_voidSetPinSpeed                                                         */
/* Description : Inilization of Pin {Speed}                                                     */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                          */
/* Fun. Argument2: Copy_u8PinID { PIN0 -> PIN15 }                                               */
/* Fun. Argument3: Copy_u8Speed  {LOW_SPEED:8MHZ,MEDIUM_SPEED:50MHZ,HIGH_SPEED:80MHZ}           */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void GPIO_voidSetPinSpeed (u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Speed);



/************************************************************************************************/
/* Function Name : GPIO_voidPortInit                                                            */
/* Description : Inilization of Port {Mode,Type,Speed}                                          */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                          */
/* Fun. Argument2: Copy_u8Mode { OUTPUT , INPUT , ALTERNATE , ANALOG }                          */
/* Fun. Argument3: Copy_u8Type  {PUSH_PULL,OPEN_DRAIN,NO_PULL_UP_DOWM,PULL_UP,PULL_DOWN }       */
/* Fun. Argument4: Copy_u8Speed {LOW_SPEED,MEDIUM_SPEED,HIGH_SPEED}                             */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void GPIO_voidPortInit(u8 Copy_u8PortID ,u8 Copy_u8Mode ,u8 Copy_u8Type ,u8 Copy_u8Speed);


/************************************************************************************************/
/* Function Name : GPIO_voidSetPortMode                                                         */
/* Description : Inilization of Port {Mode}                                                     */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                          */
/* Fun. Argument2: Copy_u8Mode { OUTPUT , INPUT , ALTERNATE , ANALOG }                          */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void GPIO_voidSetPortMode(u8 Copy_u8PortID , u8 Copy_u8Mode );



/************************************************************************************************/
/* Function Name : GPIO_voidSetPortType                                                         */
/* Description : Inilization of Port {Type}                                                     */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                          */
/* Fun. Argument2: Copy_u8Type  {PUSH_PULL,OPEN_DRAIN,NO_PULL_UP_DOWM,PULL_UP,PULL_DOWN }       */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void GPIO_voidSetPortType(u8 Copy_u8PortID , u8 Copy_u8Type );

/************************************************************************************************/
/* Function Name : GPIO_voidSetPortSpeed                                                        */
/* Description : Inilization of Port {Speed}                                                    */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                          */
/* Fun. Argument2: Copy_u8Speed  {LOW_SPEED,MEDIUM_SPEED,HIGH_SPEED}                            */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void GPIO_voidSetPortSpeed(u8 Copy_u8PortID , u8 Copy_u8Speed );


/*========================================================================================*/
/* ===========================         Write Modules          ============================*/
/*========================================================================================*/
/******************************************************************************************/
/* Function Name : GPIO_voidSetPinValueNonAtomic                                          */
/* Description : Write value for one bit of the GPIO register                             */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                    */
/* Fun. Argument2: Copy_u8PinID { PIN0 -> PIN15 }                                         */
/* Fun. Argument3: Copy_u8Value { HIGH , LOW }                                            */
/* Fun. Return : void                                                                     */
/******************************************************************************************/
void GPIO_voidSetPinValueNonAtomic (u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Value);


/******************************************************************************************/
/* Function Name : GPIO_voidSetPinValueAtomic                                             */
/* Description : Write value for one bit of the GPIO register                             */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                    */
/* Fun. Argument2: Copy_u8PinID { PIN0 -> PIN15 }                                         */
/* Fun. Argument3: Copy_u8Value { SET , RST }                                             */
/* Fun. Return : void                                                                     */
/******************************************************************************************/
void GPIO_voidSetPinValueAtomic (u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Value);


/******************************************************************************************/
/* Function Name : GPIO_voidSetPortValueNonAtomic                                       */
/* Description : Write value for one bit of the GPIO register                             */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                    */
/* Fun. Argument2: Copy_u8Value { 0x0000 => 0xFFFF                                        */
/* Fun. Return : void                                                                     */
/******************************************************************************************/
void GPIO_voidSetPortValueNonAtomic (u8 Copy_u8PortID,u16 Copy_u16Value);




/******************************************************************************************/
/* Function Name : GPIO_voidSetLeastPortValueNonAtomic                                    */
/* Description : Write value for one bit of the GPIO register                             */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                    */
/* Fun. Argument2: Copy_u8Value { 0x00 => 0xFF                                            */
/* Fun. Return : void                                                                     */
/******************************************************************************************/
void GPIO_voidSetLeastPortValueNonAtomic (u8 Copy_u8PortID,u8 Copy_u8Value);

/******************************************************************************************/
/* Function Name : GPIO_voidSetMostPortValueNonAtomic                                     */
/* Description : Write value for one bit of the GPIO register                             */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                    */
/* Fun. Argument2: Copy_u8Value { 0x00 => 0xFF                                            */
/* Fun. Return : void                                                                     */
/******************************************************************************************/
void GPIO_voidSetMostPortValueNonAtomic (u8 Copy_u8PortID,u8 Copy_u8Value);




/******************************************************************************************/
/* Function Name : GPIO_voidSetPortValueAtomic                                          */
/* Description : Write value for one bit of the GPIO register                             */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                    */
/* Fun. Argument2: Copy_u8Value { 0x0000 => 0xFFFF                                        */
/* Fun. Return : void                                                                     */
/******************************************************************************************/
void GPIO_voidSetPortValueAtomic (u8 Copy_u8PortID ,u16 Copy_u16Set_orRst);


/*==========================================================================*/
/*======================         Read Modules          =====================*/
/*==========================================================================*/
/****************************************************************************/
/* Function Name : GPIO_u8GetPinValue                                       */
/* Description : Read pin value from one bit of the Port register           */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                      */
/* Fun. Argument2: Copy_u8PinID { PIN0 -> PIN15 }                           */
/* Fun. Return :  unsigned char   { HIGH , LOW }                            */
/****************************************************************************/
u8 GPIO_u8GetPinValue (u8 Copy_u8PortID , u8 Copy_u8PinID );

/****************************************************************************/
/* Function Name : GPIO_u16GetPortValue                                     */
/* Description : Read pin value from one Port register                      */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                      */
/* Fun. Return :  unsigned long   { HIGH , LOW }                            */
/****************************************************************************/
u16 GPIO_u8GetPortValue (u8 Copy_u8PortID);

#endif /* MCAL_GPIO_GPIO_INTERFACE_H_ */
