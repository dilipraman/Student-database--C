#include"header.h"

void exit_pgm(SLL **p)
{
        char op;

        printf("\033[0;35;1mS/s : save and exit\nE/e : exit without saving\033[0m\n");
        scanf(" %c",&op);

        if(op>='A'&&op<='Z')
                op=op+32;

        if(op!='s'&&op!='e')
        printf("\033[0;31;1mYou Have Entered wrong Option\033[0m\n");

        if(op=='s')
        {
                save_data_into_file(*p);
                printf("\033[0;32;1mexited\033[0m\n");
        }
        if(op=='e')
                printf("\033[0;32;1mexited without saving\033[0m\n");
}
