/*
 * DIO.c
 *
 *  Created on: Oct 24, 2023
 *      Author: pc
 */

#include "DIO_interface.h"



Std_type Dio_SetPortDirection(S_DioSetPortDirection *Dio_ConfigPort)
{
	Std_type error = OK;
	if(DIO_STATUS_ERROR == NOT_OK)
	{
		error = NOT_OK;
	}
	else if(Dio_ConfigPort->port_num >= DIO_CONFIGURED_PORTS)
	{

		error = NOT_OK;
	}
	else
	{
		switch(Dio_ConfigPort->port_num)
		{
		case PORTA_ID:
			DIO_DDRA = Dio_ConfigPort->Direction;
			break;
		case PORTB_ID:
			DIO_DDRB = Dio_ConfigPort->Direction;
			break;
		case PORTC_ID:
			DIO_DDRC = Dio_ConfigPort->Direction;
			break;
		case PORTD_ID:
			DIO_DDRD = Dio_ConfigPort->Direction;
			break;

		}
	}

	return error;
}

Std_type Dio_SetPinDirection(S_DioSetPinDirection *Dio_ConfigPin)
{
	Std_type error = OK;
	if(DIO_STATUS_ERROR == NOT_OK)
	{
		error = NOT_OK;
	}
	else if(Dio_ConfigPin->port_num >= DIO_CONFIGURED_PORTS || Dio_ConfigPin->pin_num >DIO_CONFIGURED_PINS)
	{

		error = NOT_OK;
	}
	else
	{
		switch(Dio_ConfigPin->port_num)
		{
		case PORTA_ID:
			if(Dio_ConfigPin->Direction == PIN_HIGH)
			{
				SET_BIT(DIO_DDRA,Dio_ConfigPin->pin_num);
			}
			else
			{
				CLEAR_BIT(DIO_DDRA,Dio_ConfigPin->pin_num);
			}

			break;
		case PORTB_ID:
			if(Dio_ConfigPin->Direction == PIN_HIGH)
			{
				SET_BIT(DIO_DDRB,Dio_ConfigPin->pin_num);
			}
			else
			{
				CLEAR_BIT(DIO_DDRB,Dio_ConfigPin->pin_num);
			}
			break;
		case PORTC_ID:
			if(Dio_ConfigPin->Direction == PIN_HIGH)
			{
				SET_BIT(DIO_DDRC,Dio_ConfigPin->pin_num);
			}
			else
			{
				CLEAR_BIT(DIO_DDRC,Dio_ConfigPin->pin_num);
			}
			break;
		case PORTD_ID:
			if(Dio_ConfigPin->Direction == PIN_HIGH)
			{
				SET_BIT(DIO_DDRD,Dio_ConfigPin->pin_num);
			}
			else
			{
				CLEAR_BIT(DIO_DDRD,Dio_ConfigPin->pin_num);
			}
			break;

		}
	}

	return error;

}


Std_type Dio_ReadPort(E_DioPort Port_Num,u8PortValue Port_Value)
{
	Std_type error = OK;
	if(DIO_STATUS_ERROR == NOT_OK)
	{
		error = NOT_OK;
	}
	else if(Port_Num > DIO_CONFIGURED_PORTS)
	{

		error = NOT_OK;
	}
	else
	{
		switch (Port_Num)
		{
		case PORTA_ID:
			Port_Value = DIO_PINA;
			break;
		case PORTB_ID:
			Port_Value = DIO_PINB;
			break;
		case PORTC_ID:
			Port_Value = DIO_PINC;
			break;
		case PORTD_ID:
			Port_Value = DIO_PIND;
			break;

		}
	}
	return error;
}

Std_type Dio_ReadPin(E_DioPort Port_Num, E_DioPin Pin_Num,u8PinValue Pin_Value)
{


}
