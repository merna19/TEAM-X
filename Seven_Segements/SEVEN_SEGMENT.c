/*
 * SEVEN_SEGMENT.c
 *
 *  Created on: Oct 25, 2023
 *      Author: Marii
 */

#include "SEG_Interface.h"
#include "SEG_cfg.h"
#include <util/delay.h>

void SEG_INIT(E_DioPort port){
	S_Dio P1 = {port, PIN0_ID, OUTPUT};
	S_Dio P2 = {port, PIN1_ID, OUTPUT};
	S_Dio P3 = {port, PIN2_ID, OUTPUT};
	S_Dio P4 = {port, PIN3_ID, OUTPUT};
	S_Dio P5 = {port, PIN4_ID, OUTPUT};
	S_Dio P6 = {port, PIN5_ID, OUTPUT};
	S_Dio P7 = {port, PIN6_ID, OUTPUT};
	S_Dio P8 = {port, PIN7_ID, OUTPUT};
	//MCAL_Dio_Init(&P3);
	MCAL_Dio_SetPortDirection(&P1);
	MCAL_Dio_SetPortDirection(&P2);
	MCAL_Dio_SetPortDirection(&P3);
	MCAL_Dio_SetPortDirection(&P4);
	MCAL_Dio_SetPortDirection(&P5);
	MCAL_Dio_SetPortDirection(&P6);
	MCAL_Dio_SetPortDirection(&P7);
	MCAL_Dio_SetPortDirection(&P8);

}

void SEG_WRITE(E_DioPort port, u8PortValue Port_value){

	#if   SEVEN_SEG_TYPE == SEVEN_SEGMENT_C
	u8PortValue numbers_C[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x47,0x7f,0x6f};
	MCAL_Dio_WritePort(port, numbers_C[Port_value]);
	#elif SEVEN_SEG_TYPE == SEVEN_SEGMENT_A
	u8PortValue numbers_A[10]={~0x3f,~0x06,~0x5b,~0x4f,~0x66,~0x6d,~0x7d,~0x47,~0x7f,~0x6f};
	MCAL_Dio_WritePort(port, numbers_A[Port_value]);
	#endif
}

/*void SEG_BCD_INIT(E_DioPort port){

}

void SEG_BCD_WRITE(E_DioPort port, u8PortValue Port_value){

}*/
