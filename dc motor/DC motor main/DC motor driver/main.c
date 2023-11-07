/*
 * DC motor driver.c
 *
 * Created: 11/5/2023 7:44:02 AM
 * Author : LENOVO
 */ 

#include "DCMOTOR_Interface.h"
#define F_CPU	16000000UL
#include <util/delay.h>

S_DCMOTOR S_DC={'B','B','B',3,5,6,1};
	
int main(void)
{	
    HAL_DCMOTOR_Einit(&S_DC);
	/*HAL_DCMOTOR_Ehalfspeed(&S_DC);
	_delay_ms(10000);*/
	HAL_DCMOTOR_Efullspeed(&S_DC);
    while (1) 
    {
		
    }
}

