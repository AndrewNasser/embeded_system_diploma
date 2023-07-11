/*
 * STM32F103C6_GPIO_DRIVER.c
 *
 *  Created on: Mar 20, 2023
 *      Author:ANDREW NASSER
 */


#include"STM32F103C6_GPIO_DRIVER.h"
#include"STM32F103C6_EXTI_DRIVER.h"
#include"STM32F103X6.h"



//============================================================GENERIC VARIABLES====================================================//
//=================================================================================================================================//

void(* GP_IRQ_CALLBACK[15])(void);

//============================================================GENERIC MACROS=======================================================//
//=================================================================================================================================//

#define AFIO_GPIO_EXTI_MAPPING(x)	(	(x==GPIOA)?0:\
										(x==GPIOB)?1:\
										(x==GPIOC)?2:\
										(x==GPIOD)?3:0			)//LIKE IF CONDITION






//============================================================GENERIC FUNCTIONS====================================================//
//=================================================================================================================================//

void ENABLE_NVIC(uint16_t IRQ){
	switch(IRQ){
	case 0:
		NVIC_IRQ6_EXTI0_ENABLE;
		break;
	case 1:
		NVIC_IRQ7_EXTI1_ENABLE;
		break;
	case 2:
		NVIC_IRQ8_EXTI2_ENABLE;
		break;
	case 3:
		NVIC_IRQ9_EXTI3_ENABLE;
		break;
	case 4:
		NVIC_IRQ10_EXTI4_ENABLE;
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IRQ23_EXTI5_9_ENABLE;

	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_IRQ40_EXTI10_15_ENABLE;

	}
}

void DISABLE_NVIC(uint16_t IRQ){
	switch(IRQ){
	case 0:
		NVIC_IRQ6_EXTI0_DISABLE;
		break;
	case 1:
		NVIC_IRQ7_EXTI1_DISABLE;
		break;
	case 2:
		NVIC_IRQ8_EXTI2_DISABLE;
		break;
	case 3:
		NVIC_IRQ9_EXTI3_DISABLE;
		break;
	case 4:
		NVIC_IRQ10_EXTI4_DISABLE;
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IRQ23_EXTI5_9_DISABLE;

	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_IRQ40_EXTI10_15_DISABLE;

	}
}



void UPDATE_EXTI(EXTI_PINCONFIG_t *EXTI_CONFIG){



	//CONFIGURE GPIO TO BE ALTERNATIVE FUNCTION INPUT


	GPIO_PINCONFIG_T PINCFG;
	PINCFG.GPIO_PIN_NUMBER= EXTI_CONFIG->EXTI_PIN.GPIO_PIN;
	PINCFG.GPIO_MODE = GPIO_MODE_FLOATING;
	MCAL_GPIO_INIT(EXTI_CONFIG->EXTI_PIN.GPIO_PORT, &PINCFG);



	//UPDATE AFIO TP ROUTE BETWEEN EXTI LINE WITH PORT A , B , C , D

	uint8_t AFIO_ECTICR_INDEX = EXTI_CONFIG->EXTI_PIN.EXTI_INPUT_NUM /4 ;
	uint8_t AFIO_ECTICR_POSITION=( EXTI_CONFIG->EXTI_PIN.EXTI_INPUT_NUM % 4) *4 ;
	AFIO->EXTICR[AFIO_ECTICR_INDEX] &= ~(0xF <<AFIO_ECTICR_POSITION); 				// TO MAKE ALL BIT IN REGISTER SELECTION EQUALL ZERO
	AFIO->EXTICR[AFIO_ECTICR_INDEX] |= ((AFIO_GPIO_EXTI_MAPPING(EXTI_CONFIG->EXTI_PIN.GPIO_PORT)& 0xF) << AFIO_ECTICR_POSITION);


	//UPDATE RAISING AND FALLING EDGE
	EXTI->RTSR &= ~(1<< EXTI_CONFIG->EXTI_PIN.EXTI_INPUT_NUM); 			//TO MAKE IT EQUALL ZERO
	EXTI->FTSR &= ~(1<< EXTI_CONFIG->EXTI_PIN.EXTI_INPUT_NUM); 			//TO MAKE IT EQUALL ZERO

	if(EXTI_CONFIG->TRIGGER_CASE==EXTI_TRIGGER_RISING){

		EXTI->RTSR |= (1<< EXTI_CONFIG->EXTI_PIN.EXTI_INPUT_NUM);

	}else if(EXTI_CONFIG->TRIGGER_CASE==EXTI_TRIGGER_FALLING){

		EXTI->FTSR |= (1<< EXTI_CONFIG->EXTI_PIN.EXTI_INPUT_NUM);

	}else if(EXTI_CONFIG->TRIGGER_CASE==EXTI_TRIGGER_RISING_FALLING){

		EXTI->RTSR |= (1<< EXTI_CONFIG->EXTI_PIN.EXTI_INPUT_NUM);
		EXTI->FTSR |= (1<< EXTI_CONFIG->EXTI_PIN.EXTI_INPUT_NUM);
	}


	//UPDATE IRQ HANDLING CALLBACK

	GP_IRQ_CALLBACK[EXTI_CONFIG->EXTI_PIN.EXTI_INPUT_NUM] = EXTI_CONFIG->P_IRQ_CALLBACK;

	//ENABLE - DISABLE IRQ
	if(EXTI_CONFIG->IRQ_STATE== EXTI_IRQ_ENABLE){

		EXTI->IMR |= (1<<EXTI_CONFIG->EXTI_PIN.EXTI_INPUT_NUM);
		ENABLE_NVIC(EXTI_CONFIG->EXTI_PIN.EXTI_INPUT_NUM);
	}else{
		EXTI->IMR &= ~(1<<EXTI_CONFIG->EXTI_PIN.EXTI_INPUT_NUM);
		DISABLE_NVIC(EXTI_CONFIG->EXTI_PIN.EXTI_INPUT_NUM);

	}

}



