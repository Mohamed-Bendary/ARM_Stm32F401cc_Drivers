/*
 * GPIO_program.c
 *
 *  Created on: Jul 23, 2022
 *      Author: abdelrahmanhossam
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_Interface.h"
#include "RCC_Private.h"
#include "RCC_Config.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_configurations.h"

/******************************************************************************************/
/*Function: MGPIO_voidSetPinDirection	                         						  */
/*I/P Parameters: Port - Pin - Direction of Pin - Speed         			  			  */
/*Returns:it returns no thing	                            				  			  */
/*Desc:This Function Configures the pin 							          			  */
/******************************************************************************************/
/*
 * Options for copy_u8PORT:- GPIOA_PORT - GPIOB_PORT - GPIOC_PORT
 * Options for copy_u8PIN :- PIN0 ... PIN15
 * Options for copy_u8Direction:-
 * 								 - In case of Output
 * 								 	OUTPUT_PUSH_PULL
 * 								 	OUTPUT_PUSH_PULL_PULL_UP
 * 								 	OUTPUT_PUSH_PULL_PULL_DOWN
 * 									OUTPUT_OPEN_DRAIN
 * 									OUTPUT_PUSH_OPEN_DRAIN_UP
 * 									OUTPUT_PUSH_OPEN_DRAIN_DOWN
 *								- In case of AF
 * 								 	AF_PUSH_PULL
 * 								 	AF_PUSH_PULL_PULL_UP
 * 								 	AF_PUSH_PULL_PULL_DOWN
 * 									AF_OPEN_DRAIN
 * 									AF_PUSH_OPEN_DRAIN_UP
 * 									AF_PUSH_OPEN_DRAIN_DOWN
 *								- In case of Input
 * 								 	INPUT_FLOATING
 * 								 	INPUT_PULL_UP
 * 								 	INPUT_PULL_DOWN
 * 									INPUT_ANALOG
 * Options for copy_u8Speed:- LOW_SPEED - MEDIUM_SPEED - HIGH_SPEED - VERY_HIGH_SPEED
 */
