/*
 * EEPROM.h
 *
 *  Created on: Aug 24, 2023
 *      Author: ANDREW NASSER
 */

#ifndef INC_EEPROM_H_
#define INC_EEPROM_H_

#include "STM103C6_HEADERS.h"

#define EEPROM_SLAVE_ADRESS		0x2A  //DEFAULT FROM DATA SHEET

void EEPROM_INIT(void);
unsigned char EEPROM_WRITE_DATA(uint32_t EEPROM_ADDRESS , uint8_t* PTXBUFFER , uint8_t DATALEN);
unsigned char EEPROM_READ_DATA( uint32_t EEPROM_ADDRESS , uint8_t* PRXBUFFER , uint8_t DATALEN);

#endif /* INC_EEPROM_H_ */
