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



//I2C BASE ADRESSES
#define I2C1_BASE						0x40005400UL
#define I2C2_BASE						0x40005800UL

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




//I2C REGISTERS

typedef struct{
	volatile u_int32_t CR1;  								// REGISTER IS 32 BIT [16:31],14 & 2 RESERVED
	volatile u_int32_t CR2;  								// REGISTER IS 32 BIT [13:31],6 & 7 RESERVED
	volatile u_int32_t OAR1;  								// REGISTER IS 32 BIT [16:31] & [10:14] RESERVED
	volatile u_int32_t OAR2;  								// REGISTER IS 32 BIT [8:31] RESERVED
	volatile u_int32_t DR;  								// REGISTER IS 32 BIT [8:31] RESERVED
	volatile u_int32_t SR1;  								// REGISTER IS 32 BIT [16:31] RESERVED
	volatile u_int32_t SR2;  								// REGISTER IS 32 BIT [16:31] & 3 RESERVED
	volatile u_int32_t CCR;  								// REGISTER IS 32 BIT [16:31] RESERVED
	volatile u_int32_t TRISE;  								// REGISTER IS 32 BIT [6:31] RESERVED


}I2C_Typedef;

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
#define I2C1			((I2C_Typedef *)I2C1_BASE)
#define I2C2			((I2C_Typedef *)I2C2_BASE)
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

//CLOCK ENABLE I2C MACROS

#define RCC_I2C1_CLK_EN()	(RCC->APB1ENR |= 1<<21)			//APB1 BUS
#define RCC_I2C2_CLK_EN()	(RCC->APB1ENR |= 1<<22)			//APB1 BUS

//********************************************************************************************************//
//CLOCK RESET I2C MACROS

#define RCC_I2C1_CLK_RESET()	(RCC->APB1RSTR |= 1<<21)		//APB1 BUS
#define RCC_I2C2_CLK_RESET()	(RCC->APB1RSTR |= 1<<22)		//APB1 BUS



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

#define NVIC_IRQ35_SPI1_ENABLE					(NVIC_ISER1 |= 1<<(SPI1_IRQ - 32))		//NOTE SPI1_IRQ @ BIT NUMBER 35-32=3
#define NVIC_IRQ36_SPI2_ENABLE					(NVIC_ISER1 |= 1<<(SPI2_IRQ - 32))		//NOTE SPI2_IRQ @ BIT NUMBER 36-32=4
//#define NVIC_IRQ51_SPI3_ENABLE					(NVIC_ISER1 |= 1<<(SPI3_IRQ - 32))		//NOTE USART1_IRQ @ BIT NUMBER 39-32=7

#define NVIC_IRQ35_SPI1_DISABLE					(NVIC_ICER1 |= 1<<(SPI1_IRQ - 32))		//NOTE SPI_IRQ @ BIT NUMBER 35-32=3
#define NVIC_IRQ36_SPI2_DISABLE					(NVIC_ICER1 |= 1<<(SPI2_IRQ - 32))		//NOTE SPI_IRQ @ BIT NUMBER 36-32=4
//#define NVIC_IRQ51_SPI3_DISABLE					(NVIC_ICER1 |= 1<<(SPI3_IRQ - 32))		//NOTE USART1_IRQ @ BIT NUMBER 39-32=7

//NVIC IRQ MACROS I2C ENABLE & DISABLE

#define NVIC_IRQ31_I2C1_EV_ENABLE						(NVIC_ISER0 |= 1<<(I2C1_EV_IRQ))			//NOTE I2C1 @ BIT NUMBER 31
#define NVIC_IRQ32_I2C1_ER_ENABLE						(NVIC_ISER1 |= 1<<(I2C1_ER_IRQ - 32))		//NOTE I2C1 @ BIT NUMBER 36-32=4
#define NVIC_IRQ33_I2C2_EV_ENABLE						(NVIC_ISER1 |= 1<<(I2C2_EV_IRQ - 32))		//NOTE I2C2 @ BIT NUMBER 36-32=4
#define NVIC_IRQ34_I2C2_ER_ENABLE						(NVIC_ISER1 |= 1<<(I2C2_ER_IRQ - 32))		//NOTE I2C2 @ BIT NUMBER 36-32=4


