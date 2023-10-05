/*
 * EXTI.c
 *
 * Created: 9/14/2023 7:26:06 AM
 *  Author: ANDREW NASSER
 */ 

#include <HEADERS.h>



/*The external interrupts can be triggered by a falling or rising edge or a
low level (INT2 is only an edge triggered interrupt).*/


void EXTI0_INIT(void)
{
	/*The External Interrupt 0 is activated by the external pin INT0 if the SREG I-flag and the corresponding
	interrupt mask are set.*/
	
		SETBIT(SREG , 7);
	
	/*Table 16-2?Interrupt 0 Sense Control
	ISC01		ISC00			Description
	  0			  0			The low level of INT0 generates an interrupt request.
	  0			  1			Any logical change on INT0 generates an interrupt request.
	  1			  0			The falling edge of INT0 generates an interrupt request.
	  1			  1			The rising edge of INT0 generates an interrupt request.*/
	// GIE


	// TRIGG FALLING EDGE
	CLEARBIT(MCUCR , 0);
	SETBIT(MCUCR , 1);

	// PIE
	SETBIT(GICR , 6);

}





void EXTI1_INIT(void)
{	
			/*The External Interrupt 0 is activated by the external pin INT0 if the SREG I-flag and the corresponding
	interrupt mask are set.*/
			
			
		SETBIT(SREG , 7);
		
		
		
	/*	Table 16-1?Interrupt 1 Sense Control
	ISC11		 ISC10			Description
	  0			    0		The low level of INT1 generates an interrupt request.
	  0				1		Any logical change on INT1 generates an interrupt request.
	  1			    0		The falling edge of INT1 generates an interrupt request.
	  1			    1		The rising edge of INT1 generates an interrupt request
   */

	CLEARBIT(MCUCR , 2);
	SETBIT(MCUCR , 3);

	// PIE
	SETBIT(GICR , 7);
}










void EXTI2_INIT(void)
{
	
	
	/*The External Interrupt 0 is activated by the external pin INT0 if the SREG I-flag and the corresponding
	interrupt mask are set.*/
	
	
	SETBIT(SREG , 7);

/*. If ISC2 is written to zero, a falling edge on INT2 activates
the interrupt. If ISC2 is written to one, a rising edge on INT2 activates the interrupt. Edges on INT2 are
registered asynchronously. Pulses on INT2 wider than the minimum pulse width given in the table below
will generate an interrupt. Shorter pulses are not guaranteed to generate an interrupt. When changing the
ISC2 bit, an interrupt can occur. Therefore, it is recommended to first disable INT2 by clearing its Interrupt
Enable bit in the GICR Register. Then, the ISC2 bit can be changed. Finally, the INT2 Interrupt Flag
should be cleared by writing a logical one to its Interrupt Flag bit (INTF2) in the GIFR Register before the
interrupt is re-enabled*/	
	CLEARBIT(MCUCSR ,6);

	// PIE

	SETBIT(GICR , 5);
}
