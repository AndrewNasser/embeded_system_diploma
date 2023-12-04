/*
 * STM32F103C6_RCC_DRIVER.h
 *
 *  Created on: Jul 7, 2023
 *      Author: Andrew nasser
 */

#ifndef INC_STM32F103C6_RCC_DRIVER_H_
#define INC_STM32F103C6_RCC_DRIVER_H_

#include "STM103C6_HEADERS.H"


#define	HSI_CLCK	(uint32_t)16000000
#define	HSE_CLCK	(uint32_t)8000000

 uint32_t MCAL_RCC_HCLCK_GETFREQ(void);
 uint32_t MCAL_RCC_SYSCLCK_GETFREQ(void);
 uint32_t MCAL_RCC_PCLCK1_GETFREQ(void);
 uint32_t MCAL_RCC_PCLCK2_GETFREQ(void);


#endif /* INC_STM32F103C6_RCC_DRIVER_H_ */
