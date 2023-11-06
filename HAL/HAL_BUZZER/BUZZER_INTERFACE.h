/*
 * BUZZER_INTERFACE.h
 *
 *  Created on: Nov 6, 2023
 *      Author: Marii
 */

#ifndef BUZZER_BUZZER_INTERFACE_H_
#define BUZZER_BUZZER_INTERFACE_H_

#include "DIO_interface.h"
#include "Buzzer_Types.h"

__EErrorType HAL_BUZZER_INIT(E_DioPort BUZZERPORT, E_DioPin BUZZERPin);
__EErrorType HAL_BUZZER_ON(E_DioPort BUZZERport, E_DioPin BUZZERpin);
__EErrorType HAL_BUZZER_OFF(E_DioPort BUZZERPORT, E_DioPin BUZZERPin);

#endif /* BUZZER_BUZZER_INTERFACE_H_ */
