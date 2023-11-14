/*=================================================================================*/
/*  File        : Gpio_Program.c                                                   */
/*  Description : This Program file includes Gpio Driver for stm32f401CC           */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 14/6/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/

#include "Gpio_Private.h"
#include "Gpio_Interface.h"
#include "Gpio_Config.h"
#include "../../LIB/BIT_MATH.h"
#include "../RCC/RCC_Interface.h"


/************************************************************************************************/
/* Function Name : GPIO_voidPinInit                                                             */
/* Description : Inilization of Pin {Mode,Type,Speed}                                           */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                          */
/* Fun. Argument2: Copy_u8PinID { PIN0 -> PIN15 }                                               */
/* Fun. Argument3: Copy_u8Mode { OUTPUT , INPUT , ALTERNATE , ANALOG }                          */
/* Fun. Argument4: Copy_u8Type  {PUSH_PULL,OPEN_DRAIN,PULL_UP,PULL_DOWN }                       */
/* Fun. Argument5: Copy_u8Speed {LOW_SPEED,MEDIUM_SPEED,HIGH_SPEED}                             */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void GPIO_voidPinInit (u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Mode, u8 Copy_u8Type ,u8 Copy_u8Speed)
{
	if(Copy_u8PortID > GPIOC || Copy_u8PinID > PIN15 || Copy_u8Mode > ANALOG || Copy_u8Type > PULL_DOWN ||Copy_u8Speed > HIGH_SPEED)
	{
		/* Do Nothing*/
	}
	else 
	{
		RCC_voidEnablePeripheralClock(GPIO_BUS,Copy_u8PortID );
		GPIO_voidSetPinMode  (Copy_u8PortID ,  Copy_u8PinID ,  Copy_u8Mode);
		GPIO_voidSetPinType  (Copy_u8PortID ,  Copy_u8PinID ,  Copy_u8Type);
		if(Copy_u8Mode == OUTPUT)
		{
			GPIO_voidSetPinSpeed (Copy_u8PortID ,  Copy_u8PinID ,  Copy_u8Speed);
		}
	}
}


/**************************************************************************************/
/* Function Name : GPIO_voidSetPinMode                                                */
/* Description :                                                                      */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                */
/* Fun. Argument2: Copy_u8PinID  { PIN0 -> PIN15 }                                    */
/* Fun. Argument3: Copy_u8ModeID { INPUT,OUTPUT,AF,ANALOG }                           */
/* Fun. Return : void                                                                 */
/**************************************************************************************/
void GPIO_voidSetPinMode (u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Mode)
{
	if(Copy_u8PortID > GPIOC || Copy_u8PinID > PIN15 || Copy_u8Mode > ANALOG)
	{
		/* Do Nothing*/
	}
	else 
	{
		switch(Copy_u8Mode)
		{
		case INPUT:
			switch(Copy_u8PortID)
			{
			case GPIOA:
				CLEAR_BIT(GPIOA_REG->MODER,(Copy_u8PinID*2));
				CLEAR_BIT(GPIOA_REG->MODER,(Copy_u8PinID*2 + 1));
				break;
			case GPIOB:
				CLEAR_BIT(GPIOB_REG->MODER,(Copy_u8PinID*2));
				CLEAR_BIT(GPIOB_REG->MODER,(Copy_u8PinID*2 + 1));
				break;
			case GPIOC:
				CLEAR_BIT(GPIOC_REG->MODER,(Copy_u8PinID*2));
				CLEAR_BIT(GPIOC_REG->MODER,(Copy_u8PinID*2 + 1));
				break;
			default:
				break;
			}
			break;
			case OUTPUT:
				switch(Copy_u8PortID)
				{
				case GPIOA:
					SET_BIT(GPIOA_REG->MODER,(Copy_u8PinID*2));
					CLEAR_BIT(GPIOA_REG->MODER,(Copy_u8PinID*2 + 1));
					break;
				case GPIOB:
					SET_BIT(GPIOB_REG->MODER,(Copy_u8PinID*2));
					CLEAR_BIT(GPIOB_REG->MODER,(Copy_u8PinID*2 + 1));
					break;
				case GPIOC:
					SET_BIT(GPIOC_REG->MODER,(Copy_u8PinID*2));
					CLEAR_BIT(GPIOC_REG->MODER,(Copy_u8PinID*2 + 1));
					break;
				default:
					break;
				}
				break;
				case AF:
					switch(Copy_u8PortID)
					{
					case GPIOA:
						CLEAR_BIT(GPIOA_REG->MODER,(Copy_u8PinID*2));
						SET_BIT(GPIOA_REG->MODER,(Copy_u8PinID*2 + 1));
						break;
					case GPIOB:
						CLEAR_BIT(GPIOB_REG->MODER,(Copy_u8PinID*2));
						SET_BIT(GPIOB_REG->MODER,(Copy_u8PinID*2 + 1));
						break;
					case GPIOC:
						CLEAR_BIT(GPIOC_REG->MODER,(Copy_u8PinID*2));
						SET_BIT(GPIOC_REG->MODER,(Copy_u8PinID*2 + 1));
						break;
					default:
						break;
					}
					break;

					case ANALOG:
						switch(Copy_u8PortID)
						{
						case GPIOA:
							SET_BIT(GPIOA_REG->MODER,(Copy_u8PinID*2));
							SET_BIT(GPIOA_REG->MODER,(Copy_u8PinID*2 + 1));
							break;
						case GPIOB:
							SET_BIT(GPIOB_REG->MODER,(Copy_u8PinID*2));
							SET_BIT(GPIOB_REG->MODER,(Copy_u8PinID*2 + 1));
							break;
						case GPIOC:
							SET_BIT(GPIOC_REG->MODER,(Copy_u8PinID*2));
							SET_BIT(GPIOC_REG->MODER,(Copy_u8PinID*2 + 1));
							break;
						default:
							break;
						}
						break;
						default:
							break;
		}
	}
}


