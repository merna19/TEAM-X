
#include "RoomData.h"


int getID(struct roomData * room) // Get a variable from struct
{
    return room->roomID;
}
void setID(struct roomData * room, int id)
{
    room->roomID = id;
}
char getRoomType(struct roomData * room) // Get a variable from struct
{
    return room->roomType;
}
void setRoomType(struct roomData* room, room_type roomtype)
{
    room->roomType = roomtype;
}
char getRoomView(struct roomData * room) // Get a variable from struct
{
    return room->roomView;
}
void setRoomView(struct roomData * room, room_view view)
{
    room->roomView = view;
}
int getPriceHalf(struct roomData * room) // Get a variable from struct
{
    return room->priceHalf;
}
void setPriceHalf(struct roomData * room, int pricehalf)
{
    room->priceHalf = pricehalf;
}
int getPriceFinal(struct roomData * room) // Get a variable from struct
{
    return room->priceFinal;
}
void setPriceFinal(struct roomData * room, int pricefinal)
{
    room->priceFinal = pricefinal;
}
void setAvail(struct roomData * room, avail availablility)
{
    room->availability=availablility;
}
char getAvail(struct roomData * room)
{
    return room->availability;
}

char getMealType(struct roomData * room) // Get a variable from struct
{
    return room->mealType;
}
void setMealType(struct roomData * room, meal_type typeMeal)
{
    room->mealType = typeMeal;
}
int getDays(struct roomData * room) // Get a variable from struct
{
    return room->no_days;
}
void setDays(struct roomData * room, int daysNo)
{
    room->no_days = daysNo;
}

