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
