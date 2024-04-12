/*
 * RCC_Program.c
 *
 *  Created on: Nov 5, 2023
 *      Author: nours
 */

#include <MCAL/RCC/RCC_Config.h>
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"
#include "../include/MCAL/RCC/RCC_Interface.h"
#include "../include/MCAL/RCC/RCC_Private.h"


/***************************************/
/* Func. Name:MRCC_voidInit            */
/* i/p arguments:Nothing               */
/* o/p arguments:Nothing               */
/* Desc. : This API allows user to     */
/*select the clk source of the system  */
/*************************************/
void MRCC_voidInit(void)
{
	#if SYS_CLK_SRC == HSI
	//Turn On HSI
	SET_BIT(RCC_CR,0);
	//Set SysClk as HSI
	CLR_BIT(RCC_CFGR,0);
	CLR_BIT(RCC_CFGR,1);
	#elif SYS_CLK_SRC == HSE
	//Turn On HSE
	SET_BIT(RCC_CR,16);
	//Set SysClk as HSI
	SET_BIT(RCC_CFGR,0);
	CLR_BIT(RCC_CFGR,1);
	#elif SYS_CLK_SRC == PLL
	//Turn On HSI
	SET_BIT(RCC_CR,24);
	//Set SysClk as PLL
	#endif
}


/******************************************/
/* Func. Name: MRCC_voidEnablePerClk      */
/* i/p arguments: AHB1,AHB2,APB1,APB2     */
/* i/p arguments: 0-->31                  */
/* o/p arguments:Nothing                  */
/* Desc. : This API allows user to        */
/*Enable the clk source of the Peripherals*/
/******************************************/
void MRCC_voidEnablePerClk(u8 A_u8BusId,u8 A_u8PerId)
{
	//i/p Valiation
	if((A_u8BusId > APB2) || (A_u8PerId > 31))
	{
		//Do Nothing
	}
	else
	{
		switch(A_u8BusId)
		{
		case AHB1:
			SET_BIT(RCC_AHB1ENR,A_u8PerId);
			break;
		case AHB2:
			if(A_u8PerId != 7)
			{
				//Do Nothing
			}
			else
			{
			SET_BIT(RCC_AHB2ENR,A_u8PerId);
			}

			break;
		case APB1:
			SET_BIT(RCC_APB1ENR,A_u8PerId);
			break;
		case APB2:
			SET_BIT(RCC_APB2ENR,A_u8PerId);
			break;
		}
	}
}



/******************************************/
/* Func. Name: MRCC_voidDisablePerClk     */
/* i/p arguments: AHB1,AHB2,APB1,APB2     */
/* i/p arguments: 0-->31                  */
/* o/p arguments:Nothing                  */
/* Desc. : This API allows user to        */
/*Disable clk source of the Peripherals   */
/******************************************/
void MRCC_voidDisablePerClk(u8 A_u8BusId,u8 A_u8PerId)
{
	//i/p Valiation
		if((A_u8BusId > APB2) || (A_u8PerId > 31))
		{
			//Do Nothing
		}
		else
		{
			switch(A_u8BusId)
			{
			case AHB1:
				CLR_BIT(RCC_AHB1ENR,A_u8PerId);
				break;
			case AHB2:
				if(A_u8PerId != 7)
				{
					//Do Nothing
				}
				else
				{
				CLR_BIT(RCC_AHB2ENR,A_u8PerId);
				}

				break;
			case APB1:
				CLR_BIT(RCC_APB1ENR,A_u8PerId);
				break;
			case APB2:
				CLR_BIT(RCC_APB2ENR,A_u8PerId);
				break;
			}
		}
}

/************************************************/
/* Func. Name: MRCC_voidEnableLOWPerClk         */
/* i/p arguments: AHB1,AHB2,APB1,APB2           */
/* i/p arguments: 0-->31                        */
/* o/p arguments:Nothing                        */
/* Desc. : This API allows user to              */
/*enable clk source of the low power Peripherals*/
/************************************************/
void MRCC_voidEnableLOWPerClk(u8 A_u8BusId,u8 A_u8PerId)
{
	//i/p Valiation
		if((A_u8BusId > APB2) || (A_u8PerId > 31))
		{
			//Do Nothing
		}
		else
		{
			switch(A_u8BusId)
			{
			case AHB1:
				SET_BIT(RCC_AHB1LPENR,A_u8PerId);
				break;
			case AHB2:
				if(A_u8PerId != 7)
				{
					//Do Nothing
				}
				else
				{
				SET_BIT(RCC_AHB2LPENR,A_u8PerId);
				}

				break;
			case APB1:
				SET_BIT(RCC_APB1LPENR,A_u8PerId);
				break;
			case APB2:
				SET_BIT(RCC_APB2LPENR,A_u8PerId);
				break;
			}
		}


}
/*************************************************/
/* Func. Name: MRCC_voidDisableLOWPerClk         */
/* i/p arguments: AHB1,AHB2,APB1,APB2            */
/* i/p arguments: 0-->31                         */
/* o/p arguments:Nothing                         */
/* Desc. : This API allows user to               */
/*disable clk source of the low power Peripherals*/
/*************************************************/
void MRCC_voidDisableLOWPerClk(u8 A_u8BusId,u8 A_u8PerId)
{
	//i/p Valiation
			if((A_u8BusId > APB2) || (A_u8PerId > 31))
			{
				//Do Nothing
			}
			else
			{
				switch(A_u8BusId)
				{
				case AHB1:
					CLR_BIT(RCC_AHB1LPENR,A_u8PerId);
					break;
				case AHB2:
					if(A_u8PerId != 7)
					{
						//Do Nothing
					}
					else
					{
					CLR_BIT(RCC_AHB2LPENR,A_u8PerId);
					}

					break;
				case APB1:
					CLR_BIT(RCC_APB1LPENR,A_u8PerId);
					break;
				case APB2:
					CLR_BIT(RCC_APB2LPENR,A_u8PerId);
					break;
				}
			}





}
