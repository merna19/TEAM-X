/*
 * DIO_interface.h
 *
 *  Created on: Oct 24, 2023
 *      Author: pc
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "common_macros.h"
#include "DIO_registers.h"
#include "DIO_Types.h"
#include "DIO_private.h"
#include "DIO_config.h"
#include "DIO.stdtypes.h"


/****************************************Functions Prototypes******************************/


Std_type Dio_SetPortDirection(S_DioSetPortDirection *Dio_ConfigPort);
Std_type Dio_SetPinDirection(S_DioSetPinDirection *Dio_ConfigPin);

Std_type Dio_ReadPort(E_DioPort Port_Num,u8PortValue Port_Value);
Std_type Dio_ReadPin(E_DioPort Port_Num,E_DioPin Pin_Num,u8PinValue Pin_Value);

Std_type Dio_WritePort(E_DioPort Port_Num,u8PortValue Port_Value);
Std_type Dio_WritePin(E_DioPort Port_Num,E_DioPin Pin_Num,u8PinValue Pin_value);




#endif /* DIO_INTERFACE_H_ */
