/*
 ============================================================================
 File Name        : Student Management
 Author           : Andrew Nasser
 Description      : FIFO.c
 ============================================================================
 */
#include "FIFO.h"
FIFO_STAT FIFO_init(FIFO_DATA_TYPE * container,unsigned int len ,FIFO_BUFFER * buffer){

	if(container){

		buffer->base = container;
		buffer->head = container;
		buffer->tail = container;
		buffer->length = len;
		buffer->count = 0;

		return FIFO_NO_ERROR;
	}
	else
		return FIFO_NULL;
}

FIFO_STAT FIFO_add(FIFO_BUFFER *buffer,FIFO_DATA_TYPE student){

	if(!buffer->base||!buffer->head||!buffer->tail)
		return FIFO_NULL;
	else if(FIFO_isFull(buffer) == FIFO_FULL)
		return FIFO_FULL;

	else{
		int i;
		FIFO_DATA_TYPE *temp = buffer->tail;

		for(i = 0; i < buffer->count; i++){
			if(temp->roll == student.roll){
				return FIFO_ITEM_ID_NOT_UNIQUE;
			}
			temp++;
		}

		*(buffer->head) = student;
		buffer->count++;

		if(buffer->head == ((buffer->base)+((buffer->length)-1)))
			buffer->head = buffer->base;
		else
			(buffer->head)++;

		return FIFO_NO_ERROR;
	}
}

FIFO_STAT FIFO_findByRL(FIFO_BUFFER *buffer,int rl,FIFO_DATA_TYPE * pstudent,int objective){

	if(!buffer->base||!buffer->head||!buffer->tail)
		return FIFO_NULL;
	else if(FIFO_isEmpty(buffer) == FIFO_EMPTY)
		return FIFO_EMPTY;
	else{
		int i, j;
		FIFO_DATA_TYPE *temp = buffer->tail;
		for(i = 0; i < buffer->count; i++){
			if(rl == temp->roll){
				if(objective == FIFO_FIND)
					*pstudent = *temp;
				else if(objective == FIFO_UPDATE)
					*temp = *pstudent;
				else{
					for(j = i; j < buffer->count; j++){
						if(j == buffer->count-1){
							FIFO_DATA_TYPE null_student = {""};
							*temp = null_student;
						}
						else{
							*temp = *(temp+1);
							temp++;
						}
					}

					buffer->count--;
					if(buffer->head == buffer->base)
						buffer->head = ((buffer->base)+((buffer->length)-1));
					else
						buffer->head--;
				}
				return FIFO_NO_ERROR;
			}
			temp++;
		}
		return FIFO_ITEM_NOT_FOUND;
	}

}

FIFO_STAT FIFO_findByFName(FIFO_BUFFER *buffer,char *name,FIFO_DATA_TYPE * student){

	if(!buffer->base||!buffer->head||!buffer->tail)
		return FIFO_NULL;
	else if(FIFO_isEmpty(buffer) == FIFO_EMPTY)
		return FIFO_EMPTY;
	else{
		int i, j = 0;
		FIFO_DATA_TYPE *temp = buffer->tail;
		for(i = 0; i < buffer->count; i++){
			if(!stricmp(name,temp->fname)){
				*(student+j) = *temp;
				j++;
			}
			temp++;
		}
		if(j == 0)
			return FIFO_ITEM_NOT_FOUND;
		else
			return FIFO_NO_ERROR;
	}
}

FIFO_STAT FIFO_findByCID(FIFO_BUFFER *buffer,int cid,FIFO_DATA_TYPE * student){

	if(!buffer->base||!buffer->head||!buffer->tail)
		return FIFO_NULL;
	else if(FIFO_isEmpty(buffer) == FIFO_EMPTY)
		return FIFO_EMPTY;
	else{
		int i, j = 0, k;
		FIFO_DATA_TYPE *temp = buffer->tail;
		for(i = 0; i < buffer->count; i++){
			for(k = 0; k < 5; k++){
				if(cid == temp->cid[k]){
					*(student+j) = *temp;
					j++;
				}
			}
			temp++;
		}
		if(j == 0)
			return FIFO_ITEM_NOT_FOUND;
		else
			return FIFO_NO_ERROR;
	}
}
void FIFO_printAll(FIFO_BUFFER *buffer){

	DPRINTF("--------------------------\n");
	if(!buffer->base||!buffer->head||!buffer->tail){
		DPRINTF("[ERROR] Students database is not yet initialized\n");
	}
	else if(FIFO_isEmpty(buffer) == FIFO_EMPTY){
		DPRINTF("[ERROR] Students database is empty \n");
	}
	else{
		int i, j;
		FIFO_DATA_TYPE * temp = buffer->tail;
		for(i = 0; i < buffer->count; i++){

			DPRINTF("Student first name: %s\n",temp->fname);
			DPRINTF("Student last name: %s\n",temp->lname);
			DPRINTF("Student roll number: %d\n",temp->roll);
			DPRINTF("Student GPA: %.2f\n",temp->gpa);
			for(j = 0; j < 5; j++){
				DPRINTF(" The course ID is: %d\n",temp->cid[j]);
			}
			temp++;
			DPRINTF("--------------------------\n");

		}
	}
}

FIFO_STAT FIFO1_isFull(FIFO_BUFFER *buffer){
	if(buffer){
		if(buffer->count == buffer->length)
			return FIFO_FULL;
		else
			return FIFO_NO_ERROR;
	}else
		return FIFO_NULL;
}

FIFO_STAT FIFO_isEmpty(FIFO_BUFFER *buffer){
	if(buffer){
		if(buffer->count == 0)
			return FIFO_EMPTY;
		else
			return FIFO_NO_ERROR;
	}else
		return FIFO_NULL;
}
