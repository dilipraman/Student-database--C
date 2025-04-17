#include"header.h"

void show_the_list(SLL *ptr)
{

        if(ptr==0)
        {
                printf("\033[0;31;1mNo Records Found...\033[0m\n");
                return;
        }
        printf("\033[0;37;1mThis is the List : \033[0m\n");
        while(ptr)
        {
                printf("\033[0;34;1m%d %s %f\033[0m\n",ptr->rollno,ptr->name,ptr->percentage);
                ptr=ptr->next;
        }
}
