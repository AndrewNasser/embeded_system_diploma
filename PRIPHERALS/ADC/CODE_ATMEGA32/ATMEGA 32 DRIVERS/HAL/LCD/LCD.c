/*
 * LCD.c
 *
 * Created: 9/10/2023 10:46:19 AM
 *  Author: ANDREW NASSER
 */ 

#include <HEADERS.h>


void LCD_Init(void)
{
	MCAL_PORT_DIR(LCD_DATA_PORT,DIO_PORT_OUT);

	MCAL_PIN_MODE(LCD_CTRL_PORT,LCD_RS_PIN,PIN_OUT);
	MCAL_PIN_MODE(LCD_CTRL_PORT,LCD_RW_PIN,PIN_OUT);
	MCAL_PIN_MODE(LCD_CTRL_PORT,LCD_E_PIN,PIN_OUT);

	_delay_ms(30);
	//function set
	LCD_SendCMD(0b00111100);
	_delay_ms(1);
	//display on
	LCD_SendCMD(0b00001111);
	_delay_ms(1);
	//clear
	LCD_SendCMD(0b00000001);
	_delay_ms(2);
	//Entry mode
	LCD_SendCMD(0b00000110);

}

void LCD_SendCMD(uint8_t cmd)
{
	// RS ----->> 0 to send cmd
	MCAL_PIN_STATE(LCD_CTRL_PORT,LCD_RS_PIN,PIN_LOW);
	// RW ----->> 0 to write
	MCAL_PIN_STATE(LCD_CTRL_PORT,LCD_RW_PIN,PIN_LOW);

	MCAL_PORT_VAL(LCD_DATA_PORT , cmd);

	// E----->> 010
	MCAL_PIN_STATE(LCD_CTRL_PORT,LCD_E_PIN,PIN_HIGH);
	_delay_ms(1);
	MCAL_PIN_STATE(LCD_CTRL_PORT,LCD_E_PIN,PIN_LOW);
	_delay_ms(1);

}
void LCD_SendChar(uint8_t data)
{
	// RS ----->> 1 to send data
	MCAL_PIN_STATE(LCD_CTRL_PORT,LCD_RS_PIN,PIN_HIGH);
	// RW ----->> 0 to write
	MCAL_PIN_STATE(LCD_CTRL_PORT,LCD_RW_PIN,PIN_LOW);

	MCAL_PORT_VAL(LCD_DATA_PORT , data);

	// E----->> 010
	MCAL_PIN_STATE(LCD_CTRL_PORT,LCD_E_PIN,PIN_HIGH);
	_delay_ms(1);
	MCAL_PIN_STATE(LCD_CTRL_PORT,LCD_E_PIN,PIN_LOW);
	_delay_ms(1);

}


void LCD_SendString(uint8_t *str)
{
	while(*str !='\0')
	{
		LCD_SendChar(*str);
		str++;
	}
}


void LCD_GoTO(uint8_t row, uint8_t clm)
{
	switch(row)
	{
		case 1: LCD_SendCMD(128+clm);	break;
		case 2: LCD_SendCMD(192+clm);	break;
	}
}

void LCD_WRITE_NUM(int num){
	char str[16];
	sprintf(str,"%d",num);	//Convert the number into an array
	LCD_SendString(str);	//Pass the array to LCD_WRITE_STRING function to be displayed
}
  
  
  /************************************************ANOTHER WAY******************************************************/
  /*
void DISPLAY_ON(){
	
	LCD_COMMAND(LCD_Clear_Display);
	_delay_us(2000);
	LCD_COMMAND(LCD_Enty_Mode_Set_Inc);
	
}
void LCD_4BITS_MODE(){
	LCD_COMMAND(LCD_Return_Home);
	LCD_COMMAND(LCD_4BITS_2LINES_5X8);
	//LCD_COMMAND(LCD_4BITS_OPERATING);
	//LCD_COMMAND(LCD_4BITS_OPERATING2);
	//LCD_COMMAND(LCD_4BITS_2LINES_5X8);
}

void LCD_ENABLE(){
	(*(volatile char *)(COMMAND))	|=	(1<<E);		//SET ENABLE START HIGH TO LOW
	_delay_ms(1);
	(*(volatile char *)(COMMAND))	&=	~(1<<E);	//RESET ENAPLE END
	_delay_us(100);
}
volatile void LCD_INIT(){
	(*(volatile char *)(DATA-1))=PORT_OUTPUT;		//DDR THE DATA AS OUTPUT
	(*(volatile char *)(COMMAND-1))=PORT_OUTPUT;	//DDR THE COMMAND AS OUTPUT
	//(*(volatile char *)(DATA-2))=0X00;				//DATA PORT IS INIT FROM GARBAGE & DATA REGISTER WHICH USED AS 1 OR 0
	(*(volatile char *)(COMMAND))&= ~(1<<E);		//RESET E PIN
	
	if (MODE==8)
	{
		_delay_ms(200);
		LCD_COMMAND(LCD_8BITS_1LINE_5X10);
		
	}
	else if (MODE==4)
	{
		_delay_ms(200);
		
		LCD_4BITS_MODE();
	}
	DISPLAY_ON();
	LCD_COMMAND(LCD_DISP_ON_CURSOR_BLINK);
}
void LCD_COMMAND(char cmd){
	(*(volatile char *)(COMMAND))	&= ~(1<<RS);	//RESET REGISTER SELECT FOR COMMAND WRITE
	if (MODE==8)
	{
		(*(volatile char *)(DATA))= cmd;		//DATA PINS EQUAL COMMAND
	}
	else if(MODE==4){
		(*(volatile char *)(DATA))= (cmd & 0xf0);		//SEND HIGH NIBBLE TO D4:D7
		LCD_ENABLE();
		(*(volatile char *)(DATA))=(cmd<<4);			//SEND LOW NIBBLE TO D4:D7
		
	}
	LCD_ENABLE();
}
void LCD_OUT(unsigned char val){
	(*(volatile char *)(DATA)) |= (1<<RS)	;	//SET REGISTER SELECT FOR DATA WRITE
	if(MODE==8){
		(*(volatile char *)(DATA))=val;
	}
	else if (MODE==4)
	{
		(*(volatile char *)(DATA))= (val & 0xf0);		//SEND HIGH NIBBLE TO D4:D7
		(*(volatile char *)(COMMAND)) |= (1<<RS);
		LCD_ENABLE();
		(*(volatile char *)(DATA))=(val<<4);
	}
	LCD_ENABLE();
}
void LCD_PRINT(char * str){
	unsigned char i=0;
	while(str[i]!=0){		//NULL VALUE AS END OF STRING ARRAY
		LCD_OUT(str[i]);
		i++;
	}
}



*/
 