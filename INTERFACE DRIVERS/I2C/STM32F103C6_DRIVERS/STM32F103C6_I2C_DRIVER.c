/*
 * STM32F103C6_I2C_DRIVER.c
 *
 *  Created on: Aug 15, 2023
 *      Author: ANDREW NASSER SHOKRY
 *
 */



#include"STM103C6_HEADERS.H"


/*==========================================================GRNERIC VARIABLE===========================================================================
=================================================================================================================================================*/
I2C_CONFIG I2C_GLOBAL[2]={NULL,NULL};


/*==========================================================GRNERIC MACROS===========================================================================
=================================================================================================================================================*/


#define	I2C1_INDEX	0
#define	I2C2_INDEX	1
/*===============================================================APIS===========================================================================
=================================================================================================================================================*/

/*======================================================================================================
 * FUNC NAME ----> MCAL_I2C_INIT
 * BRIEF     ----> INTIALIZE I2C PRIEPHERALS
 * PARAM1[IN]----> I2C X
 * PARAM1[IN]----> CONFIG ALL I2C CONFIGURATION
 * RETAVAL	 ----> NONE
 * NOTE		 ----> SUPPORT I2C FULL DUPLEX MASTER/SLAVE , NSS HW/SW FOR SLAVE
 *
 */

void MCAL_I2C_INIT(I2C_Typedef *I2Cx ,I2C_CONFIG *I2C_INITSTRUCT ){

	uint16_t TMPREG=0,	FREQ_RANGE=0;

	uint32_t PCLCK1=8000000;

	uint16_t RESULT=0;

	//ENABLE RCC

	if(I2Cx==I2C1){
		RCC_I2C1_CLK_EN();
		I2C_GLOBAL[I2C1_INDEX] = *I2C_INITSTRUCT;

	}else
	{
		I2C_GLOBAL[I2C2_INDEX] = *I2C_INITSTRUCT;
		RCC_I2C2_CLK_EN();

	}
	if(I2C_INITSTRUCT->I2C_MODE==I2C_MODE_I2C){


		//INITIALIZING TIME
		//CCR=(Fpclck/2Ficlck)

		//GET THE VALUE OF CR2 REGISTER
		TMPREG=I2Cx->CR2;

		//CLEAR THE VALUE
		TMPREG &= ~(I2C_CR2_FREQ);
		PCLCK1=MCAL_RCC_PCLCK1_GETFREQ();
		FREQ_RANGE=(uint16_t)(PCLCK1/1000000);
		TMPREG |=FREQ_RANGE;
		I2Cx->CR2 = TMPREG;



		//CONFIGURE THE I2C CLOCK CONTROL REGISTER [CCR]
		I2Cx->CR1 &= ~(I2C_CR1_PE);
		TMPREG =0;

		if((I2C_INITSTRUCT->I2C_CLCK_SPEED==I2C_CLCK_SM_50K) || (I2C_INITSTRUCT->I2C_CLCK_SPEED==I2C_CLCK_SM_100K )){
			//FAST MODE NOT SUPPORTED
			//CCR=(	Fpclck	/	(2*Fi2c clck freq))
			RESULT=(uint16_t)(PCLCK1 / (I2C_INITSTRUCT->I2C_CLCK_SPEED	*	2));
			TMPREG |= RESULT;
			I2Cx->CCR = TMPREG;

			/*TRISE[5:0]: Maximum rise time IN Fm/Sm mode (Master mode)
						These bits should provide the maximum duration of the SCL feedback loop IN master mode.
						he purpose is to keep a stable SCL frequency whatever the SCL risINg edge duration.
						These bits must be programmed with the maximum SCL rise time given IN the I2C bus
						specification, INcremented by 1.
						For INstance: IN Sm mode, the maximum allowed SCL rise time is 1000 ns.
						If, IN the I2C_CR2 register, the value of FREQ[5:0] bits is equal to 0x08 and TPCLK1 = 125 ns
						therefore the TRISE[5:0] bits must be programmed with 09h.
						(1000 ns / 125 ns = 8 + 1)
			 *
			 */
			I2Cx->TRISE=FREQ_RANGE +1;

		}else
		{
		}
		TMPREG=I2Cx->CR1;
		TMPREG|=(uint16_t)(I2C_INITSTRUCT->I2C_ACK | I2C_INITSTRUCT->I2C_MODE | I2C_INITSTRUCT->I2C_GENERAL_DETECTION| I2C_INITSTRUCT->I2C_STRECH_MODE);
		I2Cx->CR1=TMPREG;

		// OR1 & OR2 CONFIGURATION
		TMPREG=0;
		if(I2C_INITSTRUCT->I2C_SLAVE_ADDRESS.DUAL_ADD ==1){
			TMPREG = I2C_OAR2_ENDUAL;
			TMPREG |= I2C_INITSTRUCT->I2C_SLAVE_ADDRESS.SECONDARY_SLAVE_ADD << I2C_OAR2_ADD2_POS;
			I2Cx->OAR2 = TMPREG;

		}
			TMPREG =0;
			TMPREG |= I2C_INITSTRUCT->I2C_SLAVE_ADDRESS.PRIMARY_SLAVE_ADD<<1;
			TMPREG |= I2C_INITSTRUCT->I2C_SLAVE_ADDRESS.I2C_ADDRESS_SLAVE_MODE;
			I2Cx->OAR1 = TMPREG;

	}else{
		//SMBUS SUPPORT

	}
		// IF WE ARE IN INTURREPT MODE(SLAVE MODE)
	if(I2C_INITSTRUCT->P_IRQ_CALL != NULL){
		// YOU ARE IN SLAVE STATE MODE
		I2Cx->CR2 |= (I2C_CR2_ITERREN);
		I2Cx->CR2 |= (I2C_CR2_ITEVTEN);
		I2Cx->CR2 |= (I2C_CR2_ITBUFEN);
		if(I2Cx==I2C1){
			NVIC_IRQ31_I2C1_EV_ENABLE;
			NVIC_IRQ32_I2C1_ER_ENABLE;
		}else if(I2Cx==I2C2){
			NVIC_IRQ33_I2C2_EV_ENABLE;
			NVIC_IRQ34_I2C2_ER_ENABLE;
		}
		I2Cx->SR1=0;
		I2Cx->SR2=0;
	}
	I2Cx->CR1 |= I2C_CR1_PE;
}






