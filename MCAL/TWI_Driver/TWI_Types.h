/*
 * TWI_Types.h
 *
 *  Created on: 2 Nov 2023
 *      Author: Ayaya
 */

#ifndef TWI_TYPES_H_
#define TWI_TYPES_H_

/* TWI prescaler value selection */
typedef enum
{
	TWI_PRESCALER_1,
	TWI_PRESCALER_4,
	TWI_PRESCALER_16,
	TWI_PRESCALER_64
}E_TWI_PRESCALER;
/* Acknowledge and not acknowledge values */
typedef enum
{
	TWI_ACK,
	TWI_NACK
}E_TWI_N_ACK;
/* Error type for TWI */
typedef enum
{
	TWI_E_OK,
	TWI_E_NOT_OK
}E_TWI_ErrorType;

/* Data to write to read from bus */
typedef unsigned char TWI_DATA;
/* Status of the TWI bus */
typedef unsigned char TWI_Status;
/* Slave address */
typedef unsigned char TWI_SlaveAddress;
/* Mask the prescaler bits in status register */
#define TWI_SR_PRE_MASK  				0xF8
/* TWI bus status values */
#define TWI_MASTER_START				0x08
#define TWI_MASTER_RESTART				0x10
#define TWI_MASTER_SLA_W_ACK			0x18
#define TWI_MASTER_SLA_W_NACK			0x20
#define TWI_MASTER_DATA_W_ACK			0x28
#define TWI_MASTER_DATA_W_NACK			0x30
#define TWI_MASTER_ARBITRATION_LOST		0x38
#define TWI_MASTER_SLA_R_ACK			0x40
#define TWI_MASTER_SLA_R_NACK			0x48
#define TWI_MASTER_DATA_R_ACK			0x50
#define TWI_MASTER_DATA_R_NACK			0x58
#define TWI_SLAVE_SLA_W_ACK				0x60
#define TWI_SLAVE_ARB_SLA_W_ACK			0x68
#define TWI_SLAVE_GENERAL_CALL_ACK		0x70
#define TWI_SLAVE_ARB_SLA_R_ACK			0x78
#define TWI_SLAVE_PRE_SLA_W_ACK			0x80
#define TWI_SLAVE_PRE_SLA_W_NACK		0x88
#define TWI_SLAVE_PRE_GENERAL_CALL_ACK	0x90
#define TWI_SLAVE_PRE_GENERAL_CALL_NACK	0x98
#define TWI_SLAVE_RESTART_STOP			0xA0
#define TWI_SLAVE_SLA_R_ACK				0xA8
#define TWI_SLAVE_DATA_W_ACK			0xB8
#define TWI_SLAVE_DATA_W_NACK			0xC0
#define TWI_SLAVE_LAST_DATA_W_ACK		0xC8
#define TWI_MISCELLANEOUS_NO_STATE		0xF8
#define TWI_MISCELLANEOUS_BUS_ERROR		0x00



#endif /* TWI_TYPES_H_ */
