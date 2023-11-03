/*
 * SPI_Interface.h
 *
 * Created: 11/3/2023 4:59:13 PM
 *  Author: LENOVO
 */ 


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

#include "SPI_Config.h"
#include "SPI_registers.h"
#include "DIO.h"
#define HIGH	1
#define	LOW	0

void SPIvinitMaster(void);
void SPIvinitSlave(void);
void SPISendRx(unsigned char* data);
void SPISlaveActivate(void);
void SPIMasterString(unsigned char* dataPtr);



#endif /* SPI_INTERFACE_H_ */