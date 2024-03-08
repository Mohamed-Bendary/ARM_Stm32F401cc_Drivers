/*
 * GPIO_Program.c
 *
 *  Created on: Nov 5, 2023
 *      Author: nours
 */



#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"
#include "../include/MCAL/GPIO/GPIO_Interface.h"
#include "../include/MCAL/GPIO/GPIO_Private.h"
#include "../include/MCAL/GPIO/GPIO_Config.h"


/***************************************/
/* Func. Name:MGPIO_voidSetPinMode     */
/* i/p arguments:IOA,IOB,IOC           */
/* i/p arguments:0-->15                */
/* i/p arguments:InpuT, output         */
/* Alternate function, Analog          */
/* o/p arguments:Nothing               */
/* Desc. : This API allows user to     */
/*Set the Pin Mode                     */
/***************************************/
void MGPIO_voidSetPinMode(u8 A_u8PortId,u8 A_u8PinId,u8 A_u8Mode)
{
	/*i/p Validation*/
	if((A_u8PortId > IOC) || (A_u8PinId > 15) || (A_u8Mode > ANALOG_MODE))
	{
		//Do Nothing
	}
	else
	{
		switch(A_u8Mode)
		{
		case INPUT_MODE:
			switch(A_u8PortId)
			{
			case IOA:
				CLR_BIT(GPIOA->MODER, (A_u8PinId*2));
				CLR_BIT(GPIOA->MODER, (A_u8PinId*2)+1);
				break;
			case IOB:
				CLR_BIT(GPIOB->MODER, (A_u8PinId*2));
				CLR_BIT(GPIOB->MODER, (A_u8PinId*2)+1);
				break;
			case IOC:
				CLR_BIT(GPIOC->MODER, (A_u8PinId*2));
				CLR_BIT(GPIOC->MODER, (A_u8PinId*2)+1);
				break;
			}
			break;
		case OUTPUT_MODE:
			switch(A_u8PortId)
			{
			case IOA:
				SET_BIT(GPIOA->MODER, (A_u8PinId*2));
				CLR_BIT(GPIOA->MODER, (A_u8PinId*2)+1);
				break;
			case IOB:
			    SET_BIT(GPIOB->MODER, (A_u8PinId*2));
				CLR_BIT(GPIOB->MODER, (A_u8PinId*2)+1);
				break;
			case IOC:
				SET_BIT(GPIOC->MODER, (A_u8PinId*2));
				CLR_BIT(GPIOC->MODER, (A_u8PinId*2)+1);
				break;
			}
			break;
		   case AF_MODE:
			switch(A_u8PortId)
			{
			case IOA:
				CLR_BIT(GPIOA->MODER, (A_u8PinId*2));
				SET_BIT(GPIOA->MODER, (A_u8PinId*2)+1);
				break;
		   case IOB:
			    CLR_BIT(GPIOB->MODER, (A_u8PinId*2));
				SET_BIT(GPIOB->MODER, (A_u8PinId*2)+1);
				break;
			case IOC:
				CLR_BIT(GPIOC->MODER, (A_u8PinId*2));
				SET_BIT(GPIOC->MODER, (A_u8PinId*2)+1);
				break;
			}
				break;

		case ANALOG_MODE:
			switch(A_u8PortId)
			{
			case IOA:
				SET_BIT(GPIOA->MODER, (A_u8PinId*2));
				SET_BIT(GPIOA->MODER, (A_u8PinId*2)+1);
				break;
			case IOB:
				SET_BIT(GPIOB->MODER, (A_u8PinId*2));
				SET_BIT(GPIOB->MODER, (A_u8PinId*2)+1);
				break;
			case IOC:
				SET_BIT(GPIOC->MODER, (A_u8PinId*2));
				SET_BIT(GPIOC->MODER, (A_u8PinId*2)+1);
				break;
			}
			    break;
		}
	}
}


