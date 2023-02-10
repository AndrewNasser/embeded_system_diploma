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
static unsigned char segments[]={0x3f,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

int main(void)
{
	DDRC = 0xFF;
	unsigned char i,j;
	while(1)
	{
		for(i=0;i<10;i++)
		{
			for(j=0;j<10;j++)
			{
				PORTC = (0b1011)| (i<<4);
				_delay_ms(30);
				PORTC = (0b0111)| (j<<4);
				_delay_ms(30);
			}
			
		}
	}
}

