/*
 * MGPIO_interface.h
 *
 *  Created on: Sep 6, 2023
 *      Author: Amr-a
 */

#ifndef MGPIO_INTERFACE_H_
#define MGPIO_INTERFACE_H_



typedef enum {
	MGPIO_PORTA = 1,
	MGPIO_PORTB,
	MGPIO_PORTC,
}t_MgpioPort;

typedef enum {
ONE_PIN			= 0b1,
TWO_PINS		= 0b11,
THREE_PINS		= 0b111,
FOUR_PINS		= 0b1111,
FIVE_PINS		= 0b11111,
SIX_PINS		= 0b111111,
SEVEN_PINS		= 0b1111111,
EIGHT_PINS		= 0b11111111,
NINE_PINS		= 0b111111111,
TEN_PINS		= 0b1111111111,
TWELVE_PINS		= 0b11111111111,
ELEVEN_PINS		= 0b111111111111,
THIRTEEN_PINS	= 0b1111111111111,
FOURTEEN_PINS	= 0b11111111111111,
FIVETEEN_PINS	= 0b111111111111111,
SIXTEEN_PINS	= 0b1111111111111111,
}t_numOfPins;

typedef enum {
	MGPIO_PIN0,
	MGPIO_PIN1,
	MGPIO_PIN2,
	MGPIO_PIN3,
	MGPIO_PIN4,
	MGPIO_PIN5,
	MGPIO_PIN6,
	MGPIO_PIN7,
	MGPIO_PIN8,
	MGPIO_PIN9,
	MGPIO_PIN10,
	MGPIO_PIN11,
	MGPIO_PIN12,
	MGPIO_PIN13,
	MGPIO_PIN14,
	MGPIO_PIN15,
}t_MgpioPin;

typedef enum {
	MGPIO_Analog 						= 0b11000,
	MGPIO_InputFloating 				= 0b00000,
	MGPIO_InputPullUp 					= 0b00010,
	MGPIO_InputPullDown					= 0b00100,
	MGPIO_OutputPushPullNoPull 			= 0b01000,
	MGPIO_OutputPushPullPullUp			= 0b01001,
	MGPIO_OutputPushPullPullDown 		= 0b01010,
	MGPIO_OutputOpenDrainNoPull 		= 0b01100,
	MGPIO_OutputOpenDrainPullUp 		= 0b01101,
	MGPIO_OutputOpenDrainPullDown		= 0b01110,
	MGPIO_AlternativePushPullNoPull 	= 0b10000,
	MGPIO_AlternativePushPullPullUp		= 0b10001,
	MGPIO_AlternativePushPullPullDown	= 0b10010,
	MGPIO_AlternativeOpenDrainNoPull	= 0b10100,
	MGPIO_AlternativeOpenDrainPullUp	= 0b10101,
	MGPIO_AlternativeOpenDrainPullDown  = 0b10110,
}t_MGPIOmode;

typedef enum {
	MGPIO_LOW,
	MGPIO_HIGH
}t_MGPIOvalue;

typedef enum {
	MGPIO_LOW_SPEED,
	MGPIO_MEDIUM_SPEED,
	MGPIO_HIGH_SPEED,
	MGPIO_VERY_HIGH_SPEED
}t_MGPIOspeed;


void MGPIO_voidSetPinMode(t_MgpioPort Copy_enuPort,t_MgpioPin Copy_enuPin ,t_MGPIOmode Copy_enuMode);
void MGPIO_voidSetPinGroupMode(t_MgpioPort Copy_enuPort,t_numOfPins numOfPins,t_MgpioPin Copy_enuStartPin ,t_MGPIOmode Copy_enuMode);

void MGPIO_voidSetPinSpeed(t_MgpioPort Copy_enuPort,t_MgpioPin Copy_enuPin, t_MGPIOspeed Copy_enuSpeed);
void MGPIO_voidSetPinGroupSpeed(t_MgpioPort Copy_enuPort,t_numOfPins numOfPins,t_MgpioPin Copy_enuStartPin , t_MGPIOspeed Copy_enuSpeed);

void MGPIO_voidSetPinValue(t_MgpioPort Copy_enuPort,t_MgpioPin Copy_enuPin, t_MGPIOvalue Copy_enuValue);
void MGPIO_voidSetPinGroupValue(t_MgpioPort Copy_enuPort,t_MgpioPin Copy_enuStartPin,t_numOfPins Copy_enuNumOfPins ,t_MGPIOvalue Copy_enuValue);
void MGPIO_voidTogPinValue(t_MgpioPort Copy_enuPort,t_MgpioPin Copy_enuPin);

t_MGPIOvalue MGPIO_t_MGPIOvalue_GetPinValue(t_MgpioPort Copy_enuPort,t_MgpioPin Copy_enuPin);

#endif /* MGPIO_INTERFACE_H_ */
