#ifndef _MY_LIFO_H

#define _MY_LIFO_H

#include <stdio.h>

int LIFO[3] = {0, 0, 0};
int key = 0;

int is_empty(void);
int is_full(void);

int push(int var)
{
    if (is_full())
    {
        printf("You can't add element");
        return 1;
    }
    LIFO[key] = var;
    key++;
    printf("SUCCESSFULL");
}

int pop(void)
{
    if (is_empty())
    {
        printf("You can't delete element");
        return 1;
    }
    int result = LIFO[key - 1];
    LIFO[key - 1] = 0;
    key--;
    printf("SUCCESSFULL");
    return result;
}

int is_empty(void)
{
    int k = 0;
    for (int i = 0; i < sizeof(LIFO); i++)
    {
        if (LIFO[i] != 0)
        {
            k++;
        }
    }
    if (k == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int is_full(void)
{
    int k = 0;
    for (int i = 0; i < sizeof(LIFO); i++)
    {
        if (LIFO[i] != 0)
        {
            k++;
        }
    }
    if (k == sizeof(LIFO))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void show_LIFO(void)
{
    for (int i = 0; i < sizeof(LIFO); i++)
    {
        printf("%d\n", LIFO[i]);
    }
}

#endif