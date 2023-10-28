/*

 * main.c
 *
 *  Created on: Oct 24, 2023
 *      Author: pc
 */


#include "LCD_Interface.h"

#define HIGH 1


int main()
{

	HAL_LCD_init();
	HAL_LCD_sendCharacter('a');
	HAL_LCD_sendString("Ayaya");
	HAL_LCD_displaystringRowColumn("Hello", 1, 5);
	HAL_LCD_displayIntegerRowColumn(1234, 2, 5);
	return 0;


}
