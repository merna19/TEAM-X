/*

 * main.c
 *
 *  Created on: Oct 24, 2023
 *      Author: pc
 */

#include <avr/io.h>
#include <util/delay.h>

#include "DIO_interface.h"



int main()
{
	S_DioSetPortDirection P1={PORTD_ID,PORT_INPUT};

	S_DioSetPinDirection p2={PORTC_ID,PIN4_ID,PIN_HIGH};
	S_DioSetPinDirection p3={PORTA_ID,PIN5_ID,PIN_HIGH};

	u8PortValue x;
	x = 0xFF;
	Dio_SetPortDirection(&P1);
	Dio_ReadPort(PORTD_ID,x);
	if(x)
	{

		 Dio_SetPinDirection(&p2);
	}
	else
	{
		//DDRA |=(1<<3);
		Dio_SetPinDirection(&p3);
	}



	while(1)
	{

	}

	return 0;


}