void generateList(int s_size, int d_size, int t_size, int f_size, lst* ptrL)
{
    int i;

    /**************** Single ********************/

    int x = 1120;
    node* ptr = (node*)malloc(sizeof(node));
    setRoomType(&(ptr->room), type_single);
    setID(&(ptr->room), x++);
    setAvail(&(ptr->room), available);
    setRoomView(&(ptr->room), view_garden);
    setPriceHalf(&(ptr->room), Single_Half);
    //setPriceFull(&(ptr->room), Single_Full);
    setPriceFinal(&(ptr->room), 0);
    setDays(&(ptr->room), 0);
    ptr->next = ptrL->top;
    ptrL->top = ptr;
    for(i=1 ; i<s_size ; i++)
    {
        node* ptr2 = (node*)malloc(sizeof(node));
        setRoomType(&(ptr2->room), type_single);
        setID(&(ptr2->room), x++);
        setAvail(&(ptr2->room), available);
        setPriceHalf(&(ptr2->room), Single_Half);
        //setPriceFull(&(ptr2->room), Single_Full);
        setPriceFinal(&(ptr2->room), 0);
        setDays(&(ptr2->room), 0);
        if(i%2==0)
        {
            setRoomView(&(ptr2->room), view_garden);
        }
        else if(i%3 ==0)
        {
            setRoomView(&(ptr2->room), view_pool);
            ptr2->room.priceHalf += Pool_Price;
            //ptr2->room.priceFull += Pool_Price;
        }
        else
        {
            setRoomView(&(ptr2->room), view_beach);
            ptr2->room.priceHalf += Beach_Price;
            //ptr2->room.priceFull += Beach_Price;
        }
        ptr2->next = ptrL->top;
        ptrL->top = ptr2;
    }
    S_head = ptrL->top;

    /**************** Double ********************/

    x = 2220;
    for(i=0 ; i<d_size ; i++)
    {
        node* ptr2 = (node*)malloc(sizeof(node));
        setRoomType(&(ptr2->room), type_double);
        setID(&(ptr2->room), x++);
        setAvail(&(ptr2->room), available);
        setPriceHalf(&(ptr2->room), Double_Half);
        //setPriceFull(&(ptr2->room), Double_Full);
        setPriceFinal(&(ptr2->room), 0);
        setDays(&(ptr2->room), 0);
        if(i%2==0)
        {
            setRoomView(&(ptr2->room), view_garden);
        }
        else if(i%3 ==0)
        {
            setRoomView(&(ptr2->room), view_pool);
            ptr2->room.priceHalf += Pool_Price;
            //ptr2->room.priceFull += Pool_Price;
        }
        else
        {
            setRoomView(&(ptr2->room), view_beach);
            ptr2->room.priceHalf += Beach_Price;
            //ptr2->room.priceFull += Beach_Price;
        }
        ptr2->next = ptrL->top;
        ptrL->top = ptr2;
    }
    D_head = ptrL->top;

    /**************** Trible ********************/

    x = 3320;
    for(i=0 ; i<t_size ; i++)
    {
        node* ptr2 = (node*)malloc(sizeof(node));
        setRoomType(&(ptr2->room), type_trible);
        setID(&(ptr2->room), x++);
        setAvail(&(ptr2->room), available);
        setPriceHalf(&(ptr2->room), Trible_Half);
        //setPriceFull(&(ptr2->room), Trible_Full);
        setPriceFinal(&(ptr2->room), 0);
        setDays(&(ptr2->room), 0);
        if(i%2==0)
        {
            setRoomView(&(ptr2->room), view_garden);
        }
        else if(i%3 ==0)
        {
            setRoomView(&(ptr2->room), view_pool);
            ptr2->room.priceHalf += Pool_Price;
            //ptr2->room.priceFull += Pool_Price;
        }
        else
        {
            setRoomView(&(ptr2->room), view_beach);
            ptr2->room.priceHalf += Beach_Price;
            //ptr2->room.priceFull += Beach_Price;
        }
        ptr2->next = ptrL->top;
        ptrL->top = ptr2;
    }
    T_head = ptrL->top;

    /**************** Family ********************/
    x = 4420;
    for(i=0 ; i<f_size ; i++)
    {
        node* ptr2 = (node*)malloc(sizeof(node));
        setRoomType(&(ptr2->room), type_family);
        setID(&(ptr2->room), x++);
        setAvail(&(ptr2->room), available);
        setPriceHalf(&(ptr2->room), Family_Half);
        //setPriceFull(&(ptr2->room), Family_Full);
        setPriceFinal(&(ptr2->room), 0);
        setDays(&(ptr2->room), 0);
        if(i%2==0)
        {
            setRoomView(&(ptr2->room), view_garden);
        }
        else if(i%3 ==0)
        {
            setRoomView(&(ptr2->room), view_pool);
            ptr2->room.priceHalf += Pool_Price;
            //ptr2->room.priceFull += Pool_Price;
        }
        else
        {
            setRoomView(&(ptr2->room), view_beach);
            ptr2->room.priceHalf += Beach_Price;
            //ptr2->room.priceFull += Beach_Price;
        }
        ptr2->next = ptrL->top;
        ptrL->top = ptr2;
    }
    F_head = ptrL->top;
}

