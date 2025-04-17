#include"header.h"

void save_data_into_file(SLL *ptr)
{
        if(ptr==0) //if no data is found tis will execute
        {
                printf("\033[0;31;1mRecords Not Found\033[0m\n");
                return;
        }
        FILE *fp;
        fp=fopen("stud.data","w");
        while(ptr)
        {             //it will store data into file
                fprintf(fp,"%d %s %f\n",ptr->rollno,ptr->name,ptr->percentage);
                ptr=ptr->next;
        }
        printf("\033[0;32;1mData Saved in File\033[0m\n");
        fclose(fp);
}

void read_file(SLL **ptr)
{
        SLL *new,*last;
        FILE *fp=fopen("stud.data","r");
        if(fp==0)
        {
                printf("\033[0;31;1mStudent Database Notfound\033[0m\n");
                return;
        }
        while(1)
        {
                new=malloc(sizeof(SLL)); //allocate d m/r to sore data from file
                if(fscanf(fp,"%d %s %f",&new->rollno,new->name,&new->percentage)==-1)
                {
                        free(new);
                        break;
                }
                new->next=0;
                if(*ptr==0)
                        *ptr=new;
                else
                {
                        last=*ptr;
                        while(last->next)
                                last=last->next;
                        last->next=new;
                }

        }
        printf("\033[0;32;1mData Successfully Fetched\033[0m\n");
}