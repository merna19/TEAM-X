/*
 * App.c
 *
 *  Created on: 7 Nov 2023
 *      Author: Ayaya
 */

#include "App.h"

void App_init()
{
	HAL_LCD_init();
	_delay_ms(100);
	MCAL_ADC_INIT();
	HAL_IR_Init();
	HAL_BUZZER_INIT(DIO_PORTC, 6);
//
//
	I2C_Init();
	TWI_init();
	HAL_Solenoid_init();
	HAL_LDR_Init();
	MCAL_UART_init(9600);
	HAL_SERVO_INIT();
	S_RTCData RTCData = {6,11,23,7,11,46,50};
	HAL_RTC_Init(&RTCData);
	HAL_LED_INIT(AC_LED_PORT, AC_LED_PIN);
}
void App_start()
{
	HAL_LCD_sendString("aaa");
	char h = MCAL_UART_receive_sysch();
	switch(h)
	{
	case 'O':
		HAL_LCD_sendCharacter('O');
		SERVICE_OPEN_DOOR();
		break;
	case 'L':
		HAL_LCD_sendCharacter('L');
		lockHouse();
		break;
	case 'N':
		HAL_LCD_sendCharacter('N');
		SERVICE_SET_ON_FLAG();
		break;

	}
}
