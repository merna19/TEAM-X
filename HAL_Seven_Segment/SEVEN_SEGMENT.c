/*
 * SEVEN_SEGMENT.c
 *
 *  Created on: Oct 25, 2023
 *      Author: Marii
 */

#include "SEG_Interface.h"
#include <util/delay.h>
#include "SEG_Types.h"

E_Error_Type HAL_SEG_INIT(){
	E_Error_Type u8LocalReturn = ENOT_OK;
	S_Dio P1 = {segPORT, PIN0_ID, OUTPUT};
	S_Dio P2 = {segPORT, PIN1_ID, OUTPUT};
	S_Dio P3 = {segPORT, PIN2_ID, OUTPUT};
	S_Dio P4 = {segPORT, PIN3_ID, OUTPUT};
	S_Dio P5 = {segPORT, PIN4_ID, OUTPUT};
	S_Dio P6 = {segPORT, PIN5_ID, OUTPUT};
	S_Dio P7 = {segPORT, PIN6_ID, OUTPUT};
	S_Dio P8 = {segPORT, PIN7_ID, OUTPUT};
	//MCAL_Dio_Init(&P3);
	u8LocalReturn = MCAL_Dio_SetPortDirection(&P1);
	u8LocalReturn = MCAL_Dio_SetPortDirection(&P2);
	u8LocalReturn = MCAL_Dio_SetPortDirection(&P3);
	u8LocalReturn = MCAL_Dio_SetPortDirection(&P4);
	u8LocalReturn = MCAL_Dio_SetPortDirection(&P5);
	u8LocalReturn = MCAL_Dio_SetPortDirection(&P6);
	u8LocalReturn = MCAL_Dio_SetPortDirection(&P7);
	u8LocalReturn = MCAL_Dio_SetPortDirection(&P8);
	return u8LocalReturn;

}

E_Error_Type HAL_SEG_WRITE(u8PortValue Port_value){
	E_Error_Type u8LocalReturn = ENOT_OK;
	S_Dio P2 = {segPORT, PIN0_ID, PIN_LOW};
	#if   SEVEN_SEG_TYPE == SEVEN_SEGMENT_C
	u8PortValue numbers_C[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	u8LocalReturn = MCAL_Dio_WritePort(&P2, numbers_C[Port_value]);
	#elif SEVEN_SEG_TYPE == SEVEN_SEGMENT_A
	u8PortValue numbers_A[10]={~0x3f,~0x06,~0x5b,~0x4f,~0x66,~0x6d,~0x7d,~0x07,~0x7f,~0x6f};
	u8LocalReturn = MCAL_Dio_WritePort(&P2, numbers_A[Port_value]);
	#endif

	return u8LocalReturn;
}

/*void SEG_BCD_INIT(E_DioPort port){

}

void SEG_BCD_WRITE(E_DioPort port, u8PortValue Port_value){

}*/