#define NVIC_IRQ31_I2C1_EV_DISABLE						(NVIC_ICER0 |= 1<<(I2C1_EV_IRQ))			//NOTE I2C1 @ BIT NUMBER 31
#define NVIC_IRQ32_I2C1_ER_DISABLE						(NVIC_ICER1 |= 1<<(I2C1_ER_IRQ - 32))		//NOTE I2C1 @ BIT NUMBER 36-32=4
#define NVIC_IRQ33_I2C2_EV_DISABLE						(NVIC_ICER1 |= 1<<(I2C2_EV_IRQ - 32))		//NOTE I2C2 @ BIT NUMBER 36-32=4
#define NVIC_IRQ34_I2C2_ER_DISABLE						(NVIC_ICER1 |= 1<<(I2C2_ER_IRQ - 32))		//NOTE I2C2 @ BIT NUMBER 36-32=4
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
#define	I2C1_EV_IRQ		31
#define	I2C1_ER_IRQ		32
#define	I2C2_EV_IRQ		33
#define	I2C2_ER_IRQ		34



//**********************************************************REGISTER DEFINATION FOR I2C*************************************************************//
//**************************************************************************************************************************************************//





/******************* BIT DEFINATION FOR I2C_CR1 REGISTER  ********************/


#define I2C_CR1_PE_POS                      (0U)
#define I2C_CR1_PE_MASK                     (0x1UL << I2C_CR1_PE_POS)           /*!< 0x00000001 */
#define I2C_CR1_PE                          I2C_CR1_PE_MASK                     /*!< Peripheral Enable */
#define I2C_CR1_SMBUS_POS                   (1U)
#define I2C_CR1_SMBUS_MASK                  (0x1UL << I2C_CR1_SMBUS_POS)        /*!< 0x00000002 */
#define I2C_CR1_SMBUS                       I2C_CR1_SMBUS_MASK                  /*!< SMBus Mode */
#define I2C_CR1_SMBTYPE_POS                 (3U)
#define I2C_CR1_SMBTYPE_MASK                (0x1UL << I2C_CR1_SMBTYPE_POS)      /*!< 0x00000008 */
#define I2C_CR1_SMBTYPE                     I2C_CR1_SMBTYPE_MASK                /*!< SMBus Type */
#define I2C_CR1_ENARP_POS                   (4U)
#define I2C_CR1_ENARP_MASK                  (0x1UL << I2C_CR1_ENARP_POS)        /*!< 0x00000010 */
#define I2C_CR1_ENARP                       I2C_CR1_ENARP_MASK                  /*!< ARP Enable */
#define I2C_CR1_ENPEC_POS                   (5U)
#define I2C_CR1_ENPEC_MASK                  (0x1UL << I2C_CR1_ENPEC_POS)        /*!< 0x00000020 */
#define I2C_CR1_ENPEC                       I2C_CR1_ENPEC_MASK                  /*!< PEC Enable */
#define I2C_CR1_ENGC_POS                    (6U)
#define I2C_CR1_ENGC_MASK                   (0x1UL << I2C_CR1_ENGC_POS)         /*!< 0x00000040 */
#define I2C_CR1_ENGC                        I2C_CR1_ENGC_MASK                   /*!< General Call Enable */
#define I2C_CR1_NOSTRETCH_POS               (7U)
#define I2C_CR1_NOSTRETCH_MASK              (0x1UL << I2C_CR1_NOSTRETCH_POS)    /*!< 0x00000080 */
#define I2C_CR1_NOSTRETCH                   I2C_CR1_NOSTRETCH_MASK              /*!< Clock Stretching Disable (Slave mode) */
#define I2C_CR1_START_POS                   (8U)
#define I2C_CR1_START_MASK                  (0x1UL << I2C_CR1_START_POS)        /*!< 0x00000100 */
#define I2C_CR1_START                       I2C_CR1_START_MASK                  /*!< Start Generation */
#define I2C_CR1_STOP_POS                    (9U)
#define I2C_CR1_STOP_MASK                   (0x1UL << I2C_CR1_STOP_POS)         /*!< 0x00000200 */
#define I2C_CR1_STOP                        I2C_CR1_STOP_MASK                   /*!< Stop Generation */
#define I2C_CR1_ACK_POS                     (10U)
#define I2C_CR1_ACK_MASK                    (0x1UL << I2C_CR1_ACK_POS)          /*!< 0x00000400 */
#define I2C_CR1_ACK                         I2C_CR1_ACK_MASK                    /*!< Acknowledge Enable */
#define I2C_CR1_POS_POS                     (11U)
#define I2C_CR1_POS_MASK                    (0x1UL << I2C_CR1_POS_POS)          /*!< 0x00000800 */
#define I2C_CR1_POS                         I2C_CR1_POS_MASK                    /*!< Acknowledge/PEC POSition (for data reception) */
#define I2C_CR1_PEC_POS                     (12U)
#define I2C_CR1_PEC_MASK                    (0x1UL << I2C_CR1_PEC_POS)          /*!< 0x00001000 */
#define I2C_CR1_PEC                         I2C_CR1_PEC_MASK                    /*!< Packet Error Checking */
#define I2C_CR1_ALERT_POS                   (13U)
#define I2C_CR1_ALERT_MASK                  (0x1UL << I2C_CR1_ALERT_POS)        /*!< 0x00002000 */
#define I2C_CR1_ALERT                       I2C_CR1_ALERT_MASK                  /*!< SMBus Alert */
#define I2C_CR1_SWRST_POS                   (15U)
#define I2C_CR1_SWRST_MASK                  (0x1UL << I2C_CR1_SWRST_POS)        /*!< 0x00008000 */
#define I2C_CR1_SWRST                       I2C_CR1_SWRST_MASK                  /*!< Software Reset */