/******************************************************************************************/
void MGPIO_voidSetPinDirection(u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8Direction, u8 copy_u8Speed)
{
	switch (copy_u8PORT)
	{
	case GPIOA_PORT:
		if ((copy_u8Direction >= OUTPUT_PUSH_PULL) && (copy_u8Direction <= OUTPUT_PUSH_OPEN_DRAIN_DOWN))
		{
			SET_BIT(GPIOA->MODER, copy_u8PIN * 2);
			CLR_BIT(GPIOA->MODER, ((copy_u8PIN * 2) + 1));
		}
		else if ((copy_u8Direction >= AF_PUSH_PULL) && (copy_u8Direction <= AF_PUSH_OPEN_DRAIN_DOWN))
		{
			CLR_BIT(GPIOA->MODER, copy_u8PIN * 2);
			SET_BIT(GPIOA->MODER, ((copy_u8PIN * 2) + 1));
		}
		else if ((copy_u8Direction >= INPUT_FLOATING) && (copy_u8Direction <= INPUT_PULL_DOWN))
		{
			CLR_BIT(GPIOA->MODER, copy_u8PIN * 2);
			CLR_BIT(GPIOA->MODER, ((copy_u8PIN * 2) + 1));
		}
		else if (copy_u8Direction == INPUT_ANALOG)
		{
			SET_BIT(GPIOA->MODER, copy_u8PIN * 2);
			SET_BIT(GPIOA->MODER, ((copy_u8PIN * 2) + 1));
		}
		switch (copy_u8Direction)
		{
		case OUTPUT_PUSH_PULL:
		case AF_PUSH_PULL:
		case INPUT_FLOATING:
			CLR_BIT(GPIOA->OTYPER, copy_u8PIN);
			CLR_BIT(GPIOA->PUPDR, copy_u8PIN * 2);
			CLR_BIT(GPIOA->PUPDR, ((copy_u8PIN * 2) + 1));
			break;
		case OUTPUT_PUSH_PULL_PULL_UP:
		case AF_PUSH_PULL_PULL_UP:
		case INPUT_PULL_UP:
		case INPUT_ANALOG:
			CLR_BIT(GPIOA->OTYPER, copy_u8PIN);
			SET_BIT(GPIOA->PUPDR, copy_u8PIN * 2);
			CLR_BIT(GPIOA->PUPDR, ((copy_u8PIN * 2) + 1));
			break;
		case OUTPUT_PUSH_PULL_PULL_DOWN:
		case AF_PUSH_PULL_PULL_DOWN:
		case INPUT_PULL_DOWN:
			CLR_BIT(GPIOA->OTYPER, copy_u8PIN);
			CLR_BIT(GPIOA->PUPDR, copy_u8PIN * 2);
			SET_BIT(GPIOA->PUPDR, ((copy_u8PIN * 2) + 1));
			break;
		case OUTPUT_OPEN_DRAIN:
		case AF_OPEN_DRAIN:
			SET_BIT(GPIOA->OTYPER, copy_u8PIN);
			CLR_BIT(GPIOA->PUPDR, copy_u8PIN * 2);
			CLR_BIT(GPIOA->PUPDR, ((copy_u8PIN * 2) + 1));
			break;
		case OUTPUT_PUSH_OPEN_DRAIN_UP:
		case AF_PUSH_OPEN_DRAIN_UP:
			SET_BIT(GPIOA->OTYPER, copy_u8PIN);
			SET_BIT(GPIOA->PUPDR, copy_u8PIN * 2);
			CLR_BIT(GPIOA->PUPDR, ((copy_u8PIN * 2) + 1));
			break;
		case OUTPUT_PUSH_OPEN_DRAIN_DOWN:
		case AF_PUSH_OPEN_DRAIN_DOWN:
			SET_BIT(GPIOA->OTYPER, copy_u8PIN);
			CLR_BIT(GPIOA->PUPDR, copy_u8PIN * 2);
			SET_BIT(GPIOA->PUPDR, ((copy_u8PIN * 2) + 1));
			break;
		}
		GPIOA->OSPEEDR &= ~(3 << (copy_u8PIN * 2));
		GPIOA->OSPEEDR |= (copy_u8Speed << (copy_u8PIN * 2));
		break;

	case GPIOB_PORT:
		if ((copy_u8Direction >= OUTPUT_PUSH_PULL) && (copy_u8Direction <= OUTPUT_PUSH_OPEN_DRAIN_DOWN))
		{
			SET_BIT(GPIOB->MODER, copy_u8PIN * 2);
			CLR_BIT(GPIOB->MODER, ((copy_u8PIN * 2) + 1));
		}
		else if ((copy_u8Direction >= AF_PUSH_PULL) && (copy_u8Direction <= AF_PUSH_OPEN_DRAIN_DOWN))
		{
			CLR_BIT(GPIOB->MODER, copy_u8PIN * 2);
			SET_BIT(GPIOB->MODER, ((copy_u8PIN * 2) + 1));
		}
		else if ((copy_u8Direction >= INPUT_FLOATING) && (copy_u8Direction <= INPUT_PULL_DOWN))
		{
			CLR_BIT(GPIOB->MODER, copy_u8PIN * 2);
			CLR_BIT(GPIOB->MODER, ((copy_u8PIN * 2) + 1));
		}
		else if (copy_u8Direction == INPUT_ANALOG)
		{
			SET_BIT(GPIOB->MODER, copy_u8PIN * 2);
			SET_BIT(GPIOB->MODER, ((copy_u8PIN * 2) + 1));
		}
		switch (copy_u8Direction)
		{
		case OUTPUT_PUSH_PULL:
		case AF_PUSH_PULL:
		case INPUT_FLOATING:
			CLR_BIT(GPIOB->OTYPER, copy_u8PIN);
			CLR_BIT(GPIOB->PUPDR, copy_u8PIN * 2);
			CLR_BIT(GPIOB->PUPDR, ((copy_u8PIN * 2) + 1));
			break;
		case OUTPUT_PUSH_PULL_PULL_UP:
		case AF_PUSH_PULL_PULL_UP:
		case INPUT_PULL_UP:
		case INPUT_ANALOG:
			CLR_BIT(GPIOB->OTYPER, copy_u8PIN);
			SET_BIT(GPIOB->PUPDR, copy_u8PIN * 2);
			CLR_BIT(GPIOB->PUPDR, ((copy_u8PIN * 2) + 1));
			break;
		case OUTPUT_PUSH_PULL_PULL_DOWN:
		case AF_PUSH_PULL_PULL_DOWN:
		case INPUT_PULL_DOWN:
			CLR_BIT(GPIOB->OTYPER, copy_u8PIN);
			CLR_BIT(GPIOB->PUPDR, copy_u8PIN * 2);
			SET_BIT(GPIOB->PUPDR, ((copy_u8PIN * 2) + 1));
			break;
		case OUTPUT_OPEN_DRAIN:
		case AF_OPEN_DRAIN:
			SET_BIT(GPIOB->OTYPER, copy_u8PIN);
			CLR_BIT(GPIOB->PUPDR, copy_u8PIN * 2);
			CLR_BIT(GPIOB->PUPDR, ((copy_u8PIN * 2) + 1));
			break;
		case OUTPUT_PUSH_OPEN_DRAIN_UP:
		case AF_PUSH_OPEN_DRAIN_UP:
			SET_BIT(GPIOB->OTYPER, copy_u8PIN);
			SET_BIT(GPIOB->PUPDR, copy_u8PIN * 2);
			CLR_BIT(GPIOB->PUPDR, ((copy_u8PIN * 2) + 1));
			break;
		case OUTPUT_PUSH_OPEN_DRAIN_DOWN:
		case AF_PUSH_OPEN_DRAIN_DOWN:
			SET_BIT(GPIOB->OTYPER, copy_u8PIN);
			CLR_BIT(GPIOB->PUPDR, copy_u8PIN * 2);
			SET_BIT(GPIOB->PUPDR, ((copy_u8PIN * 2) + 1));
			break;
		}
		GPIOB->OSPEEDR &= ~(3 << (copy_u8PIN * 2));
		GPIOB->OSPEEDR |= (copy_u8Speed << (copy_u8PIN * 2));
		break;

	case GPIOC_PORT:
		if ((copy_u8Direction >= OUTPUT_PUSH_PULL) && (copy_u8Direction <= OUTPUT_PUSH_OPEN_DRAIN_DOWN))
		{
			SET_BIT(GPIOC->MODER, copy_u8PIN * 2);
			CLR_BIT(GPIOC->MODER, ((copy_u8PIN * 2) + 1));
		}
		else if ((copy_u8Direction >= AF_PUSH_PULL) && (copy_u8Direction <= AF_PUSH_OPEN_DRAIN_DOWN))
		{
			CLR_BIT(GPIOC->MODER, copy_u8PIN * 2);
			SET_BIT(GPIOC->MODER, ((copy_u8PIN * 2) + 1));
		}
		else if ((copy_u8Direction >= INPUT_FLOATING) && (copy_u8Direction <= INPUT_PULL_DOWN))
		{
			CLR_BIT(GPIOC->MODER, copy_u8PIN * 2);
			CLR_BIT(GPIOC->MODER, ((copy_u8PIN * 2) + 1));
		}
		else if (copy_u8Direction == INPUT_ANALOG)
		{
			SET_BIT(GPIOC->MODER, copy_u8PIN * 2);
			SET_BIT(GPIOC->MODER, ((copy_u8PIN * 2) + 1));
		}
		switch (copy_u8Direction)
		{
		case OUTPUT_PUSH_PULL:
		case AF_PUSH_PULL:
		case INPUT_FLOATING:
			CLR_BIT(GPIOC->OTYPER, copy_u8PIN);
			CLR_BIT(GPIOC->PUPDR, copy_u8PIN * 2);
			CLR_BIT(GPIOC->PUPDR, ((copy_u8PIN * 2) + 1));
			break;
		case OUTPUT_PUSH_PULL_PULL_UP:
		case AF_PUSH_PULL_PULL_UP:
		case INPUT_PULL_UP:
		case INPUT_ANALOG:
			CLR_BIT(GPIOC->OTYPER, copy_u8PIN);
			SET_BIT(GPIOC->PUPDR, copy_u8PIN * 2);
			CLR_BIT(GPIOC->PUPDR, ((copy_u8PIN * 2) + 1));
			break;
		case OUTPUT_PUSH_PULL_PULL_DOWN:
		case AF_PUSH_PULL_PULL_DOWN:
		case INPUT_PULL_DOWN:
			CLR_BIT(GPIOC->OTYPER, copy_u8PIN);
			CLR_BIT(GPIOC->PUPDR, copy_u8PIN * 2);
			SET_BIT(GPIOC->PUPDR, ((copy_u8PIN * 2) + 1));
			break;
		case OUTPUT_OPEN_DRAIN:
		case AF_OPEN_DRAIN:
			SET_BIT(GPIOC->OTYPER, copy_u8PIN);
			CLR_BIT(GPIOC->PUPDR, copy_u8PIN * 2);
			CLR_BIT(GPIOC->PUPDR, ((copy_u8PIN * 2) + 1));
			break;
		case OUTPUT_PUSH_OPEN_DRAIN_UP:
		case AF_PUSH_OPEN_DRAIN_UP:
			SET_BIT(GPIOC->OTYPER, copy_u8PIN);
			SET_BIT(GPIOC->PUPDR, copy_u8PIN * 2);
			CLR_BIT(GPIOC->PUPDR, ((copy_u8PIN * 2) + 1));
			break;
		case OUTPUT_PUSH_OPEN_DRAIN_DOWN:
		case AF_PUSH_OPEN_DRAIN_DOWN:
			SET_BIT(GPIOC->OTYPER, copy_u8PIN);
			CLR_BIT(GPIOC->PUPDR, copy_u8PIN * 2);
			SET_BIT(GPIOC->PUPDR, ((copy_u8PIN * 2) + 1));
			break;
		}
		GPIOC->OSPEEDR &= ~(3 << (copy_u8PIN * 2));
		GPIOC->OSPEEDR |= (copy_u8Speed << (copy_u8PIN * 2));
		break;
	}
}

