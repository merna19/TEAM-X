/*
 * DC motor driver.c
 *
 * Created: 11/5/2023 7:44:02 AM
 * Author : LENOVO
 */ 

#include "DCMOTOR_Interface.h"
S_DCMOTOR S_DC={'B','c','c',3,5,6,1};
	
int main(void)
{	
    HAL_DCMOTOR_Einit(&S_DC);
	HAL_DCMOTOR_Ehalfspeed(&S_DC);
    while (1) 
    {
		
    }
}

