/*
 * SPI_Prog.c
 *
 * Created: 11/3/2023 5:02:11 PM
 *  Author: LENOVO
 */ 
#include "SPI_Interface.h"

E_SPI_ERROR MCAL_SPI_vinitMaster(void)
{	E_SPI_ERROR e= SPI_E_N_OK;
	S_Dio SS_PIN={MSTR_PORT,SS,HIGH};
	S_Dio MOSI_PIN={MSTR_PORT,MOSI,HIGH};
	S_Dio SCK_PIN={MSTR_PORT,SCK,HIGH};
	//set output pins
	e=MCAL_Dio_Init(&SS_PIN);
	e=MCAL_Dio_Init(&MOSI_PIN);
	e=MCAL_Dio_Init(&SCK_PIN);
	
	//set master bit Enable SPI and SPI interrupt
	//SPX2 SPR1 SPR0 =>0 0 0 => CLK=F_CPU/4 (SPI FREQUENCY CONDITION CHECKED)
	SPCR|=(1<<MSTR)|(1<<SPIE)|(1<<SPE);
	//De-activate SS pin
	e= MCAL_Dio_WriteSinglePin(&SS_PIN,SS,HIGH);
	return e;
}
E_SPI_ERROR MCAL_SPI_vinitSlave(void)
{	E_SPI_ERROR e= SPI_E_N_OK;
	S_Dio MISO_PIN={SLAVE_PORT,MISO,HIGH};
	e=MCAL_Dio_Init(&MISO_PIN);
	//ENABLE SPI and SPI interrupt enable
	SPCR=(1<<SPE)|(1<<SPIE);
	return e;
}
E_SPI_ERROR MCAL_SPI_SendRx(unsigned char* data)
{	E_SPI_ERROR e= SPI_E_N_OK;
	SPDR=*data;
	while(GET_BIT(SPSR,SPIF)==0);
	*data=SPDR;
	return e;
}
E_SPI_ERROR MCAL_SPI_SlaveActivate(void)
{	E_SPI_ERROR e= SPI_E_N_OK;
	S_Dio SS_PIN={SLAVE_PORT,SS,HIGH};
	//activate SS pin To interact
	e=MCAL_Dio_WriteSinglePin(&SS_PIN,SS,LOW);
	return e;
}
E_SPI_ERROR MCAL_SPI_MasterString(unsigned char* dataPtr)
{	E_SPI_ERROR e= SPI_E_N_OK;
	while (*dataPtr!='\0')
	{	
		e=MCAL_SPI_SendRx(dataPtr);
		dataPtr++;
		
	}
	return e;
}