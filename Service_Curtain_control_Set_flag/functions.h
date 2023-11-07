/*
 * functions.h
 *
 *  Created on: Nov 7, 2023
 *      Author: Marii
 */

#ifndef SERVICE_FUNCTIONS_H_
#define SERVICE_FUNCTIONS_H_

#include "configs.h"
#include "DIO_interface.h"
#include "ADC.h"
#include "LDR_Interface.h"
#include "SERVO.h"

void Set_Flag(void);
void Curtain_Control(void);

#endif /* SERVICE_FUNCTIONS_H_ */
