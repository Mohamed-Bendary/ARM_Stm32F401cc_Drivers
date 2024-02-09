/***********************************/
/* SWC: USART Driver               */
/* Author: Bendary                 */
/* Version: V1                     */
/* Date: 30 May 2023               */
/***********************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_Interface.h"

#include "SPI_Private.h"
#include "SPI_Interface.h"
#include "SPI_Config.h"

void SPI_voidInit()
{
	/* CHPA =1
	 * CHPOL = 1
	 * MSTR
	 * SPI Enable
	 * MSB First
	 * Slave Select By Sw
	 * */
	SPI1->CR1 = 0x00000347;
}

void SPI_voidTranceive(u8 Copy_u8DataToBeTransmitted, u8* DataToBeRecieved)
{
	//Select slave
	GPIO_voidSetPinValue(TFT_CS_PIN, PIN_LOW);
	//Send Data
	SPI1->DR = Copy_u8DataToBeTransmitted;
	//Poll until SPI isn't busy
	while(GET_BIT(SPI1->SR, 7));
	//Deselect slave
	GPIO_voidSetPinValue(TFT_CS_PIN, PIN_HIGH);
	//Return Data
	*DataToBeRecieved = (u8) (SPI1->DR);
}
