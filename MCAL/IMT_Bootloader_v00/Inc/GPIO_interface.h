/*
 * GPIO_interface.h
 *
 *  Created on: Jul 23, 2022
 *      Author: abdelrahmanhossam
 */

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7
#define PIN8 8
#define PIN9 9
#define PIN10 10
#define PIN11 11
#define PIN12 12
#define PIN13 13
#define PIN14 14
#define PIN15 15

#define GPIOA_PORT 0
#define GPIOB_PORT 1
#define GPIOC_PORT 2

#define AF_UART		7

#define LOW_SPEED 0
#define MEDIUM_SPEED 1
#define HIGH_SPEED 2
#define VERY_HIGH_SPEED 3

#define INPUT_FLOATING 1
#define INPUT_PULL_UP 2
#define INPUT_PULL_DOWN 3
#define INPUT_ANALOG 4

#define OUTPUT_PUSH_PULL 5
#define OUTPUT_PUSH_PULL_PULL_UP 6
#define OUTPUT_PUSH_PULL_PULL_DOWN 7

#define OUTPUT_OPEN_DRAIN 8
#define OUTPUT_PUSH_OPEN_DRAIN_UP 9
#define OUTPUT_PUSH_OPEN_DRAIN_DOWN 10

#define AF_PUSH_PULL 11
#define AF_PUSH_PULL_PULL_UP 12
#define AF_PUSH_PULL_PULL_DOWN 13

#define AF_OPEN_DRAIN 14
#define AF_PUSH_OPEN_DRAIN_UP 15
#define AF_PUSH_OPEN_DRAIN_DOWN 16

#define HIGH 1
#define LOW 0

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
void MGPIO_voidSetPinDirection(u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8Direction, u8 copy_u8Speed);

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
void MGPIO_voidSetPinValue(u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8Value);

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
void MGPIO_voidSetPinValueATOMIC(u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8Value);

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
s8 MGPIO_u8GetPinValue(u8 copy_u8PORT, u8 copy_u8PIN);

void MGPIO_voidSetAF(u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8AlternateFunctionNo);
#endif /* GPIO_INTERFACE_H_ */
