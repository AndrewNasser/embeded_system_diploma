/*
 * STM32F103C6_GPIO_DRIVER.h
 *
 *  Created on: Mar 20, 2023
 *      Author:ANDREW NASSER
 */

#ifndef INC_STM32F103C6_GPIO_DRIVER_H_
#define INC_STM32F103C6_GPIO_DRIVER_H_

//INCLUDES

#include "STM32F103X6.h"

//MACROS CONFIG REFERENCES


// GPIO PINS DEFINED

#define GPIO_PIN0					((uint16_t)0x0001)		//PIN 0 SELECTED
#define GPIO_PIN1					((uint16_t)0x0002)		//PIN 1 SELECTED
#define GPIO_PIN2					((uint16_t)0x0004)		//PIN 2 SELECTED
#define GPIO_PIN3					((uint16_t)0x0008)		//PIN 3 SELECTED
#define GPIO_PIN4					((uint16_t)0x0010)		//PIN 4 SELECTED
#define GPIO_PIN5					((uint16_t)0x0020)		//PIN 5 SELECTED
#define GPIO_PIN6					((uint16_t)0x0040)		//PIN 6 SELECTED
#define GPIO_PIN7					((uint16_t)0x0080)		//PIN 7 SELECTED
#define GPIO_PIN8					((uint16_t)0x0100)		//PIN 8 SELECTED
#define GPIO_PIN9					((uint16_t)0x0200)		//PIN 9 SELECTED
#define GPIO_PIN10					((uint16_t)0x0400)		//PIN 10 SELECTED
#define GPIO_PIN11					((uint16_t)0x0800)		//PIN 11 SELECTED
#define GPIO_PIN12					((uint16_t)0x1000)		//PIN 12 SELECTED
#define GPIO_PIN13					((uint16_t)0x2000)		//PIN 13 SELECTED
#define GPIO_PIN14					((uint16_t)0x4000)		//PIN 14 SELECTED
#define GPIO_PIN15					((uint16_t)0x8000)		//PIN 15 SELECTED
#define GPIO_PIN_ALL				((uint16_t)0x0001)		//ALL PINS SELECTED
#define GPIO_PIN_MASK					0x0000FFFFu			//PIN MASK FOR ASERT TEST


//GPIO MODES DEFINE

#define GPIO_MODE_ANALOG				0x00000000u			//FOR INPUT MODE ANALOG MODE
#define GPIO_MODE_FLOATING				0x00000001u			//FOR INPUT MODE FLOATING MODE
#define GPIO_MODE_PULLUP				0x00000002u			//FOR INPUT MODE PULL UP MODE
#define GPIO_MODE_PULLDOWN				0x00000003u			//FOR INPUT MODE PULL DOWN MODE
#define GPIO_MODE_PUSH_PULL				0x00000004u			//FOR OUTPUT MODE PUSH PULL MODE
#define GPIO_MODE_OPEN_DRAIN			0x00000005u			//FOR OUTPUT MODE OPEN DRAIN
#define GPIO_MODE_AF_PUSH_PULL			0x00000006u			//FOR ALTERNATIVE FUNCTION PUSH PULL
#define GPIO_MODE_AF_OPEN_DRAIN			0x00000007u			//FOR ALTERNATIVE FUNCTION OPEN DRAIN
#define GPIO_MODE_AF_INPUT				0x00000008u

//GPIO OUTPUT SPEED

#define GPIO_SPEED_10M					0x00000001u			//FOR OUTPUT SPEED MAX 10 MEGA HZ
#define GPIO_SPEED_2M					0x00000002u			//FOR OUTPUT SPEED MAX 2 MEGA HZE
#define GPIO_SPEED_50M					0x00000003u			//FOR OUTPUT SPEED MAX 50 MEGA HZ

//GPIO INPUT PIN STATE
#define GPIO_PIN_SET							1			//FOR ENABLE
#define GPIO_PIN_RESET							0			//FOR RESET


//GPIO RETURN LOCK
#define GPIO_PIN_LOCKED_DONE					1			//FOR  LOCKED SUCCESS
#define GPIO_PIN_LOCKED_ERROR          			0			//FOR LOCKED FAILED


//CONFIG STRUCTURE

typedef struct{
	uint16_t GPIO_PIN_NUMBER;		//SPECIFIC GPIO PIN CONFIG , IT MUST BE A VALUE @ MACROS CONFIG REFERENCES GPIO_PIN DEFINE
	uint8_t GPIO_MODE;				//SPECIFIC GPIO PIN CONFIG , IT MUST BE A VALUE @ MACROS CONFIG REFERENCES GPIO MODE DEFINE
	uint8_t GPIO_SPEED_OUTPUT;		//SPECIFIC GPIO PIN CONFIG , IT MUST BE A VALUE @ MACROS CONFIG REFERENCES GPIO_SPEED DEFINE

}GPIO_PINCONFIG_T;

//********************************************************************************************************************************************//

				//********************APIS SUPPORTED BY "MCAL GPIO DRIVEER"******************************//

void MCAL_GPIO_INIT(GPIO_Typedef *GPIOx ,GPIO_PINCONFIG_T *PINCONFIG );
void MCAL_GPIO_DEINIT(GPIO_Typedef *GPIOx );
uint8_t MCAL_GPIO_READPIN(GPIO_Typedef *GPIOx ,uint16_t PIN_NUMBER );
uint16_t MCAL_GPIO_READPORT(GPIO_Typedef *GPIOx);
void MCAL_GPIO_WRITEPIN(GPIO_Typedef *GPIOx ,uint16_t PIN_NUMBER , uint8_t VAL );
void MCAL_GPIO_WRITEPORT(GPIO_Typedef *GPIOx, uint16_t VAL );
void MCAL_GPIO_TOGGLEPIN(GPIO_Typedef *GPIOx ,uint16_t PIN_NUMBER);
uint8_t MCAL_GPIO_LOCKPIN(GPIO_Typedef *GPIOx ,uint16_t PIN_NUMBER);











#endif /* INC_STM32F103C6_GPIO_DRIVER_H_ */
