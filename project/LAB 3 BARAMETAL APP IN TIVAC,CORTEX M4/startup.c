#include <stdint.h>
extern int main(void);
void Reset_Handler (void);
void default_handler (){
	Reset_Handler();
}
void NMI_Handler (void) __attribute__ ((weak, alias ("default_handler")));
void H_fault_Handler (void) __attribute__ ((weak, alias ("default_handler")));
//boking 1024 byte located by .bss through un intialized arr of int 256 elment(256*4)
static unsigned long stack_topp[256] ;
void ( * const global_pointer_fun_vectors[]) () __attribute__((sections(".vectors"))) =
{
	(void (*)())	((unsigned long)stack_topp + sizeof(stack_topp)),
	&Reset_Handler,
	&NMI_Handler,
	&H_fault_Handler,

};
extern unsigned int _S_DATA;
extern unsigned int _E_DATA;
extern unsigned int _S_bss;
extern unsigned int _E_bss;
extern unsigned int _E_TEXT;

void Reset_Handler(void){
	int i;
unsigned int DATA_SIZE = (unsigned char*)&_E_DATA - (unsigned char*)&_S_DATA;
unsigned char* P_src = (unsigned char*)&_E_TEXT;
unsigned char* P_dst = (unsigned char*)&_S_DATA;
for(i=0;i<DATA_SIZE;i++){
	*((unsigned char*)P_dst++) = *((unsigned char*)P_src++);

}
unsigned int BSS_SIZE = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss;
P_dst = (unsigned char*)&_S_bss;
for(i=0;i<BSS_SIZE;i++){
		*((unsigned char*)P_dst++) = (unsigned char)0 ;

}
	main();
}