/************************************************************************************************/
/* Function Name : GPIO_voidSetPortType                                                         */
/* Description : Inilization of Port {Type}                                                     */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                          */
/* Fun. Argument2: Copy_u8Type  {PUSH_PULL,OPEN_DRAIN,NO_PULL_UP_DOWM,PULL_UP,PULL_DOWN }       */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void GPIO_voidSetPinType (u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Type)
{
	if(Copy_u8PortID > GPIOC || Copy_u8PinID > PIN15 || Copy_u8Type > PULL_DOWN )
	{
		/* Do Nothing*/
	}
	else 
	{
		switch(Copy_u8Type)
		{
		case PUSH_PULL:
			switch(Copy_u8PortID)
			{
			case GPIOA:
				CLEAR_BIT(GPIOA_REG->OTYPER,Copy_u8PinID);
				break;
			case GPIOB:
				CLEAR_BIT(GPIOB_REG->OTYPER,Copy_u8PinID);
				break;
			case GPIOC:
				CLEAR_BIT(GPIOC_REG->OTYPER,Copy_u8PinID);
				break;
			default:
				break;
			}
			break;
			case OPEN_DRAIN:
				switch(Copy_u8PortID)
				{
				case GPIOA:
					SET_BIT(GPIOA_REG->OTYPER,Copy_u8PinID);
					break;
				case GPIOB:
					SET_BIT(GPIOB_REG->OTYPER,Copy_u8PinID);
					break;
				case GPIOC:
					SET_BIT(GPIOC_REG->OTYPER,Copy_u8PinID);
					break;
				default:
					break;
				}
				break;
				case PULL_UP:
					switch(Copy_u8PortID)
					{
					case GPIOA:
						SET_BIT(GPIOA_REG->PUPDR,(Copy_u8PinID*2));
						CLEAR_BIT(GPIOA_REG->PUPDR,(Copy_u8PinID*2+1));
						break;
					case GPIOB:
						SET_BIT(GPIOB_REG->PUPDR,(Copy_u8PinID*2));
						CLEAR_BIT(GPIOB_REG->PUPDR,(Copy_u8PinID*2+1));
						break;
					case GPIOC:
						SET_BIT(GPIOC_REG->PUPDR,(Copy_u8PinID*2));
						CLEAR_BIT(GPIOC_REG->PUPDR,(Copy_u8PinID*2+1));
						break;
					default:
						break;
					}
					break;
					case PULL_DOWN:
						switch(Copy_u8PortID)
						{
						case GPIOA:
							CLEAR_BIT(GPIOA_REG->PUPDR,(Copy_u8PinID*2));
							SET_BIT(GPIOA_REG->PUPDR,(Copy_u8PinID*2+1));
							break;
						case GPIOB:
							CLEAR_BIT(GPIOB_REG->PUPDR,(Copy_u8PinID*2));
							SET_BIT(GPIOB_REG->PUPDR,(Copy_u8PinID*2+1));
							break;
						case GPIOC:
							CLEAR_BIT(GPIOC_REG->PUPDR,(Copy_u8PinID*2));
							SET_BIT(GPIOC_REG->PUPDR,(Copy_u8PinID*2+1));
							break;
						default:
							break;
						}
						break;
						default:
							break;
		}
	}
}
/************************************************************************************************/
/* Function Name : GPIO_voidSetPortSpeed                                                        */
/* Description : Inilization of Port {Speed}                                                    */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                          */
/* Fun. Argument2: Copy_u8Speed  {LOW_SPEED,MEDIUM_SPEED,HIGH_SPEED}                            */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void GPIO_voidSetPinSpeed (u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Speed)
{
	if(Copy_u8PortID > GPIOC || Copy_u8PinID > PIN15 ||Copy_u8Speed > HIGH_SPEED)
	{
		/* Do Nothing*/
	}
	else 
	{
		switch(Copy_u8Speed)
		{
		case LOW_SPEED:
			switch(Copy_u8PortID)
			{
			case GPIOA:
				CLEAR_BIT(GPIOA_REG->OSPEEDER,(Copy_u8PinID*2));
				CLEAR_BIT(GPIOA_REG->OSPEEDER,(Copy_u8PinID*2+1));
				break;
			case GPIOB:
				CLEAR_BIT(GPIOB_REG->OSPEEDER,(Copy_u8PinID*2));
				CLEAR_BIT(GPIOB_REG->OSPEEDER,(Copy_u8PinID*2+1));
				break;
			case GPIOC:
				CLEAR_BIT(GPIOC_REG->OSPEEDER,(Copy_u8PinID*2));
				CLEAR_BIT(GPIOC_REG->OSPEEDER,(Copy_u8PinID*2+1));
				break;
			default:
				break;
			}
			break;
			case MEDIUM_SPEED:
				switch(Copy_u8PortID)
				{
				case GPIOA:
					SET_BIT(GPIOA_REG->OSPEEDER,(Copy_u8PinID*2));
					CLEAR_BIT(GPIOA_REG->OSPEEDER,(Copy_u8PinID*2+1));
					break;
				case GPIOB:
					SET_BIT(GPIOB_REG->OSPEEDER,(Copy_u8PinID*2));
					CLEAR_BIT(GPIOB_REG->OSPEEDER,(Copy_u8PinID*2+1));
					break;
				case GPIOC:
					SET_BIT(GPIOC_REG->OSPEEDER,(Copy_u8PinID*2));
					CLEAR_BIT(GPIOC_REG->OSPEEDER,(Copy_u8PinID*2+1));
					break;
				default:
					break;
				}
				break;
				case HIGH_SPEED:
					switch(Copy_u8PortID)
					{
					case GPIOA:
						CLEAR_BIT(GPIOA_REG->OSPEEDER,(Copy_u8PinID*2));
						SET_BIT(GPIOA_REG->OSPEEDER,(Copy_u8PinID*2+1));
						break;
					case GPIOB:
						CLEAR_BIT(GPIOB_REG->OSPEEDER,(Copy_u8PinID*2));
						SET_BIT(GPIOB_REG->OSPEEDER,(Copy_u8PinID*2+1));
						break;
					case GPIOC:
						CLEAR_BIT(GPIOC_REG->OSPEEDER,(Copy_u8PinID*2));
						SET_BIT(GPIOC_REG->OSPEEDER,(Copy_u8PinID*2+1));
						break;
					default:
						break;
					}
					break;
					default:
						break;
		}
	}
}

