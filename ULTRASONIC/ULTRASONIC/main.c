#include <avr/io.h>
#define  F_CPU 16000000UL
#include <util/delay.h>
#include "LCD_Interface.h"
#include "ultrasonic_interface.h"
int main(void)
{
	HAL_LCD_init();
	unsigned short dis=0;
	unsigned short* distance=&dis;
	HAL_ULTRASONIC_EInit();
	while(1)
	{
		HAL_ULTRASONIC_u8ReadDistance(distance);
		HAL_LCD_clearScreen();
		HAL_LCD_sendString("DISTANCE");
		HAL_LCD_integerToString(*distance);
		HAL_LCD_sendString("cm");
		_delay_ms(500);
	}
}

