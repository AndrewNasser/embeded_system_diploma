/*
 * ADC.c
 *
 * Created: 10/4/2023 7:36:09 PM
 *  Author: ANDREW NASSER
 */ 
#include <HEADERS.h>


void MCAL_ADC_INIT( ADC_CONFIG_T* ADC_CONFIG ){
	
	
	/*Bits 7:6 – REFSn:?Reference Selection [n = 1:0]
	These bits select the voltage reference for the ADC. If these bits are changed during a conversion, the
	change will not go in effect until this conversion is complete (ADIF in ADCSRA is set). The internal
	voltage reference options may not be used if an external reference voltage is being applied to the AREF
	pin.*/
	
	if ((ADC_CONFIG->VOLTAGE_REF==AREF) || (ADC_CONFIG->VOLTAGE_REF==AVCC) || (ADC_CONFIG->VOLTAGE_REF==INTERN_V) )
	{
		ADMUX |= ADC_CONFIG->VOLTAGE_REF;
	}
	
	
	/*Bits 2:0 – ADPSn:?ADC Prescaler Select [n = 2:0]
	These bits determine the division factor between the XTAL frequency and the input clock to the ADC*/
	
	if ((ADC_CONFIG->PRESCALLING >= ADC_PRESC_2) && (ADC_CONFIG->PRESCALLING <= ADC_PRESC_128)){
		ADCSRA |= ADC_CONFIG->PRESCALLING;
	}
	/*Bit 7 – ADEN:?ADC Enable
	Writing this bit to one enables the ADC. By writing it to zero, the ADC is turned off. Turning the ADC off
	while a conversion is in progress, will terminate this conversion.	*/
	SETBIT(ADCSRA,ADEN);
}


uint16_t MCAL_ADC_READ( enum ADC_CHANNEL CH ){
	/*
	uint16_t DATA =0;
	ADMUX &= 0xE0;
	ADMUX |=CH;
	/*Bit 6 – ADSC:?ADC Start Conversion
	In Single Conversion mode, write this bit to one to start each conversion. In Free Running mode, write
	this bit to one to start the first conversion. The first conversion after ADSC has been written after the ADC
	has been enabled, or if ADSC is written at the same time as the ADC is enabled, will take 25 ADC clock
	cycles instead of the normal 13. This first conversion performs initialization of the ADC.
	
	SETBIT(ADCSRA,ADSC);
	
	while(READBIT(ADCSRA,ADSC));
	return DATA ;
	*/
	
	uint16_t data =0;
	if(CH==0)
	{
		ADMUX &=~(CH);
	}
	else
	{
		ADMUX |=CH;
	}
	SETBIT(ADCSRA,ADSC);
	
	while(!(ADC_PRESC_8 && (1<<6) ) );
	
	data = ADCL ;
	data |= (ADCH <<8) ;
	return data ;
	
	}

