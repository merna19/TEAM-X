/*
 * TWI_Interface.h
 *
 *  Created on: 2 Nov 2023
 *      Author: Ayaya
 */

#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_


#include "TWI_Config.h"
#include "TWI_Private.h"
#include "TWI_Types.h"
#include "TWI_Registers.h"
#include "../DIO_Driver/DIO_interface.h"
#include <avr/io.h>

/* Function that initializes the TWI  */
void MCAL_TWI_init();
/* Function that starts the TWI communication */
E_TWI_ErrorType MCAL_TWI_start();
/* Function that send repeated start to the TWI bus */
E_TWI_ErrorType MCAL_TWI_repeatStart();
/* Function for Master Transmitter mode that sends SLA+W the bus */
E_TWI_ErrorType MCAL_TWI_MT_SLA_W(TWI_SlaveAddress slaveAdd);
/* Function for Master Transmitter that writes data on the bus */
E_TWI_ErrorType MCAL_TWI_MT_write(TWI_DATA writeData);
/* Function for Master Transmitter mode that sends SLA+R the bus */
E_TWI_ErrorType MCAL_TWI_MT_SLA_R(TWI_SlaveAddress slaveAdd);
/* Function for Master Receiver that reads data from the bus */
E_TWI_ErrorType MCAL_TWI_MR_read(TWI_DATA* readData);
/* Function that stops the communication */
void MCAL_TWI_stop();
/* Function that gets the status of the TWI bus */
TWI_Status MCAL_TWI_getStatus();
/* Function that initializes the slave given its address */
void MCAL_TWI_SlaveInit(TWI_SlaveAddress slaAdd);
/* Function for slave to wait till it's addressed */
void MCAL_TWI_SlaveListen();
/* Function for Slave Transmitter to transmit data */
E_TWI_ErrorType MCAL_TWI_ST_send(TWI_DATA sendData);
/* Function for Slave Receiver to receive data */
E_TWI_ErrorType MCAL_TWI_SR_receive(TWI_DATA* receiveData);

#endif /* TWI_INTERFACE_H_ */