/******************************************************************************************/
/*Function: MGPIO_voidSetPinValue	                         			    			  */
/*I/P Parameters: Port - Pin - value of Pin          			  			    		  */
/*Returns:it returns no thing	                            				  			  */
/*Desc:This Function Sets the pin value to low or high				          			  */
/******************************************************************************************/
/*
 * Options for copy_u8PORT:- GPIOA_PORT - GPIOB_PORT - GPIOC_PORT
 * Options for copy_u8PIN :- PIN0 ... PIN15
 * Options for copy_u8Value :- HIGH - LOW
 */
/******************************************************************************************/
void MGPIO_voidSetPinValue(u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8Value)
{
	switch (copy_u8PORT)
	{
	case GPIOA_PORT:
		switch (copy_u8Value)
		{
		case HIGH:
			SET_BIT(GPIOA->ODR, copy_u8PIN);
			break;
		case LOW:
			CLR_BIT(GPIOA->ODR, copy_u8PIN);
			break;
		}
		break;
	case GPIOB_PORT:
		switch (copy_u8Value)
		{
		case HIGH:
			SET_BIT(GPIOB->ODR, copy_u8PIN);
			break;
		case LOW:
			CLR_BIT(GPIOB->ODR, copy_u8PIN);
			break;
		}
		break;
	case GPIOC_PORT:
		switch (copy_u8Value)
		{
		case HIGH:
			SET_BIT(GPIOC->ODR, copy_u8PIN);
			break;
		case LOW:
			CLR_BIT(GPIOC->ODR, copy_u8PIN);
			break;
		}
		break;
	}
}

