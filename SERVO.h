/*
 * SERVO.h
 *
 *  Created on: Nov 2, 2023
 *      Author: Marii
 */

#ifndef SERVO_SERVO_H_
#define SERVO_SERVO_H_

#include "DIO_interface.h"
#include "Timer0_interface.h"
#include "SERVO_Types.h"
#include "Timer1_Interface.h"
#include "SERVO_CFG.h"


ERR_TYPE HAL_SERVO_INIT();

ERR_TYPE HAL_SERVO_Write(char pos);

ERR_TYPE HAL_SERVO_Increment(int num);

ERR_TYPE HAL_SERVO_Write_CW();

ERR_TYPE HAL_SERVO_Write_CCW();

#endif /* SERVO_SERVO_H_ */
