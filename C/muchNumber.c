#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int a, b;
    printf("Wprowadź liczbę a: ");
    scanf("%d", &a);
    printf("Wprowadź liczbę b: ");
    scanf("%d", &b);
    if (a > b)
        printf("Większa liczba %d/n", a);
    else if (a < b)
        printf("Większa liczba %d\n", b);
    else
        printf("Liczby są równe\n");
        
    system("pause");
    return 0;
}