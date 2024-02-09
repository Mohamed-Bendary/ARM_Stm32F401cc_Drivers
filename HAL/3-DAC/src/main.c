#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_Interface.h"

#include "GPIO_Interface.h"

#include "STK_Interface.h"

#include "carmen.h"

void App_voidSetDACValue();

int main()
{
	/*Init System Clock*/
	RCC_voidInitSysClk();
	/*Enable Clock for GPIOA: DAC0 - DAC7*/
	RCC_voidEnablePeripheralClk(AHB1, 0);
	/*Init Systick*/
	STK_voidInit();
	/*PIN0-->PIN7 in PORTA is OUTPUT, Push Pull, LS*/
	u8 Local_u8Counter;

	for(Local_u8Counter = 0; Local_u8Counter < 8; Local_u8Counter++)
	{
	   GPIO_voidSetPinMode(IOA, Local_u8Counter, OUTPUT);
	   GPIO_voidSetPinType(IOA, Local_u8Counter, OUTPUT_PP);
	   GPIO_voidSetPinSpeed(IOA, Local_u8Counter, OUTPUT_LS);
	}

	STK_voidSetIntervalPeriodic(125, &App_voidSetDACValue);

	while(1)
	{

	}
}

void App_voidSetDACValue()
{
	static u16 i = 0;

	GPIO_voidSetPortValue(IOA, carmen_song[i]);

	i++;

	if(i == 41702)
	{
		i = 0;
	}
}


