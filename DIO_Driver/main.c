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
	S_Dio s1;




	S_Dio P1={PORTC_ID,PIN1_ID,OUTPUT};

	S_Dio p2={PORTD_ID,(PIN3_ID | PIN2_ID | PIN6_ID),OUTPUT};
	S_Dio p3={PORTB_ID,PIN5_ID| PIN7_ID,OUTPUT};


	//u8PortValue x;
	//x = 0xFF;
	//Dio_SetPortDirection(&P1);
	//Dio_ReadPort(PORTD_ID,x);
	//MCAL_Dio_Init(&p2);
	u8PinValue value;
	MCAL_Dio_SetPortDirection(&p2);
	MCAL_Dio_WritePort(PORTD_ID,0x00);
	MCAL_Dio_WritePin(PORTD_ID,PIN6_ID,PORT_HIGH);
	MCAL_Dio_ReadPin(p2.port_num,6,value);




	if(value == PIN_HIGH)
	{
		MCAL_Dio_SetPinDirection(&P1);
	}
	else
	{

		MCAL_Dio_SetPinDirection(&p3);
	}


	while(1)
	{

	}

	return 0;


}
