/*
 * lcd.h
 *
 * Created: 4/20/2023 3:01:25 PM
 *  Author: ANDREW NASSER
 */


#ifndef LCD_H_
#define LCD_H_

#define F_CPU 1000000UL
#include"STM103C6_HEADERS.H"
#include "STM32F103C6_GPIO_DRIVER.h"


#define LCD_CTRL GPIOA
#define RS_SWITCH GPIO_PIN8
#define RW_SWITCH GPIO_PIN9
#define EN_SWITCH GPIO_PIN10
#define DATA_shift 4 // in 8 bit mode 0 and in 4 bit mode 4


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
#define LCD_4BITS_OPERATING			   0x32		//FOR OPERATING THE 4 BITS MODE
#define LCD_4BITS_OPERATING2		   0x33

void LCD_INIT();
void LCD_WRITE_COMMAND(unsigned char command);
void LCD_WRITE_CHAR(unsigned char character);
void LCD_WRITE_STRING(char* string);
void LCD_CHECK_BUSY(void);
void LCD_KICK(void);
void LCD_CLEAR_SCREEN();
void LCD_GOTO_XY(unsigned char line, unsigned char position);


#endif /* LCD_H_ */
