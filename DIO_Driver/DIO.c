/*
 * DIO.c
 *
 *  Created on: Oct 24, 2023
 *      Author: pc
 */

#include "DIO_interface.h"

Std_type MCAL_Dio_Init(S_Dio *Dio_Config)
{
	Std_type error = OK;
	u8RegisterValue Mask1,Mask2;
	if(DIO_STATUS_ERROR == NOT_OK)
	{
		error = NOT_OK;
	}
	else if(Dio_Config->port_num >= DIO_CONFIGURED_PORTS)
	{

		error = NOT_OK;
	}
	else
	{

		Mask2 = ((Dio_Config->pin_num) & (Dio_Config->Direction));
		switch(Dio_Config->port_num)
		{
		case PORTA_ID:
			Mask1 = ((DIO_DDRA) & (~(Dio_Config->pin_num)));
			DIO_DDRA = Mask1 | Mask2;
			break;
		case PORTB_ID:
			Mask1 = ((DIO_DDRB) & (~(Dio_Config->pin_num)));
			DIO_DDRB = Mask1 | Mask2;
			break;
		case PORTC_ID:
			Mask1 = ((DIO_DDRC) & (~(Dio_Config->pin_num)));
			DIO_DDRC = Mask1 | Mask2;
			break;
		case PORTD_ID:
			Mask1 = ((DIO_DDRD) & (~(Dio_Config->pin_num)));
			DIO_DDRD = Mask1 | Mask2;
			break;

		}
	}

	return error;
}

Std_type MCAL_Dio_SetPortDirection(S_Dio *Dio_ConfigPort)
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

Std_type MCAL_Dio_SetPinDirection(S_Dio *Dio_ConfigPin)
{
	Std_type error = OK;
	u8RegisterValue Mask1,Mask2;

	if(DIO_STATUS_ERROR == NOT_OK)
	{

		error = NOT_OK;
	}
	else if(Dio_ConfigPin->port_num >= DIO_CONFIGURED_PORTS)
	{

		error = NOT_OK;
	}
	else
	{
		Mask2 = ((Dio_ConfigPin->pin_num) & (Dio_ConfigPin->Direction));
		switch(Dio_ConfigPin->port_num)
		{
		case PORTA_ID:
			Mask1 = ((DIO_DDRA) & (~(Dio_ConfigPin->pin_num)));
			DIO_DDRA = Mask1 | Mask2;
			break;
		case PORTB_ID:
			Mask1 = ((DIO_DDRB) & (~(Dio_ConfigPin->pin_num)));
			DIO_DDRB = Mask1 | Mask2;
			break;
		case PORTC_ID:
			Mask1 = ((DIO_DDRC) & (~(Dio_ConfigPin->pin_num)));
			DIO_DDRC = Mask1 | Mask2;
			break;
		case PORTD_ID:
			Mask1 = ((DIO_DDRD) & (~(Dio_ConfigPin->pin_num)));
			DIO_DDRD = Mask1 | Mask2;
			break;

		}
	}

	return error;

}


Std_type MCAL_Dio_ReadPort(E_DioPort Port_Num,u8PortValue Port_Value)
{
	Std_type error = OK;
	if(DIO_STATUS_ERROR == NOT_OK)
	{
		error = NOT_OK;
	}
	else if(Port_Num >= DIO_CONFIGURED_PORTS)
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

Std_type MCAL_Dio_ReadPin(E_DioPort Port_Num,E_DioPin Pin_Num,u8PinValue Pin_Value)
{
	Std_type error = OK;

	if(DIO_STATUS_ERROR == NOT_OK)
	{
		error = NOT_OK;
	}
	else if(Port_Num >= DIO_CONFIGURED_PORTS)
	{

		error = NOT_OK;

	}
	else
	{

		switch(Port_Num)
		{
		case PORTA_ID:
			if(BIT_IS_SET(DIO_PINA,Pin_Num))
			{
				Pin_Value =PIN_HIGH;
			}
			else
			{
				Pin_Value =PIN_LOW;
			}
			break;
		case PORTB_ID:
			if(BIT_IS_SET(DIO_PINB,Pin_Num))
			{
				Pin_Value = PIN_HIGH;
			}
			else
			{
				Pin_Value = PIN_LOW;
			}
			break;
		case PORTC_ID:
			if(BIT_IS_SET(DIO_PINC,Pin_Num))
			{
				Pin_Value =PIN_HIGH;
			}
			else
			{
				Pin_Value =PIN_LOW;
			}
			break;
		case PORTD_ID:
			if(BIT_IS_SET(DIO_PORTD ,Pin_Num))
			{
				Pin_Value =PIN_HIGH;
			}
			else
			{
				Pin_Value =PIN_LOW;
			}

			break;
		}
	}
	return error;
}


Std_type MCAL_Dio_WritePort(E_DioPort Port_Num,u8PortValue Port_Value)
{
	Std_type error = OK;

	if(DIO_STATUS_ERROR == NOT_OK)
	{
		error = NOT_OK;
	}
	else if(Port_Num >= DIO_CONFIGURED_PORTS)
	{

		error = NOT_OK;
	}
	else
	{
		switch (Port_Num)
		{
		case PORTA_ID:
			DIO_PORTA = Port_Value;
			break;
		case PORTB_ID:
			DIO_PORTB = Port_Value;
			break;
		case PORTC_ID:
			DIO_PORTC = Port_Value;
			break;
		case PORTD_ID:
			DIO_PORTD = Port_Value;
			break;
		}
	}
	return error;
}


Std_type MCAL_Dio_WritePin(E_DioPort Port_Num,E_DioPin Pin_Num,u8PinValue Pin_value)
{
	Std_type error = OK;
	u8RegisterValue Mask1,Mask2;
	if(DIO_STATUS_ERROR == NOT_OK)
	{
		error = NOT_OK;
	}
	else if(Port_Num >= DIO_CONFIGURED_PORTS)
	{

		error = NOT_OK;
	}
	else
	{

		Mask2 = ((Pin_Num) & (Pin_value));
		switch(Port_Num)
		{
		case PORTA_ID:
			Mask1 = ((DIO_PORTA) & (~(Pin_Num)));
			DIO_DDRA = Mask1 | Mask2;
			break;
		case PORTB_ID:
			Mask1 = ((DIO_PORTB) & (~(Pin_Num)));
			DIO_PORTB = Mask1 | Mask2;
			break;
		case PORTC_ID:
			Mask1 = ((DIO_PORTC) & (~(Pin_Num)));
			DIO_PORTC = Mask1 | Mask2;
			break;
		case PORTD_ID:
			Mask1 = ((DIO_PORTD) & (~(Pin_Num)));
			DIO_PORTD = Mask1 | Mask2;
			break;

		}
	}
	return error;
}
