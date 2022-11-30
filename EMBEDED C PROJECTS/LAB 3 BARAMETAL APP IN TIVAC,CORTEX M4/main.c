typedef volatile unsigned int vuint32_t ;
#include<stdint.h>
#define SYSCTL_RCGC2_R	(*((volatile unsigned long*)0x400FE108))
#define GPIO_PORTF_DIR_R	(*((volatile unsigned long*)0x40025400))
#define GPIO_PORTF_DEN_R	(*((volatile unsigned long*)0x4002551C))
#define GPIO_PORTF_DATA_R	(*((volatile unsigned long*)0x400253FC))

int main()
{
		volatile unsigned long counter ;
		SYSCTL_RCGC2_R = 0x00000020;
		//delay to make sure gpio is up and run
		for(counter=0 ; counter<200;counter++);
		GPIO_PORTF_DIR_R |= 1<<3 ; 
		GPIO_PORTF_DEN_R |= 1<<3 ;
		while(1)
		{
			GPIO_PORTF_DATA_R |=1<<3 ;
			for(counter=0 ; counter<2000;counter++);
				GPIO_PORTF_DATA_R &=~(1<<3) ;
			for(counter=0 ; counter<2000;counter++);
		} 



	return 0;
}