#ifndef LCD_Config_H_
#define LCD_Config_H_

#define portd 'B'	//data port
#define port2 'A'	//other port connected to B0,B1,B3
#define FOUR_MODE	//EIGHT PINS MODE OR FOUR PINS MODE(FOUR_MODE)
#define E 2		//ENABLE= pin 2
#define RS 3	//RW= pin 0
#define RW 4	//RS= pin 1

#define CLEAR 0x01
#define RETURN_HOME 0x02
#define ENTRY_MODE 0x06
#define DISPLAY_ON_CURSOR_ON 0x0E
#define customChar 64

#if defined EIGHT_MODE
#define eight_mode 0x38
#elif defined FOUR_MODE
#define four_mode 0x28
#endif






#endif