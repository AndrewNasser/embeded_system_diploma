/*
 * STEPPER_MOTOR.c
 *
 * Created: 9/15/2023 2:13:38 PM
 *  Author: ANDREW NASSER
 */ 

#include <HEADERS.h>


void STEPPER_MOTOR_INIT(uint8_t PORT , uint8_t coil_1 ,uint8_t coil_2 ,uint8_t coil_3 ,uint8_t coil_4){
	MCAL_PIN_MODE(PORT,coil_1,PIN_OUT);
	MCAL_PIN_MODE(PORT,coil_2,PIN_OUT);
	MCAL_PIN_MODE(PORT,coil_3,PIN_OUT);
	MCAL_PIN_MODE(PORT,coil_4,PIN_OUT);

}


void STEPPER_MOTOR_CW(uint8_t PORT , uint8_t coil_1 ,uint8_t coil_2 ,uint8_t coil_3 ,uint8_t coil_4 ,uint8_t degree ){
	uint8_t DEGREE_PER_STEP =1;
	uint8_t ITERATIONS = (degree/DEGREE_PER_STEP)/4;
	
	for(int i=0 ;i<ITERATIONS;i++){
			MCAL_PIN_STATE(PORT,coil_1,PIN_HIGH);
			MCAL_PIN_STATE(PORT,coil_2,PIN_LOW);
			MCAL_PIN_STATE(PORT,coil_3,PIN_LOW);
			MCAL_PIN_STATE(PORT,coil_4,PIN_LOW);
			_delay_ms(50);
			
			MCAL_PIN_STATE(PORT,coil_1,PIN_LOW);
			MCAL_PIN_STATE(PORT,coil_2,PIN_HIGH);
			MCAL_PIN_STATE(PORT,coil_3,PIN_LOW);
			MCAL_PIN_STATE(PORT,coil_4,PIN_LOW);
			_delay_ms(50);
			
			MCAL_PIN_STATE(PORT,coil_1,PIN_LOW);
			MCAL_PIN_STATE(PORT,coil_2,PIN_LOW);
			MCAL_PIN_STATE(PORT,coil_3,PIN_HIGH);
			MCAL_PIN_STATE(PORT,coil_4,PIN_LOW);
			_delay_ms(50);

			MCAL_PIN_STATE(PORT,coil_1,PIN_LOW);
			MCAL_PIN_STATE(PORT,coil_2,PIN_LOW);
			MCAL_PIN_STATE(PORT,coil_3,PIN_LOW);
			MCAL_PIN_STATE(PORT,coil_4,PIN_HIGH);
			_delay_ms(50);			


	}
}



void STEPPER_MOTOR_CCW(uint8_t PORT , uint8_t coil_1 ,uint8_t coil_2 ,uint8_t coil_3 ,uint8_t coil_4 , uint8_t degree){
		uint8_t DEGREE_PER_STEP =1;
		uint8_t ITERATIONS = (degree/DEGREE_PER_STEP)/4;
		for(int i=0 ;i<ITERATIONS;i++){
			MCAL_PIN_STATE(PORT,coil_1,PIN_LOW);
			MCAL_PIN_STATE(PORT,coil_2,PIN_LOW);
			MCAL_PIN_STATE(PORT,coil_3,PIN_LOW);
			MCAL_PIN_STATE(PORT,coil_4,PIN_HIGH);
			_delay_ms(50);
			
			MCAL_PIN_STATE(PORT,coil_1,PIN_LOW);
			MCAL_PIN_STATE(PORT,coil_2,PIN_LOW);
			MCAL_PIN_STATE(PORT,coil_3,PIN_HIGH);
			MCAL_PIN_STATE(PORT,coil_4,PIN_LOW);
			_delay_ms(50);
			
			MCAL_PIN_STATE(PORT,coil_1,PIN_LOW);
			MCAL_PIN_STATE(PORT,coil_2,PIN_HIGH);
			MCAL_PIN_STATE(PORT,coil_3,PIN_LOW);
			MCAL_PIN_STATE(PORT,coil_4,PIN_LOW);
			_delay_ms(50);

			MCAL_PIN_STATE(PORT,coil_1,PIN_HIGH);
			MCAL_PIN_STATE(PORT,coil_2,PIN_LOW);
			MCAL_PIN_STATE(PORT,coil_3,PIN_LOW);
			MCAL_PIN_STATE(PORT,coil_4,PIN_LOW);
			_delay_ms(50);


		}
		
}