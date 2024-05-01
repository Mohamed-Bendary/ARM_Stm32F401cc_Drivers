/*
 * MGPIO_program.c
 *
 *  Created on: Sep 6, 2023
 *      Author: Amr-a
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MGPIO_interface.h"
#include "MGPIO_registers.h"
#include "MGPIO_config.h"
#include "MGPIO_private.h"

void MGPIO_voidSetPinMode(t_MgpioPort Copy_enuPort,t_MgpioPin Copy_enuPin ,t_MGPIOmode Copy_enuMode){
	switch (Copy_enuMode) {
	case MGPIO_Analog						: setPinModeAsAnalog(Copy_enuPort, Copy_enuPin); break;

	case MGPIO_InputFloating				: setPinModeAsInputFloating(Copy_enuPort, Copy_enuPin); break;
	case MGPIO_InputPullUp					: setPinModeAsInputPullUp(Copy_enuPort, Copy_enuPin); break;
	case MGPIO_InputPullDown				: setPinModeAsInputPullDown(Copy_enuPort, Copy_enuPin); break;

	case MGPIO_OutputPushPullNoPull			: setPinModeAsOutputPushPullNoPull(Copy_enuPort, Copy_enuPin); break;
	case MGPIO_OutputPushPullPullUp			: setPinModeAsOutputPushPullPullUp(Copy_enuPort, Copy_enuPin); break;
	case MGPIO_OutputPushPullPullDown		: setPinModeAsOutputPushPullPullDown(Copy_enuPort, Copy_enuPin); break;
	case MGPIO_OutputOpenDrainNoPull		: setPinModeAsOutputOpenDrainNoPull(Copy_enuPort, Copy_enuPin); break;
	case MGPIO_OutputOpenDrainPullUp		: setPinModeAsOutputOpenDrainPullUp(Copy_enuPort, Copy_enuPin); break;
	case MGPIO_OutputOpenDrainPullDown		: setPinModeAsOutputOpenDrainPullDown(Copy_enuPort, Copy_enuPin); break;

	case MGPIO_AlternativePushPullNoPull	: setPinModeAsAlternativePushPullNoPull(Copy_enuPort, Copy_enuPin); break;
	case MGPIO_AlternativePushPullPullUp	: setPinModeAsAlternativePushPullPullUp(Copy_enuPort, Copy_enuPin); break;
	case MGPIO_AlternativePushPullPullDown	: setPinModeAsAlternativePushPullPullDown(Copy_enuPort, Copy_enuPin); break;
	case MGPIO_AlternativeOpenDrainNoPull	: setPinModeAsAlternativeOpenDrainNoPull(Copy_enuPort, Copy_enuPin); break;
	case MGPIO_AlternativeOpenDrainPullUp	: setPinModeAsAlternativeOpenDrainPullUp(Copy_enuPort, Copy_enuPin); break;
	case MGPIO_AlternativeOpenDrainPullDown	: setPinModeAsAlternativeOpenDrainPullDown(Copy_enuPort, Copy_enuPin); break;
	default:
		break;
	}
}

void MGPIO_voidSetPinGroupMode(t_MgpioPort Copy_enuPort,t_numOfPins numOfPins,t_MgpioPin Copy_enuStartPin ,t_MGPIOmode Copy_enuMode){
	u8 tempPinIndex = 0;
	for (; numOfPins > 0 ; numOfPins = numOfPins>>1 ) {
		MGPIO_voidSetPinMode(Copy_enuPort, Copy_enuStartPin + tempPinIndex,Copy_enuMode );
		tempPinIndex++;
	}
}

void MGPIO_voidSetPinSpeed(t_MgpioPort Copy_enuPort,t_MgpioPin Copy_enuPin, t_MGPIOspeed Copy_enuSpeed){
	switch (Copy_enuPort){
	case MGPIO_PORTA : WRITE_BITS(GPIOA_OSPEEDR,(OSPEEDR0_0+Copy_enuPin)*2,Copy_enuSpeed,TWO_BITS);
	case MGPIO_PORTB : WRITE_BITS(GPIOB_OSPEEDR,(OSPEEDR0_0+Copy_enuPin)*2,Copy_enuSpeed,TWO_BITS);
	case MGPIO_PORTC : WRITE_BITS(GPIOC_OSPEEDR,(OSPEEDR0_0+Copy_enuPin)*2,Copy_enuSpeed,TWO_BITS);
	default: break;
	}
}
void MGPIO_voidSetPinGroupSpeed(t_MgpioPort Copy_enuPort,t_numOfPins numOfPins,t_MgpioPin Copy_enuStartPin , t_MGPIOspeed Copy_enuSpeed){
	u8 tempPinIndex = 0;
		for (; numOfPins > 0 ; numOfPins = numOfPins>>1 ) {
			MGPIO_voidSetPinSpeed(Copy_enuPort, Copy_enuStartPin + tempPinIndex,Copy_enuSpeed );
			tempPinIndex++;
		}
}


void MGPIO_voidSetPinValue(t_MgpioPort Copy_enuPort,t_MgpioPin Copy_enuPin, t_MGPIOvalue Copy_enuValue){
	switch (Copy_enuPort) {
	case MGPIO_PORTA: WRITE_BITS(GPIOA_ODR,Copy_enuPin,Copy_enuValue,ONE_BIT);break;
	case MGPIO_PORTB: WRITE_BITS(GPIOB_ODR,Copy_enuPin,Copy_enuValue,ONE_BIT);break;
	case MGPIO_PORTC: WRITE_BITS(GPIOC_ODR,Copy_enuPin,Copy_enuValue,ONE_BIT);break;
		default:break;
	}
}
void MGPIO_voidTogPinValue(t_MgpioPort Copy_enuPort,t_MgpioPin Copy_enuPin){
	switch (Copy_enuPort) {
		case MGPIO_PORTA: TOGGLE_BIT(GPIOA_ODR,Copy_enuPin);break;
		case MGPIO_PORTB: TOGGLE_BIT(GPIOB_ODR,Copy_enuPin);break;
		case MGPIO_PORTC: TOGGLE_BIT(GPIOC_ODR,Copy_enuPin);break;
			default:break;
		}
}
t_MGPIOvalue MGPIO_t_MGPIOvalue_GetPinValue(t_MgpioPort Copy_enuPort,t_MgpioPin Copy_enuPin){
	t_MGPIOvalue value =  MGPIO_LOW ;
	switch (Copy_enuPort) {
		case MGPIO_PORTA: value = (GET_BIT(GPIOA_IDR,Copy_enuPin));break;
		case MGPIO_PORTB: value = (GET_BIT(GPIOB_IDR,Copy_enuPin));break;
		case MGPIO_PORTC: value = (GET_BIT(GPIOC_IDR,Copy_enuPin));break;
			default:break;
		}
	return value;
}

void MGPIO_voidSetPinGroupValue(t_MgpioPort Copy_enuPort,t_MgpioPin Copy_enuStartPin,t_numOfPins Copy_enuNumOfBits ,t_MGPIOvalue Copy_enuValue){
	switch (Copy_enuPort) {
		case MGPIO_PORTA: WRITE_BITS(GPIOA_ODR,Copy_enuStartPin,Copy_enuValue,Copy_enuNumOfBits);break;
		case MGPIO_PORTB: WRITE_BITS(GPIOB_ODR,Copy_enuStartPin,Copy_enuValue,Copy_enuNumOfBits);break;
		case MGPIO_PORTC: WRITE_BITS(GPIOC_ODR,Copy_enuStartPin,Copy_enuValue,Copy_enuNumOfBits);break;
			default:break;
		}
}


void setPinModeAsAnalog(t_MgpioPort Copy_enuPort,t_MgpioPin Copy_enuPin){
	switch (Copy_enuPort){
	case MGPIO_PORTA: WRITE_BITS(GPIOA_MODER,Copy_enuPin*2,analog,TWO_BITS);break;
	case MGPIO_PORTB: WRITE_BITS(GPIOB_MODER,Copy_enuPin*2,analog,TWO_BITS);break;
	case MGPIO_PORTC: WRITE_BITS(GPIOC_MODER,Copy_enuPin*2,analog,TWO_BITS);break;
	default: break;
	}
}

void setPinModeAsInputFloating(t_MgpioPort Copy_enuPort,t_MgpioPin Copy_enuPin){
	switch (Copy_enuPort){
	case MGPIO_PORTA:
		WRITE_BITS(GPIOA_MODER,Copy_enuPin*2,input,TWO_BITS);
		WRITE_BITS(GPIOA_PUPDR,Copy_enuPin*2,noPull,TWO_BITS);
		break;
	case MGPIO_PORTB:
		WRITE_BITS(GPIOB_MODER,Copy_enuPin*2,input,TWO_BITS);
		WRITE_BITS(GPIOB_PUPDR,Copy_enuPin*2,noPull,TWO_BITS);

		break;
	case MGPIO_PORTC:
		WRITE_BITS(GPIOC_MODER,Copy_enuPin*2,input,TWO_BITS);
		WRITE_BITS(GPIOC_PUPDR,Copy_enuPin*2,noPull,TWO_BITS);

		break;
	default: break;
	}
}

void setPinModeAsInputPullUp(t_MgpioPort Copy_enuPort,t_MgpioPin Copy_enuPin){
	switch (Copy_enuPort){
	case MGPIO_PORTA:
		WRITE_BITS(GPIOA_MODER,Copy_enuPin*2,input,TWO_BITS);
		WRITE_BITS(GPIOA_PUPDR,Copy_enuPin*2,pullUp,TWO_BITS);
		break;
	case MGPIO_PORTB:
		WRITE_BITS(GPIOB_MODER,Copy_enuPin*2,input>>3,TWO_BITS);
		WRITE_BITS(GPIOB_PUPDR,Copy_enuPin*2,pullUp>>1,TWO_BITS);

		break;
	case MGPIO_PORTC:
		WRITE_BITS(GPIOC_MODER,Copy_enuPin*2,input>>3,TWO_BITS);
		WRITE_BITS(GPIOC_PUPDR,Copy_enuPin*2,pullUp>>1,TWO_BITS);

		break;
	default: break;
	}
}
void setPinModeAsInputPullDown(t_MgpioPort Copy_enuPort,t_MgpioPin Copy_enuPin){
	switch (Copy_enuPort){
	case MGPIO_PORTA:
		WRITE_BITS(GPIOA_MODER,Copy_enuPin*2,input,TWO_BITS);
		WRITE_BITS(GPIOA_PUPDR,Copy_enuPin*2,pullDown,TWO_BITS);
		break;
	case MGPIO_PORTB:
		WRITE_BITS(GPIOB_MODER,Copy_enuPin*2,input,TWO_BITS);
		WRITE_BITS(GPIOB_PUPDR,Copy_enuPin*2,pullDown,TWO_BITS);
		break;
	case MGPIO_PORTC:
		WRITE_BITS(GPIOC_MODER,Copy_enuPin*2,input,TWO_BITS);
		WRITE_BITS(GPIOC_PUPDR,Copy_enuPin*2,pullDown,TWO_BITS);
		break;
	default: break;
	}
}
void setPinModeAsOutputPushPullNoPull(t_MgpioPort Copy_enuPort,t_MgpioPin Copy_enuPin){
	switch (Copy_enuPort){
	case MGPIO_PORTA:
		WRITE_BITS(GPIOA_MODER,Copy_enuPin*2,output,TWO_BITS);
		CLR_BIT(GPIOA_OTYPER,Copy_enuPin);
		WRITE_BITS(GPIOA_PUPDR,Copy_enuPin*2,noPull,TWO_BITS);
		break;
	case MGPIO_PORTB:
		WRITE_BITS(GPIOB_MODER,Copy_enuPin*2,output,TWO_BITS);
		CLR_BIT(GPIOB_OTYPER,Copy_enuPin);
		WRITE_BITS(GPIOB_PUPDR,Copy_enuPin*2,noPull,TWO_BITS);
		break;
	case MGPIO_PORTC:
		WRITE_BITS(GPIOC_MODER,Copy_enuPin*2,output,TWO_BITS);
		CLR_BIT(GPIOB_OTYPER,Copy_enuPin);
		WRITE_BITS(GPIOC_PUPDR,Copy_enuPin*2,noPull,TWO_BITS);
		break;
	default: break;
	}
}

void setPinModeAsOutputPushPullPullUp(t_MgpioPort Copy_enuPort,t_MgpioPin Copy_enuPin){
	switch (Copy_enuPort){
	case MGPIO_PORTA:
		WRITE_BITS(GPIOA_MODER,Copy_enuPin*2,output,TWO_BITS);
		CLR_BIT(GPIOA_OTYPER,Copy_enuPin);
		WRITE_BITS(GPIOA_PUPDR,Copy_enuPin*2,pullUp,TWO_BITS);
		break;
	case MGPIO_PORTB:
		WRITE_BITS(GPIOB_MODER,Copy_enuPin*2,output,TWO_BITS);
		CLR_BIT(GPIOB_OTYPER,Copy_enuPin);
		WRITE_BITS(GPIOB_PUPDR,Copy_enuPin*2,pullUp,TWO_BITS);

		break;
	case MGPIO_PORTC:
		WRITE_BITS(GPIOC_MODER,Copy_enuPin*2,output,TWO_BITS);
		CLR_BIT(GPIOB_OTYPER,Copy_enuPin);
		WRITE_BITS(GPIOC_PUPDR,Copy_enuPin*2,pullUp,TWO_BITS);
		break;
	default: break;
	}
}
void setPinModeAsOutputPushPullPullDown(t_MgpioPort Copy_enuPort,t_MgpioPin Copy_enuPin){
	switch (Copy_enuPort){
	case MGPIO_PORTA:
		WRITE_BITS(GPIOA_MODER,Copy_enuPin*2,output,TWO_BITS);
		CLR_BIT(GPIOA_OTYPER,Copy_enuPin);
		WRITE_BITS(GPIOA_PUPDR,Copy_enuPin*2,pullDown,TWO_BITS);
		break;
	case MGPIO_PORTB:
		WRITE_BITS(GPIOB_MODER,Copy_enuPin*2,output,TWO_BITS);
		CLR_BIT(GPIOB_OTYPER,Copy_enuPin);
		WRITE_BITS(GPIOB_PUPDR,Copy_enuPin*2,pullDown,TWO_BITS);

		break;
	case MGPIO_PORTC:
		WRITE_BITS(GPIOC_MODER,Copy_enuPin*2,output,TWO_BITS);
		CLR_BIT(GPIOB_OTYPER,Copy_enuPin);
		WRITE_BITS(GPIOC_PUPDR,Copy_enuPin*2,pullDown,TWO_BITS);
		break;
	default: break;
	}
}
void setPinModeAsOutputOpenDrainNoPull(t_MgpioPort Copy_enuPort,t_MgpioPin Copy_enuPin){
	switch (Copy_enuPort){
	case MGPIO_PORTA:
		WRITE_BITS(GPIOA_MODER,Copy_enuPin*2,output,TWO_BITS);
		SET_BIT(GPIOA_OTYPER,Copy_enuPin);
		WRITE_BITS(GPIOA_PUPDR,Copy_enuPin*2,noPull,TWO_BITS);
		break;
	case MGPIO_PORTB:
		WRITE_BITS(GPIOB_MODER,Copy_enuPin*2,output,TWO_BITS);
		SET_BIT(GPIOB_OTYPER,Copy_enuPin);
		WRITE_BITS(GPIOB_PUPDR,Copy_enuPin*2,noPull,TWO_BITS);

		break;
	case MGPIO_PORTC:
		WRITE_BITS(GPIOC_MODER,Copy_enuPin*2,output,TWO_BITS);
		SET_BIT(GPIOB_OTYPER,Copy_enuPin);
		WRITE_BITS(GPIOC_PUPDR,Copy_enuPin*2,noPull,TWO_BITS);
		break;
	default: break;
	}
}

void setPinModeAsOutputOpenDrainPullUp(t_MgpioPort Copy_enuPort,t_MgpioPin Copy_enuPin){
	switch (Copy_enuPort){
	case MGPIO_PORTA:
		WRITE_BITS(GPIOA_MODER,Copy_enuPin*2,output,TWO_BITS);
		SET_BIT(GPIOA_OTYPER,Copy_enuPin);
		WRITE_BITS(GPIOA_PUPDR,Copy_enuPin*2,pullUp,TWO_BITS);
		break;
	case MGPIO_PORTB:
		WRITE_BITS(GPIOB_MODER,Copy_enuPin*2,output,TWO_BITS);
		SET_BIT(GPIOB_OTYPER,Copy_enuPin);
		WRITE_BITS(GPIOB_PUPDR,Copy_enuPin*2,pullUp,TWO_BITS);

		break;
	case MGPIO_PORTC:
		WRITE_BITS(GPIOC_MODER,Copy_enuPin*2,output,TWO_BITS);
		SET_BIT(GPIOB_OTYPER,Copy_enuPin);
		WRITE_BITS(GPIOC_PUPDR,Copy_enuPin*2,pullUp,TWO_BITS);
		break;
	default: break;
	}
}

void setPinModeAsOutputOpenDrainPullDown(t_MgpioPort Copy_enuPort,t_MgpioPin Copy_enuPin){
	switch (Copy_enuPort){
	case MGPIO_PORTA:
		WRITE_BITS(GPIOA_MODER,Copy_enuPin*2,output,TWO_BITS);
		SET_BIT(GPIOA_OTYPER,Copy_enuPin);
		WRITE_BITS(GPIOA_PUPDR,Copy_enuPin*2,pullDown,TWO_BITS);
		break;
	case MGPIO_PORTB:
		WRITE_BITS(GPIOB_MODER,Copy_enuPin*2,output,TWO_BITS);
		SET_BIT(GPIOB_OTYPER,Copy_enuPin);
		WRITE_BITS(GPIOB_PUPDR,Copy_enuPin*2,pullDown,TWO_BITS);

		break;
	case MGPIO_PORTC:
		WRITE_BITS(GPIOC_MODER,Copy_enuPin*2,output,TWO_BITS);
		SET_BIT(GPIOB_OTYPER,Copy_enuPin);
		WRITE_BITS(GPIOC_PUPDR,Copy_enuPin*2,pullDown,TWO_BITS);
		break;
	default: break;
	}
}
void setPinModeAsAlternativePushPullNoPull(t_MgpioPort Copy_enuPort,t_MgpioPin Copy_enuPin){
	switch (Copy_enuPort){
	case MGPIO_PORTA:
		WRITE_BITS(GPIOA_MODER,Copy_enuPin*2,alternative,TWO_BITS);
		CLR_BIT(GPIOA_OTYPER,Copy_enuPin);
		WRITE_BITS(GPIOA_PUPDR,Copy_enuPin*2,noPull,TWO_BITS);
		break;
	case MGPIO_PORTB:
		WRITE_BITS(GPIOB_MODER,Copy_enuPin*2,alternative,TWO_BITS);
		CLR_BIT(GPIOB_OTYPER,Copy_enuPin);
		WRITE_BITS(GPIOB_PUPDR,Copy_enuPin*2,noPull,TWO_BITS);

		break;
	case MGPIO_PORTC:
		WRITE_BITS(GPIOC_MODER,Copy_enuPin*2,alternative,TWO_BITS);
		CLR_BIT(GPIOB_OTYPER,Copy_enuPin);
		WRITE_BITS(GPIOC_PUPDR,Copy_enuPin*2,noPull,TWO_BITS);
		break;
	default: break;
	}
}
void setPinModeAsAlternativePushPullPullUp(t_MgpioPort Copy_enuPort,t_MgpioPin Copy_enuPin){
	switch (Copy_enuPort){
	case MGPIO_PORTA:
		WRITE_BITS(GPIOA_MODER,Copy_enuPin*2,alternative,TWO_BITS);
		CLR_BIT(GPIOA_OTYPER,Copy_enuPin);
		WRITE_BITS(GPIOA_PUPDR,Copy_enuPin*2,pullUp,TWO_BITS);
		break;
	case MGPIO_PORTB:
		WRITE_BITS(GPIOB_MODER,Copy_enuPin*2,alternative,TWO_BITS);
		CLR_BIT(GPIOB_OTYPER,Copy_enuPin);
		WRITE_BITS(GPIOB_PUPDR,Copy_enuPin*2,pullUp,TWO_BITS);

		break;
	case MGPIO_PORTC:
		WRITE_BITS(GPIOC_MODER,Copy_enuPin*2,alternative,TWO_BITS);
		CLR_BIT(GPIOB_OTYPER,Copy_enuPin);
		WRITE_BITS(GPIOC_PUPDR,Copy_enuPin*2,pullUp,TWO_BITS);
		break;
	default: break;
	}
}
void setPinModeAsAlternativePushPullPullDown(t_MgpioPort Copy_enuPort,t_MgpioPin Copy_enuPin){
	switch (Copy_enuPort){
	case MGPIO_PORTA:
		WRITE_BITS(GPIOA_MODER,Copy_enuPin*2,alternative,TWO_BITS);
		CLR_BIT(GPIOA_OTYPER,Copy_enuPin);
		WRITE_BITS(GPIOA_PUPDR,Copy_enuPin*2,pullDown,TWO_BITS);
		break;
	case MGPIO_PORTB:
		WRITE_BITS(GPIOB_MODER,Copy_enuPin*2,alternative,TWO_BITS);
		CLR_BIT(GPIOB_OTYPER,Copy_enuPin);
		WRITE_BITS(GPIOB_PUPDR,Copy_enuPin*2,pullDown,TWO_BITS);

		break;
	case MGPIO_PORTC:
		WRITE_BITS(GPIOC_MODER,Copy_enuPin*2,alternative,TWO_BITS);
		CLR_BIT(GPIOB_OTYPER,Copy_enuPin);
		WRITE_BITS(GPIOC_PUPDR,Copy_enuPin*2,pullDown,TWO_BITS);
		break;
	default: break;
	}
}
void setPinModeAsAlternativeOpenDrainNoPull(t_MgpioPort Copy_enuPort,t_MgpioPin Copy_enuPin){
	switch (Copy_enuPort){
	case MGPIO_PORTA:
		WRITE_BITS(GPIOA_MODER,Copy_enuPin*2,alternative,TWO_BITS);
		SET_BIT(GPIOA_OTYPER,Copy_enuPin);
		WRITE_BITS(GPIOA_PUPDR,Copy_enuPin*2,noPull,TWO_BITS);
		break;
	case MGPIO_PORTB:
		WRITE_BITS(GPIOB_MODER,Copy_enuPin*2,alternative,TWO_BITS);
		SET_BIT(GPIOB_OTYPER,Copy_enuPin);
		WRITE_BITS(GPIOB_PUPDR,Copy_enuPin*2,noPull,TWO_BITS);

		break;
	case MGPIO_PORTC:
		WRITE_BITS(GPIOC_MODER,Copy_enuPin*2,alternative,TWO_BITS);
		SET_BIT(GPIOB_OTYPER,Copy_enuPin);
		WRITE_BITS(GPIOC_PUPDR,Copy_enuPin*2,noPull,TWO_BITS);
		break;
	default: break;
	}
}
void setPinModeAsAlternativeOpenDrainPullUp(t_MgpioPort Copy_enuPort,t_MgpioPin Copy_enuPin){
	switch (Copy_enuPort){
	case MGPIO_PORTA:
		WRITE_BITS(GPIOA_MODER,Copy_enuPin*2,alternative,TWO_BITS);
		SET_BIT(GPIOA_OTYPER,Copy_enuPin);
		WRITE_BITS(GPIOA_PUPDR,Copy_enuPin*2,pullUp,TWO_BITS);
		break;
	case MGPIO_PORTB:
		WRITE_BITS(GPIOB_MODER,Copy_enuPin*2,alternative,TWO_BITS);
		SET_BIT(GPIOB_OTYPER,Copy_enuPin);
		WRITE_BITS(GPIOB_PUPDR,Copy_enuPin*2,pullUp,TWO_BITS);
		break;
	case MGPIO_PORTC:
		WRITE_BITS(GPIOC_MODER,Copy_enuPin*2,alternative,TWO_BITS);
		SET_BIT(GPIOB_OTYPER,Copy_enuPin);
		WRITE_BITS(GPIOC_PUPDR,Copy_enuPin*2,pullUp,TWO_BITS);
		break;
	default: break;
	}
}
void setPinModeAsAlternativeOpenDrainPullDown(t_MgpioPort Copy_enuPort,t_MgpioPin Copy_enuPin){
	switch (Copy_enuPort){
	case MGPIO_PORTA:
		WRITE_BITS(GPIOA_MODER,Copy_enuPin*2,alternative,TWO_BITS);
		SET_BIT(GPIOA_OTYPER,Copy_enuPin);
		WRITE_BITS(GPIOA_PUPDR,Copy_enuPin*2,pullDown,TWO_BITS);
		break;
	case MGPIO_PORTB:
		WRITE_BITS(GPIOB_MODER,Copy_enuPin*2,alternative,TWO_BITS);
		SET_BIT(GPIOB_OTYPER,Copy_enuPin);
		WRITE_BITS(GPIOB_PUPDR,Copy_enuPin*2,pullDown,TWO_BITS);
		break;
	case MGPIO_PORTC:
		WRITE_BITS(GPIOC_MODER,Copy_enuPin*2,alternative,TWO_BITS);
		SET_BIT(GPIOB_OTYPER,Copy_enuPin);
		WRITE_BITS(GPIOC_PUPDR,Copy_enuPin*2,pullDown,TWO_BITS);
		break;
	default: break;
	}
}
