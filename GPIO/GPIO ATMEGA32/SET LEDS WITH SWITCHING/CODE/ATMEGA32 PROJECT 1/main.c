/*
 * ATMEGA32 PROJECT 1.c
 *
 * Created: 2/7/2023 5:53:03 PM
 * Author : King 45M
 */ 

#include "HEADER.h"
#include "util/delay.h"
#include "Utlis.h"
#define	F_CPU	8000000UL

int main(void)
{
	DDRA=0b11111111;
	ClearBit(DDRD,0);
	SetBit(PORTD,0);
	while (1)
	{
		if (ReadBit(PIND,0)==0)
		{
			while (ReadBit(PIND,0)==0)
			{
				SetBit(PORTA,0);
				_delay_ms(2000);
				SetBit(PORTA,1);
				_delay_ms(2000);
				SetBit(PORTA,2);
				_delay_ms(2000);
				SetBit(PORTA,3);
				_delay_ms(2000);
				SetBit(PORTA,4);
				_delay_ms(2000);
				SetBit(PORTA,5);
				_delay_ms(2000);
				SetBit(PORTA,6);
				_delay_ms(2000);
				SetBit(PORTA,7);
				_delay_ms(2000);
			}
		}
		else{
				ClearBit(PORTA,0);
				ClearBit(PORTA,1);
				ClearBit(PORTA,2);
				ClearBit(PORTA,3);
				ClearBit(PORTA,4);
				ClearBit(PORTA,5);
				ClearBit(PORTA,6);
				ClearBit(PORTA,7);
				
				

		}
	}
}

