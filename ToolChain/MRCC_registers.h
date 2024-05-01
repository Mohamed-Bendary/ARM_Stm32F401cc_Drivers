/*
 * MRCC_registers.h
 *
 *  Created on: Sep 6, 2023
 *      Author: Amr-a
 */

#ifndef MRCC_REGISTERS_H_
#define MRCC_REGISTERS_H_

#define MRCC_BASE_ADDRESS	(0x40023800)

#define RCC_CR				*((volatile u32*)(MRCC_BASE_ADDRESS + 0x00))
#define PLL_I2SRDY			27
#define PLL_I2SON			26
#define PLL_RDY				25
#define PLL_ON				24
#define CSSON				19
#define HSEBYP				18
#define HSERDY				17
#define HSEON				16
#define HSICAL_7			15
#define HSICAL_6			14
#define HSICAL_5			13
#define HSICAL_4			12
#define HSICAL_3			11
#define HSICAL_2			10
#define HSICAL_1			9
#define HSICAL_0			8
#define HSITRIM_4			7
#define HSITRIM_3			6
#define HSITRIM_2			5
#define HSITRIM_1			4
#define HSITRIM_0			3
#define HSIRDY				1
#define HSION               0

#define RCC_PLLCFGR			*((volatile u32*)(MRCC_BASE_ADDRESS + 0x04))
#define PLLQ_3             	27
#define PLLQ_2             	26
#define PLLQ_1             	25
#define PLLQ_0             	24
#define PLLSRC             	22
#define PLLP_1             	17
#define PLLP_0             	16
#define PLLN_8             	14
#define PLLN_7             	13
#define PLLN_6             	12
#define PLLN_5            	11
#define PLLN_4             	10
#define PLLN_3             	9
#define PLLN_2             	8
#define PLLN_1             	7
#define PLLN_0             	6
#define PLLM_5             	5
#define PLLM_4             	4
#define PLLM_3             	3
#define PLLM_2             	2
#define PLLM_1             	1
#define PLLM_0             	0

#define RCC_CFGR			*((volatile u32*)(MRCC_BASE_ADDRESS + 0x08))
#define MCO2_1				31
#define MCO2_0              30
#define MCO2PRE2            29
#define MCO2PRE1            28
#define MCO2PRE0            27
#define MCO1PRE2            26
#define MCO1PRE1            25
#define MCO1PRE0            24
#define I2SSRC              23
#define MCO1_1              22
#define MCO1_0              21
#define RTCPRE_4            20
#define RTCPRE_3            19
#define RTCPRE_2            18
#define RTCPRE_1            17
#define RTCPRE_0            16
#define PPRE2_2             15
#define PPRE2_1             14
#define PPRE2_0             13
#define PPRE1_2             12
#define PPRE1_1             11
#define PPRE1_0             10
#define HPRE_3              7
#define HPRE_2              6
#define HPRE_1              5
#define HPRE_0              4
#define SWS_1               3
#define SWS_0               2
#define SW_1                1
#define SW_0                0

#define RCC_CRI				*((volatile u32*)(MRCC_BASE_ADDRESS + 0x0C))
#define CSSC                23
#define PLLI2SRDYC          21
#define PLLRDYC             20
#define HSERDYC             19
#define HSIRDYC             18
#define LSERDYC             17
#define LSIRDYC             16
#define PLLI2SRDYIE         14
#define PLLRDYIE            13
#define HSERDYIE            12
#define HSIRDYIE            11
#define LSERDYIE            10
#define LSIRDYIE            9
#define CSSF                8
#define PLLI2SRDYF          5
#define PLLRDYF             4
#define HSERDYF             3
#define HSIRDYF             2
#define LSERDYF             1
#define LSIRDYF             0

#define RCC_AHB1RSTR		*((volatile u32*)(MRCC_BASE_ADDRESS + 0x10))
#define DMA2RST             22
#define DMA1RST             21
#define CRCRST              12
#define GPIOHRST            7
#define GPIOERST            4
#define GPIODRST            3
#define GPIOCRST            2
#define GPIOBRST            1
#define GPIOARST            0

#define RCC_AHB2RSTR		*((volatile u32*)(MRCC_BASE_ADDRESS + 0x14))
#define OTGFSRST			7

#define RCC_APB1RSTR		*((volatile u32*)(MRCC_BASE_ADDRESS + 0x20))
#define PWRRST              28
#define I2C3RST             23
#define I2C2RST             22
#define I2C1RST             21
#define USART2RST           17
#define SPI3RST             15
#define SPI2RST             14
#define WWDGRST             11
#define TIM5RST             3
#define TIM4RST             2
#define TIM3RST             1
#define TIM2RST             0

#define RCC_APB2RSTR		*((volatile u32*)(MRCC_BASE_ADDRESS + 0x24))
#define TIM11RST            18
#define TIM10RST            17
#define TIM9RST             16
#define SYSCFGRST           14
#define SP45RST             13
#define SPI1RST             12
#define SDIORST             11
#define ADC1RST             8
#define USART6RST           5
#define USART1RST           4
#define TIM1RST             0
#define RCC_AHB1ENR			*((volatile u32*)(MRCC_BASE_ADDRESS + 0x30))
#define DMA2EN				22
#define DMA1EN		        21
#define CRCEN		        12
#define GPIOHRST	        7
#define GPIOEEN		        4
#define GPIODEN		        3
#define GPIOCEN		        2
#define GPIOBEN		        1
#define GPIOAEN             0

