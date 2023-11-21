#include"Laundry.h"
#include"service.h"
/* Function show services and prices is used to show details about this service */
void Show_details_about_laundry()
{  /* Variable size is used to get from the user the number of services will be showed */
    int size=0;
    /* Variable j is used to  give the number of iterations when the user enter the number of services */
    int j=0;
    /* Display to the user to select services */
    printf("\nSelect Services:\n");
     /* These are services that the user should select on or more of them*/
    printf("1-Washing clothes\n2-Ironing clothes\n3-Washing and ironing clothes\n");
    do{
         /* Display to the user enter a number of services you need to see it */
         printf("\t*******************\t\n");
        printf("Enter a number of services you need to see it:");
        /* Get a number of services will be showed  from user */
        scanf("%d",&size);
        /* increment j to reduce the number of iterations */
        j++;
         /* check if the number of services that is gotten from user is less than max number of services and grater than zero */
        if( (size<=3) && (size>0))
        {
        /* For loop is used to loop on the number of services*/
        for(char i=0;i<size;i++)
        {
         /* Display to the user "Enter service" to enter services*/
        printf("\t*******************\t\n");
        printf("Enter service %d:",i+1);
        /* Get the number of services that will be showed */
        scanf("%u",&Services_laundry[i]);
        }
         /* For loop is used to loop on the number of services*/
       for(char i=0;i<size;i++)
        {
        /* Switch case is used to check if Service is  there and will show its data */
       switch(Services_laundry[i])
        {
        /* If Service is Washing clothes will show data of Washing clothes */
        case Washing_clothes:
        printf("The clothes are washed in 10 minutes\n");
        printf("the price of one piece:20$\n\n");
         printf("\t*******************\t\n");
        break;
        /* If Service is Ironing clothes will show data of Ironing clothes */
        case Ironing_clothes:
        printf("The clothes are ironed in 10 minutes\n");
        printf("the price of one piece:20$\n\n");
         printf("\t*******************\t\n");
        break;
        /* If Service is Washing and ironing clothes will show data of Washing and ironing clothes */
       case Washing_ironing_clothes:
        printf("The clothes are washed and ironed in 25 minutes\n");
        printf("the price of one piece:35$\n\n");
         printf("\t*******************\t\n");
        break;
        default:
             printf("\t*******************\t\n");
            printf("This number of service is wrong so we will not display it\n");
        break;
    }
    }
    }
     /* If user enter number of service is greater than 3 or equal 0 */
    else
    {
         printf("\t*******************\t\n");
        printf("The number of services must be from 1 to 3\n");

    } /* Check if  a number of services > 3 or equal 0 and number of iterations not equal 3 */
    }while(( (size>3) || (size ==0)) && (j !=3));


}


/* Function confirmation laundry is used to confirm the reserve*/
void confirmation_Laundry(struct Services_prices_laundry* ptr){
    /* this pointer is used to get the price of room */
    node* ptr1 = (node*)malloc(sizeof(node));
     /* Check if user is half board */
    if(Check()==half_board)
    {
        /* Variable size is used to get from the user the number of services will be showed */
       int size=0;
       /* Variable j is used to  give the number of iterations when the user enter the number of services */
       int j=0;
       /* Display to the user "The Services are:" to enter number of services he want */
       printf("\t*******************\t\n");
        printf("\nThe Services are:\n");
         /*  These are services that the user should select on or more of them*/
       printf("1-Washing clothes\n2-Ironing clothes\n3-Washing and ironing clothes\n");
      do
       {
     /* Display to the user enter a number of services you need to reserve it */
     printf("\t*******************\t\n");
       printf("Enter number of services:");
        /* Get a number of services will be reserved from user */
       scanf("%d",&size);
       /* increment j to reduce the number of iterations */
       j++;
       /* Check if the number of services that is gotten from user is less than max number of services and grater than zero */
      if( (size<=3) && (size>0))
         {
        /* For loop is used to loop on the number of services*/
          for(char i=0;i<size;i++)
          {
        /* Display to the user "Enter service" to enter services*/
        printf("\t*******************\t\n");
           printf("Enter service %d:",i+1);
            /* Get the number of services that will be reserved */
           scanf("%u",&Services_laundry[i]);
           /* Display Enter the number of the pieces*/
           printf("\t*******************\t\n");
           printf("Enter the number of pieces:");
           /* Get the number of the pieces from the user*/
           scanf("%u",&no_of_pieces);
        }
         /* For loop is used to loop on the number of services*/
      for(char i=0;i<size;i++)
      {
        /* Switch case is used to check if Service is  there and will be reserved */
          switch(Services_laundry[i])
         {
              /* If Service is washing clothes will calculate the price */
            case Washing_clothes:
             ptr->Washing_clothes=20*no_of_pieces;
            break;
             /* If Service is ironing cllothes will calculate the price */
            case Ironing_clothes:
            ptr->Ironing_clothes=20*no_of_pieces;
            break;
             /* If Service is washing and ironing will calculate the price */
            case Washing_ironing_clothes:
            ptr->Washing_ironing_clothes=35*no_of_pieces;
           break;
          default:
              printf("\t*******************\t\n");
               printf("This number of service is wrong so we will not calculate it\n");
          break;
    }

    }
    /* Variable total price  is used to calculate the total price pf launary*/
   total_price_laundry = ptr->Washing_clothes + ptr->Ironing_clothes + ptr->Washing_ironing_clothes;
  printf("the total price of laundry=%d\n",total_price_laundry);
   /* Calculate the total price */
  ptr1->room.priceFinal +=total_price_laundry;
 printf("the total price=%d\n",ptr1->room.priceFinal);
}
 /*  If user enter number of service is greater than 3 or equal 0 */
else
      {
          printf("\t*******************\t\n");
          printf("The number of services must from 1 to 3\n");
      }
    }while(( (size>3) || (size ==0)) && (j !=3));
      }
      /* if user full board */
    else
    {
        /* Check if user full board */
        if(Check()==full_board)
            {
                printf("\t*******************\t\n");
            printf("you are full board and You paid for this service when you booked the room\n");
          }
        else
        {
            printf("\t*******************\t\n");
            printf("cancel");
        }


}
}
