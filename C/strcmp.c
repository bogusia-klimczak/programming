#include <stdio.h>
#include <stdlib.h>

int strcmp(char *text1, char *text2)
{
    int countOne = 0, iOne = 0;
    while (1)
    {
        if (text1[iOne] == 0)
            break;
        else
        {
            countOne++;
            iOne++;
        }
    }
    int countTwo = 0, iTwo = 0;
    while (1)
    {
        if (text2[iTwo] == 0)
            break;
        else
        {
            countTwo++;
            iTwo++;
        }
    }
    if (countOne > countTwo)
        return -1;
    else if (countOne == countTwo)
        return 0;
    else
        return 1;
}

int main(int argc, char const *argv[])
{
    char text1[] = "Ala ma kota";
    char text2[] = "Ala ma kota";
    printf("%d\n", strcmp(text1, text2));
    system("pause");
    return 0;
}