/**======================================================================================================================================================
 * FUNC NAME ----> MCAL_I2C_DEINIT
 * BRIEF     ----> USE TO DEINIT I2C
 * PARAM1[IN]----> I2C X WHICH X CAN BE 1,2,3
 * RETAVAL	 ----> NONE
 * NOTE		 ----> DISABLE CLCK NVIC INTERRUPT AND RESET CLCK
 *
===================================================================================================================================================*/
void MCAL_I2C_DEINIT(I2C_Typedef *I2Cx ){


	if(I2Cx==I2C1){
		NVIC_IRQ31_I2C1_EV_DISABLE;
		NVIC_IRQ32_I2C1_ER_DISABLE;
		RCC_I2C1_CLK_RESET();
	}
	else if(I2Cx==I2C2){
		NVIC_IRQ33_I2C2_EV_DISABLE;
		NVIC_IRQ34_I2C2_ER_DISABLE;
		RCC_I2C2_CLK_RESET();
	}




}

/**======================================================================================================================================================
 * FUNC NAME ----> MCAL_I2C_GPIO_SETPIN
 * BRIEF     ----> USE TO SET PIN OF GPIO TO USED IN I2C
 * PARAM1[IN]----> USART X WHICH X CAN BE 1,2
 * RETAVAL	 ---->NONE
 * NOTE		 ----> NONE
 *
 ===================================================================================================================================================*/

