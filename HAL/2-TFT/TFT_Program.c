/***********************************/
/* SWC: TFT Driver                 */
/* Author: Bendary                 */
/* Version: V1                     */
/* Date: 20 Jun 2023               */
/***********************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_Interface.h"
#include "STK_Interface.h"

#include "TFT_Private.h"
#include "TFT_Interface.h"
#include "TFT_Config.h"

void TFT_voidInit(void)
{
	/*1- Reset Pulse sequence*/
	Private_voidSendResetPulse();
	/*2- Sleep out Command*/
	Private_voidSendCmd(SLP_OUT_CMD);
	/*3- Delay 10 ms*/
	STK_voidSetBusyWait(10000);
	/*4.1 - Colored Mode*/
	Private_voidSendCmd(0x3A);
	/*4.2 - RGB565 selection*/
	Private_voidSendData(0x05);
	/*5- Display ON*/
	Private_voidSendCmd(0x29);
}

void TFT_voidDisplayImage(u16* ImageArr)
{
	u32 Local_u32Counter;

	/*Set x Dimensions Command*/
	Private_voidSendCmd(0x2A);
	/*Start of x*/
	Private_voidSendData(0);
	Private_voidSendData(0);
	/*End of x*/
	Private_voidSendData(0);
	Private_voidSendData(127);

	/*Set y Dimensions Command*/
	Private_voidSendCmd(0x2B);
	/*Start of x*/
	Private_voidSendData(0);
	Private_voidSendData(0);
	/*End of x*/
	Private_voidSendData(0);
	Private_voidSendData(159);

	/*Ram memory write*/
	Private_voidSendCmd(0x2C);

	/*Write on TFT Pixel by Pixel - MSB First, each pixel is 2B, at each time --> 1B*/
	for(Local_u32Counter = 0; Local_u32Counter < 20480; Local_u32Counter++)
	{
		u8 Local_u8low = (u8) ImageArr[Local_u32Counter];
		u8 Local_u8high =(u8) (ImageArr[Local_u32Counter]>>8);
		Private_voidSendData(Local_u8high);
		Private_voidSendData(Local_u8low);
	}
}

static void Private_voidSendCmd(u8 Copy_u8Command)
{
	u8 Local_u8Temp;
	/*Select Command mode*/
	GPIO_voidSetPinValue(TFT_A0_PIN, PIN_LOW);
	/*Send Command*/
	SPI_voidTranceive(Copy_u8Command, &Local_u8Temp);
	//(void)SPI_voidTranceive(Copy_u8Command);
}

static void Private_voidSendData(u8 Copy_u8Data)
{
	u8 Local_u8Temp=0;
	/*Select Data mode*/
	GPIO_voidSetPinValue(TFT_A0_PIN, PIN_HIGH);
	/*Send Data*/
	SPI_voidTranceive(Copy_u8Data, &Local_u8Temp);
	//(void)SPI_voidTranceive(Copy_u8Command);
}

static void Private_voidSendResetPulse(void)
{
	GPIO_voidSetPinValue(TFT_RST_PIN, PIN_HIGH);
	STK_voidSetBusyWait(1000);
	GPIO_voidSetPinValue(TFT_RST_PIN, PIN_LOW);
	STK_voidSetBusyWait(10);
	GPIO_voidSetPinValue(TFT_RST_PIN, PIN_HIGH);
	STK_voidSetBusyWait(1000);
	GPIO_voidSetPinValue(TFT_RST_PIN, PIN_LOW);
	STK_voidSetBusyWait(100000);
	GPIO_voidSetPinValue(TFT_RST_PIN, PIN_HIGH);
	STK_voidSetBusyWait(120000);
}
