#pragma once

typedef struct user_data{
    char firstName[30];
    char lastName[20];
    int age;
    char gender;
    char city[20];
    char country[20];
    int room;
    char fullBoard;
    char startDate[5];
    char endDate[5];
    int Bill;
    struct user_data *link;
}user_data;

/* Linked list struct */
typedef struct userList
{
    struct userNode* top;
}userList;
/* List node struct */
typedef struct userNode
{
    struct user_data* userData;
    struct userNode* next;

}userNode;

struct user_data* add_data(struct user_data* ptr, char *firstName,\
 char *lastName, int age, char gender, char *city, char *country,\
  int room, char board, char* startDate, char*endDate, int bill);
void count_of_nodes(struct user_data *head);  //Number of available nodes
void print_room(struct user_data *head);     //print room ID
void print_gender(struct user_data *head);
void print_board(struct user_data *head);
void print_age(struct user_data *head);   //prints age
void print_bill(struct user_data *head);  //prints price
void print_allData(struct user_data *head);
int get_age(struct user_data *head);
int get_bill(struct user_data *head);
int get_room(struct user_data *head);  //room ID
char get_board(struct user_data *head);   //Full Board 'F' or Half board 'H'
char get_gender(struct user_data *head);  //Gender Female ='F' or Male = 'M'
/*The following four functions are for fetching string
so when you call the function you send
the variable you want to store in the string*/
void get_firstName(struct user_data *head, char *firstName); //Get First Name
void get_lastName(struct user_data *head, char *lasName); //Get Last Name
void get_city(struct user_data *head, char *city);        //Get City name
void get_country(struct user_data *head, char *country);   //Get country

user_data*  registeration();
