<<<<<<< HEAD
/* created on: 15/10/2022
 * By: Andrew Nasser
 */
#include "stdio.h"
#include "stdlib.h"
#include "CA.h"
#include "DC.h"
#include "state.h"
#include "US.h"

enum DC_STATE DC_STATUS;
int Speed = 0;

void (*DC_STATE)();

void DC_INIT(){
	printf("DC_INIT\n");
}

void DC_motor(int S){
	Speed = S;
	DC_STATE = STATE_CASE(_DC_BUSY);
	printf("CA -----speed=%d-----> DC\n",Speed);

}


STATE_define(_DC_IDLE){
	//state name
	DC_STATUS = DC_IDLE;

	printf("DC_IDLE_State : speed = %d \n",Speed);
};
STATE_define(_DC_BUSY){
	//state name
		DC_STATUS = DC_BUSY;
		DC_STATE = STATE_CASE(_DC_IDLE);
		printf("DC_BUSY_State : speed = %d \n",Speed);

};


=======
/* created on: 15/10/2022
 * By: Andrew Nasser
 */
#include "stdio.h"
#include "stdlib.h"
#include "CA.h"
#include "DC.h"
#include "state.h"
#include "US.h"

enum DC_STATE DC_STATUS;
int Speed = 0;

void (*DC_STATE)();

void DC_INIT(){
	printf("DC_INIT\n");
}

void DC_motor(int S){
	Speed = S;
	DC_STATE = STATE_CASE(_DC_BUSY);
	printf("CA -----speed=%d-----> DC\n",Speed);

}


STATE_define(_DC_IDLE){
	//state name
	DC_STATUS = DC_IDLE;

	printf("DC_IDLE_State : speed = %d \n",Speed);
};
STATE_define(_DC_BUSY){
	//state name
		DC_STATUS = DC_BUSY;
		DC_STATE = STATE_CASE(_DC_IDLE);
		printf("DC_BUSY_State : speed = %d \n",Speed);

};


>>>>>>> 310178b6b37516b4afa740e5a39e05d6b1367656
