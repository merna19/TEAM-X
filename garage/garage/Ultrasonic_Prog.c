/*
 * Ultrasonic_Prog.c
 *
 * Created: 11/5/2023 8:20:47 PM
 *  Author: LENOVO
 */ 
#include "Ultrasonic_Interface.h"
#include "DIO.h"
#include "std_macros.h"
#define F_CPU	16000000
#include <util/delay.h>
#include <avr/io.h>
void HAL_ULTRASONIC_EINIT(void)
{
	DIO_vsetbitdir(TRIGGER_PORT,TRIGGER_PIN,1);
	DIO_vsetbitdir(ECHO_PORT,ECHO_PIN,0);
	Pullup_enable(ECHO_PORT,ECHO_PIN,1);
	//SET_BIT(TIMSK,TICIE1);
}

void HAL_ULTRASONIC_EtrigPULSE(void)
{
	DIO_vpinwrite(TRIGGER_PORT,TRIGGER_PIN,1);
	_delay_us(50);
	DIO_vpinwrite(TRIGGER_PORT,TRIGGER_PIN,0);
}

void HAL_ULTRASONIC_EdistanceESTIMATION(unsigned short* distance)
{
	TCCR1A=0;
	unsigned short rise,fall,high;
	SET_BIT(TIFR,ICF1);
	HAL_ULTRASONIC_EtrigPULSE();
	TCNT1=0X0000;
	TCCR1B=0b11000001;//0xc1 NOISE CANCELLER & RISING EDGE & NO PRESCALLER
	while (READ_BIT(TIFR,ICF1)!=1);
	rise=ICR1;
	SET_BIT(TIFR,ICF1);
	TCCR1B=0b10000001;//0x81 NOISE CANCELLER & FALLING EDGE & NO PRESCALLER
	
	while (READ_BIT(TIFR,ICF1)!=1);
	fall=ICR1;
	SET_BIT(TIFR,ICF1);
	TCNT1=0X0000;
	TCCR1B=0X00;
	high=fall-rise;
	(*distance)=(high*SPEED_OF_SOUND)/(F_CPU*2);
}