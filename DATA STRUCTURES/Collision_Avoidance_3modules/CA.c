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
enum CA_STATE CA_STATUS;
extern int Speed ;
extern int Distance ;
int Threshold = 50;

void (*CA_STATE)();

void US_Set_distance(int D){
	Distance = D;
	(Distance <= Threshold)?(CA_STATE = STATE_CASE(_CA_waiting) ) : (CA_STATE =  STATE_CASE(_CA_driving));
	printf("US -----distance=%d-----> CA\n",Distance);
}

STATE_define(_CA_waiting){
	//state name
	CA_STATUS = CA_waiting;

	//state action
	Speed = 0;
	//DC_Motor
	DC_motor(Speed);
	printf("CA_Waiting_State : Distance = %d , Speed = %d\n",Distance,Speed);

};
STATE_define(_CA_driving)
{
	//state name
		CA_STATUS = CA_driving;
		//state action
		Speed = 30;
		//DC_Motor
		DC_motor(Speed);
		printf("CA_Driving_State : Distance = %d , Speed = %d\n",Distance,Speed);


};


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
enum CA_STATE CA_STATUS;
extern int Speed ;
extern int Distance ;
int Threshold = 50;

void (*CA_STATE)();

void US_Set_distance(int D){
	Distance = D;
	(Distance <= Threshold)?(CA_STATE = STATE_CASE(_CA_waiting) ) : (CA_STATE =  STATE_CASE(_CA_driving));
	printf("US -----distance=%d-----> CA\n",Distance);
}

STATE_define(_CA_waiting){
	//state name
	CA_STATUS = CA_waiting;

	//state action
	Speed = 0;
	//DC_Motor
	DC_motor(Speed);
	printf("CA_Waiting_State : Distance = %d , Speed = %d\n",Distance,Speed);

};
STATE_define(_CA_driving)
{
	//state name
		CA_STATUS = CA_driving;
		//state action
		Speed = 30;
		//DC_Motor
		DC_motor(Speed);
		printf("CA_Driving_State : Distance = %d , Speed = %d\n",Distance,Speed);


};


>>>>>>> 310178b6b37516b4afa740e5a39e05d6b1367656
