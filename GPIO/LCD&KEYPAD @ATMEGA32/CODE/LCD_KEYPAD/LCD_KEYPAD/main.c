/*
 * LCD_KEYPAD.c
 *
 * Created: 3/18/2023 2:40:20 PM
 * Author : King 45M
 */ 

#include <avr/io.h>
#include <KEYPAD.h>
#include <LCD_DRIVER.h>

int main(void)
{
	LCD_INIT();
	KEYPAD_INIT();
	char key;

    while (1) 
    {
		key=KEYPAD_CHAR();
		switch (key)
		{
		 case  ('\0'):
		  break;			//DEFAULT
		case  ('!'):
		LCD_COMMAND( LCD_Clear_Display);
		 break;
		 default:
		 LCD_OUT(key);
  
		}
    }
}

