/*
 * Utlis.h
 *
 * Created: 2/9/2023 11:49:59 AM
 *  Author: King 45M
 */ 


#ifndef UTLIS_H_
#define UTLIS_H_
#define SetBit(reg,bit)	(reg=reg|(1<<bit))
#define ClearBit(reg,bit)	(reg=reg&~(1<<bit))
#define ReadBit(reg,bit)	((reg>>bit)&1)
#define ToggleBit(reg,bit)	(reg=reg^(1<<bit))





#endif /* UTLIS_H_ */