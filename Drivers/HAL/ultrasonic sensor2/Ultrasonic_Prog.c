/*
 * Ultrasonic_Prog.c
 *
 * Created: 11/5/2023 8:20:47 PM
 *  Author: LENOVO
 */ 
#include "Ultrasonic_Interface.h"
#include "DIO_interface.h"
#include "common_macros.h"
#define F_CPU	16000000
#include <util/delay.h>
#include <avr/io.h>//DON'T FORGET!! delete it and include the TIMER1 REG FILE
E_ULTRASONIC_ERROR HAL_ULTRASONIC_EINIT(void)
{	
	E_ULTRASONIC_ERROR e= ULTRASONIC_OK;
	S_Dio	S_trigger={TRIGGER_PORT,TRIGGER_PIN,OUTPUT};
	S_Dio S_ECHO={ECHO_PORT,ECHO_PIN,INPUT};
	e=MCAL_Dio_Init(&S_trigger);
	e=MCAL_Dio_Init(&S_ECHO);
	e=MCAL_Dio_WriteSinglePin(&S_ECHO,ECHO_PIN,1);
	//SET_BIT(TIMSK,TICIE1);
	return e;
}

E_ULTRASONIC_ERROR HAL_ULTRASONIC_EtrigPULSE(void)
{	E_ULTRASONIC_ERROR e= ULTRASONIC_OK;
	S_Dio	S_trigger={TRIGGER_PORT,TRIGGER_PIN,OUTPUT};
	e= MCAL_Dio_WriteSinglePin(&S_trigger,TRIGGER_PIN,1);
	_delay_us(50);
	e= MCAL_Dio_WriteSinglePin(&S_trigger,TRIGGER_PIN,0);
	return e;
}

E_ULTRASONIC_ERROR HAL_ULTRASONIC_EdistanceESTIMATION(unsigned short* distance)
{	E_ULTRASONIC_ERROR e= ULTRASONIC_OK;
	TCCR1A=0;
	unsigned short rise,fall,high;
	SET_BIT(TIFR,ICF1);
	HAL_ULTRASONIC_EtrigPULSE();
	TCNT1=0X0000;
	TCCR1B=0b11000001;//0xc1 NOISE CANCELLER & RISING EDGE & NO PRESCALLER
	while (GET_BIT(TIFR,ICF1)!=1);
	rise=ICR1;
	SET_BIT(TIFR,ICF1);
	TCCR1B=0b10000001;//0x81 NOISE CANCELLER & FALLING EDGE & NO PRESCALLER
	
	while (GET_BIT(TIFR,ICF1)!=1);
	fall=ICR1;
	SET_BIT(TIFR,ICF1);
	TCNT1=0X0000;
	TCCR1B=0X00;
	high=fall-rise;
	(*distance)=(high*SPEED_OF_SOUND)/(F_CPU*2);
	return e;
}