/************************************************************************************************/
/* Function Name : GPIO_voidPortInit                                                            */
/* Description : Inilization of Port {Mode,Type,Speed}                                          */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                          */
/* Fun. Argument2: Copy_u8Mode { OUTPUT , INPUT , ALTERNATE , ANALOG }                          */
/* Fun. Argument3: Copy_u8Type  {PUSH_PULL,OPEN_DRAIN,NO_PULL_UP_DOWM,PULL_UP,PULL_DOWN }       */
/* Fun. Argument4: Copy_u8Speed {LOW_SPEED,MEDIUM_SPEED,HIGH_SPEED}                             */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void GPIO_voidPortInit(u8 Copy_u8PortID ,u8 Copy_u8Mode ,u8 Copy_u8Type ,u8 Copy_u8Speed)
{
	if(Copy_u8PortID > GPIOC || Copy_u8Mode > ANALOG  || Copy_u8Type > PULL_DOWN || Copy_u8Speed > HIGH_SPEED)
	{
		/* Do Nothing*/
	}
	else
	{
		RCC_voidEnablePeripheralClock(GPIO_BUS,Copy_u8PortID );
		u8 Pin =0;
		for(Pin = 0; Pin <16 ; Pin++)
		{
			GPIO_voidPinInit( Copy_u8PortID,  Pin,  Copy_u8Mode,  Copy_u8Type, Copy_u8Speed);
		}
	}
}
/************************************************************************************************/
/* Function Name : GPIO_voidSetPortMode                                                         */
/* Description : Inilization of Port {Mode}                                                     */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                          */
/* Fun. Argument2: Copy_u8Mode { OUTPUT , INPUT , ALTERNATE , ANALOG }                          */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void GPIO_voidSetPortMode(u8 Copy_u8PortID , u8 Copy_u8Mode )
{

	if(Copy_u8PortID > GPIOC || Copy_u8Mode > ANALOG )
	{
		/* Do Nothing*/
	}
	else
	{
		u8 Pin = 0;
		for ( Pin = 0 ; Pin < 16 ; Pin++ )
		{
			GPIO_voidSetPinType( Copy_u8PortID , Pin , Copy_u8Mode );
		}

	}
}
/************************************************************************************************/
/* Function Name : GPIO_voidSetPortType                                                         */
/* Description : Inilization of Port {Type}                                                     */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                          */
/* Fun. Argument2: Copy_u8Type  {PUSH_PULL,OPEN_DRAIN,NO_PULL_UP_DOWM,PULL_UP,PULL_DOWN }       */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void GPIO_voidSetPortType(u8 Copy_u8PortID , u8 Copy_u8Type )
{
	if(Copy_u8PortID > GPIOC ||Copy_u8Type > PULL_DOWN )
	{
		/* Do Nothing*/
	}
	else
	{
		u8 Pin = 0;
		for ( Pin = 0 ; Pin < 16 ; Pin++ )
		{
			GPIO_voidSetPinType( Copy_u8PortID , Pin , Copy_u8Type );
		}

	}
}
/************************************************************************************************/
/* Function Name : GPIO_voidSetPortSpeed                                                        */
/* Description : Inilization of Port {Speed}                                                    */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                          */
/* Fun. Argument2: Copy_u8Speed  {LOW_SPEED,MEDIUM_SPEED,HIGH_SPEED}                            */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void GPIO_voidSetPortSpeed(u8 Copy_u8PortID , u8 Copy_u8Speed )
{
	if(Copy_u8PortID > GPIOC || Copy_u8Speed > HIGH_SPEED )
	{
		/* Do Nothing*/
	}
	else
	{
		u8 Pin = 0;
		for ( Pin = 0 ; Pin < 16 ; Pin++ )
		{
			GPIO_voidSetPinType( Copy_u8PortID , Pin , Copy_u8Speed );
		}

	}
}


