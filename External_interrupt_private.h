/*
 * External_interrupt_private.h

 *
 *  Created on: Oct 29, 2023
 *      Author: dell
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_PRIVATE_H_
#define MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_PRIVATE_H_

/* External Interrupt Request 0 */
#define EXT_INT_0 __vector_1
/* External Interrupt Request 1 */
#define EXT_INT_1 __vector_2
/* External Interrupt Request 2 */
#define EXT_INT_2 __vector_3

/* Enable global interrupts */
#define sei() __asm__ __volatile__ ("sei" ::: "memory")

/* Disable global interrupts */
#define cei() __asm__ __volatile__ ("cei" ::: "memory")

/* Macro defines the ISR */
#define ISR(INT_VECT) void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)

#endif /* MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_PRIVATE_H_ */
