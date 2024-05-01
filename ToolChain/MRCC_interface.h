/*
 * MRCC_interface.h
 *
 *  Created on: Sep 6, 2023
 *      Author: Amr-a
 */

#ifndef MRCC_INTERFACE_H_
#define MRCC_INTERFACE_H_

/* each peripheral should have the right value inside bus enable reg*/
typedef enum {
	MRCC_GPIOA 		= 0,
	MRCC_GPIOB 		= 1,
	MRCC_GPIOC 		= 2,
	MRCCD_MA2EN 	= 22,
	MRCCD_MA1EN 	= 21,
	MRCCC_RCEN  	= 12,
	MRCCC_PWREN 	= 28,
	MRCCC_I2C3EN 	= 23,
	MRCCC_I2C2EN 	= 22,
	MRCCC_I2C1EN 	= 21,
	MRCCC_USART2EN 	= 17,
	MRCCC_SPI3EN 	= 15,
	MRCCC_SPI2EN 	= 14,
	MRCCC_WWDGEN 	= 11,
	MRCCC_TIM5EN 	= 3,
	MRCCC_TIM4EN 	= 2,
	MRCCC_TIM3EN 	= 1,
	MRCCC_TIM2EN 	= 0,
	MRCCC_TIM11EN 	= 18,
	MRCCC_TIM10EN 	= 17,
	MRCCC_TIM9EN 	= 16,
	MRCCC_SYSCFGEN 	= 14,
	MRCCC_SPI4EN 	= 13,
	MRCCC_SPI1EN 	= 12,
	MRCCC_SDIOEN 	= 11,
	MRCCC_ADC1EN 	= 8,
	MRCCC_USART6EN 	= 5,
	MRCCC_USART1EN 	= 4,
	MRCCC_TIM1EN 	= 0,
}t_RccPeripheral;

typedef enum {
	MRCC_AHB1,
	MRCC_AHB2,
	MRCC_APB1,
	MRCC_APB2

}t_RccBus;

/*	API's functions prototypes that user want*/
/*	error state 	*/

void MRCC_voidInitSystemAndBusClock();

void MRCC_voidEnablePerphClock(t_RccBus Copy_enuBus ,t_RccPeripheral Copy_enuPerphiralID);
void MRCC_voidDisablePerphClock(t_RccBus Copy_enuBus ,t_RccPeripheral Copy_enuPerphiralID);



#endif /* MRCC_INTERFACE_H_ */
