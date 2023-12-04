/*
 * STM32F103C6_GPIO_DRIVER.h
 *
 *  Created on: Mar 20, 2023
 *      Author:ANDREW NASSER
 */

#ifndef INC_STM32F103C6_EXTI_DRIVER_H_
#define INC_STM32F103C6_EXTI_DRIVER_H_

//INCLUDES

#include "STM103C6_HEADERS.H"

typedef struct{
	uint16_t		EXTI_INPUT_NUM;
	GPIO_Typedef *	GPIO_PORT;
	uint16_t		GPIO_PIN;
	uint8_t			IVT_IRQ_NUMBER;

}EXTI_GPIO_MAPING_t;


typedef struct{
	EXTI_GPIO_MAPING_t EXTI_PIN; 	 //SET PORT USING FOR EXTI FROM VECTPRED MACROS TABLE

	uint8_t TRIGGER_CASE;		 	 //SELECT CASE FROM EXTI_TRIGGER_CONDITIONS (RAISING EDGE - FALLING EDGE - RAISING FALLING)

	uint8_t IRQ_STATE;				 //SELECT FROM EXTI_STATES RELFLECTED TO IRQ MASK & NVIC INTERRUPT CONTROL

	void(* P_IRQ_CALLBACK)(void);	  //POINTER TO FUNCTION ---> SET THE FUNCTION WHICH WILL BE CALLED ONCE IRQ HAPPEN

}EXTI_PINCONFIG_t;



//EXTI DEFINE MACROS
#define EXTI0		0
#define EXTI1		1
#define EXTI2		2
#define EXTI3		3
#define EXTI4		4
#define EXTI5		5
#define EXTI6		6
#define EXTI7		7
#define EXTI8		8
#define EXTI9		9
#define EXTI10		10
#define EXTI11		11
#define EXTI12		12
#define EXTI13		13
#define EXTI14		14
#define EXTI15		15


//***********************VECTORED MACROS TABLE***********************//


 //EXTI0
#define EXII0_PA0	(EXTI_GPIO_MAPING_t){EXTI0,GPIOA,GPIO_PIN0,EXTI0_IRQ}
#define EXTI0_PB0	(EXTI_GPIO_MAPING_t){EXTI0,GPIOB,GPIO_PIN0,EXTI0_IRQ}
#define EXTI0_PC0	(EXTI_GPIO_MAPING_t){EXTI0,GPIOC,GPIO_PIN0,EXTI0_IRQ}
#define EXTI0_PD0	(EXTI_GPIO_MAPING_t){EXTI0,GPIOD,GPIO_PIN0,EXTI0_IRQ}

//EXTI1
#define EXII1_PA1	(EXTI_GPIO_MAPING_t){EXTI1,GPIOA,GPIO_PIN1,EXTI1_IRQ}
#define EXTI1_PB1	(EXTI_GPIO_MAPING_t){EXTI1,GPIOB,GPIO_PIN1,EXTI1_IRQ}
#define EXTI1_PC1	(EXTI_GPIO_MAPING_t){EXTI1,GPIOC,GPIO_PIN1,EXTI1_IRQ}
#define EXTI1_PD1	(EXTI_GPIO_MAPING_t){EXTI1,GPIOD,GPIO_PIN1,EXTI1_IRQ}

//EXTI2
#define EXII2_PA2	(EXTI_GPIO_MAPING_t){EXTI2,GPIOA,GPIO_PIN2,EXTI2_IRQ}
#define EXTI2_PB2	(EXTI_GPIO_MAPING_t){EXTI2,GPIOB,GPIO_PIN2,EXTI2_IRQ}
#define EXTI2_PC2	(EXTI_GPIO_MAPING_t){EXTI2,GPIOC,GPIO_PIN2,EXTI2_IRQ}
#define EXTI2_PD2	(EXTI_GPIO_MAPING_t){EXTI2,GPIOD,GPIO_PIN2,EXTI2_IRQ}

//EXTI3
#define EXII3_PA3	(EXTI_GPIO_MAPING_t){EXTI3,GPIOA,GPIO_PIN3,EXTI3_IRQ}
#define EXTI3_PB3	(EXTI_GPIO_MAPING_t){EXTI3,GPIOB,GPIO_PIN3,EXTI3_IRQ}
#define EXTI3_PC3	(EXTI_GPIO_MAPING_t){EXTI3,GPIOC,GPIO_PIN3,EXTI3_IRQ}
#define EXTI3_PD3	(EXTI_GPIO_MAPING_t){EXTI3,GPIOD,GPIO_PIN3,EXTI3_IRQ}

