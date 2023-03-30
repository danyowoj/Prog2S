#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mins(int *arr, int n, int *index1, int *index2)
{
    int min1 = 10, min2 = 10;
    // search for min element and remember its index
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min1)
        {
            min1 = arr[i];
            *index1 = i;
        }
    }
    // search for second min element and remember its index
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min2 && arr[i] >= min1 && i != *index1)
        {
            min2 = arr[i];
            *index2 = i;
        }
    }
}

// deletes (sets to 0) elements between minimal elements
void del(int *arr, int n, int *index1, int *index2)
{
    if (*index1 < *index2)
    {
        for (int i = *index1 + 1; i < *index2; i++)
        {
            arr[i] = 0;
        }
    }
    else
    {
        for (int i = *index2 + 1; i < *index1; i++)
        {
            arr[i] = 0;
        }
    }
}

main()
{
    srand(time(NULL));
    int n = 10, arr[n];
    int index1 = 0, index2 = 0;

    printf("Original array:\n");
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 10;
        printf("%5d", arr[i]);
    }

    mins(arr, n, &index1, &index2);
    del(arr, n, &index1, &index2);

    printf("\nChanged array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%5d", arr[i]);
    }

    return 0;
}