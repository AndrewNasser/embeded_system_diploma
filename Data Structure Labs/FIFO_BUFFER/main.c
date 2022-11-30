/*
 ============================================================================
 Name        : lifo.h
 Author      : ANDREW NASSER
 Created on  : 18/9
 ============================================================================
 */
#include "fifo.h"
#include "stdio.h"

element_type buffer[5];

void main(){

	FIFO_Buf_t uart_fifo;
	unsigned char i,temp=0;

	if(FIFO_init(&uart_fifo,buffer,5) == FIFO_NO_ERROR){
		printf("fifo init is comolete .. \n");
	}

	for(i=0 ; i<7 ; i++){
		printf("FIFO Enqueue %x \n",i);

		if(FIFO_enqueue(&uart_fifo, i) == FIFO_NO_ERROR)
			printf("FIFO Enqueue %x  is done \n",i);
		else
			printf("FIFO Enqueue %x is failed \n",i);

	}

	FIFO_print(&uart_fifo) ;
	FIFO_dequeue(&uart_fifo,&temp);
	printf("FIFO dequeue %x  is done \n",temp);
	FIFO_dequeue(&uart_fifo,&temp);
	printf("FIFO dequeue %x  is done \n",temp);

	for(i=0 ; i<2 ; i++){
		printf("fifo enqueue %x \n ,i");
		if(FIFO_enqueue(&uart_fifo,i)== FIFO_NO_ERROR)
			printf("fifo enqueue : %x --------------->DONE\n",i);
		else
			 printf("fifo enqueue : %x --------------->FAILED\n",i);
	}
}


	}