void MCAL_I2C_GPIO_SETPIN(I2C_Typedef *I2Cx ){
	GPIO_PINCONFIG_T PINCONFIG;
		if(I2Cx == I2C1)
		{
			// PB6 :SCL
			// PB7 :SDA
			PINCONFIG.GPIO_PIN_NUMBER =GPIO_PIN6;
			PINCONFIG.GPIO_MODE = GPIO_MODE_AF_OPEN_DRAIN;
			PINCONFIG.GPIO_SPEED_OUTPUT=GPIO_SPEED_10M ;
			MCAL_GPIO_INIT(GPIOB, &PINCONFIG);

			PINCONFIG.GPIO_PIN_NUMBER =GPIO_PIN7;
			PINCONFIG.GPIO_MODE = GPIO_MODE_AF_OPEN_DRAIN;
			PINCONFIG.GPIO_SPEED_OUTPUT= GPIO_SPEED_10M;
			MCAL_GPIO_INIT(GPIOB, &PINCONFIG);
		}

		else
		{
			// PB10 :SCL
			// PB11 :SDA
			PINCONFIG.GPIO_PIN_NUMBER =GPIO_PIN10;
			PINCONFIG.GPIO_MODE = GPIO_MODE_AF_OPEN_DRAIN;
			PINCONFIG.GPIO_SPEED_OUTPUT= GPIO_SPEED_10M;
			MCAL_GPIO_INIT(GPIOB, &PINCONFIG);

			PINCONFIG.GPIO_PIN_NUMBER =GPIO_PIN11;
			PINCONFIG.GPIO_MODE = GPIO_MODE_AF_OPEN_DRAIN;
			PINCONFIG.GPIO_SPEED_OUTPUT= GPIO_SPEED_10M;
			MCAL_GPIO_INIT(GPIOB, &PINCONFIG);
		}
}








/**======================================================================================================================================================
* FUNC NAME ----> MCAL_I2C_MASTER_TX
* BRIEF     ----> SEND DATA BY I2C FROM MASTER TO SLAVE , DATA MUST BE 8 BIT
* PARAM1[IN]---->PTXBUFFER: POINTER TO BUFFER TO SEND DATA
* PARAM1[IN]---->I2Cx:  SPECIFIED I2Cx x=[ 1 : 2 ]
* PARAM1[IN]---->STOP:  SEND STOP OR NO
* PARAM1[IN]---->START: SEND START OR REPEATED START
* PARAM1[IN]---->DATALEN:LEGTH OF DATA SEND
* PARAM1[IN]---->ADDRESS:SLAVE ADDRESS
 * RETAVAL	 ---->NONE
*  NOTE		 ---->THIS FUNCTION CONTAINS THE I2C_GENERATE_START AND I2C_GENERATE_STOP .
===================================================================================================================================================*/



void MCAL_I2C_MASTER_TX(I2C_Typedef *I2Cx , uint16_t ADDRESS , uint8_t* PTXBUFFER , uint32_t DATALEN , STOP_STATE STOP , REPEATED_START START){

	int i ;
		// Set the START bit
	I2C_GENERATE_START(I2Cx, START);
		while(!(I2C_GET_FLAG_STATUS(I2Cx, EV5))) ;
		I2C_SEND_ADDRESS(I2Cx, ADDRESS, TRANSMITTER) ;
		while(!(I2C_GET_FLAG_STATUS(I2Cx, EV6))) ;
		while(!(I2C_GET_FLAG_STATUS(I2Cx, EV8_1))) ;
		 for( i=0 ; i<DATALEN ; i++ )
		 {
			 I2Cx->DR = PTXBUFFER[i];
			 while(!(I2C_GET_FLAG_STATUS(I2Cx, EV8_1))) ;
		 }
		 while(!(I2C_GET_FLAG_STATUS(I2Cx, EV8_2))) ;
		 if( STOP==WITH_STOP )
		 {
			 I2C_GENERATE_STOP(I2Cx) ;
		 }







}






/**======================================================================================================================================================
* FUNC NAME ----> I2C_SEND_ADDRESS
* BRIEF     ---->SEND ADDRESS BY I2C FROM MASTER TO SLAVE , ADDRESS IS(7 OR 10)BIT
* PARAM1[IN]---->I2Cx:  SPECIFIED I2Cx x=[ 1 : 2 ]
* PARAM1[IN]---->ADDRESS:SLAVE ADDRESS
* PARAM1[IN]---->DIR: DIRECTION OF COMMUNICATION (TRANSMITTER OR RECIEVER)
* RETAVAL	 ---->NONE
*  NOTE		 ---->NONE
 ===================================================================================================================================================*/


