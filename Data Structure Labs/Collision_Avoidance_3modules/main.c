/*
 *
 * created on: 15/10/2022
 * By: Andrew Nasser
 *
 *
 */
#include "stdio.h"
#include "stdlib.h"
#include "CA.h"
#include "DC.h"
#include "state.h"
#include "US.h"
extern void (*CA_STATE)();
extern void (*DC_STATE)();
extern void (*US_STATE)();

void setup(){

	//init all drivers
	//init IRQ
	//init HAL
	//init Bleck
	//init pointers
	DC_INIT();
	US_INIT();
	DC_STATE = STATE_CASE(_DC_IDLE);
	US_STATE = STATE_CASE(_US_BUSY);
	CA_STATE = STATE_CASE(_CA_waiting);

}
int main (){
	setup();
	volatile int d;
while(1){
	US_STATE();
	CA_STATE();
	DC_STATE();
	for (d = 0; d<=1000;d++);
}
	return 0;
}
