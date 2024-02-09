#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"

void APP_voidGetFrame(void);
void APP_voidTakeAction(void);
void APP_voidPlay(void);

void main(void)
{
	/*Initialize System Clock*/
	RCC_voidInitSysClk();
	/*Enable Clock For GPIOA*/
	RCC_voidEnablePeripheralClk(AHB1, 0);
	/*Initialize The Pins*/
	GPIO_voidSetPinInputConfig(GPIOA, PIN0,  INPUT_NOPUNOPD);        /* A0 -> EXTI0 */
	GPIO_voidSetPinOutputConfig(GPIOA, PIN1, OUTPUT_PP, OUTPUT_LS);	 /* A1 -> RED   */
	GPIO_voidSetPinOutputConfig(GPIOA, PIN2, OUTPUT_PP, OUTPUT_LS);	 /* A2 -> BLUE  */
	GPIO_voidSetPinOutputConfig(GPIOA, PIN3, OUTPUT_PP, OUTPUT_LS);	 /* A3 -> GREEN */
	/*Set EXTI0 Callback Function*/
	EXTI_voidSetEXTIpinConfig(EXTI_PA, EXTI_LINE_0);
	EXTI_voidSetCallBack(&APP_voidGetFrame);
	/*Initialize External Line*/
	EXTI_voidInit();
	/*Enable Interrupt for EXTI6*/
	EXTI_voidSetExtiLineEnable(EXTI_LINE_0);
	NVIC_voidEnableInt(6);			// EXTI0
	/*Systick Initialize*/
	MSTK_voidInit();
	while(1)
	{

	}
}

u8   APP_u8StartFlag = 0;
u32  APP_u32ReceivedFrame[50] = {0};
u8   APP_u8EdgeCounter = 0;
u8   APP_u8Data = 0;
void APP_voidGetFrame(void)
{
	/*Check if the Received Edge The very first falling edge or not*/
	if(APP_u8StartFlag == 0)
	{
		/*Start Timer To Count The Ticks*/
		MSTK_voidSetIntervalSingle(1000000, &APP_voidTakeAction);
		APP_u8StartFlag = 1;
	}
	else
	{
		APP_u32ReceivedFrame[APP_u8EdgeCounter] = MSTK_u32GetElapsedTime();	//13500
		MSTK_voidSetIntervalSingle(1000000, &APP_voidTakeAction);
		APP_u8EdgeCounter++;
	}
}

void APP_voidTakeAction(void)
{
	APP_u8Data = 0;
	u8 Local_u8LoopCounter;
	if(APP_u32ReceivedFrame[0] >= 10000 && APP_u32ReceivedFrame[0] <= 15000 )
	{
		for(Local_u8LoopCounter = 0; Local_u8LoopCounter < 8; Local_u8LoopCounter++)
		{
			if( (APP_u32ReceivedFrame[17+Local_u8LoopCounter] >= 1000) &&
					(APP_u32ReceivedFrame[17+Local_u8LoopCounter] <= 1500))
			{
				CLR_BIT(APP_u8Data, Local_u8LoopCounter);
			}
			else
			{
				SET_BIT(APP_u8Data, Local_u8LoopCounter);
			}
		}
		APP_voidPlay();
	}
	else
	{
		/*Invalid Frame*/
	}

	APP_u32ReceivedFrame[0] = 0;
	APP_u8EdgeCounter = 0;
	APP_u8StartFlag = 0;
}

void APP_voidPlay(void)
{
	switch(APP_u8Data)	//00001010
	{
	case 69:	//Data 69 ==> ON
		GPIO_voidSetPinValue(GPIOA, PIN1, HIGH);
		break;
	case 24:	//Data 24 ==> 2
		GPIO_voidSetPinValue(GPIOA, PIN2, HIGH);
		break;
	case 28:  //Data 74 ==> 9
		GPIO_voidSetPinValue(GPIOA, PIN3, HIGH);
		break;
	}
}





