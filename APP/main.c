#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_Interface.h"

#include "GPIO_Interface.h"

#include "STK_Interface.h"

int main()
{
	/*1- Init System Clock*/
	RCC_voidInitSysClk();
	/*2- Enable Clk for the periphral GPIOA*/
	RCC_voidEnablePerClk(AHB1, 0);
	/*3- pin is O/P, O/P PP, LS*/
	GPIO_voidSetPinMode(IOA, PIN3, OUTPUT);
	GPIO_voidSetPinType(IOA, PIN3, OUTPUT_PP);
	GPIO_voidSetPinSpeed(IOA, PIN3, OUTPUT_LS);
	/*SysTick Init*/
	STK_voidInit();
	while(1)
	{
		GPIO_voidSetPinValue(IOA, PIN3, OUTPUT_HIGH);
		STK_voidSetBusyWait(100000);
		GPIO_voidSetPinValue(IOA, PIN3, OUTPUT_LOW);
		STK_voidSetBusyWait(100000);
	}
}

