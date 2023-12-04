/*
 * keypad.h
 *
 * Created: 4/20/2023 3:01:25 PM
 *  Author: ANDREW NASSER
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include"STM32F103C6_GPIO_DRIVER.h"
#include"STM32F103X6.h"


#define KEYPAD_PORT GPIOB


#define R0	GPIO_PIN0
#define R1	GPIO_PIN1
#define R2	GPIO_PIN3
#define R3	GPIO_PIN4
#define C0	GPIO_PIN5
#define C1	GPIO_PIN6
#define C2	GPIO_PIN7
#define C3	GPIO_PIN8


void Keypad_init();
char Keypad_getkey();

#endif /* KEYPAD_H_ */
