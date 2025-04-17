#include"header.h"

void sort_the_list(SLL *ptr)
{
        if(ptr==0)
        {
                printf("\033[0;31;1mNo records found\033[0m\n");
                return;
        }
        char op;
        printf("\033[0;35;1mChoose the Sorting Option\nN/n : sort with name\nP/p : sort wit percentage\033[0m\n");
        scanf(" %c",&op);
        if(op>='A'&&op<='Z')
                op=op+32;
        if(op!='n'&&op!='p')
        printf("\033[0;31;1mYou have entered wrong option\033[0m\n");

        if(op=='n')
        {
                SLL *p1=ptr,*p2,temp;
                int i,j,c=count_node(ptr);
                for(i=0;i<c-1;i++)
                {
                        p2=p1->next;
                        for(j=0;j<c-1-i;j++)
                        {
                                if(strcmp(p1->name,p2->name)>0)
                                {
                                        temp.rollno=p1->rollno;
                                        strcpy(temp.name,p1->name);
                                        temp.percentage=p1->percentage;
                                        p1->rollno=p2->rollno;
                                        strcpy(p1->name,p2->name);
                                        p1->percentage=p2->percentage;
                                        p2->rollno=temp.rollno;
                                        strcpy(p2->name,temp.name);
                                        p2->percentage=temp.percentage;
                                }
                                p2=p2->next;
                        }
                        p1=p1->next;
                }
                printf("\033[0;32;1mList Sorted Successfully\033[0m\n");
        }

        if(op=='p')
        {
                SLL *p1=ptr,*p2,temp;
                int i,j,c=count_node(ptr);
                for(i=0;i<c-1;i++)
                {
                        p2=p1->next;
                        for(j=0;j<c-1-i;j++)
                        {
                                if(p1->percentage>p2->percentage)
                                {
                                        temp.rollno=p1->rollno;
                                        strcpy(temp.name,p1->name);
                                        temp.percentage=p1->percentage;
                                        p1->rollno=p2->rollno;
                                        strcpy(p1->name,p2->name);
                                        p1->percentage=p2->percentage;
                                        p2->rollno=temp.rollno;
                                        strcpy(p2->name,temp.name);
                                        p2->percentage=temp.percentage;
                                }
                                p2=p2->next;
                        }
                        p1=p1->next;
                }
                printf("\033[0;32;1mList Sorted Successfully\033[0m\n");
        }
}
