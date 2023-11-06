/*
 * DCMOTOR_Prog.c
 *
 * Created: 11/5/2023 7:44:31 AM
 *  Author: LENOVO
 */ 
#include "DCMOTOR_Interface.h"
#include "DIO.h"
#include "common_macros.h"
#include <avr/io.h>

void HAL_DCMOTOR_Einit(S_DCMOTOR* S_DC)
{	//make sure that PWM is the OC0 PIN PB3 if you want half the speed
	DIO_vsetbitdir(S_DC->PWM_port,S_DC->PWM_pin,1);//set dc motor driver PWM SIGNAL as avr output
	DIO_vsetbitdir(S_DC->DIR_port,S_DC->DIR_pin,1);//set DC motor direction pin as avr output
	DIO_vsetbitdir(S_DC->EN_port,S_DC->EN_pin,1);//set DC motor driver enable as avr output
	DIO_vpinwrite(S_DC->EN_port,S_DC->EN_pin,1);//enable the DC MOTOR DRIVER L298
}

void HAL_DCMOTOR_Edirection(S_DCMOTOR* S_DC)
{	//set the direction clkwise or anti-clkwise
	if (S_DC->clkwise==1)
	{
		DIO_vpinwrite(S_DC->DIR_port,S_DC->DIR_pin,1);		
	}
	else if (S_DC->clkwise==0)
	{
		DIO_vpinwrite(S_DC->DIR_port,S_DC->DIR_pin,0);
	}
}

void HAL_DCMOTOR_Efullspeed(S_DCMOTOR* S_DC)
{
	HAL_DCMOTOR_Edirection(S_DC);
	DIO_vpinwrite(S_DC->PWM_port,S_DC->PWM_pin,1);
};

void HAL_DCMOTOR_Ehalfspeed(S_DCMOTOR* S_DC)
{
	//use TIMER0 fast PWM to generate 50% Duty cycle 
	SET_BIT(TCCR0,WGM01);//fast PWM mode
	SET_BIT(TCCR0,WGM00);
	
	SET_BIT(TCCR0,COM00);//Set at the compare match and clear at BOTTOM (Inverting mode)
	SET_BIT(TCCR0,COM01);
	
	SET_BIT(TCCR0,CS00);//NO PRESCALAR
	
	OCR0=OCR0_HALFSPEED;
}