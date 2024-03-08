


#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/STD_TYPES.h"
#include "../include/MCAL/STK/STK_Config.h"
#include "../include/MCAL/STK/STK_Interface.h"
#include "../include/MCAL/STK/STK_Private.h"



void (*GPF)(void)=NULL;
/*GLobal variable to check the interval of the funtion whether its single or periodic*/
u8 GLobal_u8IntervalMode=0;

/********************************************/
/* SWC: STK Driver                          */
/* Author: Bendary                          */
/* Version: v0.0                            */
/* Date: 20 OCT 2023                        */
/* Description: This is the implem. of STK  */
/********************************************/




/**********************************************************/
/* Func. Name:STK_voidInit                                */
/* i/p arguments:Nothing                                  */
/* o/p arguments:Nothing                                  */
/* Desc. : This API allows user to Intialize the STK Timer*/
/**********************************************************/
void STK_voidInit(void)
{
	/*I will start with disabling every thing until the user uses a function then
	 * i will enable the STK and the interrupts if needed (Busy waiting doesnt need interrupts)*/

	/*1-Disabling the STK timer*/
	CLR_BIT(STK_CTRL,STK_CTRL_ENABLE);

	/*2-Disabling the Interrupts request for the STK*/
	CLR_BIT(STK_CTRL,STK_CTRL_TICKINT);

#if STK_CLOCK_SOURCE == AHB
	/*3-Setting the STK clock source to the same value of AHB*/
	SET_BIT(STK_CTRL,STK_CTRL_CLKSOURCE);


#elif STK_CLOCK_SOURCE == AHB_Over_8

	/*3-Setting the STK clock source to the same value of (AHB/8)
	 * My AHB is 8MHZ,so my STK tick is 1 microsec*/
	CLR_BIT(STK_CTRL,STK_CTRL_CLKSOURCE);

#else #error
#endif
}




/****************************************************/
/* Func. Name:STK_voidSetBusyWait                   */
/* i/p arguments:Copy_u32TimeInMillis:Time in millis*/
/* o/p arguments:Nothing                            */
/* Desc. : This API allows user todelay the system  */
/* for amount of time                               */
/****************************************************/
void STK_voidSetBusyWait(u32 Copy_u32TimeInMillis)
{
	u32 Local_u32NumberOfTicks=(Copy_u32TimeInMillis*1000);
	/*Put the Number of ticks in the LOAD register*/
	STK_LOAD=Local_u32NumberOfTicks;

	/*Start the timer*/
	SET_BIT(STK_CTRL,STK_CTRL_ENABLE); //after this line the VAl register copies the value of LOAD register

	/*Wait until the flag is raised*/
	while(GET_BIT(STK_CTRL,STK_CTRL_COUNTFLAG)==0);
	/*Stop the timer*/
	CLR_BIT(STK_CTRL,STK_CTRL_ENABLE);

	/*For verification that the timer will stop(didnt listen to the last command)*/

	/*When i make the load=0 the val will copy 0 so it will count to nothing
	 * for more verification i will set the val to 0 to reset after any random operations
	 * after i stoped the timer so it can copy the 0 from the load and count to nothing*/
	STK_LOAD=0;
	STK_VAL=0;


}
/***************************************************/
/* Func. Name:STK_voidSetIntervalSingle            */
/* i/p arguments:Copy_u32TimeInMillis: Time in millis
 *               LPF:put the function that will be
 * excuted after this amount of time               */
/* o/p arguments:Nothing                           */
/* Desc. : This API allows user to set the time    */
/*between each interrupt (for one time)            */
/***************************************************/
void STK_voidSetIntervalSingle(u32 Copy_u32TimeInMillis,void (*LPF) (void))
{
	/*Setting the interval mode to single*/
	GLobal_u8IntervalMode=SingleMode;

	/*Assigning the number of ticks based on the time (1 tick= 1 microsec)*/
	u32 Local_u32NumberOfTicks=(Copy_u32TimeInMillis*1000);

	/*Put the Number of ticks in the LOAD register*/
	STK_LOAD=Local_u32NumberOfTicks;

	/*Put the LPF in the GPF to excute the interrupt*/
	GPF=LPF;

	/*Enable the Interrupt*/
	SET_BIT(STK_CTRL,STK_CTRL_TICKINT);

	/*Start the timer*/
	SET_BIT(STK_CTRL,STK_CTRL_ENABLE); //after this line the VAl register copies the value of LOAD register

}
/***************************************************/
/* Func. Name:STK_voidSetIntervalSingle            */
/* i/p arguments:Copy_u32TimeInMillis: Time in millis
 *               LPF:put the function that will be
 * excuted after this amount of time               */
/* o/p arguments:Nothing                           */
/* Desc. : This API allows user to set the time    */
/*between each interrupt                           */
/***************************************************/
void STK_voidSetIntervalPeriodic(u32 Copy_u32TimeInMillis,void (*LPF)(void))
{
	/*Setting the interval mode to single*/
	GLobal_u8IntervalMode=PeriodicMode;

	/*Assigning the number of ticks based on the time (1 tick= 1 microsec)*/
	u32 Local_u32NumberOfTicks=(Copy_u32TimeInMillis*1000);

	/*Put the Number of ticks in the LOAD register*/
	STK_LOAD=Local_u32NumberOfTicks;

	/*Put the LPF in the GPF to excute the interrupt*/
	GPF=LPF;

	/*Enable the Interrupt*/
	SET_BIT(STK_CTRL,STK_CTRL_TICKINT);

	/*Start the timer*/
	SET_BIT(STK_CTRL,STK_CTRL_ENABLE); //after this line the VAl register copies the value of LOAD register



}
/********************************************/
/* Func. Name:STK_voidGetElapsedTime        */
/* i/p arguments:Nothing                    */
/* o/p arguments:Time in microsec           */
/* Desc. : This API allows user to          */
/*get the time done till now in this cycle  */
/********************************************/
u32 STK_voidGetElapsedTime(void)
{
	/*Return the time in microsec(= number of ticks)*/
	return (STK_LOAD-STK_VAL);
}
/********************************************/
/* Func. Name:STK_voidGetRemainingTime      */
/* i/p arguments:Nothing                    */
/* o/p arguments:Time in microsec           */
/* Desc. : This API allows user to          */
/*get the time remaining in this cycle      */
/********************************************/
u32 STK_voidGetRemainingTime(void)
{
	/*Return the time in microsec(= number of ticks)*/
	return STK_VAL;
}



/*ISR*/
void SysTick_Handler()
{
	u8 Local_u8Temp;
	/*Checking this ISR is excuted from the Single or peridic funtion to
	 * take the descision whether to excute this ISR one time or multiple*/
	if(GLobal_u8IntervalMode==SingleMode)
	{
		/*Disable the timer to avoid excuting it again*/
		CLR_BIT(STK_CTRL,STK_CTRL_ENABLE);
		STK_LOAD=0;
		STK_VAL=0;

		/*Disable the interrupt*/
		CLR_BIT(STK_CTRL,STK_CTRL_TICKINT);
	}
	else
	{
		// Do Nothing
	}

	if(GPF != NULL)
	{
		GPF();
	}
	/*Matnsa4 an al flag byt3mlo clear lma te2rah bas*/
	/*Clearing the flag*/
	Local_u8Temp=GET_BIT(STK_CTRL,STK_CTRL_COUNTFLAG);


	//Note: in the first if condition(if you are single mode fuction) will disable every thing but the
	//GPF still has the LPF so it will be excuted one time normally
}



