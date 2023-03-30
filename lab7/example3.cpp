#include <stdio.h>
#include <stdlib.h>

const int n = 4, m = 4;

void MinMax(int A[][n], int B[][n], int (*C)[n], int (*D)[n], int m)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (A[i][j] > B[i][j])
            {
                C[i][j] = A[i][j];
                D[i][j] = B[i][j];
            }
            else
            {
                C[i][j] = B[i][j];
                D[i][j] = A[i][j];
            }
        }
    }
}

main()
{
    int A[m][n], B[m][n], C[m][n], D[m][n], i, j;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            A[i][j] = rand() % 20;
            printf("%5d", A[i][j]);
        }
        puts("\n");
    }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            B[i][j] = rand() % 20;
            printf("%5d", B[i][j]);
        }
        puts("\n");
    }

    MinMax(A, B, C, D, m);
    puts("\n\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%5d", C[i][j]);
        }
        puts("\n");
    }
    puts("\n\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%5d", D[i][j]);
        }
        puts("\n");
    }
    return 0;
}