//EXTI4
#define EXII4_PA4	(EXTI_GPIO_MAPING_t){EXTI4,GPIOA,GPIO_PIN4,EXTI4_IRQ}
#define EXTI4_PB4	(EXTI_GPIO_MAPING_t){EXTI4,GPIOB,GPIO_PIN4,EXTI4_IRQ}
#define EXTI4_PC4	(EXTI_GPIO_MAPING_t){EXTI4,GPIOC,GPIO_PIN4,EXTI4_IRQ}
#define EXTI4_PD4	(EXTI_GPIO_MAPING_t){EXTI4,GPIOD,GPIO_PIN4,EXTI4_IRQ}

//EXTI5
#define EXII5_PA5	(EXTI_GPIO_MAPING_t){EXTI5,GPIOA,GPIO_PIN5,EXTI5_IRQ}
#define EXTI5_PB5	(EXTI_GPIO_MAPING_t){EXTI5,GPIOB,GPIO_PIN5,EXTI5_IRQ}
#define EXTI5_PC5	(EXTI_GPIO_MAPING_t){EXTI5,GPIOC,GPIO_PIN5,EXTI5_IRQ}
#define EXTI5_PD5	(EXTI_GPIO_MAPING_t){EXTI5,GPIOD,GPIO_PIN5,EXTI5_IRQ}

//EXTI6
#define EXII6_PA6	(EXTI_GPIO_MAPING_t){EXTI6,GPIOA,GPIO_PIN6,EXTI6_IRQ}
#define EXTI6_PB6	(EXTI_GPIO_MAPING_t){EXTI6,GPIOB,GPIO_PIN6,EXTI6_IRQ}
#define EXTI6_PC6	(EXTI_GPIO_MAPING_t){EXTI6,GPIOC,GPIO_PIN6,EXTI6_IRQ}
#define EXTI6_PD6	(EXTI_GPIO_MAPING_t){EXTI6,GPIOD,GPIO_PIN6,EXTI6_IRQ}

//EXTI7
#define EXII7_PA7	(EXTI_GPIO_MAPING_t){EXTI7,GPIOA,GPIO_PIN7,EXTI7_IRQ}
#define EXTI7_PB7	(EXTI_GPIO_MAPING_t){EXTI7,GPIOB,GPIO_PIN7,EXTI7_IRQ}
#define EXTI7_PC7	(EXTI_GPIO_MAPING_t){EXTI7,GPIOC,GPIO_PIN7,EXTI7_IRQ}
#define EXTI7_PD7	(EXTI_GPIO_MAPING_t){EXTI7,GPIOD,GPIO_PIN7,EXTI7_IRQ}

//EXTI8
#define EXII8_PA8	(EXTI_GPIO_MAPING_t){EXTI8,GPIOA,GPIO_PIN8,EXTI8_IRQ}
#define EXTI8_PB8	(EXTI_GPIO_MAPING_t){EXTI8,GPIOB,GPIO_PIN8,EXTI8_IRQ}
#define EXTI8_PC8	(EXTI_GPIO_MAPING_t){EXTI8,GPIOC,GPIO_PIN8,EXTI8_IRQ}
#define EXTI8_PD8	(EXTI_GPIO_MAPING_t){EXTI8,GPIOD,GPIO_PIN8,EXTI8_IRQ}

//EXTI9
#define EXII9_PA9	(EXTI_GPIO_MAPING_t){EXTI9,GPIOA,GPIO_PIN9,EXTI9_IRQ}
#define EXTI9_PB9	(EXTI_GPIO_MAPING_t){EXTI9,GPIOB,GPIO_PIN9,EXTI9_IRQ}
#define EXTI9_PC9	(EXTI_GPIO_MAPING_t){EXTI9,GPIOC,GPIO_PIN9,EXTI9_IRQ}
#define EXTI9_PD9	(EXTI_GPIO_MAPING_t){EXTI9,GPIOD,GPIO_PIN9,EXTI9_IRQ}

//EXTI10
#define EXII10_PA10	(EXTI_GPIO_MAPING_t){EXTI10,GPIOA,GPIO_PIN10,EXTI10_IRQ}
#define EXTI10_PB10	(EXTI_GPIO_MAPING_t){EXTI10,GPIOB,GPIO_PIN10,EXTI10_IRQ}
#define EXTI10_PC10	(EXTI_GPIO_MAPING_t){EXTI10,GPIOC,GPIO_PIN10,EXTI10_IRQ}
#define EXTI10_PD10	(EXTI_GPIO_MAPING_t){EXTI10,GPIOD,GPIO_PIN10,EXTI10_IRQ}

