/*
 ============================================================================
 Name        : lifo.h
 Author      : ANDREW
 Created on  : 17/9
 ============================================================================
 */
#include"lifo.h"
LIFO_status	LIFO_Add_item(LIFO_Buf_t* lifo_buf , unsigned int item)
{
	/*CHECK LIFO VALID*/
		if(!lifo_buf->head ||! lifo_buf->base)
			return LIFO_NULL;
	/*check lifo is fill*/
		if (lifo_buf->counter== lifo_buf->length)
				return LIFO_FULL;
		/*add value*/
		*(lifo_buf->head) =item;
		lifo_buf->head ++;
		lifo_buf->counter++;
		return LIFO_NO_ERROR;

}
LIFO_status	LIFO_get_item(LIFO_Buf_t* lifo_buf , unsigned int* item)
{
	if(!lifo_buf->base || !lifo_buf->head)
				return LIFO_NULL;
	/*check empty*/
	if(lifo_buf->counter ==0)
				return LIFO_EMPTY;
lifo_buf->head-- ;
*item = *(lifo_buf->head);
lifo_buf->counter-- ;

	return LIFO_NO_ERROR;
}
LIFO_status	LIFO_init(LIFO_Buf_t* lifo_buf , unsigned int* buf,unsigned int length)
{
	if(!buf)
		return LIFO_NULL;
	lifo_buf->base = buf ;
	lifo_buf->head = buf ;
	lifo_buf->length = length ;
	lifo_buf->counter = 0 ;
	return LIFO_NO_ERROR;

}