int checkAvailability(room_type type,room_view view)
{
    /*this functions return the ID room if there is one available else it returns zero*/
    int Find_Flag=0;
    char c;
    if(type == type_single)
    {
        node* ptr = S_head;
        for(int i=0;i<S_size;i++)
        {
            c= getRoomView(&(ptr->room));
            if(c == view)
            {
                Find_Flag= getAvail(&(ptr->room));
                Find_Flag = getID(&(ptr->room));

                break;
            }
            ptr= ptr->next;
        }
    }
    else if(type == type_double)
    {
        node* ptr =D_head;
        for(int i=0;i<D_size;i++)
        {
            c= getRoomView(&(ptr->room));
            if(c == view)
            {
                Find_Flag= getAvail(&(ptr->room));
                Find_Flag = getID(&(ptr->room));
                break;
            }
            ptr= ptr->next;
        }
    }
    else if(type == type_trible)
    {
        node* ptr =T_head;
        for(int i=0;i<T_size;i++)
        {
            c= getRoomView(&(ptr->room));
            if(c == view)
            {
                Find_Flag= getAvail(&(ptr->room));
                Find_Flag = getID(&(ptr->room));
                break;
            }
            ptr= ptr->next;
        }
    }
    else if(type == type_family)
    {
        node* ptr =F_head;
        for(int i=0;i<F_size;i++)
        {
            c= getRoomView(&(ptr->room));

            if(c == view)
            {
                Find_Flag= getAvail(&(ptr->room));
                Find_Flag = getID(&(ptr->room));
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

void printRoomList()
{
    int i;
    node* ptr2 = S_head;


    printf("----------Single----------\n");
    printf("ID\tT\tV\tA\tPHalf\tD\tpFinal\n");
    for(i=0; i< S_size; i++)
    {

        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", ptr2->room.roomID, ptr2->room.roomType, ptr2->room.roomView, ptr2->room.availability, ptr2->room.priceHalf, ptr2->room.no_days, ptr2->room.priceFinal);
        ptr2=ptr2->next;
    }

    printf("----------Double----------\n");
    printf("ID\tT\tV\tA\tPHalf\tD\tpFinal\n");
    ptr2 = D_head;
    for(i=0; i< D_size; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", ptr2->room.roomID, ptr2->room.roomType, ptr2->room.roomView, ptr2->room.availability, ptr2->room.priceHalf, ptr2->room.no_days, ptr2->room.priceFinal);
        ptr2=ptr2->next;
    }

    ptr2 = T_head;
    printf("----------Trible----------\n");
    printf("ID\tT\tV\tA\tPHalf\tD\tpFinal\n");
    for(i=0; i< T_size; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", ptr2->room.roomID, ptr2->room.roomType, ptr2->room.roomView, ptr2->room.availability, ptr2->room.priceHalf, ptr2->room.no_days, ptr2->room.priceFinal);
        ptr2=ptr2->next;
    }

    ptr2 = F_head;
    printf("----------Family----------\n");
    printf("ID\tT\tV\tA\tPHalf\tD\tpFinal\n");
    for(i=0; i< F_size; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", ptr2->room.roomID, ptr2->room.roomType, ptr2->room.roomView, ptr2->room.availability, ptr2->room.priceHalf, ptr2->room.no_days, ptr2->room.priceFinal);
        ptr2=ptr2->next;
    }
}

void reservation()
{
    int x, y, z, days;

    printf("Choose room type:\n1- Single\n2- Double\n3- Trible\n4- Family\n");
    scanf("%d", &x);
    printf("Choose room view:\n1- Garden view\n2- Pool view\n3- Beach view\n");
    scanf("%d", &y);

    if(checkAvailability(x,y)==0)
    {
        printf("Sorry there is no room available with the type and view you chose, try again\n");
    }
    else
    {
        printf("Enter number of days\n");
        scanf("%d", &days);
        //setDays(room , days);

        printf("Choose meal type:\n1- Full board\n2- Half board\n");
        scanf("%d", &z);
        switch(z)
        {
            case 1:
                //setMealType(room, full);
                //setPriceFinal(room, room.priceFull * days);
                break;
            case 2:
                //setMealType(room, half);
                //setPriceFinal(room, room.priceHalf * days);
                break;
            default:
                printf("Wrong Entry\n");
                break;
        }
        //setAvail(room, not_available);

    }

}

void start()
{
    int x;
    while(1)
    {
        printf("********* Welcome to X Hotel *********\n1- Reservation\n2- Facilities\n");
        scanf("%d", &x);
        switch(x)
        {
            case 1:
                printf("********* Reservation *********\n");
                reservation();
                break;
            case 2:
                printf("********* Facilities *********\n");
                break;
            default:
                printf("Invalid input .. try again \n");
                break;
        }
    }

}

int getPriceFull(struct roomData * room)
{
    return room->priceFull;
}

void setPriceFull(struct roomData * room, int pricefull)
{
    room->priceFull=pricefull;
}
