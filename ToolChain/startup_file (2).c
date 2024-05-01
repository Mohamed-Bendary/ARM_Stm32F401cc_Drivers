#include <stdint.h>

#define RAM_START    {0x20000000}
#define RAM_SIZE     {64 * 1024}
#define RAM_END      {(RAM_START)+(RAM_SIZE)}
#define START_STACK  RAM_END

/* In the flash,, the first thing is the vector table which contains the Interrupt piriorities
 but before the piriorities of the interrupts there is 2 addresses
 1- The initializing of the stack pointer with the first address of the stack which above we defined the RAM 
 start and end (end = start + size) 
 2- The reset handler sequence,, which is a normal C function which does 3 things :
 A-Copy .data section from Flash to RAM
 B-Initialize the .bss by zeros
 C-Call main function
 */

/* We defined below the vector table array which has the vector table content as specified in order*/ 
	

void main(void); // This is the prototype to avoid linker error,, and the imolementation is on the user

/*We defined these variables in the linker script which carries the start and the end
  of the boundries of every memory section*/
  
extern uint32_t _EndOftext;
extern uint32_t _StartOfdata;
extern uint32_t _EndOfdata;
extern uint32_t _StartOfbss;
extern uint32_t _EndOfbss;


void Reset_Handler(void)
{
	
    /*Copy .data section from Flash to RAM*/	
	uint32_t Local_uint32Counter;
	
	/*The symmbols of the linker script are treated differently , they are considered like pointers
	which contains addresses of certain bositions of the memory using the (.)allocator ,,
	to access their conteained address you have to put the & before them*/
	
	uint32_t Local_uint32Size = (uint32_t)& _EndOfdata - (uint32_t)& _StartOfdata;
	
	/* Now i want to take byte by byte the values of the .data from the flash to the .data in RAM,
	  The Start of data symbol is actually carryig its start in the RAM not in the flash
	  because in the linker script i started with >SRAM not >FLASH ,, so the source of the 
	  data i want to transfer from is actually the symbol end of text*/
	
	/*The (&EndOftext) will be replaced with the address of the first address of the .data in the flash
	  so it is the source which i will transfer from.*/
	  
	uint8_t *Local_pu8Source = (uint8_t*)&_EndOftext;
	
	/* The same idea for the destination*/
	
	uint8_t *Local_pu8Destination = (uint8_t*)&_StartOfdata;
	
	for(Local_uint32Counter=0 ;Local_uint32Counter<Local_uint32Size ; Local_uint32Counter++)
	{
		*Local_pu8Destination = *Local_pu8Source;
		Local_pu8Destination++;
		Local_pu8Source++;
	}
	
	
/*Initialize the .bss by zeros */

 Local_uint32Size = (uint32_t)& _EndOfbss - (uint32_t)& _StartOfbss;
 Local_pu8Destination = (uint8_t*) _StartOfbss;
 for(Local_uint32Counter=0; Local_uint32Counter<Local_uint32Size ;Local_uint32Counter++)
 {
	*Local_pu8Destination = 0;
	 Local_pu8Destination++;
		 
 }


/*Call main function*/	
	main();
	while(1); // Embedded system code cannot end, so the code must stuck somewhere if the user didnt call the main
}

/* Its not normal that the user will implement all the handlers, so when the linker find a prototype with
no implementation will give us linker error
So the default handler will replace all the non_written handlers by the user */

void Default_Handler(void)
{
	while(1);
}
/* The first element of this prototype is weak cz the user can replace it with his implementation
    The second element is "alias" which will replace the prototype if the user didnt use the
	weak feature*/
	
