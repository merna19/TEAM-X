/*
 * LCD_Config.h
 *
 *  Created on: 26 Oct 2023
 *      Author: Ayaya
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/* LCD Ports, pins, and mode configuration */

#include "DIO_Driver/DIO_Types.h"

/* Data bits mode... 4 or 8 */
#define LCD_DATA_BITS_MODE 4
#define LOWER_PORT_PINS
/* Control PORT and Pins */
#define LCD_RS_PORT	PORTA_ID
#define LCD_RW_PORT	none
#define LCD_RS_PIN	PIN3_ID
#define LCD_RW_PIN	none
#define LCD_E_PORT	PORTA_ID
#define LCD_E_PIN	PIN2_ID
/* Data PORT and Pins */
#define LCD_DATA_PORT	PORTB_ID
#define LCD_D0_PIN  	none
#define LCD_D1_PIN		none
#define LCD_D2_PIN		none
#define LCD_D3_PIN		none
#define LCD_D4_PIN		PIN0_ID
#define LCD_D5_PIN		PIN1_ID
#define LCD_D6_PIN		PIN2_ID
#define LCD_D7_PIN		PIN4_ID
#endif /* LCD_CONFIG_H_ */