#define RCC_AHB2ENR			*((volatile u32*)(MRCC_BASE_ADDRESS + 0x34))
#define OTGFSEN				7

#define RCC_APB1ENR			*((volatile u32*)(MRCC_BASE_ADDRESS + 0x40))
#define PWREN               28
#define I2C3EN              23
#define I2C2EN              22
#define I2C1EN              21
#define SPI3EN              15
#define SPI2EN              14
#define WWDGEN              11
#define TIM5EN              3
#define TIM4EN              2
#define TIM3EN              1
#define TIM2EN              0

#define RCC_APB2ENR			*((volatile u32*)(MRCC_BASE_ADDRESS + 0x44))
#define TIM11EN             18
#define TIM10EN             17
#define TIM9EN              16
#define SYSCFGEN            14
#define SPI4EN              13
#define SPI1EN              12
#define SDIOEN              11
#define ADC1EN              8
#define USART6EN            5
#define USART1EN            4
#define TIM1EN              0

#define RCC_AHB1LPENR		*((volatile u32*)(MRCC_BASE_ADDRESS + 0x50))
#define DMA2LPEN			22
#define DMA1LPEN	        21
#define SRAM1LPEN	        16
#define FLITFLPEN	        15
#define CRCLPEN		        12
#define GPIOHLPEN	        7
#define GPIOELPEN	        4
#define GPIODLPEN	        3
#define GPIOCLPEN	        2
#define GPIOBLPEN	        1
#define GPIOALPEN	        0

#define RCC_AHB2LPENR		*((volatile u32*)(MRCC_BASE_ADDRESS + 0x54))
#define OTGFSLPEN			7

#define RCC_APB1LPENR		*((volatile u32*)(MRCC_BASE_ADDRESS + 0x60))
#define PWRLPEN             28
#define I2C3LPEN            23
#define I2C2LPEN            22
#define I2C1LPEN            21
#define USART2LPEN          17
#define SPI3LPEN            15
#define SPI2LPEN            14
#define WWDGLPEN            11
#define TIM5LPEN            3
#define TIM4LPEN            2
#define TIM3LPEN            1
#define TIM2LPEN            0

#define RCC_APB2LPENR		*((volatile u32*)(MRCC_BASE_ADDRESS + 0x64))
#define TIM11LPEN           18
#define TIM10LPEN           17
#define TIM9LPEN            16
#define SYSCFGLPEN          14
#define SPI4LPEN            13
#define SPI1LPEN            12
#define SDIOLPEN            11
#define ADC1LPEN            8
#define USART6LPEN          5
#define USART1LPEN          4
#define TIM1LPEN            0
#define RCC_BDCR			*((volatile u32*)(MRCC_BASE_ADDRESS + 0x70))
#define BDRST				16
#define RTCEN				15
#define RTCSEL_1			9
#define RTCSEL_0			8
#define LSEBYP				2
#define LSERDY				1
#define LSEON				0
#define RCC_CSR				*((volatile u32*)(MRCC_BASE_ADDRESS + 0x74))
#define LPWRRSTF			31
#define WWDGRSTF			30
#define WDGRSTF				29
#define SFTRSTF				28
#define PORRSTF				27
#define PADRSTF				26
#define BORRSTF				25
#define RMVF				24
#define LSIRDY				1
#define LSION               0

#define RCC_SSCGR			*((volatile u32*)(MRCC_BASE_ADDRESS + 0x80))
#define SSCGEN				31
#define SPREADSEL			30
#define INCSTEP14			26
#define INCSTEP13           25
#define INCSTEP12           24
#define INCSTEP11           23
#define INCSTEP10           22
#define INCSTEP9            21
#define INCSTEP8            20
#define INCSTEP7            19
#define INCSTEP6            18
#define INCSTEP5            17
#define INCSTEP4            16
#define INCSTEP3            15
#define INCSTEP2            14
#define INCSTEP1            13
#define INCSTEP0            12
#define MODPER11            11
#define MODPER10            10
#define MODPER9             9
#define MODPER8             8
#define MODPER7             7
#define MODPER6             6
#define MODPER5             5
#define MODPER4             4
#define MODPER3             3
#define MODPER2             2
#define MODPER1             1
#define MODPER0             0

#define RCC_PLLI2SCFGR		*((volatile u32*)(MRCC_BASE_ADDRESS + 0x84))
#define PLLI2SR2			30
#define PLLI2SR1			29
#define PLLI2SR0			28
#define PLLI2SN8			14
#define PLLI2SN7			13
#define PLLI2SN6			12
#define PLLI2SN5			11
#define PLLI2SN4			10
#define PLLI2SN3			9
#define PLLI2SN2			8
#define PLLI2SN1			7
#define PLLI2SN0			6

#define RCC_DCKCFGR			*((volatile u32*)(MRCC_BASE_ADDRESS + 0x8C))
#define TIMPRE				24

#endif /* MRCC_REGISTERS_H_ */
