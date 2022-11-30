#include "uart.h"
#define UARTODR *((volatile unsigned int *)((unsigned int*)0x101f1000))
void Uart_Send_String(unsigned char* p_tx_string)
{
	while(*p_tx_string!='\0')
	{
		UARTODR=(unsigned int)(*p_tx_string);
		p_tx_string++;

	}
	
}