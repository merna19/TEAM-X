
#include "RoomData.h"

/* A function used to get Room ID from struct */
int getID(struct roomData * room)
{
    /* Return room id from struct */
    return room->roomID;
}
/* A function used to set Room ID in struct */
void setID(struct roomData * room, int id)
{
    /* Set the room ID with the value given in function parameters */
    room->roomID = id;
}
/* A function used to get Room Type from struct */
char getRoomType(struct roomData * room)
{
    /* Return room type from struct */
    return room->roomType;
}
/* A function used to set Room type in struct */
void setRoomType(struct roomData* room, room_type roomtype)
{
    /* Set the room type with the value given in function parameters */
    room->roomType = roomtype;
}
/* A function used to get Room view from struct */
char getRoomView(struct roomData * room)
{
    /* Return room view from struct */
    return room->roomView;
}
/* A function used to set Room view in struct */
void setRoomView(struct roomData * room, room_view view)
{
    /* Set the room view with the value given in function parameters */
    room->roomView = view;
}
/* A function used to get Room price in half board from struct */
int getPriceHalf(struct roomData * room)
{
    /* Return room price in half board from struct */
    return room->priceHalf;
}
/* A function used to set Room price in half board in struct */
void setPriceHalf(struct roomData * room, int pricehalf)
{
    /* Set the room price half with the value given in function parameters */
    room->priceHalf = pricehalf;
}
/* A function used to get Room final price after calculating days from struct */
int getPriceFinal(struct roomData * room)
{
    /* Return room final price from struct */
    return room->priceFinal;
}
/* A function used to set Room final price in struct */
void setPriceFinal(struct roomData * room, int pricefinal)
{
    /* Set the room final price with the value given in function parameters */
    room->priceFinal = pricefinal;
}
/* A function used to set Room availability in struct */
void setAvail(struct roomData * room, avail availablility)
{
    room->availability=availablility;
}
/* A function used to get Room availability from struct */
char getAvail(struct roomData * room)
{
    /* Return room availability from struct */
    return room->availability;
}
/* A function used to get Room meal type (half/full board) from struct */
char getMealType(struct roomData * room)
{
    /* Return room meal type (half/full board) from struct */
    return room->mealType;
}
/* A function used to set Room meal type (half/full board) in struct */
void setMealType(struct roomData * room, meal_type typeMeal)
{
    /* Set the room meal type with the value given in function parameters */
    room->mealType = typeMeal;
}
/* A function used to get Room number of days from struct */
int getDays(struct roomData * room)
{
    /* Return room number of rented days from struct */
    return room->no_days;
}
/* A function used to set Room number of rented days in struct */
void setDays(struct roomData * room, int daysNo)
{
    /* Set the room number of days with the value given in function parameters */
    room->no_days = daysNo;
}
/* This function is used to generate rooms linked list along with setting room data variables with their values */
void generateList(int s_size, int d_size, int t_size, int f_size, lst* ptrL)
{
    /* Variable for loop iteration */
    int i;

    /**************** Single ********************/
    /* Initializing room ID --> 11-> single */
    int x = 1120;
    /* Creating a list node */
    node* ptr = (node*)malloc(sizeof(node));
    /* Setting room data in the list node */
    setRoomType(&(ptr->room), type_single);
    setID(&(ptr->room), x++);
    setAvail(&(ptr->room), available);
    setRoomView(&(ptr->room), view_garden);
    setPriceHalf(&(ptr->room), Single_Half);
    setPriceFull(&(ptr->room), Single_Full);
    setPriceFinal(&(ptr->room), 0);
    setDays(&(ptr->room), 0);
    /* Point to the next node in the list and make the top of the list point at the new node */
    ptr->next = ptrL->top;
    ptrL->top = ptr;
    /* Generating single rooms  */
    for(i=1 ; i<s_size ; i++)
    {
        /* Creating new node */
        node* ptr2 = (node*)malloc(sizeof(node));
        /* Setting room data in the node */
        setRoomType(&(ptr2->room), type_single);
        setID(&(ptr2->room), x++);
        setAvail(&(ptr2->room), available);
        setPriceHalf(&(ptr2->room), Single_Half);
        setPriceFull(&(ptr2->room), Single_Full);
        setPriceFinal(&(ptr2->room), 0);
        setDays(&(ptr2->room), 0);
        /* Generating different views */
        if(i%2==0)
        {
            /* for even numbers set the view to garden view */
            setRoomView(&(ptr2->room), view_garden);
        }
        else if(i%3 ==0)
        {
            /* For numbers that can be multiplied by 3 set the view to pool */
            setRoomView(&(ptr2->room), view_pool);
            /* Calculate new room half and full prices for the pool view */
            ptr2->room.priceHalf += Pool_Price;
            ptr2->room.priceFull += Pool_Price;
        }
        else
        {
            /* For the rest of the numbers set the view to beach */
            setRoomView(&(ptr2->room), view_beach);
            /* Calculate new room half and full prices for the beach view */
            ptr2->room.priceHalf += Beach_Price;
            ptr2->room.priceFull += Beach_Price;
        }
        /* Point to the next node in the list */
        ptr2->next = ptrL->top;
        ptrL->top = ptr2;
    }
    /* Set S_head to point to last room added in Single rooms */
    S_head = ptrL->top;

    /**************** Double ********************/
    /* 1st double room ID --> 22-> double */
    x = 2220;
    for(i=0 ; i<d_size ; i++)
    {
        /* Creating new node */
        node* ptr2 = (node*)malloc(sizeof(node));
        /* Setting room data in the node */
        setRoomType(&(ptr2->room), type_double);
        setID(&(ptr2->room), x++);
        setAvail(&(ptr2->room), available);
        setPriceHalf(&(ptr2->room), Double_Half);
        setPriceFull(&(ptr2->room), Double_Full);
        setPriceFinal(&(ptr2->room), 0);
        setDays(&(ptr2->room), 0);
        /* Generating different views */
        if(i%2==0)
        {
            /* for even numbers set the view to garden view */
            setRoomView(&(ptr2->room), view_garden);
        }
        else if(i%3 ==0)
        {
            /* For numbers that can be multiplied by 3 set the view to pool */
            setRoomView(&(ptr2->room), view_pool);
            /* Calculate new room half and full prices for the pool view */
            ptr2->room.priceHalf += Pool_Price;
            ptr2->room.priceFull += Pool_Price;
        }
        else
        {
            /* For the rest of the numbers set the view to beach */
            setRoomView(&(ptr2->room), view_beach);
            /* Calculate new room half and full prices for the beach view */
            ptr2->room.priceHalf += Beach_Price;
            ptr2->room.priceFull += Beach_Price;
        }
        /* Point to the next node in the list */
        ptr2->next = ptrL->top;
        ptrL->top = ptr2;
    }
    /* Set D_head to point to last room added in Double rooms */
    D_head = ptrL->top;

    /**************** Trible ********************/
    /* 1st trible room ID --> 33-> trible */
    x = 3320;
    for(i=0 ; i<t_size ; i++)
    {
        /* Creating new node */
        node* ptr2 = (node*)malloc(sizeof(node));
        /* Setting room data in the node */
        setRoomType(&(ptr2->room), type_trible);
        setID(&(ptr2->room), x++);
        setAvail(&(ptr2->room), available);
        setPriceHalf(&(ptr2->room), Trible_Half);
        setPriceFull(&(ptr2->room), Trible_Full);
        setPriceFinal(&(ptr2->room), 0);
        setDays(&(ptr2->room), 0);
        /* Generating different views */
        if(i%2==0)
        {
            /* for even numbers set the view to garden view */
            setRoomView(&(ptr2->room), view_garden);
        }
        else if(i%3 ==0)
        {
            /* For numbers that can be multiplied by 3 set the view to pool */
            setRoomView(&(ptr2->room), view_pool);
            /* Calculate new room half and full prices for the pool view */
            ptr2->room.priceHalf += Pool_Price;
            ptr2->room.priceFull += Pool_Price;
        }
        else
        {
            /* For the rest of the numbers set the view to beach */
            setRoomView(&(ptr2->room), view_beach);
            /* Calculate new room half and full prices for the beach view */
            ptr2->room.priceHalf += Beach_Price;
            ptr2->room.priceFull += Beach_Price;
        }
        /* Point to the next node in the list */
        ptr2->next = ptrL->top;
        ptrL->top = ptr2;
    }
    /* Set T_head to point to last room added in trible rooms */
    T_head = ptrL->top;

    /**************** Family ********************/
    /* 1st family room ID --> 44-> family */
    x = 4420;
    for(i=0 ; i<f_size ; i++)
    {
        /* Creating new node */
        node* ptr2 = (node*)malloc(sizeof(node));
        /* Setting room data in the node */
        setRoomType(&(ptr2->room), type_family);
        setID(&(ptr2->room), x++);
        setAvail(&(ptr2->room), available);
        setPriceHalf(&(ptr2->room), Family_Half);
        setPriceFull(&(ptr2->room), Family_Full);
        setPriceFinal(&(ptr2->room), 0);
        setDays(&(ptr2->room), 0);
        /* Generating different views */
        if(i%2==0)
        {
            /* for even numbers set the view to garden view */
            setRoomView(&(ptr2->room), view_garden);
        }
        else if(i%3 ==0)
        {
            /* For numbers that can be multiplied by 3 set the view to pool */
            setRoomView(&(ptr2->room), view_pool);
            /* Calculate new room half and full prices for the pool view */
            ptr2->room.priceHalf += Pool_Price;
            ptr2->room.priceFull += Pool_Price;
        }
        else
        {
            /* For the rest of the numbers set the view to beach */
            setRoomView(&(ptr2->room), view_beach);
            /* Calculate new room half and full prices for the beach view */
            ptr2->room.priceHalf += Beach_Price;
            ptr2->room.priceFull += Beach_Price;
        }
        /* Point to the next node in the list */
        ptr2->next = ptrL->top;
        ptrL->top = ptr2;
    }
    /* Set F_head to point to last room added in Family rooms */
    F_head = ptrL->top;
}
/*This functions return the ID room but if there is no available else it returns zero*/
int checkAvailability(room_type type,room_view view)
{
    int Find_Flag=0;
    char c;
	/*Check if the user request is a single room*/
    if(type == type_single)
    {
        node* ptr = S_head;
		/*loop to the singe room linked list to check if there is a room or not*/
        for(int i=0;i<S_size;i++)
        {
            c= getRoomView(&(ptr->room));
            if(c == view)
            {
                Find_Flag= getAvail(&(ptr->room));
				/*If there is already a room this function returns the ID in this case*/
                if(Find_Flag == 1)
                {
                 Find_Flag = getID(&(ptr->room));
                }


                break;
            }
            ptr= ptr->next;
        }
    }
	/*Check if the user request is a double room*/
    else if(type == type_double)
    {
        node* ptr =D_head;
		/*loop to the double room linked list to check if there is a room or not*/
        for(int i=0;i<D_size;i++)
        {
            c= getRoomView(&(ptr->room));
            if(c == view)
            {
                Find_Flag= getAvail(&(ptr->room));
                if(Find_Flag == 1)
                {
					/*If there is already a room this function returns the ID in this case*/
                 Find_Flag = getID(&(ptr->room));
                }
                break;
            }
            ptr= ptr->next;
        }
    }
	/*loop to the trible room linked list to check if there is a room or not*/
    else if(type == type_trible)
    {
        node* ptr =T_head;
		/*loop to the trible room linked list to check if there is a room or not*/
        for(int i=0;i<T_size;i++)
        {
            c= getRoomView(&(ptr->room));
            if(c == view)
            {
                Find_Flag= getAvail(&(ptr->room));
				/*If there is already a room this function returns the ID in this case*/
                if(Find_Flag == 1)
                {
                 Find_Flag = getID(&(ptr->room));
                }
                break;
            }
            ptr= ptr->next;
        }
    }
	/*Check if the user request is a family room*/
    else if(type == type_family)
    {
        node* ptr =F_head;
		/*loop to the family room linked list to check if there is a room or not*/
        for(int i=0;i<F_size;i++)
        {
            c= getRoomView(&(ptr->room));

            if(c == view)
            {
                Find_Flag= getAvail(&(ptr->room));
                if(Find_Flag == 1)
                {
					/*If there is already a room this function returns the ID in this case*/
                 Find_Flag = getID(&(ptr->room));
                }
                break;
            }
            ptr= ptr->next;
        }
    }
    else{}
    if(Find_Flag == 1)
    {

    }
     return Find_Flag;


}
/* This function is used to print all rooms list along with their data */
void printRoomList()
{
    /* Variable for room iteration */
    int i;
    /* Create pointer pointing on 1st single room */
    node* ptr2 = S_head;

    /* Printing all single rooms */
    printf("----------Single----------\n");
    printf("ID\tT\tV\tA\tPHalf\tPFull\tD\tpFinal\n");
    for(i=0; i< S_size; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", ptr2->room.roomID, ptr2->room.roomType, ptr2->room.roomView, ptr2->room.availability, ptr2->room.priceHalf, ptr2->room.priceFull, ptr2->room.no_days, ptr2->room.priceFinal);
        ptr2=ptr2->next;
    }
    /* Printing all double rooms */
    printf("----------Double----------\n");
    printf("ID\tT\tV\tA\tPHalf\tPFull\tD\tpFinal\n");
    /* Set Pointer on 1st double room */
    ptr2 = D_head;
    for(i=0; i< D_size; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", ptr2->room.roomID, ptr2->room.roomType, ptr2->room.roomView, ptr2->room.availability, ptr2->room.priceHalf, ptr2->room.priceFull, ptr2->room.no_days, ptr2->room.priceFinal);
        ptr2=ptr2->next;
    }
    /* Set Pointer on 1st trible room */
    ptr2 = T_head;
    /* Printing all trible rooms */
    printf("----------Trible----------\n");
    printf("ID\tT\tV\tA\tPHalf\tPFull\tD\tpFinal\n");
    for(i=0; i< T_size; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", ptr2->room.roomID, ptr2->room.roomType, ptr2->room.roomView, ptr2->room.availability, ptr2->room.priceHalf, ptr2->room.priceFull, ptr2->room.no_days, ptr2->room.priceFinal);
        ptr2=ptr2->next;
    }
    /* Set Pointer on 1st family room */
    ptr2 = F_head;
    /* Printing all family rooms */
    printf("----------Family----------\n");
    printf("ID\tT\tV\tA\tPHalf\tPFull\tD\tpFinal\n");
    for(i=0; i< F_size; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", ptr2->room.roomID, ptr2->room.roomType, ptr2->room.roomView, ptr2->room.availability, ptr2->room.priceHalf, ptr2->room.priceFull, ptr2->room.no_days, ptr2->room.priceFinal);
        ptr2=ptr2->next;
    }
}
/* This function is used to reserve a room depending on data from user */
user_data* reservation()
{
    struct user_data *head = malloc(sizeof(struct user_data));
    struct user_data *ptrnn = head;
    /* Define variables to save user's choice in */
    int x, y, z, days,a;
    /* Ask the user to choose the room type he wants */
    printf("Choose room type:\n1- Single\n2- Double\n3- Trible\n4- Family\n");
    /* Save the choice in x */
    scanf("%d", &x);
    /* Ask the user to choose the room view he wants */
    printf("Choose room view:\n1- Garden view\n2- Pool view\n3- Beach view\n");
    /* Save the choice in y */
    scanf("%d", &y);
    /* Check if there is a room available with the type and view the user chose */
    a = checkAvailability(x,y);
    /* If there isn't any room available --> function returned 0 */
    if(a==0)
    {
        /* Send mssg to user */
        printf("Sorry there is no room available with the type and view you chose, try again\n");
        /* Return to home page */
        return;
    }
    /* If there is a room available --> function returned the available room ID */
    else
    {
        /* Search for the available room ID to get a pointer to the room's struct */
        node*ptr = searchList( a);
        /* If the pointer got from the search has NULL value that means the ID doesn't exist */
        if(ptr == NULL)
        {
            /* Send mssg to the user */
            printf("Sorry there is no room available with the type and view you chose, try again\n");
            /* Return to home page */
            return;
        }
        /* We got the pointer value from the function */
        else
        {
            /* Ask user to enter the number of days he wants to rent the room for */
            printf("Enter number of days\n");
            /* Save the number in days */
            scanf("%d", &days);
            /* Set the days in the room struct with the value user sent */
            setDays(&(ptr->room) , days);
            /* Ask user to enter if he is renting half or full board room */
            printf("Choose meal type:\n1- Full board\n2- Half board\n");
            /* Save the choice in z */
            scanf("%d", &z);
            /* Switch on z */
            switch(z)
            {
                /* If full board */
                case 1:
                    /* Set meal type in room struct to full */
                    setMealType(&(ptr->room), full);
                    /* Calculate the room final price depending on meal type & number of days */
                    setPriceFinal(&(ptr->room), ptr->room.priceFull * days);
                    break;
                /* If half board */
                case 2:
                    /* Set meal type in room struct to half */
                    setMealType(&(ptr->room), half);
                    /* Calculate the room final price depending on meal type & number of days */
                    setPriceFinal(&(ptr->room), ptr->room.priceHalf * days);
                    break;
                /* Will get here for invalid input */
                default:
                    printf("Wrong Entry\n");
                    break;
            }
            /* Set room availability to not available */
            setAvail(&(ptr->room), not_available);
            printf("Please register with room ID --> %d and your bill --> %d\n",a, ptr->room.priceFinal);
            /* Call registeration function */
            ptrnn = registeration();
        }
    }
    return ptrnn;
}
/* This function is used to display the home page and switch between services */
void start(userList* userL)
{
    /* Define x to hold the choice the user chooses */
    int x;
    /* while(1) so the home page keeps popping up */
    while(1)
    {
        /* Display welcoming mssg along with choices for user to choose */
        printf("********* Welcome to X Hotel *********\n1- Reservation\n2- Facilities\n");
        /* Take user's choice and save it in x */
        scanf("%d", &x);
        /* Switch on user's choice */
        switch(x)
        {
            /* If user chose 1 */
            case 1:
                /* Print the choice */
                printf("********* Reservation *********\n");
                /* Call reservation function */
                struct user_data *head = malloc(sizeof(struct user_data));
                head = reservation();

                /* return to home page */
                break;
            /* If user chose 2 */
            case 2:
                /* Print the choice */
                printf("********* Facilities *********\n");
                Services_select(head);
                /* Return to home page */
                break;
            /* Default case */
            default:
                /* Getting in this case means that user chose an invalid choice */
                printf("Invalid input .. try again \n");
                /* Return to home page */
                break;
        }
    }

}
/* This function is used to search the list with room ID and returns a pointer to the node containing the room */
node* searchList(int sID)
{
    /* defining a variable i for loop count */
    int i=0;
    /* defining a pointer to node and pointing it to family head which points to the beginning of the linked list */
    node* p = F_head;
    /* for loop to search the list */
    for(i=0 ; i<S_size+D_size+T_size+F_size ; i++)
    {
        /* If the ID is found */
        if(p->room.roomID == sID)
        {
            /* Return the pointer --> the node containing the ID */
            return p;
        }
        /* If ID not found */
        else
        {
            /* Point to the next node in the list */
            p = p->next;
        }
    }
    /* If ID not found in the whole list then return NULL */
    return NULL;
}
/* A function used to get Room price in full board from struct */
int getPriceFull(struct roomData * room)
{
    /* Return room price in full board from struct */
    return room->priceFull;
}
/* A function used to set Room price in full board in struct */
void setPriceFull(struct roomData * room, int pricefull)
{
    /* Set the room price full with the value given in function parameters */
    room->priceFull=pricefull;
}
