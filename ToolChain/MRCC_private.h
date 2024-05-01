/*
 * MRCC_private.h
 *
 *  Created on: Sep 6, 2023
 *      Author: Amr-a
 */

#ifndef MRCC_PRIVATE_H_
#define MRCC_PRIVATE_H_
//system clock source type
#define HSI_CLK_SOURCE						(1)
#define HSE_CRYSTAL_CLK_SOURCE     			(2)
#define HSE_USER_CLK_SOURCE        			(3)
#define PLL_HSI_CLK_SOURCE        	 		(4)
#define PLL_HSE_USER_CLK_SOURCE    			(5)
#define PLL_HSE_CRYSTAL_CLK_SOURCE 			(6)


/*	SW value
 * HSI
 * HSE
 * PLL
 * */
#define SWITCH_HSI 		0
#define SWITCH_HSE		1
#define SWITCH_PLL		2

/*	AHB division factor*/
#define SYSTEM_CLOCK_NOT_DIVIDED   			(0b0000)
#define SYSTEM_CLOCK_DIVIDED_BY_2  			(0b1000)
#define SYSTEM_CLOCK_DIVIDED_BY_4  			(0b1001)
#define SYSTEM_CLOCK_DIVIDED_BY_8  			(0b1010)
#define SYSTEM_CLOCK_DIVIDED_BY_16 			(0b1011)
#define SYSTEM_CLOCK_DIVIDED_BY_64 			(0b1100)
#define SYSTEM_CLOCK_DIVIDED_BY_128			(0b1101)
#define SYSTEM_CLOCK_DIVIDED_BY_256			(0b1110)
#define SYSTEM_CLOCK_DIVIDED_BY_512			(0b1111)

/*APB buses division factor */
#define AHB_CLOCK_NOT_DIVIDED               (0b000)
#define AHB_CLOCK_DIVIDED_BY_2              (0b100)
#define AHB_CLOCK_DIVIDED_BY_4              (0b101)
#define AHB_CLOCK_DIVIDED_BY_8              (0b110)
#define AHB_CLOCK_DIVIDED_BY_16             (0b111)

/*implementation specific */

#define CLK_NOT_READY						(0)

void voidSetBusesClock();
void voidEnableHSI_CLK();
void voidEnableHSE_Crystal_CLK();
void voidEnableHSE_User_CLK();
void voidEnablePLL_HSI_CLK();
void voidEnablePLL_HSE_Crystal_CLK();
void voidEnablePLL_HSE_User_CLK();

#endif /* MRCC_PRIVATE_H_ */
