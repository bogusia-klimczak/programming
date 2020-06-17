#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int a, b, c, d, k, l;
    printf("Program wyznacza paramentry funkcji liniowej na podstawie współrzędnych dwóch dowolnych punktów\n");

    printf("Wprowadź A(x: ");
    scanf("%d", &a);

    printf("Wprowadź A(y: ");
    scanf("%d", &b);

    printf("Wprowadź B(x: ");
    scanf("%d", &c);

    printf("Wprowadź B(y: ");
    scanf("%d", &d);

    k = (b - d) / (a - c);
    l = ((d * a) - (b * c)) / (a - c);

    printf("Wzór funkcji przechodzącej punkty A(%d; %d), B(%d; %d): y = %dx + %d\n", a, b, c, d, k, l);

    system("pause");
    return 0;
}