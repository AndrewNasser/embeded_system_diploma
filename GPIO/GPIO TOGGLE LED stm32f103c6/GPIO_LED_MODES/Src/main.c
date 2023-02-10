/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

typedef volatile unsigned int vuint32_t ;
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

//RCC ADDRESS
#define RCC_BASE   0x40021000
#define RCC_APB2ENR	*((volatile uint32_t*) (RCC_BASE+0x18))
//GPIO ADDRESS
#define GPIOA_BASE	0x40010800
#define GPIOA_CRH    *((volatile uint32_t*) (GPIOA_BASE+0x04))
#define GPIOA_CRL    *((volatile uint32_t*) (GPIOA_BASE+0x00))
#define GPIOA_ODR    *((volatile uint32_t*) (GPIOA_BASE+0x0C))
#define GPIOA_IDR    *((volatile uint32_t*) (GPIOA_BASE+0x08))



#define GPIOB_BASE	0x40010C00
#define GPIOB_CRH    *((volatile uint32_t*) (GPIOB_BASE+0x04))
#define GPIOB_CRL    *((volatile uint32_t*) (GPIOB_BASE+0x00))
#define GPIOB_ODR    *((volatile uint32_t*) (GPIOB_BASE+0x0C))
#define GPIOB_IDR    *((volatile uint32_t*) (GPIOB_BASE+0x08))




void Clock_init(){
	//ENABLE CLOCK GPIOA
	RCC_APB2ENR|= (1<<2);
	//ENABLE CLOCK GPIOB
	RCC_APB2ENR|= (1<<3);


}
void GPIO_init(){
	GPIOA_CRL = 0x00;
	GPIOB_CRL = 0x00;
	GPIOA_CRH = 0x00;
	GPIOA_ODR = 0x00;

	//PA1 AS INPUT HIGH IMPEDANCE(FLOATING)
	GPIOA_CRL &= ~(0b11<<4);
	GPIOA_CRL |= (0b01<<6);

	//PB1 AS OUTPUT PUSH-PULL MODE
	//CNF PISH PULL OUTPUT GENERAL REGISTER
	GPIOB_CRL &=~(0b11<<6);
	//OUTPUT MODE MAX SPEED 12MHZ
	GPIOB_CRL |= (0b01<<4);



	//PA13 AS INPUT HIGH IMPEDANCE(FLOATING)
	GPIOA_CRH &= ~(0b11<<20);
	GPIOA_CRH |= (0b01<<22);

	//PB13 AS OUTPUT PUSH-PULL MODE
	GPIOB_CRH |= (0b01<<20);
	GPIOB_CRH &= ~(0b11<<22);


}
void my_wait(int x){
	unsigned int i , j;
	for(i=0;i<x;i++){
		for(j=0;j<255;j++);
	}
}
int main(void)
{
	Clock_init();
	GPIO_init();




	while(1)	{
		//PA1 CONNECTED EXTERNAL PUR (PULL UP REGISTER)
		if	(((GPIOA_IDR &(1<<1)) >>1) == 0){
			GPIOB_ODR ^= 1<<1;
			//FOR SINGLE PRESS
			while(((GPIOA_IDR &(1<<1)) >> 1) ==0);
		}
		//PA13 CONNECTED EXTERNAL PDR (PULL DOWN REGISTER)
		if	(((GPIOA_IDR &(1<<13)) >>13) ==1){
					GPIOB_ODR ^=( 1<<13); 		//MULTIPRESSING

				}
		my_wait(1);

	}
}
