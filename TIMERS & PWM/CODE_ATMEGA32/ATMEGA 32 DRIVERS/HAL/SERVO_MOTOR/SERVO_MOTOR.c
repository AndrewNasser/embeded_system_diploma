/*
 * SERVO_MOTOR.c
 *
 * Created: 9/15/2023 9:43:30 AM
 *  Author: ANDREW NASSER
 */ 
#include <HEADERS.h>


void SERVO_INIT(void)
{
	PWM0_INIT();
}
void SERVO_ANGLE(uint8_t angle)
{
	
	/*OCR0 – Output Compare Register
	When using the I/O specific commands IN and OUT, the I/O addresses 0x00 - 0x3F must be used. When
	addressing I/O Registers as data space using LD and ST instructions, 0x20 must be added to these offset
	addresses.
	The Output Compare Register contains an 8-bit value that is continuously compared with the counter
	value (TCNT0). A match can be used to generate an Output Compare interrupt, or to generate a
	waveform output on the OC0 pin.*/
	
	OCR0 = (uint32_t)((float)(angle * 32.0)/180 +30 );
	PWM0_START();
}