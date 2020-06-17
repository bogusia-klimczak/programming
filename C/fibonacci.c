#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int x;
    printf("Type in number of fibonacci: ");
    scanf("%d", &x);
    if (x == 0 || x < 0)
        printf("Error: wrong type in\n");
    else if (x == 1)
        printf("0\n");
    else if (x == 2)
        printf("0, 1\n");
    else
    {
        printf("0, 1, ");
        int prepre = 0, pre = 1;
        for (int n = 1; n <= x - 2; n++)
        {
            int m = prepre + pre;
            if (n == x - 2)
            {
                printf("%d", m);
                prepre = pre;
                pre = m;
            }
            else
            {
                printf("%d, ", m);
                prepre = pre;
                pre = m;
            }
        }
        printf("\n");
    }

    system("pause");
    return 0;
}