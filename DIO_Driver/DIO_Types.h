/*
 * DIO_Types.h
 *
 *  Created on: Oct 24, 2023
 *      Author: pc
 */

#ifndef DIO_TYPES_H_
#define DIO_TYPES_H_





typedef unsigned char u8PortID;
typedef unsigned char u8PinID;
typedef unsigned char u8Direction;
typedef unsigned char u8PortValue;
typedef unsigned char u8PinValue;
typedef unsigned char Std_type;





typedef enum
{
	PORTA_ID,
	PORTB_ID,
	PORTC_ID,
	PORTD_ID
}E_DioPort;

typedef enum
{
	PIN0_ID,
	PIN1_ID,
	PIN2_ID,
	PIN3_ID,
	PIN4_ID,
	PIN5_ID,
	PIN6_ID,
	PIN7_ID,
}E_DioPin;




typedef struct
{
    E_DioPort port_num;
    E_DioPin  pin_num;
	u8Direction Direction;
}S_DioSetPinDirection;

typedef struct
{
    E_DioPort port_num;
	u8Direction Direction;
}S_DioSetPortDirection;





#endif /* DIO_TYPES_H_ */
