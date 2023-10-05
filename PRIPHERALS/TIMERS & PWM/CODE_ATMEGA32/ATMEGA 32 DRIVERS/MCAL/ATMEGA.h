/*
 * ATMEGA.h
 *
 * Created: 9/5/2023 3:17:59 AM
 *  Author: ANDREW NASSER
 */ 


#ifndef ATMEGA_H_
#define ATMEGA_H_
#define F_CPU 1000000UL
/*
#define DDRA	*((volatile unsigned char *)0x3A)
#define	PORTA	*((volatile unsigned char *)0x3B)
#define	PINA	*((volatile unsigned char *)0x39)

#define DDRB	*((volatile unsigned char *)0x37)
#define PORTB	*((volatile unsigned char *)0x38)
#define PINB	*((volatile unsigned char *)0x36)

#define DDRC	*((volatile unsigned char *)0x34)
#define PORTC	*((volatile unsigned char *)0x35)
#define PINC	*((volatile unsigned char *)0x33)

#define DDRD	*((volatile unsigned char *)0x31)
#define PORTD	*((volatile unsigned char *)0x32)
#define PIND	*((volatile unsigned char *)0x30)


//EXTI
#define SREG	*((volatile unsigned char *)0x5F)
#define MCUCSR	*((volatile unsigned char *)0x54)		//MCU Control and Status Register
#define MCUCR	*((volatile unsigned char *)0x55)		//MCU Control Register
#define GICR	*((volatile unsigned char *)0x5B)

//TIMERS

#define TCCR0	*((volatile unsigned char *)0x53)
#define TIMSK	*((volatile unsigned char *)0x59)
#define TCNT0	*((volatile unsigned char *)0x54)
#define TCCR1B	*((volatile unsigned char *)0x4E)
#define OCR1A	*((volatile unsigned char *)0x49)
#define OCR0	*((volatile unsigned char *)0x5C)


*/

typedef unsigned char uint8_t;
// typedef unsigned short uint16_t;
// typedef unsigned int uint32_t;

typedef char sint8_t;
typedef short sint16_t;
typedef int sint32_t;

typedef unsigned char* ptr_uint8_t;
typedef char* ptr_sint8_t;

typedef void(*PTR_VoidFunVoid_t)(void);
#define NULL_PTR		((void*) (0))

typedef unsigned char E_STATUS_t;
#define E_OK		(E_STATUS_t)(0)
#define E_NOK		(E_STATUS_t)(1)


/*
typedef unsigned char E_STATUS_t;
#define E_OK		(E_STATUS_t)(0)
#define E_NOK		(E_STATUS_t)(1)


typedef void(*PTR_VoidFunVoid_t)(void);
//#define E_OK		((unsigned char)(0))
//#define E_NOK		((unsigned char)(1))
#define NULL_PTR	((void*) (0))*/
#define SETBIT(reg,bit)		(reg|=(1<<bit))
#define CLEARBIT(reg,bit)	(reg=reg&~(1<<bit))
#define READBIT(reg,bit)	((reg>>bit)&1)
#define TOGGLEBIT(reg,bit)	(reg=reg^(1<<bit))









#endif /* ATMEGA_H_ */