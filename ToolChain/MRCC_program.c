/*
 * MRCC_program.c
 *
 *  Created on: Sep 6, 2023
 *      Author: Amr-a
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MRCC_registers.h"
#include "MRCC_interface.h"
#include "MRCC_config.h"
#include "MRCC_private.h"



void MRCC_voidInitSystemAndBusClock(){
#if RCC_SYSTEM_CLK_SOURCE == HSI_CLK_SOURCE
	voidEnableHSI_CLK();
#elif RCC_SYSTEM_CLK_SOURCE == HSE_CRYSTAL_CLK_SOURCE
	voidEnableHSE_Crystal_CLK();
#elif RCC_SYSTEM_CLK_SOURCE == HSE_USER_CLK_SOURCE
	voidEnableHSE_User_CLK();
#elif RCC_SYSTEM_CLK_SOURCE == PLL_HSI_CLK_SOURCE
	voidEnablePLL_HSI_CLK();
#elif RCC_SYSTEM_CLK_SOURCE == PLL_HSE_USER_CLK_SOURCE
	voidEnablePLL_HSE_User_CLK();
#elif RCC_SYSTEM_CLK_SOURCE == PLL_HSE_CRYSTAL_CLK_SOURCE
	voidEnablePLL_HSE_Crystal_CLK();

#elif
	/*return error */
#endif
	voidSetBusesClock();

}

void voidSetBusesClock(){

	/* setting AHB high-speed prescaler*/
	WRITE_BITS(RCC_CFGR,HPRE_0,AHB_PRESCALER,FOUR_BITS);
	/* setting APB2 high-speed prescaler*/
	WRITE_BITS(RCC_CFGR,PPRE2_0,APB2_PRESCALER,THREE_BITS);
	/* setting : APB1 Low speed prescaler (APB1)*/
	WRITE_BITS(RCC_CFGR,PPRE1_0,APB1_PRESCALER,THREE_BITS);
}
void MRCC_voidEnablePerphClock(t_RccBus Copy_enuBus ,t_RccPeripheral Copy_enuPerphiralID){
	switch (Copy_enuBus){
	case MRCC_AHB1 : SET_BIT(RCC_AHB1ENR,Copy_enuPerphiralID); break;
	case MRCC_AHB2 : SET_BIT(RCC_AHB2ENR,Copy_enuPerphiralID); break;
	case MRCC_APB1 : SET_BIT(RCC_APB1ENR,Copy_enuPerphiralID); break;
	case MRCC_APB2 : SET_BIT(RCC_APB2ENR,Copy_enuPerphiralID); break;
	default: break ;
	}
}


void MRCC_voidDisablePerphClock(t_RccBus Copy_enuBus ,t_RccPeripheral Copy_enuPerphiralID){
	switch (Copy_enuBus){
	case MRCC_AHB1 : CLR_BIT(RCC_AHB1ENR,Copy_enuPerphiralID); break;
	case MRCC_AHB2 : CLR_BIT(RCC_AHB2ENR,Copy_enuPerphiralID); break;
	case MRCC_APB1 : CLR_BIT(RCC_APB1ENR,Copy_enuPerphiralID); break;
	case MRCC_APB2 : CLR_BIT(RCC_APB2ENR,Copy_enuPerphiralID); break;
	default: break ;
	}
}

void voidEnableHSI_CLK(){
	/* Enable HSI */
	SET_BIT(RCC_CR,HSION);

	/*trim if you want */

	/* switch system clk to HSI */

	WRITE_BITS(RCC_CFGR,SW_0,SWITCH_HSI,TWO_BITS);

	/* Booling till stable */
	while(CLK_NOT_READY == GET_BIT(RCC_CR,HSIRDY)){

	}
	/*trim if you want */
}
void voidEnableHSE_Crystal_CLK(){
	/*	Selecting HSI as Crystal */
	CLR_BIT(RCC_CR,HSEBYP);
	/* Enabling HSE	*/
	SET_BIT(RCC_CR,HSEON);
	/* switch system clk to HSE */
	WRITE_BITS(RCC_CFGR,SW_0,SWITCH_HSE,TWO_BITS);
	/*Booling till ready */
	while(CLK_NOT_READY == GET_BIT(RCC_CR,HSERDY)){

	}
}
void voidEnableHSE_User_CLK(){
	/*Selecting HSE source as py pass User*/
	SET_BIT(RCC_CR,HSEBYP);
	/* Enabling HSE */
	SET_BIT(RCC_CR,HSEON);
	/* switch system clk to HSE */
	WRITE_BITS(RCC_CFGR,SW_0,SWITCH_HSE,TWO_BITS);
	while(CLK_NOT_READY == GET_BIT(RCC_CR,HSERDY)){

	}
}

void voidEnablePLL_HSI_CLK(){

	voidEnableHSI_CLK();

	/* PLL source is HSI */
	CLR_BIT(RCC_PLLCFGR,PLLSRC);

	/*prescalers*/
	WRITE_BITS(RCC_PLLCFGR,PLLP_0,(PLL_P_DIV_FACTOR-1)/2,TWO_BITS);
	WRITE_BITS(RCC_PLLCFGR,PLLN_0,PLL_N_MUL_FACTOR,NINE_BITS);
	WRITE_BITS(RCC_PLLCFGR,PLLM_0,PLL_M_DIV_FACTOR,SIX_BITS);
	SET_BIT(RCC_CR,PLL_ON);
	/* Swich system clk to PLL */
	WRITE_BITS(RCC_CFGR,SW_0,SWITCH_PLL,TWO_BITS);
	while(CLK_NOT_READY == GET_BIT(RCC_CR,PLL_RDY)){

	}

}
void voidEnablePLL_HSE_Crystal_CLK(){

	voidEnableHSE_Crystal_CLK();

	/* PLL source is HSE */
	SET_BIT(RCC_PLLCFGR,PLLSRC);

	/*prescalers*/
	WRITE_BITS(RCC_PLLCFGR,PLLP_0,PLL_P_DIV_FACTOR/2,TWO_BITS);
	WRITE_BITS(RCC_PLLCFGR,PLLN_0,PLL_N_MUL_FACTOR,NINE_BITS);
	WRITE_BITS(RCC_PLLCFGR,PLLM_0,PLL_M_DIV_FACTOR,SIX_BITS);
	SET_BIT(RCC_CR,PLL_ON);

	/* Swich system clk to PLL */
	WRITE_BITS(RCC_CFGR,SW_0,SWITCH_PLL,TWO_BITS);
	while(CLK_NOT_READY == GET_BIT(RCC_CR,PLL_RDY)){

	}

}

void voidEnablePLL_HSE_User_CLK(){

	voidEnableHSE_Crystal_CLK();

	/* PLL source is HSE */
	SET_BIT(RCC_PLLCFGR,PLLSRC);

	/*prescalers*/
	WRITE_BITS(RCC_PLLCFGR,PLLP_0,PLL_P_DIV_FACTOR/2,TWO_BITS);
	WRITE_BITS(RCC_PLLCFGR,PLLN_0,PLL_N_MUL_FACTOR,NINE_BITS);
	WRITE_BITS(RCC_PLLCFGR,PLLM_0,PLL_M_DIV_FACTOR,SIX_BITS);
	SET_BIT(RCC_CR,PLL_ON);
	while(CLK_NOT_READY == GET_BIT(RCC_CR,PLL_RDY)){

	}

}
