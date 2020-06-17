#include <stdio.h>
#include <stdlib.h>

#define N 1000

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int n, i, j;
    int a[N];

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    { // ЧИТАЕМ ВХОД
        scanf("%d", &a[i]);
    }
    
    qsort(a, n, sizeof(int), cmp); // СОРТИРУЕМ
    for (i = 0; i < n; i++)
    { // ВЫВОДИМ РЕЗУЛЬТАТ
        printf("%d ", a[i]);
    }
    system("pause");
    return 0;
}