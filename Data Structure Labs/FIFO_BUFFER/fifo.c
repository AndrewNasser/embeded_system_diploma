#include"fifo.h"
/* *********************************** */
Buffer_status FIFO_init (FIFO_Buf_t* fifo,element_type* buff , unsigned int length){

	if(!buff )
			return FIFO_NULL;

	fifo->base = buff ;
	fifo->head = fifo->base ;
	fifo->tail = fifo->base ;
	fifo->length = length;
	fifo->counter=0;

	return FIFO_NO_ERROR;

}

/* *********************************** */

Buffer_status FIFO_enqueue (FIFO_Buf_t* fifo,element_type item){

	/* fifo null*/

if(!fifo->head || !fifo->base || !fifo->tail)
	return FIFO_NULL;

   /*fifo is full*/

if(FIFO_is_full(fifo)== FIFO_FULL)
	return FIFO_FULL;

*(fifo->head)=item;
fifo->counter ++;

/*for circular fifo again */

if(fifo->head == fifo->base + (fifo->length * sizeof(element_type)))
	fifo->head=fifo->base ;
else
	fifo->head ++;

return FIFO_NO_ERROR;


}

/* *********************************** */

Buffer_status FIFO_dequeue (FIFO_Buf_t* fifo,element_type* item){
	/*check fifo valid*/

	if(!fifo->head || !fifo->base || !fifo->tail)
		return FIFO_NULL;
	/*fifo empty*/

	if(fifo->counter==0)
		return FIFO_EMPTY;


	*item = *(fifo->tail);
	fifo->counter--;

	/*circular dequeue*/

	if(fifo->tail == (fifo->base + (fifo->length * sizeof(element_type))))
		fifo->tail=fifo->base ;
	else
		fifo->tail ++;

	return FIFO_NO_ERROR;


}

/* *********************************** */

Buffer_status FIFO_is_full (FIFO_Buf_t* fifo){

	if(!fifo->head || !fifo->base || !fifo->tail)
		return FIFO_NULL;
	if(fifo->counter == fifo->length)
		return FIFO_FULL;

	return FIFO_NO_ERROR;
}

/* *********************************** */

void FIFO_print (FIFO_Buf_t* fifo){

element_type* temp;
int i;
if(fifo->counter == 0)
	printf("fifo is empty");
else
	{
		temp=fifo->tail;
		printf("\n ==== fifo print ====\n");
			for(i=0 ; i<fifo->length ; i++){
				printf("\t %x  \n",*temp);
					temp ++;
			}


	}
}
