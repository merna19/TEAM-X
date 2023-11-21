/*
 * ultrasonic sensor.c
 *
 * Created: 11/1/2023 6:38:20 PM
 * Author : LENOVO
 */ 

#include "Ultrasonic_Interface.h"
#include "LCD_interface.h"
#define F_CPU	16000000
#include <util/delay.h>
int main(void)
{	E_LCD_ERRORTYPE error=LCD_E_NOT_OK;
	error=HAL_ULTRASONIC_EINIT();
	unsigned short distance=0;
    error= HAL_ULTRASONIC_EINIT();
    while (1) 
    {
		error=HAL_ULTRASONIC_EdistanceESTIMATION(&distance);
		error=HAL_LCD_init();
		error=HAL_LCD_sendString("distance=");
		error=HAL_LCD_integerToString(distance);
		error=HAL_LCD_sendString("CM");
		_delay_ms(1000);
		if(distance>=80)
		{
			error=HAL_LCD_goToRowColumn(2,1);
			error=HAL_LCD_sendString("OUT OF RANGE");
			_delay_ms(2000);
		}
		
    }
}

