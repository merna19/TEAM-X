/*
 * EverythingOn.c
 *
 *  Created on: 7 Nov 2023
 *      Author: Ayaya
 */

#include "EverythingOn.h"

void SERVICE_EVERYTHING_ON()
{

	while(lockedFlag == 0)
	{
		SERVICE_TempControl();
		SERVICE_Curtain_Control();
		SERVICE_LEDS_Control();
		SERVICE_DisplayDateTime(&RTCData);
	}
}
