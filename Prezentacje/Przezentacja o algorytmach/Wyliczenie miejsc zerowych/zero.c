#include <stdio.h>
#include <stdlib.h>
#include "zerolib.h"

int main()
{
    double a, b, ex, e0;
    printf("Podaj zakres poszukiwan pierwiastka: \n");
    printf("a = ");
    scanf("%lf", &a);
    printf("b = ");
    scanf("%lf", &b);
    printf("Dokladnosc wyniku: ");
    scanf("%lf", &ex);
    printf("Dokladnosc porownania f(x) z zerem: ");
    scanf("%lf", &e0);
    zero(a, b, ex, e0);

    system("pause");
    return 0;
}
