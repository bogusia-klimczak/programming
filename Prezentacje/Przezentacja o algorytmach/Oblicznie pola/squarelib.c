#include "squarelib.h"

double f(double x)
{
    return x * x + x + 2;
}

double Pole(int a, int b, int n)
{
    double x = (b - a) / (double)n;
    double S = 0.0;
    double srodek = a + x / 2.0;

    for (int i = 0; i < n; i++)
    {
        S += f(srodek);
        srodek += x;
    }
    return S * x;
}