

#ifndef FMI_PRIVATE_H_
#define FMI_PRIVATE_H_



#define FMI_BASE_ADDRESS  0x40023C00



typedef struct
{
	volatile u32 ACR;
	volatile u32 KEYR;
	volatile u32 OPTKEYR;
	volatile u32 SR;
	volatile u32 CR;
	volatile u32 OPTCR;
}FMI_t;

#define FMI   ((volatile FMI_t*)FMI_BASE_ADDRESS)



/****************************Private macros**********************/

//Registers bits
#define CR_LOCK   31
#define CR_SER    1
#define CR_STRT   16
#define CR_PG     0

#define SR_BSY    16
#define SR_EOP    0

//Keys
#define KEY1     0x45670123
#define KEY2     0xCDEF89AB

//PSIZE options
#define  x8   0b00
#define  x16  0b01
#define  x32  0b10
#define  x64  0b11


#endif