/***************************************/
/* Func. MGPIO_voidSetPinType          */
/* i/p arguments:IOA,IOB,IOC           */
/* i/p arguments:0-->15                */
/* i/p arguments: PushPull, Open Drain */
/* o/p arguments:Nothing               */
/* Desc. : This API allows user to     */
/*Set the Output Pin Type              */
/***************************************/
void MGPIO_voidSetPinType(u8 A_u8PortId,u8 A_u8PinId,u8 A_u8Type)
{
	/*i/p Validation*/
	if((A_u8PortId > IOC) || (A_u8PinId > 15) || (A_u8Type > OUTPUT_OD))
	{
		//Do Nothing
	}
	else
	{
		switch(A_u8Type)
		{
		case OUTPUT_PP:
			switch(A_u8PortId)
			{
			case IOA:
				CLR_BIT(GPIOA->OTYPER,A_u8PinId);
				break;
			case IOB:
				CLR_BIT(GPIOB->OTYPER,A_u8PinId);
				break;
			case IOC:
				CLR_BIT(GPIOC->OTYPER,A_u8PinId);
				break;
			}
			break;
		case OUTPUT_OD:
			switch(A_u8PortId)
			{
			case IOA:
				SET_BIT(GPIOA->OTYPER,A_u8PinId);
				break;
			case IOB:
				SET_BIT(GPIOB->OTYPER,A_u8PinId);
				break;
			case IOC:
				SET_BIT(GPIOC->OTYPER,A_u8PinId);
				break;
			}
			break;
		}
	}
}

/**********************************************/
/* Func. MGPIO_voidSetPinSpeed                */
/* i/p arguments:IOA,IOB,IOC                  */
/* i/p arguments:0-->15                       */
/* i/p arguments: Low, Med, High,V.High Speed */
/* o/p arguments:Nothing                      */
/* Desc. : This API allows user to            */
/*Set the Output Pin Speed                    */
/**********************************************/
void MGPIO_voidSetPinSpeed(u8 A_u8PortId,u8 A_u8PinId,u8 A_u8Speed)
{
	/*i/p Validation*/
	if((A_u8PortId > IOC) || (A_u8PinId > 15) || (A_u8Speed > VHIGH_SPEED))
		{
			//Do Nothing
		}
		else
		{
			switch(A_u8Speed)
			{
			case LOW_SPEED:
				switch(A_u8PortId)
				{
				case IOA:
					CLR_BIT(GPIOA->OSPEEDR,(A_u8PinId*2));
					CLR_BIT(GPIOA->OSPEEDR,(A_u8PinId*2)+1);
					break;
				case IOB:
					CLR_BIT(GPIOB->OSPEEDR,(A_u8PinId*2));
					CLR_BIT(GPIOB->OSPEEDR,(A_u8PinId*2)+1);
					break;
				case IOC:
					CLR_BIT(GPIOC->OSPEEDR,(A_u8PinId*2));
					CLR_BIT(GPIOC->OSPEEDR,(A_u8PinId*2)+1);
					break;
				}
				break;
			case MED_SPEED:
				switch(A_u8PortId)
				{
				case IOA:
					SET_BIT(GPIOA->OSPEEDR,(A_u8PinId*2));
					CLR_BIT(GPIOA->OSPEEDR,(A_u8PinId*2)+1);
					break;
				case IOB:
					SET_BIT(GPIOB->OSPEEDR,(A_u8PinId*2));
					CLR_BIT(GPIOB->OSPEEDR,(A_u8PinId*2)+1);
					break;
				case IOC:
					SET_BIT(GPIOC->OSPEEDR,(A_u8PinId*2));
					CLR_BIT(GPIOC->OSPEEDR,(A_u8PinId*2)+1);
					break;
				}
				break;
				case HIGH_SPEED:
					switch(A_u8PortId)
				{
				case IOA:
					CLR_BIT(GPIOA->OSPEEDR,(A_u8PinId*2));
					SET_BIT(GPIOA->OSPEEDR,(A_u8PinId*2)+1);
					break;
				case IOB:
					CLR_BIT(GPIOB->OSPEEDR,(A_u8PinId*2));
					SET_BIT(GPIOB->OSPEEDR,(A_u8PinId*2)+1);
					break;
				case IOC:
					CLR_BIT(GPIOC->OSPEEDR,(A_u8PinId*2));
					SET_BIT(GPIOC->OSPEEDR,(A_u8PinId*2)+1);
					break;
			}
					break;
				case VHIGH_SPEED:
					switch(A_u8PortId)
			{
				case IOA:
					 SET_BIT(GPIOA->OSPEEDR,(A_u8PinId*2));
					 SET_BIT(GPIOA->OSPEEDR,(A_u8PinId*2)+1);
					 break;
				case IOB:
					 SET_BIT(GPIOB->OSPEEDR,(A_u8PinId*2));
					 SET_BIT(GPIOB->OSPEEDR,(A_u8PinId*2)+1);
					 break;
				case IOC:
					 SET_BIT(GPIOC->OSPEEDR,(A_u8PinId*2));
					 SET_BIT(GPIOC->OSPEEDR,(A_u8PinId*2)+1);
					 break;
			}
					 break;
		}
	}
}

