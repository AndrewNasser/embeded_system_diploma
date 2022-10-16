/* created on: 10/9/2022
 * By: Andrew Nasser
 */
#include"stdio.h"
#include"CA.h"
 int CA_speed=0;
 int CA_distance=0;
 int CA_threeshold=50;
void (*CA_state)();
 int Distance_Random (int l,int r, int count);
void ST_CA_waiting(){
	 /*state name*/
	 CA_state_id=CA_waiting;
	 /*state action*/
	 CA_speed=0;
	 CA_distance= Distance_Random(45,55,1);
	 /*dc motor*/
	 /*event check*/

	 (CA_distance<=CA_threeshold)?	(CA_state=ST_CA_waiting) : (CA_state=ST_CA_driving);
	 printf("waiting state--> speed=%d  distance=%d",CA_speed,CA_distance);



 }
 void ST_CA_driving(){
 	 /*state name*/
 	 CA_state_id=CA_driving;
 	 /*state action*/
 	 CA_speed=30;
 	 CA_distance= Distance_Random(45,55,1);
 	 /*dc motor*/
 	 /*event check*/

 	 (CA_distance<=CA_threeshold)?	(CA_state=ST_CA_waiting) : (CA_state=ST_CA_driving);
 	 printf("waiting state--> speed=%d distance=%d \n",CA_speed,CA_distance);



  }
 int Distance_Random (int l ,int r ,int count){
 	int i ;
 	for(i = 0 ; i < count ; i++){
 		int  rand_num = (rand() % (r - l + 1)) + l;
 		return rand_num;
 	}
 return 0;

 }
