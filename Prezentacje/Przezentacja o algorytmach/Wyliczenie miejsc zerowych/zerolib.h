#include <math.h>

double f(double x)
{
    return x * x * x * (x + sin(x * x - 1) - 1) - 1;
    // return x * x - 100;
}

double zero(double a, double b, double ex, double e0)
{
    double fa, fb, x0, f0;
    fa = f(a);
    fb = f(b);
    if (fa * fb >= 0 || a >= b)
    {
        printf("Funkcja nie spelnia zalozen\n");
        return -1;
    }

    while (fabs(a - b) > ex)
    {
        x0 = (a + b) / 2;
        f0 = f(x0);
        if (fabs(f0) < e0)
        {
            break;
        }
        if (fa * f0 < 0)
        {
            b = x0;
        }
        else
        {
            a = x0;
            fa = f0;
        }
    }
    printf("x0 = %lf", x0);
    return x0;
}
