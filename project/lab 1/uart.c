#include "uart.h"
#define UARTODR *((volatile unsigned int *)((unsigned int*)0x10f1000))
void Uart_send_string(unsigned char* p_tx_string)
{
	while(*p_tx_string!='\0')
	{
		UARTODR=(unsigned int)(*p_tx_string);
		p_tx_string++;

	}
	
}