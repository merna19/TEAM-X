/*
 * SPI_registers.h
 *
 * Created: 11/3/2023 4:49:31 PM
 *  Author: LENOVO
 */ 


#ifndef SPI_REGISTERS_H_
#define SPI_REGISTERS_H_


#define SPDR	(*((volatile unsigned char*)(0x2F)))
#define SPSR	(*(volatile unsigned char*)(0x2E))
#define SPCR	(*(volatile unsigned char*)(0x2D))
#define MSTR	4
#define	SPIE	7
#define	SPE	6
#define SPIF	7

#endif /* SPI_REGISTERS_H_ */