/*
 * BUZZER_Interface.h
 *
 *  Created on: Oct 25, 2023
 *      Author: Marii
 */

#ifndef BUZZER_BUZZER_INTERFACE_H_
#define BUZZER_BUZZER_INTERFACE_H_

#include "DIO_interface.h"


void BUZZER_INIT(E_DioPort port, E_DioPin pin);
void BUZZER_ON(E_DioPort port, E_DioPin pin);
void BUZZER_OFF(E_DioPort port, E_DioPin pin);
#endif /* BUZZER_BUZZER_INTERFACE_H_ */
