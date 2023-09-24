/*
 * ATMEGA 32 DRIVERS.c
 *
 * Created: 9/5/2023 3:13:55 AM
 * Author : ANDREW NASSER
 */ 
#include <HEADERS.h>
extern uint8_t NUM_OVF;

void TIMER_OVF_CALLBACK(){
	PORTA = ~PORTA;
}

int main()
{
	DDRA=0xFF;
	sei();
	//MCAL_PORT_DIR(DIO_PORTA, DIO_PORT_OUT);
				TIMER0_SETCALLBACK_CMP_INTERRUPT(TIMER_OVF_CALLBACK);
				TE0_CONFIG_T CONFIG={CTC,OCIE_ENABLE,TOIE_DISABLE,PRESC_CLCK8};
				TIMER0_SET_CMP_VALUE(0xF0);
				TIMER0_INIT(&CONFIG);
	
		while (1)
		{

		}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	/*
	LCD_Init();

MCAL_PORT_DIR(DIO_PORTA, DIO_PORT_IN);
MCAL_PORT_DIR(DIO_PORTB, DIO_PORT_OUT);

MCAL_PIN_MODE(DIO_PORTA,PIN0,PIN_IN);
MCAL_PIN_MODE(DIO_PORTA,PIN1,PIN_IN);
MCAL_PIN_MODE(DIO_PORTA,PIN2,PIN_IN);
MCAL_PIN_MODE(DIO_PORTA,PIN3,PIN_IN);



while(1)
{
if(DIO_READ_BIT(PORTA,PIN0)){
	TOGGLE_PIN(DIO_PORTB , PIN0);
		_delay_ms(1000);
			LCD_SendString("LEVEL 100%");
		_delay_ms(1000);
			LCD_SendCMD(LCD_Clear_Display);
			

}else if(DIO_READ_BIT(PORTA,PIN1)){
		TOGGLE_PIN(DIO_PORTB , PIN1);
			_delay_ms(500);
			LCD_SendString("LEVEL IS 75%");
			_delay_ms(500);
			LCD_SendCMD(LCD_Clear_Display);
			

}else if(DIO_READ_BIT(PORTA,PIN2)){
			TOGGLE_PIN(DIO_PORTB , PIN2);
				_delay_ms(500);
			LCD_SendString("LEVEL IS 50%");
				_delay_ms(500);
			LCD_SendCMD(LCD_Clear_Display);
			

}else if(DIO_READ_BIT(PORTA,PIN3)){
		

			TOGGLE_PIN(DIO_PORTB , PIN3);
			//MCAL_PIN_MODE(DIO_PORTB,PIN7,PIN_OUT);

				_delay_ms(500);
			LCD_SendString("!!!!!WARNING !!!!");
				_delay_ms(500);
			LCD_SendCMD(LCD_Clear_Display);
			LCD_SendString("LEVEL IS 25%");
				_delay_ms(500);
				LCD_SendCMD(LCD_Clear_Display);
				

}
}


}*/
	
