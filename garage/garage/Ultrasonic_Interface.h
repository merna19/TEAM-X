/*
 * Ultrasonic_Interface.h
 *
 * Created: 11/5/2023 8:21:10 PM
 *  Author: LENOVO
 */ 


#ifndef ULTRASONIC_INTERFACE_H_
#define ULTRASONIC_INTERFACE_H_
#define SPEED_OF_SOUND	/*((331.45+0.607*27)*100)*/34300

#include "Ultrasonic_Config.h"
void HAL_ULTRASONIC_EINIT(void);

void HAL_ULTRASONIC_EtrigPULSE(void);

void HAL_ULTRASONIC_EdistanceESTIMATION(unsigned short* distance);



#endif /* ULTRASONIC_INTERFACE_H_ */