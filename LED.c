/*
 * LED.c
 *
 *  Created on: Oct 25, 2023
 *      Author: Marii
 */

#include "LED_Interface.h"


void LED_INIT(E_DioPort port, E_DioPin pin){
	S_Dio P2 = {port,pin,OUTPUT};

	MCAL_Dio_Init(&P2);

}

void LED_ON(E_DioPort port, E_DioPin pin){

	MCAL_Dio_WritePin(port, pin, 0xFF);

}

void LED_OFF(E_DioPort port, E_DioPin pin){

	MCAL_Dio_WritePin(port, pin, 0x00);

}

void LED_TOGGLE(E_DioPort port, E_DioPin pin){

	MCAL_Dio_WritePin(port, pin, 0x00);
	_delay_ms(500);
	MCAL_Dio_WritePin(port, pin, 0xFF);
	_delay_ms(500);

}




