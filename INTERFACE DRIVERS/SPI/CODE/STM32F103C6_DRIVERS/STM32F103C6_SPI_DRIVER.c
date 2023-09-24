/*
 * STM32F103C6_SPI_DRIVER.c
 *
 *  Created on: Jul 22, 2023
 *      Author: Andrew Nasser
 */
#include"STM103C6_HEADERS.H"

SPI_CONFIG* SPI_GLOBAL[2]={NULL,NULL};
#define	SPI1_INDEX	0
#define	SPI2_INDEX	1
#define	SPI_SR_TXE	((uint8_t)0x02)
#define	SPI_SR_RXNE	((uint8_t)0x01)


/*======================================================================================================
 * FUNC NAME ----> MCAL_SPI_INIT
 * BRIEF     ----> INTIALIZE SPI PRIEPHERALS
 * PARAM1[IN]----> SPI X
 * PARAM1[IN]----> CONFIG ALL SPI CONFIGURATION
 * RETAVAL	 ----> NONE
 * NOTE		 ----> SUPPORT SPI FULL DUPLEX MASTER/SLAVE , NSS HW/SW FOR SLAVE
 *
 */
void MCAL_SPI_INIT(SPI_Typedef *SPIx ,SPI_CONFIG *SPI_CONFIG ){

	//SAFETY FOR REGISTER TO BUFFER NOT WORK UNTIL U WRITE IN REGISTER
	uint16_t TEMP_CR1=0;
	uint16_t TEMP_CR2=0;



		if(SPIx==SPI1){
			RCC_SPI1_CLK_EN();
			SPI_GLOBAL[SPI1_INDEX] = SPI_CONFIG;
		}
		else if(SPIx==SPI2){
			RCC_SPI2_CLK_EN();
			SPI_GLOBAL[SPI2_INDEX] = SPI_CONFIG;
		}

	//ENABLE SPI FROM SPI_CR1 REGISTER
		TEMP_CR1=(0x1U <<6);

	//MASTER OR SLAVE MODE
		TEMP_CR1 |= SPI_CONFIG->SPI_DEVICE_MODE;

	//SPI COMMUNICATION MODE
		TEMP_CR1 |= SPI_CONFIG->SPI_COMMUNICATION_MODE;

	//SPI FRAME FORMAT
		TEMP_CR1 |= SPI_CONFIG->SPI_FRAME_FORMAT;

	//SPI DATA SIZ
		TEMP_CR1 |= SPI_CONFIG->SPI_DATA_SIZE;

	//SPI CLOCK POLARITY
		TEMP_CR1 |= SPI_CONFIG->SPI_CLCK_POLARITY;

	//SPI CLOCK PHASE
		TEMP_CR1 |= SPI_CONFIG->SPI__CLCK_PHASE;

	//SPI NSS


		if(SPI_CONFIG->SPI_NSS == SPI_NSS_HW_MASTER_OUTPUT_EN){
			TEMP_CR2 |= SPI_CONFIG->SPI_NSS;
		}
		else if(SPI_CONFIG->SPI_NSS == SPI_NSS_HW_MASTER_OUTPUT_DISEN){
			TEMP_CR2 &= SPI_CONFIG->SPI_NSS;
		}
		else{
			TEMP_CR1 |= SPI_CONFIG->SPI_NSS;
		}

	//SPI BAUD RATE
		TEMP_CR1 |= SPI_CONFIG->SPI_BAUDRATE;

	//SPI INTERRUPT
		if(SPI_CONFIG->SPI_IRQ_ENABLE != SPI_IRQ_EN_NONE){
			TEMP_CR2 |= SPI_CONFIG->SPI_IRQ_ENABLE;

			if(SPIx==SPI1){
				NVIC_IRQ35_SPI1_ENABLE;
			}
			else if(SPIx==SPI2){
				NVIC_IRQ36_SPI2_ENABLE;
			}



		}


		SPIx->CR1 = TEMP_CR1;
		SPIx->CR2 = TEMP_CR2;

}




/*======================================================================================================
 * FUNC NAME ----> MCAL_SPI_DEINIT
 * BRIEF     ----> USE TO DEINIT SPI
 * PARAM1[IN]----> SPI X WHICH X CAN BE 1,2,3
 * RETAVAL	 ----> NONE
 * NOTE		 ----> DISABLE CLCK NVIC INTERRUPT AND RESET CLCK
 *
 */
