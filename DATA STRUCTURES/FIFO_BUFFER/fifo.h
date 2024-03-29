/*
 ============================================================================
 Name        : lifo.h
 Author      : ANDREW NASSER
 Created on  : 18/9
 ============================================================================
 */
#ifndef _lifo_h
#define _lifo_h
#include "stdio.h"
#include"stdint.h"
/*customer can select element type */
#define element_type unsigned int
typedef struct{
	element_type counter;
	element_type* head;
	element_type* tail;
	element_type* base;
	element_type length;
}FIFO_Buf_t;

typedef enum{
	FIFO_NO_ERROR,
	FIFO_FULL,
	FIFO_EMPTY,
	FIFO_NULL,

}Buffer_status;

/*APIs*/

Buffer_status FIFO_init (FIFO_Buf_t* fifo,element_type* buff , unsigned int length);
Buffer_status FIFO_enqueue (FIFO_Buf_t* fifo,element_type item);
Buffer_status FIFO_dequeue (FIFO_Buf_t* fifo,element_type* item);
Buffer_status FIFO_is_full (FIFO_Buf_t* fifo);
void FIFO_print (FIFO_Buf_t* fifo);
#endif

