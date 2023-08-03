/*
 * STM32F103X6.h
 *
 *  Created on: Mar 21, 2023
 *      Author: ANDREW NASSER
 */

#ifndef INC_STM32F103X6_H_
#define INC_STM32F103X6_H_

//INCLUDES

#include<stdlib.h>
#include<stdio.h>
#include<stdint.h>


//BASE ADRESSES FOR MEMORY

#define FLASH_MEMORY_BASE				0x08000000UL
#define SYSTEM_MEMORY_BASE				0x1FFFF000UL
#define SRAM_MEMORY_BASE				0x20000000UL
#define PERIPHERALS_BASE				0x40000000UL
#define CORTEX_PERIPHERALS_BASE			0xE0000000UL	//CORTEX-M3 INTERNAL PERIPHERALS


//BASE ADDRESSES FOR AHB PERIPHERALS

#define RCC_BASE						0x40021000UL	//RESET CLOCK CONTROL


//==******************************BASE ADDRESSES FOR APB2 PERIPHERALS******************************==//

#define EXTI_BASE						0x40010400UL	//EXTERNAL INTERRUPT
#define AFIO_BASE						0x40010000UL	//ALTERNATIVE FUNCTION INPUT / OUTPUT


//**BASE ADRESSES FOR PERIPHERALS**

//GPIO BASE ADRESSES
#define GPIOA_BASE						0x40010800UL		//FULL OUT @ LQFFP48
#define GPIOB_BASE						0x40010C00UL		//FULL OUT @ LQFFP48
#define GPIOC_BASE						0x40011000UL		//PARTIAL OUT @ LQFFP48
#define GPIOD_BASE						0x40011400UL		//PARTIAL OUT @ LQFFP48
#define GPIOE_BASE						0x40011800UL		//NOT FOUND OUT @ LQFFP48



//USART BASE ADRESSES
#define USART1_BASE						0x40013800UL
#define USART2_BASE						0x40004400UL
#define USART3_BASE						0x40004800UL



//SPI BASE ADRESSES
#define SPI1_BASE						0x40013000UL
#define SPI2_BASE						0x40003C00UL
#define SPI3_BASE						0x40003800UL

//********************************************************************************************************//

//PERIPHERALS REGISTERS

//GPIO REGISTERS

typedef struct{
	volatile u_int32_t CRL;  								// REGISTER IS 32 BIT U CAN ACCESS ALL
	volatile u_int32_t CRH;  								// REGISTER IS 32 BIT U CAN ACCESS ALL
	volatile u_int32_t IDR;  								// REGISTER IS 32 BIT [16:31] RESERVED
	volatile u_int32_t ODR;  								// REGISTER IS 32 BIT [16:31] RESERVED
	volatile u_int32_t BSSR;  								// REGISTER IS 32 BIT U CAN ACCESS ALL
	volatile u_int32_t BRR;  								// REGISTER IS 32 BIT [16:31] RESERVED
	volatile u_int32_t LCKR;  								// REGISTER IS 32 BIT [16:31] RESERVED


}GPIO_Typedef;


//RCC REGISTERS

typedef struct{
	volatile u_int32_t CR;  								// REGISTER IS 32 BIT [30:31],[20:23],2 RESERVED
	volatile u_int32_t CFGR;  								// REGISTER IS 32 BIT [28:31] ,23 RESERVED
	volatile u_int32_t CIR;  								// REGISTER IS 32 BIT [24:31] ,15 RESERVED
	volatile u_int32_t APB2RSTR;  							// REGISTER IS 32 BIT [15:31],[7:8],13,1 RESERVED
	volatile u_int32_t APB1RSTR;  							// REGISTER IS 32 BIT [6:10],[12:13],[23:24],[30:31],16 RESERVED
	volatile u_int32_t AHBENR;  							// REGISTER IS 32 BIT [17:31],[7:11] , 13,5,3 RESERVED
	volatile u_int32_t APB2ENR;  							// REGISTER IS 32 BIT [15:31],[7:8] ,13 & 1 RESERVED
	volatile u_int32_t APB1ENR;  							// REGISTER IS 32 BIT [6:10],[12:13],[23:24],[30:31] & 16 RESERVED
	volatile u_int32_t BDCR;  								// REGISTER IS 32 BIT [0:2] & [8:9] &[15:16] ACCESS
	volatile u_int32_t CSR;  								// REGISTER IS 32 BIT [2:23] & 25 RESERVED
	volatile u_int32_t AHPSTR;  							// REGISTER IS 32 BIT 12 , 14 ACCESS
	volatile u_int32_t CFGR2;  								// REGISTER IS 32 BIT [16:31] RESERVED


}RCC_Typedef;


//EXTI REGISTERS

