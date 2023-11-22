
#include"Spa.h"
/* Function show services and price is used to show the time and price for each service */
void Show_services_and_price()
{  /* Variable size is used to get from the user the number of services will be showed */
    int size=0;
     /* Variable j is used to  give the number of iterations when the user enter the number of services */
    int j=0;
    /* Display to the user to select services */
    printf("Select Services:\n");
    /* These are services that the user should select on or more of them*/
    printf("1-massages\n2-facials\n3-nail_services\n4-haircuts_and_styling\n5-steam_rooms\n6-saunas\n7-aesthetician_services\n");
    do{
        /* Display to the user enter a number of services you need to see it */
        printf("Enter a number of services you need to see it:");
        /* Get a number of services will be showed  from user */
        scanf("%d",&size);
        /* increment j to reduce the number of iterations */
        j++;
       /* check if the number of services that is gotten from user is less than max number of services and grater than zero */
       if( (size<=7) && (size>0))
       {
  /*      /* For loop is used to loop on the number of services*/
         for(char i=0;i<size;i++)
         {
         /* Display to the user "Enter service" to enter sevices*/
           printf("Enter service %d:",i+1);
           /* Get the number of services that will be showed */
           scanf("%u",&Services_spa[i]);
          }
          /* For loop is used to loop on the number of services*/
        for(char i=0;i<size;i++)
       {
        /* Switch case is used to check if Service is  there and will show its data */
        switch(Services_spa[i])
        {
            /* If Service is massages will show data of massages */
           case massages:
            /* Display to the user the time of massages */
           printf("the time available for massages service is from 7:00 am to 10:00 pm\n");
           /*  Display to the user the price of the massages*/
           printf("the price of massages for one person for 60 min:300$\n\n");
          break;
          /* If Service is facials will show data of facials */
         case facials:
         /* Display to the user the time of facials */
         printf("the time available for facials service is from 7:00 am to 10:00 pm\n");
         /*  Display to the user the price of the facials*/
         printf("the price of facials for one person for 60 min:250$\n\n");
         break;
         /* If Service is nail services will show data of nail services */
          case nail_services:
            /* Display to the user the time of nail services */
         printf("the time available for nail services service is from 9:00 am to 10:00 pm\n");
         /*  Display to the user the price of the nail services*/
         printf("the price of nail services for one person:100$\n\n");
         break;
         /* If Service is haircuts and styling will show data of haircuts and styling*/
       case haircuts_and_styling:
           /* Display to the user the time of haircuts and styling */
        printf("the time available for haircuts and styling service is from 9:00 am to 10:00 pm\n");
        /*  Display to the user the price of the haircuts and styling*/
        printf("the price of haircuts and styling for one person:150$\n\n");
        break;
        /* If Service is steam rooms will show data of steam rooms */
      case steam_rooms:
        /* Display to the user the time of steam rooms */
        printf("the time available for steam rooms service is from 7:00 am to 9:00 pm\n");
        /*  Display to the user the price of the steam rooms*/
        printf("the price of steam rooms for one person for 60 min:250$\n\n");
        break;
        /* If Service is saunas will show data of saunas */
      case saunas:
          /* Display to the user the time of saunas */
        printf("the time available for saunas service is from 7:00 am to 9:00 pm\n");
        /*  Display to the user the price of the saunas*/
        printf("the price of saunas for one person for 60 min:250$\n\n");
        break;
        /* If Service is aesthetician services will show data of aesthetician services */
      case aesthetician_services:
        /* Display to the user the time of aesthetician services */
        printf("the time available for aesthetician services service is from 9:00 am to 10:00 pm\n");
        /*  Display to the user the price of the aesthetician services*/
        printf("the price of aesthetician services for one person:200$\n\n");
        break;
      default:
           printf("This number of service is wrong so we will not display it\n");
        break;
    }
    }
    }
    /* If user enter number of service is greater than 7 or equal 0 */
    else
    {
        printf("The number of services must be from 1 to 7\n");

    }
    /* Check if  a number of services > 7 or equal 0 and number of iterations not equal 3 */
    }while(( (size>7) || (size ==0)) && (j !=3));
}



