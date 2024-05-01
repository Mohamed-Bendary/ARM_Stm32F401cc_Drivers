/*
 * GPIO_private.h
 *
 *  Created on: Jul 23, 2022
 *      Author: abdelrahmanhossam
 */

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

#define GPIOA ((volatile GPIO_t *)0x40020000)
#define GPIOB ((volatile GPIO_t *)0x40020400)
#define GPIOC ((volatile GPIO_t *)0x40020800)

typedef struct
{
	volatile u32 MODER;
	volatile u32 OTYPER;
	volatile u32 OSPEEDR;
	volatile u32 PUPDR;
	volatile u32 IDR;
	volatile u32 ODR;
	volatile u32 BSRR;
	volatile u32 LCKR;
	volatile u32 AFRL;
	volatile u32 AFRH;
}GPIO_t;


#endif /* GPIO_PRIVATE_H_ */
