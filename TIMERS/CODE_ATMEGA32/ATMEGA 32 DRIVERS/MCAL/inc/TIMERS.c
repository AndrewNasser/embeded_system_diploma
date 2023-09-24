/*
 * TIMERS.c
 *
 * Created: 9/13/2023 
 *  Author: ANDREW NASSER
 */ 

#include <HEADERS.h>

/******************************************************************************
*                               GLOBAL & EXTERN VARIABLES                     *
*******************************************************************************/

TE0_CONFIG_T* TIMER0_CONFIG;
PTR_VoidFunVoid_t	CALLBACK_OVF;
PTR_VoidFunVoid_t	CALLBACK_CMP;
uint8_t NUM_OVF;




/*Clock Select Bit Description FOR TCCR1 
CS02	 CS01	 CS02	 Description
0		 0		  0		 No clock source (Timer/Counter stopped).
0		 0		  1		 clkI/O/1 (No prescaling)
0		 1		  0		 clkI/O/8 (From prescaler)
0		 1		  1		 clkI/O/64 (From prescaler)
1		 0		  0		 clkI/O/256 (From prescaler)
1		 0		  1		 clkI/O/1024 (From prescaler)
1		 1		  0		 External clock source on T0 pin. Clock on falling edge.
1		 1		  1		 External clock source on T0 pin. Clock on falling edge.

uint32_t OVER_FLOW= 0;		//SET OVER FLOW NUMBERS
uint32_t VAR = 0;			//TO SET INTIAL VALUE
*/



/******************************************************************************
*								 APIS IMPLEMENTATION			              *
*******************************************************************************/
E_STATUS_t TIMER0_INIT(TE0_CONFIG_T* CONFIG){
	E_STATUS_t RETERVAL=E_NOK;
	if(NULL_PTR==CONFIG){
		RETERVAL=E_NOK;
	}
	else{
		TIMER0_CONFIG=CONFIG;
		if((NORMAL == TIMER0_CONFIG->MODE) || (CTC == TIMER0_CONFIG->MODE)){
			TCCR0 |=TIMER0_CONFIG->MODE;
					RETERVAL=E_OK;

		}
		else{
			RETERVAL=E_NOK;
		}
		if(( NO_CLCK_SOURCE <= TIMER0_CONFIG->CLCK) && (EXTI_CLCK_RAISING >= TIMER0_CONFIG->CLCK)){
			TCCR0 |=TIMER0_CONFIG->CLCK;
			RETERVAL=E_OK;

		}
		else{
			RETERVAL=E_NOK;
		}
		if((OCIE_DISABLE == TIMER0_CONFIG->OCM_INTERRUPT)|| (OCIE_ENABLE == TIMER0_CONFIG->OCM_INTERRUPT)){
			TIMSK |=TIMER0_CONFIG->OCM_INTERRUPT;
			RETERVAL=E_OK;

		}
		else{
			RETERVAL=E_NOK;
		}
		if((TOIE_DISABLE == TIMER0_CONFIG->OVF_INTERRUPT)|| (TOIE_ENABLE == TIMER0_CONFIG->OVF_INTERRUPT)){
			TIMSK |=TIMER0_CONFIG->OVF_INTERRUPT;
			RETERVAL=E_OK;

		}
		else{
			RETERVAL=E_NOK;
		}	
	}
	return RETERVAL;
	
	
}
E_STATUS_t TIMER0_STOP(TE0_CONFIG_T* CONFIG){
	//COUNTER STOP AT NO SOURCE CLOCK
	CLEARBIT(TIMSK,CS00);
	CLEARBIT(TIMSK,CS01);
	CLEARBIT(TIMSK,CS02);
	
	
	
	
}
E_STATUS_t TIMER0_GET_CMP_VALUE(ptr_uint8_t P_TICKS){
	E_STATUS_t RETERVAL=E_NOK;
	*P_TICKS=OCR0;
	return RETERVAL;
}
E_STATUS_t TIMER0_SET_CMP_VALUE(uint8_t TICKS){
	E_STATUS_t RETERVAL=E_NOK;	
	OCR0=TICKS;
	return RETERVAL;

	
}
E_STATUS_t TIMER0_GET_COUNTER_VALUE(ptr_uint8_t P_TICKS){
	E_STATUS_t RETERVAL=E_NOK;
	*P_TICKS=TCNT0;
	return RETERVAL;
	
	
	
}
E_STATUS_t TIMER0_SET_COUNTER_VALUE(uint8_t TICKS){
	E_STATUS_t RETERVAL=E_NOK;	
	TICKS=TCNT0;
	return RETERVAL;
	
	
	
}
E_STATUS_t TIMER0_GET_OVF_VALUE(ptr_uint8_t P_TICKS){
	E_STATUS_t RETERVAL=E_NOK;	
	 *P_TICKS=NUM_OVF;
	return RETERVAL;
	
	
	
}
E_STATUS_t TIMER0_SET_OVF_VALUE(uint8_t TICKS){
	E_STATUS_t RETERVAL=E_OK;	
	 NUM_OVF=TICKS;
	return RETERVAL;

	
	
}

