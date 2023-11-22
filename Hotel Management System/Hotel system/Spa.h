#ifndef SPA_H_INCLUDED
#define SPA_H_INCLUDED
#include"service.h"
/* Variable no guest is used to get number of the guest from guest*/
static unsigned int no_guest;
/* Array is used to get the time from user */
static char time_of_spa[6];
/* Variable M price has the price of massages  */
 static int M_price1=300;
/* Variable F price has the price of facials  */
 static int F_price2=250;
/* Variable n price has the price of nail services  */
 static int N_price3=100;
 /* Variable H price has the price of haircuts and styling  */
static int H_price4=150;
/* Variable SR price has the price of steam room  */
static int SR_price5=250;
/* Variable Sa price has the price of saunas */
static int Sa_price6=250;
/* Variable AE price has the price of aesthetician services  */
static int AE_price7=200;

/* Enum Variable select services is used to select services*/
enum select_services_spa{
    /* Massages is element in enum represent number 1*/
    massages=1,
     /* Facials is element in enum represent number 2*/
    facials,
     /* Nail services is element in enum represent number 3*/
    nail_services,
     /* Haircuts and styling is element in enum represent number 4*/
    haircuts_and_styling,
     /* steam room is element in enum represent number 5*/
    steam_rooms,
     /* Saunas is element in enum represent number 6*/
    saunas,
     /* Aesthetician is element in enum represent number 7*/
    aesthetician_services

}Services_spa[7];



/* Function show services and price is used to show the time and price for each service*/
void Show_services_and_price();
/* Function confirmation spa is used to confirm the reserve*/
void confirmation_spa();
#endif // SPA_H_INCLUDED
