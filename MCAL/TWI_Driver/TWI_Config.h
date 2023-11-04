/*
 * TWI_Config.h
 *
 *  Created on: 2 Nov 2023
 *      Author: Ayaya
 */

#ifndef TWI_CONFIG_H_
#define TWI_CONFIG_H_

#define CPU_FREQ 16000000UL
#define TWI_SCL_FREQUENCY 1000000UL
#define TWI_TWBR_VALUE (((CPU_FREQ/TWI_SCL_FREQUENCY)-16)/(2*4))

#endif /* TWI_CONFIG_H_ */
