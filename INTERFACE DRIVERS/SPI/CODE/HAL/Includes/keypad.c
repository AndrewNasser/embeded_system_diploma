/*
 * keypad.c
 *
 * Created: 4/20/2023 3:01:25 PM
 *  Author: ANDREW NASSER
 */

#include"STM32F103C6_GPIO_DRIVER.h"
#include"STM32F103X6.h"
#include"keypad.h"
int Key_padRow[] = { R0, R1, R2, R3 }; //rows of the keypad
int Key_padCol[] = { C0, C1, C2, C3 }; //columns

void delay_mss(uint32_t time) {
	uint32_t i, j;
	for (i = 0; i < time; i++)
		for (j = 0; j < 255; j++)
			;
}

void Keypad_init() {

	GPIO_PINCONFIG_T PINCFG ;

	PINCFG.GPIO_PIN_NUMBER = R0;
	PINCFG.GPIO_MODE=GPIO_MODE_PUSH_PULL;
	PINCFG.GPIO_SPEED_OUTPUT=GPIO_SPEED_10M;
	MCAL_GPIO_INIT(KEYPAD_PORT, &PINCFG);

	PINCFG.GPIO_PIN_NUMBER = R1;
	PINCFG.GPIO_MODE =GPIO_MODE_PUSH_PULL;
	PINCFG.GPIO_SPEED_OUTPUT=GPIO_SPEED_10M;
	MCAL_GPIO_INIT(KEYPAD_PORT, &PINCFG);

	PINCFG.GPIO_PIN_NUMBER = R2;
	PINCFG.GPIO_MODE =GPIO_MODE_PUSH_PULL;
	PINCFG.GPIO_SPEED_OUTPUT=GPIO_SPEED_10M;
	MCAL_GPIO_INIT(KEYPAD_PORT, &PINCFG);

	PINCFG.GPIO_PIN_NUMBER = R3;
	PINCFG.GPIO_MODE =GPIO_MODE_PUSH_PULL;
	PINCFG.GPIO_SPEED_OUTPUT=GPIO_SPEED_10M;
	MCAL_GPIO_INIT(KEYPAD_PORT, &PINCFG);

	PINCFG.GPIO_PIN_NUMBER = C0;
	PINCFG.GPIO_MODE =GPIO_MODE_PUSH_PULL;
	PINCFG.GPIO_SPEED_OUTPUT=GPIO_SPEED_10M;
	MCAL_GPIO_INIT(KEYPAD_PORT, &PINCFG);

	PINCFG.GPIO_PIN_NUMBER = C1;
	PINCFG.GPIO_MODE =GPIO_MODE_PUSH_PULL;
	PINCFG.GPIO_SPEED_OUTPUT=GPIO_SPEED_10M;
	MCAL_GPIO_INIT(KEYPAD_PORT, &PINCFG);

	PINCFG.GPIO_PIN_NUMBER = C2;
	PINCFG.GPIO_MODE =GPIO_MODE_PUSH_PULL;
	PINCFG.GPIO_SPEED_OUTPUT=GPIO_SPEED_10M;
	MCAL_GPIO_INIT(KEYPAD_PORT, &PINCFG);

	PINCFG.GPIO_PIN_NUMBER = C3;
	PINCFG.GPIO_MODE =GPIO_MODE_PUSH_PULL;
	PINCFG.GPIO_SPEED_OUTPUT=GPIO_SPEED_10M;
	MCAL_GPIO_INIT(KEYPAD_PORT, &PINCFG);
	MCAL_GPIO_WRITEPORT(KEYPAD_PORT, 0xFF);

}

char Keypad_getkey() {
	int i, j;
	for (i = 0; i < 4; i++) {

		MCAL_GPIO_WRITEPIN(KEYPAD_PORT, Key_padCol[0], GPIO_PIN_SET);
		MCAL_GPIO_WRITEPIN(KEYPAD_PORT, Key_padCol[1], GPIO_PIN_SET);
		MCAL_GPIO_WRITEPIN(KEYPAD_PORT, Key_padCol[2], GPIO_PIN_SET);
		MCAL_GPIO_WRITEPIN(KEYPAD_PORT, Key_padCol[3], GPIO_PIN_SET);
		MCAL_GPIO_WRITEPIN(KEYPAD_PORT, Key_padCol[i], GPIO_PIN_RESET);
		for (j = 0; j < 4; j++) {
			if (MCAL_GPIO_READPIN(KEYPAD_PORT, Key_padRow[j]) == 0) {
				while (MCAL_GPIO_READPIN(KEYPAD_PORT, Key_padRow[j]) == 0)
					;
				switch (i) {
				case (0):
					if (j == 0)
						return '7';
					else if (j == 1)
						return '4';
					else if (j == 2)
						return '1';
					else if (j == 3)
						return '?';
					break;
				case (1):
					if (j == 0)
						return '8';
					else if (j == 1)
						return '5';
					else if (j == 2)
						return '2';
					else if (j == 3)
						return '0';
					break;
				case (2):
					if (j == 0)
						return '9';
					else if (j == 1)
						return '6';
					else if (j == 2)
						return '3';
					else if (j == 3)
						return '=';
					break;
				case (3):
					if (j == 0)
						return '/';
					else if (j == 1)
						return '*';
					else if (j == 2)
						return '-';
					else if (j == 3)
						return '+';
					break;
				}
			}
		}
	}
	return 'A';
}
