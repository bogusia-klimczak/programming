#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int table[4][4], maxPos[2], minPos[2], i, l, k, s;

    printf("Program wczytuje wartości do tablicy i wyświetla ją oraz nadaje możliwość zamiany wartości maksymalnej na minimalną\n");

    for (int i = 0; i < 4; i++)
    {
        for (int l = 0; l < 4; l++)
        {
            printf("Wprowadź liczbę: ");
            scanf("%d", &table[i][l]);
        }
    }

    int max = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int l = 0; l < 4; l++)
        {
            if (table[i][l] > max)
            {
                max = table[i][l];
                maxPos[0] = i;
                maxPos[1] = l;
            }
        }
    }

    int min = 999999999;
    for (int i = 0; i < 4; i++)
    {
        for (int l = 0; l < 4; l++)
        {
            if (table[i][l] < min)
            {
                min = table[i][l];
                minPos[0] = i;
                minPos[1] = l;
            }
        }
    }

    char option;
    printf("Chcesz zmienić minimalną i maksymalną wartości? Wprowadź y, jeżeli tak albo n, jeżeli nie: ");
    scanf(" %c", &option);
    switch (option)
    {
    case 'y':
    case 'Y':
        i = minPos[0];
        l = minPos[1];
        k = maxPos[0];
        s = maxPos[1];
        table[i][l] = max;
        table[k][s] = min;
        break;
    case 'n':
    case 'N':
        printf("Okej\n");
        break;
    default:
        printf("Zła opcja\n");
    }

    for (int i = 0; i < 4; i++)
    {
        for (int l = 0; l < 4; l++)
        {
            if (l == 3)
                printf("%5d\n", table[i][l]);
            else
                printf("%5d", table[i][l]);
        }
    }
    system("pause");
    return 0;
}