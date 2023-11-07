/*
 * DCMOTOR_Interface.h
 *
 * Created: 11/5/2023 7:45:01 AM
 *  Author: LENOVO
 */ 

#ifndef DCMOTOR_INTERFACE_H_
#define DCMOTOR_INTERFACE_H_

#include "DCMOTOR_Types.h"
#define OCR0_HALFSPEED	128
void HAL_DCMOTOR_Einit(S_DCMOTOR* S_DC);

void HAL_DCMOTOR_Efullspeed(S_DCMOTOR* S_DC);

void HAL_DCMOTOR_Edirection(S_DCMOTOR* S_DC);

void HAL_DCMOTOR_Ehalfspeed(S_DCMOTOR* S_DC);
#endif /* DCMOTOR_INTERFACE_H_ */