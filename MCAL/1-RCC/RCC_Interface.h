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

#define AHB1		0
#define AHB2		1
#define APB1		2
#define APB2		3


void MRCC_voidInit(void);
void MRCC_voidEnablePerClk(u8 A_u8BusId,u8 A_u8PerId);
void MRCC_voidDisablePerClk(u8 A_u8BusId,u8 A_u8PerId);
void MRCC_voidEnableLOWPerClk(u8 A_u8BusId,u8 A_u8PerId);
void MRCC_voidDisableLOWPerClk(u8 A_u8BusId,u8 A_u8PerId);




#endif
