/*
 * GccApplication4.c
 *
 * Created: 3/4/2023 2:42:48 AM
 * Author : King 45M
 */ 

#include <avr/io.h>
#include "LCD_DRIVER.h"

/*int main(void)
{
	LCD_INIT();
	LCD_PRINT("andrew");
	while (1)
	{
	}
}*/

void LCD_4BITS_MODE(){
	LCD_COMMAND(LCD_Return_Home);
	LCD_COMMAND(LCD_4BITS_OPERATING);
	LCD_COMMAND(LCD_4BITS_2LINES_5X8);

}
void DISPLAY_ON(){
	LCD_COMMAND(LCD_4BITS_OPERATING);
	LCD_COMMAND(LCD_Clear_Display);
	_delay_us(2000);
	LCD_COMMAND(LCD_Enty_Mode_Set_Inc);

}
void LCD_ENABLE(){
	(*(volatile char *)(COMMAND+2))	|=	(1<<E);		//SET ENABLE START HIGH TO LOW
	_delay_ms(1);
	(*(volatile char *)(COMMAND+2))	&=	~(1<<E);	//RESET ENAPLE END
	_delay_us(100);
}
volatile void LCD_INIT(){
	
	(*(volatile char *)(DATA+1))=PORT_OUTPUT;		//DDR THE DATA AS OUTPUT
	(*(volatile char *)(COMMAND+1))=PORT_OUTPUT;	//DDR THE COMMAND AS OUTPUT
	(*(volatile char *)(DATA+2))=0X00;				//DATA PORT IS INIT FROM GARBAGE
	(*(volatile char *)(COMMAND+2))&= ~(1<<E);		//RESET E PIN
	if (MODE==8)
	{
		_delay_us(2000);
		LCD_COMMAND(LCD_8BITS_2LINES_5X8);
	}
	else if (MODE==4)
	{
		LCD_4BITS_MODE();
		
	}
	DISPLAY_ON();
}
void LCD_COMMAND(char cmd){
	(*(volatile char *)(COMMAND+2))	&= ~(1<<RS);	//RESET REGISTER SELECT FOR COMMAND WRITE
	if (MODE==8)
	{
		(*(volatile char *)(DATA+2))= cmd;		//DATA PINS EQUAL COMMAND
	}
	else if(MODE==4){
		(*(volatile char *)(DATA+2))= (cmd & 0xf0);		//SEND HIGH NIBBLE TO D4:D7
		LCD_ENABLE();
		(*(volatile char *)(DATA+2))=(cmd<<4);			//SEND LOW NIBBLE TO D4:D7
		
	}
	LCD_ENABLE();
}
void LCD_OUT(unsigned char val){
	(*(volatile char *)(DATA+2)) |= (1<<RS);		//SET REGISTER SELECT FOR DATA WRITE
	if(MODE==8){
		(*(volatile char *)(DATA+2))=val;
	}
	else if (MODE==4)
	{
		(*(volatile char *)(DATA+2))= (val & 0xf0);		//SEND HIGH NIBBLE TO D4:D7
		(*(volatile char *)(COMMAND+2)) |= (1<<RS);
		LCD_ENABLE();
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


