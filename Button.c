/*
 * Button.c
 *
 *  Created on: Oct 25, 2023
 *      Author: dell
 */

#ifndef HAL_BUTTON_BUTTON_C_
#define HAL_BUTTON_BUTTON_C_

#include "Button_interface.h"
#include "Button_config.h"



/* Initialize the Button */
E_ErrorType HAL_BUTTON_init( )
{
	E_ErrorType u8LocalReturn =NOT_OK;
	S_Dio Button_interface;
	Button_interface.port_num=Button_port;
	Button_interface.pin_num=Button_pin;
	Button_interface.Direction=INPUT;
	u8LocalReturn=MCAL_Dio_Init(&Button_interface);
	return OK;
}

/* Read the button */
E_ErrorType HAL_BUTTON_read(u8PinValue *btn_state)
{
	E_ErrorType u8LocalReturn =NOT_OK;
		S_Dio Button_interface;
		Button_interface.port_num=Button_port;
		Button_interface.pin_num=Button_pin;
		u8LocalReturn= MCAL_Dio_ReadPin(&Button_interface,btn_state);
		return OK;
}

/* Set button as pull up */
E_ErrorType HAL_BUTTON_set_pullup()
{
	E_ErrorType u8LocalReturn =NOT_OK;
	S_Dio Button_interface;
	Button_interface.port_num=Button_port;
	Button_interface.pin_num=Button_pin;
	u8LocalReturn=MCAL_Dio_WritePin(&Button_interface,PIN_HIGH);
	return OK;
}



#endif /* HAL_BUTTON_BUTTON_C_ */
