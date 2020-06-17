#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int n;
    printf("Type in number of factorial: ");
    scanf("%d", &n);
    if (n == 0 || n == 1)
    {
        printf("%d! = 1\n", n);
    }
    else
    {
        int j = 1;
        for (int i = 1; i <= n; i++)
        {
            j *= i;
        }
        printf("%d! = %d\n", n, j);
    }

    system("pause");
    return 0;
}