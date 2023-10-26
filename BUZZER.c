/*
 * BUZZER.c
 *
 *  Created on: Oct 25, 2023
 *      Author: Marii
 */


#include "BUZZER_Interface.h"


void BUZZER_INIT(E_DioPort port, E_DioPin pin){
	S_Dio P1 = {port,pin,OUTPUT};

	MCAL_Dio_Init(&P1);

}

void BUZZER_ON(E_DioPort port, E_DioPin pin){

	MCAL_Dio_WritePin(port, pin, 0xFF);

}

void BUZZER_OFF(E_DioPort port, E_DioPin pin){

	MCAL_Dio_WritePin(port, pin, 0x00);

}
