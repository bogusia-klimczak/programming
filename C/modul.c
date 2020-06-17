#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int a, b, n, m;

    printf("Please, type in number a: ");
    scanf("%d", &a);

    printf("Please, type in number b: ");
    scanf("%d", &b);
    
    n = a > 0 ? a : -a;
    m = b > 0 ? b : -b;
    
    if (n > m)
        printf("|%d| > |%d|\n", a, b);
    else if (n < m)
        printf("|%d| < |%d|\n", a, b);
    else
        printf("|%d| = |%d|\n", a, b);

    system("pause");
    return 0;
}