/*******************  BIT DEFINATION FOR I2C_CR2 REGISTER  ********************/



#define I2C_CR2_FREQ_POS                    (0U)
#define I2C_CR2_FREQ_MASK                   (0x3FUL << I2C_CR2_FREQ_POS)        /*!< 0x0000003F */
#define I2C_CR2_FREQ                        I2C_CR2_FREQ_MASK                   /*!< FREQ[5:0] bits (Peripheral Clock Frequency) */
#define I2C_CR2_ITERREN_POS                 (8U)
#define I2C_CR2_ITERREN_MASK                (0x1UL << I2C_CR2_ITERREN_POS)      /*!< 0x00000100 */
#define I2C_CR2_ITERREN                     I2C_CR2_ITERREN_MASK                /*!< Error Interrupt Enable */
#define I2C_CR2_ITEVTEN_POS                 (9U)
#define I2C_CR2_ITEVTEN_MASK                (0x1UL << I2C_CR2_ITEVTEN_POS)      /*!< 0x00000200 */
#define I2C_CR2_ITEVTEN                     I2C_CR2_ITEVTEN_MASK                /*!< Event Interrupt Enable */
#define I2C_CR2_ITBUFEN_POS                 (10U)
#define I2C_CR2_ITBUFEN_MASK                (0x1UL << I2C_CR2_ITBUFEN_POS)      /*!< 0x00000400 */
#define I2C_CR2_ITBUFEN                     I2C_CR2_ITBUFEN_MASK                /*!< Buffer Interrupt Enable */
#define I2C_CR2_DMAEN_POS                   (11U)
#define I2C_CR2_DMAEN_MASK                  (0x1UL << I2C_CR2_DMAEN_POS)        /*!< 0x00000800 */
#define I2C_CR2_DMAEN                       I2C_CR2_DMAEN_MASK                  /*!< DMA Requests Enable */
#define I2C_CR2_LAST_POS                    (12U)
#define I2C_CR2_LAST_MASK                   (0x1UL << I2C_CR2_LAST_POS)         /*!< 0x00001000 */
#define I2C_CR2_LAST                        I2C_CR2_LAST_MASK                   /*!< DMA Last Transfer */