/******************************************************************************************/
/* Function Name : GPIO_voidSetPinValueNonAtomic                                          */
/* Description : Write value for one bit of the GPIO register                             */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                    */
/* Fun. Argument2: Copy_u8PinID { PIN0 -> PIN15 }                                         */
/* Fun. Argument3: Copy_u8Value { HIGH , LOW }                                            */
/* Fun. Return : void                                                                     */
/******************************************************************************************/
void GPIO_voidSetPinValueNonAtomic (u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Value)
{
	if(Copy_u8PortID > GPIOC || Copy_u8PinID > PIN15  || Copy_u8Value > HIGH)
	{
		/* Do Nothing*/
	}
	else 
	{
		switch(Copy_u8Value)
		{
		case LOW:
			switch(Copy_u8PortID)
			{
			case GPIOA:
				CLEAR_BIT(GPIOA_REG->ODR,Copy_u8PinID);
				break;
			case GPIOB:
				CLEAR_BIT(GPIOB_REG->ODR,Copy_u8PinID);;
				break;
			case GPIOC:
				CLEAR_BIT(GPIOC_REG->ODR,Copy_u8PinID);
				break;
			default:
				break;
			}
			break;

			case HIGH:
				switch(Copy_u8PortID)
				{
				case GPIOA:
					SET_BIT(GPIOA_REG->ODR,Copy_u8PinID);
					break;
				case GPIOB:
					SET_BIT(GPIOB_REG->ODR,Copy_u8PinID);;
					break;
				case GPIOC:
					SET_BIT(GPIOC_REG->ODR,Copy_u8PinID);
					break;
				default:
					break;
				}
				break;
				default:
					break;
		}
	}
}
/******************************************************************************************/
/* Function Name : GPIO_voidSetPinValueAtomic                                             */
/* Description : Write value for one bit of the GPIO register                             */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                    */
/* Fun. Argument2: Copy_u8PinID { PIN0 -> PIN15 }                                         */
/* Fun. Argument3: Copy_u8Value { SET , RST }                                             */
/* Fun. Return : void                                                                     */
/******************************************************************************************/
void GPIO_voidSetPinValueAtomic (u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Value)
{
	if(Copy_u8PortID > GPIOC || Copy_u8PinID > PIN15  || Copy_u8Value > SET)
	{
		/* Do Nothing*/
	}
	else 
	{
		switch(Copy_u8Value)
		{
		case RST:
			switch(Copy_u8PortID)
			{
			case GPIOA:
				GPIOA_REG->BSRR = (1<<(Copy_u8PinID+16));
				break;
			case GPIOB:
				GPIOB_REG->BSRR = (1<<(Copy_u8PinID+16));
				break;
			case GPIOC:
				GPIOC_REG->BSRR = (1<<(Copy_u8PinID+16));
				break;
			default:
				break;
			}
			break;

			case SET:
				switch(Copy_u8PortID)
				{
				case GPIOA:
					GPIOA_REG->BSRR = (1<<Copy_u8PinID);
					break;
				case GPIOB:
					GPIOB_REG->BSRR = (1<<Copy_u8PinID);
					break;
				case GPIOC:
					GPIOC_REG->BSRR = (1<<Copy_u8PinID);
					break;
				default:
					break;
				}
				break;
				default:
					break;
		}
	}
}

