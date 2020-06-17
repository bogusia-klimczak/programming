#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    float a, b, c, delta, rdelta, result1, result2;

    printf("Type in a: ");
    scanf("%f", &a);

    printf("Type in b: ");
    scanf("%f", &b);

    printf("Type in c: ");
    scanf("%f", &c);

    delta = b * b - 4 * a * c;

    rdelta = sqrt(delta);

    if (delta > 0)
    {
        result1 = (-b + rdelta) / (2 * a);
        result2 = (-b - rdelta) / (2 * a);
        if (b > 0 && c > 0)
        {
            printf("The solutions of %fx<sub>2</sub>*x + %fx + %f = 0 :\nx1 = %f\nx2 = %f\n", a, b, c, result1, result2);
        }
        else if (b > 0 && c == 0)
        {
            printf("The solutions of %fx*x + %fx = 0 :\nx1 = %f\nx2 = %f\n", a, b, result1, result2);
        }
        else if (b == 0 && c > 0)
        {
            printf("The solutions of %fx*x + %f = 0 :\nx1 = %f\nx2 = %f\n", a, c, result1, result2);
        }
        else if (b == 0 && c == 0)
        {
            printf("The solutions of %fx*x = 0 :\nx1 = %f\nx2 = %f\n", a, result1, result2);
        }
        else if (b > 0 && c < 0)
        {
            c = c > 0 ? c : -c;
            printf("The solutions of %fx*x + %fx - %f = 0 :\nx1 = %f\nx2 = %f\n", a, b, c, result1, result2);
        }
        else if (b == 0 && c < 0)
        {
            c = c > 0 ? c : -c;
            printf("The solutions of %fx*x - %f = 0 :\nx1 = %f\nx2 = %f\n", a, c, result1, result2);
        }
        else if (b < 0 && c == 0)
        {
            b = b > 0 ? b : -b;
            printf("The solutions of %fx*x - %fx = 0 :\nx1 = %f\nx2 = %f\n", a, b, result1, result2);
        }
        else if (b < 0 && c > 0)
        {
            b = b > 0 ? b : -b;
            printf("The solutions of %fx*x - %fx + %f = 0 :\nx1 = %f\nx2 = %f\n", a, b, c, result1, result2);
        }
        else if (b < 0 && c < 0)
        {
            b = b > 0 ? b : -b;
            c = c > 0 ? c : -c;
            printf("The solutions of %fx*x - %fx - %f = 0 :\nx1 = %f\nx2 = %f\n", a, b, c, result1, result2);
        }
    }
    else if (delta == 0)
    {
        result1 = -b / (2 * a);
        if (b > 0 && c > 0)
        {
            printf("The solutions of %fx*x + %fx + %f = 0 :\nx = %f\n", a, b, c, result1);
        }
        else if (b > 0 && c == 0)
        {
            printf("The solutions of %fx*x + %fx = 0 :\nx = %f\n", a, b, result1);
        }
        else if (b == 0 && c > 0)
        {
            printf("The solutions of %fx*x + %f = 0 :\nx = %f\n", a, c, result1);
        }
        else if (b == 0 && c == 0)
        {
            printf("The solutions of %fx*x = 0 :\nx = %f\n", a, result1);
        }
        else if (b > 0 && c < 0)
        {
            c = c > 0 ? c : -c;
            printf("The solutions of %fx*x + %fx - %f = 0 :\nx = %f\n", a, b, c, result1);
        }
        else if (b == 0 && c < 0)
        {
            c = c > 0 ? c : -c;
            printf("The solutions of %fx*x - %f = 0 :\nx = %f\n", a, c, result1);
        }
        else if (b < 0 && c == 0)
        {
            b = b > 0 ? b : -b;
            printf("The solutions of %fx*x - %fx = 0 :\nx = %f\n", a, b, result1);
        }
        else if (b < 0 && c > 0)
        {
            b = b > 0 ? b : -b;
            printf("The solutions of %fx*x - %fx + %f = 0 :\nx = %f\n", a, b, c, result1);
        }
        else if (b < 0 && c < 0)
        {
            b = b > 0 ? b : -b;
            c = c > 0 ? c : -c;
            printf("The solutions of %fx*x - %fx - %f = 0 :\nx = %f\n", a, b, c, result1);
        }
    }
    else
    {
        printf("No solution\n");
    }
    system("pause");
    return 0;
}
