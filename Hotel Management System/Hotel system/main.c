
#include "RoomData.h"




int main()
{
    /* Create Linked list */
    lst* ptrL = (lst*)malloc(sizeof(lst));
    ptrL->top= NULL;
    userList* ptrU = (userList*)malloc(sizeof(userList));
    ptrU->top= NULL;
    /* Generate the List */
    generateList(S_size,D_size,T_size,F_size, ptrL);
    /* Print the List */
    printRoomList(ptrU);
    /* Start program */
    start(ptrU);
    //FILE* fptr=fopen("userdata","a");
    //fprintf(fptr, "userdata");
    return 0;
}