void NMI_Handler                (void) __attribute__((weak,alias("Default_Handler")));
void HardFault_Handler			(void) __attribute__((weak,alias("Default_Handler")));
void MemManage_Handler			(void) __attribute__((weak,alias("Default_Handler")));
void BusFault_Handler			(void) __attribute__((weak,alias("Default_Handler")));
void UsageFault_Handler			(void) __attribute__((weak,alias("Default_Handler")));
void SVC_Handler				(void) __attribute__((weak,alias("Default_Handler")));
void DebugMon_Handler			(void) __attribute__((weak,alias("Default_Handler")));
void PendSV_Handler				(void) __attribute__((weak,alias("Default_Handler")));
void SysTick_Handler			(void) __attribute__((weak,alias("Default_Handler")));
void WWDG_IRQHandler      		(void) __attribute__((weak,alias("Default_Handler")));
void PVD_IRQHandler       		(void) __attribute__((weak,alias("Default_Handler")));
void TAMP_STAMP_IRQHandler		(void) __attribute__((weak,alias("Default_Handler")));
void RTC_WKUP_IRQHandler  		(void) __attribute__((weak,alias("Default_Handler")));
void FLASH_IRQHandler     		(void) __attribute__((weak,alias("Default_Handler")));
void RCC_IRQHandler       		(void) __attribute__((weak,alias("Default_Handler")));
void EXTI0_IRQHandler     		(void) __attribute__((weak,alias("Default_Handler")));
void EXTI1_IRQHandler     		(void) __attribute__((weak,alias("Default_Handler")));
void EXTI2_IRQHandler     		(void) __attribute__((weak,alias("Default_Handler")));
void EXTI3_IRQHandler     		(void) __attribute__((weak,alias("Default_Handler")));
void EXTI4_IRQHandler     		(void) __attribute__((weak,alias("Default_Handler")));
void DMA1_Stream0_IRQHandler    (void) __attribute__((weak,alias("Default_Handler")));
void DMA1_Stream1_IRQHandler    (void) __attribute__((weak,alias("Default_Handler")));
void DMA1_Stream2_IRQHandler    (void) __attribute__((weak,alias("Default_Handler")));
void DMA1_Stream3_IRQHandler    (void) __attribute__((weak,alias("Default_Handler")));
void DMA1_Stream4_IRQHandler    (void) __attribute__((weak,alias("Default_Handler")));
void DMA1_Stream5_IRQHandler    (void) __attribute__((weak,alias("Default_Handler")));
void DMA1_Stream6_IRQHandler    (void) __attribute__((weak,alias("Default_Handler")));
void ADC_IRQHandler             (void) __attribute__((weak,alias("Default_Handler")));
void EXTI9_5_IRQHandler         (void) __attribute__((weak,alias("Default_Handler")));
void TIM1_BRK_TIM9_IRQHandler   (void) __attribute__((weak,alias("Default_Handler")));
void TIM1_UP_TIM10_IRQHandler   (void) __attribute__((weak,alias("Default_Handler")));
void TIM1_TRG_COM_TIM11_IRQHandl(void) __attribute__((weak,alias("Default_Handler")));
void TIM1_CC_IRQHandler         (void) __attribute__((weak,alias("Default_Handler")));
void TIM2_IRQHandler            (void) __attribute__((weak,alias("Default_Handler")));
void TIM3_IRQHandler            (void) __attribute__((weak,alias("Default_Handler")));
void TIM4_IRQHandler            (void) __attribute__((weak,alias("Default_Handler")));
void I2C1_EV_IRQHandler         (void) __attribute__((weak,alias("Default_Handler")));
void I2C1_ER_IRQHandler         (void) __attribute__((weak,alias("Default_Handler")));
void I2C2_EV_IRQHandler         (void) __attribute__((weak,alias("Default_Handler")));
void I2C2_ER_IRQHandler         (void) __attribute__((weak,alias("Default_Handler")));
void SPI1_IRQHandler            (void) __attribute__((weak,alias("Default_Handler")));
void SPI2_IRQHandler            (void) __attribute__((weak,alias("Default_Handler")));
void USART1_IRQHandler          (void) __attribute__((weak,alias("Default_Handler")));
void USART2_IRQHandler          (void) __attribute__((weak,alias("Default_Handler")));
void USART3_IRQHandler          (void) __attribute__((weak,alias("Default_Handler")));
void EXTI15_10_IRQHandler       (void) __attribute__((weak,alias("Default_Handler")));
void RTC_Alarm_IRQHandler       (void) __attribute__((weak,alias("Default_Handler")));
void OTG_FS_WKUP_IRQHandler     (void) __attribute__((weak,alias("Default_Handler")));
void DMA1_Stream7_IRQHandler    (void) __attribute__((weak,alias("Default_Handler")));
void SDIO_IRQHandler            (void) __attribute__((weak,alias("Default_Handler")));
void TIM5_IRQHandler            (void) __attribute__((weak,alias("Default_Handler")));
void SPI3_IRQHandler            (void) __attribute__((weak,alias("Default_Handler")));
void DMA2_Stream0_IRQHandler	(void) __attribute__((weak,alias("Default_Handler")));
void DMA2_Stream1_IRQHandler	(void) __attribute__((weak,alias("Default_Handler")));
void DMA2_Stream2_IRQHandler	(void) __attribute__((weak,alias("Default_Handler")));
void DMA2_Stream3_IRQHandler	(void) __attribute__((weak,alias("Default_Handler")));
void DMA2_Stream4_IRQHandler	(void) __attribute__((weak,alias("Default_Handler")));
void OTG_FS_IRQHandler        	(void) __attribute__((weak,alias("Default_Handler")));
void DMA2_Stream5_IRQHandler  	(void) __attribute__((weak,alias("Default_Handler")));
void DMA2_Stream6_IRQHandler  	(void) __attribute__((weak,alias("Default_Handler")));
void DMA2_Stream7_IRQHandler  	(void) __attribute__((weak,alias("Default_Handler")));
void FPU_IRQHandler       		(void) __attribute__((weak,alias("Default_Handler")));
void SPI4_IRQHandler      		(void) __attribute__((weak,alias("Default_Handler")));
void USART6_IRQHandler      	(void) __attribute__((weak,alias("Default_Handler")));
void I2C3_EV_IRQHandler      	(void) __attribute__((weak,alias("Default_Handler")));
void I2C3_ER_IRQHandler      	(void) __attribute__((weak,alias("Default_Handler")));