void I2C_SEND_ADDRESS(I2C_Typedef* I2Cx, uint16_t ADDRESS , I2C_DIRECTION DIRECTION)
{
	ADDRESS = ADDRESS<<1 ;
	if (DIRECTION==TRANSMITTER)
		ADDRESS &= ~(1 << 0);
	else
		ADDRESS |= (1 << 0);
	I2Cx->DR = ADDRESS;
}





/**======================================================================================================================================================
* FUNC NAME ----> I2C_GENERATE_STOP
* BRIEF     ---->GENERATE STOP CONDITION TO END TRANSMITTER
* PARAM1[IN]---->I2Cx:  SPECIFIED I2Cx x=[ 1 : 2 ]
* PARAM1[IN]---->START: SEND START_REPEATED OR START
* RETAVAL	 ---->NONE
*  NOTE		 ---->NONE
 ===================================================================================================================================================*/

void I2C_GENERATE_STOP(I2C_Typedef* I2Cx )
{
	I2Cx->CR1 |=I2C_CR1_STOP ;
}




/**======================================================================================================================================================
* FUNC NAME ----> MCAL_I2C_MASTER_RX
* BRIEF     ---->RECIEVE DATA BY I2C FROM MASTER TO SLAVE , DATA MUST BE 8 BIT
* PARAM1 [out] ---->PTXBUFFER: POINTER TO BUFFER TO RECIEVE DATA
* PARAM1[IN]---->I2Cx: SPECIFIED I2Cx x=[ 1 : 2 ]
* PARAM1[IN]---->ADDRESS:SLAVE ADDRESS
* PARAM1[IN]---->STOP:SEND STOP OR NOT
* PARAM1[IN]---->START:SEND START OR REPEATED START
* PARAM1[IN]---->DATALEN: LENGTH OF DATA SEND
* RETAVAL	 ---->NONE
*  NOTE		 ---->THIS FUNCTION CONTAINS THE I2C_GENERATE_START AND I2C_GENERATE_STOP FUNCTION .
===================================================================================================================================================*/


void MCAL_I2C_MASTER_RX(I2C_Typedef *I2Cx , uint16_t ADDRESS , uint8_t* PRXBUFFER , uint32_t DATALEN , STOP_STATE STOP , REPEATED_START START){
	int i ;
		// Set the START bit
	I2C_GENERATE_START(I2Cx, START);
		while(!(I2C_GET_FLAG_STATUS(I2Cx, EV5))) ;
		I2C_SEND_ADDRESS(I2Cx, ADDRESS, RECIEVE) ;
		while(!(I2C_GET_FLAG_STATUS(I2Cx, EV6))) ;
		 for( i=0 ; i<DATALEN ; i++ )
		 {
			 while(!(I2C_GET_FLAG_STATUS(I2Cx, EV7))) ;
			 PRXBUFFER[i]= I2Cx->DR ;
		 }
		 // not ACK
		I2Cx->CR1 &= ~(I2C_CR1_ACK) ;
		 if( STOP == WITH_STOP )
		 {
			 I2C_GENERATE_STOP(I2Cx) ;
		 }
		 //Set ACK
		 I2Cx->CR1 |=(I2C_CR1_ACK) ;


}






/**======================================================================================================================================================
* FUNC NAME ----> I2C_GENERATE_START
* BRIEF     ---->GENERATE START CONDITION TO START TRANSMITTER
* PARAM1[IN]---->I2Cx:  SPECIFIED I2Cx x=[ 1 : 2 ]
* PARAM1[IN]---->START: SEND START_REPEATED OR START
* RETAVAL	 ---->NONE
*  NOTE		 ---->NONE
===================================================================================================================================================*/


