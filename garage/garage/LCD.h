#ifndef LCD_H_
#define LCD_H_
#include "DIO.h"
#include "LCD_Config.h"


void LCD_vinit(void);
static void LCD_enable(void);//to generate enable pulse 1-5msec->static to be only called in LCD.C
void LCD_vsend_char(char data);
void LCD_vsend_string(char* data);
void LCD_vsend_command(char cmd);
void LCD_vclearscreen(void);
void LCD_vmove_cursor(char row,char col);
void LCD_integerToString(unsigned long int num);
/*char cursorPos(void);*/
#endif