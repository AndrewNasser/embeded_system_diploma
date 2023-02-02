/*
 ============================================================================
 File Name        : Student Management
 Author           : Andrew Nasser
 Description      :FIFO.h
 ============================================================================
 */

#ifndef FIFO_H_
#define FIFO_H_

#include "system.h"

#define FIFO_DATA_TYPE struct sinfo
#define FIFO_FIND 1
#define FIFO_UPDATE 2
#define FIFO_DELETE 3

typedef enum {
	FIFO_NULL,
	FIFO_EMPTY,
	FIFO_FULL,
	FIFO_NO_ERROR,
	FIFO_ITEM_ID_NOT_UNIQUE,
	FIFO_ITEM_NOT_FOUND
}FIFO_STAT;

typedef struct{

	unsigned int length;
	unsigned int count;
	FIFO_DATA_TYPE *base;
	FIFO_DATA_TYPE *head;
	FIFO_DATA_TYPE *tail;

}FIFO_BUFFER;



FIFO_STAT FIFO_init(FIFO_DATA_TYPE * container,unsigned int len ,FIFO_BUFFER * buffer);
FIFO_STAT FIFO_add(FIFO_BUFFER *buffer,FIFO_DATA_TYPE student);
FIFO_STAT FIFO_findByRL(FIFO_BUFFER *buffer,int rl,FIFO_DATA_TYPE *pstudent,int state);
FIFO_STAT FIFO_findByFName(FIFO_BUFFER *buffer,char *name,FIFO_DATA_TYPE * student);
FIFO_STAT FIFO_findByCID(FIFO_BUFFER *buffer,int cid,FIFO_DATA_TYPE * student);
FIFO_STAT FIFO_isFull(FIFO_BUFFER *buffer);
FIFO_STAT FIFO_isEmpty(FIFO_BUFFER *buffer);
void FIFO_printAll(FIFO_BUFFER *buffer);
#endif /* FIFO_H_ */