/******************************************************************************************/
/* Function Name : GPIO_voidSetPortValueNonAtomic                                       */
/* Description : Write value for one bit of the GPIO register                             */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                    */
/* Fun. Argument2: Copy_u8Value { 0x0000 => 0xFFFF                                        */
/* Fun. Return : void                                                                     */
/******************************************************************************************/
void GPIO_voidSetPortValueNonAtomic (u8 Copy_u8PortID,u16 Copy_u16Value)
{
	if(Copy_u8PortID > GPIOC)
	{
		/* Do Nothing*/
	}
	else 
	{
		u8 Pin = 0;
		for(Pin = 0 ; Pin <16 ;Pin++)
		{
			GPIO_voidSetPinValueNonAtomic( Copy_u8PortID,  Pin, GET_BIT(Copy_u16Value, Pin));
		}

	}
}



/******************************************************************************************/
/* Function Name : GPIO_voidSetLeastPortValueNonAtomic                                    */
/* Description : Write value for one bit of the GPIO register                             */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                    */
/* Fun. Argument2: Copy_u8Value { 0x00 => 0xFF                                            */
/* Fun. Return : void                                                                     */
/******************************************************************************************/
void GPIO_voidSetLeastPortValueNonAtomic (u8 Copy_u8PortID,u8 Copy_u8Value)
{
	if(Copy_u8PortID > GPIOC)
	{
		/* Do Nothing*/
	}
	else 
	{
		u8 Pin = 0;
		for(Pin = 0 ; Pin <8 ;Pin++)
		{
			GPIO_voidSetPinValueNonAtomic( Copy_u8PortID, Pin, GET_BIT(Copy_u8Value,Pin));
		}

	}
}



