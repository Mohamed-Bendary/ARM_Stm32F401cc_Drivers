/*
 * main.c
 *
 *  Created on: Nov 5, 2023
 *      Author: nours
 */


#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"

#include "../include/MCAL/RCC/RCC_Interface.h"
#include "../include/MCAL/FMI/FMI_Interace.h"

void main(void)
{
	u16 Local_u16ArrayOfData[4] = {0x4050 ,0x7080 ,0x1010 ,0x5050};

	/*Enable the clock*/
	MRCC_voidInit();

	/*Enable the flash interface clock*/
    MRCC_voidEnableLOWPerClk(AHB1,15);

    /*Send the array of data to the flash*/
    /*My application will erase the memory so no need to erase*/
    FMI_voidFlashWrite(0x080008000 , Local_u16ArrayOfData , 4);

	while(1)
	{



	}
}
