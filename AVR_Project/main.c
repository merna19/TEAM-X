
#include "HAL/LCD/lcd_Interface.h"
#include "HAL/RTC/RTC_interface.h"
#include "HAL/Password/password.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


#define HIGH 1


int main()
{
	u8Data buffer[20];


	HAL_LCD_init();
	HAL_LCD_sendString("3ars");


	u8Value value = Enter_Password();

	//S_RTCData RTCData = {6,11,23,7,11,46,50};

	//HAL_RTC_Init(&RTCData);

	while(1)
	{
/*
		HAL_RTC_ReadTime(&RTCData);
		HAL_LCD_sendString("YES");
			sprintf(buffer, "%02x:%02x:%02x  ", RTCData.hours, RTCData.minutse, RTCData.seconds);
			HAL_LCD_displaystringRowColumn(buffer ,0, 0);

			HAL_RTC_ReadDate(&RTCData);
			sprintf(buffer, "%02x/%02x/%02x", RTCData.day_num, RTCData.month, RTCData.year);
			HAL_LCD_displaystringRowColumn(buffer ,1, 0);
			*/

	}
	return 0;


}
