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


ERR_TYPE HAL_SERVO_INIT(servo_pin_num pin);
ERR_TYPE HAL_SERVO_Write(servo_pin_num pin, servo_pose pos);

ERR_TYPE HAL_SERVO_Increment(servo_pin_num pin,int num);

ERR_TYPE HAL_SERVO_Write_CW(servo_pin_num pin);

ERR_TYPE HAL_SERVO_Write_CCW(servo_pin_num pin);

#endif /* SERVO_SERVO_H_ */
