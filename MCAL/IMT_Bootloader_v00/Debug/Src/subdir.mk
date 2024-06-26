################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/FMI_Program.c \
../Src/GPIO_program.c \
../Src/Hex_Parser.c \
../Src/RCC_Program.c \
../Src/STK_prg.c \
../Src/UART_program.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/FMI_Program.o \
./Src/GPIO_program.o \
./Src/Hex_Parser.o \
./Src/RCC_Program.o \
./Src/STK_prg.o \
./Src/UART_program.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/FMI_Program.d \
./Src/GPIO_program.d \
./Src/Hex_Parser.d \
./Src/RCC_Program.d \
./Src/STK_prg.d \
./Src/UART_program.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F401CCUx -DSTM32 -DSTM32F4 -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/FMI_Program.cyclo ./Src/FMI_Program.d ./Src/FMI_Program.o ./Src/FMI_Program.su ./Src/GPIO_program.cyclo ./Src/GPIO_program.d ./Src/GPIO_program.o ./Src/GPIO_program.su ./Src/Hex_Parser.cyclo ./Src/Hex_Parser.d ./Src/Hex_Parser.o ./Src/Hex_Parser.su ./Src/RCC_Program.cyclo ./Src/RCC_Program.d ./Src/RCC_Program.o ./Src/RCC_Program.su ./Src/STK_prg.cyclo ./Src/STK_prg.d ./Src/STK_prg.o ./Src/STK_prg.su ./Src/UART_program.cyclo ./Src/UART_program.d ./Src/UART_program.o ./Src/UART_program.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

