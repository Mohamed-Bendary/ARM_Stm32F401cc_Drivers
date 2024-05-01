#ifndef BIT_MATH_H
	#define BIT_MATH_H
	
#define SET_BIT(REG, BIT_NO) (REG |= (1 << (BIT_NO) ) )

#define CLR_BIT(REG, BIT_NO) (REG &= ~(1 << (BIT_NO) ) )

#define TOG_BIT(REG, BIT_NO) (REG ^= (1 << (BIT_NO) ) )

#define GET_BIT(REG, BIT_NO) ( (REG >> (BIT_NO) ) & 1 )

/* Masking a given register with a given value with the help of the BITS_GROUP
 * To use it you need:-
 * REG ==> the register or the variable that you would like to mask the bits into it
 * START_BIT_NO ==> the number of the bits from where it will start masking
 * VAL ==> the value that you would like to mask
 * BITS_GROUP ==> number of bits you will mask will be send like 0b111 if 3 bits
 * 				  or 0b11 if 2 bits (note that it should be in a binary format and all
 * 				  bits are ones )*/
#define WRT_GROUP_OF_BITS(REG, START_BIT_NO, VAL, BITS_GROUP)	( (REG) = ( (REG) & ~( (BITS_GROUP) << (START_BIT_NO) ) ) | ( (VAL) << (START_BIT_NO) ) )

#endif
