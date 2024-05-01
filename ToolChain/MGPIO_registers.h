/*
 * MGPIO_registers.h
 *
 *  Created on: Sep 6, 2023
 *      Author: Amr-a
 */

#ifndef MGPIO_REGISTERS_H_
#define MGPIO_REGISTERS_H_

#define MGPIOA_OFFSET_VALUE				(0x40020000)
#define MGPIOB_OFFSET_VALUE				(0x40020400)
#define MGPIOC_OFFSET_VALUE				(0x40020800)


#define	GPIOA_MODER			*((volatile u32*)(0x00 + MGPIOA_OFFSET_VALUE))
#define	GPIOB_MODER			*((volatile u32*)(0x00 + MGPIOB_OFFSET_VALUE))
#define GPIOC_MODER			*((volatile u32*)(0x00 + MGPIOC_OFFSET_VALUE))
#define MODER15_1				31
#define MODER15_0             30
#define MODER14_1             29
#define MODER14_0             28
#define MODER13_1             27
#define MODER13_0             26
#define MODER12_1             25
#define MODER12_0             24
#define MODER11_1             23
#define MODER11_0             22
#define MODER10_1             21
#define MODER10_0             20
#define MODER9_1              19
#define MODER9_0              18
#define MODER8_1              17
#define MODER8_0              16
#define MODER7_1              15
#define MODER7_0              14
#define MODER6_1              13
#define MODER6_0              12
#define MODER5_1              11
#define MODER5_0            	10
#define MODER4_1              9
#define MODER4_0              8
#define MODER3_1              7
#define MODER3_0              6
#define MODER2_1              5
#define MODER2_0              4
#define MODER1_1              3
#define MODER1_0              2
#define MODER0_1              1
#define MODER0_0              0


/*	coul16 	*/
#define GPIOA_OTYPER			*((volatile u32*)(0x04 + MGPIOA_OFFSET_VALUE))
#define GPIOB_OTYPER          *((volatile u32*)(0x04 + MGPIOB_OFFSET_VALUE))
#define GPIOC_OTYPER          *((volatile u32*)(0x04 + MGPIOC_OFFSET_VALUE))
#define OT15					15
#define OT14        			14
#define OT13		        	13
#define OT12       		 	12
#define OT11			        11
#define OT10      			10
#define OT9			         9
#define OT8			         8
#define OT7			         7
#define OT6			         6
#define OT5			         5
#define OT4			         4
#define OT3			         3
#define OT2			         2
#define OT1			         1
#define OT0			         0


#define GPIOA_OSPEEDR        	*((volatile u32*)(0x08 + MGPIOA_OFFSET_VALUE))
#define GPIOB_OSPEEDR        	*((volatile u32*)(0x08 + MGPIOB_OFFSET_VALUE))
#define GPIOC_OSPEEDR        	*((volatile u32*)(0x08 + MGPIOC_OFFSET_VALUE))
#define OSPEEDR15_1           31
#define OSPEEDR15_0           30
#define OSPEEDR14_1           29
#define OSPEEDR14_0           28
#define OSPEEDR13_1           27
#define OSPEEDR13_0           26
#define OSPEEDR12_1           25
#define OSPEEDR12_0           24
#define OSPEEDR11_1           23
#define OSPEEDR11_0           22
#define OSPEEDR10_1           21
#define OSPEEDR10_0           20
#define OSPEEDR9_1            19
#define OSPEEDR9_0            18
#define OSPEEDR8_1            17
#define OSPEEDR8_0            16
#define OSPEEDR7_1            15
#define OSPEEDR7_0            14
#define OSPEEDR6_1            13
#define OSPEEDR6_0            12
#define OSPEEDR5_1            11
#define OSPEEDR5_0            10
#define OSPEEDR4_1            9
#define OSPEEDR4_0            8
#define OSPEEDR3_1            7
#define OSPEEDR3_0            6
#define OSPEEDR2_1            5
#define OSPEEDR2_0            4
#define OSPEEDR1_1            3
#define OSPEEDR1_0            2
#define OSPEEDR0_1            1
#define OSPEEDR0_0            0


#define GPIOA_PUPDR			*((volatile u32*)(0x0C + MGPIOA_OFFSET_VALUE))
#define GPIOB_PUPDR			*((volatile u32*)(0x0C + MGPIOB_OFFSET_VALUE))
#define GPIOC_PUPDR			*((volatile u32*)(0x0C + MGPIOC_OFFSET_VALUE))


#define GPIOA_IDR			   *((volatile u32*)(0x10 + MGPIOA_OFFSET_VALUE))
#define GPIOB_IDR            *((volatile u32*)(0x10 + MGPIOB_OFFSET_VALUE))
#define GPIOC_IDR            *((volatile u32*)(0x10 + MGPIOC_OFFSET_VALUE))


#define GPIOA_ODR				*((volatile u32*)(0x14 + MGPIOA_OFFSET_VALUE))
#define GPIOB_ODR             *((volatile u32*)(0x14 + MGPIOB_OFFSET_VALUE))
#define GPIOC_ODR             *((volatile u32*)(0x14 + MGPIOC_OFFSET_VALUE))

#define GPIOA_BSRR			*((volatile u32*)(0x18 + MGPIOA_OFFSET_VALUE))
#define GPIOB_BSRR            *((volatile u32*)(0x18 + MGPIOB_OFFSET_VALUE))
#define GPIOC_BSRR            *((volatile u32*)(0x18 + MGPIOC_OFFSET_VALUE))

#define GPIOA_LCKR			*((volatile u32*)(0x1C + MGPIOA_OFFSET_VALUE))
#define GPIOB_LCKR            *((volatile u32*)(0x1C + MGPIOB_OFFSET_VALUE))
#define GPIOC_LCKR            *((volatile u32*)(0x1C + MGPIOC_OFFSET_VALUE))

#define GPIOA_AFRL			*((volatile u32*)(0x20 + MGPIOA_OFFSET_VALUE))
#define GPIOB_AFRL            *((volatile u32*)(0x20 + MGPIOB_OFFSET_VALUE))
#define GPIOC_AFRL            *((volatile u32*)(0x20 + MGPIOC_OFFSET_VALUE))

#define GPIOA_AFRH			*((volatile u32*)(0x24 + MGPIOA_OFFSET_VALUE))
#define GPIOB_AFRH            *((volatile u32*)(0x24 + MGPIOB_OFFSET_VALUE))
#define GPIOC_AFRH            *((volatile u32*)(0x24 + MGPIOC_OFFSET_VALUE))

#endif /* MGPIO_REGISTERS_H_ */
