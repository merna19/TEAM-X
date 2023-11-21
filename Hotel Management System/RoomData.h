#ifndef ROOMDATA_H_INCLUDED
#define ROOMDATA_H_INCLUDED


#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "heads.h"
#include "Laundry.h"
#include "service.h"
#include "Spa.h"
#include "Restaurant.h"
#include "GYM.h"
/* Defining room price depending on type and meal type */
#define Single_Full 2000
#define Single_Half 1000

#define Double_Full 3000
#define Double_Half 2000

#define Trible_Full 4000
#define Trible_Half 3000

#define Family_Full 5000
#define Family_Half 4000
/* Defining the additional price for view */
#define Pool_Price 500
#define Beach_Price 1000
/* Defining number of rooms in each type */
#define S_size 5
#define D_size 5
#define T_size 5
#define F_size 5


/* enum for room type */
typedef enum
{
    type_single=1,
    type_double,
    type_trible,
    type_family
}room_type;
/* enum for room view */
typedef enum room_view
{
    view_garden=1,
    view_pool,
    view_beach
}room_view;
/* enum for availability */
typedef enum
{
    not_available,
    available

}avail;
/* enum for meal type (half/full board) */
typedef enum
{
    full = 1,
    half

}meal_type;
/* Struct that holds room data */
typedef struct roomData
{
    char availability;
    int no_days;
    int roomID;
    room_type roomType;
    room_view roomView;
    meal_type mealType;
    int priceFull;
    int priceHalf;
    int priceFinal;
}roomData;
/* Linked list struct */
typedef struct lst
{
    struct node* top;
}lst;
/* List node struct */
typedef struct node
{
    struct roomData room;
    struct node* next;

}node;
/* Defining pointers to hold 1st room in each type --> single, double, trible, family */
 struct node *S_head ;
 struct node *D_head ;
 struct node *T_head ;
 struct node *F_head ;


/* A function used to get Room ID from struct */
int getID(struct roomData * room);
/* A function used to set Room ID in struct */
void setID(struct roomData * room, int id);
/* A function used to get Room number of days from struct */
int getDays(struct roomData * room);
/* A function used to set Room number of rented days in struct */
void setDays(struct roomData * room, int daysNo);
/* A function used to get Room Type from struct */
char getRoomType(struct roomData * room);
/* A function used to set Room type in struct */
void setRoomType(struct roomData * room, room_type type);
/* A function used to get Room view from struct */
char getRoomView(struct roomData * room);
/* A function used to set Room view in struct */
void setRoomView(struct roomData * room,room_view view);
/* A function used to get Room availability from struct */
char getAvail(struct roomData * room);
/* A function used to set Room availability in struct */
void setAvail(struct roomData * room, avail availablility);
/* A function used to get Room price in full board from struct */
int getPriceFull(struct roomData * room);
/* A function used to set Room price in full board in struct */
void setPriceFull(struct roomData * room, int pricefull);
/* A function used to get Room price in half board from struct */
int getPriceHalf(struct roomData * room);
/* A function used to set Room price in half board in struct */
void setPriceHalf(struct roomData * room, int pricehalf);
/* A function used to get Room final price after calculating days from struct */
int getPriceFinal(struct roomData * room);
/* A function used to set Room final price in struct */
void setPriceFinal(struct roomData * room, int pricefinal);
/* A function used to get Room meal type (half/full board) from struct */
char getMealType(struct roomData * room);
/* A function used to set Room meal type (half/full board) in struct */
void setMealType(struct roomData * room, meal_type typeMeal);
/*This functions return the ID room but if there is no available else it returns zero*/
int checkAvailability(room_type type,room_view view);
/* This function is used to generate rooms linked list along with setting room data variables with their values */
void generateList(int s_size, int d_size, int t_size, int f_size, lst* ptrL);
/* This function is used to print all rooms list along with their data */
void printRoomList();
/* This function is used to reserve a room depending on data from user */
user_data* reservation();
/* This function is used to display the home page and switch between services */
void start(userList* userL);
/* This function is used to search the list with room ID and returns a pointer to the node containing the room */
node* searchList(int sID);


#endif // ROOMDATA_H_INCLUDED
