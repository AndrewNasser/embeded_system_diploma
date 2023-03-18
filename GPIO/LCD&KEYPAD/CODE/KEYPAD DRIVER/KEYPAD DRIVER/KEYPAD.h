/*
 * KEYPAD.h
 *
 * Created: 3/17/2023 1:01:26 PM
 *  Author: King 45M
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#include <avr/io.h>
#include <util/delay.h>
#ifndef F_CPU
#define F_CPU 8000000UL

#define KEYPAD_PORT   PORTB
#define KEYPAD_DDR    DDRB
#define KEYPAD_PIN    PINB





#define R0	0
#define R1  1
#define R2  2
#define R3  3
#define C0  4
#define C1  5
#define C2  6
#define C3  7

void KEYPAD_INIT();
char KEYPAD_CHAR();




#endif /* KEYPAD_H_ */