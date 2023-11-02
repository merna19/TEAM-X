/*
 * ultrasonic_interface.h
 *
 * Created: 11/1/2023 9:33:42 PM
 *  Author: LENOVO
 */ 
#ifndef ULTRASONIC_INTERFACE_H_
#define ULTRASONIC_INTERFACE_H_
#include <avr/io.h>
#include "ultrasonic_Registers.h"
#include "ultrasonic_config.h"
#include "ultrasonic_private.h"
#include "ultrasonic_Types.h"
#include "DIO.h"
#define F_CPU 16000000
#include <util/delay.h>
/*
Service name: HAL_ULTRASONIC_EInit
Description:	It initiates the trigger pin for the ultrasonic sensor
Sync/Async:	Synchronous
Re-entrancy:	Re-enterant
Parameters (in):	--
Parameters (out):	--
Parameters (inout):	--
Return type:	Std_type(error)
*/
void HAL_ULTRASONIC_EInit(void);

/*
Service name:	HAL_ULTRASONIC_u8ReadDistance
Description:	It reads the sent distance by the ultrasonic sensor
Sync/Async:	Synchronous
Re-entrancy:	Re-enterant
Parameters (in):	--
Parameters (out):	--
Parameters (inout):	distance pointer: location of distance estimated by ultrasonic sensor
Return type:	stdType(error)
*/
void HAL_ULTRASONIC_u8ReadDistance(unsigned short* distance);

#endif /* ULTRASONIC_INTERFACE_H_ */