void MCAL_SPI_DEINIT(SPI_Typedef *SPIx ){


	if(SPIx==SPI1){
		NVIC_IRQ35_SPI1_DISABLE;
		RCC_SPI1_CLK_RESET();
	}
	else if(SPIx==SPI2){
		NVIC_IRQ36_SPI2_DISABLE;
		RCC_SPI2_CLK_RESET();
	}


}


/*======================================================================================================
 * FUNC NAME ----> MCAL_USART_GPIO_SETPIN
 * BRIEF     ----> USE TO SET PIN OF GPIO TO USED IN UART
 * PARAM1[IN]----> USART X WHICH X CAN BE 1,2,3
 * RETAVAL	 ---->NONE
 * NOTE		 ----> NONE
 *
 */
void MCAL_SPI_GPIO_SETPIN(SPI_Typedef *SPIx ){
	GPIO_PINCONFIG_T PINCFG ;


 if(SPIx == SPI1){

	 //PA4: SPI_NSS     ,   PA5: SPI_CLCK     , PA6: SPI_MISO     , PA7: SPI_MOSI


	 if(SPI_GLOBAL[SPI1_INDEX]->SPI_DEVICE_MODE == SPI_MASTER_MODE){

		 switch(SPI_GLOBAL[SPI1_INDEX]->SPI_NSS){

		 case SPI_NSS_HW_MASTER_OUTPUT_DISEN:
				 		 	PINCFG.GPIO_PIN_NUMBER = GPIO_PIN4;
				 		 	PINCFG.GPIO_MODE = GPIO_MODE_FLOATING;
				 			PINCFG.GPIO_SPEED_OUTPUT = GPIO_SPEED_10M;
				 			MCAL_GPIO_INIT(GPIOA, &PINCFG);
		 		 			break;
		 case SPI_NSS_HW_MASTER_OUTPUT_EN:
		 		 	 	 	PINCFG.GPIO_PIN_NUMBER = GPIO_PIN4;
		 		 			PINCFG.GPIO_MODE = GPIO_MODE_PUSH_PULL;
		 		 			PINCFG.GPIO_SPEED_OUTPUT = GPIO_SPEED_10M;
		 		 			MCAL_GPIO_INIT(GPIOA, &PINCFG);
		 		 			break;
		 }
		 //FOR CLOCK
	 	 	PINCFG.GPIO_PIN_NUMBER = GPIO_PIN5;
			PINCFG.GPIO_MODE = GPIO_MODE_AF_PUSH_PULL;
			PINCFG.GPIO_SPEED_OUTPUT = GPIO_SPEED_10M;
			MCAL_GPIO_INIT(GPIOA, &PINCFG);

		//FOR MISO
	 	 	PINCFG.GPIO_PIN_NUMBER = GPIO_PIN6;
			PINCFG.GPIO_MODE = GPIO_MODE_FLOATING;
			PINCFG.GPIO_SPEED_OUTPUT = GPIO_SPEED_10M;
			MCAL_GPIO_INIT(GPIOA, &PINCFG);

		 //FOR MOSI
		 	PINCFG.GPIO_PIN_NUMBER = GPIO_PIN7;
			PINCFG.GPIO_MODE = GPIO_MODE_AF_PUSH_PULL;
			PINCFG.GPIO_SPEED_OUTPUT = GPIO_SPEED_10M;
			MCAL_GPIO_INIT(GPIOA, &PINCFG);


	 }else{
		 if(SPI_GLOBAL[SPI1_INDEX]->SPI_DEVICE_MODE == SPI_SLAVE_MODE){
	 		 	PINCFG.GPIO_PIN_NUMBER = GPIO_PIN4;
	 		 	PINCFG.GPIO_MODE = GPIO_MODE_FLOATING;
	 			PINCFG.GPIO_SPEED_OUTPUT = GPIO_SPEED_10M;
	 			MCAL_GPIO_INIT(GPIOA, &PINCFG);
		 }


				 //FOR CLOCK
			 	 	PINCFG.GPIO_PIN_NUMBER = GPIO_PIN5;
					PINCFG.GPIO_MODE = GPIO_MODE_FLOATING;
					PINCFG.GPIO_SPEED_OUTPUT = GPIO_SPEED_10M;
					MCAL_GPIO_INIT(GPIOA, &PINCFG);

				//FOR MISO
			 	 	PINCFG.GPIO_PIN_NUMBER = GPIO_PIN6;
					PINCFG.GPIO_MODE = GPIO_MODE_AF_PUSH_PULL;
					PINCFG.GPIO_SPEED_OUTPUT = GPIO_SPEED_10M;
					MCAL_GPIO_INIT(GPIOA, &PINCFG);

				 //FOR MOSI
				 	PINCFG.GPIO_PIN_NUMBER = GPIO_PIN7;
					PINCFG.GPIO_MODE = GPIO_MODE_FLOATING;
					PINCFG.GPIO_SPEED_OUTPUT = GPIO_SPEED_10M;
					MCAL_GPIO_INIT(GPIOA, &PINCFG);


		 }



 }
 else if (SPIx == SPI2){

	 //PB12: SPI_NSS     ,   PB13: SPI_CLCK     , PB14: SPI_MISO     , PB15: SPI_MOSI
	 if(SPI_GLOBAL[SPI2_INDEX]->SPI_DEVICE_MODE == SPI_MASTER_MODE){

		 switch(SPI_GLOBAL[SPI2_INDEX]->SPI_NSS){

		 case SPI_NSS_HW_MASTER_OUTPUT_DISEN:
				 		 	PINCFG.GPIO_PIN_NUMBER = GPIO_PIN12;
				 		 	PINCFG.GPIO_MODE = GPIO_MODE_FLOATING;
				 			PINCFG.GPIO_SPEED_OUTPUT = GPIO_SPEED_10M;
				 			MCAL_GPIO_INIT(GPIOB, &PINCFG);
		 		 			break;
		 case SPI_NSS_HW_MASTER_OUTPUT_EN:
		 		 	 	 	PINCFG.GPIO_PIN_NUMBER = GPIO_PIN12;
		 		 			PINCFG.GPIO_MODE = GPIO_MODE_AF_PUSH_PULL;
		 		 			PINCFG.GPIO_SPEED_OUTPUT = GPIO_SPEED_10M;
		 		 			MCAL_GPIO_INIT(GPIOB, &PINCFG);
		 		 			break;
		 }
		 //FOR CLOCK
	 	 	PINCFG.GPIO_PIN_NUMBER = GPIO_PIN13;
			PINCFG.GPIO_MODE = GPIO_MODE_AF_PUSH_PULL;
			PINCFG.GPIO_SPEED_OUTPUT = GPIO_SPEED_10M;
			MCAL_GPIO_INIT(GPIOB, &PINCFG);

		//FOR MISO
	 	 	PINCFG.GPIO_PIN_NUMBER = GPIO_PIN14;
			PINCFG.GPIO_MODE = GPIO_MODE_FLOATING;
			PINCFG.GPIO_SPEED_OUTPUT = GPIO_SPEED_10M;
			MCAL_GPIO_INIT(GPIOB, &PINCFG);

		 //FOR MOSI
		 	PINCFG.GPIO_PIN_NUMBER = GPIO_PIN15;
			PINCFG.GPIO_MODE = GPIO_MODE_AF_PUSH_PULL;
			PINCFG.GPIO_SPEED_OUTPUT = GPIO_SPEED_10M;
			MCAL_GPIO_INIT(GPIOB, &PINCFG);


	 }else{
		 if(SPI_GLOBAL[SPI2_INDEX]->SPI_DEVICE_MODE == SPI_SLAVE_MODE){
	 		 	PINCFG.GPIO_PIN_NUMBER = GPIO_PIN12;
	 		 	PINCFG.GPIO_MODE = GPIO_MODE_FLOATING;
	 			PINCFG.GPIO_SPEED_OUTPUT = GPIO_SPEED_10M;
	 			MCAL_GPIO_INIT(GPIOB, &PINCFG);
		 }


				 //FOR CLOCK
			 	 	PINCFG.GPIO_PIN_NUMBER = GPIO_PIN13;
					PINCFG.GPIO_MODE = GPIO_MODE_FLOATING;
					PINCFG.GPIO_SPEED_OUTPUT = GPIO_SPEED_10M;
					MCAL_GPIO_INIT(GPIOB, &PINCFG);

				//FOR MISO
			 	 	PINCFG.GPIO_PIN_NUMBER = GPIO_PIN14;
					PINCFG.GPIO_MODE = GPIO_MODE_AF_PUSH_PULL;
					PINCFG.GPIO_SPEED_OUTPUT = GPIO_SPEED_10M;
					MCAL_GPIO_INIT(GPIOB, &PINCFG);

				 //FOR MOSI
				 	PINCFG.GPIO_PIN_NUMBER = GPIO_PIN15;
					PINCFG.GPIO_MODE = GPIO_MODE_FLOATING;
					PINCFG.GPIO_SPEED_OUTPUT = GPIO_SPEED_10M;
					MCAL_GPIO_INIT(GPIOB, &PINCFG);


		 }


 }





}