/* This is the array containing the Stack pointer initialization address which is the first address of the
stack and then the reset handler,, then the interrupts handlers*/

/*The linker that manages .bss, .data. and so on will be given another different section which i called it-->.vector
using the implementation below*/
uint32_t Vectors[]            __attribute__((section(".vector")))   =  
{ 
    START_STACK,
	(uint32_t)Reset_Handler,
	(uint32_t)NMI_Handler				   ,
	(uint32_t)HardFault_Handler			,
	(uint32_t)MemManage_Handler			,
	(uint32_t)BusFault_Handler			,
	(uint32_t)UsageFault_Handler			,
	0, //Reserved
	0, //Reserved
	0, //Reserved
	0, //Reserved
    (uint32_t)SVC_Handler				   ,
    (uint32_t)DebugMon_Handler			,
	0, //Reserved
    (uint32_t)PendSV_Handler				,
    (uint32_t)SysTick_Handler			   ,
    (uint32_t)WWDG_IRQHandler      		,
    (uint32_t)PVD_IRQHandler       		,
    (uint32_t)TAMP_STAMP_IRQHandler		,
    (uint32_t)RTC_WKUP_IRQHandler  		,
    (uint32_t)FLASH_IRQHandler     		,
    (uint32_t)RCC_IRQHandler       		,
    (uint32_t)EXTI0_IRQHandler     		,
    (uint32_t)EXTI1_IRQHandler     		,
    (uint32_t)EXTI2_IRQHandler     		,
    (uint32_t)EXTI3_IRQHandler     		,
    (uint32_t)EXTI4_IRQHandler     		,
    (uint32_t)DMA1_Stream0_IRQHandler    ,
    (uint32_t)DMA1_Stream1_IRQHandler    ,
    (uint32_t)DMA1_Stream2_IRQHandler    ,
    (uint32_t)DMA1_Stream3_IRQHandler    ,
    (uint32_t)DMA1_Stream4_IRQHandler    ,
    (uint32_t)DMA1_Stream5_IRQHandler    ,
    (uint32_t)DMA1_Stream6_IRQHandler    ,
    (uint32_t)ADC_IRQHandler             ,
    (uint32_t)EXTI9_5_IRQHandler         ,
    (uint32_t)TIM1_BRK_TIM9_IRQHandler   ,
    (uint32_t)TIM1_UP_TIM10_IRQHandler   ,
    (uint32_t)TIM1_TRG_COM_TIM11_IRQHandl,
    (uint32_t)TIM1_CC_IRQHandler         ,
    (uint32_t)TIM2_IRQHandler            ,
    (uint32_t)TIM3_IRQHandler            ,
    (uint32_t)TIM4_IRQHandler            ,
    (uint32_t)I2C1_EV_IRQHandler         ,
    (uint32_t)I2C1_ER_IRQHandler         ,
    (uint32_t)I2C2_EV_IRQHandler         ,
    (uint32_t)I2C2_ER_IRQHandler         ,
    (uint32_t)SPI1_IRQHandler            ,
    (uint32_t)SPI2_IRQHandler            ,
    (uint32_t)USART1_IRQHandler          ,
    (uint32_t)USART2_IRQHandler          ,
    (uint32_t)EXTI15_10_IRQHandler       ,
    (uint32_t)RTC_Alarm_IRQHandler       ,
    (uint32_t)OTG_FS_WKUP_IRQHandler     ,
    (uint32_t)DMA1_Stream7_IRQHandler     ,
    (uint32_t)SDIO_IRQHandler             ,
    (uint32_t)TIM5_IRQHandler             ,
    (uint32_t)SPI3_IRQHandler             ,
    (uint32_t)DMA2_Stream0_IRQHandler	    ,
    (uint32_t)DMA2_Stream1_IRQHandler	    ,
    (uint32_t)DMA2_Stream2_IRQHandler	    ,
    (uint32_t)DMA2_Stream3_IRQHandler	    ,
    (uint32_t)DMA2_Stream4_IRQHandler	    ,
	0, //Reserved
	0, //Reserved
    (uint32_t)OTG_FS_IRQHandler        	,
    (uint32_t)DMA2_Stream5_IRQHandler  	,
    (uint32_t)DMA2_Stream6_IRQHandler  	,
    (uint32_t)DMA2_Stream7_IRQHandler  	,
    (uint32_t)USART6_IRQHandler        	,
    (uint32_t)I2C3_EV_IRQHandler       	,
    (uint32_t)I2C3_ER_IRQHandler       	,
	0, //Reserved
	0, //Reserved
	0, //Reserved
	0, //Reserved
	0, //Reserved
	0, //Reserved
	0, //Reserved
    (uint32_t)FPU_IRQHandler       		,
	0, //Reserved
	0, //Reserved
    (uint32_t)SPI4_IRQHandler 
	
};






