#ifndef ROOMDATA_H_INCLUDED
#define ROOMDATA_H_INCLUDED


#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#define Single_Full 2000
#define Single_Half 1000

#define Double_Full 3000
#define Double_Half 2000

#define Trible_Full 4000
#define Trible_Half 3000

#define Family_Full 5000
#define Family_Half 4000

#define Pool_Price 500
#define Beach_Price 1000

#define S_size 5
#define D_size 5
#define T_size 5
#define F_size 5



typedef enum
{
    type_single=1,
    type_double,
    type_trible,
    type_family
}room_type;

typedef enum room_view
{
    view_garden=1,
    view_pool,
    view_beach
}room_view;

typedef enum
{
    not_available,
    available

}avail;

typedef enum
{
    full = 1,
    half

}meal_type;

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

typedef struct lst
{
    struct node* top;
}lst;

typedef struct node
{
    struct roomData room;
    struct node* next;

}node;

 struct node *S_head ;
 struct node *D_head ;
 struct node *T_head ;
 struct node *F_head ;



int getID(struct roomData * room); // Get a variable from struct
void setID(struct roomData * room, int id);
int getDays(struct roomData * room); // Get a variable from struct
void setDays(struct roomData * room, int daysNo);
char getRoomType(struct roomData * room); // Get a variable from struct
void setRoomType(struct roomData * room, room_type type);
char getRoomView(struct roomData * room); // Get a variable from struct
void setRoomView(struct roomData * room,room_view view);
char getAvail(struct roomData * room); // Get a variable from struct
void setAvail(struct roomData * room, avail availablility);
/*****************************/

int getPriceFull(struct roomData * room); // Get a variable from struct
void setPriceFull(struct roomData * room, int pricefull);
int getPriceHalf(struct roomData * room); // Get a variable from struct
void setPriceHalf(struct roomData * room, int pricehalf);
int getPriceFinal(struct roomData * room); // Get a variable from struct
void setPriceFinal(struct roomData * room, int pricefinal);
char getMealType(struct roomData * room); // Get a variable from struct
void setMealType(struct roomData * room, meal_type typeMeal);
int checkAvailability(room_type type,room_view view);
void generateList(int s_size, int d_size, int t_size, int f_size, lst* ptrL);

void printRoomList();

void reservation();

void start();


#endif // ROOMDATA_H_INCLUDED
