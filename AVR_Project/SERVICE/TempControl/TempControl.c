/*
 * TempControl.c
 *
 *  Created on: 6 Nov 2023
 *      Author: Ayaya
 */

#include "TempControl.h"

void SERVICE_TempControl(void)
{
	unsigned long int adcValue = MCAL_ADC_read(CH1);
	unsigned char tempValue = HAL_LM35_readTemp(adcValue);
	S_DCMOTOR S_DC={'B','B','B',3,5,6,1};
	if(tempValue < LOW_TEMP)
	{
		//Fan off
		HAL_DCMOTOR_vStopMotor(&S_DC);
		//AC off
		HAL_LED_OFF(AC_LED_PORT, AC_LED_PIN);
	}
	else if(tempValue >= LOW_TEMP)
	{
		//Fan low speed
		HAL_DCMOTOR_Ehalfspeed(&S_DC);
		//AC off
		HAL_LED_OFF(AC_LED_PORT, AC_LED_PIN);
	}
	else if(tempValue >= MED_TEMP)
	{
		//Fan high speed
		HAL_DCMOTOR_Efullspeed(&S_DC);
		//AC off
		HAL_LED_OFF(AC_LED_PORT, AC_LED_PIN);
	}
	else if(tempValue >= HIGH_TEMP)
	{
		//Fan off
		HAL_DCMOTOR_vStopMotor(&S_DC);
		//AC on
		HAL_LED_ON(AC_LED_PORT, AC_LED_PIN);
	}
	else
	{
		//Do nothing
	}
}
