#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_Interface.h"
#include "GPIO_Interface.h"
#include "USART_Interface.h"

#include "SPI_Interface.h"
#include "TFT_Interface.h"

#include "image.h"

int main()
{
	u8 Local_u8Counter;

	/*Init System Clock*/
	RCC_voidInitSysClk();

	/*Enable Clock for GPIOA, SPI1*/
	RCC_voidEnablePeripheralClk(AHB1, 0);
	RCC_voidEnablePeripheralClk(APB2, 12);

	/*0- Configure Direction of Pins*/
	for(Local_u8Counter = 0; Local_u8Counter < 3; Local_u8Counter++)
	{
		GPIO_voidSetPinMode(GPIOA, Local_u8Counter, OUTPUT);
		GPIO_voidSetPinType(GPIOA, Local_u8Counter, OUTPUT_PP);
		GPIO_voidSetPinSpeed(GPIOA, Local_u8Counter, OUTPUT_LS);
	}

	/*Configure SPI Pins*/
	GPIO_voidSetPinMode(GPIOA, PIN5, AF);
	GPIO_voidSetPinMode(GPIOA, PIN7, AF);

	GPIO_voidSetPinAlternativeFunNo(GPIOA, PIN5, AF5);
	GPIO_voidSetPinAlternativeFunNo(GPIOA, PIN7, AF5);

	SPI_voidInit();

	TFT_voidInit();

	while(1)
	{
		TFT_voidDisplayImage(arr);
	}
}
