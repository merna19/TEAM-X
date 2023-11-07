/*
 * Servo.c
 *
 *  Created on: Nov 2, 2023
 *      Author: Marii
 */


#include "SERVO.h"
#include "util/delay.h"
#include "DIO_Driver/DIO_interface.h"
#include "DIO_Driver/DIO_Types.h"
#include "DIO_Driver/DIO_registers.h"
#include "DIO_Driver/common_macros.h"


ERR_TYPE HAL_SERVO_INIT(){
	ERR_TYPE u8LocalReturn = _E_NOT_OK ;
	u8LocalReturn =  Timer1_Init(mode,pscaler);
	TCNT1 = 0;
	ICR1 = 39999;
	OCR1A = 0;
		return u8LocalReturn;

}


ERR_TYPE HAL_SERVO_Write(char pos){
	ERR_TYPE u8LocalReturn = _E_NOT_OK ;
	u8LocalReturn = Timer1_OCRA1Mode(OCRA_NON_INVERTING);
	switch (pos){
	case 1:
		OCR1A = 186;	//Set servo shaft at 0° position
		break;
	case 2:
	OCR1A = 300;	//Set servo at +90 position
		break;

	case 3:
		OCR1A = 0;	//Set servo -90	position
		break;
	}

	return u8LocalReturn;
}

ERR_TYPE HAL_SERVO_Increment(int num){
	ERR_TYPE u8LocalReturn = _E_NOT_OK ;
	u8LocalReturn = Timer1_OCRA1Mode(OCRA_NON_INVERTING);
	OCR1A = 194 + (num);
	/*if(num<0){
		OCR1A = 194 + (num+5);

	}
	else if (num ==0){
		OCR1A = 194 + (num);

	}
	else if(num>0 && num<15){
		OCR1A = 194 + (num);
	}
	else{
		OCR1A = 194 + (num-13);
	}*/
		return u8LocalReturn;

}

ERR_TYPE HAL_SERVO_Write_CW(){
	ERR_TYPE u8LocalReturn = _E_NOT_OK ;
	u8LocalReturn = HAL_SERVO_Write(3);
	return u8LocalReturn;
}

ERR_TYPE HAL_SERVO_Write_CCW(){
	ERR_TYPE u8LocalReturn = _E_NOT_OK ;
	u8LocalReturn = HAL_SERVO_Write(2);
	return u8LocalReturn;
}
