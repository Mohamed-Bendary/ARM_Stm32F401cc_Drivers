
ENTRY (Reset_Handler)

MEMORY
{
  FLASH(rx): ORIGIN = 0x08000000 , LENGTH = 256K
  SRAM(rwx): ORIGIN = 0x20000000 , LENGTH = 64k

}

SECTIONS
{
   .text :
   {
     *(.vector)
	 *(.text)
	 *(.rodata)
	 . =ALIAGN(4);
	 _EndOftext = .;
   }>FLASH
   
   .data :
   {
   _StartOfdata = .;
   *(.data)
   . =ALIAGN(4);
   _EndOfdata = .;
   }>SRAM AT>FLASH

   .bss :
   {
   _StartOfbss = .;
   *(.bss)
   . =ALIAGN(4);
   _EndOfbss = .;
   }>SRAM
}








