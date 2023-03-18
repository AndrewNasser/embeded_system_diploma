/*
 * LCD_DRIVER.h
 *
 * Created: 3/4/2023 1:15:43 AM
 *  Author: King 45M
 */ 


#ifndef LCD_DRIVER_H_
#define LCD_DRIVER_H_
#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 1000000UL

//FOR USER WRITE THE PORT AND PINS WHICH USES HERE
#define DATA	A
#define COMMAND	C
#define RS	2
#define E	1
#define MODE	4

//PORT BASE ADDRESS
#define	A	0x39
#define B	0x36
#define C	0x33
#define D	0x30
#define PORT_OUTPUT	0XFF
//LCD INSTRUCTIONS
#define LCD_Clear_Display              0x01		//CLEAR DISPLAY SCREEN
#define LCD_Return_Home                0x02		//RETURN HOME
#define LCD_Enty_Mode_Set_Dec          0x04		//ENTY MODE SET DECREMENT
#define LCD_Enty_Mode_Set_Inc_Shift    0x05		//SHIFT DISPLAY RIGHT
#define LCD_Enty_Mode_Set_Inc          0x06		//ENTY MODE SET INCREMENT
#define LCD_Enty_Mode_Set_Dec_Shift    0x07		//SHIFT DISPLAY LEFT
#define LCD_DISP_OFF                   0x08		//DISPLAY OFF , CURSOR OFF
#define LCD_DISP_ON                    0x0C		//DISPLAY ON, CURSOR OFF
#define LCD_DISP_ON_BLINK              0x0D		//DISPLAY OFF, CURSOR ON
#define LCD_DISP_ON_CURSOR             0x0E		//DISPLAY ON CURSOR BLINKING
#define LCD_DISP_ON_CURSOR_BLINK       0x0F
#define LCD_MOV_CURSOR_LEFT            0x10		//SHIFT CURSOR TO LIFT
#define LCD_MOV_CURSOR_RIGHT           0x14		//SHIFT CURSOR TO RIGHT
#define LCD_MOV_DISP_LEFT              0x18		//SHIFT ENTIRE DISPLAY TO LEFT
#define LCD_MOV_DISP_RIGHT             0x1C		//SHIFT ENTIRE DISPLAY TO RIGHT
#define LCD_4BITS_2LINES_5X10          0x2C
#define LCD_4BITS_2LINES_5X8           0x28		//2 LINES - 5*7 MATRIX (D4-D7,4BIT)
#define LCD_4BITS_1LINE_5X10           0x24
#define LCD_4BITS_1LINE_5X8            0x20
#define LCD_8BITS_2LINES_5X10          0x3C
#define LCD_8BITS_2LINES_5X8           0x38		//2 LINES - 5*7 MATRIX (D0-D7,8 BIT)
#define LCD_8BITS_1LINE_5X10           0x34
#define LCD_8BITS_1LINE_5X8            0x30
#define LCD_ROW1_COLUMN1               0x80		//FORCE CURSOR TO BEGINING 1st LINE
#define LCD_ROW2_COLUMN2			   0xC0		//FORCE CURSOR TO BEGINING 2nd LINE
#define LCD_4BITS_OPERATING			   0X32		//FOR OPERATING THE 4 BITS MODE
#define LCD_4BITS_OPERATING2		   0x33
//LCD FUNCTIONS
void LCD_INIT();
void LCD_COMMAND(char cmd);
void LCD_ENABLE();
void LCD_OUT(unsigned char val);
void LCD_PRINT(char * str);
void LCD_4BITS_MODE();
void DISPLAY_ON();

#endif /* LCD_DRIVER_H_ */