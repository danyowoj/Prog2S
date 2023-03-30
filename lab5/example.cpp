#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

main()
{
    int m, n, i, j;
    float **matr; // matr is a pointer on the array of pointers
    float *mass;
    system("CLS");
    printf("Enter size of a row: ");
    scanf("%d", &n);
    printf("Enter amount of rows: ");
    scanf("%d", &m);

    // allocating memory for the array of rows' sums
    mass = new float[m];
    if (mass == NULL)
    {
        puts("Dynamic array was not created!");
        return 1;
    }

    // allocating memory for the array of pointers
    matr = new float *[m];
    if (matr == NULL)
    {
        puts("Dynamic array was not created!");
        return 1;
    }

    for (i = 0; i < m; i++)
    {
        // allocating memory for the i string
        matr[i] = new float[n];
        if (matr[i] == NULL)
        {
            puts("Dynamic array was not created!");
            return 1;
        }

        // filling the row with random numbers
        for (j = 0; j < n; j++)
        {
            matr[i][j] = rand() % 100;
        }
    }

    for (i = 0; i < m; i++)
    {
        mass[i] = 0;
        // putting the sum of i string into the 1D array
        for (j = 0; j < n; j++)
        {
            mass[i] += matr[i][j];
        }
    }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("\t%6.2f", matr[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < m; i++)
    {
        printf("\nSum of %d string is %8.2f", i, mass[i]);
    }

    // freeing memory of i string
    for (i = 0; i < m; i++)
    {
        delete matr[i];
        matr[i] == NULL;
    }

    // freeing memory of array of pointers
    delete matr;
    matr == NULL;

    // freeing memory of array of sums
    delete mass;
    mass == NULL;

    return 0;
}