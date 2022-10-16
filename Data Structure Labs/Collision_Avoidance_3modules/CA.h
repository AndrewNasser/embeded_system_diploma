/*
 * CA.h
 *
 *  Created on: Oct 15, 2022
 *      Author: Andrew Nasser
 */

#ifndef CA_H_
#define CA_H_
#include "stdio.h"
#include "stdlib.h"
#include "state.h"
enum CA_STATE{
	CA_waiting,
	CA_driving
};

STATE_define(_CA_waiting);
STATE_define(_CA_driving);

#endif /* CA_H_ */