/* Function confirmation spa is used to confirm the reserve*/
void confirmation_spa(){
    /* this pointer is used to get the price of room */
    node* ptr = (node*)malloc(sizeof(node));
   /* Check if user is half board */
    if(Check()==half_board)
    {
        /* Variable size is used to get from the user the number of services will be showed */
          int size=0;
        /* Variable j is used to  give the number of iterations when the user enter the number of services */
          int j=0;
           /* Local variables are used to calculate the price */
              int m_price=0 ,f_price=0,n_price=0,h_price=0,sr_price=0,sa_price=0,ae_price=0;
              /* Display to the user "The Services are:" to enter number of services he want */
              printf("\t*******************\t\n");
              printf("\nThe Services are:\n");
              /*  These are services that the user should select on or more of them*/
              printf("1-massages\n2-facials\n3-nail_services\n4-haircuts_and_styling\n5-steam_rooms\n6-saunas\n7-aesthetician_services\n");
              do{
             /* Display to the user enter a number of services you need to reserve it */
             printf("\t*******************\t\n");
              printf("Enter number of services:");
              /* Get a number of services will be reserved from user */
              scanf("%d",&size);
              /* increment j to reduce the number of iterations */
              j++;
              /* Check if the number of services that is gotten from user is less than max number of services and grater than zero */
            if( (size<=7) && (size>0))
            {
                /* For loop is used to loop on the number of services*/
             for(char i=0;i<size;i++)
             {
            /* Display to the user "Enter service" to enter services*/
            printf("\t*******************\t\n");
             printf("Enter service %d:",i+1);
              /* Get the number of services that will be reserved */
             scanf("%u",&Services_spa[i]);
             /* Check if user enter Services in the list to ask from user to enter the no guest*/
                if(Services_spa[i]==massages || Services_spa[i]==nail_services || Services_spa[i]==facials|| Services_spa[i]== haircuts_and_styling ||  Services_spa[i]==saunas || Services_spa[i]==steam_rooms || Services_spa[i]==aesthetician_services  )
                  {
             /* Display to the user "Enter number of guest" */
             do{
                    printf("\t*******************\t\n");
                  printf("Enter numbers of guests [should be the range of the guest from 0 to 10]:");
             /* Get from the user the number of guests */
                scanf("%u",&no_guest);

             }while(no_guest>10);
                  /* Print Enter available time */
                  printf("\t*******************\t\n");
                 printf("enter available  time:");
             /* get time from user */
                scanf("%s",time_of_spa);
             }}
      /* For loop is used to loop on the number of services*/
            for(int i=0;i<size;i++)
          {
        /* Switch case is used to check if Service is  there and will be reserved */
              switch(Services_spa[i])
             {
                 /* If Service is massages will calculate the price */
                case massages:
                m_price=M_price1*no_guest;
                break;
                 /* If Service is facials will calculate the price */
               case facials:
                f_price=F_price2*no_guest;
               break;
                /* If Service is nail prices will calculate the price */
               case nail_services:
                 n_price=N_price3*no_guest;
               break;
                /* If Service is hair and styling will calculate the price */
               case haircuts_and_styling:
                h_price=H_price4*no_guest;
               break;
                /* If Service is steam room will calculate the price */
              case steam_rooms:
               sr_price=SR_price5 *no_guest;
               break;
                /* If Service is saunas will calculate the price */
              case saunas:
               sa_price= Sa_price6 *no_guest;
               break;
                /* If Service is aesthetician will calculate the price */
              case aesthetician_services:
              ae_price=AE_price7*no_guest;
              break;
              default:
                  printf("\t*******************\t\n");
                   printf("This number of service is wrong so we will not calculate it\n");
              break;
             }
          } /* Variable total is used to calculate the total price of spa */
           int  total_price_spa= m_price + f_price + n_price + h_price + sr_price+ ae_price +sa_price;
           /* Print the price of  spa */
           printf("\t*******************\t\n");
           printf("the total price of spa =%u\n",total_price_spa);
           /* Calculate the total price */
         ptr->room.priceFinal +=total_price_spa;
         printf("\t*******************\t\n");
         printf("the total price=%d\n",ptr->room.priceFinal);

        }
        /*  If user enter number of service is greater than 7 or equal 0 */
        else
        {
          printf("\t*******************\t\n");
          printf("The number of services must be from 1 to 7\n");
        }
        }while(( (size>7) || (size ==0)) && (j !=3));
    } /* if user full board */

        /* Check if user full board */
        else
        { if(Check()==full_board)
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

