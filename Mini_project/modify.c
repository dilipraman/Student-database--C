#include"header.h"
void modify_the_records(SLL **ptr)
{
        char op;
        int r;
        SLL *p1;
        p1=*ptr; //p1 is holding starting node
        printf("\033[0;35;1mEnter which record to search for modification\nR/r : to search a rollno\nN/n : to search a name\nP/p : percentage based\033[0m\n");
        scanf(" %c",&op);

        if(op>='A'&&op<='Z')
                op=op+32;

        if(op!='r'&&op!='n'&&op!='p')
        printf("\033[0;31;1mYou Have Entered Wrong Option\033[0m\n");

        if(op=='r')
        {
                printf("\033[0;35;1menter roll number\033[0m\n");
                scanf("%d",&r);
                while(p1)
                {
                        if(r==p1->rollno)  // if rollno matches it will ask user to enter name and percentage
                        {
                                printf("\033[0;35;1mplease enter name and percentage\033[0m\n");
                                scanf("%s%f",p1->name,&p1->percentage);
                                printf("\033[0;32;1mStudent Data Modified Successfully\033[0m\n");
                                return;
                        }
                        p1=p1->next;
                }                          //if rollno not matches with any student rollno this will execute
                        printf("\033[0;31;1mRoll Number Not Found\033[0m\n");
        }

        if(op=='n')
        {
                char name[20];
                SLL *p2;
                int f=0;
                printf("\033[0;35;1menter name\033[0m\n");
                scanf("%s",name);
                while(p1)
                {
                        if(strcmp(name,p1->name)==0) //if name found then it will search remaining records to
                        {                            //check if the name is present again or not
                                p2=p1->next;        //p2 holds holds the next node
                                break;
                        }
                        p1=p1->next;
                }
                if(p1==0)
                {
                        printf("\033[0;31;1mName not found\033[0m\n");
                        return;
                }
                while(p2)
                {
                        if(strcmp(name,p2->name)==0)  //if name is found again then it will ask use to enter rollno
                        {
                                int r1;
                                printf("\033[0;35;1msome students having same name please enter rollno to modify\033[0m\n");
                                scanf("%d",&r1);
                                SLL *p3;
                                p3=*ptr; //p3 holds the starting node
                                while(p3) //tis loop rotate untill last node
                                {
                                        if(r1==p3->rollno) //if rollno found then it will ask stud name and perntge
                                        {
                                                f=1;
                                                printf("\033[0;35;1mplease enter name and percentage\033[0m\n");
                                                scanf("%s%f",p3->name,&p3->percentage);
                                                printf("\033[0;32;1mStudent Data Modified Successfully\033[0m\n");
                                                break;
                                        }
                                        p3=p3->next;
                                }
                                if(p3==0)
                                        printf("\033[0;31;1mRollno not found\033[0m\n");
                        }
                        if(f==1)
                                break;
                        p2=p2->next;
                }
                if(p2==0)   //if second time name is not found this will execute
                {           //p1 holds the node which is having same name
                        printf("\033[0;35;1mplease enter name and percentage\033[0m\n");
                        scanf("%s%f",p1->name,&p1->percentage);
                        printf("\033[0;32;1mStudent Data Modified Successfully\033[0m\n");
                }
        }

        if(op=='p')
        {
                float f1;
                int f2;
                SLL *p1,*p2;
                p1=*ptr;
                printf("\033[0;35;1mEnter Percentage\033[0m\n");
                scanf("%f",&f1);
                while(p1)
                {
                        if(p1->percentage==f1)
                        {
                                p2=p1->next;
                                break;
                        }
                        p1=p1->next;
                }
                if(p1==0)
                {
                        printf("\033[0;31;1mNo students having %f percentage\033[0m\n",f1);
                        return;
                }

                while(p2)
                {
                        if(p2->percentage==f1)
                        {
                                int r1;
                                printf("\033[0;35;1msome students having same percentage please enter rollno to modify\033[0m\n");
                                scanf("%d",&r1);
                                SLL *p3;
                                p3=*ptr;
                                while(p3)
                                {
                                        if(r1==p3->rollno)
                                        {
                                                f2=1;
                                                printf("\033[0;35;1mplease enter name and percentage\033[0m\n");
                                                scanf("%s%f",p3->name,&p3->percentage);
                                                printf("\033[0;32;1mStudent Data Modified Successfully\033[0m\n");
                                                break;
                                        }
                                        p3=p3->next;
                                }
                                if(p3==0)
                                        printf("\033[0;31;1mRollno not found\033[0m\n");
                        }
                        if(f2==1)
                                break;
                        p2=p2->next;
                }
                if(p2==0)
                {
                        printf("\033[0;35;1mplease enter name and percentage\033[0m\n");
                        scanf("%s%f",p1->name,&p1->percentage);
                        printf("\033[0;32;1mStudent Data Modified Successfully\033[0m\n");
                }
        }
}