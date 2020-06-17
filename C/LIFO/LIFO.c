#include <stdio.h>
#include <stdlib.h>
#include "myLIFO.h"

void menu(void)
{
    printf("\nEnter:\n");
    printf("    - U for push element\n");
    printf("    - O for pop element\n");
    printf("    - M for check table if it is empty\n");
    printf("    - F for check table if it is full\n");
    printf("    - S for show all table\n");
    printf("    - E for end\n");
}

int main(int argc, char const *argv[])
{
    char option = ' ';
    while (option != 'E')
    {
        menu();
        scanf("%c", &option);
        if (option == 'U')
        {
            push(5);
        }
        else if (option == 'O')
        {
            pop();
        }
        else if (option == 'M')
        {
            if (is_empty() == 1)
                printf("The LIFO is empty");
            else
                printf("The LIFO isn't empty");
        }
        else if (option == 'F')
        {
            if (is_full() == 1)
                printf("The LIFO is full");
            else
                printf("The LIFO isn't full");
        }
        else if (option == 'S')
        {
            show_LIFO();
        }
        else
        {
            printf("This option does not exist");
        }
    }

    system("pause");
    return 0;
}