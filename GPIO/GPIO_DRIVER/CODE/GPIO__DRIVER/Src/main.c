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

#include"STM32F103C6_GPIO_DRIVER.h"
#include"STM32F103X6.h"





void Clock_init(){
	//ENABLE CLOCK GPIOA
	RCC_GPIOA_CLK_EN();
	//ENABLE CLOCK GPIOB
	RCC_GPIOB_CLK_EN();


}
void GPIO_init(){
	GPIO_PINCONFIG_T PINCFG;


	//PA1 AS INPUT HIGH IMPEDANCE(FLOATING)
	PINCFG.GPIO_PIN_NUMBER = GPIO_PIN1;
	PINCFG.GPIO_MODE=GPIO_MODE_FLOATING;
	MCAL_GPIO_INIT(GPIOA, &PINCFG);


	//PB1 AS OUTPUT PUSH-PULL MODE
	//CNF PISH PULL OUTPUT GENERAL REGISTER
	PINCFG.GPIO_PIN_NUMBER = GPIO_PIN1;
	PINCFG.GPIO_MODE=GPIO_MODE_PUSH_PULL;
	PINCFG.GPIO_SPEED_OUTPUT=GPIO_SPEED_10M;
	MCAL_GPIO_INIT(GPIOB, &PINCFG);




	//PA13 AS INPUT HIGH IMPEDANCE(FLOATING)
	PINCFG.GPIO_PIN_NUMBER = GPIO_PIN13;
	PINCFG.GPIO_MODE=GPIO_MODE_FLOATING;
	MCAL_GPIO_INIT(GPIOA, &PINCFG);

	//PB13 AS OUTPUT PUSH-PULL MODE
	PINCFG.GPIO_PIN_NUMBER = GPIO_PIN13;
	PINCFG.GPIO_MODE=GPIO_MODE_PUSH_PULL;
	PINCFG.GPIO_SPEED_OUTPUT=GPIO_SPEED_10M;
	MCAL_GPIO_INIT(GPIOB, &PINCFG);


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
		if	(MCAL_GPIO_READPIN(GPIOA, GPIO_PIN1)	==	0) 		//THAT WE PRESS
		{
			MCAL_GPIO_TOGGLEPIN(GPIOB, GPIO_PIN1);

			while(MCAL_GPIO_READPIN(GPIOA, GPIO_PIN1)	==	0);		//FOR SINGLE PRESS IF CONDITION ALAWYS TRUE
		}
		//PA13 CONNECTED EXTERNAL PDR (PULL DOWN REGISTER)
		if	(MCAL_GPIO_READPIN(GPIOA, GPIO_PIN13)	==	1)			// ==1 BECAUSE IT IS PULL DOWN REGISTER
		{
			MCAL_GPIO_TOGGLEPIN(GPIOB, GPIO_PIN13);
				}
		my_wait(1);

	}
}