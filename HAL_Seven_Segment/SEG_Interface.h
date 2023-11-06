/*
 * SEG_Interface.h
 *
 *  Created on: Oct 25, 2023
 *      Author: Marii
 */

#ifndef SEVEN_SEGMENT_SEG_INTERFACE_H_
#define SEVEN_SEGMENT_SEG_INTERFACE_H_

#include "DIO_interface.h"
#include "SEG_cfg.h"
#include "SEG_Types.h"

#define SEVEN_SEGMENT_C      0
#define SEVEN_SEGMENT_A      1


E_Error_Type HAL_SEG_INIT();

E_Error_Type HAL_SEG_WRITE(u8PortValue Port_value);

/*void SEG_BCD_INIT(E_DioPort port);

void SEG_BCD_WRITE(E_DioPort port, u8PortValue Port_value);*/


#endif /* SEVEN_SEGMENT_SEG_INTERFACE_H_ */
