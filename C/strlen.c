#include <stdio.h>
#include <stdlib.h>

int strlenght(char *text)
{
    int count = 0, i = 0;
    while (1)
    {
        if (text[i] == 0)
            return count;
        else
        {
            count++;
            i++;
        }
    }
}

int main(int argc, char const *argv[])
{
    char text[] = "Ala ma kota";
    printf("%d\n", strlenght(text));
    system("pause");
    return 0;
}