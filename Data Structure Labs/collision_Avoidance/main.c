<<<<<<< HEAD
#include "CA.h"
#include"state.h"


void setup(){

	//init all drivers
	//init IRQ
	//init HAL
	//init Bleck
	//init pointers
	CA_state = ST_CA_waiting ;


}
int main (){
	setup();
while(1){
	CA_state();
}
	return 0;
}
=======
#include "CA.h"
#include"state.h"


void setup(){

	//init all drivers
	//init IRQ
	//init HAL
	//init Bleck
	//init pointers
	CA_state = ST_CA_waiting ;


}
int main (){
	setup();
while(1){
	CA_state();
}
	return 0;
}
>>>>>>> 310178b6b37516b4afa740e5a39e05d6b1367656