typedef struct{
	volatile u_int32_t IMR;  								// REGISTER IS 32 BIT [20:31] RESERVED
	volatile u_int32_t EMR;  								// REGISTER IS 32 BIT [20:31] RESERVED
	volatile u_int32_t RTSR;  								// REGISTER IS 32 BIT [20:31] RESERVED
	volatile u_int32_t FTSR;  								// REGISTER IS 32 BIT [20:31] RESERVED
	volatile u_int32_t SWIER;  								// REGISTER IS 32 BIT [20:31] RESERVED
	volatile u_int32_t PR;  								// REGISTER IS 32 BIT [20:31] RESERVED


}EXTI_Typedef;


//AFIO REGISTERS

typedef struct{
	volatile u_int32_t EVCR;  								// REGISTER IS 32 BIT [7:31] RESERVED
	volatile u_int32_t MAPR;
	volatile u_int32_t EXTICR[4];  							// REGISTER IS 32 BIT [16:31] RESERVED
	//volatile u_int32_t EXTICR2;  							// REGISTER IS 32 BIT [16:31] RESERVED
	//volatile u_int32_t EXTICR3;  							// REGISTER IS 32 BIT [16:31] RESERVED
	//volatile u_int32_t EXTICR4;  							// REGISTER IS 32 BIT [16:31] RESERVED
			 u_int32_t RESERVED;							//0X18 NOT ALLOW TO ACCESS
	volatile u_int32_t MAPR2;								//0X1C

}AFIO_Typedef;


//USART REGISTERS
typedef struct{

	volatile u_int32_t SR;  								// REGISTER IS 32 BIT [10:31] RESERVED
	volatile u_int32_t DR;  								// REGISTER IS 32 BIT [9:31] RESERVED
	volatile u_int32_t BRR;  								// REGISTER IS 32 BIT [16:31] RESERVED
	volatile u_int32_t CR1;  								// REGISTER IS 32 BIT [14:31] RESERVED
	volatile u_int32_t CR2;  								// REGISTER IS 32 BIT [15:31] RESERVED
	volatile u_int32_t CR3;  								// REGISTER IS 32 BIT [11:31] RESERVED
	volatile u_int32_t GTPR;  								// REGISTER IS 32 BIT [16:31] RESERVED


}USART_Typedef;


//SPI REGISTERS
typedef struct{

	volatile u_int32_t CR1;  								// REGISTER IS 32 BIT [16:31] RESERVED
	volatile u_int32_t CR2;  								// REGISTER IS 32 BIT [8:31] & [3:4] RESERVED
	volatile u_int32_t SR;  								// REGISTER IS 32 BIT [8:31] RESERVED
	volatile u_int32_t DR;  								// REGISTER IS 32 BIT [16:31] RESERVED
	volatile u_int32_t CRCPR;  								// REGISTER IS 32 BIT [16:31] RESERVED
	volatile u_int32_t RXCRCR;  							// REGISTER IS 32 BIT [16:31] RESERVED
	volatile u_int32_t TXCRCR;  							// REGISTER IS 32 BIT [16:31] RESERVED
	volatile u_int32_t I2SCFGR;  							// REGISTER IS 32 BIT [12:31] RESERVED
	volatile u_int32_t I2SPR; 	 							// REGISTER IS 32 BIT [10:31] RESERVED


}SPI_Typedef;
//*******************************************************************************************************//

//PERIPHERALS INSTANTS (CASTING STRUCT AS POINTER TO PERIPHERALS BASE ADDRESSES)

#define GPIOA			((GPIO_Typedef *)GPIOA_BASE)
#define GPIOB			((GPIO_Typedef *)GPIOB_BASE)
#define GPIOC			((GPIO_Typedef *)GPIOC_BASE)
#define GPIOD			((GPIO_Typedef *)GPIOD_BASE)
#define GPIOE			((GPIO_Typedef *)GPIOE_BASE)
#define EXTI			((EXTI_Typedef *)EXTI_BASE)
#define AFIO			((AFIO_Typedef *)AFIO_BASE)
#define RCC				((RCC_Typedef *)RCC_BASE)
#define USART1			((USART_Typedef *)USART1_BASE)
#define USART2			((USART_Typedef *)USART2_BASE)
#define USART3			((USART_Typedef *)USART3_BASE)
#define SPI1			((SPI_Typedef *)SPI1_BASE)
#define SPI2			((SPI_Typedef *)SPI2_BASE)
#define SPI3			((SPI_Typedef *)SPI3_BASE)

//********************************************************************************************************//

//CLOCK ENABLE GPIO MACROS

