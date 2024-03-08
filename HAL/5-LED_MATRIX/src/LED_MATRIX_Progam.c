#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"


#include "../include/HAL/LED_MATRIX/LED_MATRIX_Config.h"
#include "../include/HAL/LED_MATRIX/LED_MATRIX_Private.h"
#include "../include/HAL/LED_MATRIX/LED_MATRIX_Interface.h"

#include "../include/MCAL/GPIO/GPIO_Interface.h"
#include "../include/MCAL/STK/STK_Interface.h"

static void Deactivate_Columns(void);

void LED_MATRIX_voidInit()
{
	/*Setting all the used pins as:
	 * OUTPUT , Low_Speed , PushPull*/
	MGPIO_voidSetPinMode(R1_Port,R1_Pin,OUTPUT_MODE);
	MGPIO_voidSetPinMode(R2_Port,R2_Pin,OUTPUT_MODE);
	MGPIO_voidSetPinMode(R3_Port,R3_Pin,OUTPUT_MODE);
	MGPIO_voidSetPinMode(R4_Port,R4_Pin,OUTPUT_MODE);
	MGPIO_voidSetPinMode(R5_Port,R5_Pin,OUTPUT_MODE);
	MGPIO_voidSetPinMode(R6_Port,R6_Pin,OUTPUT_MODE);
	MGPIO_voidSetPinMode(R7_Port,R7_Pin,OUTPUT_MODE);
	MGPIO_voidSetPinMode(R8_Port,R8_Pin,OUTPUT_MODE);

	MGPIO_voidSetPinMode(C1_Port,C1_Pin,OUTPUT_MODE);
	MGPIO_voidSetPinMode(C2_Port,C2_Pin,OUTPUT_MODE);
	MGPIO_voidSetPinMode(C3_Port,C3_Pin,OUTPUT_MODE);
	MGPIO_voidSetPinMode(C4_Port,C4_Pin,OUTPUT_MODE);
	MGPIO_voidSetPinMode(C5_Port,C5_Pin,OUTPUT_MODE);
	MGPIO_voidSetPinMode(C6_Port,C6_Pin,OUTPUT_MODE);
	MGPIO_voidSetPinMode(C7_Port,C7_Pin,OUTPUT_MODE);
	MGPIO_voidSetPinMode(C8_Port,C8_Pin,OUTPUT_MODE);

	MGPIO_voidSetPinType(R1_Port,R1_Pin,OUTPUT_PP);
	MGPIO_voidSetPinType(R2_Port,R2_Pin,OUTPUT_PP);
	MGPIO_voidSetPinType(R3_Port,R3_Pin,OUTPUT_PP);
	MGPIO_voidSetPinType(R4_Port,R4_Port,OUTPUT_PP);
	MGPIO_voidSetPinType(R5_Port,R5_Pin,OUTPUT_PP);
	MGPIO_voidSetPinType(R6_Port,R6_Pin,OUTPUT_PP);
	MGPIO_voidSetPinType(R7_Port,R7_Pin,OUTPUT_PP);
	MGPIO_voidSetPinType(R8_Port,R8_Pin,OUTPUT_PP);

	MGPIO_voidSetPinType(C1_Port,C1_Pin,OUTPUT_PP);
	MGPIO_voidSetPinType(C2_Port,C2_Pin,OUTPUT_PP);
	MGPIO_voidSetPinType(C3_Port,C3_Pin,OUTPUT_PP);
	MGPIO_voidSetPinType(C4_Port,C4_Pin,OUTPUT_PP);
	MGPIO_voidSetPinType(C5_Port,C5_Pin,OUTPUT_PP);
	MGPIO_voidSetPinType(C6_Port,C6_Pin,OUTPUT_PP);
	MGPIO_voidSetPinType(C7_Port,C7_Pin,OUTPUT_PP);
	MGPIO_voidSetPinType(C8_Port,C8_Pin,OUTPUT_PP);

	MGPIO_voidSetPinSpeed(R1_Port,R1_Pin,LOW_SPEED);
	MGPIO_voidSetPinSpeed(R2_Port,R2_Pin,LOW_SPEED);
	MGPIO_voidSetPinSpeed(R3_Port,R3_Pin,LOW_SPEED);
	MGPIO_voidSetPinSpeed(R4_Port,R4_Pin,LOW_SPEED);
	MGPIO_voidSetPinSpeed(R5_Port,R5_Pin,LOW_SPEED);
	MGPIO_voidSetPinSpeed(R6_Port,R6_Pin,LOW_SPEED);
	MGPIO_voidSetPinSpeed(R7_Port,R7_Pin,LOW_SPEED);
	MGPIO_voidSetPinSpeed(R8_Port,R8_Pin,LOW_SPEED);

	MGPIO_voidSetPinSpeed(C1_Port,C1_Pin,LOW_SPEED);
	MGPIO_voidSetPinSpeed(C2_Port,C2_Pin,LOW_SPEED);
	MGPIO_voidSetPinSpeed(C3_Port,C3_Pin,LOW_SPEED);
	MGPIO_voidSetPinSpeed(C4_Port,C4_Pin,LOW_SPEED);
	MGPIO_voidSetPinSpeed(C5_Port,C5_Pin,LOW_SPEED);
	MGPIO_voidSetPinSpeed(C6_Port,C6_Pin,LOW_SPEED);
	MGPIO_voidSetPinSpeed(C7_Port,C7_Pin,LOW_SPEED);
	MGPIO_voidSetPinSpeed(C8_Port,C8_Pin,LOW_SPEED);

	/*Setting the cathode pins as High(ROWS)*/

	MGPIO_voidSetPinValue(R1_Port,R1_Pin,OUTPUT_HIGH);
	MGPIO_voidSetPinValue(R2_Port,R2_Pin,OUTPUT_HIGH);
	MGPIO_voidSetPinValue(R3_Port,R3_Pin,OUTPUT_HIGH);
	MGPIO_voidSetPinValue(R4_Port,R4_Pin,OUTPUT_HIGH);
	MGPIO_voidSetPinValue(R5_Port,R5_Pin,OUTPUT_HIGH);
	MGPIO_voidSetPinValue(R6_Port,R6_Pin,OUTPUT_HIGH);
	MGPIO_voidSetPinValue(R7_Port,R7_Pin,OUTPUT_HIGH);
	MGPIO_voidSetPinValue(R8_Port,R8_Pin,OUTPUT_HIGH);

}
void LED_MATRIX_voidSetColumnsValue (u8 Copy_C1Value,u8 Copy_C2Value,u8 Copy_C3Value
		,u8 Copy_C4Value,u8 Copy_C5Value,u8 Copy_C6Value,
		u8 Copy_C7Value,u8 Copy_C8Value)
{
	u8 Cx_R1Value,Cx_R2Value,Cx_R3Value,Cx_R4Value,Cx_R5Value,Cx_R6Value,Cx_R7Value,Cx_R8Value=0;

	Copy_C1Value=~Copy_C1Value;
	Copy_C2Value=~Copy_C2Value;
	Copy_C3Value=~Copy_C3Value;
	Copy_C4Value=~Copy_C4Value;
	Copy_C5Value=~Copy_C5Value;
	Copy_C6Value=~Copy_C6Value;
	Copy_C7Value=~Copy_C7Value;
	Copy_C8Value=~Copy_C8Value;

	/*Setting the cathode pins as High(ROWS)*/

	MGPIO_voidSetPinValue(R1_Port,R1_Pin,OUTPUT_HIGH);
	MGPIO_voidSetPinValue(R2_Port,R2_Pin,OUTPUT_HIGH);
	MGPIO_voidSetPinValue(R3_Port,R3_Pin,OUTPUT_HIGH);
	MGPIO_voidSetPinValue(R4_Port,R4_Pin,OUTPUT_HIGH);
	MGPIO_voidSetPinValue(R5_Port,R5_Pin,OUTPUT_HIGH);
	MGPIO_voidSetPinValue(R6_Port,R6_Pin,OUTPUT_HIGH);
	MGPIO_voidSetPinValue(R7_Port,R7_Pin,OUTPUT_HIGH);
	MGPIO_voidSetPinValue(R8_Port,R8_Pin,OUTPUT_HIGH);

	/*Deactivating all the columns*/
	Deactivate_Columns();

	/*Activating the first column
	 *  and setting its corresponding rows, based on the user input*/

	MGPIO_voidSetPinValue(C1_Port,C1_Pin,OUTPUT_HIGH);

	Cx_R1Value = GET_BIT(Copy_C1Value,0);
	Cx_R2Value = GET_BIT(Copy_C1Value,1);
	Cx_R3Value = GET_BIT(Copy_C1Value,2);
	Cx_R4Value = GET_BIT(Copy_C1Value,3);
	Cx_R5Value = GET_BIT(Copy_C1Value,4);
	Cx_R6Value = GET_BIT(Copy_C1Value,5);
	Cx_R7Value = GET_BIT(Copy_C1Value,6);
	Cx_R8Value = GET_BIT(Copy_C1Value,7);

	MGPIO_voidSetPinValue(R1_Port,R1_Pin,Cx_R1Value);
	MGPIO_voidSetPinValue(R2_Port,R2_Pin,Cx_R2Value);
	MGPIO_voidSetPinValue(R3_Port,R3_Pin,Cx_R3Value);
	MGPIO_voidSetPinValue(R4_Port,R4_Pin,Cx_R4Value);
	MGPIO_voidSetPinValue(R5_Port,R5_Pin,Cx_R5Value);
	MGPIO_voidSetPinValue(R6_Port,R6_Pin,Cx_R6Value);
	MGPIO_voidSetPinValue(R7_Port,R7_Pin,Cx_R7Value);
	MGPIO_voidSetPinValue(R8_Port,R8_Pin,Cx_R8Value);

	STK_voidSetBusyWait(Deactivating_Delay);

	/*Deactivating all the columns*/
	Deactivate_Columns();


	/*Activating the Second column
	 *  and setting its corresponding rows, based on the user input*/

	MGPIO_voidSetPinValue(C2_Port,C2_Pin,OUTPUT_HIGH);

	Cx_R1Value = GET_BIT(Copy_C2Value,0);
	Cx_R2Value = GET_BIT(Copy_C2Value,1);
	Cx_R3Value = GET_BIT(Copy_C2Value,2);
	Cx_R4Value = GET_BIT(Copy_C2Value,3);
	Cx_R5Value = GET_BIT(Copy_C2Value,4);
	Cx_R6Value = GET_BIT(Copy_C2Value,5);
	Cx_R7Value = GET_BIT(Copy_C2Value,6);
	Cx_R8Value = GET_BIT(Copy_C2Value,7);

	MGPIO_voidSetPinValue(R1_Port,R1_Pin,Cx_R1Value);
	MGPIO_voidSetPinValue(R2_Port,R2_Pin,Cx_R2Value);
	MGPIO_voidSetPinValue(R3_Port,R3_Pin,Cx_R3Value);
	MGPIO_voidSetPinValue(R4_Port,R4_Pin,Cx_R4Value);
	MGPIO_voidSetPinValue(R5_Port,R5_Pin,Cx_R5Value);
	MGPIO_voidSetPinValue(R6_Port,R6_Pin,Cx_R6Value);
	MGPIO_voidSetPinValue(R7_Port,R7_Pin,Cx_R7Value);
	MGPIO_voidSetPinValue(R8_Port,R8_Pin,Cx_R8Value);

	STK_voidSetBusyWait(Deactivating_Delay);

	/*Deactivating all the columns*/
	Deactivate_Columns();

	/*Activating the Third column
	 *  and setting its corresponding rows, based on the user input*/

	MGPIO_voidSetPinValue(C3_Port,C3_Pin,OUTPUT_HIGH);

	Cx_R1Value = GET_BIT(Copy_C3Value,0);
	Cx_R2Value = GET_BIT(Copy_C3Value,1);
	Cx_R3Value = GET_BIT(Copy_C3Value,2);
	Cx_R4Value = GET_BIT(Copy_C3Value,3);
	Cx_R5Value = GET_BIT(Copy_C3Value,4);
	Cx_R6Value = GET_BIT(Copy_C3Value,5);
	Cx_R7Value = GET_BIT(Copy_C3Value,6);
	Cx_R8Value = GET_BIT(Copy_C3Value,7);

	MGPIO_voidSetPinValue(R1_Port,R1_Pin,Cx_R1Value);
	MGPIO_voidSetPinValue(R2_Port,R2_Pin,Cx_R2Value);
	MGPIO_voidSetPinValue(R3_Port,R3_Pin,Cx_R3Value);
	MGPIO_voidSetPinValue(R4_Port,R4_Pin,Cx_R4Value);
	MGPIO_voidSetPinValue(R5_Port,R5_Pin,Cx_R5Value);
	MGPIO_voidSetPinValue(R6_Port,R6_Pin,Cx_R6Value);
	MGPIO_voidSetPinValue(R7_Port,R7_Pin,Cx_R7Value);
	MGPIO_voidSetPinValue(R8_Port,R8_Pin,Cx_R8Value);

	STK_voidSetBusyWait(Deactivating_Delay);

	/*Deactivating all the columns*/
	Deactivate_Columns();

	/*Activating the Fourth column
	 *  and setting its corresponding rows, based on the user input*/

	MGPIO_voidSetPinValue(C4_Port,C4_Pin,OUTPUT_HIGH);

	Cx_R1Value = GET_BIT(Copy_C4Value,0);
	Cx_R2Value = GET_BIT(Copy_C4Value,1);
	Cx_R3Value = GET_BIT(Copy_C4Value,2);
	Cx_R4Value = GET_BIT(Copy_C4Value,3);
	Cx_R5Value = GET_BIT(Copy_C4Value,4);
	Cx_R6Value = GET_BIT(Copy_C4Value,5);
	Cx_R7Value = GET_BIT(Copy_C4Value,6);
	Cx_R8Value = GET_BIT(Copy_C4Value,7);

	MGPIO_voidSetPinValue(R1_Port,R1_Pin,Cx_R1Value);
	MGPIO_voidSetPinValue(R2_Port,R2_Pin,Cx_R2Value);
	MGPIO_voidSetPinValue(R3_Port,R3_Pin,Cx_R3Value);
	MGPIO_voidSetPinValue(R4_Port,R4_Pin,Cx_R4Value);
	MGPIO_voidSetPinValue(R5_Port,R5_Pin,Cx_R5Value);
	MGPIO_voidSetPinValue(R6_Port,R6_Pin,Cx_R6Value);
	MGPIO_voidSetPinValue(R7_Port,R7_Pin,Cx_R7Value);
	MGPIO_voidSetPinValue(R8_Port,R8_Pin,Cx_R8Value);

	STK_voidSetBusyWait(Deactivating_Delay);

	/*Deactivating all the columns*/
	Deactivate_Columns();

	/*Activating the Fifth column
	 *  and setting its corresponding rows, based on the user input*/

	MGPIO_voidSetPinValue(C5_Port,C5_Pin,OUTPUT_HIGH);

	Cx_R1Value = GET_BIT(Copy_C5Value,0);
	Cx_R2Value = GET_BIT(Copy_C5Value,1);
	Cx_R3Value = GET_BIT(Copy_C5Value,2);
	Cx_R4Value = GET_BIT(Copy_C5Value,3);
	Cx_R5Value = GET_BIT(Copy_C5Value,4);
	Cx_R6Value = GET_BIT(Copy_C5Value,5);
	Cx_R7Value = GET_BIT(Copy_C5Value,6);
	Cx_R8Value = GET_BIT(Copy_C5Value,7);

	MGPIO_voidSetPinValue(R1_Port,R1_Pin,Cx_R1Value);
	MGPIO_voidSetPinValue(R2_Port,R2_Pin,Cx_R2Value);
	MGPIO_voidSetPinValue(R3_Port,R3_Pin,Cx_R3Value);
	MGPIO_voidSetPinValue(R4_Port,R4_Pin,Cx_R4Value);
	MGPIO_voidSetPinValue(R5_Port,R5_Pin,Cx_R5Value);
	MGPIO_voidSetPinValue(R6_Port,R6_Pin,Cx_R6Value);
	MGPIO_voidSetPinValue(R7_Port,R7_Pin,Cx_R7Value);
	MGPIO_voidSetPinValue(R8_Port,R8_Pin,Cx_R8Value);

	STK_voidSetBusyWait(Deactivating_Delay);

	/*Deactivating all the columns*/
	Deactivate_Columns();

	/*Activating the Sixth column
	 *  and setting its corresponding rows, based on the user input*/

	MGPIO_voidSetPinValue(C6_Port,C6_Pin,OUTPUT_HIGH);

	Cx_R1Value = GET_BIT(Copy_C6Value,0);
	Cx_R2Value = GET_BIT(Copy_C6Value,1);
	Cx_R3Value = GET_BIT(Copy_C6Value,2);
	Cx_R4Value = GET_BIT(Copy_C6Value,3);
	Cx_R5Value = GET_BIT(Copy_C6Value,4);
	Cx_R6Value = GET_BIT(Copy_C6Value,5);
	Cx_R7Value = GET_BIT(Copy_C6Value,6);
	Cx_R8Value = GET_BIT(Copy_C6Value,7);

	MGPIO_voidSetPinValue(R1_Port,R1_Pin,Cx_R1Value);
	MGPIO_voidSetPinValue(R2_Port,R2_Pin,Cx_R2Value);
	MGPIO_voidSetPinValue(R3_Port,R3_Pin,Cx_R3Value);
	MGPIO_voidSetPinValue(R4_Port,R4_Pin,Cx_R4Value);
	MGPIO_voidSetPinValue(R5_Port,R5_Pin,Cx_R5Value);
	MGPIO_voidSetPinValue(R6_Port,R6_Pin,Cx_R6Value);
	MGPIO_voidSetPinValue(R7_Port,R7_Pin,Cx_R7Value);
	MGPIO_voidSetPinValue(R8_Port,R8_Pin,Cx_R8Value);

	STK_voidSetBusyWait(Deactivating_Delay);

	/*Deactivating all the columns*/
	Deactivate_Columns();

	/*Activating the Seventh column
	 *  and setting its corresponding rows, based on the user input*/

	MGPIO_voidSetPinValue(C7_Port,C7_Pin,OUTPUT_HIGH);

	Cx_R1Value = GET_BIT(Copy_C7Value,0);
	Cx_R2Value = GET_BIT(Copy_C7Value,1);
	Cx_R3Value = GET_BIT(Copy_C7Value,2);
	Cx_R4Value = GET_BIT(Copy_C7Value,3);
	Cx_R5Value = GET_BIT(Copy_C7Value,4);
	Cx_R6Value = GET_BIT(Copy_C7Value,5);
	Cx_R7Value = GET_BIT(Copy_C7Value,6);
	Cx_R8Value = GET_BIT(Copy_C7Value,7);

	MGPIO_voidSetPinValue(R1_Port,R1_Pin,Cx_R1Value);
	MGPIO_voidSetPinValue(R2_Port,R2_Pin,Cx_R2Value);
	MGPIO_voidSetPinValue(R3_Port,R3_Pin,Cx_R3Value);
	MGPIO_voidSetPinValue(R4_Port,R4_Pin,Cx_R4Value);
	MGPIO_voidSetPinValue(R5_Port,R5_Pin,Cx_R5Value);
	MGPIO_voidSetPinValue(R6_Port,R6_Pin,Cx_R6Value);
	MGPIO_voidSetPinValue(R7_Port,R7_Pin,Cx_R7Value);
	MGPIO_voidSetPinValue(R8_Port,R8_Pin,Cx_R8Value);

	STK_voidSetBusyWait(Deactivating_Delay);

	/*Deactivating all the columns*/
	Deactivate_Columns();

	/*Activating the Eights column
	 *  and setting its corresponding rows, based on the user input*/

	MGPIO_voidSetPinValue(C8_Port,C8_Pin,OUTPUT_HIGH);

	Cx_R1Value = GET_BIT(Copy_C8Value,0);
	Cx_R2Value = GET_BIT(Copy_C8Value,1);
	Cx_R3Value = GET_BIT(Copy_C8Value,2);
	Cx_R4Value = GET_BIT(Copy_C8Value,3);
	Cx_R5Value = GET_BIT(Copy_C8Value,4);
	Cx_R6Value = GET_BIT(Copy_C8Value,5);
	Cx_R7Value = GET_BIT(Copy_C8Value,6);
	Cx_R8Value = GET_BIT(Copy_C8Value,7);

	MGPIO_voidSetPinValue(R1_Port,R1_Pin,Cx_R1Value);
	MGPIO_voidSetPinValue(R2_Port,R2_Pin,Cx_R2Value);
	MGPIO_voidSetPinValue(R3_Port,R3_Pin,Cx_R3Value);
	MGPIO_voidSetPinValue(R4_Port,R4_Pin,Cx_R4Value);
	MGPIO_voidSetPinValue(R5_Port,R5_Pin,Cx_R5Value);
	MGPIO_voidSetPinValue(R6_Port,R6_Pin,Cx_R6Value);
	MGPIO_voidSetPinValue(R7_Port,R7_Pin,Cx_R7Value);
	MGPIO_voidSetPinValue(R8_Port,R8_Pin,Cx_R8Value);

	STK_voidSetBusyWait(Deactivating_Delay);

	/*Deactivating all the columns*/
	Deactivate_Columns();
}

static void Deactivate_Columns(void)
{
	/*Setting all pins as low*/
	MGPIO_voidSetPinValue(C1_Port,C1_Pin,OUTPUT_LOW);
	MGPIO_voidSetPinValue(C2_Port,C2_Pin,OUTPUT_LOW);
	MGPIO_voidSetPinValue(C3_Port,C3_Pin,OUTPUT_LOW);
	MGPIO_voidSetPinValue(C4_Port,C4_Pin,OUTPUT_LOW);
	MGPIO_voidSetPinValue(C5_Port,C5_Pin,OUTPUT_LOW);
	MGPIO_voidSetPinValue(C6_Port,C6_Pin,OUTPUT_LOW);
	MGPIO_voidSetPinValue(C7_Port,C7_Pin,OUTPUT_LOW);
	MGPIO_voidSetPinValue(C8_Port,C8_Pin,OUTPUT_LOW);


}




