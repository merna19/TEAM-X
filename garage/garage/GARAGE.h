/*
 * GARAGE.h
 *
 * Created: 11/6/2023 1:07:22 PM
 *  Author: LENOVO
 */ 


#ifndef GARAGE_H_
#define GARAGE_H_
#include "Ultrasonic_Interface.h"
#include "LCD.h"

#define DOOR_HIEGHT	60
#define DOOR_THER	20


void SERVICE_GARAGE_Einit(void);
void SERVICE_GARAGE_openDoor(void);
void SERVICE_GARAGE_closeDoor(void);



#endif /* GARAGE_H_ */