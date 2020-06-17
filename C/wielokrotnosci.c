#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int n, m;
    printf("Program wczytuje dwie liczby i wypisuje w kolejnych wiersach wszystkie dodatnie wielokrotności liczby n mniejsze od liczby m\n");

    printf("Wprowadź liczbę n: ");
    scanf("%d", &n);

    printf("Wprowadź liczbę m: ");
    scanf("%d", &m);
    
    for (int i = n; i < m; i++)
    {
        if (i % n == 0)
            printf("%d\n", i);
    }
    system("pause");
    return 0;
}