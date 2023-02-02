<<<<<<< HEAD
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



int Distance_Random (int l ,int r ,int count);
enum US_STATE US_STATUS;
int Distance = 0;


void (*US_STATE)();

void US_INIT(){
	printf("US_init \n");
};

STATE_define(_US_BUSY){
	//state name
		US_STATUS = US_BUSY;
		//state action
		Distance = Distance_Random (45,55,1);
		//DC_Motor

		printf("US_Driving_State : Distance = %d \n",Distance);
		US_Set_distance(Distance);

};

int Distance_Random (int l ,int r ,int count){
	int i ;
	for(i = 0 ; i < count ; i++){
		int  rand_num = (rand() % (r - l + 1)) + l;
		return rand_num;
	}
return 0;

}



=======
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



int Distance_Random (int l ,int r ,int count);
enum US_STATE US_STATUS;
int Distance = 0;


void (*US_STATE)();

void US_INIT(){
	printf("US_init \n");
};

STATE_define(_US_BUSY){
	//state name
		US_STATUS = US_BUSY;
		//state action
		Distance = Distance_Random (45,55,1);
		//DC_Motor

		printf("US_Driving_State : Distance = %d \n",Distance);
		US_Set_distance(Distance);

};

int Distance_Random (int l ,int r ,int count){
	int i ;
	for(i = 0 ; i < count ; i++){
		int  rand_num = (rand() % (r - l + 1)) + l;
		return rand_num;
	}
return 0;

}



>>>>>>> 310178b6b37516b4afa740e5a39e05d6b1367656
