#include <stdio.h>
#include <stdlib.h>

void dynamic_matrix_print(int **A, size_t N, size_t M)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%5d", A[i][j]);
        }
        puts("\n");
    }
}

int **dynamic_matrix_allocate(size_t N, size_t M)
{
    int **A = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++)
    {
        A[i] = (int *)malloc(M * sizeof(int));
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

int main()
{
    int n, m;
    printf("Enter size of the array:\n");
    scanf("%d%d", &n, &m);

    int **A = dynamic_matrix_allocate(n, m);

    // filling matrix B[n][m] with random numbers
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            A[i][j] = rand() % 10;
        }
    }
    dynamic_matrix_print(A, n, m);
    puts("\n");

    int row_sum, col_sum;
    int row_sum_arr[n], col_sum_arr[m], corner = 0;

    // counting sum of rows
    for (int i = 0; i < n; i++)
    {
        row_sum = 0;
        for (int j = 0; j < m; j++)
        {
            row_sum += A[i][j];
            corner += A[i][j];
        }
        row_sum_arr[i] = row_sum;
    }
    puts("\n");

    // counting for sum of column
    for (int i = 0; i < m; i++)
    {
        col_sum = 0;
        for (int j = 0; j < n; j++)
        {
            col_sum += A[j][i];
            corner += A[j][i];
        }
        col_sum_arr[i] = col_sum;
    }

    int **D = dynamic_matrix_allocate(n + 1, m + 1);

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == n && j == m)
            {
                D[i][j] = corner;
                // printf("%d;\t", D[i][j]);
                continue;
            }

            if (j == m)
            {
                D[i][j] = row_sum_arr[i];
                // printf("%d;\t", D[i][j]);
                continue;
            }

            if (i == n)
            {
                D[i][j] = col_sum_arr[j];
                // printf("%d;\t", D[i][j]);
                continue;
            }

            D[i][j] = A[i][j];
            // printf("%d;\t", D[i][j]);
        }
    }
    dynamic_matrix_print(D, n + 1, m + 1);

    dynamic_matrix_free(A, n);
    dynamic_matrix_free(D, n + 1);
    return 0;
}