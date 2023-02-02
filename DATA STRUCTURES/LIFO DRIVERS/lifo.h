/*
 ============================================================================
 Name        : lifo.h
 Author      : ANDREW
 Created on  : 17/9
 ============================================================================
 */
#ifndef LIFO_H_
#define LIFO_H_
#include"stdlib.h"
#include"stdio.h"
typedef struct {
	unsigned int length;
	unsigned int counter;
	unsigned int* base;
	unsigned int* head;

}LIFO_Buf_t;
typedef enum {
	LIFO_NO_ERROR,
	LIFO_FULL,
	LIFO_EMPTY,
	LIFO_NULL
}LIFO_status;


LIFO_status	LIFO_Add_item(LIFO_Buf_t* lifo_buf , unsigned int item);
LIFO_status	LIFO_get_item(LIFO_Buf_t* lifo_buf , unsigned int* item);
LIFO_status	LIFO_init(LIFO_Buf_t* lifo_buf , unsigned int* buf , unsigned int length );
#endif

