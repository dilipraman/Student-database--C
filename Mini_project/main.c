#include"header.h"

void main()
{
        SLL *headptr=0;
        char op;
        while(1)
        {
                printf("\033[0;36;1;4m****STUDENT RECORDS MENU****\033[0m\n");
                printf("\033[0;36;1ma/A : add_new_record\nd/D : delete_a_record\ns/S : show_the_list\nm/M : modify_the_records\nv/V : save_data_into_file\nt/T : sort_the_list\nl/L : delete_all_records\nr/R : reverse_the_records\ne/E : exit\nK/k : read_file\nEnter your choice :\033[0m\n");
                scanf(" %c",&op);

                if(op>='A' && op<='Z')
                        op=op+32;

                switch(op)
                {

                        case 'a':add_new_record(&headptr);
                                 break;
                        case 's':show_the_list(headptr);
                                 break;
                        case 'd':delete_a_record(&headptr);
                                 break;
                        case 'm':modify_the_records(&headptr);
                                 break;
                        case 'v':save_data_into_file(headptr);
                                 break;
                        case 'e':exit_pgm(&headptr);
                                 break;
                        case 't':sort_the_list(headptr);
                                 break;
                        case 'l':delete_all_records(&headptr);
                                 break;
                        case 'r':reverse_the_records(headptr);
                                 break;
                        case 'k':read_file(&headptr);
                                 break;
                        default :printf("\033[0;31;1mYou Have Entered Wrong Option,Please Choose Correct Option\033[0m\n");
                }
        }
}
