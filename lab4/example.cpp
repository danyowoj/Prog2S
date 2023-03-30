#include <stdio.h>
#include <stdlib.h>

const int n = 5;     // amount of elements in the row
typedef int rown[n]; // rown is a new type: array(string) of n integer numbers

main()
{
    int i, j, m;
    rown *a; // pointer on a row
    int *b;  // pointer on an integer
    printf("Number of rows? ");
    scanf("%d", &m);
    a = new rown[m]; // allocating memory for the matrix
    // at the adress a, m rows of n elemets per row

    if (a == NULL)
    {
        printf("No memory allocated");
        return 1; // error message
    }
    b = new int[m]; // allocating memory for the array of rows' sum
    if (b == NULL)
    {
        printf("No memory allocated");
        return 1; // error message
    }
    // filling the matrix with random numbers
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            a[i][j] = rand() % 11;
            printf("%4d", a[i][j]);
        }
        puts("\n");
    }
    // filling array b with sums of matrix's rows
    for (i = 0; i < m; i++)
    {
        b[i] = 0;
        for (j = 0; j < n; j++)
        {
            b[i] += a[i][j];
        }

    }
    puts("\n");
    for (j = 0; j < n-1; j++)
    {
        printf("%4d", b[j]);
    }
    delete a; // freeing up the memory occupied by the matrix
    delete b; // freeing the memory occupied by the array
    puts("\n");
    return 0;
}