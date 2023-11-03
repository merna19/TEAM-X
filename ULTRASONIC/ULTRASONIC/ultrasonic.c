/*
 * ultrasonic.c
 *
 * Created: 11/1/2023 9:32:53 PM
 *  Author: LENOVO
 */ 

#include "ultrasonic_interface.h"

void HAL_ULTRASONIC_EInit(void)
{
	/*S_Dio* trig;
	trig->pin_num=TRIGGER_PIN;
	trig->port_num=TRIGGER_PORT;
	trig->Direction=0xFF;*///set it as output
	DIO_vsetbitdir(TRIGGER_PORT,TRIGGER_PIN,1);
}

void HAL_ULTRASONIC_u8ReadDistance(unsigned short* distance)
{	
	unsigned short a,high,b;
	TCCR1A = 0;
	TIFR = (1<<ICF1);  	/* Clear ICF (Input Capture flag)  */
	DIO_vpinwrite(TRIGGER_PORT,TRIGGER_PIN,1);
	_delay_us(50);
	DIO_vpinwrite(TRIGGER_PORT,TRIGGER_PIN,0);
	
	TCCR1B = 0xc1;  	/* Rising edge, no prescaler , noise canceler*/
	while ((TIFR&(1<<ICF1)) == 0);
	a = ICR1;  		/* Take value of capture register */
	TIFR = (1<<ICF1);  	/* Clear ICF flag */
	TCCR1B = 0x81;  	/* Falling edge, no prescaler ,noise canceler*/
	while ((TIFR&(1<<ICF1)) == 0);
	b = ICR1;  		/* Take value of capture register */
	TIFR = (1<<ICF1);  	/* Clear ICF flag */
	TCNT1=0;
	TCCR1B = 0;  		/* Stop the timer */
	high=b-a;
	*distance=((high*34600)/(F_CPU*2));
}


