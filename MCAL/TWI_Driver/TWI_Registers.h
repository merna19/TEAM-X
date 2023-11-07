/*
 * TWI_Registers.h
 *
 *  Created on: 2 Nov 2023
 *      Author: Ayaya
 */

#ifndef TWI_REGISTERS_H_
#define TWI_REGISTERS_H_



#define TWDR (*((volatile unsigned char *)0x23))
#define TWAR (*((volatile unsigned char *)0x02))
#define TWSR (*((volatile unsigned char *)0x21))
#define TWBR (*((volatile unsigned char *)0x20))
#define TWCR (*((volatile unsigned char *)0x56))


#define TWGCE	0
#define TWA0	1
#define TWA1	2
#define TWA2	3
#define TWA3	4
#define TWA4	5
#define TWA5	6
#define TWA6	7

#define TWPS0	0
#define TWPS1	1
#define TWS3	3
#define TWS4	4
#define TWS5	5
#define TWS6	6
#define TWS7	7

#define TWIE	0
#define TWEN	2
#define TWWC	3
#define TWSTO	4
#define TWSTA	5
#define TWEA	6
#define TWINT	7

#endif /* TWI_REGISTERS_H_ */