void TIMER0_SETCALLBACK_OVF_INTERRUPT(PTR_VoidFunVoid_t CALLBACK){

	CALLBACK=CALLBACK_OVF;

	
	
	
}
void TIMER0_SETCALLBACK_CMP_INTERRUPT(PTR_VoidFunVoid_t CALLBACK){
	

		CALLBACK_CMP=CALLBACK;


	
	
	
}

ISR(TIMER0_COMP_vect){
	CALLBACK_CMP();
}
ISR(TIMER0_OVF_vect){
	 NUM_OVF++;
	 CALLBACK_OVF();
}






















/*void TIMER0_INIT(void)
{
	Bit 6 – WGM00:?Waveform Generation Mode
	These bits control the counting sequence of the counter, the source for the maximum (TOP) counter
	value, and what type of waveform generation to be used. Modes of operation supported by the Timer/
	Counter unit are: Normal mode, Clear Timer on Compare Match (CTC) mode, and two types of Pulse
	Width Modulation (PWM) modes.
	
	CLEARBIT(TCCR0 , 3);
	CLEARBIT(TCCR0 , 6);
	
	// 2- GIE enable
	SETBIT(SREG , 7);
	
	// 3- PIE enable
	SETBIT(TIMSK , 0);
}
void TIMER0_START(void)
{
	// select timer frequency with prescaller 1024
	SETBIT(TCCR0 , 0);
	CLEARBIT(TCCR0 , 1);
	SETBIT(TCCR0 , 2);

}
void TIMER0_STOP(void)
{
	// select timer frequency = 0
	CLEARBIT(TCCR0 , 0);
	CLEARBIT(TCCR0 , 1);
	CLEARBIT(TCCR0 , 2);
}

void TIMER0_DELAY(uint32_t time)
{

	uint32_t tick_time = (1024 / 8) ;   // us
	uint32_t ticks_no  =  (time *1000) / tick_time ; // 256

	// Calculate number of interrupt
	OVER_FLOW = ticks_no / 256 ;   //1
	
	
	VAR = 256 - (ticks_no % 256);  // 256 -0
	TCNT0 = VAR;
	OVER_FLOW++; //2
}

*

// pwm timer0
void PWM0_INIT(void)
{
	
	SETBIT(DDRB , 3);
	
	SETBIT(TCCR0 ,3);
	SETBIT(TCCR0 ,6);

	// non inverted mode
	SETBIT(TCCR0 , 5);
}
void PWM0_START(void)
{
	// select timer frequency with prescaller 256
	CLEARBIT(TCCR0 , 0);
	CLEARBIT(TCCR0 , 1);
	SETBIT(TCCR0 , 2);
}
void PWM0_STOP(void)
{
	// select timer frequency = 0
	CLEARBIT(TCCR0 , 0);
	CLEARBIT(TCCR0 , 1);
	CLEARBIT(TCCR0 , 2);
}
void PWM_SET_DC(uint8_t DC)
{
	OCR0 = (uint32_t )(DC/100.0 *256)-1;
}






void TIMER1_INIT(void)
{
	/*Bit 3 – WGM12:?Waveform Generation Mode
	Refer to TCCR1A.
	 1- set normal mode*/
	/*
	SETBIT(TCCR1B , 3);
	
	// 2- GIE enable
	
	SETBIT(SREG ,7);
	
	// 3- PIE enable
	/*This register contains interrupt control bits for several Timer/Counters, but only Timer1 bits are
	described in this section. The remaining bits are described in their respective timer sections.*
	SETBIT(TIMSK , 4);

}
void TIMER1_START(void)
{
	
	/*Clock Select Bit Description
	CA12	   CA11 	CS10	Description
	0			 0	     0		 No clock source (Timer/Counter stopped).
	0			 0	     1		 clkI/O/1 (No prescaling)
	0			 1	     0		 clkI/O/8 (From prescaler)
	0			 1	     1		 clkI/O/64 (From prescaler)
	1			 0   	 0		 clkI/O/256 (From prescaler)
	1			 0 	     1		 clkI/O/1024 (From prescaler)
	1			 1	     0		 External clock source on T1 pin. Clock on falling edge.
	1			 1	     1		 External clock source on T1 pin. Clock on rising edge.
	*
	SETBIT(TCCR1B ,0);
	CLEARBIT(TCCR1B ,1);
	SETBIT(TCCR1B ,2);
}
void TIMER1_STOP(void)
{
	CLEARBIT(TCCR1B ,0);
	CLEARBIT(TCCR1B ,1);
	CLEARBIT(TCCR1B ,2);
}
void TIMER1_DELAY(uint32_t time)
{
	if(time <= 8000)
	{
		uint32_t tick_time = 1024 /8 ; //us
		uint32_t ticks_num = (time *1000)/tick_time ;
		OCR1A = ticks_num -1 ;

	}

}
*/