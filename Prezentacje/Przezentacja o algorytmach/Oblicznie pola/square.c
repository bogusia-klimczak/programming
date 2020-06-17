#include <stdio.h>
#include <stdlib.h>
#include "squarelib.h"

int main(int argc, char *argv)
{
    int a, b, n;
    printf("Podaj przedzial [a, b]\n");
    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);
    printf("Podaj liczbe prostokatow: ");
    scanf("%d", &n);

    if (a >= b)
    {
        printf("To nie jest przedzial!");
    }
    else
    {
        printf("Pole figury wynosi: %.2f\n", Pole(a, b, n));
    }

    system("pause");
    return 0;
}