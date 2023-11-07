/*
 * TWI_Prog.c
 *
 *  Created on: 2 Nov 2023
 *      Author: Ayaya
 */


#include "TWI_Interface.h"

/* Function that initializes the TWI  */
void MCAL_TWI_init()
{
	/* Prescaler = 1 */
	CLEAR_BIT(TWSR, TWPS0);
	CLEAR_BIT(TWSR, TWPS1);
	/* Set the bit rate */
	TWBR = (unsigned char)TWI_TWBR_VALUE;
	/* Enable the TWI */
	SET_BIT(TWCR, TWEN);
}
/* Function that starts the TWI communication */
E_TWI_ErrorType MCAL_TWI_start()
{
	E_TWI_ErrorType u8ReturnType = TWI_E_NOT_OK;
	/* SEt the start condition bit */
	SET_BIT(TWCR, TWSTA);
	/* Clear the interrupt flag */
	SET_BIT(TWCR, TWINT);
	/* Wait until the start condition is transmitted */
	while(GET_BIT(TWCR, TWINT) == 0);
	/* Get the bus status and check if the start condition is transmitted */
	while(MCAL_TWI_getStatus() != TWI_MASTER_START);
	{
		u8ReturnType = TWI_E_OK;
	}
	//else
	{
		//Do nothing
	}
	return u8ReturnType;
}
/* Function that send repeated start to the TWI bus */
E_TWI_ErrorType MCAL_TWI_repeatStart()
{
	E_TWI_ErrorType u8ReturnType = TWI_E_NOT_OK;
	/* SEt the start condition bit */
	SET_BIT(TWCR, TWSTA);
	/* Clear the interrupt flag */
	SET_BIT(TWCR, TWINT);
	/* Wait until the start condition is transmitted */
	while(GET_BIT(TWCR, TWINT) == 0);
	/* Get the bus status and check if the start condition is transmitted */
	while(MCAL_TWI_getStatus() != TWI_MASTER_RESTART);
	u8ReturnType = TWI_E_OK;
	return u8ReturnType;
}
/* Function for Master Transmitter mode that sends SLA+W the bus */
E_TWI_ErrorType MCAL_TWI_MT_SLA_W(TWI_SlaveAddress slaveAdd)
{
	E_TWI_ErrorType u8ReturnType = TWI_E_NOT_OK;
	/* Put the slave address + W in data register... slave address 7bits */
	TWDR = slaveAdd;
	/* Start sending the byte */
	/* Clear the start bit */
	CLEAR_BIT(TWCR, TWSTA);
	/* Clear the interrupt flag */
	SET_BIT(TWCR, TWINT);
	/* Wait until the data is transmitted */
	while(GET_BIT(TWCR, TWINT) == 0);
	/* Check if SLA+W has been transmitted */
	while(MCAL_TWI_getStatus()!= TWI_MASTER_SLA_W_ACK);

	u8ReturnType = TWI_E_OK;

	return u8ReturnType;
}
/* Function for Master Transmitter that writes data on the bus */
E_TWI_ErrorType MCAL_TWI_MT_write(TWI_DATA writeData)
{
	E_TWI_ErrorType u8ReturnType = TWI_E_NOT_OK;
	/* Put the data in data register */
	TWDR = writeData;
	/* Start sending the byte */
	/* Clear the interrupt flag */
	SET_BIT(TWCR, TWINT);
	/* Wait until the data is transmitted */
	while(GET_BIT(TWCR, TWINT) == 0);
	/* Check if data has been transmitted */
	while(MCAL_TWI_getStatus()!= TWI_MASTER_DATA_W_ACK);

	u8ReturnType = TWI_E_OK;

	return u8ReturnType;
}
/* Function for Master Transmitter mode that sends SLA+R the bus */
E_TWI_ErrorType MCAL_TWI_MT_SLA_R(TWI_SlaveAddress slaveAdd)
{
	E_TWI_ErrorType u8ReturnType = TWI_E_NOT_OK;
	/* Put the slave address + R in data register... slave address 7bits */
	TWDR = (slaveAdd | 0x01);
	/* Start sending the byte */
	/* Clear the start bit */
	CLEAR_BIT(TWCR, TWSTA);
	/* Clear the interrupt flag */
	SET_BIT(TWCR, TWINT);
	/* Wait until the data is transmitted */
	while(GET_BIT(TWCR, TWINT) == 0);
	/* Check if SLA+R has been transmitted */
	while(MCAL_TWI_getStatus()!= TWI_MASTER_SLA_R_ACK);

	u8ReturnType = TWI_E_OK;

	return u8ReturnType;
}
/* Function for Master Receiver that reads data from the bus */
E_TWI_ErrorType MCAL_TWI_MR_read(TWI_DATA* readData)
{
	E_TWI_ErrorType u8ReturnType = TWI_E_NOT_OK;
	/* Start receiving the byte */
	/* Set the Acknowledge bit */
	SET_BIT(TWCR, TWEA);
	/* Clear the interrupt flag */
	SET_BIT(TWCR, TWINT);
	/* Wait until the data is transmitted */
	while(GET_BIT(TWCR, TWINT) == 0);
	/* Check if data has been transmitted */
	while(MCAL_TWI_getStatus()!= TWI_MASTER_DATA_R_ACK);

	u8ReturnType = TWI_E_OK;
	*readData = TWDR;

	return u8ReturnType;
}
/* Function that stops the communication */
void MCAL_TWI_stop()
{
	/* SEt the stop condition bit */
	SET_BIT(TWCR, TWSTO);
	/* Clear the interrupt flag */
	SET_BIT(TWCR, TWINT);
}
/* Function that gets the status of the TWI bus */
TWI_Status MCAL_TWI_getStatus()
{
	TWI_Status busStatus = TWSR & TWI_SR_PRE_MASK;

	return busStatus;
}
/* Function that initializes the slave given its address */
void MCAL_TWI_SlaveInit(TWI_SlaveAddress slaAdd)
{
	/* Set the salve address */
	TWAR = slaAdd;
	CLEAR_BIT(TWAR, 0);
	/* Clear the start bit */
	CLEAR_BIT(TWCR, TWSTA);
	/* Set the Acknowledge bit */
	SET_BIT(TWCR, TWEA);
	/* Clear the interrupt flag */
	SET_BIT(TWCR, TWINT);
}
/* Function for slave to wait till it's addressed */
void MCAL_TWI_SlaveListen()
{
	/* Wait to be addressed */
	while(GET_BIT(TWCR, TWINT) == 0);
}
/* Function for Slave Transmitter to transmit data */
E_TWI_ErrorType MCAL_TWI_ST_send(TWI_DATA sendData)
{
	E_TWI_ErrorType u8ReturnType = TWI_E_NOT_OK;
	/* Wait to be addressed */
	MCAL_TWI_SlaveListen();
	/* If slave is addressed with R */
	while(MCAL_TWI_getStatus()!= TWI_SLAVE_SLA_R_ACK);

	TWDR = sendData;
	/* Clear the start bit */
	CLEAR_BIT(TWCR, TWSTA);
	/* Clear the interrupt flag */
	SET_BIT(TWCR, TWINT);
	/* Wait until the data is transmitted */
	while(GET_BIT(TWCR, TWINT) == 0);
	/* Check if data has been sent */
	while(MCAL_TWI_getStatus()!= TWI_SLAVE_DATA_W_ACK);

	u8ReturnType = TWI_E_OK;

	return u8ReturnType;
}
/* Function for Slave Receiver to receive data */
E_TWI_ErrorType MCAL_TWI_SR_receive(TWI_DATA* receiveData)
{
	E_TWI_ErrorType u8ReturnType = TWI_E_NOT_OK;
	/* Wait to be addressed */
	MCAL_TWI_SlaveListen();
	/* If slave is addressed with W */
	while(MCAL_TWI_getStatus()!= TWI_SLAVE_SLA_W_ACK);
	/* Clear the interrupt flag */
	SET_BIT(TWCR, TWINT);
	/* Wait until the data is received */
	while(GET_BIT(TWCR, TWINT) == 0);
	/* Get the received data */
	*receiveData = TWDR;
	u8ReturnType = TWI_E_OK;
	return u8ReturnType;
}
