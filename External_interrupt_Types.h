/*
 * External_interrupt_Types.h

 *
 *  Created on: Oct 29, 2023
 *      Author: dell
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_TYPES_H_
#define MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_TYPES_H_

#define OK       0
#define NOT_OK   1
#define NULL 0

#define Interrupt_STATUS_ERROR OK

static void (*ptr2fun_ext_int_0)(void) = NULL;
static void (*ptr2fun_ext_int_1)(void) = NULL;
static void (*ptr2fun_ext_int_2)(void) = NULL;

typedef unsigned char E_Error_state;
typedef enum{
	ext_int_0,
	ext_int_1,
	ext_int_2

}ext_int;

typedef enum{
	low_level_sense,
	anyLogicChange_sense,
	falling_edge_sense,
	rising_edge_sense
}EN_interrupt_sense_t;




#endif /* MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_TYPES_H_ */
