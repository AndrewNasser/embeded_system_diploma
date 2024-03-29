/*
 * main.c
 *
 * Created: 2/3/2023 6:58:29 PM
 *  Author: ANDREW NASSER
 */ 

#include <xc.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define F_CPU 1000000UL
#define IO_BASE 0x20
#define IO_PORTD *((volatile unsigned char *)(IO_BASE + 0x12))
#define IO_DDRD *((volatile unsigned char *)(IO_BASE + 0x11))
#define INT_MCUCR *((volatile unsigned char *)(IO_BASE + 0x35))
#define INT_MCUCSR *((volatile unsigned char *)(IO_BASE + 0x34))
#define INT_GICR *((volatile unsigned char *)(IO_BASE + 0x3B))
#define INT_SREG *((volatile unsigned char *)(IO_BASE + 0x3F))
void init (void){
	//GPIO_Init
	IO_DDRD |= (1 << 5);
	IO_DDRD |= (1 << 6);
	IO_DDRD |= (1 << 7);
	INT_MCUCR &= ~(0b00001111);
	 //ENABLE THE CONTROL REGISTER ( INT1 -> rising , INT0 -> logic )
	INT_MCUCR |= (0b00001101);
	// enable the control state register ( INT2 -> falling )
	INT_MCUCSR &= ~(1 << 6);   
	//enable the interrupts ( INT0 , INT1 , INT2 )
	INT_GICR |=(0b11100000);   
	//enable state register
	INT_SREG |=(1 << 7); 
	
}


void main(void){
	init ();
	while (1);
}


void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	//DDRD = 0xff;
	IO_PORTD |= (1 << 5);
	_delay_ms(500);
	IO_PORTD &= ~(1 << 5);
	
}


void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{
	//DDRD = 0xff;
	IO_PORTD |= (1 << 6);
	_delay_ms(500);
	IO_PORTD &= ~(1 << 6);
}

void __vector_3 (void) __attribute__((signal));
void __vector_3 (void)
{
	//DDRD = 0xff;
	IO_PORTD |= (1 << 7);
	_delay_ms(500);
	IO_PORTD &= ~(1 << 7);
}

