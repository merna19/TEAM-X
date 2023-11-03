/*
 * app.c
 *
 *  Created on: Oct 26, 2023
 *      Author: dell
 */

#include"app.h"


void APP_app_init()
{

	Std_type u8LocalReturn;

	u8LocalReturn =HAL_Solenoid_init();




}





void APP_app_start()
{
	Std_type u8LocalReturn;

	//u8LocalReturn =HAL_Solenoid_Open();
	u8LocalReturn =HAL_Solenoid_Close();


}