/******************************************/
/* Func. MGPIO_voidSetPinValue            */
/* i/p arguments:IOA,IOB,IOC              */
/* i/p arguments:0-->15                   */
/* i/p arguments: Output_Low, Output_High */
/* o/p arguments:Nothing                  */
/* Desc. : This API allows user to        */
/*Set the Output Pin Value                */
/******************************************/
void MGPIO_voidSetPinValue(u8 A_u8PortId,u8 A_u8PinId,u8 A_u8Value)
{
	/*i/p Validation*/
	if((A_u8PortId > IOC) || (A_u8PinId > 15) || (A_u8Value > OUTPUT_HIGH))
	{

	}
	else
	{
		switch(A_u8Value)
		{
		case OUTPUT_LOW:
			switch(A_u8PortId)
			{
			case IOA:
				CLR_BIT(GPIOA->ODR,A_u8PinId);
				break;
			case IOB:
				CLR_BIT(GPIOB->ODR,A_u8PinId);
				break;
			case IOC:
				CLR_BIT(GPIOC->ODR,A_u8PinId);
				break;
			}
				break;
		case OUTPUT_HIGH:
			switch(A_u8PortId)
			{
			case IOA:
				SET_BIT(GPIOA->ODR,A_u8PinId);
				break;
			case IOB:
				SET_BIT(GPIOB->ODR,A_u8PinId);
				break;
			case IOC:
				SET_BIT(GPIOC->ODR,A_u8PinId);
				break;
			}
				break;
		}
	}
}

/******************************************/
/* Func. MGPIO_voidSetPortValue           */
/* i/p arguments:IOA,IOB,IOC              */
/* i/p arguments:0-->15                   */
/* i/p arguments: Output_Low, Output_High */
/* o/p arguments:Nothing                  */
/* Desc. : This API allows user to        */
/*Set All Pins Value                      */
/******************************************/
void MGPIO_voidSetPortValue(u8 A_u8PortId,u32 A_u8Value)
{
	if(A_u8PortId > IOC)
	{
		//Do Nothing
	}
	else
	{
		switch(A_u8PortId)
		{
		case IOA:
			GPIOA->ODR = A_u8Value;
			break;
		case IOB:
			GPIOB->ODR = A_u8Value;
			break;
		case IOC:
			GPIOC->ODR = A_u8Value;
			break;
		}
	}

}

/**************************************************/
/* Func. MGPIO_voidSetPinValueDirectAccess        */
/* i/p arguments:IOA,IOB,IOC                      */
/* i/p arguments:0-->15                           */
/* i/p arguments: OUTPUT_RESET, OUTPUT_SET        */
/* o/p arguments:Nothing                          */
/* Desc. : This API allows user to                */
/*Set Pin Value                                   */
/**************************************************/
void MGPIO_voidSetPinValueDirectAccess(u8 A_u8PortId,u8 A_u8PinId,u8 A_u8SetRstType)
{
	if((A_u8PortId > IOC) || (A_u8PinId > 15) || (A_u8SetRstType > OUTPUT_SET))
	{
		//Do Nothing
	}
	else
	{
		switch(A_u8SetRstType)
		{
		case OUTPUT_RESET:
			switch(A_u8PortId)
			{
			case IOA:
				GPIOA->BSRR = (1 << (A_u8PinId + 16));
			    break;
			case IOB:
				GPIOB->BSRR = (1 << (A_u8PinId + 16));
			    break;
			case IOC:
				GPIOC->BSRR = (1 << (A_u8PinId + 16));
			    break;
			}
			break;
		case OUTPUT_SET:
			switch(A_u8PortId)
			{
			case IOA:
				GPIOA->BSRR = (1 << A_u8PinId);
				break;
			case IOB:
				GPIOB->BSRR = (1 << A_u8PinId);
				break;
			case IOC:
				GPIOC->BSRR = (1 << A_u8PinId);
				break;
			}
			break;
		}
	}
}

