/*
 * GARAGE.c
 *
 * Created: 11/6/2023 1:07:06 PM
 *  Author: LENOVO
 */ 
#include "GARAGE.h"
#define F_CPU 16000000UL
#include <util/delay.h>
void SERVICE_GARAGE_Einit(void)
{
	HAL_ULTRASONIC_EINIT();
	LCD_vinit();
	_delay_ms(200);
}
void SERVICE_GARAGE_openDoor(void)
{
	//MARIEM: CALL servo to open at 0 deg
	LCD_vsend_string("open");
}
void SERVICE_GARAGE_closeDoor(void)
{	
	unsigned short distance=DOOR_HIEGHT;
	unsigned char garagePOS=0;
	
	while(garagePOS<180)//not completely closed 
	{	LCD_vclearscreen();
		LCD_vsend_string("ANGLE: ");
		LCD_integerToString(garagePOS);
		_delay_ms(500);
		HAL_ULTRASONIC_EdistanceESTIMATION(&distance);
		LCD_vclearscreen();
		LCD_integerToString(distance);
		LCD_vmove_cursor(2,1);
		
		if (distance<=DOOR_THER)
		{	_delay_ms(300);
			if (distance<=DOOR_THER)//OBSTACLE
			{	LCD_vsend_string("WATCH OUT");
				_delay_ms(700);
				LCD_vmove_cursor(2,1);
				LCD_vsend_string("open garage again");
				_delay_ms(800);
				SERVICE_GARAGE_openDoor();
				garagePOS=0;
			}
			else//no obstacle
			{
				garagePOS+=10;
				
				//MARIEM: CALL SERVO TO SPIN AT garagePOS degree
			}
		}
		else
		{	garagePOS+=10;
			//MARIEM: CALL SERVO TO SPIN AT garagePOS degree
			LCD_vsend_string("Increment SERVO");
			_delay_ms(700);
			LCD_integerToString(garagePOS);
		}
	}
	LCD_vclearscreen();
	LCD_vsend_string("DOOR CLOSED");
	_delay_ms(2000);
}