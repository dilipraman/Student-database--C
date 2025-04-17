#include"header.h"

void add_new_record(SLL **ptr)
{
        SLL *new;

        static int rollno=1;

        new=malloc(sizeof(SLL));   //alloacte m/r in DMA

        new->next=0;               //update newly created m/r next addr as 0

        printf("\033[0;35;1mEnter Student Name and Percentage :\033[0m\n");
        scanf("%s%f",new->name,&new->percentage);       //take i/p from user

        SLL *r1,*r2;
        r1=*ptr;                 //r1 is holding starting node

        if(*ptr)
        {

                r2=r1->next;
                if(r1->rollno != 1)             //if rollno1 is not available(i.e.,deleted) it will take rollno as 1
                        new->rollno=1;          //for newly created student database
                else
                {
                        while(r2)
                         {
                                if((r1->rollno) != (r2->rollno)-1) //it will check whether any rollno is missing or not from rollno1 onwards if yes it will update  newly created student rollno as prev student rollno + 1.
                                {

                                        new->rollno=r1->rollno + 1;
                                        break;
                                }
                                r1=r1->next;
                                r2=r2->next;
                        }
                        if(r2==0)
                                new->rollno=r1->rollno + 1; //if rollno is not missing till the end of the list it will update newly created student rollno as prev student rollno + 1.
                }
        }


        if(*ptr==0)                     //it is going to be true when no student data is available before
        {
                new->rollno=rollno++;   //it will update 1st student rollno as 1 and it will update headptr
                *ptr=new;
        }


        else
         {
                SLL *p1,*p2;

                int i,j;

                int c=count_node(*ptr);
                p1=*ptr;             // p1 and p2 holding starting node
                p2=p1;
                for(i=0;i<c;i++)
                {
                        if((p1->rollno) > (new->rollno) )  //it will compare newly created student rollno with all other student rollno's and it will do sorting
                        {                                  //accordingly
                                new->next=p1;
                                if(*ptr==p1)
                                        *ptr=new;
                                else
                                        p2->next=new;
                                break;
                        }
                        p2=p1;
                        p1=p1->next;
                }
                if(i==c)       //it is going to true when p1 reaches end of the list so we have to udate prev node next address
                p2->next=new;
        }
        printf("\033[0;32;1mStudent Record Successfully Added\033[0m\n");
}