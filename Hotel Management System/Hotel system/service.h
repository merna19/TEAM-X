#ifndef SERVICE_H_INCLUDED
#define SERVICE_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"RoomData.h"
#include"heads.h"
#include"Spa.h"
#include"Laundry.h"
#include "Restaurant.h"
#include "GYM.h"
//#include"RoomData.c"


/* Variable enum guest check is used to know  if guest is full or half board. */
enum CHF{
    /* Element in enum guest check*/
    half_board=1,
    /* Element in enum guest check. */
    full_board=2
}Guest_check;

/* Enum Variable entery is used to know if the guest wants to reserve or cancel */
enum Reserve_Cancel{
    /* Element in enum entery. */
    reserve=1,
    /* Element in enum entery. */
    cancel=2
}Entery;

enum services
{
    spa=1,
    laundry,
    rest,
    gymm
}Select_Servies;

/* Function Check is used to know  the guest is half or full board */
char Check();

/* Function reserve_or_cancel is used to know  that if the guest want to reserve or not */
char Reserve_or_cancel();
void Laundry();
void Spa();
void Services_select(user_data* head);



#endif
