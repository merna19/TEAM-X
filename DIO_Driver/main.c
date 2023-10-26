/*

 * main.c
 *
 *  Created on: Oct 24, 2023
 *      Author: pc
 */

#include <avr/io.h>
#include <util/delay.h>

#include "DIO_interface.h"
#include "Dio_stdtypes.h"

#define HIGH 1


int main()
{
	S_Dio s1;




	S_Dio P1={PORTC_ID,PIN1_ID |PIN7_ID ,OUTPUT};

	S_Dio p2={PORTB_ID,(PIN3_ID ),OUTPUT };
	S_Dio p3={PORTB_ID,(PIN5_ID| PIN7_ID|PIN4_ID),OUTPUT};


	u8PinValue *x;
	//x = 0xFF;
	//Dio_SetPortDirection(&P1);
	//Dio_ReadPort(PORTD_ID,x);
	//MCAL_Dio_Init(&p2);
	MCAL_Dio_Init(&p2);

	//MCAL_Dio_SetPortDirection(&p2);
	//MCAL_Dio_SetPinDirection(&p2);
	//MCAL_Dio_WritePort(PORTD_ID,0x00);
	//MCAL_Dio_WritePin(PORTD_ID,PIN6_ID,PORT_HIGH);

	//MCAL_Dio_SetPinDirection(&P1);
	//MCAL_Dio_SetPinDirection(&p2);
	//MCAL_Dio_WritePort(&p3,0x8F8);
	MCAL_Dio_WritePin(&p3,PIN_HIGH);
	//MCAL_Dio_WritePort(&p2,PORT_HIGH);
	PORTB = 0xFF;








	while(1)
	{

		MCAL_Dio_ReadPin(&p2,PIN5_ID,&x);
			if(x == 1)
			{
				DDRA = 0xFF;
			}
			else
			{
				DDRD =0xFF;
			}

			_delay_ms(500);

	}

	return 0;


}
