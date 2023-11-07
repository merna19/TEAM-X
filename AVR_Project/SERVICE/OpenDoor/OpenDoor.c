/*
 * OpenDoor.c
 *
 *  Created on: 7 Nov 2023
 *      Author: Ayaya
 */


#include "OpenDoor.h"

void SERVICE_OPEN_DOOR()
{
	//PAssword
	if(Enter_Password()==0)
	{
		//Check IR

		SERVICE_Check_IR();

	}
	else
	{
		//Do nothing
	}


}
