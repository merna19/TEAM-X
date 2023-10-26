/*
 * LED_Interface.h
 *
 *  Created on: Oct 25, 2023
 *      Author: Marii
 */

#ifndef LED_LED_INTERFACE_H_
#define LED_LED_INTERFACE_H_

#include "DIO_interface.h"
#include <util/delay.h>


void LED_INIT(E_DioPort port, E_DioPin pin);

void LED_ON(E_DioPort port, E_DioPin pin);

void LED_OFF(E_DioPort port, E_DioPin pin);

void LED_TOGGLE(E_DioPort port, E_DioPin pin);
#endif /* LED_LED_INTERFACE_H_ */
