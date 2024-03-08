/********************************************/
/* SWC: RCC Driver                          */
/* Author: NRSHA5                           */
/* Version: v0.0                            */
/* Date: 04 AUG 2023                        */
/* Description: This is the implem. of RCC  */
/********************************************/
/*File Guard*/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H


void MGPIO_voidSetPinMode(u8 A_u8PortId,u8 A_u8PinId,u8 A_u8Mode);
void MGPIO_voidSetPinType(u8 A_u8PortId,u8 A_u8PinId,u8 A_u8Type);
void MGPIO_voidSetPinSpeed(u8 A_u8PortId,u8 A_u8PinId,u8 A_u8Speed);
void MGPIO_voidSetPinValue(u8 A_u8PortId,u8 A_u8PinId,u8 A_u8Value);
void MGPIO_voidSetPortValue(u8 A_u8PortId,u32 A_u8Value);
void MGPIO_voidSetPinValueDirectAccess(u8 A_u8PortId,u8 A_u8PinId,u8 A_u8SetRstType);
void MGPIO_voidSetPinPuPdConfig(u8 A_u8PortId,u8 A_u8PinId,u8 A_u8Type);
u8 MGPIO_u8GetPinValue(u8 A_u8PortId,u8 A_u8PinId);

#define IOA		0
#define IOB		1
#define IOC		2

#define PIN0	0
#define PIN1	1
#define PIN2	2
#define PIN3	3
#define PIN4	4
#define PIN5	5
#define PIN6	6
#define PIN7	7
#define PIN8	8
#define PIN9	9
#define PIN10	10
#define PIN11	11
#define PIN12	12
#define PIN13	13
#define PIN14	14
#define PIN15	15

#define INPUT_MODE		0
#define OUTPUT_MODE		1
#define AF_MODE			2
#define ANALOG_MODE		3


#define OUTPUT_PP		0
#define OUTPUT_OD		1

#define LOW_SPEED		0
#define MED_SPEED		1
#define HIGH_SPEED		2
#define VHIGH_SPEED		3

#define OUTPUT_LOW		0
#define OUTPUT_HIGH		1

#define OUTPUT_RESET	0
#define OUTPUT_SET		1

#define FLOATING		0
#define PULL_UP			1
#define PULL_DOWN		2

#endif