/******************************************************************************************/
/* Function Name : GPIO_voidSetMostPortValueNonAtomic                                     */
/* Description : Write value for one bit of the GPIO register                             */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                    */
/* Fun. Argument2: Copy_u8Value { 0x00 => 0xFF                                            */
/* Fun. Return : void                                                                     */
/******************************************************************************************/
void GPIO_voidSetMostPortValueNonAtomic (u8 Copy_u8PortID,u8 Copy_u8Value)
{
	if(Copy_u8PortID > GPIOC)
	{
		/* Do Nothing*/
	}
	else 
	{
		u8 Pin = 0;
		for(Pin = 8 ; Pin <16 ;Pin++)
		{
			GPIO_voidSetPinValueNonAtomic(Copy_u8PortID,  Pin, GET_BIT(Copy_u8Value,Pin));
		}

	}
}


/******************************************************************************************/
/* Function Name : GPIO_voidSetPortValueAtomic                                          */
/* Description : Write value for one bit of the GPIO register                             */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                    */
/* Fun. Argument2: Copy_u8Value { 0x0000 => 0xFFFF                                        */
/* Fun. Return : void                                                                     */
/******************************************************************************************/
void GPIO_voidSetPortValueAtomic (u8 Copy_u8PortID ,u16 Copy_u16Set_orRst)
{
	if(Copy_u8PortID > GPIOC)
	{
		/* Do Nothing*/
	}
	else 
	{
		u8 Pin = 0;

		for(Pin = 0 ; Pin <16 ;Pin++)
		{
			GPIO_voidSetPinValueAtomic( Copy_u8PortID, Pin, GET_BIT(Copy_u16Set_orRst, Pin));
		}

	}
}


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
u8 GPIO_u8GetPinValue (u8 Copy_u8PortID , u8 Copy_u8PinID )
{
	u8 value = 0;
	if(Copy_u8PortID > GPIOC || Copy_u8PinID > PIN15 )
	{
		/* Do Nothing*/
	}
	else 
	{
		switch(Copy_u8PortID)
		{
		case GPIOA:
			value = GET_BIT(GPIOA_REG->IDR,Copy_u8PinID);
			break;
		case GPIOB:
			value = GET_BIT(GPIOB_REG->IDR,Copy_u8PinID);
			break;
		case GPIOC:
			value = GET_BIT(GPIOC_REG->IDR,Copy_u8PinID);
			break;
		default:
			break;
		}
	}
	return value;
}

/****************************************************************************/
/* Function Name : GPIO_u16GetPortValue                                     */
/* Description : Read pin value from one Port register                      */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                      */
/* Fun. Return :  unsigned long   { HIGH , LOW }                            */
/****************************************************************************/
u16 GPIO_u8GetPortValue (u8 Copy_u8PortID)
{
	u16 value = 0;
	if(Copy_u8PortID > GPIOC )
	{
		/* Do Nothing*/
	}
	else 
	{
		switch(Copy_u8PortID)
		{
		case GPIOA:
			value = GPIOA_REG->IDR;
			break;
		case GPIOB:
			value = GPIOB_REG->IDR;
			break;
		case GPIOC:
			value = GPIOC_REG->IDR;
			break;
		default:
			break;
		}
	}
	return value;
}
