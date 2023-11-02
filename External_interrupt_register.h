/*
 * External_interrupt_register.h

 *
 *  Created on: Oct 29, 2023
 *      Author: dell
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_REGISTER_H_
#define MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_REGISTER_H_

/************************************************************************/
/* interrupt                                                                      */
/************************************************************************/
 /* MCU control register */
#define MCUCR *((volatile unsigned int *)0x55)
/* MCU control and status register */
#define MCUCSR *((volatile unsigned int *)0x54)
/* General interrupt control register */
#define GICR *((volatile unsigned int *)0x5B)
/* General interrupt flag register */
#define GIFR *((volatile unsigned int*)0x5A)
/* External interrupt 0 sense bits */
#define ISC00   0
#define ISC01   1
/* External interrupt 1 sense bits */
#define ISC10   2
#define ISC11   3
/* External interrupt 2 sense bits */
#define ISC2   6
/* External interrupt enable bits */
#define INT2    5
#define INT0    6
#define INT1    7


#endif /* MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_REGISTER_H_ */
