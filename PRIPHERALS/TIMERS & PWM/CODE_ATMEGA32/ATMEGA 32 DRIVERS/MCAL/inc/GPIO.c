/*
 * GPIO.c
 *
 * Created: 9/5/2023 4:14:11 AM
 *  Author: ANDREW NASSER
 */ 
#include <HEADERS.h>


/*The DDxn bit in the DDRx Register selects the direction of this pin. If DDxn is written logic one, Pxn is
configured as an output pin. If DDxn is written logic zero, Pxn is configured as an input pin.

If PORTxn is written logic one when the pin is configured as an input pin, the pull-up resistor is activated.
To switch the pull-up resistor off, PORTxn has to be written logic zero or the pin has to be configured as
an output pin. The port pins are tri-stated when reset condition becomes active, even if no clocks are
running.

If PORTxn is written logic one when the pin is configured as an output pin, the port pin is driven high
(one). If PORTxn is written logic zero when the pin is configured as an output pin, the port pin is driven
low (zero).*/




/*======================================================================================================
 * FUNC NAME ----> MCAL_PORT_DIRICTION
 * BRIEF     ----> SPECIFIED THE DIRECTIO OF DIO PORT
 * PARAM1[IN]----> PORT ACC[A,B,C,D]
 * PARAM1[IN]----> DIRECTION
 * RETAVAL	 ----> NONE
 * NOTE		 ----> NONE
 *
 */

void MCAL_PORT_DIR(uint8_t PORT,uint8_t DIR){
	switch(PORT)
	{
		case DIO_PORTA:
		 DDRA=DIR;
		 	break;
		case DIO_PORTB:
		 DDRB=DIR;
		 	break;
		case DIO_PORTC:
		 DDRC=DIR;
		 	break;
		case DIO_PORTD:
		 DDRD=DIR;
		 	break;
	}
}

/*======================================================================================================
 * FUNC NAME ----> MCAL_PORT_VAL
 * BRIEF     ----> SPECIFIED THE VALUE IN DIO PORT
 * PARAM1[IN]----> PORT ACC[A,B,C,D]
 * PARAM1[IN]----> VALUE IN PORT
 * RETAVAL	 ----> NONE
 * NOTE		 ----> NONE
 *
 */

void MCAL_PORT_VAL(uint8_t PORT,uint8_t VAL){
	
	{
		switch(PORT)
		{
			case DIO_PORTA:
				 PORTA=VAL;
				 	break;
			case DIO_PORTB:
				 PORTB=VAL;
				 	break;
			case DIO_PORTC:
				 PORTC=VAL;
				 	break;
			case DIO_PORTD:
				 PORTD=VAL;
				 	break;
		}
	}

	
	
}


/*======================================================================================================
 * FUNC NAME ----> MCAL_PIN_STATE
 * BRIEF     ----> SPECIFIED THE STATE OF PIN IS HIGH OR LOW 
 * PARAM1[IN]----> PORT ACC[A,B,C,D]
 * PARAM1[IN]----> PIN NUMBER
 * PARAM1[IN]----> STATE OF PIN
 * RETAVAL	 ----> NONE
 * NOTE		 ----> NONE
 *
 */
void MCAL_PIN_STATE(uint8_t PORT,uint8_t PIN,uint8_t STATE){

	switch(STATE)
	{
	case PIN_HIGH:
		switch(PORT)
	{
		case DIO_PORTA :
			SETBIT(PORTA, PIN);
			break;
		case DIO_PORTB :
			 SETBIT(PORTB, PIN);
			 break;
		case DIO_PORTC :
			 SETBIT(PORTC, PIN); 
			 break;
		case DIO_PORTD :
			 SETBIT(PORTD, PIN); 
			 break;
	}
	break;
	case PIN_LOW :
	switch(PORT)
	{
		case DIO_PORTA :
			 CLEARBIT(PORTA, PIN);
			  break;
		case DIO_PORTB :
			 CLEARBIT(PORTB, PIN);
			  break;
		case DIO_PORTC :
			 CLEARBIT(PORTC, PIN);
			  break;
		case DIO_PORTD :
			 CLEARBIT(PORTD, PIN);
			  break;
	}

	break;
}



}

/*======================================================================================================
 * FUNC NAME ----> MCAL_PIN_MODE
 * BRIEF     ----> SPECIFIED THE MODE OF PIN IS INPUT OR OUTPUT 
 * PARAM1[IN]----> PORT ACC[A,B,C,D]
 * PARAM1[IN]----> PIN NUMBER
 * PARAM1[IN]----> DIRECTION
 * RETAVAL	 ----> NONE
 * NOTE		 ----> NONE
 *
 */
void MCAL_PIN_MODE(uint8_t PORT,uint8_t PIN,uint8_t DIR)
{
	switch(DIR)
	{
		case PIN_OUT :
		switch(PORT)
		{
			case DIO_PORTA :
				 SETBIT(DDRA, PIN);
				  break;
			case DIO_PORTB :
				 SETBIT(DDRB, PIN);
				  break;
			case DIO_PORTC :
				 SETBIT(DDRC, PIN);
				  break;
			case DIO_PORTD :
				 SETBIT(DDRD, PIN);
				  break;
		}
		break;
		case PIN_IN :
		switch(PORT)
		{
			case DIO_PORTA :
				CLEARBIT(DDRA, PIN);
					break;
			case DIO_PORTB :
				CLEARBIT(DDRB, PIN);
					break;
			case DIO_PORTC :
				CLEARBIT(DDRC, PIN);
					break;
			case DIO_PORTD :
				CLEARBIT(DDRD, PIN);
					break;
		}
		break;
	}

}



void TOGGLE_PIN(uint8_t PORT , uint8_t PIN)
{
	switch(PORT)
	{
		case DIO_PORTA : TOGGLEBIT(PORTA , PIN);	break;
		case DIO_PORTB : TOGGLEBIT(PORTB , PIN);	break;
		case DIO_PORTC : TOGGLEBIT(PORTC , PIN);	break;
		case DIO_PORTD : TOGGLEBIT(PORTD , PIN);	break;
	}
}

uint8_t DIO_READ_BIT(uint8_t PORT , uint8_t PIN )
{
	switch(PORT)
	{
		case DIO_PORTA : return READBIT(PINA , PIN);	break;
		case DIO_PORTB : return READBIT(PINB , PIN);	break;
		case DIO_PORTC : return READBIT(PINC , PIN);	break;
		case DIO_PORTD : return READBIT(PIND , PIN);	break;
	}
}















