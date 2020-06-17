#include <malloc.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include "flib.h"

// M_PI 16 numbers after dot

int is_numeric(char string)
{
    if (string == '0' || string == '1' || string == '2' || string == '3' || string == '4' || string == '5' || string == '6' || string == '7' || string == '8' || string == '9')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int factorial(int number)
{
    if (number < 0)
    {
        return -1;
    }
    else if (number == 0 || number == 1)
    {
        return 1;
    }
    else
    {
        return factorial(number - 1) * number;
    }
}

double m_sin(double x)
{
    double result = 0.0;
    int i = 0, l = 1, n = 17;
    while (n--)
    {
        if (i % 2 == 0)
        {
            result += (pow(x, l)) / (factorial(l));
            l += 2;
            i++;
        }
        else
        {
            result -= (pow(x, l)) / (factorial(l));
            l += 2;
            i--;
        }
    }

    return result;
}

double m_cos(double x)
{
    double result = 0.0;
    int i = 0, l = 0, n = 17;
    while (n--)
    {
        if (i % 2 == 0)
        {
            result += (pow(x, l)) / (factorial(l));
            l += 2;
            i++;
        }
        else
        {
            result -= (pow(x, l)) / (factorial(l));
            l += 2;
            i--;
        }
    }

    return result;
}

double m_tan(double x)
{
    return m_sin(x) / m_cos(x);
}

double m_ctg(double x)
{
    return m_cos(x) / m_sin(x);
}

char *delete_space(char *str)
{
    int l = 0;
    char *expr;
    expr = (char *)malloc(1);
    if (expr == NULL)
    {
        exit(1);
    }
    expr[0] = '\0';

    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == ' ')
        {
            continue;
        }
        else
        {
            expr = realloc(expr, (strlen(expr) + 2) * sizeof(char));
            expr[l] = str[i];
            expr[l + 1] = '\0';
            l++;
        }
    }

    return expr;
}

char **explode(char delimiter, char *string)
{
    char **result;
    int rows = 1, *cols, k = 0;
    result = (char **)malloc(1 * sizeof(char *)); // array with pointers to strings
    cols = (int *)malloc(1 * sizeof(int));        // array of count of symbols in strings
    cols[0] = 1;
    result[0] = (char *)malloc(1 * sizeof(char)); // string
    result[0][0] = '\0';

    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == delimiter)
        {
            rows++;
            cols = (int *)realloc(cols, rows * sizeof(int));
            result = (char **)realloc(result, rows * sizeof(char *));
            cols[rows - 1] = 1;
            result[rows - 1] = (char *)malloc(1 * sizeof(char));
            k = 0;
        }
        else
        {
            cols[rows - 1] += 1;
            result[rows - 1] = (char *)realloc(result[rows - 1], cols[rows - 1] * sizeof(char));
            result[rows - 1][k] = string[i];
            result[rows - 1][k + 1] = '\0';
            k++;
        }
    }

    return result;
}

double f(char *func, double x)
{
    char *funcWithoutSpace = delete_space(func);
    char *formula = explode('=', funcWithoutSpace)[1];
    double result = 0.0;

    for (int i = 0; i < strlen(formula); i++)
    {
        if (formula[i] == '(')
        {
            printf("This is open skobka\n");
        }
        else if (formula[i] == ')')
        {
            printf("This is close skobka\n");
        }
        else if (formula[i] == '^')
        {
            printf("This is power\n");
        }
        else if (formula[i] == '*')
        {
            printf("This is multiplication\n");
        }
        else if (formula[i] == '/')
        {
            printf("This is division\n");
        }
        else if (formula[i] == '+')
        {
            printf("This is addition\n");
        }
        else if (formula[i] == '-')
        {
            printf("This is substaction\n");
        }
        else if (formula[i] == 'x')
        {
            printf("This is x\n");
        }
        else if (is_numeric(formula[i]))
        {
            printf("This number\n");
        }
        printf("%c\n\n", formula[i]);
    }

    return 0.0;
}