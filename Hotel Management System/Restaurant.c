#include "Restaurant.h"
#include "string.h"

/**********************************************************/
enum vacancy checkVacancy(int num_guests)
{
    //multiple returns METRA Violation
    static signed char VacantChairs=CHAIRS;
    if(VacantChairs-num_guests<0)
    {
        //number of guests are more than vacant chairs
        return notVacant;
    }
    else
    {
        VacantChairs-=num_guests;
        return Vacant;
    }

}
/**********************************************************/
char menu[][11]={"Breakfast","Main Dish","Dinner","Supper","Dessert"};
int prices[]={0,300,200,100,50};

void showMenu(void)
{

    for(char meal=0;meal<(sizeof(menu)/sizeof(menu[0]));meal++)
    {
        printf("%d.%s.\t%dLE\n",meal+1,menu[meal],prices[meal]);
    }
}
/**********************************************************/
enum status checkStatus(struct user_data* node)
{
    if(node->fullBoard==0)
    {
        //printf("half board\n");
        return halfboard;
    }
    else
    {
        //printf("full board\n");
        return fullboard;
    }

};
/**********************************************************/
void addToBill(struct user_data* node,int fee)
{
    node->Bill+=fee;
}
/************************************************************/
void restaurant(struct user_data* node)
{   int guests=0;
    int meals[CHAIRS]={0};
    printf("WELCOME SIR, YOU WANT A TABLE FOR HOW MANY GUESTS?\n");
    scanf("%d",&guests);
    if(checkVacancy(guests))
    {
        printf("HERE'S OUR MENU\n");
        showMenu();
        printf("PLEASE CHOOSE YOUR MEALS\n");
        int fee=0;
        for(int i=0;i<guests;i++)
        {
            scanf(" %d",meals+i);
            printf("entered\n");
            if((meals[i]>0)&&(meals[i]<6))
            {
                if(!checkStatus(node))
                {   //if it's half board
                    //if(i!=0)
                    {
                        fee+=prices[meals[i]-1];

                    }
                }
            }
            else
            {
                printf("PLEASE CHOOSE YOUR MEAL FROM THE MENU\n");
                i--;
            }

        }
        printf("YOUR MEAL WILL COST YOU %dLE\nWOULD YOU LIKE TO CONFIRM?\n1.YES\t2.NO\n",fee);
        int check;
        scanf("%d",&check);
        if(check==1)
        {
            addToBill(node,fee);
            printf("%dLE HAS BEEN ADDED TO YOUR ROOM BILL\nYOUR CURRENT BILL HAS REACHED %d\n",fee,node->Bill);
        }
        else
        {
            printf("OKAY SIR, HAVE A NICE DAY\n");
        }
    }
    else
    {
        printf("SORRY, SIR BUT THERE'S NO VACANCY\n");

    }
}

