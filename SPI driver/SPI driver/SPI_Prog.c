/*
 * SPI_Prog.c
 *
 * Created: 11/3/2023 5:02:11 PM
 *  Author: LENOVO
 */ 
#include "SPI_Interface.h"

void SPIvinitMaster(void)
{
	//set output pins
	DIO_vsetbitdir(MSTR_PORT,SS,HIGH);
	DIO_vsetbitdir(MSTR_PORT,MOSI,HIGH);
	DIO_vsetbitdir(MSTR_PORT,SCK,HIGH);
	
	//set master bit Enable SPI and SPI interrupt
	//SPX2 SPR1 SPR0 =>0 0 0 => CLK=F_CPU/4 (SPI FREQUENCY CONDITION CHECKED)
	SPCR|=(1<<MSTR)|(1<<SPIE)|(1<<SPE);
	//De-activate SS pin
	DIO_vpinwrite(MSTR_SS_PORT,SS,HIGH);
}
void SPIvinitSlave(void)
{
	//SET output pins
	DIO_vsetbitdir(SLAVE_PORT,MISO,HIGH);
	
	//ENABLE SPI and SPI interrupt enable
	SPCR=(1<<SPE)|(1<<SPIE);
}
void SPISendRx(unsigned char* data)
{
	SPDR=*data;
	while(READ_BIT(SPSR,SPIF)==0);
	*data=SPDR;
}
void SPISlaveActivate(void)
{
	//activate SS pin To interact
	DIO_vpinwrite(SLAVE_PORT,SS,LOW);
}
void SPIMasterString(unsigned char* dataPtr)
{
	while (*dataPtr!='\0')
	{
		SPISendRx(*dataPtr);
		dataPtr++;
	}
}