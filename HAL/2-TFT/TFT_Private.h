/***********************************/
/* SWC: TFT Driver                 */
/* Author: Bendary                 */
/* Version: V1                     */
/* Date: 20 Jun 2023               */
/***********************************/
/*File Gaurd*/
#ifndef TFT_PRIVATE_H
#define TFT_PRIVATE_H

static void Private_voidSendCmd(u8 Copy_u8Command);
static void Private_voidSendData(u8 Copy_u8Data);
static void Private_voidSendResetPulse(void);

#define SLP_OUT_CMD		0x11

#endif
