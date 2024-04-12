/*
 * Flash_Driver_Program.c
 *
 *  Created on: Apr 12, 2024
 *      Author: dell
 */
#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/STD_TYPES.h"

#include "../include/MCAL/FMI/FMI_Private.h"
#include "../include/MCAL/FMI/FMI_Interace.h"
#include "../include/MCAL/FMI/FMI_Config.h"

void FMI_voidSectorErase(u8 Copy_u8SectorNumber)
{
	/* Wait if the flash is busy */
	while(GET_BIT(FMI->SR , SR_BSY) == 1);

	/* Unlock CR register by KEYR*/
	if(GET_BIT(FMI->CR,CR_LOCK) == 1)
	{
		FMI->KEYR = KEY1;
		FMI->KEYR = KEY2;
	}

	/* Select the sector number */

	//Masking the old value in the sector bits
	FMI->CR &= ~((u32)(0b1111 << 3));

	//Adding the user new sector value
	FMI->CR |=((Copy_u8SectorNumber)<<3);

	/* Select the erase operation */
	SET_BIT(FMI->CR ,CR_SER);

	/* Start the operation */
	SET_BIT(FMI->CR,CR_STRT);

	/* Wait if the flash is busy */
	while(GET_BIT(FMI->SR , SR_BSY) == 1);

	/* Clear the EOP */
	SET_BIT(FMI->SR,SR_EOP);

	/* DeSelect the erase operation*/
	CLR_BIT(FMI->CR ,CR_SER);

}
void FMI_voidFlashWrite(u32 Copy_u32Address , u16 *Copy_u16Array , u16 Copy_u16Array_Length)
{
	u16 Local_u16Counter;

	/* Wait if the flash is busy */
	while(GET_BIT(FMI->SR , SR_BSY) == 1);

	/* Unlock CR register by KEYR*/
	if(GET_BIT(FMI->CR,CR_LOCK) == 1)
	{
		FMI->KEYR = KEY1;
		FMI->KEYR = KEY2;
	}

	/* Select the element size */
	//Masking the old value of the size of the elements being flashed at a time
	FMI->CR &= ~((u32)(0b11 << 8));

	//Adding the user new size value specified of our chip stm32f401cc
	FMI->CR |=(u32)((PSIZE)<<8);

	/* Select the programming mode*/
	SET_BIT(FMI->CR ,CR_PG);

	/* Write the data to the flash memory */
	for(Local_u16Counter = 0 ;Local_u16Counter<Copy_u16Array_Length;Local_u16Counter++)
	{
		//Casting the user address as a pointer and derefrencing it with the value to be flashed
		*(volatile u16*)Copy_u32Address = Copy_u16Array[Local_u16Counter];

		/*Adding (2) to the decimal value of the given address so next iteration i will point to the next 16bits
		 *  to be flashed,,if address given is 0x8000 1111 first i made a pointer of u16 type to point to this address
		 *  so it can write only 16 bits in the array,, then i make the address 0x8000 1113 to point to the next
		 *  address to flash the next 2 bytes
		 * */
		Copy_u32Address+=2;

		/* Wait for the writing operation to be completed*/
		while(GET_BIT(FMI->SR , SR_BSY) == 1);

		/* Clear the EOP bit indicating the end of this flashing operation*/
		SET_BIT(FMI->SR,SR_EOP);

	}
	/* DeSelect the flashing(programming) operation*/
	CLR_BIT(FMI->CR ,CR_PG);


}
