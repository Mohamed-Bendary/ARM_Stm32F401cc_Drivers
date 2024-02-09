/*****************************************/
/* Author  :  Bendary                    */
/* Version :  V01                        */
/* Date    : 18 May 2023                 */
/*****************************************/
#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/NVIC_interface.h"
#include "../include/NVIC_private.h"
#include "../include/NVIC_config.h"

u32 GlobalStatic_u32GroupConf;

void NVIC_voidEnableInt(u8 Copy_u8IntId)
{
	/*NVIC_ISER[0]-->NVIC_ISER[7]*/
	NVIC->ISER[Copy_u8IntId / 32] = (1 << (Copy_u8IntId % 32));	//17/32
}

void NVIC_voidDisableInt(u8 Copy_u8IntId)
{
	NVIC->ICER[Copy_u8IntId / 32] = (1 << (Copy_u8IntId % 32));
}

void NVIC_voidSetPendingFlag(u8 Copy_u8IntId)
{
	NVIC->ISPR[Copy_u8IntId / 32] = (1 << (Copy_u8IntId % 32));
}

void NVIC_voidClearPendingFlag(u8 Copy_u8IntId)
{
	NVIC->ICPR[Copy_u8IntId / 32] = (1 << (Copy_u8IntId % 32));
}

/*Copy_u8PriorityOption: GROUP4BITS_SUBGROUP0BITS - GROUP3BITS_SUBGROUP1BITS - GROUP2BITS_SUBGROUP2BITS - GROUP1BITS_SUBGROUP3BITS - GROUP0BITS_SUBGROUP4BITS*/
void NVIC_voidSetPriorityConfig(u8 Copy_u8PriorityOption)
{
	/*3bits starting from bit8 in AIRCR Reg*/
	GlobalStatic_u32GroupConf = VECT_KEY | (Copy_u8PriorityOption << 8);
	SCB -> AIRCR = GlobalStatic_u32GroupConf;
}

/*Copy_u8GroupId, Copy_u8SubGroupId ==> normal numbers*/
void NVIC_voidSetIntPriority(s8 Copy_s8IntId, u8 Copy_u8GroupId, u8 Copy_u8SubGroupId)
{
	u8 local_u8Priority = Copy_u8SubGroupId | Copy_u8GroupId << ((GlobalStatic_u32GroupConf - 0x05FA0300) / 256);
	/*Internal Interrupt :: SCB -> SHPR[1-3]*/
	if(Copy_s8IntId < 0)
	{

	}
	else if(Copy_s8IntId >= 0)
	{
		/*External Interrupt*/
		NVIC -> IPR[Copy_s8IntId] = (local_u8Priority << 4);	//The 4 LSB bits in the 8-bit register isn't used.
	}
}