void I2C_GENERATE_START(I2C_Typedef* I2Cx , REPEATED_START START){
	if ( START != REPEATEDSTART )
		{
			while( I2C_GET_FLAG_STATUS(I2Cx, I2C_BUSY)) ;
		}
		I2Cx->CR1 |=I2C_CR1_START ;
}





/**======================================================================================================================================================
* FUNC NAME ----> I2C_GET_FLAG_STATUS
* BRIEF     ---->USED TO CHECK THE CURRENT STATE OF I2C [BUSY , RECIEVE DATA....]
* PARAM1[IN]---->I2Cx:  SPECIFIED I2Cx x=[ 1 : 2 ]
* PARAM1[IN]---->FLAG: IT IS THE STATUS TO CHECK IT
* RETAVAL	 ---->FLAG_STATUS
*  NOTE		 ---->NONE
===================================================================================================================================================*/


FLAG_STATUS I2C_GET_FLAG_STATUS( I2C_Typedef *I2Cx , STATUS FLAG ){




	FLAG_STATUS STATE ;
		switch( FLAG )
		{
		case I2C_BUSY :
			if (I2Cx->SR2 & I2C_SR2_BUSY)
				STATE=SET ;
			else
				STATE=RESET ;
			break;
		case EV5 :
			if (I2Cx->SR1 & I2C_SR1_SB)
				STATE=SET ;
			else
				STATE=RESET ;
			break;
		case EV6 :
			if (I2Cx->SR1 & I2C_SR1_ADDR)
				STATE=SET ;
			else
				STATE=RESET ;
			break;
		case EV8_1 :
			if (I2Cx->SR1 & I2C_SR1_TXE)
				STATE=SET ;
			else
				STATE=RESET ;
			break;
		case EV8_2 :
			if (I2Cx->SR1 & I2C_SR1_BTF)
				STATE=SET ;
			else
				STATE=RESET ;
			break;
		case EV7 :
			if (I2Cx->SR1 & I2C_SR1_RXNE)
				STATE=SET ;
			else
				STATE=RESET ;
			break;
		}
		return STATE ;




}



/**======================================================================================================================================================
* FUNC NAME ---->  MCAL_I2C_SLAVE_TX
* BRIEF     ---->SEND DATA BY I2C FROM SLAVE TO MASTER
* PARAM1[IN]---->I2Cx:  SPECIFIED I2Cx x=[ 1 : 2 ]
* PARAM1[IN]---->DATA: THE DATA SEND
* RETAVAL	 ---->NONE
*  NOTE		 ---->NONE
===================================================================================================================================================*/


void MCAL_I2C_SLAVE_TX(I2C_Typedef *I2Cx ,uint8_t DATA)
{
	I2Cx->DR = DATA;
}




/**======================================================================================================================================================
* FUNC NAME ---->MCAL_I2C_SLAVE_RX
* BRIEF     ---->RECIEVE DATA BY I2C FROM SLAVE TO MASTER
* PARAM1[IN]---->I2Cx:  SPECIFIED I2Cx x=[ 1 : 2 ]
* RETAVAL	 ---->RETURN DATA RECIEVED FROM MASTER
*  NOTE		 ---->NONE
 ===================================================================================================================================================*/


uint8_t MCAL_I2C_SLAVE_RX(I2C_Typedef *I2Cx )
{
	return (uint8_t)I2Cx->DR;

}


