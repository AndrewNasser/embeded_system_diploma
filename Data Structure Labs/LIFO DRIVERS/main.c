/*
 ============================================================================
 Name        : lifo.h
 Author      : ANDREW
 Created on  : 17/9
 ============================================================================
 */
#include "stdio.h"
#include"lifo.h"
#include"stdlib.h"
unsigned int buffer1 [5];
int main (void)
{
	int i , temp ;
	LIFO_Buf_t uart_lifo , I2C_lifo ;
	/*static allocation*/
	LIFO_init(&uart_lifo , buffer1 , 5 );
	/*dynamic allocation*/
	unsigned int* buffer2 = (unsigned int*) malloc (5 * sizeof(unsigned int));
	LIFO_init(&I2C_lifo , buffer2 , 5);

	for (i=0 ; i<5 ; i++){
		if(LIFO_Add_item(&uart_lifo , i ) == LIFO_NO_ERROR)
			printf ("uart_lifo add %d \n",i );
	}
	for (i=0 ; i<5 ; i++) {
		if(LIFO_get_item(&uart_lifo , &temp) == LIFO_NO_ERROR)
			printf ("uart_lifo get %d \n",temp );
	}
}

