/*
 * LM35.h
 *
 * Created: 10/4/2023 10:17:01 PM
 *  Author: ANDREW NASSER
 */ 

#include <HEADERS.h>

#ifndef LM35_H_
#define LM35_H_


void LM35_INIT(enum ADC_CHANNEL CH);

uint16_t LM35_TEMPERTURE(enum ADC_CHANNEL CH);


#endif /* LM35_H_ */