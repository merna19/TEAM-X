#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"heads.h"

struct user_data* add_data(struct user_data* ptr, char *firstName,\
 char *lastName, int age, char gender, char *city, char *country,\
  int room, char board, char* startDate, char*endDate, int bill){
    struct user_data *tmp = malloc(sizeof(struct user_data));
	strcpy(tmp->firstName,firstName);
	strcpy(tmp->lastName,lastName);
    tmp->age = age;
    tmp->gender = gender;
	strcpy(tmp->city,city);
	strcpy(tmp->country,country);
    tmp->room = room;
    tmp->fullBoard = board;
	strcpy(tmp->startDate,startDate);
	strcpy(tmp->endDate,endDate);
    tmp->Bill = bill;
    tmp->link = NULL;

    ptr->link =tmp;
    return tmp;
}

void count_of_nodes(struct user_data *head){
int count = 0;
if(head == NULL)
printf("Linked List is empty\n");
struct user_data *ptr = NULL;
ptr = head;
while(ptr!= NULL){
    count++;
    ptr = ptr->link;
}
printf("%d\n", count);
}

void print_room(struct user_data *head){
	if(head == NULL)
		printf("Linked List is empty\n");
	struct user_data *ptr = NULL;
	ptr = head;
	while(ptr != NULL){
	printf("%d\n", ptr->room);
	ptr = ptr -> link;
		}
}
int get_room(struct user_data *head){
	if(head == NULL)
		printf("Linked List is empty\n");
	struct user_data *ptr = NULL;
	ptr = head;
	/*
	while(ptr != NULL){
	printf("%d\n", ptr->room);
	ptr = ptr -> link;
		}*/
	return ptr->room;
}
void print_gender(struct user_data *head){
	if(head == NULL)
		printf("Linked List is empty\n");
	struct user_data *ptr = NULL;
	ptr = head;
	while(ptr != NULL){
	printf("%c\n", ptr->gender);
	ptr = ptr -> link;
		}
}
char get_gender(struct user_data *head){
	if(head == NULL)
		printf("Linked List is empty\n");
	struct user_data *ptr = NULL;
	ptr = head;
	/*while(ptr != NULL){
	printf("%c\n", ptr->gender);
	ptr = ptr -> link;
		}*/
	return ptr->gender;
}
void print_board(struct user_data *head){
	if(head == NULL)
		printf("Linked List is empty\n");
	struct user_data *ptr = NULL;
	ptr = head;
	while(ptr != NULL){
	printf("%c\n", ptr->fullBoard);
	ptr = ptr -> link;
		}
}
char get_board(struct user_data *head){
	if(head == NULL)
		printf("Linked List is empty\n");
	struct user_data *ptr = NULL;
	ptr = head;
	/*while(ptr != NULL){
	printf("%c\n", ptr->fullBoard);
	ptr = ptr -> link;
		}*/
		return ptr->fullBoard;
}
void print_age(struct user_data *head){
	if(head == NULL)
		printf("Linked List is empty\n");
	struct user_data *ptr = NULL;
	ptr = head;
	while(ptr != NULL){
	printf("%d\n", ptr->age);
	ptr = ptr -> link;
		}
}
int get_age(struct user_data *head){
	if(head == NULL)
		printf("Linked List is empty\n");
	struct user_data *ptr = NULL;
	ptr = head;
	/*while(ptr != NULL){
	ptr = ptr -> link;
		}*/
	return ptr->age;
}
int get_bill(struct user_data *head){
	if(head == NULL)
		printf("Linked List is empty\n");
	struct user_data *ptr = NULL;
	ptr = head;
	/*while(ptr != NULL){
	ptr = ptr -> link;
		}*/
	return ptr->Bill;
}
void print_bill(struct user_data *head){
	if(head == NULL)
		printf("Linked List is empty\n");
	struct user_data *ptr = NULL;
	ptr = head;
	while(ptr != NULL){
	printf("%d\n", ptr->Bill);
	ptr = ptr -> link;
		}
}
void get_firstName(struct user_data *head, char *firName){
	int i =0;
	if(head == NULL)
		printf("Linked List is empty\n");
	struct user_data *ptr = NULL;
	ptr = head;
	char fName[10];
	char *f_name[10];
	strncpy(firName,ptr->firstName,20);
}
void get_lastName(struct user_data *head, char *lasName){
	int i =0;
	if(head == NULL)
		printf("Linked List is empty\n");
	struct user_data *ptr = NULL;
	ptr = head;
	char fName[10];
	char *f_name[10];
	strncpy(lasName,ptr->lastName,20);
}
void get_city(struct user_data *head, char *city){
	int i =0;
	if(head == NULL)
		printf("Linked List is empty\n");
	struct user_data *ptr = NULL;
	ptr = head;
	char fName[10];
	char *f_name[10];
	strncpy(city,ptr->city,20);
}
void get_country(struct user_data *head, char *country){
	int i =0;
	if(head == NULL)
		printf("Linked List is empty\n");
	struct user_data *ptr = NULL;
	ptr = head;
	char fName[10];
	char *f_name[10];
	strncpy(country,ptr->country,20);
}
void print_allData(struct user_data *head){
	if(head == NULL)
		printf("Linked List is empty\n");
	struct user_data *ptr = NULL;
	ptr = head;
	while(ptr != NULL){
	printf("First Name: %s\n", ptr->firstName);
	printf("Last Name: %s\n", ptr->lastName);
    printf("Age: %d\n", ptr->age);
    printf("Gender: %c\n", ptr->gender);
	printf("City: %s\n", ptr->city);
	printf("Country: %s\n", ptr->country);
    printf("F/H Board: %c\n", ptr->fullBoard);
	printf("Room ID: %d\n", ptr->room);
	printf("Start Date: %s\n", ptr->startDate);
	printf("End Date: %s\n", ptr->endDate);
    printf("Bill: %d\n", ptr->Bill);
	ptr = ptr -> link;
		}
}

user_data* registeration()
{
    int i =0;
    int age, room, bill;
    char gen, board;
    char firstName[20],lastName[20],city[20],country[20];
    //Dates are stored in string
    char startDate[5]= "23/5", endDate[5]= "28/5";
    int age1, room1, bill1;
    char gen1, board1;
    char firstName1[20], lastName1[20], city1[20], country1[20];
    //Initializing
    struct user_data *head = malloc(sizeof(struct user_data));
    struct user_data *ptr = head;
    //userNode* ptn = ptrU->top;
    printf("Please enter your first name\n");
    scanf("%s", &firstName);
    printf("Please enter your last name\n");
    scanf("%s", &lastName);
    printf("Please enter your age\n");
    scanf("%d", &age);
    printf("Please enter you gender\n");
    scanf(" %c", &gen);
    printf("Please enter your city\n");
    scanf(" %s", &city);
    printf("Please enter your country\n");
    scanf(" %s", &country);
    printf("Please enter room id\n");
    scanf("%d", &room);
    board = 'Y';
    printf("Please enter the bill\n");
    scanf("%d", &bill);
    printf("-------------\n");
    ptr = add_data(ptr, &firstName, &lastName, age, gen, &city, &country,\
    room, board,&startDate, &endDate, bill);
    /*ptn->userData = ptr;
    ptn->next = ptrU->top;
    ptrU->top = ptn;*/
    return ptr;
}
