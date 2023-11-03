/*
 * main.c

 *
 *  Created on: Oct 26, 2023
 *      Author: dell
 */


#include "APP/app.h"

int main(void)
{
	APP_app_init();
	while(1)
	{
		APP_app_start();
	}
	return 0;
}


