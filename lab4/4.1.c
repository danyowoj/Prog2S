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

/*
    return pointer on 2d dynamic array
    !allocates memory -> to be freed later
*/
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

main()
{
    int n, m, max_elem = 0, max_col, max_row;
    printf("Enter size of the matrix:\n");
    scanf("%d%d", &n, &m);

    int **B = dynamic_matrix_allocate(n, m);

    // filling the matrix with random numbers
    // and searching for the max element
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            B[i][j] = rand() % 10;
            if (B[i][j] > max_elem)
            {
                max_elem = B[i][j];
                max_row = i;
                max_col = j;
            }
        }
    }
    dynamic_matrix_print(B, n, m);
    puts("\n");

    int **C = dynamic_matrix_allocate(n - 1, m - 1);
    int k = 0, l = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == max_row)
        {
            continue;
        }
        for (int j = 0; j < m; j++)
        {
            if (j == max_col)
            {
                continue;
            }
            C[k][l] = B[i][j];
            printf("%5d", C[k][l]);
            l++;
        }
        puts("\n");
        k++;
    }

    dynamic_matrix_free(B, n);
    dynamic_matrix_free(C, n - 1);

    return 0;
}