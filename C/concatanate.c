#include <stdio.h>
#include <stdlib.h>

char *concatanate(char *text1, char *text2)
{
    char newText[] = "";
    sprintf(newText, "%s%s", text1, text2);
    return newText;
}

int main(int argc, char const *argv[])
{
    char text1[] = "Ala ma";
    char text2[] = " kota";
    printf("%s", concatanate(text1, text2));

    system("pause");
    return 0;
}