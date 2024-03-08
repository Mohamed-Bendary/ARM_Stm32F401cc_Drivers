#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/STD_TYPES.h"

#include "../include/MCAL/RCC/RCC_Interface.h"
#include "../include/MCAL/GPIO/GPIO_Interface.h"
#include "../include/MCAL/STK/STK_Interface.h"
#include "../include/HAL/LED_MATRIX/LED_MATRIX_Interface.h"

void main (void)
{
	/*Clock Init*/
	MRCC_voidInit();
	MRCC_voidEnablePerClk(AHB1,0);


	/*STK_INIT*/
	STK_voidInit();

	/*LED_Matrix Init*/
	LED_MATRIX_voidInit();


	while(1)
	{
		LED_MATRIX_voidSetColumnsValue(62, 72, 82, 80, 80, 82, 72, 62);
		STK_voidSetBusyWait(500);
		LED_MATRIX_voidSetColumnsValue(62, 64, 90, 72, 72, 90, 64, 62);
	}


}