//============================================================APIS FUNCTION========================================================//
//=================================================================================================================================//


/*======================================================================================================
 * FUNC NAME ----> MCAL_EXTI_GPIO_DEINIT
 * BRIEF     ----> RESET EXTI REGISTER & NVIC CORRESPONDING IRQ MASK
 * PARAM1[IN]----> NONE
 * RETAVAL	 ----> NONE
 * NOTE		 ----> (NOTE THE RCC RESET REGISTER NOT HAVE ACCESS AT EXTI LINE)
 *
 */


void MCAL_EXTI_GPIO_DEINIT(){
	EXTI->IMR  = 0x00000000; 		//INTERRUPT MASK REGISTER RESET VALUE
	EXTI->EMR  = 0x00000000;		//EVENT MASK REGISTER RESET VALUE
	EXTI->RTSR = 0x00000000;		//RISING TRIGGER SELECTION REGISTER RESET VALUE
	EXTI->FTSR = 0x00000000;		//FALLING TRIGGER SELECTION REGISTER RESET VALUE
	EXTI->SWIER= 0x00000000;		//SOFTWARE INTERRUPT EVENT REGISTER RESET VALUE
	EXTI->PR   = 0xFFFFFFFF;		//PENDING REQUEST REGISTER RESET VALUE BY WRITE ONE TO CLEAR

	//DISABLE EXTI IRQ FROM NVIC BY CALLING MACROS
	NVIC_IRQ6_EXTI0_DISABLE;
	NVIC_IRQ7_EXTI1_DISABLE	;
	NVIC_IRQ8_EXTI2_DISABLE;
	NVIC_IRQ9_EXTI3_DISABLE;
	NVIC_IRQ10_EXTI4_DISABLE;
	NVIC_IRQ23_EXTI5_9_DISABLE;
	NVIC_IRQ40_EXTI10_15_DISABLE ;


}

/*======================================================================================================
 * FUNC NAME ----> MCAL_EXTI_GPIO_INIT
 * BRIEF     ----> INTAILIZE EXTI REGISTER SPECIFIC GPIO PINS & SPECIFIY IRQ MASK
 * PARAM1[IN]----> EXTI CONFIG SET BY A REFERENCE EXTI DEFINE - TRIGGER CASE - IRQ STATE
 * RETAVAL	 ----> NONE
 * NOTE		 ----> FOR LQFP48 PACKAGE HAS ONLY GPIO A , B AND PART OF C,D
 *
 */

