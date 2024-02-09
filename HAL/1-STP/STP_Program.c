/********************************************/
/* SWC: STP Driver                          */
/* Author: Bendary                          */
/* Version: v0.0                            */
/* Date: 22 SEP 2023                        */
/* Description: This is the implem. of STP  */
/********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_Interface.h"
#include "STK_Interface.h"

#include "STP_Interface.h"
#include "STP_Private.h"
#include "STP_Config.h"

void STP_voidInit()
{
    /*Configure the direction of SERIAL_PIN, SHIFT_CLK_PIN, STORE_CLK_PIN as O/P, PP, LS*/
    GPIO_voidSetPinMode(SERIAL_PIN,    OUTPUT);
    GPIO_voidSetPinMode(SHIFT_CLK_PIN, OUTPUT);
    GPIO_voidSetPinMode(STORE_CLK_PIN, OUTPUT);

    GPIO_voidSetPinType(SERIAL_PIN,    OUTPUT_PP);
    GPIO_voidSetPinType(SHIFT_CLK_PIN, OUTPUT_PP);
    GPIO_voidSetPinType(STORE_CLK_PIN, OUTPUT_PP);

    GPIO_voidSetPinSpeed(SERIAL_PIN,    OUTPUT_LS);
    GPIO_voidSetPinSpeed(SHIFT_CLK_PIN, OUTPUT_LS);
    GPIO_voidSetPinSpeed(STORE_CLK_PIN, OUTPUT_LS);
}

void STP_voidSendSynch(u8 Copy_u8Data)  //01010101  
{
    s8 Local_s8Counter;
    u8 Local_u8BitValue;
    for(Local_s8Counter = 7; Local_s8Counter >= 0; Local_s8Counter--)
    {
        /*write the current bit*/
        Local_u8BitValue = GET_BIT(Copy_u8Data, Local_s8Counter);
        GPIO_voidSetPinValue(SERIAL_PIN, Local_u8BitValue);
        /*Clk on SHIFT clk pin*/
        GPIO_voidSetPinValue(SHIFT_CLK_PIN, OUTPUT_HIGH);
        STK_voidSetBusyWait(1);
        GPIO_voidSetPinValue(SHIFT_CLK_PIN, OUTPUT_LOW);
        STK_voidSetBusyWait(1);
    }
    /*Clk on SHIFT clk pin*/
    GPIO_voidSetPinValue(STORE_CLK_PIN, OUTPUT_HIGH);
    STK_voidSetBusyWait(1);
    GPIO_voidSetPinValue(STORE_CLK_PIN, OUTPUT_LOW);
    STK_voidSetBusyWait(1);
}
