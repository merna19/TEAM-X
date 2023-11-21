#ifndef LAUNDRY_H_INCLUDED
#define LAUNDRY_H_INCLUDED
/* Variable  no of pieces that is used to  get the number of pieces from the user*/
static unsigned int  no_of_pieces;
int total_price_laundry;

/* Enumeration Variable select services laundry is used to select services*/
enum select_services_laundry{
     /* Washing clothes is element in enumeration represent number 1*/
    Washing_clothes=1,
    /* Ironing clothes is element in enumeration  represent number 2*/
    Ironing_clothes,
    /* Washing ironing clothes is element in enumeration represent number 3*/
    Washing_ironing_clothes

}Services_laundry[3];
/* Structure services price contain variables that are used to calculate the price laundry services*/
struct Services_prices_laundry{
    /* Variable that is used to calculate Washing ironing clothes prices */
  unsigned int Washing_ironing_clothes;
   /* Variable that is used to calculate Washing  clothes prices */
  unsigned int Washing_clothes;
   /* Variable that is used to calculate ironing clothes prices */
  unsigned int  Ironing_clothes;

}Prices_laundry;
/* Function show services and prices is used to show details about this service */
void Show_services_and_price();
/* Function confirmation laundry is used to confirm the reserve*/
void confirmation_Laundry(struct Services_prices_laundry* ptr);



#endif // LAUNDRY_H_INCLUDED
