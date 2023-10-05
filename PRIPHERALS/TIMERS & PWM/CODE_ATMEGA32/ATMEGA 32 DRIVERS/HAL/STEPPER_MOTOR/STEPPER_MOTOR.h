/*
 * STEPPER_MOTOR.h
 *
 * Created: 9/12/2023 2:13:25 PM
 *  Author: ANDREW NASSER
 */ 


#ifndef STEPPER_MOTOR_H_
#define STEPPER_MOTOR_H_

void STEPPER_MOTOR_INIT(uint8_t PORT , uint8_t coil_1 ,uint8_t coil_2 ,uint8_t coil_3 ,uint8_t coil_4);

void STEPPER_MOTOR_CW(uint8_t PORT , uint8_t coil_1 ,uint8_t coil_2 ,uint8_t coil_3 ,uint8_t coil_4 ,uint8_t degree );	

void STEPPER_MOTOR_CCW(uint8_t PORT , uint8_t coil_1 ,uint8_t coil_2 ,uint8_t coil_3 ,uint8_t coil_4 , uint8_t degree);




#endif /* STEPPER_MOTOR_H_ */