/******************************************************************************************/
/*Function: MGPIO_voidSetPinValueATOMIC                      			    			  */
/*I/P Parameters: Port - Pin - value of Pin          			  			    		  */
/*Returns:it returns no thing	                            				  			  */
/*Desc:This Function Sets the pin value to low or high				          			  */
/******************************************************************************************/
/*
 * Options for copy_u8PORT:- GPIOA_PORT - GPIOB_PORT - GPIOC_PORT
 * Options for copy_u8PIN :- PIN0 ... PIN15
 * Options for copy_u8Value :- HIGH - LOW
 */
/******************************************************************************************/
void MGPIO_voidSetPinValueATOMIC(u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8Value)
{
	switch (copy_u8PORT)
	{
	case GPIOA_PORT:
		switch (copy_u8Value)
		{
		case HIGH:
			GPIOA->BSRR = (1 << copy_u8PIN);
			break;
		case LOW:
			GPIOA->BSRR = (1 << (copy_u8PIN + 16));
			break;
		}
		break;
	case GPIOB_PORT:
		switch (copy_u8Value)
		{
		case HIGH:
			GPIOB->BSRR = (1 << copy_u8PIN);
			break;
		case LOW:
			GPIOB->BSRR = (1 << (copy_u8PIN + 16));
			break;
		}
		break;
	case GPIOC_PORT:
		switch (copy_u8Value)
		{
		case HIGH:
			GPIOC->BSRR = (1 << copy_u8PIN);
			break;
		case LOW:
			GPIOC->BSRR = (1 << (copy_u8PIN + 16));
			break;
		}
		break;
	}
}

