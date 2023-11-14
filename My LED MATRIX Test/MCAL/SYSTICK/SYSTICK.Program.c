/*=================================================================================*/
/*  File        : SYSTICK_Program.c                                                */
/*  Description : This Program file includes SYSTICK Program for stm32f401CC       */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 25/6/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "SYSTICK.Config.h"
#include "SYSTICK.Interface.h"
#include "SYSTICK.Private.h"


static volatile void (*Global_PC_Call_Back)(void) = {NULL_PTR};

/* Global Variables */
u8 STK_IntervalMode = 0 ;

/************************************************************************************************/
/* Function Name : STK_voidInit                                                                 */
/* Description : Inilization of SYSTICK Source                                                  */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void STK_voidInit (void)
{
	/* Stop Timer */
	STK_voidStopInterval();

	/* Select CLOCK Source */
#if(STK_CLOCK_SOURCE == AHB_CLOCK)
	SET_BIT(STK_CTRL,SYSTIC_CLKSOURCE);
#elif(STK_CLOCK_SOURCE == AHB_CLOCK_DividedBy_8)
	CLEAR_BIT(STK_CTRL,SYSTIC_CLKSOURCE);
#endif

}



/************************************************************************************************/
/* Function Name : STK_voidSetBusyWait                                                          */
/* Description : Delay for Given Time in Msecond                                                */
/* Fun. Argument1: Copy_u32TimeMs                                                               */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void STK_voidSetBusyWait(u32 Copy_u32TimeMs)
{
	/* Set Time on LOAD */
	STK_LOAD = Copy_u32TimeMs * 1000 ;

	/* Start Timer */
	SET_BIT(STK_CTRL,SYSTIC_ENABLE);

	/* Polling on Flag */
	while(GET_BIT(STK_CTRL,SYSTIC_COUNTFLAG) == 0);

	/* Stop Timer to Clear all Past Data */
	STK_voidStopInterval();
}



/************************************************************************************************/
/* Function Name : STK_voidSetIntervalSingle                                                    */
/* Description : Take Action on CallBack Function at specific time for single interval          */
/* Fun. Argument1: Copy_u32TimeMs                                                               */
/* Fun. Argument2: void (*Copy_ptr)(void) ( Address of Call Back Function )                     */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void STK_voidSetIntervalSingle (f32 Copy_u32TimeMs,void (*Copy_ptr)(void))
{
	/* Disable Timer */
	CLEAR_BIT(STK_CTRL,SYSTIC_ENABLE);
	STK_VAL = 0;

	/* Load Time to LOAD Register */
	STK_LOAD = Copy_u32TimeMs * 1000;

	 /* Set Mode To Single Interval */
	STK_IntervalMode = STK_SingleInterval;

	 /* Save Call Back */
	Global_PC_Call_Back = Copy_ptr;

	/* Start Timer */
	SET_BIT(STK_CTRL,SYSTIC_ENABLE);

	/* Enable Timer Interrupt */
	SET_BIT(STK_CTRL,SYSTIC_TICKINT);

}

/************************************************************************************************/
/* Function Name : STK_voidSetIntervalPeriodic                                                  */
/* Description : Take Action on CallBack Function at specific time for Periodic interval        */
/* Fun. Argument1: Copy_u32TimeMs                                                               */
/* Fun. Argument2: void (*Copy_ptr)(void) ( Address of Call Back Function )                     */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void STK_voidSetIntervalPeriodic(f32 Copy_u32TimeMs,void (*Copy_ptr)(void))
{
	/* Disable Timer */
	CLEAR_BIT(STK_CTRL,SYSTIC_ENABLE);
	STK_VAL = 0;

	/* Load Time to LOAD Register */
	STK_LOAD = Copy_u32TimeMs*1000;

	 /* Set Mode To Periodic Interval */
	STK_IntervalMode = STK_PeriodicInterval;

	 /* Save Call Back */
	Global_PC_Call_Back = Copy_ptr;

	/* Start Timer */
	SET_BIT(STK_CTRL,SYSTIC_ENABLE);

	/* Enable Timer Interrupt */
	SET_BIT(STK_CTRL,SYSTIC_TICKINT);
}



void STK_voidStopInterval (void)
{
	/* Stop Interrupt */
	CLEAR_BIT(STK_CTRL,SYSTIC_TICKINT);

	/* Stop Timer */
	CLEAR_BIT(STK_CTRL,SYSTIC_ENABLE);

	/* Clear Registers */
	STK_LOAD = 0;
	STK_VAL = 0;
}


/************************************************************************************************/
/* Function Name : STK_u32GetElapsedTime                                                        */
/* Description : Return The Elapsed Time                                                        */
/* Fun. Return : u32 Elapsed Time                                                               */
/************************************************************************************************/
u32  STK_u32GetElapsedTime (void)
{
	u32 Local_Elapsed_Time = 0;

	Local_Elapsed_Time = STK_LOAD - STK_VAL;

	return Local_Elapsed_Time;
}


/************************************************************************************************/
/* Function Name : STK_u32GetRemainingTime                                                      */
/* Description : Return The Remaining Time                                                      */
/* Fun. Return : u32 Remaining Time                                                             */
/************************************************************************************************/
u32  STK_u32GetRemainingTime (void)
{
	u32 LocalRemainingTime ;
	LocalRemainingTime = STK_VAL ;
	return LocalRemainingTime ;
}


/*==============   ISR  SYSTICK   ===============*/
void SysTick_Handler(void)
{
	if(STK_IntervalMode == STK_SingleInterval)
	{
		STK_voidStopInterval();
	}


	if(Global_PC_Call_Back != NULL_PTR)
	{
		Global_PC_Call_Back();
	}

	/* Clear Interrupt Flag by Reading */
	u8 Local_u8Temp = 0 ;
	Local_u8Temp = GET_BIT(STK_CTRL,SYSTIC_COUNTFLAG);

}
