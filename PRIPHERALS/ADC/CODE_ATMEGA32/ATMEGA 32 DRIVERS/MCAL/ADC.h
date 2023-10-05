/*
 * ADC.h
 *
 * Created: 10/4/2023 7:35:47 PM
 *  Author: ANDREW NASSER
 */ 


#ifndef ADC_H_
#define ADC_H_


/******************************************************************************
*									ENUMS	                				  *
*******************************************************************************/



 enum ADC_CHANNEL{
	ADC_CH0=0,
	ADC_CH1,
	ADC_CH2,
	ADC_CH3,
	ADC_CH4,
	ADC_CH5,
	ADC_CH6,
	ADC_CH7
};



typedef enum{
	AREF=0,
	AVCC=0x40,
	INTERN_V=0xc0
}ADC_VREF;



typedef enum{
	 ADC_PRESC_2,
	 ADC_PRESC_4,
	 ADC_PRESC_8,
	 ADC_PRESC_16,
	 ADC_PRESC_32,
	 ADC_PRESC_64,
	 ADC_PRESC_128
}ADC_PRESC;
		

/******************************************************************************
*									STRUCT	                				  *
*******************************************************************************/

typedef struct{
	ADC_VREF VOLTAGE_REF;
	ADC_PRESC PRESCALLING;
	

}ADC_CONFIG_T;
		
		
void MCAL_ADC_INIT( ADC_CONFIG_T* ADC_CONFIG );
uint16_t MCAL_ADC_READ( enum ADC_CHANNEL CH );


#endif /* ADC_H_ */