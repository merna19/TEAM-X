/*
 * Timer0_interface.h
 *
 *  Created on: Oct 28, 2023
 *      Author: pc
 */

#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

#include "Timer0_config.h"
#include "Timer0_register.h"
#include "Timer0_private.h"
#include "Timer0_types.h"
#include "common_macros.h"


#define OVER_FLOW_MODE 0
#define CTC_MODE 1
#define FAST_PWM_MODE 2
#define PCP_PWM_MODE 3

#define TIMER0_MODE OVER_FLOW_MODE


/***********************************************************
 *
 *                   Functions Prototypes
 *
 **********************************************************/


E_ErrorType MCAL_Timer0_Init(E_Prescaler prescaler,u8CompareValue CompareValue,u8DutyCyle Duty_Cycle);



#endif /* TIMER0_INTERFACE_H_ */
