#include "GYM.h"
void displayClasses(void)
{
    char classes[][16]={"ZUMBA","YOGA","FITTING","FREE WORKOUT","ORIENTAL DANCING","BOXING"};
    for(int i=0;i<(sizeof(classes)/sizeof(classes[0]));i++)
    {
        printf("%d.%s.\n",i+1,classes[i]);
    }
}
void displaySchedule(void)
{
    printf("\nGYM SCHEDULE:\n");
    printf("*YOGA CLASSES EVERYDAY FROM 7:00am TO 8:00am\n");
    printf("*ZUMBA CLASSES EVERYDAY FROM 9:00am TO 11:00am\n");
    printf("*FITTING CLASSES EVERYDAY FROM 1:00pm TO 5:00pm\n");
    printf("*FREE WORKOUT CLASSES from MONDAY TO THURSDAY FROM 10:00am to 5:00pm\n");
    printf("*ORIENTAL DANCING CLASSES ON SUNDAY FROM 10:00am to 5:00pm\n");
    printf("*BOXING CLASSES ON EVERYDAY FROM 4:00pm to 5:00pm\n");
}

void gym(void)
{
    printf("HELLO SIR, ALLOW ME TO DIPLAY OUR AVAILABLE CLASSES\n");
    displayClasses();
    printf("IF YOU'RE INTERESTED IN OUR CLASSES LET ME KNOW THAT I CAN GIVE YOU OUR SCHEDULE\n");
    displaySchedule();
    printf("our fee is 40LE per hour\n WOULD YOU LIKE TO BOOK NOW\n1.YES\t2.NO\n");
    char check;
    scanf("%d",&check);
    if(check)
    {
        int hours;
        printf("for how many hours?\n");
        scanf("%d",&hours);
        printf("your reservation has been booked \nit costs %dLE\nthe expenses has been added to your room bill",hours*40);
    }

}
