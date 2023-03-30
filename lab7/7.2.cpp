#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **dynamic_matrix_create(size_t N)
{
    srand(time(NULL));
    int **A = (int **)malloc(N * sizeof(int *));
    int r;
    for (int i = 1; i <= N; i++)
    {
        r = 2 + rand() % (10 - 2 + 1);
        A[i] = (int *)malloc(r * sizeof(int));
        A[i][0] = r;
        printf("%5d", A[i][0]);
        for (int j = 1; j < r; j++)
        {
            A[i][j] = rand() % 10;
            printf("%5d", A[i][j]);
        }
        puts("\n");
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

void row_sum(int **A, int N)
{
    int sum;
    for (int i = 0; i < N; i++)
    {
        sum = 0;
        for (int j = 0; j < A[i][0]; j++)
        {
            sum += A[i][j];
        }
        printf("Sum of row %d = %d\n", i, sum);
    }
}

int main()
{
    srand(time(NULL));

    int n;

    printf("\nEnter the height of the matrix: ");
    scanf("%d", &n);

    printf("\nOriginal matrix:\n\n");
    int **A = dynamic_matrix_create(n);

    // row_sum(A, n);

    int sum;
    for (int i = 1; i <= n; i++)
    {
        sum = 0;
        for (int j = 0; j < A[i][0]; j++)
        {
            sum += A[i][j];
        }
        printf("Sum of row %d = %d\n", i - 1, sum);
    }

    dynamic_matrix_free(A, n);

    return 0;
}