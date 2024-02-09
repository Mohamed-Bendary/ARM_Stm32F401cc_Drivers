/***********************************/
/* SWC: SPI Driver                 */
/* Author: Bendary                 */
/* Version: V1                     */
/* Date: 30 May 2023               */
/***********************************/
/*File Gaurd*/
#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

/*USART1 Bus: APB2, USART6 Bus: APB2, USART2 Bus: APB1*/
/*USART1 Base Address: 0x40011000, USART6 Base Address: 0x40011400, USART2 Base Address: 0x40004400*/
typedef struct 
{
    volatile u32 CR1;
    volatile u32 RES;
    volatile u32 SR;
    volatile u32 DR;
}SPI_t;

#define SPI1         ((volatile SPI_t*)0x40013000)

/*Private Macros*/


#endif
