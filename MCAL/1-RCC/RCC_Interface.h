/********************************************/
/* SWC: RCC Driver                          */
/* Author: Bendary                          */
/* Version: v0.0                            */
/* Date: 04 AUG 2023                        */
/* Description: This is the implem. of RCC  */
/********************************************/
/*File Guard*/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

void RCC_voidInitSysClk(void);
void RCC_voidEnablePerClk(u8 Copy_u8BusId, u8 Copy_u8PerId);
void RCC_voidDisablePerClk(u8 Copy_u8BusId, u8 Copy_u8PerId);

#define AHB1            0
#define AHB2            1
#define APB1            2
#define APB2            3

#endif