/*******************  BIT DEFINATION FOR I2C_OAR2 REGISTER  *******************/


#define I2C_OAR2_ENDUAL_POS                 (0U)
#define I2C_OAR2_ENDUAL_MASK                (0x1UL << I2C_OAR2_ENDUAL_POS)      /*!< 0x00000001 */
#define I2C_OAR2_ENDUAL                     I2C_OAR2_ENDUAL_MASK                /*!< Dual addressing mode enable */
#define I2C_OAR2_ADD2_POS                   (1U)



/*******************  BIT DEFINATION FOR I2C_SR1 REGISTER  ********************/



#define I2C_SR1_SB_POS                      (0U)
#define I2C_SR1_SB_MASK                     (0x1UL << I2C_SR1_SB_POS)           /*!< 0x00000001 */
#define I2C_SR1_SB                          I2C_SR1_SB_MASK                     /*!< Start Bit (Master mode) */
#define I2C_SR1_ADDR_POS                    (1U)
#define I2C_SR1_ADDR_MASK                   (0x1UL << I2C_SR1_ADDR_POS)         /*!< 0x00000002 */
#define I2C_SR1_ADDR                        I2C_SR1_ADDR_MASK                   /*!< Address sent (master mode)/matched (slave mode) */
#define I2C_SR1_BTF_POS                     (2U)
#define I2C_SR1_BTF_MASK                    (0x1UL << I2C_SR1_BTF_POS)          /*!< 0x00000004 */
#define I2C_SR1_BTF                         I2C_SR1_BTF_MASK                    /*!< Byte Transfer Finished */
#define I2C_SR1_ADD10_POS                   (3U)
#define I2C_SR1_ADD10_MASK                  (0x1UL << I2C_SR1_ADD10_POS)        /*!< 0x00000008 */
#define I2C_SR1_ADD10                       I2C_SR1_ADD10_MASK                  /*!< 10-bit header sent (Master mode) */
#define I2C_SR1_STOPF_POS                   (4U)
#define I2C_SR1_STOPF_MASK                  (0x1UL << I2C_SR1_STOPF_POS)        /*!< 0x00000010 */
#define I2C_SR1_STOPF                       I2C_SR1_STOPF_MASK                  /*!< Stop detection (Slave mode) */
#define I2C_SR1_RXNE_POS                    (6U)
#define I2C_SR1_RXNE_MASK                   (0x1UL << I2C_SR1_RXNE_POS)         /*!< 0x00000040 */
#define I2C_SR1_RXNE                        I2C_SR1_RXNE_MASK                   /*!< Data Register not Empty (receivers) */
#define I2C_SR1_TXE_POS                     (7U)
#define I2C_SR1_TXE_MASK                    (0x1UL << I2C_SR1_TXE_POS)          /*!< 0x00000080 */
#define I2C_SR1_TXE                         I2C_SR1_TXE_MASK                    /*!< Data Register Empty (transmitters) */
#define I2C_SR1_BERR_POS                    (8U)
#define I2C_SR1_BERR_MASK                   (0x1UL << I2C_SR1_BERR_POS)         /*!< 0x00000100 */
#define I2C_SR1_BERR                        I2C_SR1_BERR_MASK                   /*!< Bus Error */
#define I2C_SR1_ARLO_POS                    (9U)
#define I2C_SR1_ARLO_MASK                   (0x1UL << I2C_SR1_ARLO_POS)         /*!< 0x00000200 */
#define I2C_SR1_ARLO                        I2C_SR1_ARLO_MASK                   /*!< Arbitration Lost (master mode) */
#define I2C_SR1_AF_POS                      (10U)
#define I2C_SR1_AF_MASK                     (0x1UL << I2C_SR1_AF_POS)           /*!< 0x00000400 */
#define I2C_SR1_AF                          I2C_SR1_AF_MASK                     /*!< Acknowledge Failure */
#define I2C_SR1_OVR_POS                     (11U)
#define I2C_SR1_OVR_MASK                    (0x1UL << I2C_SR1_OVR_POS)          /*!< 0x00000800 */
#define I2C_SR1_OVR                         I2C_SR1_OVR_MASK                    /*!< Overrun/Underrun */
#define I2C_SR1_PECERR_POS                  (12U)
#define I2C_SR1_PECERR_MASK                 (0x1UL << I2C_SR1_PECERR_POS)       /*!< 0x00001000 */
#define I2C_SR1_PECERR                      I2C_SR1_PECERR_MASK                 /*!< PEC Error in reception */
#define I2C_SR1_TIMEOUT_POS                 (14U)
#define I2C_SR1_TIMEOUT_MASK                (0x1UL << I2C_SR1_TIMEOUT_POS)      /*!< 0x00004000 */
#define I2C_SR1_TIMEOUT                     I2C_SR1_TIMEOUT_MASK                /*!< Timeout or Tlow Error */
#define I2C_SR1_SMBALERT_POS                (15U)
#define I2C_SR1_SMBALERT_MASK               (0x1UL << I2C_SR1_SMBALERT_POS)     /*!< 0x00008000 */
#define I2C_SR1_SMBALERT                    I2C_SR1_SMBALERT_MASK               /*!< SMBus Alert */




