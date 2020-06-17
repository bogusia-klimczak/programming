#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "flib.h"

int main(int argc, char const *argv[])
{
    char table[] = "f(x) = sin(x^2 + 1) + 5 * x^(1/2) - 3";
    f(table, 0.0);

    printf("%lf\n", m_sin(M_PI / 6));
    printf("%lf\n", sin(M_PI / 6));

    system("pause");
    return 0;
}