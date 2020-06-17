#include <stdio.h>
#include <stdlib.h>

#define INTI 10

FILE *file;
void name(int *table)
{
    if ((file = fopen("text.txt", "wb")) == NULL)
    {
        printf("Cannot open file.");
        exit(1);
    }
    int a = 5;
    fwrite(table, sizeof(int), INTI, file);
    fclose(file);

    if ((file = fopen("text.txt", "rb")) == NULL)
    {
        printf("Cannot open file.");
        exit(1);
    }
    int b[INTI];
    fread(&b, sizeof(int), INTI, file);
    fclose(file);
    for (int i = 0; i < INTI; i++)
    {
        printf("\n%d\n", b[i]);
    }
}

int main(int argc, char const *argv[])
{
    int table[INTI] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    name(table);

    system("pause");
    return 0;
}