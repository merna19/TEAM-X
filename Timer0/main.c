/*
 * main.c
 *
 *  Created on: Oct 28, 2023
 *      Author: pc
 */

#include "Timer0_interface.h"
#include "avr/interrupt.h"
#include <avr/io.h>
#include <util/delay.h>

int counter = 0;
/*
ISR(TIMER0_OVF_vect)
{
	counter ++;
	if(counter == 10)
	{
		PORTA = PORTA ^ (1<<PINA7);
		counter = 0;
	}

}
*/
/*
ISR (TIMER0_COMP_vect)
{
	counter ++;
	if(counter == 30)
		{
			PORTA = PORTA ^ (1<<PINA7);
			counter = 0;
		}

}
*/
int main(void)
{
	DDRA = 0xFF;
	PORTA =0x00;
	//SREG |=(1<<7);

	//MCAL_Timer0_OVF_Init(3);
	//MCAL_Timer0_CTC_Init(2,250);

	while(1)
	{
		MCAL_Timer0_PCPWM_Init(1,90);
		_delay_ms(1000);
		MCAL_Timer0_PCPWM_Init(1,125);
		_delay_ms(1000);


	}

	return 0;
}
