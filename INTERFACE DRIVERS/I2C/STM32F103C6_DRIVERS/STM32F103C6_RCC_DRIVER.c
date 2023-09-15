/*
 * STM32F103C6_RCC_DRIVER.c
 *
 *  Created on: Jul 7, 2023
 *      Author: King 45M
 */





#include"STM32F103C6_GPIO_DRIVER.h"
#include"STM32F103C6_RCC_DRIVER.h"
#include"STM32F103X6.h"

/*Bits 10:8 PPRE1: APB low-speed prescaler (APB1)
Set and cleared by software to control the division factor of the APB low-speed clock
(PCLK1).
Warning: the software has to set correctly these bits to not exceed 36 MHz on this domain.
0xx: HCLK not divided
100: HCLK divided by 2
101: HCLK divided by 4
110: HCLK divided by 8
111: HCLK divided by 16

Bits 13:11 PPRE2: APB high-speed prescaler (APB2)
Set and cleared by software to control the division factor of the APB high-speed clock
(PCLK2).
0xx: HCLK not divided
100: HCLK divided by 2
101: HCLK divided by 4
110: HCLK divided by 8
111: HCLK divided by 16


Bits 7:4 HPRE: AHB prescaler
Set and cleared by software to control the division factor of the AHB clock.
0xxx: SYSCLK not divided
1000: SYSCLK divided by 2
1001: SYSCLK divided by 4
1010: SYSCLK divided by 8
1011: SYSCLK divided by 16
1100: SYSCLK divided by 64
1101: SYSCLK divided by 128
1110: SYSCLK divided by 256
1111: SYSCLK divided by 512


Bits 3:2 SWS: System clock switch status
Set and cleared by hardware to indicate which clock source is used as system clock.
00: HSI oscillator used as system clock
01: HSE oscillator used as system clock
10: PLL used as system clock
11: not applicable*/


const uint8_t APBPRESC_TABLE[8U]={0,0,0,0,1,2,3,4};		//AT INDEX 4 (100) THE SHIFT =1 ---> 2^1  DEVIDED BY 2
														//AT INDEX 5 (101) THE SHIFT =2 ---> 2^2  DEVIDED BY 4
const uint8_t AHBPRESC_TABLE[17U]={0,0,0,0,0,0,0,0,1,2,3,4,5,6,7,8,9};



/*======================================================================================================
 * FUNC NAME ----> MCAL_RCC_SYSCLCK_GETFREQ
 * BRIEF     ----> USE TO GET THE FIRST CLCK
 * PARAM1[IN]----> NUMBER OF PIN
 * RETAVAL	 ----> POSITION IN CR REGISTER
 * NOTE		 ----> EACH PIN HAVE 4 BIT IN CR REGISTER
 *
 */

 uint32_t MCAL_RCC_SYSCLCK_GETFREQ(void){
	 switch((RCC->CFGR >> 2) & 0b11){
		 case 0:
			 return HSI_CLCK;
			 break;
		 case 1:
			 return HSE_CLCK;
			 break;
		 case 2:
			 return 16000000;
			 break;
	 }

 }
 uint32_t MCAL_RCC_HCLCK_GETFREQ(void){
 	 return (MCAL_RCC_SYSCLCK_GETFREQ()	>>	AHBPRESC_TABLE[(RCC->CFGR >> 4) & 0xF]);

 }

 uint32_t MCAL_RCC_PCLCK1_GETFREQ(void){
	 	 return (MCAL_RCC_HCLCK_GETFREQ()	>>	APBPRESC_TABLE[(RCC->CFGR >> 8) & 0b111]);
 }
 uint32_t MCAL_RCC_PCLCK2_GETFREQ(void){
		return (MCAL_RCC_HCLCK_GETFREQ()	>>	APBPRESC_TABLE[(RCC->CFGR >> 11) & 0b111]);

 }
