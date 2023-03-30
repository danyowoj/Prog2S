#include <stdio.h>
#include <stdlib.h>

void dynamic_array_print(int **A, size_t N, size_t M)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%*d", 5, A[i][j]);
        }
        printf("\n");
    }
}

int **dynamic_array_alloc(size_t N, size_t M)
{
    int **A = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++)
    {
        A[i] = (int *)malloc(M * sizeof(int));
    }
    return A;
}

void dynamic_array_free(int **A, size_t N)
{
    for (int i = 0; i < N; i++)
    {
        free(A[i]);
    }
    free(A);
}

void dynamic_array_test(size_t N, size_t M)
{
    int **A = dynamic_array_alloc(N, M);
    int x = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            A[i][j] = x;
            x += 1;
        }
    }
    dynamic_array_print(A, N, M);
    dynamic_array_free(A, N);
}

int main()
{
    int MATRIX_HEIGHT, MATRIX_WIDTH;
    printf("Enter the height and the width of the matrix:\n");
    scanf("%d%d", &MATRIX_HEIGHT, &MATRIX_WIDTH);
    dynamic_array_test(MATRIX_HEIGHT, MATRIX_WIDTH);
    return 0;
}