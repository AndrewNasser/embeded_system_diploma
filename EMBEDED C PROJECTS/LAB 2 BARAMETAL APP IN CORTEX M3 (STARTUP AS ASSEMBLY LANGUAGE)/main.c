typedef volatile unsigned int vuint32_t ;
#include<stdint.h>
#define RCC_BASE   0x40021000
#define GPIO_BASE 0x40010800
#define RCC_APB2ENR *(volatile uint32_t*) (RCC_BASE+0x18)
#define GPIO_CRH    *(volatile uint32_t*) (GPIO_BASE+0x04)
#define GPIO_ODR    *(volatile uint32_t*) (GPIO_BASE+0x0C)
#define RCC_IOPAEN	(1<<2)
#define GPIO13	    (1UL<<13)

typedef union {
	vuint32_t	all_fields;
	struct {
		vuint32_t	reserved:13;
		vuint32_t	p_13:1 ;
	} pin;

} R_ODR_t;
volatile R_ODR_t*	R_ODR = (volatile R_ODR_t*)(GPIO_BASE + 0x0c);
int main(void)
{
	int i;
	RCC_APB2ENR|= RCC_IOPAEN; //to set 1 bit
	GPIO_CRH &= 0xFF0FFFFF;  //make 4 bit as to or with 2 (in binary 0010) in next step
	GPIO_CRH|=  0x00200000;
	while(1){
		R_ODR->pin.p_13 = 1;
		for(i=0;i<5000;i++); //delay counter
		R_ODR->pin.p_13 = 0;  //reset specific bit
		for(i=0;i<5000;i++);

	}



	return 0;
}