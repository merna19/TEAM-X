
#include "RoomData.h"




int main()
{
    int x;
    lst* ptrL = (lst*)malloc(sizeof(lst));
    ptrL->top= NULL;
    generateList(S_size,D_size,T_size,F_size, ptrL);

    printRoomList();

    printf("--------------------\n");
    x= checkAvailability(type_single,view_garden);
    printf("check avilability:%d\n",x);

    start();

    return 0;
}
