/*
 * GPIO.h
 *
 * Created: 9/5/2023 3:18:20 AM
 *  Author: King 45M
 */ 


#ifndef GPIO_H_
#define GPIO_H_




/*The DDxn bit in the DDRx Register selects the direction of this pin. If DDxn is written logic one, Pxn is
configured as an output pin. If DDxn is written logic zero, Pxn is configured as an input pin.*/

#define OUTPUT_PIN	1
#define INPUT_PIN	0

/*If PORTxn is written logic one when the pin is configured as an input pin, the pull-up resistor is activated.
To switch the pull-up resistor off, PORTxn has to be written logic zero or the pin has to be configured as
an output pin. The port pins are tri-stated when reset condition becomes active, even if no clocks are
running.
If PORTxn is written logic one when the pin is configured as an output pin, the port pin is driven high
(one). If PORTxn is written logic zero when the pin is configured as an output pin, the port pin is driven
low (zero)*/


#define  DIO_PORTA	0
#define  DIO_PORTB	1
#define  DIO_PORTC	2
#define  DIO_PORTD	3

#define  DIO_PORT_OUT    0xff
#define  DIO_PORT_IN     0x00

#define  DIO_PORT_HIGH    0xff
#define  DIO_PORT_LOW     0x00

#define PIN_OUT		1
#define PIN_IN		0

#define PIN_HIGH		1
#define PIN_LOW			0


#define PIN0   0
#define PIN1   1
#define PIN2   2
#define PIN3   3
#define PIN4   4
#define PIN5   5
#define PIN6   6
#define PIN7   7


void MCAL_PORT_DIR(uint8_t PORT,uint8_t DIR);
void MCAL_PORT_STATE(uint8_t PORT,uint8_t STATE);

void MCAL_PIN_MODE(uint8_t PORT,uint8_t PIN,uint8_t DIR);
void MCAL_PIN_STATE(uint8_t PORT,uint8_t PIN,uint8_t STATE);
void TOGGLE_PIN(uint8_t PORT , uint8_t PIN);
uint8_t DIO_READ_BIT(uint8_t PORT , uint8_t PIN );

#endif /* GPIO_H_ */