/*******************  BIT DEFINATION FOR I2C_SR2 REGISTER  ********************/



#define I2C_SR2_MSL_POS                     (0U)
#define I2C_SR2_MSL_MASK                    (0x1UL << I2C_SR2_MSL_POS)          /*!< 0x00000001 */
#define I2C_SR2_MSL                         I2C_SR2_MSL_MASK                    /*!< Master/Slave */
#define I2C_SR2_BUSY_POS                    (1U)
#define I2C_SR2_BUSY_MASK                   (0x1UL << I2C_SR2_BUSY_POS)         /*!< 0x00000002 */
#define I2C_SR2_BUSY                        I2C_SR2_BUSY_MASK                   /*!< Bus Busy */
#define I2C_SR2_TRA_POS                     (2U)
#define I2C_SR2_TRA_MASK                    (0x1UL << I2C_SR2_TRA_POS)          /*!< 0x00000004 */
#define I2C_SR2_TRA                         I2C_SR2_TRA_MASK                    /*!< Transmitter/Receiver */
#define I2C_SR2_GENCALL_POS                 (4U)
#define I2C_SR2_GENCALL_MASK                (0x1UL << I2C_SR2_GENCALL_POS)      /*!< 0x00000010 */
#define I2C_SR2_GENCALL                     I2C_SR2_GENCALL_MASK                /*!< General Call Address (Slave mode) */
#define I2C_SR2_SMBDEFAULT_POS              (5U)
#define I2C_SR2_SMBDEFAULT_MASK             (0x1UL << I2C_SR2_SMBDEFAULT_POS)   /*!< 0x00000020 */
#define I2C_SR2_SMBDEFAULT                  I2C_SR2_SMBDEFAULT_MASK             /*!< SMBus Device Default Address (Slave mode) */
#define I2C_SR2_SMBHOST_POS                 (6U)
#define I2C_SR2_SMBHOST_MASK                (0x1UL << I2C_SR2_SMBHOST_POS)      /*!< 0x00000040 */
#define I2C_SR2_SMBHOST                     I2C_SR2_SMBHOST_MASK                /*!< SMBus Host Header (Slave mode) */
#define I2C_SR2_DUALF_POS                   (7U)
#define I2C_SR2_DUALF_MASK                  (0x1UL << I2C_SR2_DUALF_POS)        /*!< 0x00000080 */
#define I2C_SR2_DUALF                       I2C_SR2_DUALF_MASK                  /*!< Dual Flag (Slave mode) */
#define I2C_SR2_PEC_POS                     (8U)
#define I2C_SR2_PEC_MASK                    (0xFFUL << I2C_SR2_PEC_POS)         /*!< 0x0000FF00 */
#define I2C_SR2_PEC                         I2C_SR2_PEC_MASK                    /*!< Packet Error Checking Register */


#endif /* INC_STM32F103X6_H_ */
