#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int ROWS = 5;
int COLS = 4;

FILE *file;

void type_data(int *array) // Function to type data to table
{
    printf("\n");
    int m = 0;
    for (int i = 0; i < ROWS; i++)
    {
        for (int k = 0; k < COLS; k++)
        {
            printf("table[%d][%d] = ", i, k);
            scanf("%d", &array[m]);
            m++;
        }
    }
}

void show_data(int *array) // Function to show data from table
{
    printf("\n");
    for (int s = 0; s < ROWS * COLS; s++)
    {
        if ((s + 1) % COLS == 0)
            printf("%6d\n", array[s]);
        else
            printf("%6d", array[s]);
    }
}

void swap_min_and_max(int *array) // Function to swap min and max values
{
    int maxPos, minPos; // Declaration of index of max element, index of min element

    int max = 0; // Declaration of max element
    for (int i = 0; i < ROWS * COLS; i++)
    {
        if (array[i] > max) // Checking if current element is bigger than max element
        {
            max = array[i]; // max element is current element
            maxPos = i;     // index of max element is current index
        }
    }

    int min = 999999999; // Declaration of max element
    for (int i = 0; i < ROWS * COLS; i++)
    {
        if (array[i] < min) // Checking if current element is smaller than min element
        {
            min = array[i]; // min element is current element
            minPos = i;     // index of min element is current index
        }
    }

    array[minPos] = max; // For element with min index set max element
    array[maxPos] = min; // For element with max index set min element
}

void random_data(int *array) // Function to generate random data
{
    for (int m = 0; m < ROWS * COLS; m++)
    {
        array[m] = rand();
    }
}

int cmp(const void *a, const void *b) // Function for sorting array
{
    return *(int *)a - *(int *)b;
}

void arit_mean_and_median(int *array)
{
    // Declaration of variable with arithmetic mean
    double arit_mean;

    // The sum of the elements
    double summ = 0;

    for (int i = 0; i < ROWS * COLS; i++)
    {
        // Add current element
        summ += array[i];
    }
    printf("\n");

    // Сalculate the arithmetic mean
    arit_mean = summ / (ROWS * COLS);

    // Show result
    printf("\n%.2f\n", arit_mean);

    // Declaration
    int newTable[ROWS * COLS];
    // and initialization of new array
    for (int i = 0; i < ROWS * COLS; i++)
    {
        newTable[i] = array[i];
    }

    // Sorting array to find median
    qsort(newTable, ROWS * COLS, sizeof(int), cmp);

    // Declaration of variable with median
    double median;

    // Checking where is middle of array
    if ((ROWS * COLS) % 2 == 0) // If count of elements is even
    {
        int var = ((ROWS * COLS) / 2) - 1;
        median = (array[var] + array[var + 1]) / 2.0;
    }
    else // If count of elements is odd
    {
        int var = ((ROWS * COLS) / 2) - 0.5;
        median = array[var];
    }
    printf("%.2f", median);
}

int save_in_file(int *array)
{
    if ((file = fopen("text", "wb")) == NULL) // If sth went wrong
    {
        printf("Cannot open file.");
        exit(1);
    }

    // If everything is OK, write in file from table
    fwrite(array, sizeof(int), ROWS * COLS, file);

    // Close access to file
    fclose(file);
}

void type_in_table_from_file(int *array)
{
    if ((file = fopen("text", "rb")) == NULL) // If sth went wrong
    {
        printf("Cannot open file.");
        exit(1);
    }

    // If everything is OK, read from file in table
    fread(array, sizeof(int), ROWS * COLS, file);

    // Close access to file
    fclose(file);
}

void change_count_array(int *array)
{
    printf("Enter count of ROWS");
    scanf("%d", &ROWS);
    printf("Enter count of COLS");
    scanf("%d", &COLS);
    realloc(array, ROWS * COLS * sizeof(int));
}

void menu() // Function to show menu
{
    printf("\n");
    printf("1 - enter data\n");
    printf("2 - show data\n");
    printf("3 - calculate arethmetic mean and median\n");
    printf("4 - swap the smallest value with the highest value\n");
    printf("5 - generate random data\n");
    printf("6 - change count array\n");
    printf("s - save data to file\n");
    printf("r - read data from file\n");
    printf("e - program end\n");
    printf("\n");
}

int main(int argc, char const *argv[])
{
    srand(time(NULL)); // For really random numbers (see more:https://pl.wikibooks.org/wiki/C/srand AND https://pl.wikibooks.org/wiki/C/rand)

    // Declaration of table
    int *table;
    table = (int *)malloc(ROWS * COLS * sizeof(int));

    // Declaration of variable with user's option
    char option;

    while (option != 'e')
    {
        // Show menu
        menu();

        // Get option from user
        scanf("%c", &option);

        // Compare user's option and existing options
        switch (option)
        {
        case '1':             // if user's option is 1
            type_data(table); // it's mean user want to type in data
            printf("\nData entered\n");
            break;
        case '2':             // if user's option is 2
            show_data(table); // it's mean user want to show data
            printf("\nData displayed\n");
            break;
        case '3':                        // if user's option is 3
            arit_mean_and_median(table); // it's mean user want to get arithmetic mean and median
            printf("\nThe arithmetic mean and the median displayed\n");
            break;
        case '4':                    // if user's option is 4
            swap_min_and_max(table); // it's mean user want to swap data
            printf("\nData changed\n");
            break;
        case '5':               // if user's option is 5
            random_data(table); // it's mean user want to get random data
            printf("\nRandom data\n");
            break;
        case '6':                      // if user's option is 5
            change_count_array(table); // it's mean user want to get random data
            printf("\nCount of array changed\n");
            break;
        case 's':                // if user's option is s
            save_in_file(table); // it's mean user want to save data in file
            printf("\nData saved to file\n");
            break;
        case 'r':                           // if user's option is r
            type_in_table_from_file(table); // it's mean user want to get data from file
            printf("\nData loaded from file\n");
            break;
        case 'e':                         // if user's option is e
            printf("\nEnd of program\n"); // it's mean user want to end program
            break;
        }
    }
    free(table);

    system("pause");
    return 0;
}