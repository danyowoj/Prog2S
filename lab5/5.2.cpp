#include <stdio.h>
#include <stdlib.h>

int **dynamic_matrix_allocate(size_t N)
{
    int **A = (int **)malloc(N * sizeof(int *));
    for (int i = 1; i <= N; i++)
    {
        A[i] = (int *)malloc(i * sizeof(int));
    }
    return A;
}

void dynamic_matrix_free(int **A, size_t N)
{
    for (int i = 0; i < N; i++)
    {
        free(A[i]);
    }
    free(A);
}

main()
{
    int n, m, f = 1, mult;
    printf("Enter the height of the matrix:");
    scanf("%d", &n);
    int **A = dynamic_matrix_allocate(n);
    printf("\nMultiplication table up to %d:\n\n", n);

    for (int i = 0; i < n; i++)
    {
        mult = 1;
        for (int j = 0; j <= i; j++)
        {
            A[i][j] = f * mult;
            printf("%4d", A[i][j]);
            mult++;
        }
        f++;
        puts("\n");
    }
    dynamic_matrix_free(A, n);
    return 0;
}