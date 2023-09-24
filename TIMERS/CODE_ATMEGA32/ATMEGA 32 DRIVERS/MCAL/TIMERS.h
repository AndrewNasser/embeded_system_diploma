/*
 * timers.h
 *
 * Created: 9/13/2023 
 *  Author: ANDREW NASSER
 */ 


#ifndef TIMERS_H_
#define TIMERS_H_
/******************************************************************************
*                               INCLUDES			                          *
*******************************************************************************/

#include <HEADERS.h>


/******************************************************************************
*									ENUMS	                				  *
*******************************************************************************/

typedef enum{
	NORMAL,
	CTC=0x08,
}TIMER0_MODE_T;

typedef enum{
	OCIE_DISABLE=0x00,
	OCIE_ENABLE=0x02

}OCM_TE0_T;

typedef enum{
	TOIE_DISABLE=0x00,
	TOIE_ENABLE=0x01

}OVF_TE0_T;


typedef enum{
	NO_CLCK_SOURCE,
	NO_PRESC,
	PRESC_CLCK8,
	PRESC_CLCK64,
	PRESC_CLCK256,
	PRESC_CLCK1024,
	EXTI_CLCK_FALLING,
	EXTI_CLCK_RAISING
}TIMER0_CLCK_T;






/******************************************************************************
*									STRUCT	                				  *
*******************************************************************************/

typedef struct{

TIMER0_MODE_T MODE;
OCM_TE0_T OCM_INTERRUPT;
OVF_TE0_T OVF_INTERRUPT;
TIMER0_CLCK_T CLCK;


}TE0_CONFIG_T;


/******************************************************************************************************
*									APIS				                      *
********************************************************************************************************/

E_STATUS_t TIMER0_INIT(TE0_CONFIG_T* CONFIG);
E_STATUS_t TIMER0_STOP();
E_STATUS_t TIMER0_GET_CMP_VALUE(ptr_uint8_t P_TICKS);		//COMPARE VALUE
E_STATUS_t TIMER0_SET_CMP_VALUE(uint8_t TICKS);
E_STATUS_t TIMER0_GET_COUNTER_VALUE(ptr_uint8_t P_TICKS);	//COUNTER VALUE
E_STATUS_t TIMER0_SET_COUNTER_VALUE(uint8_t TICKS);
E_STATUS_t TIMER0_GET_OVF_VALUE(ptr_uint8_t P_TICKS);		//OVERFLOW VALUE
E_STATUS_t TIMER0_SET_OVF_VALUE(uint8_t TICKS);

void TIMER0_SETCALLBACK_OVF_INTERRUPT(PTR_VoidFunVoid_t CALLBACK);
void TIMER0_SETCALLBACK_CMP_INTERRUPT(PTR_VoidFunVoid_t CALLBACK);

/*
void PWM0_INIT(void);
void PWM0_START(void);
void PWM0_STOP(void);
void PWM_SET_DC(uint8_t DC);	//setting the duty cycle

// ctc mode
void TIMER1_INIT(void);
void TIMER1_START(void);
void TIMER1_STOP(void);
void TIMER1_DELAY(uint32_t time);	//time refere to time desired to delay

*/


#endif /* TIMERS_H_ */