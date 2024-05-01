/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MGPIO_interface.h"
#include "MRCC_interface.h"

int main(void)
{
	MRCC_voidInitSystemAndBusClock();
	MRCC_voidEnablePerphClock(MRCC_AHB1, MRCC_GPIOA);
	MGPIO_voidSetPinMode(MGPIO_PORTA, MGPIO_PIN0, MGPIO_OutputPushPullNoPull);
	MGPIO_voidSetPinSpeed(MGPIO_PORTA, MGPIO_PIN0, MGPIO_LOW_SPEED);
	MGPIO_voidSetPinValue(MGPIO_PORTA, MGPIO_PIN0, MGPIO_LOW);
	MGPIO_voidSetPinValue(MGPIO_PORTA, MGPIO_PIN1, MGPIO_HIGH);
    /* Loop forever */
	for(;;);
}