#define RCC_GPIOA_CLK_EN()	(RCC->APB2ENR |= 1<<2)		// IO PORT A ENABLE
#define RCC_GPIOB_CLK_EN()	(RCC->APB2ENR |= 1<<3)		// IO PORT B ENABLE
#define RCC_GPIOC_CLK_EN()	(RCC->APB2ENR |= 1<<4)		// IO PORT C ENABLE
#define RCC_GPIOD_CLK_EN()	(RCC->APB2ENR |= 1<<5)		// IO PORT D ENABLE
#define RCC_GPIOE_CLK_EN()	(RCC->APB2ENR |= 1<<6)		// IO PORT E ENABLE
#define AFIO_CLK_EN()		(RCC->APB2ENR |= 1<<0)		// ALTERNATIVE FUNCTION IO ENABLE

//********************************************************************************************************//

//CLOCK ENABLE USART MACROS

#define RCC_USART1_CLK_EN()	(RCC->APB2ENR |= 1<<14)		//APB2 BUS
#define RCC_USART2_CLK_EN()	(RCC->APB1ENR |= 1<<17)		//APB1 BUS
#define RCC_USART3_CLK_EN()	(RCC->APB2ENR |= 1<<18)		//APB1 BUS


//********************************************************************************************************//

//CLOCK RESET USART MACROS

#define RCC_USART1_CLK_RESET()	(RCC->APB2RSTR |= 1<<14)		//APB2 BUS
#define RCC_USART2_CLK_RESET()	(RCC->APB1RSTR |= 1<<17)		//APB1 BUS
#define RCC_USART3_CLK_RESET()	(RCC->APB1RSTR |= 1<<18)		//APB1 BUS

//********************************************************************************************************//

//CLOCK ENABLE SPI MACROS

#define RCC_SPI1_CLK_EN()	(RCC->APB2ENR |= 1<<12)			//APB2 BUS
#define RCC_SPI2_CLK_EN()	(RCC->APB1ENR |= 1<<14)			//APB1 BUS
#define RCC_SPI3_CLK_EN()	(RCC->APB1ENR |= 1<<15)			//APB1 BUS



//********************************************************************************************************//

//CLOCK RESET SPI MACROS

#define RCC_SPI1_CLK_RESET()	(RCC->APB2RSTR |= 1<<12)			//APB2 BUS
#define RCC_SPI2_CLK_RESET()	(RCC->APB1RSTR |= 1<<14)		//APB1 BUS
#define RCC_SPI3_CLK_RESET()	(RCC->APB1RSTR |= 1<<15)		//APB1 BUS


//********************************************************************************************************//

//NVIC ADDRESSES  						(ADDRESSES @ CORTEX-M3 TRM)
#define NVIC_BASE								0xE000E100UL							//NVIC CONTROL  BASE
#define NVIC_ISER0						*(volatile uint32_t *)(NVIC_BASE + 0x000)		//INTERRUPT SET ENABLE REGISTER
#define NVIC_ISER1						*(volatile uint32_t *)(NVIC_BASE + 0x004)
#define NVIC_ISER2						*(volatile uint32_t *)(NVIC_BASE + 0x008)
#define NVIC_ICER0						*(volatile uint32_t *)(NVIC_BASE + 0x080)		//INTERRUPT CLEAR ENABLE REGISTER
#define NVIC_ICER1						*(volatile uint32_t *)(NVIC_BASE + 0x084)
#define NVIC_ICER2						*(volatile uint32_t *)(NVIC_BASE + 0x088)

//NVIC IRQ MACROS EXTI ENABLE & DISABLE
#define NVIC_IRQ6_EXTI0_ENABLE						(NVIC_ISER0 |= 1<< 6)		//NOTE EXTI0_IRQ @ BIT NUMBER 6
#define NVIC_IRQ7_EXTI1_ENABLE						(NVIC_ISER0 |= 1<< 7)		//NOTE EXTI1_IRQ @ BIT NUMBER 7
#define NVIC_IRQ8_EXTI2_ENABLE						(NVIC_ISER0 |= 1<< 8)		//NOTE EXTI2_IRQ @ BIT NUMBER 8
#define NVIC_IRQ9_EXTI3_ENABLE						(NVIC_ISER0 |= 1<< 9)		//NOTE EXTI3_IRQ @ BIT NUMBER 9
#define NVIC_IRQ10_EXTI4_ENABLE						(NVIC_ISER0 |= 1<< 10)		//NOTE EXTI4_IRQ @ BIT NUMBER 10
#define NVIC_IRQ23_EXTI5_9_ENABLE					(NVIC_ISER0 |= 1<< 23)		//NOTE EXTI5:9_IRQ @ BIT NUMBER 23
#define NVIC_IRQ40_EXTI10_15_ENABLE					(NVIC_ISER1 |= 1<< 8)		//NOTE EXTI10:15_IRQ @ BIT NUMBER 40-32=8