/**************************************************/
/* Func. MGPIO_voidSetPinPuPdConfig               */
/* i/p arguments:IOA,IOB,IOC                      */
/* i/p arguments:0-->15                           */
/* i/p arguments: FLOATING, PULL UP, PULL DOWN    */
/* o/p arguments:Nothing                          */
/* Desc. : This API allows user to                */
/*Set Pin Value                                   */
/**************************************************/
void MGPIO_voidSetPinPuPdConfig(u8 A_u8PortId,u8 A_u8PinId,u8 A_u8Type)
{
	if((A_u8PortId > IOC) || (A_u8PinId > 15) || (A_u8Type > PULL_DOWN))
	{
		//Do Nothing
	}
	else
	{
		switch(A_u8Type)
		{
		case FLOATING:
			switch(A_u8PortId)
			{
			case IOA:
				CLR_BIT(GPIOA->PUPDR,(A_u8PinId*2));
				CLR_BIT(GPIOA->PUPDR,((A_u8PinId*2) + 1));
				break;
			case IOB:
				CLR_BIT(GPIOB->PUPDR,(A_u8PinId*2));
				CLR_BIT(GPIOB->PUPDR,((A_u8PinId*2) + 1));
				break;
			case IOC:
				CLR_BIT(GPIOC->PUPDR,(A_u8PinId*2));
				CLR_BIT(GPIOC->PUPDR,((A_u8PinId*2) + 1));
				break;
			}
			break;
		case PULL_UP:
			switch(A_u8PortId)
			{
			case IOA:
				SET_BIT(GPIOA->PUPDR,(A_u8PinId*2));
				CLR_BIT(GPIOA->PUPDR,((A_u8PinId*2) + 1));
				break;
			case IOB:
				SET_BIT(GPIOB->PUPDR,(A_u8PinId*2));
				CLR_BIT(GPIOB->PUPDR,((A_u8PinId*2) + 1));
				break;
			case IOC:
				SET_BIT(GPIOC->PUPDR,(A_u8PinId*2));
				CLR_BIT(GPIOC->PUPDR,((A_u8PinId*2) + 1));
				break;
			}
			break;
		case PULL_DOWN:
			switch(A_u8PortId)
			{
			case IOA:
				CLR_BIT(GPIOA->PUPDR,(A_u8PinId*2));
				SET_BIT(GPIOA->PUPDR,((A_u8PinId*2) + 1));
				break;
			case IOB:
				CLR_BIT(GPIOB->PUPDR,(A_u8PinId*2));
				SET_BIT(GPIOB->PUPDR,((A_u8PinId*2) + 1));
			break;
			case IOC:
				CLR_BIT(GPIOC->PUPDR,(A_u8PinId*2));
				SET_BIT(GPIOC->PUPDR,((A_u8PinId*2) + 1));
				break;
			}
		break;
	 }
  }
}

/**************************************************/
/* Func. MGPIO_u8GetPinValue                      */
/* i/p arguments:IOA,IOB,IOC                      */
/* i/p arguments:0-->15                           */
/* o/p arguments: u8 Pin Value                    */
/* Desc. : This API allows user to                */
/*Get Pin Value                                   */
/**************************************************/
u8 MGPIO_u8GetPinValue(u8 A_u8PortId,u8 A_u8PinId)
{
	u8 local_u8PinValue;
	/*i/p Validation*/
	if((A_u8PortId > IOC) || (A_u8PinId > 15))
	{
		//Do Nothing
	}
	else
	{
		switch(A_u8PortId)
		{
		case IOA:
			local_u8PinValue = GET_BIT(GPIOA->IDR,A_u8PinId);
			break;
		case IOB:
			local_u8PinValue = GET_BIT(GPIOB->IDR,A_u8PinId);
			break;
		case IOC:
			local_u8PinValue = GET_BIT(GPIOC->IDR,A_u8PinId);
			break;
	    }
      }
	return local_u8PinValue;
}
