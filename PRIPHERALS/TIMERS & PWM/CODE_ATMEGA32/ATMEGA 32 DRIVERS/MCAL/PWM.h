/*
 * PWM.h
 *
 * Created: 9/24/2023 11:19:32 AM
 *  Author: ANDREW NASSER
 */ 


#ifndef PWM_H_
#define PWM_H_


/******************************************************************************
*									ENUMS	                				  *
*******************************************************************************/

typedef enum{
	FAST_PWM=0x40,
	PH_CORRECT_PWM=0x08
}PWM_MODE_T;


typedef enum{
	PWM_OCIE_DISABLE=0x00,
	PWM_OCIE_ENABLE=0x02

}PWM_OCM_T;

typedef enum{
	PWM_TOIE_DISABLE=0x00,
	PWM_TOIE_ENABLE=0x01

}PWM_OVF_T;

typedef enum{
	PWM_NO_CLCK_SOURCE,
	PWM_NO_PRESC,
	PWM_PRESC_CLCK8,
	PWM_PRESC_CLCK64,
	PWM_PRESC_CLCK256,
	PWM_PRESC_CLCK1024,
	PWM_EXTI_CLCK_FALLING,
	PWM_EXTI_CLCK_RAISING
}PWM_CLCK_T;



typedef enum
{
	PWM_INVERTING = 0x30,
	PWM_NON_INVERTING = 0x20
}PWM_STATE_T;




/******************************************************************************
*									STRUCT	                				  *
*******************************************************************************/

typedef struct{

	PWM_MODE_T MODE;
	PWM_OCM_T OCM_INTERRUPT;
	PWM_OVF_T OVF_INTERRUPT;
	PWM_CLCK_T CLCK;
	PWM_STATE_T STATE;

}PWM_CONFIG_T;



/******************************************************************************************************
*									APIS				                      *
********************************************************************************************************/

E_STATUS_t PWM_INIT(PWM_CONFIG_T* CONFIG);
E_STATUS_t PWM_STOP();

E_STATUS_t PWM_GET_CMP_VALUE(ptr_uint8_t P_TICKS);		//COMPARE VALUE
E_STATUS_t PWM_SET_CMP_VALUE(uint8_t TICKS);

E_STATUS_t PWM_GET_COUNTER_VALUE(ptr_uint8_t P_TICKS);	//COUNTER VALUE
E_STATUS_t PWM_SET_COUNTER_VALUE(uint8_t TICKS);

E_STATUS_t PWM_GET_OVF_VALUE(ptr_uint8_t P_TICKS);		//OVERFLOW VALUE
E_STATUS_t PWM_SET_OVF_VALUE(uint8_t TICKS);

void PWM_SETCALLBACK_OVF_INTERRUPT(PTR_VoidFunVoid_t CALLBACK);
void PWM_SETCALLBACK_CMP_INTERRUPT(PTR_VoidFunVoid_t CALLBACK);

#endif /* PWM_H_ */