#define NVIC_IRQ6_EXTI0_DISABLE						(NVIC_ICER0 |= 1<< 6)		//NOTE EXTI0_IRQ @ BIT NUMBER 6
#define NVIC_IRQ7_EXTI1_DISABLE						(NVIC_ICER0 |= 1<< 7)		//NOTE EXTI1_IRQ @ BIT NUMBER 7
#define NVIC_IRQ8_EXTI2_DISABLE						(NVIC_ICER0 |= 1<< 8)		//NOTE EXTI2_IRQ @ BIT NUMBER 8
#define NVIC_IRQ9_EXTI3_DISABLE						(NVIC_ICER0 |= 1<< 9)		//NOTE EXTI3_IRQ @ BIT NUMBER 9
#define NVIC_IRQ10_EXTI4_DISABLE					(NVIC_ICER0 |= 1<< 10)		//NOTE EXTI4_IRQ @ BIT NUMBER 10
#define NVIC_IRQ23_EXTI5_9_DISABLE					(NVIC_ICER0 |= 1<< 23)		//NOTE EXTI5:9_IRQ @ BIT NUMBER 23
#define NVIC_IRQ40_EXTI10_15_DISABLE				(NVIC_ICER1 |= 1<< 8)		//NOTE EXTI10:15_IRQ @ BIT NUMBER 40-32=8

//NVIC IRQ MACROS USART ENABLE & DISABLE

#define NVIC_IRQ37_EUSART1_ENABLE					(NVIC_ISER1 |= 1<<(USART1_IRQ - 32))		//NOTE USART1_IRQ @ BIT NUMBER 37-32=5
#define NVIC_IRQ38_EUSART2_ENABLE					(NVIC_ISER1 |= 1<<(USART2_IRQ - 32))		//NOTE USART1_IRQ @ BIT NUMBER 38-32=6
#define NVIC_IRQ39_EUSART3_ENABLE					(NVIC_ISER1 |= 1<<(USART3_IRQ - 32))		//NOTE USART1_IRQ @ BIT NUMBER 39-32=7

#define NVIC_IRQ37_EUSART1_DISABLE					(NVIC_ICER1 |= 1<<(USART1_IRQ - 32))		//NOTE USART1_IRQ @ BIT NUMBER 37-32=5
#define NVIC_IRQ38_EUSART2_DISABLE					(NVIC_ICER1 |= 1<<(USART2_IRQ - 32))		//NOTE USART1_IRQ @ BIT NUMBER 38-32=6
#define NVIC_IRQ39_EUSART3_DISABLE					(NVIC_ICER1 |= 1<<(USART3_IRQ - 32))		//NOTE USART1_IRQ @ BIT NUMBER 39-32=7


//NVIC IRQ MACROS SPI ENABLE & DISABLE

#define NVIC_IRQ35_SPI1_ENABLE					(NVIC_ISER1 |= 1<<(SPI1_IRQ - 32))		//NOTE USART1_IRQ @ BIT NUMBER 35-32=3
#define NVIC_IRQ36_SPI2_ENABLE					(NVIC_ISER1 |= 1<<(SPI2_IRQ - 32))		//NOTE USART1_IRQ @ BIT NUMBER 36-32=4
//#define NVIC_IRQ51_SPI3_ENABLE					(NVIC_ISER1 |= 1<<(SPI3_IRQ - 32))		//NOTE USART1_IRQ @ BIT NUMBER 39-32=7

#define NVIC_IRQ35_SPI1_DISABLE					(NVIC_ICER1 |= 1<<(SPI1_IRQ - 32))		//NOTE USART1_IRQ @ BIT NUMBER 35-32=3
#define NVIC_IRQ36_SPI2_DISABLE					(NVIC_ICER1 |= 1<<(SPI2_IRQ - 32))		//NOTE USART1_IRQ @ BIT NUMBER 36-32=4
//#define NVIC_IRQ51_SPI3_DISABLE					(NVIC_ICER1 |= 1<<(SPI3_IRQ - 32))		//NOTE USART1_IRQ @ BIT NUMBER 39-32=7



//EXTI VECTOR TABLE

#define	EXTI0_IRQ		6
#define	EXTI1_IRQ		7
#define	EXTI2_IRQ		8
#define	EXTI3_IRQ		9
#define	EXTI4_IRQ		10
#define	EXTI5_IRQ		23
#define	EXTI6_IRQ		23
#define	EXTI7_IRQ		23
#define	EXTI8_IRQ		23
#define	EXTI9_IRQ		23
#define	EXTI10_IRQ		40
#define	EXTI11_IRQ		40
#define	EXTI12_IRQ		40
#define	EXTI13_IRQ		40
#define	EXTI14_IRQ		40
#define	EXTI15_IRQ		40
#define	USART1_IRQ		37
#define	USART2_IRQ		38
#define	USART3_IRQ		39
#define	SPI1_IRQ		35
#define	SPI2_IRQ		36
#define	SPI3_IRQ		51







#endif /* INC_STM32F103X6_H_ */
