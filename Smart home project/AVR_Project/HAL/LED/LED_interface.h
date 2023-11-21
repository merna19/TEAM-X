/*
 * LED_interface.h
 *
 *  Created on: Nov 6, 2023
 *      Author: pc
 */

#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_

#include "../../MCAL/DIO/DIO_interface.h"
#include <util/delay.h>
#include "LED_Types.h"



E_ErrorType_ HAL_LED_INIT(E_DioPort ledPORT, E_DioPin LEDPin);
E_ErrorType_ HAL_LED_ON(E_DioPort port, E_DioPin pin);
E_ErrorType_ HAL_LED_OFF(E_DioPort ledPORT, E_DioPin LEDPin);
E_ErrorType_ HAL_LED_TOGGLE(E_DioPort ledPORT, E_DioPin LEDPin);

#endif /* HAL_LED_LED_INTERFACE_H_ */
