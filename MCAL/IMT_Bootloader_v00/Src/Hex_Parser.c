/*
 * Hex_Parser.c
 *
 *  Created on: Nov 3, 2023
 *      Author: hp
 */
#include <stdint.h>
#include "STD_TYPES.h"
#include "FMI_Interace.h"
#include "Hex_Parser.h"

#define BASE_ADDRESS		0x08000000

uint16_t FlashData[100];
static u8 HexParser_u8Ascii2Num(u8 Copy_u8Ascii)
{
	u8 Local_u8Return = 0;
	if(Copy_u8Ascii >= '0' && Copy_u8Ascii <= '9')
	{
		/*'0'=48 ,, so '0'-48 = (0) as decimal or hexa*/
		Local_u8Return = Copy_u8Ascii - '0';
	}
	else if(Copy_u8Ascii >='A' && Copy_u8Ascii <='F') //In checksum
	{
		/* 'A'-10 = 55 ,sense A = 10 as a hexa to decimal value,
		 * So by 'A' - 55 = 10 = (A) as a decimal  */
		Local_u8Return = Copy_u8Ascii - 55;
	}
	return Local_u8Return;
}

/*   : 02 0000 04 0800 F2  --> Record 1*/
/*   : 10 4000 00  0000 0120 1D48 0008 9D47 0008 A347 0008 44 --> Record 2*/
/*   : 10 4010 00  A947 0008 AF47 0008 B547 0008 0000 0000 A6 --> Record 3*/
void HexParser_vParseData(uint8_t *Data)
{
	/* Calculate record address */
	uint32_t Address = 0;
	uint8_t i;
	uint8_t digit0 , digit1 , digit2 , digit3;

	/* As for record 2--> 4000 i want to take each element as decimal to OR with the base address */
	digit0 = HexParser_u8Ascii2Num(Data[3]);
	digit1 = HexParser_u8Ascii2Num(Data[4]);
	digit2 = HexParser_u8Ascii2Num(Data[5]);
	digit3 = HexParser_u8Ascii2Num(Data[6]);

    /* After this operation the address of record 2 will be 0x0800 4000*/
	Address = (BASE_ADDRESS | (digit0 << 12)
							| (digit1 << 8)
							| (digit2 << 4)
							| digit3);

	/* Calculate Length */
	uint8_t Length_Low , Length_High , Length;
	Length_Low = HexParser_u8Ascii2Num(Data[2]);
	Length_High = HexParser_u8Ascii2Num(Data[1]);

	/* The length(in record 2) = 16 which is the actual black data which also means 16 byte
	 * but the array that will be sent by the API: FMI_voidFlashWrite is u16 type
	 * so every element in the sent array is 2 bytes,, so the length being sent to the
	 * API is the calculated length/2 */
	Length = (Length_High << 4) | Length_Low;

	/* Store data in FlashArray  */
	for(i = 0; i < Length/2; i++)
	{
		digit0 = HexParser_u8Ascii2Num(Data[(4*i)+9]);
		digit1 = HexParser_u8Ascii2Num(Data[(4*i)+10]);
		digit2 = HexParser_u8Ascii2Num(Data[(4*i)+11]);
		digit3 = HexParser_u8Ascii2Num(Data[(4*i)+12]);
		FlashData[i] = (  (digit0 << 12)
						| (digit1 << 8)
						| (digit2 << 4)
						|  digit3);
	}


	/* Flashing data */
	FMI_voidFlashWrite(Address, FlashData, Length/2);


}
