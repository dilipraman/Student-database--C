#include"header.h"

void delete_all_records(SLL **ptr)
{
        if(*ptr==0)
        {
                printf("\033[0;31;1mNo Records found\033[0m\n");
                return;
        }
        int c=1;
        SLL *del=*ptr;
        while(del)
        {
                *ptr=del->next;
                free(del);
                del=*ptr;
        }
        printf("\033[0;32;1mAll records are successfully deleted\033[0m\n");
}

void delete_a_record(SLL **ptr)
{
        if(*ptr==0)
        {
                printf("\033[0;31;1mNo Records found\033[0m\n");
                return;
        }
        char op;
        printf("\033[0;35;1mR/r : enter roll to delete\nN/n : enter name to delete\033[0m\n");
        scanf(" %c",&op);

        if(op=='R' || op=='N' )
                op=op+32;
        if(op!='r'&&op!='n')
        printf("\033[0;31;1mYou Have Entered Wrong Option\033[0m\n");

        if(op=='r')
        {
                int num;
                printf("\033[0;35;1mPlease Enter Rollno\033[0m\n");
                scanf("%d",&num);
                SLL *del=*ptr,*prev;           //del holding starting node
                prev=0;
                while(del)                     //this loop roates untill end of the list
                {
                        if(del->rollno==num)  //if rollno is found
                        {
                                if(prev==0)   //if it is 1st node ten e have to update headptr
                                        *ptr=del->next;
                                else          //if it is not 1st node we have to update prev node next addr
                                        prev->next=del->next;
                                free(del);     //delete record
                                printf("\033[0;32;1mStudent Record Deleted Successfully\033[0m\n");
                                return;
                        }
                        prev=del;
                        del=del->next;
                }
                printf("\033[0;31;1mRoll Number Not Found\033[0m\n");
        }

        if(op=='n')
        {
                char name[20];
                printf("\033[0;35;1mPlease Enter Name\033[0m\n");
                scanf("%s",name);
                SLL *del1,*del2,*prev1,*p4;
                del1=*ptr;         //del1 and prev1 holding staarting node
                prev1=del1;
                while(del1)        //this loop rotate untill end of te list
                {
                        if(strcmp(name,del1->name)==0) //if name is found
                        {
                        del2 = del1->next;   //del2 and p4 holds the next node
                        p4 = del1->next;
                        break;
                        }
                        prev1=del1;
                        del1=del1->next;
                }
                if(del1==0)     //if name is not found it is going to be true
                {
                        printf("\033[0;31;1mName not found\033[0m\n");
                        return;
                }

                while(del2)  //it will rotate untill end of the list
                {
                        if(strcmp(name,del2->name)==0) //if name is found again
                        {
                                int r1;
                                printf("\033[0;35;1msome students having same name please enter rollno to delete\033[0m\n");
                                scanf("%d",&r1);   //take rollno from the user
                                SLL *del,*prev;
                                del=*ptr;         //del holding starting node
                                while(del)
                                {
                                        if(r1==del->rollno) //if roll no found
                                        {
                                                if(del==*ptr)  //check whether it is 1st node or not
                                                *ptr=del->next; //if yes first node update headptr
                                                else
                                                prev->next=del->next; //if no update prev node next address
                                                free(del);            //deleting student data
                                                printf("\033[0;32;1mStudent Record Deleted Successfully\033[0m\n");
                                                return;
                                        }
                                        prev=del;
                                        del=del->next;
                                }
                                        printf("\033[0;31;1mRollno not found\033[0m\n");
                        }
                        del2=del2->next;
                }

                if(del2==0)          //if name is not found 2nd time it is going to true
                {
                        if(prev1->next==p4)    //if it is 1st node
                                *ptr=prev1->next; //update headptr
                        else
                        prev1->next=del1->next; //if it is not 1st node update prev node next address
                        free(del1);    //delete student data
                        printf("\033[0;32;1mStudent Record Deleted Successfully\033[0m\n");
                }

        }
}