/*
 * PWM.c
 *
 * Created: 9/24/2023 11:19:11 AM
 *  Author: ANDREW NASSER
 */ 

#include <HEADERS.h>

/******************************************************************************
*                               GLOBAL & EXTERN VARIABLES                     *
*******************************************************************************/

PWM_CONFIG_T* PWM_CONFIG;
PTR_VoidFunVoid_t	CALLBACK_OVF;
PTR_VoidFunVoid_t	CALLBACK_CMP;
uint8_t NUM_OVF;
uint8_t NUM_COM;





E_STATUS_t PWM_INIT(PWM_CONFIG_T* CONFIG){
	E_STATUS_t RETERVAL=E_NOK;
	if(NULL_PTR==CONFIG){
		RETERVAL=E_NOK;
	}else{
		PWM_CONFIG=CONFIG;
		
/*
WGM01  WGM00  TIMERMODE
 0		 0		 Normal 
 0		 1		 PWM, Phase Correct 
 1		 0	     CTC OCR0 
 1		 1		 Fast PWM 		
*/
		if((FAST_PWM == PWM_CONFIG->MODE) || (PH_CORRECT_PWM == PWM_CONFIG->MODE)){
			 RETERVAL=E_OK;
			if( PWM_CONFIG->MODE == FAST_PWM){
				SETBIT(TCCR0,WGM00);
				SETBIT(TCCR0,WGM01);

			}else{
				SETBIT(TCCR0,WGM00);
				CLEARBIT(TCCR0,WGM01);
			}

		}else{
			RETERVAL=E_NOK;
		}
		if (( PWM_NO_CLCK_SOURCE <= PWM_CONFIG->CLCK) && (PWM_EXTI_CLCK_RAISING >= PWM_CONFIG->CLCK))
		{
			TCCR0 |=PWM_CONFIG->CLCK;
			RETERVAL=E_OK;

		}else{
			RETERVAL=E_NOK;
		}
		if ((PWM_OCIE_DISABLE == PWM_CONFIG->OCM_INTERRUPT)|| (PWM_OCIE_ENABLE == PWM_CONFIG->OCM_INTERRUPT))
		{
			TIMSK |=PWM_CONFIG->OCM_INTERRUPT;
			RETERVAL=E_OK;

			}else{
			RETERVAL=E_NOK;
		}
		if ((PWM_TOIE_DISABLE == PWM_CONFIG->OVF_INTERRUPT)|| (PWM_TOIE_ENABLE == PWM_CONFIG->OVF_INTERRUPT))
		{
			TIMSK |=PWM_CONFIG->OVF_INTERRUPT;
			RETERVAL=E_OK;

			}else{
			RETERVAL=E_NOK;
		}
/*COM01 COM00		 Description
	0	 0		 Normal port operation, OC0 disconnected.
	0	 1			 Reserved
	1	 0		Clear OC0 on Compare Match, (non-inverting mode)
	1	 1		 Set OC0 on Compare Match, (inverting mode)
*/		
		if ((PWM_INVERTING == PWM_CONFIG->STATE) || (PWM_NON_INVERTING == PWM_CONFIG->STATE))
		{
						RETERVAL=E_OK;

			if (PWM_INVERTING == PWM_CONFIG->STATE)
			{
				SETBIT(TCCR0,COM01);
				SETBIT(TCCR0,COM00);
			}else{
				
				SETBIT(TCCR0,COM01);
				CLEARBIT(TCCR0,COM00);
			}
			}else{
			RETERVAL=E_NOK;
		}
	}
	
	
	return RETERVAL;
}
E_STATUS_t PWM_STOP(){
	
	CLEARBIT(TIMSK,CS00);
	CLEARBIT(TIMSK,CS01);
	CLEARBIT(TIMSK,CS02);
	
	
	
}

E_STATUS_t PWM_GET_CMP_VALUE(ptr_uint8_t P_TICKS){
	/*The Output Compare Register contains an 8-bit value that is continuously compared with the
	counter value (TCNT0). A match can be used to generate an output compare interrupt, or to
	generate a waveform output on the OC0 pin*/
	E_STATUS_t RETERVAL=E_NOK;
	*P_TICKS=OCR0;
	return RETERVAL;
	
	
}
E_STATUS_t PWM_SET_CMP_VALUE(uint8_t TICKS){
	
	E_STATUS_t RETERVAL=E_NOK;
	OCR0=TICKS;
	return RETERVAL;

	
	
}

E_STATUS_t PWM_GET_COUNTER_VALUE(ptr_uint8_t P_TICKS){
	
	
	E_STATUS_t RETERVAL=E_NOK;
	*P_TICKS=TCNT0;
	return RETERVAL;
	
}
E_STATUS_t PWM_SET_COUNTER_VALUE(uint8_t TICKS){
	
	E_STATUS_t RETERVAL=E_NOK;
	TICKS=TCNT0;
	return RETERVAL;
	
	
	
}

E_STATUS_t PWM_GET_OVF_VALUE(ptr_uint8_t P_TICKS){
	
	E_STATUS_t RETERVAL=E_NOK;
	*P_TICKS=NUM_OVF;
	return RETERVAL;
	
	
	
}
E_STATUS_t PWM_SET_OVF_VALUE(uint8_t TICKS){
	
	E_STATUS_t RETERVAL=E_OK;
	NUM_OVF=TICKS;
	return RETERVAL;

	
	
	
	
	
}

void PWM_SETCALLBACK_OVF_INTERRUPT(PTR_VoidFunVoid_t CALLBACK){
	
		CALLBACK=CALLBACK_OVF;

	
}
void PWM_SETCALLBACK_CMP_INTERRUPT(PTR_VoidFunVoid_t CALLBACK){
	
			CALLBACK_CMP=CALLBACK;
}

/*
ISR(TIMER0_COMP_vect){
	NUM_COM++;
	CALLBACK_CMP();
}
ISR(TIMER0_OVF_vect){
	NUM_OVF++;
	CALLBACK_OVF();
}
*/