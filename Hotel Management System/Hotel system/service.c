#include"service.h"

/* Function Check is used to know  the guest is half or full board. */
char Check()
{
   int ID_room;
   /* Display to the user enter id room*/
   printf("Enter ID Room:");
    /* Get from the user Id room */
    scanf("%d",&ID_room);
    node * ptr=searchList( ID_room);
    if(ptr == NULL)
    {
        printf("error\n");
    }
    else{
    /* Ask user  are you half board or full board */
    printf("\t*******************\t\n");
    printf("Are you half board or full board\n");
    /* Display half board and full board */
    printf("1-Half board\n2-Full board\n");
    /* Display enter to get answer from user if he half or full */
    printf("Enter:");
    /* Get the answer from the user */
    scanf("%d",&Guest_check);
    /* Function will return the value of guest check this value can be half board or full board*/
    return Guest_check;
    }
}

/* Function reserve_or_cancel is used to know  that if the guest wants to reserve or not */
char Reserve_or_cancel()
{
/* Ask user do you want reserve or cancel */
printf("\t*******************\t\n");
printf("Do you want to reserve or cancel?\n");
/* Display reserve and cancel*/
printf("1-Reserve\n2-Cancel\n");
/* Display enter to get answer from user if he wants to reserve or cancel */
printf("Enter:");
/* Get answer from the user  if he wants to reserve or cancel */
scanf("%d",&Entery);
/* Function will return the value of Entery this value can be reserve or cancel*/
return Entery;
}

void Laundry()
{

Show_details_about_laundry();
int x =Reserve_or_cancel();
if(x == reserve)
{
    confirmation_Laundry(&Prices_laundry);
}
else
{
    printf("Cancel\n");
}

}

void Spa()
{

   Show_services_and_price();
int x =Reserve_or_cancel();
if(x == reserve)
{
    confirmation_spa();
}
else
{
    printf("Cancel\n");
}

}


void Services_select(user_data* head)
{
printf("\t*******************\t\n");
printf("1-Spa\n2-Laundry\n3-Restaurant\n4-Gym\n");
printf("Enter:");
scanf("%d",&Select_Servies);
switch(Select_Servies)
{
    case spa:
        Spa();
        break;
    case laundry:
        Laundry();
        break;
    case rest:
        restaurant(head);
        break;
    case gymm:
        gym();
        break;
    default:
        printf("Wrong Entry \n");
        break;
}

}
