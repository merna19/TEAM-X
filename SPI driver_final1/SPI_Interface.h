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
#include "DIO_Interface.h"
#include "SPI_Types.h"

#define HIGH	1
#define	LOW	0
/*
	description: this function initiates the master pins
*/
E_SPI_ERROR MCAL_SPI_vinitMaster(void);
/*
	description:this function initiates the slave pins
*/
E_SPI_ERROR MCAL_SPI_vinitSlave(void);
/*
	description: this function sends/recieves one byte
*/
E_SPI_ERROR MCAL_SPI_SendRx(unsigned char* data);
/*
	description: this function activates the slave select pin
*/
E_SPI_ERROR MCAL_SPI_SlaveActivate(void);
/*
	description: this function sends a string of data
*/
E_SPI_ERROR MCAL_SPI_MasterString(unsigned char* dataPtr);



#endif /* SPI_INTERFACE_H_ */