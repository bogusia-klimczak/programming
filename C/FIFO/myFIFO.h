#include <stdio.h>

int FIFO[3];
int key1 = 0;
int key2 = 0;

int is_empty(void);
int is_full(void);

int push(int var)
{
    if (is_full())
    {
        printf("You can't add element");
        return 1;
    }
    FIFO[key1] = var;
    key1++;
    printf("SUCCESSFULL");
}

int pop(void)
{
    if (is_empty())
    {
        printf("You can't delete element");
        return 1;
    }
    int result = FIFO[key2];
    FIFO[key2] = 0;
    key2++;
    printf("SUCCESSFULL");
    return result;
}

int is_empty(void)
{
    int k = 0;
    for (int i = 0; i < sizeof(FIFO); i++)
    {
        if (FIFO[i] != 0)
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
    for (int i = 0; i < sizeof(FIFO); i++)
    {
        if (FIFO[i] != 0)
        {
            k++;
        }
    }
    if (k == sizeof(FIFO))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void show_FIFO(void)
{
    for (int i = 0; i < sizeof(FIFO); i++)
    {
        printf("%d\n", FIFO[i]);
    }
}