void I2C_EV_IRQHandler()
{
	volatile uint32_t READ = 0;

	uint32_t TEMP_1, TEMP_2, TEMP_3;

	TEMP_3 = (I2C1->SR1 & (I2C_SR1_STOPF));		// STOP DETECTION(SLAVE MODE)
	TEMP_1 = (I2C1->CR2 & (I2C_CR2_ITEVTEN));	// EVENT INTERRUPT ENABLE
	TEMP_2 = (I2C1->CR2 & (I2C_CR2_ITBUFEN));	// BUFFER INTERRUPT ENABLE



	//CHECK STOP DETECTION

	if(TEMP_1 && TEMP_3)
	{
		//CLEARD BY SOFTWARE READING THE SR1 REGISTER FOLLOWED BY A WRITE IN THE CR1 REGISTER, OR BY HARDWARE @ PE=0

		I2C1->CR1 |= 0x0000;
		SLAVE_STATUS(I2C1 , I2C_EV_STOP);
	}


	// CHECK ADDRESS MATCHED

	TEMP_3 = (I2C1->SR1 & (I2C_SR1_ADDR));
	if(TEMP_1 && TEMP_3)
	{

		// CHECK MASTER OR SLAVE MODE

		if(I2C1->SR2 & (I2C_SR2_MSL))
		{
			// MASTER MODE
		}
		else
		{
			// SLAVE MODE
			READ  = I2C1->SR1 ;
			READ  = I2C1->SR2 ;
			SLAVE_STATUS(I2C1 , I2C_EV_ADDR_MATCHED) ;
		}
	}


	// DATA REGISTER EMPTY AT SLAVE TX


	TEMP_3 = (I2C1->SR1 & (I2C_SR1_TXE));
	if(TEMP_1 && TEMP_2 && TEMP_3)
	{
		//CLEARED BY SW WRITING TO THE DR REGISTER OR BY HW AFTER A START OR A STOP CONDITION WHEN PE=0
		// CHECK MASTER OR SLAVE MODE

		if(I2C1->SR2 & (I2C_SR2_MSL))
		{
			// MASTER MODE
		}
		else
		{
			// SLAVE MODE
			SLAVE_STATUS(I2C1 , I2C_EV_DATA_REQ);
		}
	}
	// DATS REGISTER NOT EMPTY AT SLAVE RECIEVE
	TEMP_3 = (I2C1->SR1 & (I2C_SR1_RXNE));
	if(TEMP_1 && TEMP_2 && TEMP_3)
	{
		// CHECK MASTER MODE OR SLAVE MODE
		if(I2C1->SR2 & (I2C_SR2_MSL))
		{
			// Master mode
		}
		else
		{
			// SLAVE MODE
			SLAVE_STATUS(I2C1 , I2C_DATA_REC);
		}
	}
}

/**======================================================================================================================================================
* FUNC NAME ---->SLAVE_STATUS
* BRIEF     ---->CHECK THE STATE OF I2C (BUSY,RECIEVE DATA,....) TO DETERMINE SOURCE OF INTERRUPT
* PARAM1[IN]---->I2Cx:  SPECIFIED I2Cx x=[ 1 : 2 ]
* PARAM1[IN]---->STATE: STATUS TO BE CHECK
* RETAVAL	 ---->NONE
*  NOTE		 ---->FUNCTION CALL INTERRUPT IN MAIN
===================================================================================================================================================*/




void SLAVE_STATUS(I2C_Typedef* I2Cx , SLAVE_STATE STATE)
{
	uint8_t INDEX =  I2Cx == I2C1 ? 0 : 1 ;

	switch(STATE)
	{
	case I2C_EV_STOP :
		if(I2Cx->SR2 & (I2C_SR2_TRA))
		{
			//STOP CONDITION IS DETECTED ON THE BUS BY THE SLAVE AFTER AN ACK
			I2C_GLOBAL[INDEX].P_IRQ_CALL(I2C_EV_STOP);
		}
		break;
	case I2C_EV_ADDR_MATCHED :
		//ADDRESS NATCHED WITH THE OAR REGISTER CONTENT , GENERAL CALL
		I2C_GLOBAL[INDEX].P_IRQ_CALL(I2C_EV_ADDR_MATCHED);
		break;
	case I2C_EV_DATA_REQ :
		if(I2Cx->SR2 & (I2C_SR2_TRA))
		{
			// THE APP LAYER SHOULD SEND THE DATA
			I2C_GLOBAL[INDEX].P_IRQ_CALL(I2C_EV_DATA_REQ);
		}
		break;
	case I2C_DATA_REC :
		// TO CONFIRM THE SLAVE IN RECIEVER
		if(!(I2Cx->SR2 & (I2C_SR2_TRA)))
		{
			// APPLICATION SHOULD READ DATA
			I2C_GLOBAL[INDEX].P_IRQ_CALL(I2C_DATA_REC);
		}
		break;
	}
}

