/********************************************/
/* SWC: STK Driver                          */
/* Author: Bendary                          */
/* Version: v0.0                            */
/* Date: 20 OCT 2023                        */
/* Description: This is the implem. of STK  */
/********************************************/
/*File Guard*/
#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

void STK_voidInit(void);
void STK_voidSetBusyWait(u32 Copy_u32TimeInMillis);
void STK_voidSetIntervalSingle(u32 Copy_u32TimeInMillis,void (*LPF) (void));
void STK_voidSetIntervalPeriodic(u32 Copy_u32TimeInMillis,void (*LPF)(void));
u32 STK_voidGetElapsedTime(void);
u32 STK_voidGetRemainingTime(void);

#endif