/*======================================================================================================
 * FUNC NAME ----> MCAL_USART_INIT
 * BRIEF     ----> INTIALIZE UART (ASYNC ONLY)
 * PARAM1[IN]----> USARTx
 * PARAM1[IN]----> CONFIG ALL UART CONFIGURATION
 * RETAVAL	 ----> POSITION IN CR REGISTER
 * NOTE		 ----> SUPPORT ASYNC WITH CLCK OUT 8MHZ
 *
 */
void MCAL_SPI_SEND(SPI_Typedef *SPIx, uint16_t *PTX_BUFFER,enum POLLING_MECHASIM POLLINGEN ){


	//FOR RECIEVING ONLY
		if(POLLINGEN == POLLING_ENABLE)
		while(!((SPIx)->SR & SPI_SR_TXE));
		SPIx->DR = *PTX_BUFFER;

}



/*======================================================================================================
 * FUNC NAME ----> MCAL_USART_INIT
 * BRIEF     ----> INTIALIZE UART (ASYNC ONLY)
 * PARAM1[IN]----> USARTx
 * PARAM1[IN]----> CONFIG ALL UART CONFIGURATION
 * RETAVAL	 ----> POSITION IN CR REGISTER
 * NOTE		 ----> SUPPORT ASYNC WITH CLCK OUT 8MHZ
 *
 */