//EXTI11
#define EXII11_PA11	(EXTI_GPIO_MAPING_t){EXTI11,GPIOA,GPIO_PIN11,EXTI11_IRQ}
#define EXTI11_PB11	(EXTI_GPIO_MAPING_t){EXTI11,GPIOB,GPIO_PIN11,EXTI11_IRQ}
#define EXTI11_PC11	(EXTI_GPIO_MAPING_t){EXTI11,GPIOC,GPIO_PIN11,EXTI11_IRQ}
#define EXTI11_PD11	(EXTI_GPIO_MAPING_t){EXTI11,GPIOD,GPIO_PIN11,EXTI11_IRQ}

//EXTI12
#define EXII12_PA12	(EXTI_GPIO_MAPING_t){EXTI12,GPIOA,GPIO_PIN12,EXTI12_IRQ}
#define EXTI12_PB12	(EXTI_GPIO_MAPING_t){EXTI12,GPIOB,GPIO_PIN12,EXTI12_IRQ}
#define EXTI12_PC12	(EXTI_GPIO_MAPING_t){EXTI12,GPIOC,GPIO_PIN12,EXTI12_IRQ}
#define EXTI12_PD12	(EXTI_GPIO_MAPING_t){EXTI12,GPIOD,GPIO_PIN12,EXTI12_IRQ}

//EXTI13
#define EXII13_PA13	(EXTI_GPIO_MAPING_t){EXTI13,GPIOA,GPIO_PIN13,EXTI13_IRQ}
#define EXTI13_PB13	(EXTI_GPIO_MAPING_t){EXTI13,GPIOB,GPIO_PIN13,EXTI13_IRQ}
#define EXTI13_PC13	(EXTI_GPIO_MAPING_t){EXTI13,GPIOC,GPIO_PIN13,EXTI13_IRQ}
#define EXTI13_PD13	(EXTI_GPIO_MAPING_t){EXTI13,GPIOD,GPIO_PIN13,EXTI13_IRQ}

//EXTI14
#define EXII14_PA14	(EXTI_GPIO_MAPING_t){EXTI14,GPIOA,GPIO_PIN14,EXTI14_IRQ}
#define EXTI14_PB14	(EXTI_GPIO_MAPING_t){EXTI14,GPIOB,GPIO_PIN14,EXTI14_IRQ}
#define EXTI14_PC14	(EXTI_GPIO_MAPING_t){EXTI14,GPIOC,GPIO_PIN14,EXTI14_IRQ}
#define EXTI14_PD14	(EXTI_GPIO_MAPING_t){EXTI14,GPIOD,GPIO_PIN14,EXTI14_IRQ}

//EXTI15
#define EXII15_PA15	(EXTI_GPIO_MAPING_t){EXTI15,GPIOA,GPIO_PIN15,EXTI15_IRQ}
#define EXTI15_PB15	(EXTI_GPIO_MAPING_t){EXTI15,GPIOB,GPIO_PIN15,EXTI15_IRQ}
#define EXTI15_PC15	(EXTI_GPIO_MAPING_t){EXTI15,GPIOC,GPIO_PIN15,EXTI15_IRQ}
#define EXTI15_PD15	(EXTI_GPIO_MAPING_t){EXTI15,GPIOD,GPIO_PIN15,EXTI15_IRQ}




//*******************************EXTI_TRIGGER_CONDITIONS*******************************//

#define EXTI_TRIGGER_RISING				0
#define EXTI_TRIGGER_FALLING			1
#define EXTI_TRIGGER_RISING_FALLING		2



//*******************************EXTI_STATES*******************************//


#define EXTI_IRQ_ENABLE			1
#define EXTI_IRQ_DISABLE		0




//********************************************************************************************************************************************//

				//********************APIS SUPPORTED BY "MCAL GPIO DRIVEER"******************************//


void MCAL_EXTI_GPIO_INIT(EXTI_PINCONFIG_t *EXTI_CONFIG);
void MCAL_EXTI_GPIO_DEINIT(void);
void MCAL_EXTI_GPIO_UPDATE(EXTI_PINCONFIG_t *EXTI_CONFIG);












#endif /* INC_STM32F103C6_EXTI_DRIVER_H_ */
