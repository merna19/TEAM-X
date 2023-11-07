/*
 * GARAGE.c
 *
 * Created: 11/6/2023 1:07:06 PM
 *  Author: LENOVO
 */ 
#include "GARAGE.h"
#define F_CPU 16000000UL
#include <util/delay.h>
E_GARAGE_ERROR SERVICE_GARAGE_Einit(void)
{	E_GARAGE_ERROR error=GARAGE_OK;
	error=HAL_ULTRASONIC_EINIT();
	error=HAL_LCD_init();
	_delay_ms(200);
	return error;
}
E_GARAGE_ERROR SERVICE_GARAGE_openDoor(void)
{	E_GARAGE_ERROR error=GARAGE_OK;
	//MARIEM: CALL servo to open at 0 deg
	error=HAL_LCD_sendString("open");
	return error;
}
E_GARAGE_ERROR SERVICE_GARAGE_closeDoor(void)
{	
	E_GARAGE_ERROR error=GARAGE_OK;
	unsigned short distance=DOOR_HIEGHT;
	unsigned char garagePOS=0;
	
	while(garagePOS<180)//not completely closed 
	{	error=HAL_LCD_clearScreen();
		error=HAL_LCD_sendString("ANGLE: ");
		error=HAL_LCD_integerToString(garagePOS);
		_delay_ms(500);
		error=HAL_ULTRASONIC_EdistanceESTIMATION(&distance);
		error=HAL_LCD_clearScreen();
		error=HAL_LCD_integerToString(distance);
		error=HAL_LCD_goToRowColumn(2,1);
		
		if (distance<=DOOR_THER)
		{	_delay_ms(300);
			if (distance<=DOOR_THER)//OBSTACLE
			{	error=HAL_LCD_sendString("WATCH OUT");
				_delay_ms(700);
				error=HAL_LCD_goToRowColumn(2,1);
				error=HAL_LCD_sendString("open garage again");
				_delay_ms(800);
				error=SERVICE_GARAGE_openDoor();
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
			error=HAL_LCD_sendString("Increment SERVO");
			_delay_ms(700);
			error=HAL_LCD_integerToString(garagePOS);
		}
	}
	error=HAL_LCD_clearScreen();
	error=HAL_LCD_sendString("DOOR CLOSED");
	_delay_ms(2000);
	return error;
}