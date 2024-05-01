/*
 * MGPIO_private.h
 *
 *  Created on: Sep 6, 2023
 *      Author: Amr-a
 */

#ifndef MGPIO_PRIVATE_H_
#define MGPIO_PRIVATE_H_
typedef enum {
	input,
	output,
	alternative,
	analog
}t_mode;

typedef enum {
	noPull,
	pullUp,
	pullDown,
}t_pullType;

typedef enum {
	pushPull,
	openDrain
}t_outType;

void setPinModeAsAnalog(t_MgpioPort Copy_enuPort,t_MgpioPin Copy_enuPin);

void setPinModeAsInputFloating(t_MgpioPort Copy_enuPort,t_MgpioPin Copy_enuPin);
void setPinModeAsInputPullUp(t_MgpioPort Copy_enuPort,t_MgpioPin Copy_enuPin);
void setPinModeAsInputPullDown(t_MgpioPort Copy_enuPort,t_MgpioPin Copy_enuPin);

void setPinModeAsOutputPushPullNoPull(t_MgpioPort Copy_enuPort,t_MgpioPin Copy_enuPin);
void setPinModeAsOutputPushPullPullUp(t_MgpioPort Copy_enuPort,t_MgpioPin Copy_enuPin);
void setPinModeAsOutputPushPullPullDown(t_MgpioPort Copy_enuPort,t_MgpioPin Copy_enuPin);
void setPinModeAsOutputOpenDrainNoPull(t_MgpioPort Copy_enuPort,t_MgpioPin Copy_enuPin);
void setPinModeAsOutputOpenDrainPullUp(t_MgpioPort Copy_enuPort,t_MgpioPin Copy_enuPin);
void setPinModeAsOutputOpenDrainPullDown(t_MgpioPort Copy_enuPort,t_MgpioPin Copy_enuPin);

void setPinModeAsAlternativePushPullNoPull(t_MgpioPort Copy_enuPort,t_MgpioPin Copy_enuPin);
void setPinModeAsAlternativePushPullPullUp(t_MgpioPort Copy_enuPort,t_MgpioPin Copy_enuPin);
void setPinModeAsAlternativePushPullPullDown(t_MgpioPort Copy_enuPort,t_MgpioPin Copy_enuPin);
void setPinModeAsAlternativeOpenDrainNoPull(t_MgpioPort Copy_enuPort,t_MgpioPin Copy_enuPin);
void setPinModeAsAlternativeOpenDrainPullUp(t_MgpioPort Copy_enuPort,t_MgpioPin Copy_enuPin);
void setPinModeAsAlternativeOpenDrainPullDown(t_MgpioPort Copy_enuPort,t_MgpioPin Copy_enuPin);


#endif /* MGPIO_PRIVATE_H_ */
