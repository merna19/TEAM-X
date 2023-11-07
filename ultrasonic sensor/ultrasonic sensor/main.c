/*
 * ultrasonic sensor.c
 *
 * Created: 11/1/2023 6:38:20 PM
 * Author : LENOVO
 */ 

#include "Ultrasonic_Interface.h"
#include "LCD.h"
#define F_CPU	16000000
#include <util/delay.h>
int main(void)
{	LCD_vinit();
	unsigned short distance=0;
    HAL_ULTRASONIC_EINIT();
    while (1) 
    {
		HAL_ULTRASONIC_EdistanceESTIMATION(&distance);
		LCD_vclearscreen();
		LCD_vsend_string("distance=");
		LCD_integerToString(distance);
		LCD_vsend_string("CM");
		_delay_ms(1000);
		if(distance>=80)
		{
			LCD_vmove_cursor(2,1);
			LCD_vsend_string("OUT OF RANGE");
			_delay_ms(2000);
		}
		
    }
}

