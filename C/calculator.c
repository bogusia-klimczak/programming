#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int a, b;
    float result;
    char option;

    printf("Wybierz dziłanie:\nA - suma\nS - odejmowanie\nM - iloczyn\nD - iloraz\n");
    scanf("%c", &option);

    printf("Wybierz liczbę a:");
    scanf("%d", &a);

    printf("Wybierz liczbę b:");
    scanf("%d", &b);

    switch (option)
    {
    case 'A':
    case 'a':
        result = a + b;
        printf("%.0f\n", result);
        break;
    case 'S':
    case 's':
        result = a - b;
        printf("%.0f\n", result);
        break;
    case 'M':
    case 'm':
        result = a * b;
        printf("%.0f\n", result);
        break;
    case 'D':
    case 'd':
        if (b == 0)
        {
            printf("Nie można dzielić przez 0!\n");
            break;
        }
        else
        {
            result = a / b;
            printf("%.0f\n", result);
            break;
        }
    default:
        printf("Error. Wybrana opcja nie poprawna\n");
    }

    system("pause");
    return 0;
}