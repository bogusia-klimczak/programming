#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

FILE *file;

void list_of_game(void)
{
    printf("\nType number to play or return:\n");
    printf("    0 - \"To menu\"\n");
    printf("    1 - \"Tic Tac Toe\"\n");
    printf("    2 - \"Mike's adventure\"\n\n");
}

int check_user_win(char *table, char option)
{
    if (table[0] == option && table[1] == option && table[2] == option || table[3] == option && table[4] == option && table[5] == option || table[6] == option && table[7] == option && table[8] == option || table[0] == option && table[3] == option && table[6] == option || table[1] == option && table[4] == option && table[7] == option || table[2] == option && table[5] == option && table[8] == option || table[0] == option && table[4] == option && table[8] == option || table[2] == option && table[4] == option && table[6] == option)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int can_user_go(char *table)
{
    for (int i = 0; i < 9; i++)
    {
        if (table[i] != ' ')
        {
            continue;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

int check_comp_win(char *table, char option)
{
    char coption;
    switch (option)
    {
    case 'X':
        coption = 'O';
        break;
    case 'O':
        coption = 'X';
        break;
    }
    if (table[0] == coption && table[1] == coption && table[2] == coption || table[3] == coption && table[4] == coption && table[5] == coption || table[6] == coption && table[7] == coption && table[8] == coption || table[0] == coption && table[3] == coption && table[6] == coption || table[1] == coption && table[4] == coption && table[7] == coption || table[2] == coption && table[5] == coption && table[8] == coption || table[0] == coption && table[4] == coption && table[8] == coption || table[2] == coption && table[4] == coption && table[6] == coption)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int computer_go(char *table, char option)
{
    char coption;
    switch (option)
    {
    case 'X':
        coption = 'O';
        break;
    case 'O':
        coption = 'X';
        break;
    }
    if (table[0] == ' ' && table[1] == ' ' && table[2] == ' ' && table[3] == ' ' && table[4] == ' ' && table[5] == ' ' && table[6] == ' ' && table[7] == ' ' && table[8] == ' ')
    {
        int field = 0 + rand() % 8;
        table[field] = coption;
    }
    else if (table[0] != ' ' && table[1] == ' ' && table[2] == ' ' && table[3] == ' ' && table[4] == ' ' && table[5] == ' ' && table[6] == ' ' && table[7] == ' ' && table[8] == ' ')
    {
        int field = 0 + rand() % 8;
        while (field == 0)
            field = 0 + rand() % 8;
        table[field] = coption;
    }
    else if (table[1] != ' ' && table[0] == ' ' && table[2] == ' ' && table[3] == ' ' && table[4] == ' ' && table[5] == ' ' && table[6] == ' ' && table[7] == ' ' && table[8] == ' ')
    {
        int field = 0 + rand() % 8;
        while (field == 1)
            field = 0 + rand() % 8;
        table[field] = coption;
    }
    else if (table[2] != ' ' && table[1] == ' ' && table[0] == ' ' && table[3] == ' ' && table[4] == ' ' && table[5] == ' ' && table[6] == ' ' && table[7] == ' ' && table[8] == ' ')
    {
        int field = 0 + rand() % 8;
        while (field == 2)
            field = 0 + rand() % 8;
        table[field] = coption;
    }
    else if (table[3] != ' ' && table[1] == ' ' && table[2] == ' ' && table[0] == ' ' && table[4] == ' ' && table[5] == ' ' && table[6] == ' ' && table[7] == ' ' && table[8] == ' ')
    {
        int field = 0 + rand() % 8;
        while (field == 3)
            field = 0 + rand() % 8;
        table[field] = coption;
    }
    else if (table[4] != ' ' && table[1] == ' ' && table[2] == ' ' && table[3] == ' ' && table[0] == ' ' && table[5] == ' ' && table[6] == ' ' && table[7] == ' ' && table[8] == ' ')
    {
        int field = 0 + rand() % 8;
        while (field == 4)
            field = 0 + rand() % 8;
        table[field] = coption;
    }
    else if (table[5] != ' ' && table[1] == ' ' && table[2] == ' ' && table[3] == ' ' && table[4] == ' ' && table[0] == ' ' && table[6] == ' ' && table[7] == ' ' && table[8] == ' ')
    {
        int field = 0 + rand() % 8;
        while (field == 5)
            field = 0 + rand() % 8;
        table[field] = coption;
    }
    else if (table[6] != ' ' && table[1] == ' ' && table[2] == ' ' && table[3] == ' ' && table[4] == ' ' && table[5] == ' ' && table[0] == ' ' && table[7] == ' ' && table[8] == ' ')
    {
        int field = 0 + rand() % 8;
        while (field == 6)
            field = 0 + rand() % 8;
        table[field] = coption;
    }
    else if (table[7] != ' ' && table[1] == ' ' && table[2] == ' ' && table[3] == ' ' && table[4] == ' ' && table[5] == ' ' && table[6] == ' ' && table[0] == ' ' && table[8] == ' ')
    {
        int field = 0 + rand() % 8;
        while (field == 7)
            field = 0 + rand() % 8;
        table[field] = coption;
    }
    else if (table[8] != ' ' && table[1] == ' ' && table[2] == ' ' && table[3] == ' ' && table[4] == ' ' && table[5] == ' ' && table[6] == ' ' && table[7] == ' ' && table[0] == ' ')
    {
        int field = 0 + rand() % 8;
        while (field == 8)
            field = 0 + rand() % 8;
        table[field] = coption;
    }
    else if (table[0] == option && table[1] == option && table[2] == ' ')
    {
        table[2] = coption;
    }
    else if (table[0] == option && table[1] == ' ' && table[2] == option)
    {
        table[1] = coption;
    }
    else if (table[0] == ' ' && table[1] == option && table[2] == option)
    {
        table[0] = coption;
    }
    else if (table[3] == option && table[4] == option && table[5] == ' ')
    {
        table[5] = coption;
    }
    else if (table[3] == option && table[4] == ' ' && table[5] == option)
    {
        table[4] = coption;
    }
    else if (table[3] == ' ' && table[4] == option && table[5] == option)
    {
        table[3] = coption;
    }
    else if (table[6] == option && table[7] == option && table[8] == ' ')
    {
        table[8] = coption;
    }
    else if (table[6] == option && table[7] == ' ' && table[8] == option)
    {
        table[7] = coption;
    }
    else if (table[6] == ' ' && table[7] == option && table[8] == option)
    {
        table[6] = coption;
    }
    else if (table[0] == option && table[3] == option && table[6] == ' ')
    {
        table[6] = coption;
    }
    else if (table[0] == option && table[3] == ' ' && table[6] == option)
    {
        table[3] = coption;
    }
    else if (table[0] == ' ' && table[3] == option && table[6] == option)
    {
        table[0] = coption;
    }
    else if (table[1] == option && table[4] == option && table[7] == ' ')
    {
        table[7] = coption;
    }
    else if (table[1] == option && table[4] == ' ' && table[7] == option)
    {
        table[4] = coption;
    }
    else if (table[1] == ' ' && table[4] == option && table[7] == option)
    {
        table[1] = coption;
    }
    else if (table[2] == option && table[5] == option && table[8] == ' ')
    {
        table[8] = coption;
    }
    else if (table[2] == option && table[5] == ' ' && table[8] == option)
    {
        table[5] = coption;
    }
    else if (table[2] == ' ' && table[5] == option && table[8] == option)
    {
        table[2] = coption;
    }
    else if (table[0] == option && table[4] == option && table[8] == ' ')
    {
        table[8] = coption;
    }
    else if (table[0] == option && table[4] == ' ' && table[8] == option)
    {
        table[4] = coption;
    }
    else if (table[0] == ' ' && table[4] == option && table[8] == option)
    {
        table[0] = coption;
    }
    else if (table[2] == option && table[4] == option && table[6] == ' ')
    {
        table[6] = coption;
    }
    else if (table[2] == option && table[4] == ' ' && table[6] == option)
    {
        table[4] = coption;
    }
    else if (table[2] == ' ' && table[4] == option && table[6] == option)
    {
        table[2] = coption;
    }
    else if (table[0] != ' ' && table[1] != ' ' && table[2] != ' ' && table[3] != ' ' && table[4] != ' ' && table[5] != ' ' && table[6] != ' ' && table[7] != ' ' && table[8] != ' ')
    {
        return 0;
    }
    else
    {
        if (table[0] == coption && table[1] == coption && table[2] == ' ')
        {
            table[2] = coption;
        }
        else if (table[0] == coption && table[1] == ' ' && table[2] == coption)
        {
            table[1] = coption;
        }
        else if (table[0] == ' ' && table[1] == coption && table[2] == coption)
        {
            table[0] = coption;
        }
        else if (table[3] == coption && table[4] == coption && table[5] == ' ')
        {
            table[5] = coption;
        }
        else if (table[3] == coption && table[4] == ' ' && table[5] == coption)
        {
            table[4] = coption;
        }
        else if (table[3] == ' ' && table[4] == coption && table[5] == coption)
        {
            table[3] = coption;
        }
        else if (table[6] == coption && table[7] == coption && table[8] == ' ')
        {
            table[8] = coption;
        }
        else if (table[6] == coption && table[7] == ' ' && table[8] == coption)
        {
            table[7] = coption;
        }
        else if (table[6] == ' ' && table[7] == coption && table[8] == coption)
        {
            table[6] = coption;
        }
        else if (table[0] == coption && table[3] == coption && table[6] == ' ')
        {
            table[6] = coption;
        }
        else if (table[0] == coption && table[3] == ' ' && table[6] == coption)
        {
            table[3] = coption;
        }
        else if (table[0] == ' ' && table[3] == coption && table[6] == coption)
        {
            table[0] = coption;
        }
        else if (table[1] == coption && table[4] == coption && table[7] == ' ')
        {
            table[7] = coption;
        }
        else if (table[1] == coption && table[4] == ' ' && table[7] == coption)
        {
            table[4] = coption;
        }
        else if (table[1] == ' ' && table[4] == coption && table[7] == coption)
        {
            table[1] = coption;
        }
        else if (table[2] == coption && table[5] == coption && table[8] == ' ')
        {
            table[8] = coption;
        }
        else if (table[2] == coption && table[5] == ' ' && table[8] == coption)
        {
            table[5] = coption;
        }
        else if (table[2] == ' ' && table[5] == coption && table[8] == coption)
        {
            table[2] = coption;
        }
        else if (table[0] == coption && table[4] == coption && table[8] == ' ')
        {
            table[8] = coption;
        }
        else if (table[0] == coption && table[4] == ' ' && table[8] == coption)
        {
            table[4] = coption;
        }
        else if (table[0] == ' ' && table[4] == coption && table[8] == coption)
        {
            table[0] = coption;
        }
        else if (table[2] == coption && table[4] == coption && table[6] == ' ')
        {
            table[6] = coption;
        }
        else if (table[2] == coption && table[4] == ' ' && table[6] == coption)
        {
            table[4] = coption;
        }
        else if (table[2] == ' ' && table[4] == coption && table[6] == coption)
        {
            table[2] = coption;
        }
        else
        {
            for (int i = 0; i < 9; i++)
            {
                if (table[i] == ' ')
                {
                    table[i] = coption;
                    break;
                }
            }
        }
    }
}

void tic_tac_toe(void)
{
    printf("                                                                    \n");
    printf("  *   )                 *   )                   *   )               \n");
    printf("` )  /(   (           ` )  /(      )          ` )  /(           (   \n");
    printf(" ( )(_))  )\\    (      ( )(_))  ( /(    (      ( )(_))   (     ))\\  \n");
    printf("(_(_())  ((_)   )\\    (_(_())   )(_))   )\\    (_(_())    )\\   /((_) \n");
    printf("|_   _|   (_)  ((_)   |_   _|  ((_)_   ((_)   |_   _|   ((_) (_))   \n");
    printf("  | |     | | / _|      | |    / _` | / _|      | |    / _ \\ / -_)  \n");
    printf("  |_|     |_| \\__|      |_|    \\__,_| \\__|      |_|    \\___/ \\___|  \n");

    char symbol_table[9];
    for (int i = 0; i < 9; i++)
    {
        symbol_table[i] = ' ';
    }
    int sybol = 1 + rand() % 10;
    char option = ' ';
    if (sybol < 5.5)
    {
        printf("You are going to play X\n");
        option = 'X';
    }
    else
    {
        printf("You are going to play O\n");
        option = 'O';
    }
    printf("You must select one of nine fields by typing number of it\n");

    printf(" 1 | 2 | 3 \n");
    printf("---+---+---\n");
    printf(" 4 | 5 | 6 \n");
    printf("---+---+---\n");
    printf(" 7 | 8 | 9 \n");
    printf("\n");

    int z = 0;
    int nowint;
    int who_first = 1 + rand() % 10;
    if (who_first < 5.5)
    {
        printf("You are first\n");
        while (9)
        {
            if (can_user_go(symbol_table)) // if yes, returns 0 if not - 1
            {
                printf("Draw\n");
                break;
            };
            scanf("%d", &nowint);
            printf("\n");
            if (nowint == 1)
            {
                if (symbol_table[0] == ' ')
                {
                    symbol_table[0] = option;
                }
                else
                {
                    printf("You can not change busy field\n");
                    break;
                }
            }
            else if (nowint == 2)
            {
                if (symbol_table[1] == ' ')
                {
                    symbol_table[1] = option;
                }
                else
                {
                    printf("You can not change busy field\n");
                    break;
                }
            }
            else if (nowint == 3)
            {
                if (symbol_table[2] == ' ')
                {
                    symbol_table[2] = option;
                }
                else
                {
                    printf("You can not change busy field\n");
                    break;
                }
            }
            else if (nowint == 4)
            {
                if (symbol_table[3] == ' ')
                {
                    symbol_table[3] = option;
                }
                else
                {
                    printf("You can not change busy field\n");
                    break;
                }
            }
            else if (nowint == 5)
            {
                if (symbol_table[4] == ' ')
                {
                    symbol_table[4] = option;
                }
                else
                {
                    printf("You can not change busy field\n");
                    break;
                }
            }
            else if (nowint == 6)
            {
                if (symbol_table[5] == ' ')
                {
                    symbol_table[5] = option;
                }
                else
                {
                    printf("You can not change busy field\n");
                    break;
                }
            }
            else if (nowint == 7)
            {
                if (symbol_table[6] == ' ')
                {
                    symbol_table[6] = option;
                }
                else
                {
                    printf("You can not change busy field\n");
                    break;
                }
            }
            else if (nowint == 8)
            {
                if (symbol_table[7] == ' ')
                {
                    symbol_table[7] = option;
                }
                else
                {
                    printf("You can not change busy field\n");
                    break;
                }
            }
            else if (nowint == 9)
            {
                if (symbol_table[8] == ' ')
                {
                    symbol_table[8] = option;
                }
                else
                {
                    printf("You can not change busy field\n");
                    break;
                }
            }
            printf(" %c | %c | %c \n", symbol_table[0], symbol_table[1], symbol_table[2]);
            printf("---+---+---\n");
            printf(" %c | %c | %c \n", symbol_table[3], symbol_table[4], symbol_table[5]);
            printf("---+---+---\n");
            printf(" %c | %c | %c \n", symbol_table[6], symbol_table[7], symbol_table[8]);
            printf("\n");
            printf("\n");
            if (check_user_win(symbol_table, option) == 1) // if user win, returns 1, if not - 0
            {
                printf("You win!\n");
                break;
            }
            else
            {
                if (computer_go(symbol_table, option) == 0)
                {
                    printf("Draw\n");
                    break;
                };
                printf(" %c | %c | %c \n", symbol_table[0], symbol_table[1], symbol_table[2]);
                printf("---+---+---\n");
                printf(" %c | %c | %c \n", symbol_table[3], symbol_table[4], symbol_table[5]);
                printf("---+---+---\n");
                printf(" %c | %c | %c \n", symbol_table[6], symbol_table[7], symbol_table[8]);
                printf("\n");
                printf("\n");
                if (check_comp_win(symbol_table, option))
                {
                    printf("You lose :(\n");
                    break;
                }
            }
            z++;
        }
    }
    else
    {
        printf("Computer is first\n");
        while (9)
        {
            if (computer_go(symbol_table, option) == 0)
            {
                printf("Draw\n");
                break;
            };
            printf(" %c | %c | %c \n", symbol_table[0], symbol_table[1], symbol_table[2]);
            printf("---+---+---\n");
            printf(" %c | %c | %c \n", symbol_table[3], symbol_table[4], symbol_table[5]);
            printf("---+---+---\n");
            printf(" %c | %c | %c \n", symbol_table[6], symbol_table[7], symbol_table[8]);
            printf("\n");
            printf("\n");
            if (check_comp_win(symbol_table, option))
            {
                printf("You lose :(\n");
                break;
            }
            if (can_user_go(symbol_table)) // if yes, returns 0 if not - 1
            {
                printf("Draw\n");
                break;
            };
            scanf("%d", &nowint);
            printf("\n");
            if (nowint == 1)
            {
                if (symbol_table[0] == ' ')
                {
                    symbol_table[0] = option;
                }
                else
                {
                    printf("You can not change busy field\n");
                    break;
                }
            }
            else if (nowint == 2)
            {
                if (symbol_table[1] == ' ')
                {
                    symbol_table[1] = option;
                }
                else
                {
                    printf("You can not change busy field\n");
                    break;
                }
            }
            else if (nowint == 3)
            {
                if (symbol_table[2] == ' ')
                {
                    symbol_table[2] = option;
                }
                else
                {
                    printf("You can not change busy field\n");
                    break;
                }
            }
            else if (nowint == 4)
            {
                if (symbol_table[3] == ' ')
                {
                    symbol_table[3] = option;
                }
                else
                {
                    printf("You can not change busy field\n");
                    break;
                }
            }
            else if (nowint == 5)
            {
                if (symbol_table[4] == ' ')
                {
                    symbol_table[4] = option;
                }
                else
                {
                    printf("You can not change busy field\n");
                    break;
                }
            }
            else if (nowint == 6)
            {
                if (symbol_table[5] == ' ')
                {
                    symbol_table[5] = option;
                }
                else
                {
                    printf("You can not change busy field\n");
                    break;
                }
            }
            else if (nowint == 7)
            {
                if (symbol_table[6] == ' ')
                {
                    symbol_table[6] = option;
                }
                else
                {
                    printf("You can not change busy field\n");
                    break;
                }
            }
            else if (nowint == 8)
            {
                if (symbol_table[7] == ' ')
                {
                    symbol_table[7] = option;
                }
                else
                {
                    printf("You can not change busy field\n");
                    break;
                }
            }
            else if (nowint == 9)
            {
                if (symbol_table[8] == ' ')
                {
                    symbol_table[8] = option;
                }
                else
                {
                    printf("You can not change busy field\n");
                    break;
                }
            }
            printf(" %c | %c | %c \n", symbol_table[0], symbol_table[1], symbol_table[2]);
            printf("---+---+---\n");
            printf(" %c | %c | %c \n", symbol_table[3], symbol_table[4], symbol_table[5]);
            printf("---+---+---\n");
            printf(" %c | %c | %c \n", symbol_table[6], symbol_table[7], symbol_table[8]);
            printf("\n");
            printf("\n");
            if (check_user_win(symbol_table, option) == 1) // if user win, returns 1, if not - 0
            {
                printf("You win!\n");
                break;
            }
            z++;
        }
    }
}

void mikes_adventure(void)
{
    printf("   *                                                                                                         \n");
    printf(" (  `             )           (             (        (                                )                      \n");
    printf(" )\\))(    (    ( /(     (     )\\            )\\       )\\ )     )       (            ( /(     (    (       (   \n");
    printf("((_)()\\   )\\   )\\())   ))\\   ((_)  (     ((((_)(    (()/(    /((     ))\\    (      )\\())   ))\\   )(     ))\\  \n");
    printf("(_()((_) ((_) ((_)\\   /((_)        )\\     )\\ _ )\\    ((_))  (_))\\   /((_)   )\\ )  (_))/   /((_) (()\\   /((_) \n");
    printf("|  \\/  |  (_) | |(_) (_))         ((_)    (_)_\\(_)   _| |   _)((_) (_))    _(_/(  | |_   (_))(   ((_) (_))   \n");
    printf("| |\\/| |  | | | / /  / -_)        (_-<     / _ \\   / _` |   \\ V /  / -_)  | ' \\)) |  _|  | || | | '_| / -_)  \n");
    printf("|_|  |_|  |_| |_\\_\\  \\___|        /__/    /_/ \\_\\  \\__,_|    \\_/   \\___|  |_||_|   \\__|   \\_,_| |_|   \\___|  \n");

    struct timespec tw = {0, 100000000}; // seconds, nanoseconds; 1second - 10^10 nanoseconds
    struct timespec tr;

    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("   ... \n");
    printf("  .o.o. \n");
    printf("   ... \n");
    printf("  ..... \n");
    printf(" .. . .. \n");
    printf(" .. . .. \n");
    printf("    .    \n");
    printf("  ..... \n");
    printf(" ..   .. \n");
    printf(" ..   .. \n");
    printf("\n");
    int i = 0;
    while (i < 5)
    {
        printf("\r\\");
        fflush(stdout);
        nanosleep(&tw, &tr);

        printf("\r|");
        fflush(stdout);
        nanosleep(&tw, &tr);

        printf("\r/");
        fflush(stdout);
        nanosleep(&tw, &tr);

        printf("\r-");
        fflush(stdout);
        nanosleep(&tw, &tr);
        i++;
    }
    printf("\nNow it does not work\n");
}

void game_play(void)
{
    int option;
    while (1)
    {
        list_of_game();
        scanf("%d", &option);
        if (option == 0)
        {
            break;
        }
        else if (option == 1)
        {
            printf("\nYou chosen \"Tic Tac Toe\"\n");
            tic_tac_toe();
        }
        else if (option == 2)
        {
            printf("\nYou chosen \"Mike's adventure\"\n");
            mikes_adventure();
        }
        else
        {
            printf("\nThis number is not a game\n");
        }
    }
}

void menu_settings(void)
{
    printf("\nWhat do you want to change?\n");
    printf("Type number to choose or return\n");
    printf("    0 - \"To menu\"\n");
}

void game_settings(void)
{
    int option;
    while (1)
    {
        menu_settings();
        scanf("%d", &option);
        if (option == 0)
        {
            break;
        }
        else
        {
            printf("\nThis number is not an option\n");
        }
    }
}

void game_exit(void)
{
    printf("You Successfully go to exit!\n");
}

void menu(void)
{
    printf("\n\nType:\n");
    printf("    - \"play\" to play\n");
    printf("    - \"settings\" to change settings\n");
    printf("    - \"exit\" to exit from game\n");
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    printf("\n");
    printf(" __  __              _____                            \n");
    printf("|  \\/  |            / ____|                           \n");
    printf("| \\  / |  _   _    | |  __    __ _   _ __ ___     ___ \n");
    printf("| |\\/| | | | | |   | | |_ |  / _` | | '_ ` _ \\   / _ \\\n");
    printf("| |  | | | |_| |   | |__| | | (_| | | | | | | | |  __/\n");
    printf("|_|  |_|  \\__, |    \\_____|  \\__,_| |_| |_| |_|  \\___|\n");
    printf("           __/ |                                      \n");
    printf("          |___/                                       \n");

    for (; 1;)
    {
        menu();
        char option[10] = " ";
        scanf("%s", &option);
        if (strcmp(option, "play") == 0 || strcmp(option, "PLAY") == 0 || strcmp(option, "Play") == 0 || strcmp(option, "pl") == 0)
        {
            game_play();
        }
        if (strcmp(option, "settings") == 0 || strcmp(option, "SETTINGS") == 0 || strcmp(option, "Settings") == 0 || strcmp(option, "s") == 0)
        {
            game_settings();
        }
        else if (strcmp(option, "exit") == 0 || strcmp(option, "EXIT") == 0 || strcmp(option, "Exit") == 0 || strcmp(option, "e") == 0)
        {
            game_exit();
            break;
        }
        else
        {
            printf("\n\nYour input string does not an option");
        }
    }

    system("pause");
    return 0;
}