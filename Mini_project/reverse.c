#include"header.h"

void reverse_the_records(SLL *ptr)
{
        if(ptr==0)
        {
                printf("\033[0;31;1mNo Records found\033[0m\n");
                return;
        }
        SLL *temp;
        int i,j,c=count_node(ptr);
        for(i=0;i<c;i++)
        {
                temp=ptr;
                for(j=1;j<c-i;j++)
                        temp=temp->next;
                printf("\033[0;34;1m%d %s %f\033[0m\n",temp->rollno,temp->name,temp->percentage);
        }
}