#include"header.h"

int count_node(SLL *ptr)
{
        int c=0;
        while(ptr)
        {
                c++;
                ptr=ptr->next;
        }
        return c;
}