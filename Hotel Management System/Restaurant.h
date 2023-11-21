#ifndef RESTAURANT_H_INCLUDED
#define RESTAURANT_H_INCLUDED
#include "heads.h"

#define CHAIRS 100

/**********************************************/
enum vacancy{notVacant=0,Vacant};
enum status{halfboard=0,fullboard};

enum vacancy checkVacancy(int num_guests);
void showMenu(void);
enum status checkStatus(struct user_data* node);
void addToBill(struct user_data* node,int fee);
void restaurant(struct user_data* node);

#endif // RESTAURANT_H_INCLUDED