void MCAL_EXTI_GPIO_INIT(EXTI_PINCONFIG_t *EXTI_CONFIG){
	UPDATE_EXTI(EXTI_CONFIG);
}

/*======================================================================================================
 * FUNC NAME ----> MCAL_EXTI_GPIO_UPDATE
 * BRIEF     ----> INTAILIZE EXTI REGISTER SPECIFIC GPIO PINS & SPECIFIY IRQ MASK
 * PARAM1[IN]----> EXTI CONFIG SET BY A REFERENCE EXTI DEFINE - TRIGGER CASE - IRQ STATE
 * RETAVAL	 ----> NONE
 * NOTE		 ----> NONE
 *
 */

void MCAL_EXTI_GPIO_UPDATE(EXTI_PINCONFIG_t *EXTI_CONFIG){
	UPDATE_EXTI(EXTI_CONFIG);

}






//============================================================ISR FUNCTION========================================================//
//=======================================================(INTERRUPT SERVICE ROUTINE)======================================================//

void EXTI0_IRQHandler(void){

	//CLEAR THE INTERRUPT FROM PENDING REGISTER TO NOT STILL FOUND FOR CPU!!
	EXTI->PR = 1<<0;		//FOR EXTI0

	//CALL IRQ CALLBACK
	GP_IRQ_CALLBACK[0]();
}

void EXTI1_IRQHandler(void){

	//CLEAR THE INTERRUPT FROM PENDING REGISTER TO NOT STILL FOUND FOR CPU!!
		EXTI->PR |= (1<<1);		//FOR EXTI1

		//CALL IRQ CALLBACK
		GP_IRQ_CALLBACK[1]();

}

void EXTI2_IRQHandler(void){

	//CLEAR THE INTERRUPT FROM PENDING REGISTER TO NOT STILL FOUND FOR CPU!!
		EXTI->PR |= (1<<2);		//FOR EXTI2

		//CALL IRQ CALLBACK
		GP_IRQ_CALLBACK[2]();

}

void EXTI3_IRQHandler(void){

	//CLEAR THE INTERRUPT FROM PENDING REGISTER TO NOT STILL FOUND FOR CPU!!
		EXTI->PR |= (1<<3);		//FOR EXTI3

		//CALL IRQ CALLBACK
		GP_IRQ_CALLBACK[3]();

}

void EXTI4_IRQHandler(void){

	//CLEAR THE INTERRUPT FROM PENDING REGISTER TO NOT STILL FOUND FOR CPU!!
		EXTI->PR |= (1<<4);		//FOR EXTI4

		//CALL IRQ CALLBACK
		GP_IRQ_CALLBACK[4]();


}

void EXTI9_5_IRQHandler(void){
	if(EXTI->PR & 1<<5){ EXTI->PR |= (1<<5) ;	GP_IRQ_CALLBACK[5](); }
	if(EXTI->PR & 1<<6){ EXTI->PR |= (1<<6) ;	GP_IRQ_CALLBACK[6](); }
	if(EXTI->PR & 1<<7){ EXTI->PR |= (1<<7) ;	GP_IRQ_CALLBACK[7](); }
	if(EXTI->PR & 1<<8){ EXTI->PR |= (1<<8) ;	GP_IRQ_CALLBACK[8](); }
	if(EXTI->PR & 1<<9){ EXTI->PR |= (1<<9) ;	GP_IRQ_CALLBACK[9](); }
}

void EXTI15_10_IRQHandler(void){

	if(EXTI->PR & 1<<10){ EXTI->PR |= (1<<10) ;	GP_IRQ_CALLBACK[10](); }
	if(EXTI->PR & 1<<11){ EXTI->PR |= (1<<11) ;	GP_IRQ_CALLBACK[11](); }
	if(EXTI->PR & 1<<12){ EXTI->PR |= (1<<12) ;	GP_IRQ_CALLBACK[12](); }
	if(EXTI->PR & 1<<13){ EXTI->PR |= (1<<13) ;	GP_IRQ_CALLBACK[13](); }
	if(EXTI->PR & 1<<14){ EXTI->PR |= (1<<14) ;	GP_IRQ_CALLBACK[14](); }
	if(EXTI->PR & 1<<15){ EXTI->PR |= (1<<15) ;	GP_IRQ_CALLBACK[15](); }

}
