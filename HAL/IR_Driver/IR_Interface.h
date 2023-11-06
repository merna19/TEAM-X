/*
 * IR_Interface.h
 *
 *  Created on: 5 Nov 2023
 *      Author: Ayaya
 */

#ifndef IR_INTERFACE_H_
#define IR_INTERFACE_H_

#include "IR_Config.h"
#include "IR_Private.h"
#include "IR_Registers.h"
#include "IR_Types.h"
#include "DIO_Driver/DIO_interface.h"



void HAL_IR_Init();

unsigned char HAL_IR_Read();

#endif /* IR_INTERFACE_H_ */
