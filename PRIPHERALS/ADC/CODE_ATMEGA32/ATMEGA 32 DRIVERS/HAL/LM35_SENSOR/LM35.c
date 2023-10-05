/*
 * LM35.c
 *
 * Created: 10/4/2023 10:16:49 PM
 *  Author: ANDREW NASSER
 */ 

#include <HEADERS.h>


void LM35_INIT(enum ADC_CHANNEL CH){
	
	
		switch(CH)
		{
			case 0:
			{
				MCAL_PIN_MODE(PORTA,PIN0,PIN_IN);
				break ;
			}
			case 1:
			{
				MCAL_PIN_MODE(PORTA,PIN1,PIN_IN);
				break ;
			}
			case 2:
			{
				MCAL_PIN_MODE(PORTA,PIN2,PIN_IN);
				break ;
			}
			case 3:
			{
				MCAL_PIN_MODE(PORTA,PIN3,PIN_IN);
				break ;
			}
			case 4:
			{
				MCAL_PIN_MODE(PORTA,PIN4,PIN_IN);
				break ;
			}
			case 5:
			{
				MCAL_PIN_MODE(PORTA,PIN5,PIN_IN);
				break ;
			}
			case 6:
			{
				MCAL_PIN_MODE(PORTA,PIN6,PIN_IN);
				break ;
			}			
			case 7:
			{
				MCAL_PIN_MODE(PORTA,PIN7,PIN_IN);
				break ;
			}
			}
	
	}

uint16_t LM35_TEMPERTURE(enum ADC_CHANNEL CH){
	uint16_t read;
	read=MCAL_ADC_READ( CH );
	return read;
	}