/******************************************************************************************/
/*Function: MGPIO_u8GetPinValue		                        			    			  */
/*I/P Parameters: Port - Pin 				         			  			    		  */
/*Returns:it returns value of the pin from IDR register      				  			  */
/*Desc:This Function returns the value of the pin   				          			  */
/******************************************************************************************/
/*
 * Options for copy_u8PORT:- GPIOA_PORT - GPIOB_PORT - GPIOC_PORT
 * Options for copy_u8PIN :- PIN0 ... PIN15
 */
/******************************************************************************************/
s8 MGPIO_u8GetPinValue(u8 copy_u8PORT, u8 copy_u8PIN)
{
	s8 local_u8PinValue = -1;
	switch (copy_u8PORT)
	{
	case GPIOA_PORT:
		local_u8PinValue = GET_BIT(GPIOA->IDR, copy_u8PIN);
		break;
	case GPIOB_PORT:
		local_u8PinValue = GET_BIT(GPIOB->IDR, copy_u8PIN);
		break;
	case GPIOC_PORT:
		local_u8PinValue = GET_BIT(GPIOC->IDR, copy_u8PIN);
		break;
	}
	return local_u8PinValue;
}

void MGPIO_voidSetAF(u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8AlternateFunctionNo)
{
	switch (copy_u8PORT)
	{
	case GPIOA_PORT:
		if (copy_u8PIN<8)
		{
			GPIOA->AFRL |= (copy_u8AlternateFunctionNo<<(copy_u8PIN*4));
		}
		else
		{
			GPIOA->AFRH |= (copy_u8AlternateFunctionNo<<((copy_u8PIN-8)*4));
		}
		break;
	case GPIOB_PORT:
		if (copy_u8PIN<8)
		{
			GPIOB->AFRL |= (copy_u8AlternateFunctionNo<<(copy_u8PIN*4));
		}
		else
		{
			GPIOB->AFRH |= (copy_u8AlternateFunctionNo<<((copy_u8PIN-8)*4));
		}
		break;
	case GPIOC_PORT:
		if (copy_u8PIN<8)
		{
			GPIOC->AFRL |= (copy_u8AlternateFunctionNo<<(copy_u8PIN*4));
		}
		else
		{
			GPIOC->AFRH |= (copy_u8AlternateFunctionNo<<((copy_u8PIN-8)*4));
		}
		break;
	}
}