void MCAL_SPI_RECIEVE(SPI_Typedef *SPIx, uint16_t *PTX_BUFFER,enum POLLING_MECHASIM POLLINGEN ){


	//FOR TRANSMITT ONLY
		if(POLLINGEN == POLLING_ENABLE)
		while(!((SPIx)->SR & SPI_SR_RXNE));
		*PTX_BUFFER = SPIx->DR ;


}



/*======================================================================================================
 * FUNC NAME ----> MCAL_USART_INIT
 * BRIEF     ----> INTIALIZE UART (ASYNC ONLY)
 * PARAM1[IN]----> USARTx
 * PARAM1[IN]----> CONFIG ALL UART CONFIGURATION
 * RETAVAL	 ----> POSITION IN CR REGISTER
 * NOTE		 ----> SUPPORT ASYNC WITH CLCK OUT 8MHZ
 *
 */
void MCAL_SPI_TX_RX(SPI_Typedef *SPIx, uint16_t *PTX_BUFFER,enum POLLING_MECHASIM POLLINGEN ){

	if(POLLINGEN == POLLING_ENABLE)
	while(!((SPIx)->SR & SPI_SR_TXE));
	SPIx->DR = *PTX_BUFFER;

	if(POLLINGEN == POLLING_ENABLE)
	while(!((SPIx)->SR & SPI_SR_RXNE));
	*PTX_BUFFER = SPIx->DR ;


}


/*========================================IRQ================================*/
void SPI1_IRQHandler (void)
{
	struct S_IRQ_SRC IRQ_SRC;
	IRQ_SRC.TXE = ((SPI1->SR & (1<<1)) >> 1);
	IRQ_SRC.RXNE = ((SPI1->SR & (1<<0)) >> 0);
	IRQ_SRC.ERRI = ((SPI1->SR & (1<<4)) >> 4);




	SPI_GLOBAL[SPI1_INDEX]->P_IRQ_CALLBACK (IRQ_SRC);

}

void SPI2_IRQHandler (void)
{
	struct S_IRQ_SRC IRQ_SRC;
	IRQ_SRC.TXE = ((SPI2->SR & (1<<1)) >> 1);
	IRQ_SRC.RXNE = ((SPI2->SR & (1<<0)) >> 0);
	IRQ_SRC.ERRI = ((SPI2->SR & (1<<4)) >> 4);


		SPI_GLOBAL[SPI2_INDEX]->P_IRQ_CALLBACK (IRQ_SRC);
}

