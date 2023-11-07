/*
 * LCD.c
 *
 * Created: 8/1/2023 7:10:42 PM
 * Author: MERNA
 */ 

#include "LCD.h"

#define  F_CPU 8000000UL
#include <util/delay.h>

void LCD_vinit()
{	
	#if defined EIGHT_MODE
	//set all pins to be outputs
	DIO_vsetportdir(portd,1);
	DIO_vsetbitdir(port2,E,1);
	DIO_vsetbitdir(port2,RS,1);
	DIO_vsetbitdir(port2,RW,1);
	DIO_vpinwrite(port2,RW,0);//write=0
	
	LCD_vsend_command(RETURN_HOME)
	_delay_ms(10);//wait for the cmd register to flush	
	LCD_vsend_command(eight_mode);
	
	#elif defined FOUR_MODE
	DIO_vsetbitdir(portd,0,1);
	DIO_vsetbitdir(portd,1,1);
	DIO_vsetbitdir(portd,2,1);
	DIO_vsetbitdir(portd,4,1);
	DIO_vsetbitdir(port2,E,1);
	DIO_vsetbitdir(port2,RS,1);
	/*DIO_vsetbitdir(port2,RW,1);
	DIO_vpinwrite(port2,RW,0);//write=0*/
	
	LCD_vsend_command(RETURN_HOME);//must be called before four mode cmd
	_delay_ms(10);//wait for the cmd register to flush
	LCD_vsend_command(four_mode);
	#endif
	_delay_ms(1);
	LCD_vsend_command(DISPLAY_ON_CURSOR_ON);
	_delay_ms(1);
	LCD_vsend_command(ENTRY_MODE);
	_delay_ms(1);
	LCD_vsend_command(CLEAR);
}
static void LCD_enable()
{	//you can enable lcd by sending a pulse of length 1-5msec
	DIO_vpinwrite(port2,E,1);
	_delay_ms(2);
	DIO_vpinwrite(port2,E,0);
	_delay_ms(2);
}


void LCD_vsend_char(char data)
{	
	#if defined eight_mode
	DIO_vportwrite(portd,data);
	DIO_vpinwrite(port2,RS,1);
	LCD_enable();
	
	#elif defined four_mode
	char dataH=((data>>4)&(0x07))|(((data>>4)&(0x08))<<1);
	//write_high_nibble(portd,data>>4);
	DIO_vportwrite(portd,dataH);
	DIO_vpinwrite(port2,RS,1);
	LCD_enable();
	char dataL=((data)&(0x07))|(((data)&(0x08))<<1);
	DIO_vportwrite(portd,dataL);
	//write_high_nibble(portd,data);
	DIO_vpinwrite(port2,RS,1);
	LCD_enable();
	#endif
}
void LCD_vsend_command(char cmd)
{
	#if defined eight_mode
	DIO_vportwrite(portd,cmd);
	DIO_vpinwrite(port2,RS,0);
	LCD_enable();
	
	#elif defined four_mode
	char cmdH=((cmd>>4)&(0x07))|(((cmd>>4)&(0x08))<<1);
	DIO_vportwrite(portd,cmdH);
	/**/
	//write_high_nibble(portd,cmd>>4);
	DIO_vpinwrite(port2,RS,0);
	LCD_enable();
	char cmdL=(cmd&(0x07))|(((cmd)&(0x08))<<1);
	DIO_vportwrite(portd,cmdL);
	/**/
	//write_high_nibble(portd,cmd);
	DIO_vpinwrite(port2,RS,0);
	LCD_enable();
	#endif
}
void LCD_vsend_string(char* data)
{
	while((*data)!='\0')
	{
		LCD_vsend_char(*data);
		data++;
	}
} 
void LCD_vclearscreen()
{
	LCD_vsend_command(CLEAR);
	_delay_ms(10);
}
void LCD_vmove_cursor(char row,char col)
{	if((col<1)||(col>16)||(row<1)||(row>2))//limit your cursor within your LCD
		LCD_vsend_command(0x80);
	else{
			switch (row)
			{	case 1:
						LCD_vsend_command(0x80|(col-1));
						break;
				case 2:
						LCD_vsend_command(0xC0|(col-1));
						break;
			}
		}
	_delay_ms(10);
}
void LCD_integerToString(unsigned long int num)
{
	
	signed char str[16];
	unsigned char i, rem, len=0;
	unsigned long int n = num;
	if(n ==0)
	{
		len = 1;
	}
	else
	{
		while(n != 0)
		{
			len++;
			n /= 10;
		}
	}
	for(i=0 ; i<len ; i++)
	{
		rem = num % 10;
		num = num /10;
		str[len - (i + 1)] = rem + '0';
	}
	str[len] = '\0';
	LCD_vsend_string(str);
	
}