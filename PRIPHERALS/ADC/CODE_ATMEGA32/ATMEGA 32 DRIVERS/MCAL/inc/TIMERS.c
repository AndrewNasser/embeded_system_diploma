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
/*
ISR(TIMER0_COMP_vect){
	CALLBACK_CMP();
}
ISR(TIMER0_OVF_vect){
	 NUM_OVF++;
	 CALLBACK_OVF();
}
*/




















