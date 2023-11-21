/*
 * App.h
 *
 *  Created on: 7 Nov 2023
 *      Author: Ayaya
 */

#ifndef APP_APP_H_
#define APP_APP_H_

#include "../SERVICE/OpenDoor/OpenDoor.h"
#include "../SERVICE/SET_ON_FLAG/setOnFlag.h"
#include "../SERVICE/LockHouse/lockHouse.h"
#include "../HAL/Buzzrer/BUZZER_INTERFACE.h"
#include "../MCAL/UART/Uart_interface.h"
#include "../MCAL/I2C/I2C.h"
#include "../MCAL/I2C/twi.h"

void App_init();
void App_start();


#endif /* APP_APP_H_ */
